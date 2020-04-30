/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * eCall_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   eCall Modem Driver  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include <stdio.h>
#include "ecall_defines.h"
#include "ecall_control.h"
#include "modemx.h"

#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio.h"
#include "pcm4way.h"
#include "am.h"
#include "media.h"
#include "bli_exp.h"
#include "spc_drv.h"


Int16 eCall_TX_CTRL_SEQ_State[800];
Int16 eCall_TX_CTRL_SEQ_dlData[800];
Int16 eCall_TX_CTRL_SEQ_dlMetric[800];
Int16 eCall_RX_CTRL_SEQ_State[800];
Int16 eCall_RX_CTRL_SEQ_dlData[800];
Int16 eCall_RX_CTRL_SEQ_dlMetric[800];
Int16 eCall_RX_Ctrl_Index;



#define PCM_FIFO_LEN 2   // could be 1 ~ N
#define BLI_SRC_BUFFER_SIZE 2184 // fixed value

typedef enum {
   Udef = -1, Ivs, IvsRx, IvsTx, Psap, PsapRx, PsapTx
} RunMode;

typedef struct {
   RunMode mode;

   kal_bool  ivsPush;
   kal_bool  msdReceived;
   kal_bool  msdSet;
   kal_uint8 aud_id;
   kal_uint8 Ctrl_Par_Switch;
   kal_bool  TxRx;

   int frameStartHlack;
   int frameStartHlackCur;
   
   Ord8  NewMsd[MSD_MAX_LENGTH];
   Ord8  CurMsd[MSD_MAX_LENGTH];
   
   // For PCM4Way
   kal_uint16 pcm_fifo_read;
   kal_uint16 pcm_fifo_write;
   kal_uint16 next_to_process;
   kal_uint16 ul_pcm_fifo[2*PCM_FIFO_LEN][160];
   kal_uint16 dl_pcm_fifo[2*PCM_FIFO_LEN][160];
   kal_uint16 temp_pcm[160];

   //for WB
   uint16 ul_wb_pcm_fifo[2*PCM_FIFO_LEN][320]; // input buffer size = 320
   uint16 dl_wb_pcm_fifo[2*PCM_FIFO_LEN][320];
   //BLI_HANDLE * ul_downsample;
   BLI_HANDLE * dl_downsample;   
   //BLI_HANDLE * ul_upsample;
   BLI_HANDLE * dl_upsample;
   //////////////
   
   eCall_Callback handler;
   
   void *allocMem;
} EcallShell;

static EcallShell *eCallModemIVS;
static EcallShell *eCallModemPSAP;

//uint8 internal_buf_ul_in[2184]; // internal buffer for src
//uint8 internal_buf_ul_out[2184]; // internal buffer for src
//uint8 internal_buf_dl_in[19564]; // internal buffer for src
//uint8 internal_buf_dl_out[19564]; // internal buffer for src
uint8 internal_buf_dl_in[2184]; // internal buffer for src
uint8 internal_buf_dl_out[2184]; // internal buffer for src   

/*------------------------------------------------*/
/* The private functions of eCall modem driver.   */
/*------------------------------------------------*/
#pragma arm section code="SECONDARY_ROCODE"

static void eCall_IVS_hisr(void)
{
   kal_uint16 read_idx, write_idx;
   
   if (eCallModemIVS == NULL)
      return;
   kal_bool is_WB = SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1) == 320 ? KAL_TRUE : KAL_FALSE;
  
   //kal_bool is_WB = 0;

   read_idx  = eCallModemIVS->pcm_fifo_read;
   write_idx = eCallModemIVS->pcm_fifo_write;
   
   if (eCallModemIVS->pcm_fifo_read == eCallModemIVS->next_to_process) {
      // Processed data isn't enough
	if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_ENABLE ){
         		PCM4WAY_FillSE(0); 
         		PCM4WAY_FillSpk(0);
      	}
   } else {
      if(!is_WB) {
	         if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_ENABLE ){
         		PCM4WAY_PutToSE((const uint16*)(eCallModemIVS->ul_pcm_fifo[read_idx]));
         		PCM4WAY_PutToSpk((const uint16*)(eCallModemIVS->dl_pcm_fifo[read_idx]));
         }
      }
	  else {  	
	  	if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_ENABLE ){	
         		PCM4WAY_PutToSE((const uint16*)(eCallModemIVS->ul_wb_pcm_fifo[read_idx]));
         		PCM4WAY_PutToSpk((const uint16*)(eCallModemIVS->dl_wb_pcm_fifo[read_idx]));
	  	}
	  }
	  // Update index
      eCallModemIVS->pcm_fifo_write++;
      if (eCallModemIVS->pcm_fifo_write == 2*PCM_FIFO_LEN) {
         eCallModemIVS->pcm_fifo_write = 0;
      }
   }
   if (read_idx != write_idx) {
   	  if(!is_WB) {
         PCM4WAY_GetFromMic((uint16*)(eCallModemIVS->ul_pcm_fifo[write_idx]));
         PCM4WAY_GetFromSD((uint16*)(eCallModemIVS->dl_pcm_fifo[write_idx]));
   	  }
	  else {
	     PCM4WAY_GetFromMic((uint16*)(eCallModemIVS->ul_wb_pcm_fifo[write_idx]));	  
	     PCM4WAY_GetFromSD((uint16*)(eCallModemIVS->dl_wb_pcm_fifo[write_idx]));	 
	  }
	  // Update index
      eCallModemIVS->pcm_fifo_read++; 
      if (eCallModemIVS->pcm_fifo_read == 2*PCM_FIFO_LEN) {
         eCallModemIVS->pcm_fifo_read = 0;
      }
   }
                        
   L1Audio_SetEvent(eCallModemIVS->aud_id, (void*)0);
}
#pragma arm section

