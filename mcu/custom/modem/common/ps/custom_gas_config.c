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
 * custom_gas_config.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the GAS configuration.
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

#include "kal_general_types.h"

/* For customer define the improved call prefer setting, TRUE: enable, FALSE: disable */
#define IMPROVED_CALL_PREFER_SETTING  KAL_TRUE

/* For customer define the L2 fill bits randomization setting, TRUE: enable, FALSE: disable(default setting) */
#define L2_FILL_BITS_RANDOMIZATION_SETTING  KAL_FALSE

/* 20130902 James: at%campreq: search specific channels */
/* The variable of the specific channel searching */
kal_bool gas_custom_specific_channel_srch = KAL_FALSE;

/* The number of specific channels */
#define NUM_OF_SPECIFIC_CHANNELS    16 

/* The specific channels */
kal_uint16 specific_arfcn[NUM_OF_SPECIFIC_CHANNELS] = 
{      1,    2,    3,    4, /* band value 1: gsm900 */
     131,  132,  133,  134, /* band value 2: gsm850 */
    1536, 1537, 1538, 1539, /* band value 3: pcs, need to add PCS tag (value 1024) */
                            /* ex. arfcn 512 of pcs should be 512 + 1024 = 1536    */
     512,  513,  514,  515  /* band value 4: dcs    */
};

/* Customer can set the total number of frequencies which are scanned for full band PLMN search/list. */
kal_uint16 gas_custom_max_arfcn_to_try = 100;

/* Customer can set the number of GSM cells of each GSM band to decode for PLMN search
* or PLMN List procedure. The impact is that the larger the number, the result will be more
* sensative under that environment, but it will spend longer time to finish the procedure.
* Please do not assign each value more than 255.
*/
kal_uint8 gas_custom_max_decoded_cell_a_band[] =
{
    32, /* PGSM900 */
    32, /* EGSM900 */
    32, /* RGSM900 */
    32, /* DCS1800 */
    32, /* PCS1900 */
    32, /* GSM450  */
    32, /* GSM480  */
    32  /* GSM850  */
};

/* rlac threshold in CSFB procedure, when a specific cell's power is above the set value,
 * MS will try to camp on this 2G cell
*/
kal_int16 gas_rlac_threshold_in_CSFB = -90;

/* the value of RXLEV_ACCESS_MIN */

kal_int16 rxlev_access_min = -90;

/* customer can set whether enable avoid fake cell feature. */
#define ENABLE_AVOID_FAKE_CELL_FEATURE KAL_TRUE
#define DISABLE_AVOID_FAKE_CELL_FEATURE KAL_FALSE
kal_bool gas_custom_fake_cell_feature = DISABLE_AVOID_FAKE_CELL_FEATURE;

/* the default value is true, means gaging low power switch is on */
kal_bool gas_custom_paging_low_power_switch = KAL_TRUE;

/* RRM will put the serving into barred list if rach fail count more than this count.*/
kal_uint16 max_rach_fail_count = 3;

/* threshold of ARFCN number, MS will based on the threshold adjust barred timer length.*/
kal_uint16 cell_count_threshold = 8;

/* RACH fail barred timer length.the max value is 30min, min value is 15s */
kal_uint16 max_bar_timer_period = 30;    /* unit: second */
kal_uint16 min_bar_timer_period = 30;    /* unit: second */

/* RACH fail barred timer default length.the value is 30s */
kal_uint16 bar_timer_default_period = 30;    /* unit: second */

/* During 2G to 4G high prio cell reselection, Reward LTE RSRP to 10 dBm */
kal_uint8 gas_custom_lte_rsrp_reward_threshold = 10;

/* the default value is 5s, means if any LTE cell is satisfied cell resel criteria and UMTS T_resel reached to 5s or below then reset its time */
kal_uint32 gas_custom_umts_cell_resel_penalty_time = 5; /* unit: second */

