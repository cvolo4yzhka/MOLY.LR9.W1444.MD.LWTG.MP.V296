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
 *   custom_emm_config.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file is used to define the EMM configuration.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "custom_emm_config.h"

//The mapping table of customized FTAI time and PLMN ID
kal_uint64 custom_plmn_ftai_table[CUSTOMIZED_PLMN_FTAI_NUM][CUSTOMIZED_PLMN_INFO_MAX]=
{

	 /* PLMN_ID (Hex)*/       /* FTAI_TIME (Dec)*/   
	{0xFFFFFFFFFFFFFFFF,             43200    }   //The default setting is 43200 seconds (12 hours)
	
	 /*Customized FTAI time*/
	 /*The notation of PLMN ID:
	     byte 8:0x00    byte 7:0x00    byte 6:MCC1    byte 5:MCC2    byte 4:MCC3    byte 3:MNC1    byte 2:MNC2    byte 1:MNC3
	     if PLMN ID does not have MNC3, then fill byte 1's value with 0x0F 

	     Ex:
	     {0x000000000100010F,	         86400	   }    // PLMN ID:00101  FTAI time :  86400 (24 hours) 
	  */

};



/**
 *  @brief  This function is used to obtain the period of erasing forbbiden TAI list 
 *
 *
 * @return    kal_uint32
 * @retval    the period to clear forbidden TAI list (in seconds)
 * 
 */
kal_uint32 emm_custom_get_default_ftai_timer_length()
{
    return (kal_uint32)(custom_plmn_ftai_table[DEFAULT_PLMN_FTAI_NUM][EMM_CUSTOM_PLMN_INFO_FTAI_TIME_LINE]);
}

/**
 *  @brief  This function is used to obtain the number of customized FTAI time 
 *
 *
 * @return    kal_uint32
 * @retval    the number of customized FTAI time
 * 
 */

kal_uint32 emm_custom_get_plmn_ftai_number()
{
	return CUSTOMIZED_PLMN_FTAI_NUM;
}

/**
 * @brief  This function is used to map air emm cause to custom emm cause.
 *         [Important] 
 *         Please note that as UE will behave as custom emm cause, 
 *         NW behavior is not predictable.
 *
 * @param[in]	emm_msg: air emm cause (24.301 Section 8.2 EPS mobility management messages)
 * @param[in] emm_cause: 24.301 Annex A Cause values for EPS mobility management
 * @param[in] is_hplmn: KAL_TRUE for hplmn
 * @param[in] is_test_sim: KAL_TRUE for test SIM
 *
 * @return    emm_cause_enum: custom emm cause (24.301 Section 8.2 EPS mobility management messages)
 */
emm_cause_enum emm_custom_get_customize_cause(emm_msg_type_enum emm_msg, emm_cause_enum emm_cause, kal_bool is_hplmn, kal_bool is_test_sim)
{
    emm_cause_enum cust_cause;
    
    // not enabled
    if (sbp_query_md_feature(SBP_EMM_CUST_MAP_EMM_CAUSE) == KAL_FALSE)
    {
        return emm_cause;
    }

    // not applicable for test SIM
    if (is_test_sim == KAL_TRUE)
    {
        return emm_cause;
    }

    switch (emm_msg)
    {
        case EMM_MSG_ATTACH_REJECT:
        case EMM_MSG_TAU_REJECT:
        	switch (emm_cause)
            {
                case EMM_CAUSE_ILLEGAL_UE:    // emm cause #3
                case EMM_CAUSE_ILLEGAL_ME:    // emm cause #6
                case EMM_CAUSE_EPS_NOT_ALLOWED:    // emm cause #7
                case EMM_CAUSE_EPS_NON_EPS_NOT_ALLOWED:    // emm cause #8
                    if (is_hplmn == KAL_TRUE)
                    {
                        // change to emm cause #15
                        cust_cause = EMM_CAUSE_NO_SUITABLE_CELL_IN_TA;
                    }
                    else if (emm_cause == EMM_CAUSE_EPS_NOT_ALLOWED)    // on VPLMN and emm cause #7
                    {
                        // change to emm cause #14
                        cust_cause = EMM_CAUSE_EPS_NOT_ALLOWED_IN_PLMN;
                    }
                    else    // on VPLMN
                    {
                    	// change to emm cause #13
                        cust_cause = EMM_CAUSE_ROAMING_NOT_ALLOWED_IN_TA;
                    }
                    break;

                default:
                    // no change
                    cust_cause = emm_cause;
                    break;
            }
            break;

        default:
            // no change
            cust_cause = emm_cause;
            break;
    }
    
    return cust_cause;
}


/**
 * @brief  This function is to get customized T3402 after a NW Deatch of type re-attach not required with some specific cause
 *
 * @param[in] emm_cause: 24.301 Annex A Cause values for EPS mobility management
 * @param[out] cust_t3402: the customized T3402 value
 *
 * @return	kal_bool
 * @retval  KAL_TRUE        Customized value is needed for this cause; cust_t3402 returns the value
 * @retval  KAL_FALSE      No customized value
 */
kal_bool emm_custom_get_t3402_nw_detach_other_cause(emm_cause_enum emm_cause, kal_uint16 *cust_t3402)
{
    switch (emm_cause)
    {
    case EMM_CAUSE_NO_EPS_CTXT_ACT:     // #40
        *cust_t3402 = CUSTOM_T3402_VALUE;
        return KAL_TRUE;
        break;

    default:
        break;
    }
    return KAL_FALSE;
}