static void eCall_IVS_ProcessFrame(void)
{
   kal_uint32 proc_idx;
   uint16 ret;
   uint32 dl_ds_inLen, dl_ds_outLen,dl_us_inLen,dl_us_outLen;
   kal_bool is_WB = SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1) == 320 ? KAL_TRUE : KAL_FALSE;
   kal_prompt_trace(MOD_L1SP, "SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1):%d ",SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1));
   //kal_bool is_WB = 0;


   
   if (eCallModemIVS == NULL)
      return;

   proc_idx = eCallModemIVS->next_to_process;

   switch (eCallModemIVS->mode) {
      case Ivs:
         if (eCallModemIVS->ivsPush == KAL_TRUE) {
            IvsSendStart();
            eCallModemIVS->ivsPush = KAL_FALSE;
         }
         if(is_WB) {
   	        dl_ds_inLen	= 320 << 1;  // in byte
            dl_ds_outLen = 160 << 1;  // in byte 
            ret = BLI_Convert(eCallModemIVS->dl_downsample, eCallModemIVS->dl_wb_pcm_fifo[proc_idx], &dl_ds_inLen, eCallModemIVS->temp_pcm, &dl_ds_outLen);
            kal_prompt_trace(MOD_L1SP, "[Mike] DL down sampling ret = %d", ret);
         }
		 else {
            memcpy(eCallModemIVS->temp_pcm, eCallModemIVS->dl_pcm_fifo[proc_idx], 160*sizeof(kal_uint16));
		 }
         
#if 1
         {
            IvsState preRxState = IvsRxGetState();
            IvsState curState;
            
            IvsProcess( (Int16 *)eCallModemIVS->temp_pcm );

            curState = IvsTxGetState();
            if ((curState == IvsTrigger) || (curState == IvsStart) || (curState == IvsSendMsd) || (preRxState != IvsIdle) || (IvsRxGetState() != IvsIdle) ) {
				if(is_WB) {
					dl_us_inLen = 160 << 1; // in byte
					dl_us_outLen = 320 << 1;
					ret = BLI_Convert(eCallModemIVS -> dl_upsample, eCallModemIVS->temp_pcm, &dl_us_inLen, eCallModemIVS->ul_wb_pcm_fifo[proc_idx], &dl_us_outLen);				
					kal_prompt_trace(MOD_L1SP, "[Mike] DL up sampling ret = %d", ret);
				}
				else {
			        memcpy(eCallModemIVS->ul_pcm_fifo[proc_idx], eCallModemIVS->temp_pcm, 160*sizeof(kal_uint16));
				}
            }
         }
#else         
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         
         break;
      case IvsRx:
         if (eCallModemIVS->ivsPush == KAL_TRUE) {
            IvsSendStart();
            eCallModemIVS->ivsPush = KAL_FALSE;
         }
         if(is_WB) {
   	        dl_ds_inLen	= 320 << 1;  // in byte
            dl_ds_outLen = 160 << 1;  // in byte 
            ret = BLI_Convert(eCallModemIVS->dl_downsample, eCallModemIVS->dl_wb_pcm_fifo[proc_idx], &dl_ds_inLen, eCallModemIVS->temp_pcm, &dl_ds_outLen);
            kal_prompt_trace(MOD_L1SP, "[Mike] DL down sampling ret = %d", ret);
         }
		 else {
            memcpy(eCallModemIVS->temp_pcm, eCallModemIVS->dl_pcm_fifo[proc_idx], 160*sizeof(kal_uint16));
		 }


#if 1
         {
            IvsState preRxState = IvsRxGetState();
            IvsState curState;
            
            IvsRxProcess( (Int16 *)eCallModemIVS->temp_pcm );
            
            curState = IvsTxGetState();
            if ((curState == IvsTrigger) || (curState == IvsStart) || (curState == IvsSendMsd) || (preRxState != IvsIdle) || (IvsRxGetState() != IvsIdle)){
				if(is_WB) {
					dl_us_inLen = 160 << 1; // in byte
					dl_us_outLen = 320 << 1;
					ret = BLI_Convert(eCallModemIVS -> dl_upsample, eCallModemIVS->temp_pcm, &dl_us_inLen, eCallModemIVS->ul_wb_pcm_fifo[proc_idx], &dl_us_outLen);				
					kal_prompt_trace(MOD_L1SP, "[Mike] DL up sampling ret = %d", ret);
				}
				else {
			        memcpy(eCallModemIVS->ul_pcm_fifo[proc_idx], eCallModemIVS->temp_pcm, 160*sizeof(kal_uint16));
				}


            }
         }
#else          
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         
         break;
      default:
         ASSERT(0);
         break;
   }
}

