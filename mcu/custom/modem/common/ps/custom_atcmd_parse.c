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

/*****************************************************************************
 * Filename:
 * ---------
 * custom_atcmd_parse.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for parsing general proprietary AT command.
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
 *
 * removed!
 * removed!
 * removed!

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define RMMI_PARSER_C

#include "kal_general_types.h"
#ifdef __BTMTK__
#include "bluetooth_msgid.h"
#endif
#ifdef __GPS_SUPPORT__
#include "gps_msgid.h"
#endif
#include "tst_sap.h"
#ifdef __FM_AT_SUPPORT__
#include "mmiapi_msgid.h"
#endif
#if defined(__WIFI_SUPPORT__) && !defined(EXTERNAL_MMI) && defined(__MMI_FMI__)
#include "mmi_msgid.h"
#endif


#include <stdio.h>
#include <string.h>


#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"

#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
#include "kal_public_api.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"
#include "dcl_uart.h"

#include "uart_sw.h"
#include "tst_msgid.h"
#ifdef __BTMTK__
#include "Bluetooth_struct.h"
extern void rmmi_send_msg_to_bt (msg_type msg_name, void *param_ptr);
#endif

#ifndef __L1_STANDALONE__
extern kal_bool tst_process_pc_command_from_ATCmd(kal_int32 len, kal_uint8 *param);
#endif

#if defined(__GPS_SUPPORT__)
#include "gps_struct.h"
#endif /* __GPS_SUPPORT__ */

#ifdef __FM_AT_SUPPORT__
#include "FMATCommand.h"
#endif

#ifndef L4_NOT_PRESENT
#ifdef __MOD_SMU__
#include "ps2sim_struct.h"
#include "ps2sat_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#endif /* __MOD_SMU__ */ 
/*#include "csmss_common_enums.h"
#include "mcd_l4_common.h"
#include "l4c_common_enum.h"
#include "rmmi_common_enum.h"
#include "rmmi_common_enum.h"*/
//#include "rmmi_context.h"

#ifdef __AGPS_SUPPORT__
//#include "ipc_msgsvc_msgid.h"
//#include "ipc_msgsvc.h"
//#include "l4c_aux_struct.h"
#include "md_mmi_sap.h"
#include "agps_md_interface.h"
extern module_type l4c_current_mod_id;
#endif

//extern rmmi_context_struct *rmmi_ptr_g;
#endif /* L4_NOT_PRESENT */

#include "rmmi_struct.h"
#include "rmmi_common_enum.h"

#if defined(__WIFI_SUPPORT__) && !defined(EXTERNAL_MMI) && defined(__MMI_FMI__)
#include "dtcntsrviprot.h"
#include "dtcnt_struct.h"
#endif

#ifdef __AGPS_CONTROL_PLANE__
extern void l4c_agps_reset_positioning_lind(void);
extern kal_uint8 l4c_get_csmss_g_ss_id(void);
#endif

/* mtk01616_080104: 
  * This is used to define default <time> and <pause> value for AT+CKPD.
  * <time> * 0.1 sec is the time to stroke each key
  * <pause> * 0.1 sec  is the length between two strokes.  
  * <time> or <pause> should not larger than 255 (25.5 sec)
  * Default value is manufacturer specific,but should be so long that a normal MT can handle keystrokes correctly
  * Please refer to spec 07.07 section 8.7 for more detailed information
  */
#define CUSTOM_AT_CKPD_DEFAULT_TIME 2
#define CUSTOM_AT_CKPD_DEFAULT_PAUSE 4 

//Define AT command URC "RING" interval , the unit is 0.1 sec , default value is 4 sec = 40 x 0.1 sec
#define CUSTOM_URC_RING_INTERVAL 40

extern UART_PORT PS_UART_PORT;
extern UART_PORT PS_UART_PORT_2;

#ifdef __UMTS_RAT__
#define CUSTOM_MAX_MOD_NAME (8)

typedef struct {
kal_char ModuleName[CUSTOM_MAX_MOD_NAME];
kal_uint32 ModuleEnum;
} module_name_enum_map_struct;
#endif

#ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"

static kal_bool process_gt818_ctp_cmd( kal_uint8 action, kal_uint32 data_len, kal_uint8 *data_str )
{
    kal_uint16 ret_len = 0;
    kal_uint16 i;
    kal_uint16 inlen;
    kal_uint16 offset;
    STS_CTRL_COMMAND_T cmd;
    DCL_HANDLE handle;
    kal_uint8 *ctp_buffer = NULL;
    kal_uint8 *result = NULL;
    
    ctp_buffer = (kal_uint8 *)get_ctrl_buffer( 1024 );
    
    if ( ctp_buffer == NULL )
        EXT_ASSERT(0, (int)ctp_buffer, 0, 0);
        
    cmd.u4Command = action;
    cmd.pVoid1 = (void *)data_str;
    cmd.pVoid2 = (void *)&result;
    
    handle = DclSTS_Open( DCL_TS, 0 );
    DclSTS_Control( handle, STS_CMD_COMMAND, (DCL_CTRL_DATA_T *)&cmd );   
    DclSTS_Close(handle);     
    
    if ( action == DCL_CTP_COMMAND_GET_VERSION )
        ret_len = 6;
        
    if ( action == DCL_CTP_COMMAND_GET_CONFIG )
        ret_len = 106;
            
    if ( action == DCL_CTP_COMMAND_GET_DIFF_DATA )
        ret_len = 162;      

    if ( action == DCL_CTP_COMMAND_GET_FW_BUFFER )
    {
        offset = data_str[0]*256 + data_str[1];
        inlen = data_str[2];
        memcpy( &result[offset], &data_str[3], inlen);
        
        if ( inlen != 128 )
        {
            #define GT818_FW_STRING  "ctp_firmware_rusklmeoxkwjadfjnklruo3"
            kal_int16   drv_letter;
            FS_HANDLE fs_handle;
            UINT writen;
            kal_wchar   CTP_FIRMWARE_PATH[64];
                    
            drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
            kal_wsprintf( CTP_FIRMWARE_PATH, "%c:\\%s", drv_letter, GT818_FW_STRING );    
            fs_handle = FS_Open( CTP_FIRMWARE_PATH, FS_CREATE_ALWAYS | FS_READ_WRITE );
            FS_Write(fs_handle, (kal_uint8 *) result , offset+inlen, &writen);
            FS_Close( fs_handle );
        }            
    }
    
    kal_sprintf( (kal_char *)ctp_buffer, "+EGCMD: " );
            
    for ( i = 0 ; i < ret_len ; i++ )
        kal_sprintf( (kal_char *)&ctp_buffer[strlen((char *)(ctp_buffer))], "%02X", result[i] );            
        
    rmmi_write_unsolicitedResultCode( ctp_buffer, strlen((kal_char *)(ctp_buffer)), KAL_TRUE, 1, NULL );    
    
    free_ctrl_buffer( ctp_buffer );
    
    return KAL_TRUE;
}
#endif

