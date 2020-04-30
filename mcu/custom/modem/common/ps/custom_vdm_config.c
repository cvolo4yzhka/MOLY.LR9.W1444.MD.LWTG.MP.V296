/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2017
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
 *   custom_vdm_config.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file is used to define the VDM configuration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#include "custom_vdm_config.h"


/*****************************************************************************
* FUNCTION
*   vdm_custom_disable_emergency_allow_ims
* DESCRIPTION
*   This function is used to define allow_ims for emergency call is disabled for
*   specific operator
* PARAMETERS
*   sim_sbp_id
* RETURNS
*   KAL_FALSE:default (read nvram)
    KAL_TRUE:allow_ims for emergency is disabled
*****************************************************************************/
kal_bool vdm_custom_disable_emergency_allow_ims(void)
{
    kal_uint8 imsi[9], mnc_length = 0;
    kal_uint16 mcc = 0, mnc = 0;

    l4csmu_get_imsi_by_idx((kal_uint8*) imsi, 0);
    mnc_length = sim_query_mnc_num(SIM1);

    mcc = (imsi[0]>>4)*100 + (imsi[1]&0x0f)*10 + (imsi[1]>>4);
    mnc = (imsi[2]&0x0f)*10 + (imsi[2]>>4);
    
    if (mnc_length == 3)
    {
        mnc = mnc*10 + (imsi[3]&0x0f);
    }
    else
    {
        // treat the length of mnc is 2 because some SIM card don't have MNC length value in the EF_AD.
    }

    /* disable emergency allow_ims according to MCC/MNC */

    if ( ((mcc == 238) && (mnc == 01)) ||
         ((mcc == 238) && (mnc == 10)) )
    {
        return KAL_TRUE; // Denmark TDC
    }
    else if ( ((mcc == 466) && (mnc == 89)) ||
              ((mcc == 466) && (mnc == 90)) )
    {
        return KAL_TRUE; // T-star
    }
    else if ( ((mcc == 204) && (mnc == 16)) ||
              ((mcc == 204) && (mnc == 20)) )
    {
        return KAL_TRUE; // Telekom (T-Moble) Netherlands
    }
    else if ((mcc == 204) && (mnc == 02))
    {
        return KAL_TRUE; // Tele2 Netherlands
    }
    else if ((mcc == 246) && (mnc == 01))
    {
        return KAL_TRUE; // Telia Lithuania
    }
    else if ((mcc == 206) && (mnc == 01))
    {
        return KAL_TRUE; // Proximus Belgium
    }
    else if ((mcc == 655) && (mnc == 02))
    {
        return KAL_TRUE; // Telkom South Afr
    }
    else if ((mcc == 216) && (mnc == 01))
    {
        return KAL_TRUE; // Telenor Hungary
    }
    else if ((mcc == 452) && (mnc == 04))
    {
        return KAL_TRUE; // Viettel Vietnum
    }
    else if ((mcc == 716) && (mnc == 06))
    {
        return KAL_TRUE; // Movistar Peru
    }
    else if ((mcc == 730) && (mnc == 02))
    {
        return KAL_TRUE; // Movistar Chile
    }
    else if ((mcc == 515) && (mnc == 03))
    {
        return KAL_TRUE; // Smart Philippines
    }
    else if ((mcc == 655) && (mnc == 10))
    {
        return KAL_TRUE; // MTN ZA South Africa
    }
    else if ((mcc == 722) && (mnc == 07))
    {
        return KAL_TRUE; // MoviStar Argentina
    }
    else if ((mcc == 730) && (mnc == 03))
    {
        return KAL_TRUE; // Claro Chile
    }
    else if ((mcc == 732) && (mnc == 123))
    {
        return KAL_TRUE; // Movistar Colombia
    }
    else if ((mcc == 740) && (mnc == 00))
    {
        return KAL_TRUE; // Movistar Ecuador
    }
    else if ((mcc == 334) && (mnc == 030))
    {
        return KAL_TRUE; // Movistar Mexico
    }
    else if ((mcc == 250) && (mnc == 99))
    {
        return KAL_TRUE; // Beeline Russia
    }
    else /* default */
    {
        return KAL_FALSE;
    }

}


