/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   custom_sml_sec_verify.c
 *
 * Project:
 * --------
 *   UMOLYA
 *
 * Description:
 * ------------
 *   This file is used to define the SML security verification.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#ifdef __SMB_SIMME_LOCK__
#include "custom_sml_sec_verify.h"
#include "che_ossl_api.h"

//#define __GBLOB_DEBUG__

#if defined(__GBLOB_DEBUG__)
#include "dhl_trace.h"
#endif

kal_uint32 cust_sec_hck_verify (TYPE_HCK_ALGO algo, kal_char *ck, kal_uint32 ck_len, kal_uint8 *salt, kal_uint32 iter, kal_uint8 *hck){
	
	int ret = ERR_SEC_CHECK_HCK_UNSUPPORT_ALGO;	
	kal_uint8 hck_calc[64] = {0};
#if defined(__GBLOB_DEBUG__)	
	kal_uint32 i = 0;
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "ck_len: %x, algo: %x, ck: %x, hck: %x", ck_len, algo, ck, hck);
	for(i=0;i<ck_len;i++)
		dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "hck: %x", hck[i]);
#endif		
	if( (ck == NULL) || (hck == NULL) )
		return ERR_SEC_CHECK_HCK_INVALID_INOUT;
			
	switch(algo){
		case TYPE_HCK_ALGO_NONE:
			if(memcmp(ck, hck, ck_len) != 0){
				return ERR_SEC_CHECK_HCK_NONE_CMP_FAIL;
			}else{
				return ERR_SEC_CHECK_HCK_SUCCESS;
			}
			break;
		case TYPE_HCK_PBKDF2_HMAC_SHA256_SALT128:	//Fixed HCK: 32B, Salt: 16B
			if( (salt == NULL) || (ck_len == 0) )
				return ERR_SEC_CHECK_HCK_INVALID_INOUT;
				
			ret = PKCS5_PBKDF2_HMAC_SHA256(ck, ck_len, salt, 16, iter, 32, hck_calc);
			
			/* PKCS5_PBKDF2_HMAC_SHA256 if error occurs, internal hardcode return 1*/
			if( ret != 1 )
				return ERR_SEC_CHECK_PBKDF2_SHA256_SALT128;
			else if(memcmp(hck_calc, hck, 32) != 0)	
				return ERR_SEC_CHECK_PBKDF2_SHA256_SALT128_CMP_FAIL;
			else
				return ERR_SEC_CHECK_HCK_SUCCESS;	
			break;	
		default:
				return ERR_SEC_CHECK_HCK_UNSUPPORT_ALGO;
			break;	
	}
	return ret;	
}

kal_uint32 cust_sec_gblob_verify(sml_gblob_s_context_struct *data, void *key){

	TYPE_SIG_ALGO 	sig_algo;
	kal_uint32	  	ret = ERR_SEC_CHECK_SIG_UNSUPPORT_ALGO;
	kal_uint32		data_len = sizeof(sml_gblob_s_context_struct) - sizeof(data->signature);
	kal_uint32	  	data_start = (kal_uint32) data;
	kal_uint8*		sig = data->signature;
	kal_uint32		sig_len = sizeof(data->signature);
	t_cust_chl_asym_key		asym_key;	/* We default use RSA as our asymmetric key */
	gblob_rsa_pub_key_s*	rsa_pub_key_ptr;
#if defined(__GBLOB_DEBUG__)
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "sml_lock_rule: %x", data->sml_lock_type);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "sml_lock_sub_rule: %x %x", data->sml_lock_sub_type[0], data->sml_lock_sub_type[1]);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "dev_protection_algo: %x", data->dev_protection_algo);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "device_interation_cnt: %x %x %x %x", data->device_interation_cnt[0], data->device_interation_cnt[1], data->device_interation_cnt[2], data->device_interation_cnt[3]);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "device_salt: %x %x %x %x", data->device_salt[0], data->device_salt[1], data->device_salt[2], data->device_salt[3]);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "device_hck: %x %x %x %x", data->device_hck[0], data->device_hck[1], data->device_hck[2], data->device_hck[3]);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "sig_protection_algo: %x", data->sig_protection_algo);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "sig_len: %x", sig_len);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "signature: %x %x %x %x", data->signature[0], data->signature[1],data->signature[2],data->signature[3]);
#endif
	if( (data == NULL) || (key == NULL) ){
#if defined(__GBLOB_DEBUG__)		
		dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "data: %x, key:%x", data, key);
#endif		
		return ERR_SEC_CHECK_SIG_INVALID_INOUT;
	}	
	
	memcpy(&sig_algo, &(data->sig_protection_algo), sizeof(data->sig_protection_algo));
	
	switch(sig_algo){
		case TYPE_SIG_NONE:
			return ERR_SEC_CHECK_SIG_SUCCESS;
			break;
		case TYPE_SIG_RSA_PSS_SHA256:
			rsa_pub_key_ptr = (gblob_rsa_pub_key_s*)key;
			memcpy(asym_key.m_E_key, rsa_pub_key_ptr->m_E_key, sizeof(rsa_pub_key_ptr->m_E_key));
			memcpy(asym_key.m_N_key, rsa_pub_key_ptr->m_N_key, sizeof(rsa_pub_key_ptr->m_N_key));
			asym_key.m_E_len = rsa_pub_key_ptr->m_E_len;
			asym_key.m_N_len = rsa_pub_key_ptr->m_N_len;
			ret = CustCHL_Verify_RSA_Signature(CUST_CHL_ALG_RSA_PSS_SHA256,
                                        (kal_uint8*) data_start, 
                                        data_len,
                                        sig,
                                        sig_len,
                                        &asym_key);
            if( ret != ERR_SEC_CHECK_SIG_SUCCESS )
				return ret;
			else
				return ERR_SEC_CHECK_SIG_SUCCESS;	
			break;
		default:
				return ERR_SEC_CHECK_SIG_UNSUPPORT_ALGO;
			break;		
	}
	return ret;
}
#endif