/* Customer can set the total number of frequencies which are tryed for stored list PLMN search.                    */
/* The default value of GAS turnable MAX ARFCN to try for stored list plmn search is 8 cells.                       */
/* The maximum number of turnable trying cell is 32 cells and the minimum number of turnable trying cell is 1 cell. */
/* Please note that increasing number of tryed cell may be increas risk of DUT out of service. Because of poor RF   */
/* level cell will be camped on when DUT camps to later ARFCN in order. The connection procedure maybe always fail. */
kal_uint32 custom_max_arfcn_to_try_for_stored_search = 8;  /* unit: cell */

/*****************************************************************************
* FUNCTION
*  rr_get_improved_call_prefer_setting
* DESCRIPTION
*   This function is used to define the improved call prefer setting
*   TRUE: enable improved call prefer, FALSE: disable improved call prefer
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool rr_get_improved_call_prefer_setting (void)
{
   return (IMPROVED_CALL_PREFER_SETTING);
}


/*****************************************************************************
* FUNCTION
*  rr_get_l2_fill_bits_randomization_setting
* DESCRIPTION
*   This function is used to define the L2 fill bits randomization setting
*   TRUE: enable L2 randomization, FALSE: disable L2 randomization
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool rr_get_l2_fill_bits_randomization_setting (void)
{
   return (L2_FILL_BITS_RANDOMIZATION_SETTING);
}

/*****************************************************************************
* FUNCTION
*  gas_custom_is_specific_channel_srch
* DESCRIPTION
*   The function returns whether UE is in specific channel search mode.
*
* PARAMETERS
*  Void
* RETURNS
*  kal_bool
*  TRUE: specific channel search mode, FALSE: normal search mode
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool gas_custom_is_specific_channel_srch(void)
{
    return gas_custom_specific_channel_srch;
}

/*****************************************************************************
* FUNCTION
*   gas_custom_get_num_of_specific_channels
* DESCRIPTION
*   The function returns the number of specific channels
*
* PARAMETERS
*  Void
* RETURNS
*  kal_unit16 the number of specific channels 
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 gas_custom_get_num_of_specific_channels(void)
{
    if (gas_custom_specific_channel_srch == KAL_TRUE)
    {
        return NUM_OF_SPECIFIC_CHANNELS;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
* FUNCTION
*   gas_custom_get_specific_channels
* DESCRIPTION
*   The function returns the number of specific channels
*
* PARAMETERS
*  Void
* RETURNS
*  kal_unit16 the number of specific channels 
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 * gas_custom_get_specific_channels(void)
{
    if (gas_custom_specific_channel_srch == KAL_TRUE)
    {
        return (&(specific_arfcn[0]));
    }
    else
    {
        return NULL;
    }
}

/*****************************************************************************
* FUNCTION
*  as_custom_set_specific_channel_srch
* DESCRIPTION
*   The function set specific search mode.
*
* PARAMETERS
*   kal_bool
*   TRUE: set specific search mode, FALSE: disable specific search mode.
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void gas_custom_set_specific_channel_srch( kal_bool set_value )
{
    gas_custom_specific_channel_srch = set_value;
}

/*****************************************************************************
* FUNCTION
*  as_custom_get_rlac_threshold_in_csfb
* DESCRIPTION
*   The function get rlac threshold in csfb procedure.
*
* PARAMETERS
*   kal_int16 rlac threshold in csfb procedure.
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_int16 as_custom_get_rlac_threshold_in_csfb (void)
{
    return gas_rlac_threshold_in_CSFB * 4;
}

#ifdef __A5_3_AND_GEA_WHILTE_LIST__

/*****************************************************************************
* FUNCTION
*  gas_custom_check_plmn_for_a5_gea
* DESCRIPTION
*  This function is for customizing PLMN in the  list, on which gas support A5 algorithms
* 
* PARAMETERS
* plmn_id : the currently camped plmn/plmn in IMSI. the plmn is taken in the form of uint32. Each nibble holds each part of plmn.
*           each nibble in plmn ID stands for: XXXX XXXX===> X->spare(most significant nibble), X->spare, X->mcc1, X->mcc2, X->mcc3, X->mnc1, X->mnc2, X->mnc3(least significant nibble)
*
* a5        The value in this variable is filled bit wise and as per spec 24.008
*           this variable is used to set the a5 algo based on the plmn match. this indicates algo support in bit map format
*             XXXX XXXX => spear bit(MSB), a5/1, a5/2, a5/3, a5/4, a5/5, a5/6,a5/7(LSB)
*            For a51 bit  ==> bit value 0 ==> algo enabled
*                         ==> bit value 1 ==> algo disabled
*            for rest of the algo(a52 to a57)
*             bit value 0 => algo disabled
*             bit value 1 =>  algo enabled
*
* gea       : this variable is used to enable/disable the gea_x algo.
*             XXXX XXXX => spear bit(MSB), gea/1, gea/2, gea/3, gea/4, gea/5, gea/6,gea/7(LSB)
*             when bit value is set as 1, then corresponding gea algo is made enabled
*             when bit value is set as 0, then corresponding gea algo is made disabled
*           
* RETURNS
* plmn_match : if true, then the camped plmn is matched in the list of customer specified plmn
*              if false, then the camped plmn is not matched in the list of customer specified plmn       
* 
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool gas_custom_check_plmn_for_a5_gea(kal_uint32 plmn_id, kal_uint8 *a5, kal_uint8 *gea )
{
     kal_bool plmn_match = KAL_FALSE;
  
    /* each bit in the uint a5 stands for each a5/x algo as explained in description of function   */

	switch(plmn_id)
    {

	/*Please add  plmn list (as format explained in description )below for enabling and disabling a5/x algorithm */
	
     /*case 0x0046697f: *a5 = 0x60;                  
                      *gea =  0x60;	     
                       plmn_match = KAL_TRUE;
                       break; */  

          default: plmn_match = KAL_FALSE;
                        break; 
    }  	
    
    return plmn_match ;
}