kal_bool custom_send_sm_stress_inject_msg( kal_char *cmd_str, module_type dst_mod )
{
#if defined(__MTK_TARGET__) && defined(MTK_SLEEP_ENABLE)
    tst_module_string_inject_struct *tst_inject;
    tst_inject = (tst_module_string_inject_struct *)
                construct_local_para((kal_uint16)sizeof(tst_module_string_inject_struct), TD_RESET);

    strcpy((kal_char*)tst_inject->string, cmd_str);
    msg_send5(MOD_L4C, dst_mod, 0, MSG_ID_TST_INJECT_STRING, (local_para_struct*)tst_inject);
    
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}
extern void PBKDF2_HMAC_Test_Main(void);
// TMO pattern
kal_uint8 g_chl_tmo_cipher_with_pubkey[256] = {0x5d, 0x35, 0x41, 0xa1, 0x5c, 0x63, 0x46, 0xe0, 0x14, 0xf4, 0xdf, 0xb3, 0x23, 0xa0, 0xa0, 0x84, 
																											0x43, 0xf8, 0x5a, 0x0a, 0xd4, 0x03, 0x10, 0x15, 0xab, 0xba, 0xb9, 0x5a, 0xa4, 0x9a, 0xa9, 0xa3, 
																											0xc3, 0x49, 0x12, 0xf3, 0x2e, 0xce, 0xef, 0x91, 0xba, 0xf9, 0xee, 0xd0, 0xdc, 0x00, 0xf8, 0xa6, 
																											0xda, 0x01, 0xdb, 0xd6, 0xbb, 0xa9, 0x3f, 0xfd, 0x09, 0x1b, 0x05, 0xaf, 0xa8, 0x79, 0x55, 0xab, 
																											0x6c, 0x78, 0xcb, 0x51, 0xb5, 0xbf, 0x47, 0x63, 0x58, 0x37, 0xc1, 0x70, 0x5e, 0x7f, 0xc6, 0x0b, 
																											0xac, 0x6a, 0x65, 0xff, 0x63, 0x25, 0x5a, 0x41, 0xa2, 0xe9, 0xa3, 0x63, 0x97, 0xfc, 0x3a, 0xfd, 
																											0x01, 0x42, 0xad, 0x38, 0x4c, 0x95, 0xd6, 0x8b, 0x46, 0xde, 0xf4, 0x5d, 0xd0, 0xa0, 0x60, 0x4b, 
																											0xd2, 0xf1, 0x72, 0x56, 0x19, 0xa0, 0x4e, 0x15, 0xc5, 0xf0, 0x2d, 0x97, 0xc4, 0x50, 0xb6, 0xdd, 
																											0x1f, 0x2f, 0x95, 0x89, 0xf2, 0xe9, 0x8a, 0x23, 0x37, 0xac, 0x64, 0x33, 0x49, 0x23, 0x92, 0x32, 
																											0xe5, 0xe7, 0xba, 0xdb, 0x31, 0x27, 0x0d, 0xcd, 0xf1, 0x16, 0x23, 0x8e, 0xc1, 0x40, 0xd3, 0xe5, 
																											0xfb, 0xfd, 0xc3, 0xdf, 0xb0, 0x08, 0xbc, 0x4a, 0x49, 0xf3, 0xaf, 0x37, 0x15, 0xac, 0xcf, 0x53, 
																											0x08, 0x22, 0x76, 0xcd, 0x34, 0xd1, 0x09, 0x9d, 0xff, 0xfe, 0x8e, 0x3f, 0x08, 0x50, 0x93, 0xcf, 
																											0x57, 0xfb, 0x1a, 0x68, 0xc7, 0x35, 0xec, 0x7f, 0x6c, 0x59, 0x51, 0x08, 0xef, 0x14, 0x95, 0x01, 
																											0x2c, 0x61, 0xa4, 0xc3, 0xaa, 0x5d, 0x20, 0xb3, 0x01, 0x2c, 0x53, 0x7e, 0x92, 0x97, 0x02, 0x94, 
																											0x12, 0x03, 0xf6, 0x0b, 0x64, 0x2e, 0x70, 0xf8, 0x30, 0x57, 0x4c, 0xa2, 0x1c, 0xb1, 0x7d, 0x14, 
																											0x81, 0xbf, 0xa7, 0x73, 0x89, 0x8c, 0x96, 0xf5, 0x09, 0xfa, 0xc3, 0xd1, 0x3a, 0xa2, 0x12, 0x26};

