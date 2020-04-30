
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "kal_trace.h"


#include "l1audio_def.h"
#include "l1sp_trc.h"
#include "common_def.h"


#include "l1audio.h"
#include "spc_drv.h"

#if defined(__SMART_PHONE_MODEM__)		
extern _SP_ENC SP_ENC; 
#endif

static uint16 sp_2G_ul_tempBuf[SAL_2G_DATA_HB_LEN+3]; // enc_hdr+data+len
static uint16 sp_2G_dl_tempBuf[SAL_2G_DATA_HB_LEN+3];//dec_hdr+1+len
int32 before_ul_codec;
int32 before_dl_codec;






void SP_ENC_2G_DL_task(void *data)
{
#if defined(__SMART_PHONE_MODEM__)

	int32 I;

    SP_ENC.DL_2G_befor_Dec_buffer[0]= Set_Network_2G;
	SP_ENC.DL_2G_befor_Dec_buffer[1] = SP_ENC.Spc_2G_DL_Dbg_Count;
	SP_ENC.Spc_2G_DL_Dbg_Count =SP_ENC.Spc_2G_DL_Dbg_Count+1;
 	  
   	if(SP_ENC.Spc_2G_DL_Dbg_Count == 0xFF)
	{
	   SP_ENC.Spc_2G_DL_Dbg_Count = 0;
	}

	for(I=0;I<(SAL_2G_DATA_HB_LEN+3);I++)
	{
		SP_ENC.DL_2G_befor_Dec_buffer[2+I]= sp_2G_dl_tempBuf[I];
	}
	Spc_SetVoiceDecryptionHandler(Set_2G_Decrypt);
	
#endif

}

void SP_ENC_2G_UL_task(void *data)
{
#if defined(__SMART_PHONE_MODEM__)

	int32 I;

	SP_ENC.UL_2G_befor_Enc_buffer[0]= Set_Network_2G;
	SP_ENC.UL_2G_befor_Enc_buffer[1] = SP_ENC.Spc_2G_UL_Dbg_Count;
	SP_ENC.Spc_2G_UL_Dbg_Count =SP_ENC.Spc_2G_UL_Dbg_Count+1;
 	  
   	if(SP_ENC.Spc_2G_UL_Dbg_Count == 0xFF)
	{
	   SP_ENC.Spc_2G_UL_Dbg_Count = 0;
	}

	for(I=0;I<(SAL_2G_DATA_HB_LEN+3);I++)
	{
		SP_ENC.UL_2G_befor_Enc_buffer[2+I]= sp_2G_ul_tempBuf[I];
	}
    Spc_SetVoiceEncryptionHandler(Set_2G_Encrypt);
	    
#endif

}
	