#endif /* __A5_3_AND_GEA_WHILTE_LIST__ */


/*****************************************************************************
* FUNCTION
*  as_custom_get_rxlev_access_min
* DESCRIPTION
*   get the value of rxlev access min
*
* PARAMETERS
*   void
* RETURNS
*   the value of rxlev access min
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_int16 as_custom_get_rxlev_access_min (void)
{
	return rxlev_access_min;
}

/*****************************************************************************
* FUNCTION
*  gas_custom_get_fake_cell_feature_mode
* DESCRIPTION
*   The function get fake cell feature mode.
*
* PARAMETERS
*   Void
* RETURNS
*   kal_bool
*   TRUE: enable fake cell feature, FALSE: disable fake cell feature.
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool gas_custom_get_fake_cell_feature_mode (void)
{
    return gas_custom_fake_cell_feature;
}

/*****************************************************************************
* FUNCTION
*  gas_custom_get_paging_low_power_switch
* DESCRIPTION
*   The function get paging low power switch.
*
* PARAMETERS
*   Void
* RETURNS
*   kal_bool
*   TRUE: low power switch is on, FALSE: low power switch is off.
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool gas_custom_get_paging_low_power_switch (void)
{
    return gas_custom_paging_low_power_switch;
}


/*****************************************************************************
* FUNCTION
*  as_custom_get_max_rach_fail_count
* DESCRIPTION
*   The function get max rach fail count, RRM will put the 
*   serving into barred list if rach fail count more than this count.
*
* PARAMETERS
*   kal_uint16 max rach fail count.
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 as_custom_get_max_rach_fail_count (void)
{
	return max_rach_fail_count;
}

/*****************************************************************************
* FUNCTION
*  as_custom_get_bar_timer_period
* DESCRIPTION
*   RACH fail barred timer length
*
* PARAMETERS
*   kal_uint16 RACH fail barred timer length.
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint16 as_custom_get_bar_timer_period (kal_uint8 arfcn_count)
{
	kal_uint16 bar_timer_period = 30;

	if (arfcn_count >= cell_count_threshold)
	{
		bar_timer_period = max_bar_timer_period;
	}
	else
{
		bar_timer_period = min_bar_timer_period;
	}

	return bar_timer_period;
}

/*****************************************************************************
* FUNCTION
*  as_custom_get_bar_timer_default_period
* DESCRIPTION
*   RACH fail barred timer default length
*
* PARAMETERS
*   kal_uint16 RACH fail barred timer default length.
* RETURNS
*   Void
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint16 as_custom_get_bar_timer_default_period (void)
{
    return bar_timer_default_period;
}

/*****************************************************************************
* FUNCTION
*  gas_custom_get_lte_rsrp_reward_threshold
* DESCRIPTION
*   The function is used to get the LTE RSRP reward theshold during high prio cell reselection.
*
* PARAMETERS
*   Void
* RETURNS
*   kal_uint8
*   
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 gas_custom_get_lte_rsrp_reward_threshold (void)
{
    return gas_custom_lte_rsrp_reward_threshold;
}

/*****************************************************************************
* FUNCTION
*  gas_custom_get_umts_cell_resel_penalty_time
* DESCRIPTION
*   The function get time value of UMTS cell resel penalty.
*
* PARAMETERS
*   Void
* RETURNS
*   kal_uint32: default time of umts penalty
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 gas_custom_get_umts_cell_resel_penalty_time (void)
{
    return gas_custom_umts_cell_resel_penalty_time;

}

/*****************************************************************************
* FUNCTION
*  gas_custom_max_arfcn_to_try_for_stored_list_search
* DESCRIPTION
*   The function to get the customer set max cell number for stored list plmn search.
*
* PARAMETERS
*   Void
* RETURNS
*   kal_uint32: default number of max ARFCN to try for stored list search
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 gas_custom_max_arfcn_to_try_for_stored_list_search (void)
{
    return custom_max_arfcn_to_try_for_stored_search;

}
#ifdef __VAMOS_CUSTOM_CONFIG__
/*****************************************************************************
* FUNCTION
*  gas_custom_check_plmn_for_vamos
* DESCRIPTION
*  This function is for customizing PLMN in the  list and VAMOS support for the added PLMN
* 
* PARAMETERS
* plmn_id : the currently camped plmn/plmn in IMSI. the plmn is taken in the form of uint32. Each nibble holds each part of plmn.
*           each nibble in plmn ID stands for: XXXX XXXX===> X->spare(most significant nibble), X->spare, X->mcc1, X->mcc2, X->mcc3, X->mnc1, X->mnc2, X->mnc3(least significant nibble)
*
* vamos: the value can be either 1 for vamos1 or 2 for vamos2 support
*           
* RETURNS
* plmn_match : if true, then the camped plmn is matched in the list of customer specified plmn
*              if false, then the camped plmn is not matched in the list of customer specified plmn       
* 
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool gas_custom_check_plmn_for_vamos(kal_uint32 plmn_id, kal_uint8 *vamos)
{
    kal_bool plmn_match = KAL_FALSE;
      

    switch(plmn_id)
    {
    
      /*Please add  plmn list (as format explained in description )below for setting the vamos values */
        
      /* example to set vamos for a specific plmn is given below */
      case 0x0072207f:   /* Argentina  */
      case 0x0073002f:   /* Chile  */
      case 0x0073007f:   /* Chile  */
      case 0x00732123:   /* Columbia  */
      case 0x0071204f:   /* Costa Rica  */
      case 0x0074000f:   /* Ecqador  */
      case 0x0070604f:   /* Salvador  */
      case 0x0070403f:   /* Guatemala  */
      case 0x0033403f:   /* Mexico  */
      case 0x00710300:   /* Nicaragua  */
      case 0x0071420f:   /* Panama  */
      case 0x0074807f:   /* Uruguay  */
      case 0x0073404f:   /* Venezuela  */
                        *vamos = 0x00;                  
                          plmn_match = KAL_TRUE;
                             break;  
         
          default: plmn_match = KAL_FALSE;
                   break; 
        }   
        
        return plmn_match ;
    }


#endif /* __VAMOS_CUSTOM_CONFIG__ */