kal_uint8 g_chl_tmo_cipher_with_privkey[256] = {0x88, 0x15, 0x98, 0xf3, 0xe7, 0x1f, 0xec, 0x61, 0xe1, 0x69, 0x00, 0xdd, 0x42, 0xbe, 0x0d, 0x55, 
																											0x45, 0xc8, 0x4e, 0x3d, 0x5d, 0x0b, 0x9f, 0xde, 0xc1, 0x69, 0xa1, 0xfd, 0x6d, 0x07, 0x93, 0x35, 
																											0xfc, 0x60, 0x4a, 0x66, 0x8d, 0x44, 0xb0, 0x88, 0x4a, 0x5f, 0x06, 0x94, 0xb9, 0x62, 0x51, 0x49, 
																											0x1a, 0x93, 0xca, 0x9b, 0x21, 0xd7, 0x11, 0xdf, 0x12, 0xa6, 0x55, 0xa8, 0x70, 0x96, 0xed, 0xfb, 
																											0x04, 0x05, 0x3a, 0xd5, 0x9b, 0xea, 0xaa, 0xb4, 0x67, 0xd1, 0xfb, 0x5b, 0x07, 0x3a, 0xbc, 0x2a, 
																											0x06, 0x28, 0xfa, 0x91, 0x71, 0x7a, 0x51, 0x9a, 0x1a, 0x99, 0x87, 0x6b, 0x8c, 0xe1, 0xd0, 0xd3, 
																											0x16, 0xa1, 0x6a, 0x3e, 0x38, 0x26, 0xaa, 0x3a, 0x7f, 0x83, 0x7c, 0x9b, 0xe6, 0x45, 0x83, 0x4f, 
																											0xc4, 0x56, 0x4b, 0x56, 0xbf, 0x64, 0xd1, 0x87, 0x77, 0x5a, 0xcf, 0x5a, 0x0c, 0x84, 0xc2, 0xb2, 
																											0x21, 0xf7, 0x29, 0x7a, 0x3e, 0xc9, 0x44, 0x11, 0x33, 0x00, 0xc7, 0x43, 0x9a, 0xbf, 0x1e, 0xa7, 
																											0xef, 0xcb, 0x1f, 0x35, 0x8a, 0x87, 0x60, 0xd3, 0x42, 0x92, 0x33, 0x51, 0xfc, 0x75, 0x5d, 0x14, 
																											0x03, 0x1c, 0x5e, 0xae, 0x4a, 0x71, 0x00, 0x33, 0x47, 0x7d, 0x1e, 0x97, 0x4e, 0x1f, 0xad, 0xdf, 
																											0x0b, 0x1d, 0x7b, 0x74, 0x08, 0xf9, 0x90, 0x15, 0x47, 0x19, 0xc4, 0x0e, 0x92, 0xd0, 0x2e, 0x9b, 
																											0xaa, 0xcf, 0x03, 0x84, 0xfc, 0xc4, 0x2c, 0xbd, 0xb8, 0x04, 0x9f, 0xa9, 0x12, 0x94, 0xf8, 0x26, 
																											0xc5, 0x5c, 0xf1, 0x17, 0x20, 0x22, 0x83, 0x2d, 0xcc, 0x21, 0x6a, 0x9a, 0x6d, 0x03, 0x11, 0x65, 
																											0xb4, 0x22, 0xac, 0xa7, 0xc2, 0x17, 0x0b, 0xfd, 0x23, 0x19, 0x8f, 0x23, 0x39, 0x73, 0x38, 0x6b, 
																											0xff, 0x4e, 0xb6, 0x75, 0x5f, 0xc2, 0xd2, 0x2a, 0x25, 0x49, 0xae, 0x28, 0x97, 0x56, 0xdd, 0xb5};

kal_uint8 g_chl_tmo_ptext[12] = {0x14, 0x00, 0x01, 0x2c, 0x7d, 0x7e, 0x10, 0xc0, 0x00, 0x00, 0x00, 0x00};

