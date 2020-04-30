#ifndef __WOD_CHANNEL_H__
#define __WOD_CHANNEL_H__

#include <utils/utils.h>

#define	MAX_VIP_NUM		2
#define	MAX_DNS_NUM		10
#define	MAX_PCSCF_NUM	10
#define	MAX_NETMASK_NUM	2
#define MAX_SUBNET_NUM	2
#define	IP_ADDR_LEN		16	//	xxx.xxx.xxx.xxx
#define	IP6_ADDR_LEN	40	//	xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx
#define MAX_BUF_LEN      1024

#if defined (ANDROID) || defined(STRONGSWAN_UNIT_TEST)
#define IS_MDMI_SUPPORTED()	false//property_get_bool("persist.mtk_mdmi_support", false)
#endif

typedef enum _imei_format_t {
	IMEI_BCD = 0,
	IMEI_STRING = 1,
} imei_format_t;

typedef enum wo_notify_cmd_t {
	N_ATTACH,
	N_DETACH,
	N_PCSCF,
	N_DNS,
	N_OOS_START,
	N_OOS_END,
	N_PCSCF_RESTORE,
	N_WDRV_KEEP_ALIVE,
	N_IKE_SRC_PORT,
	N_IKE_NATT_SRC_PORT,
	N_IKE_DECRYPT_ADD,
	N_IKE_DECRYPT_DEL,
	N_ESP_DECRYPT_ADD,
	N_ESP_DECRYPT_DEL
} wo_notify_cmd_t;

typedef struct conn_info {
	int status;
	int sub_error;
	int backoff_time;
	char ip[MAX_VIP_NUM][IP_ADDR_LEN];
	char ip6[MAX_VIP_NUM][IP6_ADDR_LEN];
	char dns[MAX_DNS_NUM][IP_ADDR_LEN];
	char dns6[MAX_DNS_NUM][IP6_ADDR_LEN];
	char pcscf[MAX_PCSCF_NUM][IP_ADDR_LEN];
	char pcscf6[MAX_PCSCF_NUM][IP6_ADDR_LEN];
	char netmask[MAX_NETMASK_NUM][IP_ADDR_LEN];
	char netmask6[MAX_NETMASK_NUM][IP6_ADDR_LEN];
	char subnet[MAX_SUBNET_NUM][IP_ADDR_LEN];
	char subnet6[MAX_SUBNET_NUM][IP6_ADDR_LEN];
} conn_info_prop;

typedef struct keepalive_info {
	bool enable;
	u_int32_t interval;
	char src_ip[IP6_ADDR_LEN];
	u_int16_t src_port;
	char dst_ip[IP6_ADDR_LEN];
	u_int16_t dst_port;
} keepalive_info_prop;

void notify_wod(wo_notify_cmd_t cmd, const char *value, void* param);
void notify_wod_attach_failed(const char *value, int status, int sub_error,int backoff_timer);
int atcmd_txrx(char *txbuf, char *rxbuf, int rxbuf_size, int *rxlen);
void notify_mdmi(wo_notify_cmd_t cmd, void *value);

#endif // __WOD_CHANNEL_H__

