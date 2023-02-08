//Dependencies
#include "core/net.h"
#include "os/include/m2m_wifi_ex.h"

//Global variables
extern NetInterface *wilc1000ApInterface;


NMI_API sint8 os_m2m_wifi_init(tstrWifiInitParam *pWifiInitParam)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_init(pWifiInitParam);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_deinit(void *arg)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_deinit(arg);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_handle_events(void *arg)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_handle_events(arg);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_connect(char *pcSsid, uint8 u8SsidLen, uint8 u8SecType, tuniM2MWifiAuth *puniAuthInfo, uint16 u16Ch)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_connect(pcSsid, u8SsidLen, u8SecType, puniAuthInfo, u16Ch);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_disconnect(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_disconnect();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_get_connection_info(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_get_connection_info();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_mac_address(uint8 au8MacAddress0[6], uint8 au8MacAddress1[6])
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_mac_address(au8MacAddress0, au8MacAddress1);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_wps(uint8 u8TriggerType, const char *pcPinNumber)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_wps(u8TriggerType, pcPinNumber);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_wps_disable(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_wps_disable();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_p2p(uint8 u8Channel, tenuP2PTrigger enuTrigger, uint16 u16WPS_CfgMehods)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_p2p(u8Channel, enuTrigger, u16WPS_CfgMehods);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_p2p_disconnect(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_p2p_disconnect();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_enable_ap(CONST tstrM2MAPConfig *pstrM2MAPConfig)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_enable_ap(pstrM2MAPConfig);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_disable_ap(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Valid interface?
   if(wilc1000ApInterface != NULL)
   {
      //Link is down
      wilc1000ApInterface->linkState = FALSE;
      //Process link state change event
      nicNotifyLinkChange(wilc1000ApInterface);
   }

   //Invoke underlying function
   status = m2m_wifi_disable_ap();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_ap_get_assoc_info(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_ap_get_assoc_info();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_ap_add_black_list(uint8 bAddNewEntry, uint8 *mac_addr)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_ap_add_black_list(bAddNewEntry, mac_addr);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_scan_options(uint8 u8NumOfSlot, uint8 u8SlotTime)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_scan_options(u8NumOfSlot, u8SlotTime);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_scan_region(uint8 ScanRegion)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_scan_region(ScanRegion);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_scan_list(tstrM2MScanList *pstrScanList)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_scan_list(pstrScanList);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_request_scan(uint8 ch)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_request_scan(ch);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_request_scan_ssid(uint8 ch, char *pcssid)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_request_scan_ssid(ch, pcssid);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API uint8 os_m2m_wifi_get_num_ap_found(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_get_num_ap_found();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_req_scan_result(uint8 index)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_req_scan_result(index);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_req_curr_rssi(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_req_curr_rssi();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_get_otp_mac_address(uint8 *pu8MacAddr, uint8 *pu8IsValid)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_get_otp_mac_address(pu8MacAddr, pu8IsValid);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_get_mac_address(uint8 *pu8MacAddr0, uint8 *pu8MacAddr1)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_get_mac_address(pu8MacAddr0, pu8MacAddr1);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_sleep_mode(uint8 PsTyp, uint8 BcastEn)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_sleep_mode(PsTyp, BcastEn);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API uint8 os_m2m_wifi_get_sleep_mode(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_get_sleep_mode();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_device_name(uint8 *pu8DeviceName, uint8 u8DeviceNameLength)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_device_name(pu8DeviceName, u8DeviceNameLength);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_p2p_pin(uint8 *pu8PinNumber, uint8 u8PinLength)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_p2p_pin(pu8PinNumber, u8PinLength);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_allow_p2p_connection(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_allow_p2p_connection();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_lsn_int(tstrM2mLsnInt *pstrM2mLsnInt)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_lsn_int(pstrM2mLsnInt);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_enable_monitoring_mode(tstrM2MWifiMonitorModeCtrl *pstrMtrCtrl)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_enable_monitoring_mode(pstrMtrCtrl);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_disable_monitoring_mode(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_disable_monitoring_mode();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_change_monitoring_channel(uint8 u8ChannelID)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_change_monitoring_channel(u8ChannelID);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_send_wlan_pkt(uint8 *pu8WlanPacket, uint16 u16WlanHeaderLength, uint16 u16WlanPktSize)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_send_wlan_pkt(pu8WlanPacket, u16WlanHeaderLength, u16WlanPktSize);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_send_ethernet_pkt(uint8 *pu8Packet, uint16 u16PacketSize, uint8 u8IfcId)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_send_ethernet_pkt(pu8Packet, u16PacketSize, u8IfcId);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_cust_InfoElement(uint8 *pau8M2mCustInfoElement)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_cust_InfoElement(pau8M2mCustInfoElement);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_enable_mac_mcast(uint8 *pu8MulticastMacAddress, uint8 u8AddRemove)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_enable_mac_mcast(pu8MulticastMacAddress, u8AddRemove);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_enable_mcast_filter(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_enable_mcast_filter();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_disable_mcast_filter(void)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_disable_mcast_filter();

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_receive_buffer(void *pvBuffer, uint16 u16BufferLen)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_receive_buffer(pvBuffer, u16BufferLen);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_tx_power(uint8 u8TxPwrLevel)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_tx_power(u8TxPwrLevel);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_max_tx_rate(tenuTxDataRate enuMaxTxDataRate)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_max_tx_rate(enuMaxTxDataRate);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}


NMI_API sint8 os_m2m_wifi_set_antenna_mode(uint8 ant_mode, uint8 gpio_mode, uint8 ant_gpio1, uint8 ant_gpio2)
{
   sint8 status;

   //Get exclusive access
   osAcquireMutex(&netMutex);

   //Invoke underlying function
   status = m2m_wifi_set_antenna_mode(ant_mode, gpio_mode, ant_gpio1, ant_gpio2);

   //Release exclusive access
   osReleaseMutex(&netMutex);
   
   //Return status code
   return status;
}