void sp2genc_hisr_ul(void *data)
{
#if defined(__SMART_PHONE_MODEM__)

	Sal_2G_Data ul2Gfrm;
	volatile uint16* dsp_ptr;
	int i;
	int32 after_ul_codec;
	
	SAL_Get_2G_Data(&ul2Gfrm);


	dsp_ptr = ul2Gfrm.enc_hdr_addr;
    sp_2G_ul_tempBuf[0] = *dsp_ptr;
	
	dsp_ptr = ul2Gfrm.enc_mode_addr;
	sp_2G_ul_tempBuf[1] = *dsp_ptr;
	after_ul_codec = sp_2G_ul_tempBuf[1];
	
	sp_2G_ul_tempBuf[2] = SAL_2G_DATA_HB_LEN;
	
    dsp_ptr =  ul2Gfrm.enc_hb_addr;
	
   	for( i=0; i<SAL_2G_DATA_HB_LEN; i++ ){
        sp_2G_ul_tempBuf[i+3] = *dsp_ptr ++ ;
	}


	// put ENC UL data to dsp and modify index
	if(SP_ENC.UL_2G_Delay_Count < 3)
	{ 
        kal_trace( TRACE_FUNC,SPC_ENC_2G_UL_ENC_DATA_NOT_READY,SP_ENC.UL_2G_Delay_Count,SP_ENC.UL_2G_after_Enc_buffer_count);	
	 	SP_ENC.UL_2G_Delay_Count++;
		SAL_HNW_Set_Ready_UL(false);
	}
	else if(SP_ENC.UL_2G_Delay_Count==3 && SP_ENC.UL_2G_after_Enc_buffer_count == 0)
	{
		kal_trace( TRACE_FUNC,SPC_ENC_2G_UL_ENC_DATA_NOT_READY,SP_ENC.UL_2G_Delay_Count,SP_ENC.UL_2G_after_Enc_buffer_count);
		SAL_HNW_Set_Ready_UL(false);
	}
	else
	{
        dsp_ptr = ul2Gfrm.enc_hdr_addr;
		*dsp_ptr = SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][0];
		
		dsp_ptr = ul2Gfrm.enc_mode_addr;
		*dsp_ptr = SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][1];
		
		dsp_ptr = ul2Gfrm.enc_hb_addr;
		
		for( i=0; i<SAL_2G_DATA_HB_LEN; i++ )
		{		
			*dsp_ptr ++ =  SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][3+i];	
		}
		
        
		kal_trace( TRACE_FUNC,SPC_ENC_GET_2G_UL_DATA,SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][0],SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][1],SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][2],SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][3],SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][4],SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][5],SP_ENC.UL_2G_after_Enc_buffer[SP_ENC.UL_2G_after_Enc_buffer_read_index][6]);		
		if(SP_ENC.UL_2G_after_Enc_buffer_count != 0)
        {
			SP_ENC.UL_2G_after_Enc_buffer_count--;
        }
	    SP_ENC.UL_2G_after_Enc_buffer_read_index++;
        if(SP_ENC.UL_2G_after_Enc_buffer_read_index == MAX_UL_2G_ENC_BUFFER_NUM )
        {
           	SP_ENC.UL_2G_after_Enc_buffer_read_index = 0;
        }
		
		SAL_HNW_Set_Ready_UL(true);	
	}
	if(after_ul_codec != before_ul_codec)
	{
	    kal_trace( TRACE_FUNC,SPC_ENC_2G_CODEC_CHANGE,before_ul_codec,after_ul_codec);
		SP_ENC_2G_Init();	
	}
	before_ul_codec = after_ul_codec;
	kal_trace( TRACE_FUNC,SPC_ENC_CHECK_2G_UL_BUFFER_INDEX,1,SP_ENC.UL_2G_after_Enc_buffer_count,SP_ENC.UL_2G_after_Enc_buffer_read_index,SP_ENC.UL_2G_after_Enc_buffer_write_index);
	L1Audio_SetEvent(SP_ENC.aud_UL_id, (void*)0);
#endif  
}

void sp2gdec_hisr_dl(void *data)
{
#if defined(__SMART_PHONE_MODEM__)
	Sal_2G_Data dl2Gfrm;
	volatile uint16* dsp_ptr;
	int i;
	int32 after_dl_codec;

    SAL_Get_2G_Data(&dl2Gfrm);
	
	dsp_ptr =  dl2Gfrm.dec_hdr_addr;
    sp_2G_dl_tempBuf[0] = *dsp_ptr; // feame type 

	dsp_ptr =  dl2Gfrm.dec_mode_addr;
	sp_2G_dl_tempBuf[1] = *dsp_ptr; // feame type 
	after_dl_codec = sp_2G_dl_tempBuf[1];
	
	sp_2G_dl_tempBuf[2] = SAL_2G_DATA_HB_LEN;
	
	//read data from DSP

    dsp_ptr =  dl2Gfrm.dec_hb_addr;
	
   	for( i=0; i<SAL_2G_DATA_HB_LEN; i++ )
	{
        sp_2G_dl_tempBuf[i+3] = *dsp_ptr ++ ;
	}
	
	// put DEC DL data to dsp and modify index
	if(SP_ENC.DL_2G_Delay_Count < 3)
	{    
		kal_trace( TRACE_FUNC,SPC_ENC_2G_DL_DEC_DATA_NOT_READY,SP_ENC.DL_2G_Delay_Count,SP_ENC.DL_2G_after_Dec_buffer_count);
	 	SP_ENC.DL_2G_Delay_Count++;
		SAL_HNW_Set_Ready_DL(false);
	}
	else if(SP_ENC.DL_2G_Delay_Count==3 && SP_ENC.DL_2G_after_Dec_buffer_count == 0)
	{    
		kal_trace( TRACE_FUNC,SPC_ENC_2G_DL_DEC_DATA_NOT_READY,SP_ENC.DL_2G_Delay_Count,SP_ENC.DL_2G_after_Dec_buffer_count);
		SAL_HNW_Set_Ready_DL(false);
	}
	else
	{           
	    dsp_ptr =  dl2Gfrm.dec_hdr_addr;
     	*dsp_ptr=  SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][0];
		dsp_ptr =  dl2Gfrm.dec_hb_addr;
        for( i=0; i<SAL_2G_DATA_HB_LEN; i++ ) 
        {
        	*dsp_ptr ++ = SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][3+i];
        }
		
		kal_trace( TRACE_FUNC,SPC_DEC_GET_2G_DL_DATA,SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][0],SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][1],SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][2],SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][3],SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][4],SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][5],SP_ENC.DL_2G_after_DEC_buffer[SP_ENC.DL_2G_after_Dec_buffer_read_index][6]);
		if(SP_ENC.DL_2G_after_Dec_buffer_count != 0)
        {
			SP_ENC.DL_2G_after_Dec_buffer_count--;
        }
	    SP_ENC.DL_2G_after_Dec_buffer_read_index++;
        if(SP_ENC.DL_2G_after_Dec_buffer_read_index == MAX_DL_2G_ENC_BUFFER_NUM )
        {
           	SP_ENC.DL_2G_after_Dec_buffer_read_index = 0;
        }	
		SAL_HNW_Set_Ready_DL(true);
	 }
	 if(after_dl_codec != before_dl_codec)
	 {		
		kal_trace( TRACE_FUNC,SPC_DEC_2G_CODEC_CHANGE,before_dl_codec,after_dl_codec);
		SP_ENC_2G_Init();	
	 }
	 before_dl_codec = after_dl_codec;
	 kal_trace( TRACE_FUNC,SPC_DEC_CHECK_2G_DL_BUFFER_INDEX,1,SP_ENC.DL_2G_after_Dec_buffer_count,SP_ENC.DL_2G_after_Dec_buffer_read_index,SP_ENC.DL_2G_after_Dec_buffer_write_index);
	 L1Audio_SetEvent(SP_ENC.aud_DL_id, (void*)0);