static void eCall_IVS_ProcessTask(void *data)
{
   if (eCallModemIVS == NULL) {
      return;
   }
   
   while (eCallModemIVS->next_to_process != eCallModemIVS->pcm_fifo_write) {
      // Process each frame
      eCall_IVS_ProcessFrame();
      
      // Update index
      eCallModemIVS->next_to_process++;
      if (eCallModemIVS->next_to_process == 2 * PCM_FIFO_LEN) {
         eCallModemIVS->next_to_process = 0;
      }
   }
}

static void eCall_IVS_OnHandler( void *data ) 
{
   (void)data;
   
   PCM4WAY_Start(eCall_IVS_hisr, 1);
}

static void eCall_IVS_OffHandler( void *data ) 
{      
   (void)data;
   
   PCM4WAY_Stop(0);
}

/*------------------------------------------------*/
/* The public functions of eCall modem driver.    */
/*------------------------------------------------*/
eCall_Modem_Status eCall_IVS_Open(eCall_Callback handler)
{
	uint32 i;
   ASSERT( handler != NULL );
  
   	
   kal_trace( TRACE_GROUP_ECALL, ECALL_IVS_OPEN, spc_Get_Ecall_Lib_Status());
   if (eCallModemPSAP != NULL) {
      return eCALL_OPERATION_FAIL;
   }
   
   if ( eCallModemIVS != NULL ) {
      return eCALL_OPERATION_ALREADY_OPEN;
   }
   
   //L1SP_EnableSpeechEnhancement(KAL_FALSE);
   
   //eCallModemIVS = (EcallShell *)audio_alloc_mem_cacheable( sizeof(EcallShell) );
   eCallModemIVS = (EcallShell *)get_ctrl_buffer( sizeof(EcallShell) );
   ASSERT( eCallModemIVS != NULL );
   memset(eCallModemIVS, 0, sizeof(EcallShell));
   
   // Allocate for IVS internal structure
   {
      kal_uint32 reqSize;
      
      reqSize = (kal_uint32) IvsGetMemSize();
     // eCallModemIVS->allocMem = (void *)audio_alloc_mem_cacheable( reqSize ); 
     eCallModemIVS->allocMem = (void *)get_ctrl_buffer( reqSize );
      memset(eCallModemIVS->allocMem, 0, sizeof(reqSize));
      IvsInit( eCallModemIVS->allocMem );
   }
   
   eCallModemIVS->aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler(eCallModemIVS->aud_id , eCall_IVS_ProcessTask);
   L1Audio_SetFlag(eCallModemIVS->aud_id);
   
   IvsRxReset();
   
   eCallModemIVS->mode = IvsRx;
   eCallModemIVS->pcm_fifo_read = 0;
   eCallModemIVS->pcm_fifo_write = PCM_FIFO_LEN;
   eCallModemIVS->next_to_process = PCM_FIFO_LEN;
   eCallModemIVS->handler = handler;
   
   //Init eCall RX ctrl seq 
    memset(eCall_RX_CTRL_SEQ_State, 0, 800*sizeof(Int16));
    memset(eCall_RX_CTRL_SEQ_dlData, 0, 800*sizeof(Int16));
    memset(eCall_RX_CTRL_SEQ_dlMetric, 0, 800*sizeof(Int16));
    eCall_RX_Ctrl_Index = 1;
    eCall_RX_CTRL_SEQ_dlMetric[0] = 0xFF;
    eCall_RX_CTRL_SEQ_State[0] = 0xDD;
    eCall_RX_CTRL_SEQ_dlData[0] = 0xEE;
   


  


   //eCallModemIVS -> ul_downsample =  BLI_Open( 16000, 1, 8000, 1, (char*)internal_buf_ul_in, 0); // open UL down sampling src
   eCallModemIVS -> dl_downsample =  BLI_Open( 16000, 1, 8000, 1, (char*)internal_buf_dl_in, 0); // open DL down sampling src
   //eCallModemIVS -> ul_upsample =  BLI_Open( 8000, 1, 16000, 1, (char*)internal_buf_ul_out, 0); // open UL up sampling src
   eCallModemIVS -> dl_upsample =  BLI_Open( 8000, 1, 16000, 1, (char*)internal_buf_dl_out, 0); // open DL up sampling src

   if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_SDT_ONLY ){
	Ivs_Set_Ecall_Lib_Status(Ivs_ECALL_SDT_ONLY);   
   }else if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_ENABLE){
	Ivs_Set_Ecall_Lib_Status(Ivs_ECALL_ENABLE);   
   }else {
	return eCALL_OPERATION_FAIL;   
   }

   if ( AM_IsSpeechOn() ) {
      eCall_IVS_OnHandler( (void *)0 );
   }

   


   // Hook service to L1SP
   L1SP_Register_Pcm4WayService( eCall_IVS_OnHandler, eCall_IVS_OffHandler );
   
   return eCALL_OPERATION_SUCCESS;
}