t_cust_chl_asym_key g_chl_tmo_asym_key = 
{
	  // TM TEST PRIVATE KEY1
		4,
    	256,
	  	256,
		{
			0x00, 0x01, 0x00, 0x01
		},
		{
			0x61, 0x5b, 0x91, 0x7b, 0x85, 0x5f, 0xab, 0x00, 0xb1, 0x48, 0xb2, 0x7a, 0x30, 0xff, 0x81, 0x18, 
			0x4c, 0xa9, 0xe9, 0x19, 0x8b, 0x45, 0x04, 0x46, 0xf4, 0xd1, 0x38, 0xf0, 0x23, 0x80, 0xbe, 0xec, 
			0x0e, 0xef, 0x34, 0xb8, 0x0f, 0xe9, 0x8c, 0xf3, 0x5d, 0xfb, 0x2b, 0xf1, 0x01, 0x17, 0x91, 0xa5, 
			0xb1, 0x12, 0x57, 0x5c, 0x8e, 0x68, 0x63, 0x16, 0x5a, 0x88, 0x31, 0xc9, 0xeb, 0xcc, 0xc1, 0xd9, 
			0x93, 0x3e, 0x17, 0xfc, 0xa7, 0x67, 0xc6, 0x4a, 0x2c, 0x29, 0x36, 0x2f, 0x54, 0x25, 0x5b, 0xfc, 
			0xe3, 0x4a, 0x6e, 0x5c, 0x26, 0x43, 0xec, 0xe5, 0x01, 0x66, 0x36, 0xfd, 0x59, 0x17, 0xea, 0xc8, 
			0x8b, 0xfd, 0xf3, 0xd6, 0xb9, 0xc7, 0x7c, 0xfc, 0x1c, 0x63, 0xf8, 0xfe, 0x06, 0x0e, 0x21, 0xdc, 
			0xa2, 0x8d, 0x0a, 0x59, 0x9b, 0xad, 0xf5, 0xde, 0xdb, 0xcb, 0x3d, 0xda, 0xca, 0x63, 0xeb, 0x95, 
			0xae, 0x0c, 0x0b, 0xc7, 0x6f, 0x6f, 0x3f, 0x83, 0x73, 0x59, 0x30, 0xb0, 0x52, 0xee, 0xa8, 0x45, 
			0xea, 0x67, 0xd6, 0x95, 0x14, 0xb3, 0xe9, 0x61, 0xf5, 0x14, 0x2f, 0x46, 0xb1, 0xe7, 0xb3, 0x51, 
			0xed, 0xd7, 0x07, 0x0e, 0x68, 0xab, 0x04, 0x4c, 0xf8, 0xe8, 0x91, 0x7c, 0x14, 0xfc, 0x2d, 0x64, 
			0x4c, 0x1b, 0xd4, 0x4d, 0xeb, 0x64, 0x4d, 0xe2, 0x3e, 0xe0, 0x76, 0x01, 0x6d, 0x18, 0xaa, 0xc6, 
			0x3b, 0x65, 0x7d, 0x1f, 0xa3, 0xc2, 0x65, 0xc6, 0x89, 0x93, 0xa4, 0x5f, 0x94, 0x9b, 0x44, 0xc7, 
			0x63, 0xa8, 0xaf, 0xf4, 0xb4, 0x5a, 0x54, 0xed, 0x57, 0xcd, 0xdf, 0x8c, 0x58, 0xc4, 0xcc, 0x57, 
			0xc6, 0x93, 0x6e, 0x3c, 0x1d, 0x4d, 0x2d, 0x5c, 0x4b, 0xaa, 0x4b, 0xc4, 0xe3, 0xfd, 0xd9, 0x5b, 
			0x54, 0x8b, 0xf1, 0x4f, 0xc7, 0x47, 0x1c, 0x77, 0x5a, 0xf2, 0x5a, 0x2a, 0x57, 0x93, 0x43, 0x79
		},
		
		{
			0xbb, 0xad, 0xe2, 0x20, 0xfc, 0xf9, 0x6d, 0xd8, 0x0c, 0x2d, 0xd7, 0x5f, 0xd8, 0xac, 0xf7, 0x6f, 
			0xd3, 0xcc, 0xcf, 0x0a, 0xf9, 0x5e, 0xc7, 0x14, 0x77, 0xab, 0x58, 0x54, 0x9c, 0x7b, 0x4c, 0xf8, 
			0x91, 0x15, 0x7e, 0xe9, 0xf6, 0xd7, 0x2b, 0xbf, 0xc6, 0x84, 0xfb, 0x06, 0x21, 0x36, 0x42, 0x80, 
			0x04, 0x46, 0xff, 0x2f, 0x9c, 0x66, 0x35, 0x9e, 0xa5, 0xf7, 0x8d, 0xbd, 0x4f, 0x80, 0x07, 0xff, 
			0xdb, 0x8d, 0x4b, 0xcb, 0xbc, 0x98, 0x0f, 0x60, 0x42, 0xa6, 0xcf, 0x10, 0xec, 0x2d, 0xb1, 0x89, 
			0xd9, 0x01, 0x0f, 0x21, 0xde, 0x11, 0xee, 0x29, 0x25, 0x84, 0x39, 0x39, 0xac, 0x69, 0x1e, 0x72, 
			0x95, 0x5e, 0xcf, 0x56, 0x95, 0xe1, 0x57, 0xe1, 0x68, 0x7a, 0xfd, 0xda, 0x99, 0x35, 0x46, 0x50, 
			0x68, 0xc5, 0x62, 0x98, 0x9e, 0xab, 0xa6, 0xf8, 0x75, 0xb9, 0xd8, 0xdf, 0xbc, 0x47, 0xa4, 0x17, 
			0x71, 0x2a, 0x0d, 0xb2, 0xcf, 0x9a, 0x26, 0x9e, 0xd3, 0x04, 0x0b, 0x64, 0x81, 0xa5, 0x81, 0x76, 
			0x41, 0x08, 0x5a, 0x28, 0x96, 0xcd, 0x6f, 0xf5, 0x1c, 0xe1, 0x04, 0x97, 0x23, 0xb8, 0xd9, 0x21, 
			0xbc, 0x69, 0x16, 0xc6, 0x8e, 0x58, 0xd7, 0x9d, 0xba, 0x32, 0x90, 0x09, 0x38, 0x0a, 0x02, 0x45, 
			0x1c, 0xb7, 0xa4, 0xc1, 0x30, 0xf3, 0x54, 0xa2, 0x22, 0xe0, 0x4c, 0xc9, 0xfa, 0xd0, 0xfe, 0x2e, 
			0x3f, 0xde, 0x57, 0x00, 0x6d, 0xf2, 0xc3, 0x96, 0xfe, 0xef, 0x01, 0x29, 0x26, 0xe8, 0x66, 0x56, 
			0x9e, 0x79, 0xe3, 0x14, 0xa8, 0xf9, 0x62, 0x03, 0xd1, 0xcf, 0x9f, 0x35, 0x94, 0x3d, 0x76, 0xd7, 
			0x80, 0x24, 0x2c, 0x3a, 0x1f, 0xb3, 0xc1, 0xd0, 0x4b, 0x62, 0x1e, 0xfc, 0x2b, 0x5a, 0x23, 0x7e, 
			0xbf, 0xe2, 0x83, 0x97, 0x40, 0x6b, 0xcf, 0x21, 0xe3, 0xb6, 0x75, 0xd7, 0x34, 0xbf, 0x9d, 0x8f	
		}

};
kal_uint8 g_chl_tmo_symkey_raw[32] = {0xd9, 0x90, 0xea, 0xff, 0xeb, 0xa4, 0x24, 0xa4, 0x19, 0x60, 0x4c, 0xa6, 0x43, 0xb1, 0x62, 0x81, 
																			0xd3, 0x11, 0xb0, 0x72, 0xee, 0xb0, 0xff, 0x8e, 0x63, 0x16, 0x90, 0xd7, 0x4b, 0x63, 0x45, 0xc0};