/*****************************************************************************
* FUNCTION
*   vdm_custom_disable_emergency_allow_wfc
* DESCRIPTION
*   This function is used to define allow_wfc for emergency call is disabled for
*   specific operator
* PARAMETERS
*   NONE
* RETURNS
*   KAL_FALSE:default (read nvram)
    KAL_TRUE:allow_ims for emergency is disabled
*****************************************************************************/
kal_bool vdm_custom_disable_emergency_allow_wfc(void)
{
    kal_uint8 imsi[9], mnc_length = 0;
    kal_uint16 mcc = 0, mnc = 0;

    l4csmu_get_imsi_by_idx((kal_uint8*) imsi, 0);
    mnc_length = sim_query_mnc_num(SIM1);

    mcc = (imsi[0]>>4)*100 + (imsi[1]&0x0f)*10 + (imsi[1]>>4);
    mnc = (imsi[2]&0x0f)*10 + (imsi[2]>>4);
    
    if (mnc_length == 3)
    {
        mnc = mnc*10 + (imsi[3]&0x0f);
    }
    else
    {
        // treat the length of mnc is 2 because some SIM card don't have MNC length value in the EF_AD.
    }

    /* disable emergency allow_ims according to MCC/MNC */
    if ((mcc == 216) && (mnc == 01))
    {
        return KAL_TRUE; // Telenor Hungary
    }
    else if ((mcc == 655) && (mnc == 02))
    {
        return KAL_TRUE; // Telkom South Afr
    }
    else if ((mcc == 716) && (mnc == 06))
    {
        return KAL_TRUE; // Movistar Peru
    }
    else if ((mcc == 730) && (mnc == 02))
    {
        return KAL_TRUE; // Movistar Chile
    }
    else if ((mcc == 515) && (mnc == 03))
    {
        return KAL_TRUE; // Smart Philippines
    }
    else if ((mcc == 655) && (mnc == 10))
    {
        return KAL_TRUE; // MTN ZA South Africa
    }
    else if ((mcc == 722) && (mnc == 07))
    {
        return KAL_TRUE; // MoviStar Argentina
    }
    else if ((mcc == 730) && (mnc == 03))
    {
        return KAL_TRUE; // Claro Chile
    }
    else if ((mcc == 732) && (mnc == 123))
    {
        return KAL_TRUE; // Movistar Colombia
    }
    else if ((mcc == 740) && (mnc == 00))
    {
        return KAL_TRUE; // Movistar Ecuador
    }
    else if ((mcc == 334) && (mnc == 030))
    {
        return KAL_TRUE; // Movistar Mexico
    }
    else if ((mcc == 250) && (mnc == 99))
    {
        return KAL_TRUE; // Beeline Russia
    }
    else if ((mcc == 216) && (mnc == 03))
    {
        return KAL_TRUE; // Digi Hungary
    }
    else /* default */
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
* FUNCTION
*   vdm_custom_cellular_prefer_check_vowifi_first
* DESCRIPTION
*   This function is used to define if VoWiFi should be used for MO call
*   setup in cellular preferred mode when IMS is registered on WiFi for
*   specific operator
* PARAMETERS
*   void
* RETURNS
*   KAL_FALSE: default (CS domain is checked before VoWiFi in cellular 
*                       preferred mode)
*   KAL_TRUE: VoWiFi is checked first, if IMS is registered over WiFi it
*             should be preferred over CS in cellular preferred mode
*****************************************************************************/
kal_bool vdm_custom_cellular_prefer_check_vowifi_first(void)
{
    kal_uint8 imsi[9], mnc_length = 0;
    kal_uint16 mcc = 0, mnc = 0;

    l4csmu_get_imsi_by_idx((kal_uint8*) imsi, 0);
    mnc_length = sim_query_mnc_num(SIM1);

    mcc = (imsi[0]>>4)*100 + (imsi[1]&0x0f)*10 + (imsi[1]>>4);
    mnc = (imsi[2]&0x0f)*10 + (imsi[2]>>4);
    
    if (mnc_length == 3)
    {
        mnc = mnc*10 + (imsi[3]&0x0f);
    }
    else
    {
        // treat the length of mnc is 2 because some SIM card don't have MNC length value in the EF_AD.
    }

    /* enable checking vowifi first in cellular preferred mode according to MCC/MNC */

    if ( ((mcc == 234) && (mnc == 15)) ||
         ((mcc == 234) && (mnc == 27)) ||
         ((mcc == 234) && (mnc == 91)) ||
         ((mcc == 235) && (mnc == 91)) ||
         ((mcc == 222) && (mnc ==  6)) ||
         ((mcc == 222) && (mnc == 10)) ||
         ((mcc == 262) && (mnc ==  2)) ||
         ((mcc == 262) && (mnc ==  4)) ||
         ((mcc == 262) && (mnc ==  9)) ||
         ((mcc == 268) && (mnc ==  1)) ||
         ((mcc == 214) && (mnc ==  1)) ||
         ((mcc == 214) && (mnc ==  6)) ||
         ((mcc == 286) && (mnc ==  2)) ||
         ((mcc == 204) && (mnc ==  4)) ||
         ((mcc == 230) && (mnc ==  3)) ||
         ((mcc == 202) && (mnc ==  5)) ||
         ((mcc == 655) && (mnc ==  1)) ||
         ((mcc == 645) && (mnc ==  5)) ||
         ((mcc == 602) && (mnc ==  2)) )
    {
        return KAL_TRUE; // Vodafone (SBP_ID = 6), all countries
    }
    else if ( ((mcc == 208) && (mnc ==  1)) ||
              ((mcc == 208) && (mnc ==  2)) ||
              ((mcc == 208) && (mnc == 29)) ||
              ((mcc == 208) && (mnc == 91)) ||
              ((mcc == 340) && (mnc ==  1)) ||
              ((mcc == 214) && (mnc ==  3)) ||
              ((mcc == 214) && (mnc ==  9)) ||
              ((mcc == 214) && (mnc == 11)) ||
              ((mcc == 602) && (mnc ==  1)) ||
              ((mcc == 260) && (mnc ==  3)) ||
              ((mcc == 226) && (mnc == 10)) ||
              ((mcc == 231) && (mnc ==  1)) ||
              ((mcc == 206) && (mnc == 10)) )
    {
        return KAL_TRUE; // Orange (SBP_ID = 3), all countries
    }
    else if ( ((mcc == 262) && (mnc ==  1)) ||
              ((mcc == 262) && (mnc ==  6)) ||
              ((mcc == 260) && (mnc ==  2)) ||
              ((mcc == 260) && (mnc == 34)) ||
              ((mcc == 230) && (mnc ==  1)) ||
              ((mcc == 219) && (mnc ==  1)) ||
              ((mcc == 202) && (mnc ==  1)) ||
              ((mcc == 202) && (mnc ==  2)) ||
              ((mcc == 216) && (mnc == 30)) ||
              ((mcc == 204) && (mnc == 16)) ||
              ((mcc == 204) && (mnc == 20)) ||
              ((mcc == 231) && (mnc ==  2)) ||
              ((mcc == 231) && (mnc ==  4)) ||
              ((mcc == 232) && (mnc ==  3)) ||
              ((mcc == 232) && (mnc ==  7)) )
    {
        return KAL_TRUE; // TMO EU (SBP_ID = 5), all countries
    }
    else if ( ((mcc == 244) && (mnc == 91)) ||
              ((mcc == 246) && (mnc ==  1)) ||
              ((mcc == 248) && (mnc ==  1)) ||
              ((mcc == 242) && (mnc ==  2)) ||
              ((mcc == 242) && (mnc ==  5)) ||
              ((mcc == 240) && (mnc ==  1)) ||
              ((mcc == 240) && (mnc ==  5)) )
    {
        return KAL_TRUE; // Telia (SBP_ID = 154), all countries
    }
    else if ( ((mcc == 234) && (mnc == 20)) ||
              ((mcc == 235) && (mnc == 94)) ||
              ((mcc == 240) && (mnc ==  2)) ||
              ((mcc == 238) && (mnc ==  6)) ||
              ((mcc == 232) && (mnc ==  5)) ||
              ((mcc == 232) && (mnc == 10)) )
    {
        return KAL_TRUE; // H3G (SBP_ID = 11), all countries
    }
    else if ( ((mcc == 234) && (mnc ==  2)) ||
              ((mcc == 234) && (mnc == 10)) ||
              ((mcc == 262) && (mnc ==  7)) ||
              ((mcc == 262) && (mnc ==  8)) )
    {
        return KAL_TRUE; // Telefonica (O2) (SBP_ID = 15), all countries
    }
    else if ( ((mcc == 235) && (mnc ==  2)) ||
              ((mcc == 234) && (mnc == 30)) ||
              ((mcc == 234) && (mnc == 33)) ||
              ((mcc == 234) && (mnc == 34)) ||
              ((mcc == 234) && (mnc == 86)) )
    {
        return KAL_TRUE; // EE (SBP_ID = 16), GB
    }
    else if ( ((mcc == 647) && (mnc == 10)) ||
              ((mcc == 208) && (mnc ==  9)) ||
              ((mcc == 208) && (mnc == 10)) ||
              ((mcc == 208) && (mnc == 11)) ||
              ((mcc == 208) && (mnc == 13)) )
    {
        return KAL_TRUE; // SFR (SBP_ID = 107), all countries
    }
    else if ( ((mcc == 334) && (mnc ==  2)) ||
              ((mcc == 334) && (mnc == 20)) )
    {
        return KAL_TRUE; // SFR (SBP_ID = 112), TelCel Mexico
    }
    else if ( ((mcc == 250) && (mnc ==  2)) ||
              ((mcc == 250) && (mnc == 11)) ||
              ((mcc == 250) && (mnc == 30)) )
    {
        return KAL_TRUE; // Megafon (SBP_ID = 127), RU
    }
    else if ( (mcc == 244) && (mnc ==  5) )
    {
        return KAL_TRUE; // Elisa (SBP_ID = 134), FI
    }
    else if ( ((mcc == 250) && (mnc ==  1)) ||
              ((mcc == 250) && (mnc ==  4)) ||
              ((mcc == 250) && (mnc ==  5)) ||
              ((mcc == 250) && (mnc == 10)) ||
              ((mcc == 250) && (mnc == 13)) ||
              ((mcc == 250) && (mnc == 39)) ||
              ((mcc == 250) && (mnc == 92)) ||
              ((mcc == 250) && (mnc == 93)) )
    {
        return KAL_TRUE; // MTS (SBP_ID = 135), RU
    }
    else if ( (mcc == 286) && (mnc ==  1) )
    {
        return KAL_TRUE; // Turkcell (SBP_ID = 143), TR
    }
    else if ( ((mcc == 424) && (mnc ==  2)) ||
              ((mcc == 602) && (mnc ==  3)) )
    {
        return KAL_TRUE; // Etisalat (SBP_ID = 146), all countries
    }
    else if ( (mcc == 420) && (mnc ==  4) )
    {
        return KAL_TRUE; // Zain (SBP_ID = 158), SA
    }
    else if ( (mcc == 655) && (mnc ==  7) )
    {
        return KAL_TRUE; // CellC (SBP_ID = 141), ZA
    }
    else if ( (mcc == 655) && (mnc == 10) )
    {
        return KAL_TRUE; // MTN (SBP_ID = 140), ZA
    }
    else if ( ((mcc == 260) && (mnc ==  6)) ||
              ((mcc == 260) && (mnc == 98)) )
    {
        return KAL_TRUE; // Play (SBP_ID = 161), PL
    }
    else if ( ((mcc == 226) && (mnc ==  5)) ||
              ((mcc == 216) && (mnc ==  3)) )
    {
        return KAL_TRUE; // Digi (SBP_ID = 155), all countries
    }
    else if ( (mcc == 244) && (mnc == 12) )
    {
        return KAL_TRUE; // DNA (SBP_ID = 128), FI
    }
    else if ( ((mcc == 228) && (mnc ==  1)) ||
              ((mcc == 295) && (mnc ==  1)) )
    {
        return KAL_TRUE; // Swisscom (SBP_ID = 150), all countries
    }
    else if ( ((mcc == 238) && (mnc ==  2)) ||
              ((mcc == 238) && (mnc == 77)) ||
              ((mcc == 242) && (mnc ==  1)) ||
              ((mcc == 284) && (mnc ==  5)) ||
              ((mcc == 240) && (mnc ==  8)) )
    {
        return KAL_TRUE; // Telenor (SBP_ID = 156), all countries
    }
    else if ( ((mcc == 238) && (mnc ==  1)) ||
              ((mcc == 238) && (mnc == 10)) )
    {
        return KAL_TRUE; // TDC (SBP_ID = 175), DK
    }
    else if ( (mcc == 232) && (mnc ==  1) )
    {
        return KAL_TRUE; // A1 (SBP_ID = 188), AT
    }
    else if ( ((mcc == 208) && (mnc == 20)) ||
              ((mcc == 208) && (mnc == 88)) )
    {
        return KAL_TRUE; // Bouygues (SBP_ID = 139), FR
    }
    else if ( (mcc == 206) && (mnc ==  1) )
    {
        return KAL_TRUE; // Proximus (SBP_ID = 182), BE
    }
    else if ( (mcc == 655) && (mnc ==  2) )
    {
        return KAL_TRUE; // Telkom South-Africa (SBP_ID = 181), ZA
    }
    else if ( (mcc == 228) && (mnc ==  2) )
    {
        return KAL_TRUE; // Sunrise Switzerland (SBP_ID = 165), CH
    }
    else if ( (mcc == 418) && (mnc == 66) )
    {
        return KAL_TRUE; // Newroz Iraq (SBP_ID = 179), IQ
    }
    else if ( (mcc == 204) && (mnc ==  2) )
    {
        return KAL_TRUE; // Tele2 Netherland (SBP_ID = 137), NL
    }
    else if ( (mcc == 268) && (mnc ==  3) )
    {
        return KAL_TRUE; // NOS Portugal (SBP_ID = 203), PT
    }
    else /* default */
    {
        return KAL_FALSE;
    }
}