eCall_Modem_Status eCall_IVS_Close(void)
{
	uint32 i;
    kal_trace( TRACE_GROUP_ECALL, ECALL_IVS_CLOSE);
   if ( eCallModemIVS == NULL ) {
      return eCALL_OPERATION_ALREADY_CLOSE;
   }

   if (eCallModemPSAP != NULL) {
      return eCALL_OPERATION_FAIL;
   }
   if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_DISABLE){
	   return eCALL_OPERATION_FAIL;   	
   }
   //close blisrc
   //BLI_Close( eCallModemIVS-> ul_downsample, 0); // Close UL down sampling src
   BLI_Close( eCallModemIVS-> dl_downsample, 0); // Close DL down sampling src
   //BLI_Close( eCallModemIVS-> ul_upsample, 0); // Close UL up sampling src
   BLI_Close( eCallModemIVS-> dl_upsample, 0); // Close DL up sampling src


   // Unhook service to L1SP
   L1SP_UnRegister_Pcm4Way_Service();
   
   if ( AM_IsSpeechOn() ) {
      eCall_IVS_OffHandler( (void *)0 );
   }
   
   L1Audio_ClearFlag(eCallModemIVS->aud_id);
   L1Audio_FreeAudioID(eCallModemIVS->aud_id);
   
   // Deallocate for IVS internal structure
   {
      IvsDeinit();
	  free_ctrl_buffer( (void *) eCallModemIVS->allocMem );
   }
   
   free_ctrl_buffer( (void *) eCallModemIVS );
   //L1SP_EnableSpeechEnhancement(KAL_TRUE);
   eCallModemIVS = NULL;

   //transfer ctrl data to AP
   spc_eCall_RX_CTRL_Data(0xDD);
   spc_eCall_RX_CTRL_Data(0xEE);
   spc_eCall_RX_CTRL_Data(0xFF);
	 
   
   return eCALL_OPERATION_SUCCESS;
}

eCall_Modem_Status eCall_IVS_PutMSD(const kal_uint8 *pMSD, const kal_uint32 uLen)
{   
	kal_uint8 i=0;
   if (eCallModemPSAP != NULL) {
      return eCALL_OPERATION_FAIL;
   }

   if ( eCallModemIVS == NULL ) {
      return eCALL_OPERATION_FAIL;
   }

   if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_SDT_ONLY)
   {
	return eCALL_OPERATION_STOP;
   }
   ASSERT( pMSD != NULL );
   ASSERT( uLen <= MSD_MAX_LENGTH);
   
   memset(eCallModemIVS->NewMsd, 0, MSD_MAX_LENGTH*sizeof(Ord8));
   memcpy(eCallModemIVS->NewMsd, pMSD, uLen*sizeof(Ord8));
   //for(i=0;i<140;i=i+7)
  // {
//	 kal_trace( TRACE_GROUP_ECALL, ECALL_IVS_PUT_MSD, pMSD[i],pMSD[i+1],pMSD[i+2],pMSD[i+3],pMSD[i+4],pMSD[i+5],pMSD[i+6]);	  	
 //  }
   // Check status and copy to current MSD
   //if ( IvsTxGetState() == IvsIdle ) {
      memcpy(eCallModemIVS->CurMsd, eCallModemIVS->NewMsd, MSD_MAX_LENGTH*sizeof(Ord8));
   //}
   for(i=0;i<140;i=i+7)
   {
	 kal_trace( TRACE_GROUP_ECALL, ECALL_IVS_PUT_MSD, eCallModemIVS->CurMsd[i],eCallModemIVS->CurMsd[i+1],eCallModemIVS->CurMsd[i+2],eCallModemIVS->CurMsd[i+3],eCallModemIVS->CurMsd[i+4],eCallModemIVS->CurMsd[i+5],eCallModemIVS->CurMsd[i+6]);	  	
   }   
   eCallModemIVS->msdSet = KAL_TRUE;
   IvsTxReset(eCallModemIVS->CurMsd, MSD_MAX_LENGTH);
   
   return eCALL_OPERATION_SUCCESS;
}

