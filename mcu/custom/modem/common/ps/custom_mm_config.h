/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 *
 * Filename:
 * ---------
 * custom_mm_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the MM configuration.
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _CUSTOM_MM_CONFIG_H
#define _CUSTOM_MM_CONFIG_H

#include "kal_general_types.h"
#include "ps_public_utility.h"

/*************************************************************************
* Constant
*************************************************************************/
#define ALL_MCC_ALLOWED 0xfff
#define NO_MCC_ALLOWED 0xffffffff

extern const kal_uint32 ECC_IMSI_MCC_LIST[];
extern const kal_uint32 ECC_IMSI_MCC_NUM;

extern const kal_uint32 LR_BEFORE_ECC_MCC_LIST[];
extern const kal_uint32 LR_BEFORE_ECC_MCC_NUM;


#define CUSTOM_TEST_PLMN_SET_END "FFFFFF"
extern const char *CUSTOM_TEST_PLMN[];
extern const kal_uint32 CUSTOM_TEST_PLMN_NUM;

/* Ignore Reject cause 7, GPRS serive not allowed, in ATTACH REJECT or 
   in ROUTING AREA UPDATING REJECT message when roaming. Reject Cause 
   14, GPRS serive not allowed in this PLMN, insteads of */
#define IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_SET_END "FFFFFF"
extern const char *IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR[];
extern const kal_uint32 IGNORE_GPRS_SERVICE_NOT_ALLOWED_WHEN_ROAMING_OPERATOR_NUM;

#define DISABLE_SRVCC_IE_PLMN_SET_END "FFFFFF"
extern const char *DISABLE_SRVCC_IE_PLMN[];
extern const kal_uint32 DISABLE_SRVCC_IE_PLMN_NUM;

/* Disable CSMT flag in paging response for specific PLMNs */
#define DISABLE_PAGING_CSMT_FLAG_PLMN_END "FFFFFF"
extern const char *DISABLE_PAGING_CSMT_FLAG_PLMN[];
extern const kal_uint32 DISABLE_PAGING_CSMT_FLAG_PLMN_NUM;

/* Enable CSMT flag in paging response for specific PLMNs */
#define ENABLE_PAGING_CSMT_FLAG_PLMN_END "FFFFFF"
extern const char *ENABLE_PAGING_CSMT_FLAG_PLMN[];
extern const kal_uint32 ENABLE_PAGING_CSMT_FLAG_PLMN_NUM;

#define CUSTOM_CAUSE_PLMN_SET_ANY "FFFFFF"
extern const char *CUSTOM_CAUSE_PLMN[];
extern const kal_uint32 CUSTOM_CAUSE_PLMN_NUM;

/* Configure SKIP_LU_AFTER_CSFB_FOR_EAFR specific PLMNs */
#define CONFIGURE_SKIP_LU_AFTER_CSFB_FOR_EAFR_PLMN_END "FFFFFF"
extern const char *CONFIGURE_SKIP_LU_AFTER_CSFB_FOR_EAFR_PLMN[];
extern const kal_uint32 CONFIGURE_SKIP_LU_AFTER_CSFB_FOR_EAFR_PLMN_NUM;

/*************************************************************************
* Enum
*************************************************************************/
typedef enum
{
    MM_ENABLE_LR_REJ111_RETRY,
    MM_ENABLE_HPPLMN_SEARCH_FORCE_RELEASE_PCH_CONNECTION,
    MM_ECC_NOT_PREEMPT_SEARCH
}mm_setting_enum;

typedef enum
{
    MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_SERVICE,
    MM_STAY_ON_LA_OF_REGIONAL_PROVISIONAL_ONLY_IF_TEST_SIM_TEST_MODE,
    MM_NOT_STAY_ON_LA_OF_REGINOAL_PROVISIONAL_SERVICE
}mm_rej_12_handle_enum;

typedef enum
{
    MM_CUSTOM_UNKNOWN_PLMN_TYPE,
    MM_CUSTOM_HPLMN,
    MM_CUSTOM_R_E_PLMN
}mm_custom_plmn_type;