#include "cust_chl_interface.h"
void chl_test_case_tmo_pss_signature()
{
    
	kal_uint32 ret = CUST_CHL_ERROR_NONE;
	kal_uint8 corrupted_privkey[256];
	
	// 8.5.1 verify good signature
	ret = CustCHL_Verify_PSS_Signature(CUST_CHL_ALG_RSA_PSS_SHA256, g_chl_tmo_symkey_raw, sizeof(g_chl_tmo_symkey_raw), g_chl_tmo_cipher_with_privkey, &g_chl_tmo_asym_key);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "[CHL] pss test ret = %x", ret);
	ASSERT( ret == CUST_CHL_ERROR_NONE);

	// 8.5.2 verify bad signature
	memcpy(corrupted_privkey, g_chl_tmo_cipher_with_privkey, sizeof(corrupted_privkey));
	corrupted_privkey[255] = 0; // modify 1 byte
	ret = CustCHL_Verify_PSS_Signature(CUST_CHL_ALG_RSA_PSS_SHA256, g_chl_tmo_symkey_raw, sizeof(g_chl_tmo_symkey_raw), corrupted_privkey, &g_chl_tmo_asym_key);
	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "[CHL] pss test ret = %x", ret);
	ASSERT( ret != CUST_CHL_ERROR_NONE);

}
/*****************************************************************************
* FUNCTION
*  	rmmi_general_command_parsing()
* DESCRIPTION
*   	This function should parse general proprietary AT command request.
*     Each owner should maintain and modify the code.
* PARAMETERS
*   	kal_uint32 op 
*	kal_uint32 data_len 
*	kal_uint8 *data_str
* RETURNS
*	KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool rmmi_general_command_parsing(kal_uint32 op, 
                                                kal_uint32 data_len, 
                                                kal_uint8 *data_str)
{
    kal_bool ret_val = KAL_FALSE;
    
#ifndef L4_NOT_PRESENT

    switch(op)
    {
        case 1:
        {
        	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "[CHL] PBKDF2_Case Start");
        	PBKDF2_HMAC_Test_Main();
        	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "[CHL] PBKDF2_Case Finish");
        	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "[CHL] PSS Start");
        	chl_test_case_tmo_pss_signature();
        	dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_NVRAM, "[CHL] PSS Finish");
        	
        	break;
        }	
        case 2: /* add by stanley 2006-07-03*/
        {
#if  defined(__BTMTK__)
            bt_test_cmd_req_struct  *param_ptr;
            param_ptr = (bt_test_cmd_req_struct *)construct_local_para(
                                                            (kal_uint16)sizeof(bt_test_cmd_req_struct),
                                                            TD_CTRL);   

            kal_mem_cpy(param_ptr->test_cmd_content, data_str, data_len);
            rmmi_send_msg_to_bt(MSG_ID_BT_TEST_CMD_REQ, param_ptr);  
            ret_val = KAL_TRUE;
#endif /* __BTMTK__ */
      break;
        }
        
    case 6:
    {
#ifdef __UMTS_RAT__
        kal_char *pp, *strModuleName, *strTstInject, *tt;
        kal_uint32 module_enum = 0, input_str_data_len = 0;

        input_str_data_len = strlen((kal_char*)data_str);


        if( input_str_data_len > 0 && input_str_data_len < 255)
        {

            strModuleName = (kal_char*) kal_strtok_r((kal_char*)data_str, "_", &pp);

            tt = (kal_char*) kal_strtok_r(NULL, "", &pp);
            if(NULL != tt)
            {
                strTstInject = tt;
            }
            else
            {
                strTstInject = "";
            }

            /* Length of module name should be less than 8 bytes and Length of TST inject string shall be less than 128 bytes */
            if((CUSTOM_MAX_MOD_NAME > strlen(strModuleName)) && (128 > strlen(strTstInject)))
            {
                kal_uint8 idx;
                kal_uint32 length_map;
                static const module_name_enum_map_struct mod_map[] = 
                    {
                            {"MEME", MOD_MEME},//0                    
                            {"CSE", MOD_CSE},
                            {"CSCE", MOD_CSCE},
                            {"SIBE", MOD_SIBE}, 
                            {"USIME", MOD_USIME},
                            {"RRCE", MOD_RRCE},//5
                            {"SLCE", MOD_SLCE},
                            {"ADR", MOD_ADR},
                            {"URR", MOD_URR}, 
                            {"URLC", MOD_URLC},
                            {"UMAC", MOD_UMAC},//10
                            {"UL2", MOD_UL2},                    
                            {"MM", MOD_MM},
                            {"CC", MOD_CC}, 
                            {"CISS", MOD_CISS},
                            {"SMS", MOD_SMS},//15
                            {"SIM", MOD_SIM},
                            {"L4C", MOD_L4C},
                            {"TCM", MOD_TCM}, 
                            {"SMSAL", MOD_SMSAL},
                            {"UEM", MOD_UEM},//20
                            {"RAC", MOD_RAC},
                            {"SMU", MOD_SMU},
                            {"USAT", MOD_USAT}, 
                            {"CSM", MOD_CSM},
                            {"ENG", MOD_ENG},//25
                            {"PHB", MOD_PHB},
                            {"RRM", MOD_RRM},
                            {"RLC", MOD_RLC}, 
                            {"MAC", MOD_MAC},
                            {"LAPDM", MOD_LAPDM}, //30
                            {"MPAL", MOD_MPAL},
                            {"SNDCP", MOD_SNDCP},
                            {"SM", MOD_SM}, 
                            {"LLC", MOD_LLC},
                            {"GMSS", MOD_GMSS}, //35
                            {"NWSEL", MOD_NWSEL},
                            {"ERRC", MOD_ERRC}
                        };
                length_map = sizeof(mod_map)/sizeof(module_name_enum_map_struct);
                for(idx = 0; idx < length_map; idx++)
                {
                    if(strcmp(strModuleName, mod_map[idx].ModuleName) == 0)
                    {
                        module_enum = mod_map[idx].ModuleEnum;
                        break;
                    }
                }

                if(idx != length_map)
                {
                    /* The target module is found, and send the TST to the module */
                    tst_module_string_inject_struct *tst_inject;
                    tst_inject = (tst_module_string_inject_struct *)
                                            construct_local_para((kal_uint16)sizeof(tst_module_string_inject_struct), TD_RESET);
                    strcpy((kal_char*)tst_inject->string, strTstInject);
                    tst_inject->index = data_len;

                    {
                        msg_send5(MOD_L4C, (module_type)module_enum, 0, MSG_ID_TST_INJECT_STRING, (local_para_struct*)tst_inject);
                    }
                }
            }

        ret_val = KAL_TRUE;
        }
#endif /* __UMTS_RAT__ */
    }
    break;

    #if defined(__AGPS_CONTROL_PLANE__)            
        case 14:
        {
            l4c_agps_reset_positioning_lind();
            ret_val = KAL_TRUE;
            break;
        }
    #endif

/************************sample code begin************************/			
//		case op: /*owner_date: purpose*/
//		{
//			/*call proprietary parsing function here and AT will give result  */
//			/*code OK/ERROR according to return value of parsing function*/	
//
//			break;
//		}
/************************sample code end*************************/
    #ifdef __CTP_GOODIX_GT818_TRUE_MULTIPLE__
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        {
            ret_val = process_gt818_ctp_cmd( (kal_uint8)(op - 15), data_len, data_str );
            break;
        }   
    #endif

