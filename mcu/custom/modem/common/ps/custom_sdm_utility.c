/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2015
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * custom_sdm_utility.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * This file is for sms domain management customization functions, 
 * customer can use these functions to configure parameters for SMS
 * domain selection. 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**   Includes
*/
#include <string.h>

#include "kal_general_types.h"
#include "custom_sdm_utility.h"


/*****************************************************************************
* FUNCTION
*   sms_over_sgs_preferred_in_lte
* DESCRIPTION
*   This function is used to define SMS over SGs preference to SMS over IP
*   for 4G MO SMS domain selection in specific networks (MCC & MNC) 
*
* PARAMETERS
*
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool sms_over_sgs_preferred_in_lte(char *mcc, char *mnc)
{
    /* When TRUE is returned, SMS over SGs is preferred over IMS */

    /* Telefonica Germany */
    if ( (strncmp(mcc, "262", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "07", 2) == 0) ||
              (strncmp(mnc, "77", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* Telefonica UK */
    if ( (strncmp(mcc, "234", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* VDF Spain */
    if ( (strncmp(mcc, "214", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* VDF Portugal */
    if ( (strncmp(mcc, "268", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* VDF UK */
    if ( (strncmp(mcc, "234", 3) == 0) && (strncmp(mnc, "15", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* VDF Netherlands */
    if ( (strncmp(mcc, "204", 3) == 0) && (strncmp(mnc, "04", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* VDF Ireland */
    if ( (strncmp(mcc, "272", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* Movistar Argentina */
    if ( (strncmp(mcc, "722", 3) == 0) && (strncmp(mnc, "07", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* ViVo Brazil */
    if ( (strncmp(mcc, "724", 3) == 0) && 
            ( (strncmp(mnc, "06", 2) == 0) ||
              (strncmp(mnc, "10", 2) == 0) ||
              (strncmp(mnc, "11", 2) == 0) ||
              (strncmp(mnc, "23", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* MegaFon Russia */
    if ( (strncmp(mcc, "250", 3) == 0) && 
            ( (strncmp(mnc, "02", 2) == 0) ||
              (strncmp(mnc, "11", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* TIM Italy */
    if ( (strncmp(mcc, "222", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* TIM Brazil */
    if ( (strncmp(mcc, "724", 3) == 0) && 
            ( (strncmp(mnc, "02", 2) == 0) ||
              (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "04", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* Movistar Mexico */
    if ( (strncmp(mcc, "334", 3) == 0) && (strncmp(mnc, "030", 3) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* Orange Spain */
    if ( (strncmp(mcc, "214", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "09", 2) == 0) ||
              (strncmp(mnc, "11", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }
    
    /* Orange France */
    if ( (strncmp(mcc, "208", 3) == 0) && 
            ( (strncmp(mnc, "01", 2) == 0) ||
              (strncmp(mnc, "02", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }
    
    /* Orange Romania */
    if ( (strncmp(mcc, "226", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* Orange Poland */
    if ( (strncmp(mcc, "260", 3) == 0) && (strncmp(mnc, "03", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* Orange Belgium */
    if ( (strncmp(mcc, "206", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* Etisalat United Arab Emirates */
    if ( (strncmp(mcc, "424", 3) == 0) && (strncmp(mnc, "02", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* STC Saudi Arabia */
    if ( (strncmp(mcc, "420", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* Digi Mobil Romania */
    if ( (strncmp(mcc, "226", 3) == 0) && (strncmp(mnc, "05", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* Bouygues France */
    if ( (strncmp(mcc, "208", 3) == 0) && (strncmp(mnc, "20", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* T-Star */
    if ( (strncmp(mcc, "466", 3) == 0) && 
            ( (strncmp(mnc, "89", 2) == 0) ||
              (strncmp(mnc, "90", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* Netherlands Telekom (T-Moble) */
    if ( (strncmp(mcc, "204", 3) == 0) && 
            ( (strncmp(mnc, "16", 2) == 0) ||
              (strncmp(mnc, "20", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* Telia Lithuania  */
    if ( (strncmp(mcc, "246", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* TMOEU Hungary */
    if ( (strncmp(mcc, "216", 3) == 0) && (strncmp(mnc, "30", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* TMOEU Croatia */
    if ( (strncmp(mcc, "219", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* TMOEU Slovakia */
    if ( (strncmp(mcc, "231", 3) == 0) && (strncmp(mnc, "02", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* TMOEU Austria */
    if ( (strncmp(mcc, "232", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "07", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* Tele2 Sweden */
    if ( (strncmp(mcc, "240", 3) == 0) && (strncmp(mnc, "07", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* Telenor Hungary */
    if ( (strncmp(mcc, "216", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* Telenor Bulgaria */
    if ( (strncmp(mcc, "284", 3) == 0) && (strncmp(mnc, "05", 2) == 0) )
    {
        return (KAL_TRUE);
    }
	
	/* Movistar Peru */
    if ( (strncmp(mcc, "716", 3) == 0) && (strncmp(mnc, "06", 2) == 0) )
    {
        return (KAL_TRUE);
    }
	
	/* Movistar Chile */
    if ( (strncmp(mcc, "730", 3) == 0) && (strncmp(mnc, "02", 2) == 0) )
    {
        return (KAL_TRUE);
    }
	
	/* Smart Philippines */
    if ( (strncmp(mcc, "515", 3) == 0) && (strncmp(mnc, "03", 2) == 0) )
    {
        return (KAL_TRUE);
    }
	
	/* MTN ZA South Africa */
    if ( (strncmp(mcc, "655", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* Avea Turkey */
    if ( (strncmp(mcc, "286", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "04", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }
	
	/* Movistar Colombia */
    if ( (strncmp(mcc, "732", 3) == 0) && (strncmp(mnc, "123", 3) == 0) )
    {
        return (KAL_TRUE);
    }
	
	/* Movistar Ecuador */
    if ( (strncmp(mcc, "740", 3) == 0) && (strncmp(mnc, "00", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* O2 Czech */
    if ( (strncmp(mcc, "230", 3) == 0) && (strncmp(mnc, "02", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    
    /* Vivacom Bulgaria */
    if ( (strncmp(mcc, "284", 3) == 0) && (strncmp(mnc, "03", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* NOS Portugal */
    if ( (strncmp(mcc, "268", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "07", 2) == 0) ||
              (strncmp(mnc, "99", 2) == 0) ) )
    {
        return (KAL_TRUE);
    }

    /* VDF New Zealand */
    if ( (strncmp(mcc, "530", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    /* C&W/Panama */
    if ( (strncmp(mcc, "714", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }    

    /* Entel/Chile */
    if ( (strncmp(mcc, "730", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }      

    /* Claro/Chile */
    if ( (strncmp(mcc, "730", 3) == 0) && (strncmp(mnc, "03", 2) == 0) )
    {
        return (KAL_TRUE);
    } 

    /* Default */
    return (KAL_FALSE);
}


/*****************************************************************************
* FUNCTION
*   sms_over_wifi_allowed
* DESCRIPTION
*   This function is used to define whether SMS over IP is allowed when using
*   WiFi access for MO SMS domain selection in specific networks (MCC & MNC) 
*
* PARAMETERS
*
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool sms_over_wifi_allowed(char *mcc, char *mnc)
{
    /* When TRUE is returned, SMS over IP is allowed on WiFi */

    /* Telefonica UK */
    if ( (strncmp(mcc, "234", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* VDF UK */
    if ( (strncmp(mcc, "234", 3) == 0) && (strncmp(mnc, "15", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* VDF Netherlands */
    if ( (strncmp(mcc, "204", 3) == 0) && (strncmp(mnc, "04", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* VDF Ireland */
    if ( (strncmp(mcc, "272", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_FALSE);
    }
    
    /* Telefonica Germany */
    if ( (strncmp(mcc, "262", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "07", 2) == 0) ||
              (strncmp(mnc, "77", 2) == 0) ) )
    {
        return (KAL_FALSE);
    }

    /* MegaFon Russia */
    if ( (strncmp(mcc, "250", 3) == 0) && 
            ( (strncmp(mnc, "02", 2) == 0) ||
              (strncmp(mnc, "11", 2) == 0) ) )
    {
        return (KAL_FALSE);
    }

    /* TIM Italy */
    if ( (strncmp(mcc, "222", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* TIM Brazil */
    if ( (strncmp(mcc, "724", 3) == 0) && 
            ( (strncmp(mnc, "02", 2) == 0) ||
              (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "04", 2) == 0) ) )
    {
        return (KAL_FALSE);
    }
    
    /* Orange Spain */
    if ( (strncmp(mcc, "214", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "09", 2) == 0) ||
              (strncmp(mnc, "11", 2) == 0) ) )
    {
        return (KAL_FALSE);
    }
    
    /* Orange France */
    if ( (strncmp(mcc, "208", 3) == 0) && 
            ( (strncmp(mnc, "01", 2) == 0) ||
              (strncmp(mnc, "02", 2) == 0) ) )
    {
        return (KAL_FALSE);
    }
    
    /* Orange Romania */
    if ( (strncmp(mcc, "226", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_FALSE);
    }
    
    /* Orange Poland */
    if ( (strncmp(mcc, "260", 3) == 0) && (strncmp(mnc, "03", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* Orange Belgium */
    if ( (strncmp(mcc, "206", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_FALSE);
    }
    
    /* Etisalat United Arab Emirates */
    if ( (strncmp(mcc, "424", 3) == 0) && (strncmp(mnc, "02", 2) == 0) )
    {
        return (KAL_FALSE);
    }
    
    /* STC Saudi Arabia */
    if ( (strncmp(mcc, "420", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_FALSE);
    }
    
    /* Digi Mobil Romania */
    if ( (strncmp(mcc, "226", 3) == 0) && (strncmp(mnc, "05", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* Telenor Hungary */
    if ( (strncmp(mcc, "216", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_FALSE);
    }  

    /* Telenor Bulgaria */
    if ( (strncmp(mcc, "284", 3) == 0) && (strncmp(mnc, "05", 2) == 0) )
    {
        return (KAL_FALSE);
    }
	
    /* Smart Philippines */
    if ( (strncmp(mcc, "515", 3) == 0) && (strncmp(mnc, "03", 2) == 0) )
    {
        return (KAL_FALSE);
    }
	
    /* MTN ZA South Africa */
    if ( (strncmp(mcc, "655", 3) == 0) && (strncmp(mnc, "10", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* Avea Turkey */
    if ( (strncmp(mcc, "286", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "04", 2) == 0) ) )
    {
        return (KAL_FALSE);
    }
	
	/* Movistar Argentina */
    if ( (strncmp(mcc, "722", 3) == 0) && (strncmp(mnc, "07", 2) == 0) )
    {
        return (KAL_FALSE);
    }
	
	/* Movistar Colombia */
    if ( (strncmp(mcc, "732", 3) == 0) && (strncmp(mnc, "123", 3) == 0) )
    {
        return (KAL_FALSE);
    }
    
    /* O2 Czech */
    if ( (strncmp(mcc, "230", 3) == 0) && (strncmp(mnc, "02", 2) == 0) )
    {
        return (KAL_FALSE);
    }
    
    /* Vivacom Bulgaria */
    if ( (strncmp(mcc, "284", 3) == 0) && (strncmp(mnc, "03", 2) == 0) )
    {
        return (KAL_FALSE);
    }

    /* NOS Portugal */
    if ( (strncmp(mcc, "268", 3) == 0) && 
            ( (strncmp(mnc, "03", 2) == 0) ||
              (strncmp(mnc, "07", 2) == 0) ||
              (strncmp(mnc, "99", 2) == 0) ) )
    {
        return (KAL_FALSE);
    }

    /* Default */
    return (KAL_TRUE);
}

/*****************************************************************************
* FUNCTION
*   sdm_retry_ims_when_ims_send_fail
* DESCRIPTION
*   This function is used to define retry IMS when IMS send fail for MO SMS
    in specific networks (MCC & MNC) 
*
* PARAMETERS
*
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool sdm_retry_ims_when_ims_send_fail(char *mcc, char *mnc)
{
    /* CT */
    if ( (strncmp(mcc, "460", 3) == 0) && (strncmp(mnc, "11", 2) == 0) )
    {
        return (KAL_TRUE);
    }

    return (KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*   sdm_get_retry_timer_by_operator
* DESCRIPTION
*   This function is used to define sdm_get_retry_timer_by_operator for MO SMS
    in specific networks (MCC & MNC) 
*
* PARAMETERS
*
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool sdm_get_retry_timer_by_operator(char *mcc, char *mnc, kal_uint8 *retry_timer)
{
	/* CT */
	if ( (strncmp(mcc, "460", 3) == 0) && (strncmp(mnc, "11", 2) == 0) )
	{
        *retry_timer = 30;
		return KAL_TRUE;
	}
    /* not match any operator */
    else
    {
        return KAL_FALSE; 
    }
}

/*****************************************************************************
* FUNCTION
*   sdm_cust_sms_over_wifi_preference
* DESCRIPTION
*   This function is used to customize the WiFI Preference for 
*   MO SMS domain selection in specific networks (MCC & MNC) 
*
* PARAMETERS
*
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
wfc_profile_enum sdm_cust_sms_over_wifi_preference(char *mcc, char *mnc, kal_uint8 mnc_len)
{
    /* Regardless the WFCP setting, customize the SMS over WIFI preference according to MCC/MNC */

    if(mnc_len != 3)
    {
        mnc_len = 2;
    }

    /* Claro Argentina */
    if ( (strncmp(mcc, "722", 3) == 0) && (strncmp(mnc, "310", mnc_len) == 0) )
    {
        return (WFC_PROFILE_CELLULAR_PREFERRED);
    }

    /* Default */
    return (WFC_PROFILE_NUM);
}

/*****************************************************************************
* FUNCTION
*   sms_over_cs_in_2g_call_allowed
* DESCRIPTION
*   This function is used to define whether SMS should be sent over CS when 2G
*   call is ongoing.
*
* PARAMETERS
*
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool sms_over_cs_when_2g_call_ongoing(char *mcc, char *mnc)
{
    /* When TRUE is returned, SMS over CS is atttempted
     * when call is ongoing 2G */

    /* Telia SE */
    if ( (strncmp(mcc, "240", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    /* A1 Austria */
    else if ( (strncmp(mcc, "232", 3) == 0) && (strncmp(mnc, "01", 2) == 0) )
    {
        return (KAL_TRUE);
    }
    return (KAL_FALSE);
}

/*****************************************************************************
* FUNCTION
*   sdm_cust_sms_over_ip_allowed
* DESCRIPTION
*   This function is used to define whether SMS over IP is allowed for 
*   MO SMS domain selection in specific networks (MCC & MNC) 
*
* PARAMETERS
*
* RETURNS
*   kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_bool sdm_cust_sms_over_ip_allowed(char *mcc, char *mnc, kal_uint8 mnc_len)
{

    /* When TRUE is returned, SMS over IP is allowed*/

    if(mnc_len != 3)
    {
        mnc_len = 2;
    }

    /* Movistar */
    if ( (strncmp(mcc, "722", 3) == 0) && (strncmp(mnc, "07", mnc_len) == 0) )
    {
        return (KAL_FALSE);
    }

    /* Vodafone India */
    if (((strncmp(mcc, "404", 3) == 0) && ((strncmp(mnc, "20", 2) == 0) || 
                                           (strncmp(mnc, "05", 2) == 0) || 
                                           (strncmp(mnc, "11", 2) == 0) ||          
                                           (strncmp(mnc, "30", 2) == 0) ||                    
                                           (strncmp(mnc, "86", 2) == 0) ||                    
                                           (strncmp(mnc, "84", 2) == 0) ||                    
                                           (strncmp(mnc, "13", 2) == 0) ||                    
                                           (strncmp(mnc, "88", 2) == 0) ||                    
                                           (strncmp(mnc, "15", 2) == 0) ||                    
                                           (strncmp(mnc, "01", 2) == 0) ||                    
                                           (strncmp(mnc, "60", 2) == 0) ||                    
                                           (strncmp(mnc, "46", 2) == 0) ||                    
                                           (strncmp(mnc, "27", 2) == 0) ||                    
                                           (strncmp(mnc, "43", 2) == 0) ))||
        ((strncmp(mcc, "405", 3) == 0) && ((strncmp(mnc, "67", 2) == 0) || 
                                           (strncmp(mnc, "66", 2) == 0) || 
                                           (strncmp(mnc, "753", 3) == 0) ||          
                                           (strncmp(mnc, "751", 3) == 0) ||                    
                                           (strncmp(mnc, "756", 3) == 0) ||                    
                                           (strncmp(mnc, "752", 3) == 0) ||                    
                                           (strncmp(mnc, "755", 3) == 0) ||                    
                                           (strncmp(mnc, "754", 3) == 0) ||                    
                                           (strncmp(mnc, "750", 3) == 0))))
    {
        return (KAL_FALSE);
    }    

    /* Default */
    return (KAL_TRUE);

}