typedef enum
{
    MM_CUST_SIM1           =    0x0,
    MM_CUST_SIM2           =    0x1,
    MM_CUST_SIM3           =    0x2,
}mm_custom_sim_index;

typedef enum
{
    MM_CUST_PROC_LU         =    0x1,
    MM_CUST_PROC_ATTACH     =    0x2,
    MM_CUST_PROC_RAU        =    0x3,
}mm_custom_mm_proc;
typedef enum
{
    MM_CUSTOM_MM,
    MM_CUSTOM_GMM,
}mm_custom_proc_type;


typedef enum
{
    CUST_MM_MSG_LU_REJECT,
    CUST_MM_MSG_CM_SERVICE_REJECT,
    CUST_MM_MSG_ABORT,
    CUST_GMM_MSG_ATTACH_ACCEPT,
    CUST_GMM_MSG_ATTACH_REJECT,
    CUST_GMM_MSG_RAU_ACCEPT,
    CUST_GMM_MSG_RAU_REJECT,
    CUST_GMM_MSG_DETACH_REQUEST,
    CUST_GMM_MSG_SERVICE_REJECT
}mm_custom_proc_msg;


typedef enum
{
   MM_CUST_IMSI_UNKNOWN_IN_HLR            =     0x02,
   MM_CUST_ILLEGAL_MS                     =     0x03,
   MM_CUST_ILLEGAL_ME                     =     0x06,
   MM_CUST_GPRS_NOT_ALLOWED               =     0x07,
   MM_CUST_GPRS_NON_GPRS_NOT_ALLOWED      =     0x08,
   MM_CUST_ROAMING_AREA_NOT_ALLOWED       =     0x0d,  /* Cause #13 */
   MM_CUST_GPRS_NOT_ALLOWED_IN_PLMN       =     0x0e,  /* Cause #14*/
   MM_CUST_NO_SUITABLE_CELLS_IN_LA        =     0x15,  /* Cause #15 */
   MM_CUST_NETWORK_FAILURE                =     0x11,  /* Cause #17*/
}mm_custom_reject_cause;

/*************************************************************************
* Function
*************************************************************************/
extern kal_bool mm_custom_registration_related_setting(mm_setting_enum setting);

extern mm_rej_12_handle_enum mm_custom_stay_on_la_of_regional_provisional_service(void);

extern kal_bool mm_custom_allow_rplmn_hplmn_combined_search(void);

/* MAUI_03014009 Russia Operator BeeLine request to use ECC with IMEI */
extern kal_bool mm_custom_force_ecc_with_imei(void);

extern kal_bool mm_custom_is_try_abnormal_lai_once_more(void);

extern kal_bool mm_custom_start_timer_for_mt_mm_conn(void);

extern kal_uint32 mm_custom_get_erase_forbidden_la_list_timer_period(void);

extern kal_bool mm_custom_enable_early_oos_ind(void);

extern kal_bool mm_custom_reattach_for_mt_gprs_detach_other_cause(void);

extern kal_bool mm_custom_imsi_detach_when_mm_conn_active(void);
extern kal_bool mm_custom_report_cell_global_identity(void);

extern kal_bool mm_custom_csmt_flag_in_3g_paging_response(void);
extern kal_bool mm_custom_enable_dynamic_set_modem2_imei(void);

extern kal_bool mm_custom_report_reg_when_csfb_ecc_lu_delayed(mm_custom_plmn_type current_plmn_type);


extern kal_uint32 mm_custom_get_t3x11_period(void);
extern kal_bool mm_custom_use_minimum_T3212(void);

extern mm_custom_reject_cause mm_custom_cs_ps_reject_cause_transform
                        (mm_custom_reject_cause reject_cause ,kal_bool on_hplmn, mm_custom_mm_proc mm_proc,
			             mm_custom_sim_index sim_index);

extern kal_uint8 mm_custom_get_proc_cause_converter(kal_uint8 cause, mm_custom_proc_msg cust_proc, kal_bool is_on_hplmn, kal_bool is_test ,protocol_id_enum protocol_id);

#endif /* _CUSTOM_MM_CONFIG_H */