#if defined(__AGPS_SUPPORT__)
        /* below codes are for auto-test */
        case 25:
        case 26:
        {
            /*agps_auto_test_ind_struct *param_ptr = construct_local_para(
            (kal_uint16)sizeof(agps_auto_test_ind_struct), TD_RESET);

            param_ptr->mode = (op == 25)? 1 : 0;*/

            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_AUTO_TEST_IND, param_ptr);
            agps_md_auto_test_ind data;
            data.mode = (op == 25)? 1 : 0;
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_TEST_IND, (kal_uint8*)&data, sizeof(data));
            ret_val = KAL_TRUE;
            break;
        }
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        {
            /*agps_cp_up_status_ind_struct *param_ptr = construct_local_para(
            (kal_uint16)sizeof(agps_cp_up_status_ind_struct), TD_RESET);

            param_ptr->mode = (op-27);*/

            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_CP_UP_STATUS_IND, param_ptr);
            agps_md_auto_cp_up_status_ind data;
            data.mode = (op-27);
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_CP_UP_STATUS_IND, (kal_uint8*)&data, sizeof(data));
            ret_val = KAL_TRUE;
            break;
        }
        case 33:
        case 34:
        {
            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_MOLR_START_IND+(op-33), NULL);
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_MOLR_START_IND+(op-33), NULL, 0);
            ret_val = KAL_TRUE;
            break;
        }
        case 35:
        case 36:
        {
            /*agps_mtlr_response_ind_struct *param_ptr = construct_local_para(
            (kal_uint16)sizeof(agps_mtlr_response_ind_struct), TD_RESET);

            param_ptr->response = (op-35);*/
            /* Send the message to the module in AP */
            //ret_val = custom_send_agps_autotest_ipc(IPC_MSG_ID_AGPS_MTLR_RESPONSE_IND, param_ptr);
            agps_md_auto_mtlr_response_ind data;
            data.response = (op-35);
            data.session_id = l4c_get_csmss_g_ss_id();
            rmmi_lbs_send_data(AGPS_MD_TYPE_AUTO_MTLR_RESPONSE_IND, (kal_uint8*)&data, sizeof(data));
            ret_val = KAL_TRUE;
            break;
        }
#endif
        /* Sleep Mode Stress Test */
        case 37:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GStressEnable", MOD_L1);
            break;
        }
#ifdef __UMTS_FDD_MODE__
        case 38:
        {
            ret_val = custom_send_sm_stress_inject_msg( "3GStressEnable", MOD_UL1);
            break;
        }
#endif
        case 39:
        {
            ret_val = custom_send_sm_stress_inject_msg( "RTOSStressEnable", MOD_L1);
            break;
        }
        case 40:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GStressDisable", MOD_L1);
            break;
        }
#ifdef __UMTS_FDD_MODE__
        case 41:
        {
            ret_val = custom_send_sm_stress_inject_msg( "3GStressDisable", MOD_UL1);
            break;
        }
#endif
        case 42:
        {
            ret_val = custom_send_sm_stress_inject_msg( "RTOSStressDisable", MOD_L1);
            break;
        }
        /*Re  Calibration Stress */
        case 43:
        {
            ret_val = custom_send_sm_stress_inject_msg( "ReKEnable", MOD_L1);
            break;
        }
        case 44:
        {
            ret_val = custom_send_sm_stress_inject_msg( "ReKDisable", MOD_L1);
            break;
        }
        case 45:
        {
            ret_val = custom_send_sm_stress_inject_msg( "IgnoreXtaModeL1SM", MOD_L1);
            break;
        }
#ifdef __LTE_RAT__
        case 46:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GStressEnable", MOD_EL1);
            break;
        }
        case 47:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GStressDisable", MOD_EL1);
            break;
        }
#endif
        case 48:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GSleepEnable", MOD_L1);
            break;
        }
        case 49:
        {
            ret_val = custom_send_sm_stress_inject_msg( "2GSleepDisable", MOD_L1);
            break;
        }
#ifdef __UMTS_FDD_MODE__
        case 50:
        {
            ret_val = custom_send_sm_stress_inject_msg( "3GSleepEnable", MOD_UL1);
            break;
        }
        case 51:
        {
            ret_val = custom_send_sm_stress_inject_msg( "3GSleepDisable", MOD_UL1);
            break;
        }
#endif
#ifdef __LTE_RAT__
        case 52:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GSleepEnable", MOD_EL1);
            break;
        }
        case 53:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GSleepDisable", MOD_EL1);
            break;
        }
#endif
        case 54:
        {
            ret_val = custom_send_sm_stress_inject_msg( "OSTDSleepEnable", MOD_L1);
            break;
        }
        case 55:
        {
            ret_val = custom_send_sm_stress_inject_msg( "OSTDSleepDisable", MOD_L1);
            break;
        }
#ifdef __LTE_RAT__
        case 56:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GDVFSEnable", MOD_EL1);
            break;
        }
        case 57:
        {
            ret_val = custom_send_sm_stress_inject_msg( "4GDVFSDisable", MOD_EL1);
            break;
        }
#endif
#ifdef __DHL_MODULE__
        case 58:
        {
       	    //@mcu/interface/service/dhl/dhl_trace.h
            extern kal_bool dhl_enable_customized_SD_wakeup_time(kal_uint8 c_sec);
            extern kal_bool dhl_disable_customized_SD_wakeup_time(void);
            kal_uint8 val = *(kal_uint8 *) data_str;
            if (val == 0) {
                ret_val = dhl_disable_customized_SD_wakeup_time();
            } else {
                ret_val = dhl_enable_customized_SD_wakeup_time(val);
            }
            break;
        }
#endif
		default:
			break;	
	}
#endif // L4_NOT_PRESENT

	return ret_val;
}

kal_uint16 rmmi_get_ckpd_default_time(void)
{
	return CUSTOM_AT_CKPD_DEFAULT_TIME;
}

kal_uint16 rmmi_get_ckpd_default_pause(void)
{
	return CUSTOM_AT_CKPD_DEFAULT_PAUSE;
}

kal_uint16 rmmi_get_ring_interval(void)
{
	return CUSTOM_URC_RING_INTERVAL;
}

#if defined(__MOD_TCM__) //&& !defined(__MMI_FMI__)
extern kal_uint8 custom_l4c_psbearer_indicate(void);
#endif