#endif
}


void SP_ENC_2G_Init(void)
{
#if defined(__SMART_PHONE_MODEM__)
	SP_ENC.UL_2G_after_Enc_buffer_write_index =0;
	SP_ENC.UL_2G_after_Enc_buffer_read_index =0;
	SP_ENC.UL_2G_after_Enc_buffer_count =0;
	SP_ENC.DL_2G_after_Dec_buffer_write_index =0;
	SP_ENC.DL_2G_after_Dec_buffer_read_index =0;
	SP_ENC.DL_2G_after_Dec_buffer_count =0;
    SP_ENC.Spc_2G_DL_Dbg_Count = 0;
	SP_ENC.Spc_2G_UL_Dbg_Count = 0;
	SP_ENC.UL_2G_Delay_Count = 0;
    SP_ENC.DL_2G_Delay_Count =0;
#endif	

}

void SP_ENC_2G_Open(void)
{
#if defined(__SMART_PHONE_MODEM__)

	if(SP_ENC.Is_2G_Voice_Enc == true)
	{
		return;
	}
    //init
	L1Audio_SetEventHandler(SP_ENC.aud_UL_id , SP_ENC_2G_UL_task);
	L1Audio_SetEventHandler(SP_ENC.aud_DL_id , SP_ENC_2G_DL_task);

	// Hook handler
   L1Audio_HookHisrHandler(DP_D2C_DEC_REQ_DL,(L1Audio_EventHandler)sp2gdec_hisr_dl, 0);
   L1Audio_HookHisrHandler(DP_D2C_ENC_REQ_UL,(L1Audio_EventHandler)sp2genc_hisr_ul, 0);
   SP_ENC_2G_Init();
   SAL_HNW_Switch(true);

   before_ul_codec = 0;
   before_dl_codec = 0;
   
   SP_ENC.Is_2G_Voice_Enc = true;
#endif
}

void SP_ENC_2G_Close(void)
{
#if defined(__SMART_PHONE_MODEM__)
	if(SP_ENC.Is_2G_Voice_Enc == false)
	{
		return;
	}

// unhook handler
	L1Audio_UnhookHisrHandler(DP_D2C_DEC_REQ_DL);
	L1Audio_UnhookHisrHandler(DP_D2C_ENC_REQ_UL);
	
	SAL_HNW_Switch(false);
	SP_ENC.Is_2G_Voice_Enc = false;
#endif
}