eCall_Modem_Status eCall_IVS_SendStart(void)
{
   kal_trace( TRACE_GROUP_ECALL, ECALL_IVS_SEND_START);

   if (eCallModemPSAP != NULL) {
      return eCALL_OPERATION_FAIL;
   }

   if ( eCallModemIVS == NULL ) {
      return eCALL_OPERATION_FAIL;
   }
   
   // Check state
   if ( IvsTxGetState() != IvsIdle ) {
      return eCALL_OPERATION_DURING_TRANSMISSION;
   }
   if(spc_Get_Ecall_Lib_Status()==SPC_ECALL_DISABLE){
	   return eCALL_OPERATION_FAIL;   	
   }
   eCallModemIVS->TxRx = KAL_TRUE;
   IvsRxReset();
   
   if (eCallModemIVS->msdSet) {
      eCallModemIVS->mode = Ivs;
   }
   
   eCallModemIVS->ivsPush = KAL_TRUE;
   
   return eCALL_OPERATION_SUCCESS;
}


#if 1
/*------------------------------------------------*/
/* The unit test code for callback.               */
/*------------------------------------------------*/

void IvsCatchEvent(IvsEvent ie)
{
   ASSERT(eCallModemIVS);
   
   kal_trace( TRACE_GROUP_ECALL, ECALL_IVS_DRV_CATCH_EVENT, ie);
   /* custom event handlers to be implemented here... */
   /* see modemx.h for a list of possible events (enum IvsEvent) */
   switch (ie) {
      case IVSEVENT_SENDINGMSD:
       	spc_eCall_Handshake_Info_Notify(0xE1,0);
       break;
      case IVSEVENT_CONTROLLOCK:
         eCallModemIVS->mode = Ivs;
         eCallModemIVS->TxRx = KAL_TRUE;	
         eCallModemIVS->handler( eCALL_EVENT_RECV_START, NULL);
         break;
      case IVSEVENT_NACKRECEIVED:
         eCallModemIVS->handler( eCALL_EVENT_RECV_NACK, NULL);
         break;
      case IVSEVENT_LLACKRECEIVED:
         eCallModemIVS->mode = IvsRx;
         spc_eCall_Handshake_Info_Notify(0xE2,0);		 
         eCallModemIVS->handler( eCALL_EVENT_RECV_LL_ACK, NULL);
         break;
      case IVSEVENT_HLACKRECEIVED:
         eCallModemIVS->mode = IvsRx;
         break;
      case IVSEVENT_RECEIVESTART:
         spc_eCall_Handshake_Info_Notify(0xE4,0);
         break;		 
      default:
         break;
   }
}

void IvsReceiveHlack(const Ord8 data)
{
   kal_trace( TRACE_GROUP_ECALL, ECALL_IVS_DRV_HLACK, (eCallModemIVS->CurMsd[0] & 0x0F), (data & 0x0F));
    spc_eCall_Handshake_Info_Notify(0xE3,data);	
   if ((eCallModemIVS->CurMsd[0] & 0x0F) == (data & 0x0F)) {
      eCallModemIVS->handler( eCALL_EVENT_RECV_HL_ACK_CORRECT, (void *)data);
   } else {
      eCallModemIVS->handler( eCALL_EVENT_RECV_HL_ACK_MISMATCH, (void *)data);
   }
   IvsRxReset();
   IvsTxReset(eCallModemIVS->CurMsd, MSD_MAX_LENGTH);
   eCallModemIVS->TxRx = KAL_FALSE;
}

void PsapCatchEvent(PsapEvent pe)
{
   kal_trace( TRACE_GROUP_ECALL, ECALL_PSAP_DRV_CATCH_EVENT, pe);
   
   switch (pe) {
      /* custom event handlers to be implemented here... */
      /* see modemx.h for a list of possible events (enum PsapEvent) */
      case PSAPEVENT_CONTROLLOCK:
         eCallModemPSAP->TxRx = KAL_TRUE;
         break;
      case PSAPEVENT_IDLEPOSTHLACK:
         PsapReset();
         eCallModemPSAP->frameStartHlackCur = 0;
         eCallModemPSAP->msdReceived = KAL_FALSE;
         eCallModemPSAP->ivsPush = KAL_TRUE;
         eCallModemPSAP->TxRx = KAL_FALSE;
         break;
      default:
         break;
   }
}

#endif

#if defined(__ECALL_PSAP_SUPPORT__)

/*------------------------------------------------*/
/* The unit test code for PSAP.                   */
/*------------------------------------------------*/

