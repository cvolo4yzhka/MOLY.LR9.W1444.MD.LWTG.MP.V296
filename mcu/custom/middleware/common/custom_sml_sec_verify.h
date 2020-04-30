#ifndef __CUSTOM_SML_SEC_VERIFY_H__
#define __CUSTOM_SML_SEC_VERIFY_H__

#ifdef __SMB_SIMME_LOCK__ 

#include "cust_chl_interface.h"
#include "custom_nvram_sec.h"

typedef enum{
	TYPE_HCK_ALGO_NONE 					= 0,
	TYPE_HCK_PBKDF2_HMAC_SHA256_SALT128	= 1,
	TYPE_HCK_INTR_USE_END 				= 99,
	TYPE_HCK_EXT_USE_START 				= 100,
	/* Note for customer: please add customized enum value for HCK calculation algorithm here */ 
	TYPE_HCK_EXT_USE_END 				= 255
}TYPE_HCK_ALGO;

typedef enum{
	TYPE_SIG_NONE							= 0,
	TYPE_SIG_RSA_PSS_SHA256					= 1,
	TYPE_SIG_INTR_USE_END					= 99,
	TYPE_SIG_EXT_USE_START					= 100,
	/* Note for customer: please add customized enum value for signature verification algorithm here */
	TYPE_SIG_RSA_END 						= 255
}TYPE_SIG_ALGO;

typedef enum{
	ERR_SEC_CHECK_HCK_SUCCESS				= 0,
	ERR_SEC_CHECK_SIG_SUCCESS				= 0,
	ERR_SEC_CHECK_HCK_NONE_CMP_FAIL			= 1,
	ERR_SEC_CHECK_HCK_INVALID_INOUT			= 2,
	ERR_SEC_CHECK_HCK_UNSUPPORT_ALGO		= 3,
	ERR_SEC_CHECK_SIG_INVALID_INOUT			= 4,
	ERR_SEC_CHECK_PBKDF2_SHA256_SALT128		= 5,
	ERR_SEC_CHECK_PBKDF2_SHA256_SALT128_CMP_FAIL = 6,
	ERR_SEC_CHECK_SIG_VERIRY_FAIL			= 7,
	ERR_SEC_CHECK_SIG_UNSUPPORT_ALGO		= 8,
	ERR_SEC_INTR_USE_END					= 999,
	ERR_SEC_EXT_USE_START					= 1000,
	/* Note for customer: please add customized enum value for error code here */
	ERR_SEC_CHECK_END						= 0xFFFFFFFF
}TYPE_HCK_SIG_ERR;

typedef struct{
	kal_uint32		m_E_len;
	kal_uint32		m_N_len;
	kal_uint8		m_E_key[MAX_CUST_CHL_ASYM_KEY_LEN];
	kal_uint8		m_N_key[MAX_CUST_CHL_ASYM_KEY_LEN];
}gblob_rsa_pub_key_s;

kal_uint32 cust_sec_hck_verify (TYPE_HCK_ALGO algo, kal_char *ck, kal_uint32 ck_len, kal_uint8 *salt, kal_uint32 iter, kal_uint8 *hck);

kal_uint32 cust_sec_gblob_verify(sml_gblob_s_context_struct *data, void *key);

#endif  /* __SMB_SIMME_LOCK__ */

#endif
