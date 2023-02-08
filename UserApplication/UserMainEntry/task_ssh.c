#include "task_ssh.h"

#include "rng/trng.h"
#include "rng/yarrow.h"
#include "shell/shell_server.h"
#include "resource_manager.h"
#include "sftp/sftp_server.h"
#include "path.h"

#define APP_SSH_MAX_CONNECTIONS 3
#define APP_SSH_MAX_CHANNELS 3
#define APP_SHELL_MAX_SESSIONS 3
#define APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY 	"keys/server_ecdsa_p256_public_key.pem"
#define APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY "keys/server_ecdsa_p256_private_key.pem"
#define APP_SSH_SERVER_ED25519_PUBLIC_KEY 		"keys/server_ed25519_public_key.pem"
#define APP_SSH_SERVER_ED25519_PRIVATE_KEY 		"keys/server_ed25519_private_key.pem"



SshServerSettings sshServerSettings;
SshServerContext sshServerContext;
SshConnection sshConnections[APP_SSH_MAX_CONNECTIONS];
SshChannel sshChannels[APP_SSH_MAX_CHANNELS];
ShellServerSettings shellServerSettings;
ShellServerContext shellServerContext;
ShellServerSession shellSessions[APP_SHELL_MAX_SESSIONS];


#define APP_SFTP_MAX_SESSIONS 4
#define APP_SFTP_MAX_FILES 4

SftpServerSettings sftpServerSettings;
SftpServerContext sftpServerContext;
SftpServerSession sftpSessions[APP_SFTP_MAX_SESSIONS];
SftpFileObject sftpFileObjects[APP_SFTP_MAX_FILES];


/**
 * @brief Password authentication callback function
 * @param[in] connection Handle referencing a client connection
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] password NULL-terminated string that contains the corresponding password
 * @return Authentication status (SSH_AUTH_STATUS_SUCCESS, SSH_AUTH_STATUS_FAILURE or
 *   SSH_AUTH_STATUS_PASSWORD_EXPIRED)
 **/

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen)
{
   SshAuthStatus status;

   //Debug message
   msg_log("SSH server: Password verification\r\n");

   //Manage authentication policy
   if(!strcmp(user, "root"))
   {
      //Check password
      if(passwordLen == 6 && !strncmp(password, "123456", 6))
      {
         //The provided password is valid
         status = SSH_AUTH_STATUS_SUCCESS;
      }
      else
      {
         //The provided password is not valid
         status = SSH_AUTH_STATUS_FAILURE;
      }
   }
   else
   {
      //Unknown user name
      status = SSH_AUTH_STATUS_FAILURE;
   }

   //Return access status
   return status;
}



/**
 * @brief Load SSH server's keys
 * @param[in] context Pointer to the SSH server context
 * @return Error code
 **/