void PsapReceiveMsd(const Ord8 *msd, int length) {
   int n;
   
   kal_trace( TRACE_GROUP_ECALL, ECALL_PSAP_DRV_RECEIVE_MSD);
   
   for (n = 0; n < MSD_MAX_LENGTH; n++) {
      eCallModemPSAP->CurMsd[n] = msd[n];
   }
   eCallModemPSAP->msdReceived = KAL_TRUE;

   for (n=0; n<20; n++) {
      kal_uint32 base = 7*n;
      
      kal_trace( TRACE_GROUP_ECALL, ECALL_PSAP_DRV_MSD_DATA,
         msd[base], msd[base+1], msd[base+2], msd[base+3], msd[base+4], msd[base+5], msd[base+6]);
   }
   
   eCallModemPSAP->handler( eCALL_EVENT_PSAP_RECV_MSD, eCallModemPSAP->CurMsd);
}

#pragma arm section code="SECONDARY_ROCODE"
static void eCall_PSAP_hisr(void)
{
   kal_uint16 read_idx, write_idx;
   //kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
   kal_bool is_WB = SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1) == 320 ? KAL_TRUE : KAL_FALSE;
   kal_prompt_trace(MOD_L1SP, "SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1):%d ",SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1));
   //kal_bool is_WB = 0;

   read_idx  = eCallModemPSAP->pcm_fifo_read;
   write_idx = eCallModemPSAP->pcm_fifo_write;
   
   if (eCallModemPSAP->pcm_fifo_read == eCallModemPSAP->next_to_process) {
      // Processed data isn't enough
      PCM4WAY_FillSE(0);
      PCM4WAY_FillSpk(0);
   } else {
      if(!is_WB){
         PCM4WAY_PutToSE((const uint16*)(eCallModemPSAP->ul_pcm_fifo[read_idx]));
         PCM4WAY_PutToSpk((const uint16*)(eCallModemPSAP->dl_pcm_fifo[read_idx]));
      }
      else {
	     PCM4WAY_PutToSE((const uint16*)(eCallModemPSAP->ul_wb_pcm_fifo[read_idx]));
         PCM4WAY_PutToSpk((const uint16*)(eCallModemPSAP->dl_wb_pcm_fifo[read_idx]));
	  }
      // Update index
      eCallModemPSAP->pcm_fifo_write++;
      if (eCallModemPSAP->pcm_fifo_write == 2*PCM_FIFO_LEN) {
         eCallModemPSAP->pcm_fifo_write = 0;
      }
   }
   if (read_idx != write_idx) {
      // There is enough space to write data from microphone
      if(!is_WB){
         PCM4WAY_GetFromMic((uint16*)(eCallModemPSAP->ul_pcm_fifo[write_idx]));
         PCM4WAY_GetFromSD((uint16*)(eCallModemPSAP->dl_pcm_fifo[write_idx]));
      }
	  else {
		 PCM4WAY_GetFromMic((uint16*)(eCallModemPSAP->ul_wb_pcm_fifo[write_idx]));	   
		 PCM4WAY_GetFromSD((uint16*)(eCallModemPSAP->dl_wb_pcm_fifo[write_idx]));
	  }
      
      // Update index
      eCallModemPSAP->pcm_fifo_read++; 
      if (eCallModemPSAP->pcm_fifo_read == 2*PCM_FIFO_LEN) {
         eCallModemPSAP->pcm_fifo_read = 0;
      }
   }
                        
   L1Audio_SetEvent(eCallModemPSAP->aud_id, (void*)0);
}
#pragma arm section