/*****************************************************************************
* FUNCTION
*  	rmmi_custom_init_context()
* DESCRIPTION
* This function is to customize AT command default setting
*
* PARAMETERS
*	NONE
*
* RETURNS
*	NONE
*
*****************************************************************************/
void rmmi_custom_init_context(rmmi_custom_context_struct *rmmi_ptr_g)
{
#ifndef L4_NOT_PRESENT
    /* ATE default value */
    rmmi_ptr_g->rsp_mode.echo_flag = 0xff; // default echo on

    /* ATV default value */
    rmmi_ptr_g->rsp_mode.format = RMMI_VERBOSE_FULL_HEAD_TAIL;

	/* ATW default value */
    rmmi_ptr_g->rsp_mode.ext_result_code = 2;

	/* ATQ default value */
    rmmi_ptr_g->rsp_mode.suppress_flag = RMMI_SUPPRESS_OFF;

    /* AT+CMEE=<n> default value */
    rmmi_ptr_g->error_report_mode = RMMI_SIMPLE_ERROR;

    /* AT+CSCS=<chset> default value */
    rmmi_ptr_g->char_set = RMMI_CHSET_IRA;    

	/* AT+COPS=<mode>,<format> default value */
    rmmi_ptr_g->plmn_format = RMMI_PLMN_LONG_ALPHA;       //default for long alpha
    rmmi_ptr_g->cops_mode = 0; // default "automatic" mode

#ifdef __PLMN_LIST_WITH_LAC__
    rmmi_ptr_g->list_plmn_with_lac = KAL_FALSE; //default not print LAC
#endif

	/* AT+CPOL=<index>,<format> , set <format> default value here */
    rmmi_ptr_g->CPOL_plmn_format = RMMI_PLMN_NUMERIC;	

    /* AT+CMEC=<keyp>,<disp>,<ind> default value */
    rmmi_ptr_g->cmec_keyp = 2; 
    rmmi_ptr_g->cmec_disp = 0;
    rmmi_ptr_g->cmec_ind = 0;

    /* AT+CLAE=<mode> default value */    
    rmmi_ptr_g->clae_mode = KAL_FALSE;    

	/* AT+CSDH=<show> default value */
    rmmi_ptr_g->csdh_show = KAL_FALSE;

	/* AT+CVHU=<mode> default value, only (0-1) is supported */
#if defined(__MULTIPLE_PPP_DIALUP_SUPPORT__) && defined(__MMI_FMI__)
	rmmi_ptr_g->cvhu_mode = 1; //MAUI_02862643, mtk02285, ignore ATH in default -> To prevent disc CS call for Ericsson IOT  
#else
	rmmi_ptr_g->cvhu_mode = 0;
#endif

    /* AT+EIND=<flag> default value*/
#if defined (__CMUX_SUPPORT__) || defined (__MODEM_CARD__) /* EDGE card default enable eind */
    rmmi_ptr_g->report_mode.eind = 0x000000ff;
#else
    rmmi_ptr_g->report_mode.eind = 0; 
#endif

    /* AT+EINFO=<flag> default value*/
    rmmi_ptr_g->report_mode.einfo = 0;

    /* AT+ECPI=<mode> default value*/
#if defined(__UE_SIMULATOR__) && defined(__IMS_SUPPORT__)
    rmmi_ptr_g->report_mode.ecpi = 0xFFFFFFFF;
#else
    rmmi_ptr_g->report_mode.ecpi = 0;
#endif

    /* AT+ECSQ=<flag> default value*/
    rmmi_ptr_g->report_mode.ecsq = 0;

    /* AT+CMER=<mode>,<keyp>,0,<ind>,<bfr> default value */	
    rmmi_ptr_g->report_mode.cmer_mode = 0;  
    rmmi_ptr_g->report_mode.cmer_keyp = 0;
    rmmi_ptr_g->report_mode.cmer_ind = 0;   
    rmmi_ptr_g->report_mode.cmer_bfr = 0;	

    /* AT+CLIP=<n> default value*/	
    rmmi_ptr_g->report_mode.clip = 0;

    /* AT+COLP=<n> default value*/	
    rmmi_ptr_g->report_mode.colp = RMMI_DISABLE_REPORT;

    /* AT+CLIR=<n> default value*/	
    rmmi_ptr_g->report_mode.clir = RMMI_DISABLE_REPORT;

    /* AT+CDIP=<n> default value*/	
    rmmi_ptr_g->report_mode.cdip = RMMI_DISABLE_REPORT;

    /* AT+CNAP=<n> default value*/	
    rmmi_ptr_g->report_mode.cnap = RMMI_DISABLE_REPORT;

#if defined(__UE_SIMULATOR__) && defined(__IMS_SUPPORT__)
    /* AT+CREG=<n> default value*/  
    rmmi_ptr_g->report_mode.cs_reg = RMMI_ENABLE_LOC_REPORT;

    /* AT+CGREG=<n> default value*/ 
    rmmi_ptr_g->report_mode.ps_reg = RMMI_ENABLE_LOC_REPORT;
#else	
    /* AT+CREG=<n> default value*/	
    rmmi_ptr_g->report_mode.cs_reg = RMMI_DISABLE_NW_REG_REPORT;

    /* AT+CGREG=<n> default value*/	
    rmmi_ptr_g->report_mode.ps_reg = RMMI_DISABLE_NW_REG_REPORT;
#endif
    /* AT+CAOC=<mode> default value*/	
    rmmi_ptr_g->report_mode.ccm = RMMI_DISABLE_REPORT;

    /* AT+CCWE=<mode> default value*/	
    rmmi_ptr_g->report_mode.acm_warning = RMMI_DISABLE_REPORT;

    /* AT+CCWA=<n> default value*/	
    rmmi_ptr_g->report_mode.call_wait = RMMI_DISABLE_REPORT;

    /* AT+CGEREP=<mode> default value*/	
    rmmi_ptr_g->report_mode.cgerep = RMMI_DISABLE_REPORT;

    /* AT+CR=<mode> default value*/	
    rmmi_ptr_g->report_mode.cr = RMMI_DISABLE_REPORT;

    /* AT+CRC=<mode> default value*/	
    rmmi_ptr_g->report_mode.crc = RMMI_DISABLE_REPORT;

    /* AT+CTZR=<onoff> default value*/	
    rmmi_ptr_g->report_mode.timezone = RMMI_DISABLE_REPORT;

    /* AT+CUSD=<n> default value*/	
    rmmi_ptr_g->report_mode.ussd = RMMI_DISABLE_REPORT;

    /* AT+CSSN=<n>,<m> default value*/	
    rmmi_ptr_g->report_mode.ss_mo = RMMI_DISABLE_REPORT;	
    rmmi_ptr_g->report_mode.ss_mt = RMMI_DISABLE_REPORT;	

    /* AT+CEN=<reporting> */
    rmmi_ptr_g->report_mode.cen = RMMI_ENABLE_REPORT; // +CEN

#if !defined(__MMI_FMI__)
    /* AT+ESIMS=<n> default value*/
    rmmi_ptr_g->report_mode.esims = 0;
#endif

    /* AT+EUSIM=<n> default value*/
    rmmi_ptr_g->report_mode.eusim = RMMI_ENABLE_REPORT;

    /* AT+ETESTSIM=<n> default value*/
    rmmi_ptr_g->report_mode.etestsim = RMMI_ENABLE_REPORT;

#if defined(__MOD_TCM__) //&& !defined(__MMI_FMI__)
    rmmi_ptr_g->report_mode.psbearer_indicate = custom_l4c_psbearer_indicate();
#endif

    rmmi_ptr_g->report_mode.pacsp = RMMI_DISABLE_REPORT;

    /* AT+ECGREG=<n> default value*/
	rmmi_ptr_g->report_mode.ecgreg = RMMI_DISABLE_REPORT;

    /* AT+ECEREG=<n> default value*/
	rmmi_ptr_g->report_mode.ecereg = RMMI_DISABLE_REPORT;

    /* AT+ECREG=<n> default value*/
	rmmi_ptr_g->report_mode.ecreg = RMMI_DISABLE_REPORT;

    /* AT+EIMSESS=<n> default value*/
	rmmi_ptr_g->report_mode.eimsess = RMMI_DISABLE_REPORT;

#ifdef __OP01__
    /* AT^DSCI=<n> default value */
    rmmi_ptr_g->op01_report_mode.dsci = 0;
    rmmi_ptr_g->op01_report_mode.cardmode = 0;
    rmmi_ptr_g->op01_report_mode.rfsw = 0;
#endif

#ifdef __CSG_SUPPORT__
    rmmi_ptr_g->report_mode.ecsg = RMMI_DISABLE_REPORT;
#endif

#ifdef __IMS_SUPPORT__
    rmmi_ptr_g->report_mode.cireg = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.cirep = RMMI_ENABLE_REPORT;
    rmmi_ptr_g->report_mode.cnem = RMMI_ENABLE_REPORT;
    rmmi_ptr_g->report_mode.ecmpcid = RMMI_ENABLE_REPORT;
#endif

    rmmi_ptr_g->report_mode.ecell = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.ecsra = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.eemcinfo = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.ecode33_mode = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.armee = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.cusats = RMMI_DISABLE_REPORT;

    rmmi_ptr_g->report_mode.ecamp = RMMI_DISABLE_REPORT;
    
    rmmi_ptr_g->report_mode.evocd = RMMI_DISABLE_REPORT;

	rmmi_ptr_g->report_mode.eccause = RMMI_DISABLE_REPORT;
#ifdef __BCSFB__
	rmmi_ptr_g->report_mode.erlm_mode = RMMI_DISABLE_REPORT;
#endif /* __BCSFB__ */   

    rmmi_ptr_g->report_mode.esimecc = RMMI_ENABLE_REPORT;
	rmmi_ptr_g->report_mode.ereginfo = RMMI_DISABLE_REPORT;
    rmmi_ptr_g->report_mode.esimapp = RMMI_DISABLE_REPORT;
#endif /* L4_NOT_PRESENT */    
}