error_t sshServerImportKeys(SshServerContext *context)
{
   error_t error;
   const char_t *publicKey;
   size_t publicKeyLen;
   const char_t *privateKey;
   size_t privateKeyLen;

   //Get server's ECDSA P-256 public key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's ECDSA P-256 private key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load ECDSA P-256 key pair
   error = sshServerLoadHostKey(&sshServerContext, publicKey,
      publicKeyLen, privateKey, privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's Ed25519 public key
   error = resGetData(APP_SSH_SERVER_ED25519_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's Ed25519 private key
   error = resGetData(APP_SSH_SERVER_ED25519_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load Ed25519 key pair
   error = sshServerLoadHostKey(&sshServerContext, publicKey,
      publicKeyLen, privateKey, privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}



/**
 * @brief User verification callback function
 * @param[in] session Handle referencing a shell session
 * @param[in] user NULL-terminated string that contains the user name
 * @return Access status
 **/

ShellAccessStatus shellServerCheckUserCallback(ShellServerSession *session,
   const char_t *user)
{
   //Debug message
   msg_log("Shell server: User verification\r\n");

   //Set welcome banner
   shellServerSetBanner(session,
      "You are connected to \x1b[32mCycloneSSH\x1b[39m Server\r\n");

   //Set shell prompt
   shellServerSetPrompt(session, ">");

   //All SSH users are granted access to the shell service
   return SHELL_ACCESS_ALLOWED;
}


/**
 * @brief Command line processing callback function
 * @param[in] session Handle referencing an SCP session
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] path Canonical path of the file
 * @return Permissions for the specified file
 **/

error_t shellServerCommandLineCallback(ShellServerSession *session,
   char_t *commandLine)
{
   error_t error;

   //Debug message
   msg_log("Shell server: Command line received\r\n");
   msg_log("  %s\r\n", commandLine);

   //Check command name
   if(!strcasecmp(commandLine, "hello"))
   {
      //Send response to the client
      error = shellServerWriteStream(session, "Hello World!\r\n", 14,
         NULL, 0);
   }
   else if(!strcasecmp(commandLine, "exit") ||
      !strcasecmp(commandLine, "quit"))
   {
      //Close shell session
      error = ERROR_END_OF_STREAM;
   }
   else
   {
      //Unknown command received
      error = shellServerWriteStream(session, "Unknown command!\r\n", 18,
         NULL, 0);
   }

   //Return status code
   return error;
}



/**
 * @brief User verification callback function
 * @param[in] session Handle referencing an SFTP session
 * @param[in] user NULL-terminated string that contains the user name
 * @return Access status
 **/

SftpAccessStatus sftpServerCheckUserCallback(SftpServerSession *session,
   const char_t *user)
{
   //Debug message
   msg_log("SFTP server: User verification\r\n");

   //All SSH users are granted access to the SFTP service
   return SFTP_ACCESS_ALLOWED;
}


/**
 * @brief Callback used to retrieve file permissions
 * @param[in] session Handle referencing an SFTP session
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] path Canonical path of the file
 * @return Permissions for the specified file
 **/

uint_t sftpServerGetFilePermCallback(SftpServerSession *session,
   const char_t *user, const char_t *path)
{
   uint_t perm;

   //Debug message
   msg_log("SFTP server: Checking access rights for %s\r\n", path);

//   //Manage access rights
//   if(!strcmp(user, "root"))
//   {
//      //Check path name
//      if(pathMatch(path, "/temp/*"))
//      {
//         //Allow read/write access to temp directory
//         perm = SFTP_FILE_PERM_LIST | SFTP_FILE_PERM_READ | SFTP_FILE_PERM_WRITE;
//      }
//      else
//      {
//         //Allow read access only to other directories
//         perm = SFTP_FILE_PERM_LIST | SFTP_FILE_PERM_READ;
//      }
//   }
//   else 
//		 
	 if(!strcmp(user, "root"))
   {
      //Allow read/write access
      perm = SFTP_FILE_PERM_LIST | SFTP_FILE_PERM_READ | SFTP_FILE_PERM_WRITE;
   }
   else
   {
      //Deny access
      perm = 0;
   }

   //Return the relevant permissions
   return perm;
}


int32_t task_ssh_server_init(void * yarrowContext)
{
	error_t error;

	//Get default settings
	sshServerGetDefaultSettings(&sshServerSettings);
	//Bind SSH server to the desired interface
	sshServerSettings.interface = NULL;
	//Listen to port 22
	sshServerSettings.port = SSH_PORT;
	//SSH connections
	sshServerSettings.numConnections = APP_SSH_MAX_CONNECTIONS;
	sshServerSettings.connections = sshConnections;
	//SSH channels
	sshServerSettings.numChannels = APP_SSH_MAX_CHANNELS;
	sshServerSettings.channels = sshChannels;
	//Pseudo-random number generator
	sshServerSettings.prngAlgo = YARROW_PRNG_ALGO;
	sshServerSettings.prngContext = yarrowContext;
	//Password authentication callback function
	sshServerSettings.passwordAuthCallback = sshServerPasswordAuthCallback;

	//SSH server initialization
	error = sshServerInit(&sshServerContext, &sshServerSettings);
	//Failed to initialize SSH server?
	if(error)
	{
		//Debug message
		msg_log("Failed to initialize SSH server!\r\n");
	}

	//Load keys
	error = sshServerImportKeys(&sshServerContext);
	//Failed to load keys?
	if(error)
	{
		//Debug message
		msg_log("Failed to load keys!\r\n");
	}

	//Start SSH server
	error = sshServerStart(&sshServerContext);
	//Failed to start SSH server?
	if(error)
	{
		//Debug message
		msg_log("Failed to start SSH server!\r\n");
	}

	//Get default settings
	shellServerGetDefaultSettings(&shellServerSettings);
	//SSH server context
	shellServerSettings.sshServerContext = &sshServerContext;
	//Shell sessions
	shellServerSettings.numSessions = APP_SHELL_MAX_SESSIONS;
	shellServerSettings.sessions = shellSessions;
	//User verification callback function
	shellServerSettings.checkUserCallback = shellServerCheckUserCallback;
	//Command line processing callback function
	shellServerSettings.commandLineCallback = shellServerCommandLineCallback;

	//Shell server initialization
	error = shellServerInit(&shellServerContext, &shellServerSettings);
	//Failed to initialize shell server?
	if(error)
	{
		//Debug message
		msg_log("Failed to initialize shell server!\r\n");
	}

	//Start shell server
	error = shellServerStart(&shellServerContext);
	//Failed to start shell server?
	if(error)
	{
		//Debug message
		msg_log("Failed to start shell server!\r\n");
	}
	
   //Get default settings
   sftpServerGetDefaultSettings(&sftpServerSettings);
   //SSH server context
   sftpServerSettings.sshServerContext = &sshServerContext;
   //SFTP sessions
   sftpServerSettings.numSessions = APP_SFTP_MAX_SESSIONS;
   sftpServerSettings.sessions = sftpSessions;
   //File objects
   sftpServerSettings.numFileObjects = APP_SFTP_MAX_FILES;
   sftpServerSettings.fileObjects = sftpFileObjects;
   //Root directory
   sftpServerSettings.rootDir = "/";
   //User verification callback function
   sftpServerSettings.checkUserCallback = sftpServerCheckUserCallback;
   //Callback used to retrieve file permissions
   sftpServerSettings.getFilePermCallback = sftpServerGetFilePermCallback;

   //SFTP server initialization
   error = sftpServerInit(&sftpServerContext, &sftpServerSettings);
   //Failed to initialize SFTP server?
   if(error)
   {
      //Debug message
      msg_log("Failed to initialize SFTP server!\r\n");
   }

   //Start SFTP server
   error = sftpServerStart(&sftpServerContext);
   //Failed to start SFTP server?
   if(error)
   {
      //Debug message
      msg_log("Failed to start SFTP server!\r\n");
   }
	
	return error;
}