static void eCall_PSAP_ProcessFrame(void)
{
   kal_uint32 proc_idx = eCallModemPSAP->next_to_process;
   uint32 dl_ds_inLen, dl_ds_outLen,dl_us_inLen,dl_us_outLen;
   uint16 ret;
   //kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
   kal_bool is_WB = SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1) == 320 ? KAL_TRUE : KAL_FALSE;
   kal_prompt_trace(MOD_L1SP, "SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1):%d ",SAL_PcmEx_GetBufLen(SAL_PCMEX_PNW_BUF_UL1));
   //kal_bool is_WB = 0;

   switch (eCallModemPSAP->mode) {
      case Psap:
         if (eCallModemPSAP->ivsPush == KAL_FALSE) {
            PsapSendStart();
            eCallModemPSAP->ivsPush = KAL_TRUE;
         }
         if (eCallModemPSAP->msdReceived == KAL_TRUE) {
            if ( ++eCallModemPSAP->frameStartHlackCur == eCallModemPSAP->frameStartHlack)
               PsapSendHlack(eCallModemPSAP->CurMsd[0] & 0x0F);
         }
         if(is_WB) {
   	        dl_ds_inLen	= 320 << 1;  // in byte
            dl_ds_outLen = 160 << 1;  // in byte 


            ret = BLI_Convert(eCallModemPSAP->dl_downsample, eCallModemPSAP->dl_wb_pcm_fifo[proc_idx], &dl_ds_inLen, eCallModemPSAP->temp_pcm, &dl_ds_outLen);
            kal_prompt_trace(MOD_L1SP, "[Mike] DL down sampling ret = %d", ret);
         }
		 else {
            memcpy(eCallModemPSAP->temp_pcm, eCallModemPSAP->dl_pcm_fifo[proc_idx], 160*sizeof(kal_uint16));     
		 }
         PsapProcess( (Int16 *)eCallModemPSAP->temp_pcm );
         
         if (eCallModemPSAP->TxRx){
			 if(is_WB) {
				dl_us_inLen = 160 << 1; // in byte
				dl_us_outLen = 320 << 1;
				ret = BLI_Convert(eCallModemPSAP -> dl_upsample, eCallModemPSAP->temp_pcm, &dl_us_inLen, eCallModemPSAP->ul_wb_pcm_fifo[proc_idx], &dl_us_outLen);			 
				kal_prompt_trace(MOD_L1SP, "[Mike] DL up sampling ret = %d", ret);
			 }
			 else {
                memcpy(eCallModemPSAP->ul_pcm_fifo[proc_idx], eCallModemPSAP->temp_pcm, 160*sizeof(kal_uint16));
			 }
		 }
         break;
      case PsapRx:
         if (eCallModemPSAP->ivsPush == KAL_FALSE) {
            PsapSendStart();
            eCallModemPSAP->ivsPush = KAL_TRUE;
         }
         if (eCallModemPSAP->msdReceived == KAL_TRUE) {
            if ( ++eCallModemPSAP->frameStartHlackCur == eCallModemPSAP->frameStartHlack)
               PsapSendHlack(eCallModemPSAP->CurMsd[0] & 0x0F);
         }
         if(is_WB) {
   	        dl_ds_inLen	= 320 << 1;  // in byte
            dl_ds_outLen = 160 << 1;  // in byte 
            ret = BLI_Convert(eCallModemPSAP->dl_downsample, eCallModemPSAP->dl_wb_pcm_fifo[proc_idx], &dl_ds_inLen, eCallModemPSAP->temp_pcm, &dl_ds_outLen);
            kal_prompt_trace(MOD_L1SP, "[Mike] DL down sampling ret = %d", ret);
         }
		 else {
            memcpy(eCallModemPSAP->temp_pcm, eCallModemPSAP->dl_pcm_fifo[proc_idx], 160*sizeof(kal_uint16));     
		 }  
         PsapRxProcess( (Int16 *)eCallModemPSAP->temp_pcm );
         
         if (eCallModemPSAP->TxRx){
			 if(is_WB) {
		        dl_us_inLen = 160 << 1; // in byte
				dl_us_outLen = 320 << 1;
				ret = BLI_Convert(eCallModemPSAP -> dl_upsample, eCallModemPSAP->temp_pcm, &dl_us_inLen, eCallModemPSAP->ul_wb_pcm_fifo[proc_idx], &dl_us_outLen);			 
				kal_prompt_trace(MOD_L1SP, "[Mike] DL up sampling ret = %d", ret);
			 }
			 else {
                memcpy(eCallModemPSAP->ul_pcm_fifo[proc_idx], eCallModemPSAP->temp_pcm, 160*sizeof(kal_uint16));
			 }
		 }
		 break;
      default:
         ASSERT(0);
         break;
   }
}

static void eCall_PSAP_ProcessTask(void *data)
{
   if (eCallModemPSAP == NULL) {
      return;
   }
   
   while (eCallModemPSAP->next_to_process != eCallModemPSAP->pcm_fifo_write) {
      // Process each frame
      eCall_PSAP_ProcessFrame();
      
      // Update index
      eCallModemPSAP->next_to_process++;
      if (eCallModemPSAP->next_to_process == 2 * PCM_FIFO_LEN) {
         eCallModemPSAP->next_to_process = 0;
      }
   }
}

static void eCall_PSAP_OnHandler( void *data ) 
{
   (void)data;
   
   PCM4WAY_Start(eCall_PSAP_hisr, 1);
}

static void eCall_PSAP_OffHandler( void *data ) 
{      
   (void)data;
   
   PCM4WAY_Stop(0);
}


