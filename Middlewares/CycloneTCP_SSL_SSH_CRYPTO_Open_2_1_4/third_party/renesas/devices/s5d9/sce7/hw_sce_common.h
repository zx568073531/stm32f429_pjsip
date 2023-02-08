/***********************************************************************************************************************
 * Copyright [2020-2021] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics America Inc. and may only be used with products
 * of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  Renesas products are
 * sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for the selection and use
 * of Renesas products and Renesas assumes no liability.  No license, express or implied, to any intellectual property
 * right is granted by Renesas. This software is protected under all applicable laws, including copyright laws. Renesas
 * reserves the right to change or discontinue this software and/or this documentation. THE SOFTWARE AND DOCUMENTATION
 * IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST EXTENT
 * PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE OR
 * DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.  TO THE MAXIMUM
 * EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR DOCUMENTATION
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @addtogroup SCE
 * @{
 ***********************************************************************************************************************/

#ifndef HW_SCE_COMMON_H
#define HW_SCE_COMMON_H

/**********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include "s5d9.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

typedef enum e_ssp_err
{
    SSP_SUCCESS = 0,

    /* Start of Crypto specific (0x10000) */
    SSP_ERR_CRYPTO_CONTINUE               = 0x10000,  ///< Continue executing function
    SSP_ERR_CRYPTO_SCE_RESOURCE_CONFLICT  = 0x10001,  ///< Hardware resource busy
    SSP_ERR_CRYPTO_SCE_FAIL               = 0x10002,  ///< Internal I/O buffer is not empty
    SSP_ERR_CRYPTO_SCE_HRK_INVALID_INDEX  = 0x10003,  ///< Invalid index
    SSP_ERR_CRYPTO_SCE_RETRY              = 0x10004,  ///< Retry
    SSP_ERR_CRYPTO_SCE_VERIFY_FAIL        = 0x10005,  ///< Verify is failed
    SSP_ERR_CRYPTO_SCE_ALREADY_OPEN       = 0x10006,  ///< HW SCE module is already opened
    SSP_ERR_CRYPTO_NOT_OPEN               = 0x10007,  ///< Hardware module is not initialized
    SSP_ERR_CRYPTO_UNKNOWN                = 0x10008,  ///< Some unknown error occurred
    SSP_ERR_CRYPTO_NULL_POINTER           = 0x10009,  ///< Null pointer input as a parameter
    SSP_ERR_CRYPTO_NOT_IMPLEMENTED        = 0x1000a,  ///< Algorithm/size not implemented
    SSP_ERR_CRYPTO_RNG_INVALID_PARAM      = 0x1000b,  ///< An invalid parameter is specified
    SSP_ERR_CRYPTO_RNG_FATAL_ERROR        = 0x1000c,  ///< A fatal error occurred
    SSP_ERR_CRYPTO_INVALID_SIZE           = 0x1000d,  ///< Size specified is invalid
    SSP_ERR_CRYPTO_INVALID_STATE          = 0x1000e,  ///< Function used in an valid state
    SSP_ERR_CRYPTO_ALREADY_OPEN           = 0x1000f,  ///< control block is already opened
    SSP_ERR_CRYPTO_INSTALL_KEY_FAILED     = 0x10010,  ///< Specified input key is invalid.
    SSP_ERR_CRYPTO_AUTHENTICATION_FAILED  = 0x10011,  ///< Authentication failed
    SSP_ERR_CRYPTO_SCE_KEY_SET_FAIL       = 0x10012,  ///< Failure to Init Cipher
    SSP_ERR_CRYPTO_SCE_AUTHENTICATION     = 0x10013,  ///< Authentication failed
    SSP_ERR_CRYPTO_SCE_PARAMETER          = 0x10014,  ///< Input date is illegal.
    SSP_ERR_CRYPTO_SCE_PROHIBIT_FUNCTION  = 0x10015,  ///< An invalid function call occurred.

    /* Start of SF_CRYPTO specific */
    SSP_ERR_CRYPTO_COMMON_NOT_OPENED      = 0x20000, ///< Crypto Framework Common is not opened
    SSP_ERR_CRYPTO_HAL_ERROR              = 0x20001, ///< Cryoto HAL module returned an error
    SSP_ERR_CRYPTO_KEY_BUF_NOT_ENOUGH     = 0x20002, ///< Key buffer size is not enough to generate a key
    SSP_ERR_CRYPTO_BUF_OVERFLOW           = 0x20003, ///< Attempt to write data larger than what the buffer can hold
    SSP_ERR_CRYPTO_INVALID_OPERATION_MODE = 0x20004, ///< Invalid operation mode.
    SSP_ERR_MESSAGE_TOO_LONG              = 0x20005, ///< Message for RSA encryption is too long.
    SSP_ERR_RSA_DECRYPTION_ERROR          = 0x20006, ///< RSA Decryption error.
} ssp_err_t;

/***********************************************************************************************************************
 * Private function prototypes
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Private Functions
 ***********************************************************************************************************************/

/*******************************************************************************************************************//**
 *
 **********************************************************************************************************************/
__STATIC_INLINE void HW_SCE_PowerOn (void)
{
    // power on the SCE module
    R_MSTP->MSTPCRC_b.MSTPC31 = 0;
}

__STATIC_INLINE void HW_SCE_PowerOff (void)
{
    // power off the SCE module
    R_MSTP->MSTPCRC_b.MSTPC31 = 1;
}

#endif                                 /* HW_SCE_COMMON_H */

/*******************************************************************************************************************//**
 * @}
 **********************************************************************************************************************/