/*****************************************************************************
* FUNCTION
*  	rmmi_custom_ps_uart_port()
* DESCRIPTION
*   	This function is to provide custom_ps_uart_port setting for ATCI
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
UART_PORT rmmi_custom_ps_uart_port(void)
{
    // uart_port_null => won't open extra port

//temp_sol for 6582+6290
#if defined(__SMART_PHONE_MODEM__) && !defined(__FLAVOR_MULTI_MODE_ROUTER__) && !defined(__FLAVOR_SINGLE_MODE_ROUTER__)
    return (kal_uint16)uart_port_usb;
#else
    return (kal_uint16)uart_port_null;
#endif
}

/*****************************************************************************
* FUNCTION
*  	rmmi_custom_urc_channel()
* DESCRIPTION
*   	This function is to decide the URC will be sent to specific port or not
*
* PARAMETERS
*	NONE
*
* RETURNS
*       KAL_TRUE:   send URC to the port
*       KAL_FALSE: DO NOT send URC to the port
*****************************************************************************/
kal_bool rmmi_custom_urc_channel(kal_uint8 port)
{
    // In default, only sent URC to PS_UART_PORT

    if (port == PS_UART_PORT)
    {
        return KAL_TRUE;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return KAL_FALSE;
}

/*****************************************************************************
* FUNCTION
*  	rmmi_get_vgr_default_setting()
* DESCRIPTION
*   	This function is to define default setting for ATE
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
void rmmi_get_vgr_default_setting(kal_bool *customer_provided, kal_uint8 *vgr_gain)
{
    *customer_provided = KAL_FALSE;
    *vgr_gain = 150;
}

/*****************************************************************************
* FUNCTION
*  	rmmi_get_vgt_default_setting()
* DESCRIPTION
*   	This function is to define default setting for ATE
*
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
void rmmi_get_vgt_default_setting(kal_bool *customer_provided, kal_uint8 *vgt_gain)
{
    *customer_provided = KAL_FALSE;
    *vgt_gain = 150;
}



/*****************************************************************************
* FUNCTION
*  	rmmi_remove_listing_at_command()
* DESCRIPTION
*   	
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
kal_bool rmmi_remove_listing_at_command(kal_char const *rsp_str)
{
/* If you don't want to list some at command, you can refer the following example.
    If you don't list ata and at+casp, please refer the following code.*/
/*	
       if (strcmp(rsp_str, "a") == 0 || strcmp(rsp_str, "casp") == 0)
	{
		return KAL_FALSE;
	}
*/
	return KAL_TRUE;
}
/*****************************************************************************
* FUNCTION
*  	rmmi_add_listing_at_command()
* DESCRIPTION
*   	
* PARAMETERS
*	NONE
*
* RETURNS
*
*****************************************************************************/
kal_uint16 rmmi_add_listing_at_command(kal_char **rsp_str)
{
/* If you want to list some custom at command, you can refer the following example.
    If you list at+aaaa and at+bbbb, please refer the following code.*/
/*    
    rsp_str[0]="at+aaaa\0";
    rsp_str[1]="at+bbbb\0";

    return 2; // total 2 at command (at+aaaa and at+bbbb)
*/
    return 0;
}