eCall_Modem_Status eCall_PSAP_Open(eCall_Callback handler)
{              
	 

   ASSERT( handler != NULL );
   
   if ( eCallModemIVS != NULL ) {
      return eCALL_OPERATION_FAIL;
   }
   
   if ( eCallModemPSAP != NULL ) {
      return eCALL_OPERATION_ALREADY_OPEN;
   }
   

      
   //L1SP_EnableSpeechEnhancement(KAL_FALSE);
   
   //eCallModemPSAP = (EcallShell *)audio_alloc_mem_cacheable( sizeof(EcallShell) ); 
   eCallModemPSAP = (EcallShell *)get_ctrl_buffer( sizeof(EcallShell) );
   ASSERT( eCallModemPSAP != NULL );
   memset(eCallModemPSAP, 0, sizeof(EcallShell));
   
   // Allocate for PSAP internal structure
   {
      kal_uint32 reqSize;
      
      reqSize = (kal_uint32) PsapGetMemSize();
      //eCallModemPSAP->allocMem = (void *)audio_alloc_mem_cacheable( reqSize );
      eCallModemPSAP->allocMem = (void *)get_ctrl_buffer( reqSize );
      memset(eCallModemPSAP->allocMem, 0, sizeof(reqSize));
      PsapInit( eCallModemPSAP->allocMem );
   }
   
   eCallModemPSAP->aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler(eCallModemPSAP->aud_id , eCall_PSAP_ProcessTask);
   L1Audio_SetFlag(eCallModemPSAP->aud_id);
   
   PsapReset();
   
   // open BLI Src for psap   
   eCallModemPSAP->dl_downsample =  BLI_Open( 16000, 1, 8000, 1, (char*)internal_buf_dl_in, 0); // open DL down sampling src
   eCallModemPSAP->dl_upsample =  BLI_Open( 8000, 1, 16000, 1, (char*)internal_buf_dl_out, 0); // open DL up sampling src
   kal_prompt_trace(MOD_L1SP, "[Mike] finish psap bli_open");
   
   eCallModemPSAP->mode = Psap; //PsapRx;
   eCallModemPSAP->ivsPush = KAL_TRUE; //KAL_FALSE;
   eCallModemPSAP->msdReceived = KAL_FALSE;
   eCallModemPSAP->frameStartHlack = 10;
   eCallModemPSAP->pcm_fifo_read = 0;
   eCallModemPSAP->pcm_fifo_write = PCM_FIFO_LEN;
   eCallModemPSAP->next_to_process = PCM_FIFO_LEN;
   eCallModemPSAP->frameStartHlackCur = 0;
   eCallModemPSAP->handler = handler;
   
   if ( AM_IsSpeechOn() ) {
      eCall_PSAP_OnHandler( (void *)0 );
   }
   
   // Hook service to L1SP
   L1SP_Register_Pcm4WayService( eCall_PSAP_OnHandler, eCall_PSAP_OffHandler );
   
   return eCALL_OPERATION_SUCCESS;
}

eCall_Modem_Status eCall_PSAP_Close(void)
{
   if( eCallModemPSAP == NULL ) {
      return eCALL_OPERATION_ALREADY_CLOSE;
   }
   
   if ( eCallModemIVS != NULL ) {
      return eCALL_OPERATION_FAIL;
   }

      //close blisrc
   //BLI_Close( eCallModemPSAP-> ul_downsample, 0); // Close UL down sampling src
   BLI_Close( eCallModemPSAP-> dl_downsample, 0); // Close DL down sampling src
   //BLI_Close( eCallModemPSAP-> ul_upsample, 0); // Close UL up sampling src
   BLI_Close( eCallModemPSAP-> dl_upsample, 0); // Close DL up sampling src
   
   // Unhook service to L1SP
   L1SP_UnRegister_Pcm4Way_Service();
   
   if ( AM_IsSpeechOn() ) {
      eCall_PSAP_OffHandler( (void *)0 );
   }
   
   L1Audio_ClearFlag(eCallModemPSAP->aud_id);
   L1Audio_FreeAudioID(eCallModemPSAP->aud_id);
   
   // Deallocate for PSAP internal structure
   {
      PsapDeinit();
	  free_ctrl_buffer( (void *) eCallModemPSAP->allocMem );
   }
   
   free_ctrl_buffer( (void *) eCallModemPSAP ); 
   //L1SP_EnableSpeechEnhancement(KAL_TRUE);
   eCallModemPSAP = NULL;
   return eCALL_OPERATION_SUCCESS;
}

eCall_Modem_Status eCall_PSAP_SendStart(void)
{
   if (eCallModemPSAP == NULL) {
      return eCALL_OPERATION_FAIL;
   }
   
   if ( eCallModemIVS != NULL ) {
      return eCALL_OPERATION_FAIL;
   }
   
   eCallModemPSAP->TxRx = KAL_TRUE;
   eCallModemPSAP->mode = Psap;
   eCallModemPSAP->ivsPush = KAL_FALSE;
   
   return eCALL_OPERATION_SUCCESS;
}

#else

// Provide dummy function to support feature switchable
void PsapReceiveMsd(const Ord8 *msd, int length) { }
eCall_Modem_Status eCall_PSAP_Open(eCall_Callback handler) {return eCALL_OPERATION_FAIL;}
eCall_Modem_Status eCall_PSAP_Close(void) {return eCALL_OPERATION_FAIL;}
eCall_Modem_Status eCall_PSAP_SendStart(void) {return eCALL_OPERATION_FAIL;}

#endif
