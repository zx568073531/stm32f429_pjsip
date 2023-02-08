#ifndef _M2M_WIFI_EX_H
#define _M2M_WIFI_EX_H

//Dependencies
#include "driver/include/m2m_wifi.h"

//Thread-safe functions
NMI_API sint8 os_m2m_wifi_init(tstrWifiInitParam *pWifiInitParam);
NMI_API sint8 os_m2m_wifi_deinit(void *arg);
NMI_API sint8 os_m2m_wifi_handle_events(void *arg);
NMI_API sint8 os_m2m_wifi_connect(char *pcSsid, uint8 u8SsidLen, uint8 u8SecType, tuniM2MWifiAuth *puniAuthInfo, uint16 u16Ch);
NMI_API sint8 os_m2m_wifi_disconnect(void);
NMI_API sint8 os_m2m_wifi_get_connection_info(void);
NMI_API sint8 os_m2m_wifi_set_mac_address(uint8 au8MacAddress0[6], uint8 au8MacAddress1[6]);
NMI_API sint8 os_m2m_wifi_wps(uint8 u8TriggerType, const char *pcPinNumber);
NMI_API sint8 os_m2m_wifi_wps_disable(void);
NMI_API sint8 os_m2m_wifi_p2p(uint8 u8Channel, tenuP2PTrigger enuTrigger, uint16 u16WPS_CfgMehods);
NMI_API sint8 os_m2m_wifi_p2p_disconnect(void);
NMI_API sint8 os_m2m_wifi_enable_ap(CONST tstrM2MAPConfig *pstrM2MAPConfig);
NMI_API sint8 os_m2m_wifi_disable_ap(void);
NMI_API sint8 os_m2m_wifi_ap_get_assoc_info(void);
NMI_API sint8 os_m2m_wifi_ap_add_black_list(uint8 bAddNewEntry, uint8 *mac_addr);
NMI_API sint8 os_m2m_wifi_set_scan_options(uint8 u8NumOfSlot, uint8 u8SlotTime);
NMI_API sint8 os_m2m_wifi_set_scan_region(uint8 ScanRegion);
NMI_API sint8 os_m2m_wifi_set_scan_list(tstrM2MScanList *pstrScanList);
NMI_API sint8 os_m2m_wifi_request_scan(uint8 ch);
NMI_API sint8 os_m2m_wifi_request_scan_ssid(uint8 ch, char *pcssid);
NMI_API uint8 os_m2m_wifi_get_num_ap_found(void);
NMI_API sint8 os_m2m_wifi_req_scan_result(uint8 index);
NMI_API sint8 os_m2m_wifi_req_curr_rssi(void);
NMI_API sint8 os_m2m_wifi_get_otp_mac_address(uint8 *pu8MacAddr, uint8 *pu8IsValid);
NMI_API sint8 os_m2m_wifi_get_mac_address(uint8 *pu8MacAddr0, uint8 *pu8MacAddr1);
NMI_API sint8 os_m2m_wifi_set_sleep_mode(uint8 PsTyp, uint8 BcastEn);
NMI_API uint8 os_m2m_wifi_get_sleep_mode(void);
NMI_API sint8 os_m2m_wifi_set_device_name(uint8 *pu8DeviceName, uint8 u8DeviceNameLength);
NMI_API sint8 os_m2m_wifi_set_p2p_pin(uint8 *pu8PinNumber, uint8 u8PinLength);
NMI_API sint8 os_m2m_wifi_allow_p2p_connection(void);
NMI_API sint8 os_m2m_wifi_set_lsn_int(tstrM2mLsnInt *pstrM2mLsnInt);
NMI_API sint8 os_m2m_wifi_enable_monitoring_mode(tstrM2MWifiMonitorModeCtrl *pstrMtrCtrl);
NMI_API sint8 os_m2m_wifi_disable_monitoring_mode(void);
NMI_API sint8 os_m2m_wifi_change_monitoring_channel(uint8 u8ChannelID);
NMI_API sint8 os_m2m_wifi_send_wlan_pkt(uint8 *pu8WlanPacket, uint16 u16WlanHeaderLength, uint16 u16WlanPktSize);
NMI_API sint8 os_m2m_wifi_send_ethernet_pkt(uint8 *pu8Packet, uint16 u16PacketSize, uint8 u8IfcId);
NMI_API sint8 os_m2m_wifi_set_cust_InfoElement(uint8 *pau8M2mCustInfoElement);
NMI_API sint8 os_m2m_wifi_enable_mac_mcast(uint8 *pu8MulticastMacAddress, uint8 u8AddRemove);
NMI_API sint8 os_m2m_wifi_enable_mcast_filter(void);
NMI_API sint8 os_m2m_wifi_disable_mcast_filter(void);
NMI_API sint8 os_m2m_wifi_set_receive_buffer(void *pvBuffer, uint16 u16BufferLen);
NMI_API sint8 os_m2m_wifi_set_tx_power(uint8 u8TxPwrLevel);
NMI_API sint8 os_m2m_wifi_set_max_tx_rate(tenuTxDataRate enuMaxTxDataRate);
NMI_API sint8 os_m2m_wifi_set_antenna_mode(uint8 ant_mode, uint8 gpio_mode, uint8 ant_gpio1, uint8 ant_gpio2);

#endif
