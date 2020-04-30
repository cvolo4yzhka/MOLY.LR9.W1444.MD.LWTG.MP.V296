/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
/*
**   Includes
*/
#include "kal_general_types.h"

#include "custom_rrce_config.h"
/*
**   Macros
*/

/* For custom to determine support UPA or not */
/* KAL_TRUE: support UPA */
/* KAL_FALSE: not support UPA */
#define RRCE_IS_SUPPORT_HSUPA KAL_TRUE

const custom_plmn_list CUSTOM_ERACH_PLMN_LIST[] = 
{
/* New MCCMNC can be added in this as below. But make sure that it is either 5 digit or 6 digit
    {40402},
    {404346},
*/
    {999999}
};

const kal_uint32 CUSTOM_ERACH_PLMN_LIST_NUM = sizeof(CUSTOM_ERACH_PLMN_LIST)/sizeof(custom_plmn_list);

/*****************************************************************************
* FUNCTION
*  rrce_is_support_HSUPA
* DESCRIPTION
*
*  this function allow custom to determine support UPA or not
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/
#ifndef __HSUPA_CAPABILITY_NOT_SUPPORT__
kal_bool rrce_is_support_HSUPA (void)
{
   return (RRCE_IS_SUPPORT_HSUPA);
}
#endif




kal_bool rrce_is_support_opt1(void)
{

#ifdef __TC7_CS_OPT1__   
return KAL_TRUE;
#else
return KAL_FALSE;
#endif

}



kal_bool rrce_is_support_opt2(void)
{


#ifdef __TC7_CS_OPT2__   
return KAL_TRUE;
#else
return KAL_FALSE;
#endif



}


extern kal_bool is_erach_plmn_in_custom_config(void* plmn_id, kal_uint32* retmccmnc)
{
    kal_uint32 mccmnc;
    kal_uint32 i;
    Custom_RRC_PLMN_Id* rrc_plmn = (Custom_RRC_PLMN_Id*)plmn_id;

    mccmnc = rrc_plmn->mcc.element[0];                        // mcc1
    mccmnc = (mccmnc * 10) + (rrc_plmn->mcc.element[1]);      // mcc2
    mccmnc = (mccmnc * 10) + (rrc_plmn->mcc.element[2]);        // mcc3

    mccmnc = (mccmnc * 10) + (rrc_plmn->mnc.element[0]);      // mnc1
    mccmnc = (mccmnc * 10) + (rrc_plmn->mnc.element[1]);        // mnc2

    if (rrc_plmn->mnc.numElements == 3)
    {
       mccmnc = (mccmnc * 10) + (rrc_plmn->mnc.element[2]);  // mnc3
    }

    *retmccmnc = mccmnc;
        
    for(i = 0; i < CUSTOM_ERACH_PLMN_LIST_NUM; i++)
    {        
        if(CUSTOM_ERACH_PLMN_LIST[i].mccMnc == mccmnc)
        {    // Found in the table
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
 
}
