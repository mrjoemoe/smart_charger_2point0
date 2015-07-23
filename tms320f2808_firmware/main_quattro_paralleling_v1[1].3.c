//#############################################################################
// FILE:   			main_quattro_paraleling_v1.1.c
// TITLE:  			main file of the quattro project for the received new control boards
// DESCRIPTION:		main file ho contents the main() and the other source
//					code and subroutines of the quattro project	
//	Parallel  v1.1  Paralleling phase. First is to re-organize the ADC routine into subroutines
//				    Second is to synchronize with the input voltage. We use (SOGI+FLL) to
//				    syncrhonize extracting the error from FLL and using it to decide the conecction point.
//				    We discover that we should avoid constants definition inside algorithms (i.e. _IQ(30)), do that in declaration area
//		      v1.2  We introduce a method to obtain the Phase angle for this syncronization part
//            v1.3  We introduce a method to obtain the amplitude of input voltage to finish the synchronization.
//
//
//AUTHORS:			YaoWei (19/6/09)
//#############################################################################
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++  For IQmath variables debbuging  ++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Select the global Q value to use:
#define	GLOBAL_Q	19		// Q1 to Q29
long  GlobalQ = GLOBAL_Q;	//This variable is used by the GEL functions to

//+++++++++++++ Include ++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "DSP281x_Device.h"       	// DSP281x Header include file
#include "DSP281x_Examples.h"     	// DSP281x Examples include file
#include "IQmathLib.h"				//IQmath header
#include "DSP281x_Spi_complet.h"    

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++ Declarations to include to run program ++++++++++++++++++++++++
//+++++++++++++ from internal Flash memory  +++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*extern unsigned int secureRamFuncs_loadstart;
extern unsigned int secureRamFuncs_loadend;
extern unsigned int secureRamFuncs_runstart;
*/

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++ 50Hz sine generation variables +++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Uint16 	countramp=0;			//Pointer for ramp generation of sinus reference

_iq25	frequency_iq=_IQ25(50.0);
_iq		amplitudeconstant_iq=_IQ(7.21758911); 
_iq		sin_out_iq=0;
_iq		sin_ampl_out_iq;			//Sinus real output
_iq		ampl_cnt_iq;				//Sinus amplitude constant

Uint16 	sinramp=0;				//Sinus ramp counter
Uint16	startramp=1;			//Flag that initiates sinus ramp
Uint16  count_amplitude=0;       //Amplitude caculator count

_iq		sinusamplitude_iq=0;	//For PDPINTA changing the reference voltage

_iq		sininput_iq[3]={0,0,0};
_iq		SampleTime_iq=_IQ30(0.00004);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++ Inverter control variables +++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Uint32 	hh,hh2=0;				// General variable used to spend time in board test
char 	ADC_en=1;				// Enable ADC converter

Uint16 	DCBusvolt=360;			// Voltage level for the DC bus. 360V for 220Veff, 370V for 230Veff

Uint16	sinusamplitude=220;		// Amplitude of output voltage sinus Veff

Uint16 	vdc_aux=0;	 			// Counter to ramp of DC bus voltage
Uint16 	DCBus_aux=0;			// Auxiliary variable

_iq		DCBusconstant_iq=_IQ(7.57);	//To translate DCbus volt value to internal value for compare3
_iq		DCBus_iq=0;

Uint16	Shut_down=0;			//Inverter disconnection (turnrs down to 0V the VO and DCbus
char	shortcircuit=0;			//For shorcircuit action if PDPINTA is activated
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++ ADC calibration variables  ++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
_iq		Adc_iq[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};    //To store all the ADC channels in iq format

Uint16	AdcVR15=0;				//Variable to read 1.5 Vreference
Uint16	AdcVR05=0;				//Variable to read 1.5 Vreference

Uint16 	ii,pp=0;				// Auxiliary variables
Uint16	auxADC=0;
char 	buffer_full=0;			//Flag to indicate if the buffers are full, (=0, initiates calibration)
Uint32 	mean05=0;				//Average calculation of 0.5V voltage reference
Uint32  mean15=0;				//Average calculation of 0.5V voltage reference
Uint16  sogi_reset_ramp=0;      //sogi_reset ramp count


_iq		mean15_iq=0;
_iq		mean05_iq=0;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++ PI control variables +++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
_iq 	VoOff_iq=_IQ(2048);				//Offset in Q19 to interact with ADC variables in  Q19

				/*** PI gains  ***/		//kp=0.05 ki=1800*0.00002
					
_iq 	kp_iq=_IQ(0.1);							//kp  PI gain for the output voltage loop
_iq 	kiT_iq=_IQ(350*0.00004);				//ki*T PI gain for the output voltage loop, (T/2 sampling period) (T=0.00004)
								//ki es la unica responsable de que llegue al regimen estacionario
								//hay que poner la minima ki para que regule
								//kp ha de ser baja para que minimice harmonicos en la zona sin carga

_iq 	y_pi_iq[2]={0,0};					//Actual sample: y_pi_iq[0]; previous sample:y_pi_iq[1]

_iq		ampl_fractional_iq=_IQ(0.05);
_iq		ampl_frac2_iq=0;

_iq		auxx[2]={0,0};
_iq 	auxx0_iq=0;
_iq 	auxx1_iq=0;
_iq 	auxx2_iq=0;
_iq 	auxx3_iq=0;
_iq 	auxx4_iq=0;
_iq 	auxx5_iq=0;
_iq 	auxx6_iq=0;
_iq 	auxx7_iq=0;
_iq 	auxx8_iq=0;
_iq 	auxx9_iq=0;
_iq 	auxx10_iq=0;
_iq 	auxx11_iq=0;
_iq 	auxx12_iq=0;
_iq 	auxx13_iq=0;
_iq 	auxx14_iq=0;
_iq 	auxx15_iq=0;
_iq 	auxx16_iq=0;
_iq 	auxx17_iq=0;
_iq 	auxx18_iq=0;
_iq 	auxx19_iq=0;

_iq 	auxx20_iq=0;
_iq 	auxx21_iq=0;
_iq 	auxx22_iq=0;
_iq 	auxx23_iq=0;


_iq 	auxx24_iq=0;
_iq 	auxx25_iq=0;
_iq 	auxx26_iq=0;
_iq 	auxx27_iq=0;
_iq 	auxx28_iq=0;

_iq		GP_iq=_IQ(4.5);              

_iq		GILvGVO_iq=_IQ(6.6659891);   
_iq		GILvGIO_iq=_IQ(0.5192375);    
_iq		GEvGIL_iq=_IQ(0.28595216);  
_iq		GEvGVO_iq=_IQ(1.906153965); 

_iq		rL_iq=_IQ(0.3);

_iq		GVH_iq=_IQ(1500);
_iq		MaxVH_iq=_IQ(1500);
_iq		MinVH_iq=_IQ(-1500);

_iq		Gainsat_iq=_IQ(0.005);				//Gainsat=T/0.001
_iq		MaxSatCurrent_iq=_IQ(10*0.018*1365);
_iq		MinSatCurrent_iq=_IQ(-10*0.018*1365);

_iq		Two_cnt_iq=_IQ30(1.999999999);
_iq		One_cnt_iq=_IQ30(1);
_iq     Quarter_cnt_iq=_IQ30(0.25);
_iq     Amplitude_cnt_iq[2]={0,0};


_iq		Ebusctn_iq=_IQ30(0.000271076);		//(1/3689) We chose a middle point between 3581(for 360V) and 3797(for 390V maximum)

Uint16	PWM_out=0;

_iq 	auxxx0_iq=0;
_iq 	auxxx1_iq=0;
_iq 	auxxx2_iq=0;
_iq 	auxxx3_iq=0;
_iq 	auxxx4_iq=0;
_iq 	auxxx5_iq=0;
_iq 	auxxx6_iq=0;
_iq 	auxxx7_iq=0;
_iq 	auxxx8_iq=0;
_iq 	auxxx9_iq=0;
_iq 	auxxx10_iq=0;
_iq 	auxxx11_iq=0;
_iq 	auxxx12_iq=0;



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++  General auxiliary variables ++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Uint16 outspi=0;			//Flag to output a valu to the DAC chip

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++  IQ variables      ++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
_iq		aux_iq=0;
_iq		Gain_cal_iq;
_iq		Offset_cal_iq;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++  IO curent sample abs and integer values  +++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Uint16 	shortcir=0;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++  Variables for FLL+SOGI  ++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

_iq xsogi_iq[3]={0,0,0};
_iq ysogi_iq[2]={0,0};
_iq x2sogi_iq[3]={0,0,0};
_iq y2sogi_iq[2]={0,0};
_iq yfll_iq[2]={_IQ(314.159265),_IQ(314.159265)};

_iq	Twoshi_iq=_IQ(1.4142135);
_iq T1_iq=_IQ30(0.00006);
_iq T2_iq=_IQ30(0.00002);
_iq TS_iq=_IQ(0.00004);
_iq sogigain_iq=_IQ30(0.023);

_iq SatsogiH=_IQ(30);
_iq SatsogiL=_IQ(-30);

_iq	Inv2pi_iq=_IQ30(0.159154943);			//(1/2pi)
_iq	Inv_iq=_IQ30(0.000100232);
_iq	Inv3_iq=_IQ30(0.02);		            //1/(GVO*GAD*50)	


_iq aux_err2_iq;
int	aux_value,value;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++ Subroutines definitions +++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ADC_calibration(void);
void Sinusgen(void);
void Rampgen(void);
void Internal_algo(void);
void FLLSOGI(void);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++ ISR function definitions ++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
interrupt void isr_adc(void);
interrupt void isr_pdpinta(void);

//*****************************************************************************
//*****************************************************************************
//***********  main routine ***************************************************
//*****************************************************************************
void main(void)
{
// Initialize System Control: PLL, WatchDog, enable Peripheral Clocks
   InitSysCtrl();

// Initialize GPAMUX, GPBMUX and GPFMUX
   InitGpio();

//----------------------------------------------------------------------------  
//----- Section secureRamFuncs contains user defined code that ---------------
//----- runs from CSM secured RAM  -------------------------------------------
/*   memcpy(	&secureRamFuncs_runstart,
			&secureRamFuncs_loadstart,
			&secureRamFuncs_loadend - &secureRamFuncs_loadstart);

   InitFlash();			// Initialize the FLASH (FILE: SysCtrl.c)

*/
//----------------------------------------------------------------------------
   DINT; 	// Disable CPU interrupts 

// Initialize PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.  
   InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt Service Routines (ISR). 
// This will populate the entire table, even if the interrupt is not used in this example.  This is useful for debug purposes.
   InitPieVectTable();
   
// Interrupts that are used in this example are re-mapped to
// ISR functions found within this file.  
   EALLOW; 		// This is needed to write to EALLOW protected registers
   PieVectTable.ADCINT = &isr_adc;
   PieVectTable.PDPINTA = &isr_pdpinta;
   EDIS;   		// This is needed to disable write to EALLOW protected registers

// Initialize EventManager
   InitEv(); 

// Initialize Port SPI
   InitSpi();	

// Initialize ADC
   InitAdc();  	

// Enable PIE group 1 interrupt 6 for ADCINT
   PieCtrlRegs.PIEIER1.all = M_INT6;

// Enable PIE group 1. Enable interrupt 1 inside this group for PDPINTA
   PieCtrlRegs.PIEIER1.all = M_INT6;
   PieCtrlRegs.PIEIER1.bit.INTx1 = 1;

// Disable PDPINTA high-z
 	EvaRegs.EVAIMRA.bit.PDPINTA = 0;


// Enable CPU INT1 for ADCINT
   IER |= M_INT1;

// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global real-time interrupt DBGM

//=============================================================================
//== DSP setup is ended =======================================================
//== Selecction of different Quattro board options ============================
//=============================================================================
   GpioDataRegs.GPBDAT.bit.GPIOB2 = 1;	//Enable inrush relay K2, NTCs(2x5ohms)	(=1), ByPass(=0) (IOS_REL_INRUSH)
   GpioDataRegs.GPBDAT.bit.GPIOB3 = 1;	//Enable charger, disc.(=1), conec.(=0) (IOS_CHG)
   GpioDataRegs.GPBDAT.bit.GPIOB4 = 1;	//Enable DC-DC mode, disc.(=1), conec.(=0) (IOS_INV)
   GpioDataRegs.GPBDAT.bit.GPIOB5 = 1;	//Enable output capacitor K4/C13, disc.(=1), conec.(=0) (IOS_REL_OUTCAP)
   GpioDataRegs.GPBDAT.bit.GPIOB6 = 1;	//Enable input relay K1-K5, disc.(=1), conec.(=0) (IOS_REL_INPUT)

   if (ADC_en==1) EvaRegs.GPTCONA.bit.T1TOADC = 2;
   else EvaRegs.GPTCONA.bit.T1TOADC = 0;
	
	ampl_cnt_iq=_IQmpyI32(amplitudeconstant_iq,sinusamplitude);
	ampl_fractional_iq=_IQmpy(ampl_cnt_iq,_IQ(0.05));

	DCBus_iq=_IQmpyI32(DCBusconstant_iq, DCBusvolt);
	DCBus_aux=_IQint(DCBus_iq);

//==================================================
//=== main loop  ===================================
//==================================================
   
  while(1)	 // main loop
   {

	//--------------------------------------------------------------
	//	When the buffer is full the calibration ADC algorithm executes
	//  Calculates Gain_cal and CalOffset
	//--------------------------------------------------------------
		if(buffer_full==1)
		{
				//To start a new calibration put 0 in this variable

					//mean15 and mean05 are a cumulative 4k samples of 1.5V and 0.5V references
					//Final recalculation is made on ADC subroutine
		
			mean15_iq=_IQdiv(_IQ7(mean15),_IQ7(4096));		//Obtain the mean values for 4k samples		
			mean05_iq=_IQdiv(_IQ8(mean05),_IQ8(4096));

			aux_iq=mean15_iq-mean05_iq;
			Offset_cal_iq=mean15_iq-_IQmpy(aux_iq,_IQ(1.5));  //Offset=Y15-(Y15-Y05)*1.5  
			Gain_cal_iq=_IQdiv(_IQ(1365),aux_iq);			  //Gain=(4095/3)/(Y15-Y05)

			buffer_full=2;					//To indicate that Calibration phase is over
		}

		if (buffer_full==2)
		{
			if (Shut_down==0)
			{
				EvaRegs.CMPR3=DCBus_aux;
				for (hh=0;hh<3000000;hh++);				//Wait time for DC-DC to achieve the stationary set point 
				GpioDataRegs.GPBDAT.bit.GPIOB4 =1;		//Enable DC-DC
				for (hh=0;hh<30000000;hh++);				//Wait time for DC-DC to achieve the stationary set point 
				buffer_full=3;
			}

			if (Shut_down==2)
			{
				EvaRegs.CMPR3=0;
				Shut_down=3;							//Shows the end of shut down process, we can disconnect system
				GpioDataRegs.GPBDAT.bit.GPIOB4=1;		//Disable DC-DC converter (IOS_INV)
				buffer_full=4;
			}
		}

 		if (outspi==1)
		{
			aux_err2_iq=auxxx0_iq+VoOff_iq;				//To see SOGI output voltage
			value = _IQint(aux_err2_iq);
			aux_value=(value|0x1000); 					//To show trough channel 0 of DAC
		 	SpiaRegs.SPITXBUF=aux_value; 				//To send to spi 

/*			aux_err2_iq=sin_ampl_out_iq+VoOff_iq;				//To see SOGI output voltage
			value = _IQint(aux_err2_iq);
			aux_value=(value|0x5000); 					//To show trough channel 0 of DAC
		 	SpiaRegs.SPITXBUF=aux_value; 				//To send to spi 
*/
	    	aux_err2_iq=ysogi_iq[0]+VoOff_iq;						//To see SOGI output voltage
			value = _IQint(aux_err2_iq);
			aux_value=(value|0x9000); 					//To show trough channel 0 of DAC
		 	SpiaRegs.SPITXBUF=aux_value; 

			aux_err2_iq=_IQmpyIQX(sininput_iq[0],30,GVH_iq,19);					//To see SOGI output voltage
			value = _IQint(aux_err2_iq);
			aux_value=(value|0xC000); 					//To show trough channel 0 of DAC
		 	SpiaRegs.SPITXBUF=aux_value; 

/*			aux_err2_iq=yfll_iq[0];					//To see SOGI output voltage
			value = _IQint(aux_err2_iq);
			aux_value=(value|0xC000); 					//To show trough channel 0 of DAC
		 	SpiaRegs.SPITXBUF=aux_value; 
*/			
			outspi=0;
	  	}
   }
} 

//*****************************************************************************
//***********  ISR Routines****************************************************
//*****************************************************************************
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// INT1.6 --> ADC Interruption when has finished to read all the channels
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
interrupt void isr_adc(void) 
{
    ADC_calibration();			//ADC calibration subroutine

	if (buffer_full==3)
	{
		FLLSOGI();	

		Sinusgen();				//Sinus generation in per unit

		Rampgen();				//Ramp generation with 20 steps		

		sin_ampl_out_iq=_IQmpyIQX(sin_out_iq,30,sinusamplitude_iq,GLOBAL_Q);

		Internal_algo();
	
		outspi=1;		//To send to SPI
	}


	EvaRegs.CMPR1 = 1500 + PWM_out;  			//The maximum bounds for PWM_out
	EvaRegs.CMPR2 = 1500 - PWM_out;  			//are between -1500 a 1500
								   				//EvaRegs.CMPR1 is for PWM 1 and 2 (Timer1)
								   				//EvaRegs.CMPR2 is for PWM 3 and 4 (Timer1)

	//-------------------------------------
   // Reinitialize for next ADC sequence
   //--------------------------------------
   AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;         // Reset SEQ1
   AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;       // Clear INT SEQ1 bit

   // To receive more interrupts from this PIE group, acknowledge this interrupt 
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
   //-------------------------------------
   // End of reinitilization
   //-------------------------------------
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ADC_calibration subroutine ++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void ADC_calibration(void)
{

   //Fills buffer with data at beginning for the calibration process
   if (buffer_full==0)
   {
       AdcVR15 = AdcRegs.ADCRESULT5 >>4;		//Voltage reference 1.5V
       AdcVR05 = AdcRegs.ADCRESULT6 >>4;		//Voltage reference 0.5V

	   hh2++;						//Counter to counter a specified number of sums
       mean15=mean15+AdcVR15;		//Accumulative addition of 1.5V voltage reference
       mean05=mean05+AdcVR05;		//Accumulative addition of 0.5V voltage reference
	   if (hh2==4096)				//When reach again 2k new samples
	    {
	        hh2=0;					//Clears counter	
		    buffer_full=1;			//Indicates that buffers full of data (this flag is linked to the main loop)
	    }
	}

			/*** Read and calibrate ****/ 

	if ((buffer_full==2)||(buffer_full==3))
	{
	   auxADC = AdcRegs.ADCRESULT0>>4;				//Output current Io (ADS_IAC)
	   Adc_iq[2] = _IQ(auxADC) - Offset_cal_iq;		//Offset is in Q19 format
	   Adc_iq[2] = _IQmpy(Adc_iq[2],Gain_cal_iq);	//Calibrate

	   auxADC = AdcRegs.ADCRESULT1>>4;				//Input current Iin, (ADS_IIN)			
	   Adc_iq[6] = _IQ(auxADC) - Offset_cal_iq;		//Offset is in Q19 format
	   Adc_iq[6] = _IQmpy(Adc_iq[6],Gain_cal_iq);		//Calibrate

	   auxADC = AdcRegs.ADCRESULT2>>4;				//Output voltage Vo, (ADS_UAC)
	   Adc_iq[0] = _IQ(auxADC) - Offset_cal_iq;		//Offset is in Q19 format
	   Adc_iq[0] = _IQmpy(Adc_iq[0],Gain_cal_iq);		//Calibrate

	   auxADC = AdcRegs.ADCRESULT3>>4;				//Input voltage Vin, (ADS_UIN)
	   Adc_iq[4] = _IQ(auxADC) - Offset_cal_iq;		//Offset is in Q19 format
	   Adc_iq[4] = _IQmpy(Adc_iq[4],Gain_cal_iq);		//Calibrate

	   auxADC = AdcRegs.ADCRESULT4>>4;				//DC bus voltage VDCbus, (ADS_UDC)
	   Adc_iq[1] = _IQ(auxADC) - Offset_cal_iq;		//Offset is in Q19 format
	   Adc_iq[1] = _IQmpy(Adc_iq[1],Gain_cal_iq);		//Calibrate

	   auxADC = AdcRegs.ADCRESULT7>>4;				//Inverter Hbridge current, IL (ACS_ICS) 
	   Adc_iq[9] = _IQ(auxADC) - Offset_cal_iq;		//Offset is in Q19 format
	   Adc_iq[9] = _IQmpy(Adc_iq[9],Gain_cal_iq);		//Calibrate

	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Sinus generation subroutine +++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Sinusgen(void)
{
	sininput_iq[0]=sininput_iq[1]+_IQ30mpyIQX(frequency_iq,25,SampleTime_iq,30);
    
    sininput_iq[2]=sininput_iq[1];

	sininput_iq[1]=sininput_iq[0];

   


	if (startramp==1)
	{
		if (sininput_iq[0]>One_cnt_iq)
		{
			sininput_iq[0]=sininput_iq[0]-One_cnt_iq;
	        sininput_iq[1]=sininput_iq[0];
		}
	}
	else
	{
		if (sogi_reset_ramp==1)
		{
			sininput_iq[0]=0;//_IQ30mpyIQX(ysogi_iq[0],19,Inv_iq,30);
	        sininput_iq[1]=sininput_iq[0];
			sogi_reset_ramp=0;
		}
	}
	sin_out_iq=_IQ30sinPU(sininput_iq[0]);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Ramp generation +++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Rampgen(void)
{
	//Generates a ramp by multiplicating a 1/20 fraction
	//It uses a counter and multiplication is bewteen an integer and a IQnumber

	if (startramp==1)							
	{
		sinramp++;
		if (sinramp==1250)
		{
			sinramp=0;
			countramp++;
			ampl_frac2_iq=_IQmpyI32(ampl_fractional_iq,countramp);	
			sinusamplitude_iq= ampl_frac2_iq;

			if (countramp==20) 
			{
				startramp=0;
		        GpioDataRegs.GPBDAT.bit.GPIOB2 = 0;	//Enable inrush relay K2, NTCs(2x5ohms)	(=1), ByPass(=0) (IOS_REL_INRUSH)
			}
		}
	}

	if (Shut_down==1)				//it takes Vo sinus amplitude down to 0V, can be removed at the end of the project
	{
		sinramp++;
		if (sinramp==1250)
		{
			sinramp=0;
			countramp--;
			ampl_frac2_iq=_IQmpyI32(ampl_fractional_iq,countramp);		//Sinus Ramp
			sinusamplitude_iq= ampl_frac2_iq;						//Store final value
			if (countramp==0) 
			{
				Shut_down=2;						//Now goes to shut_down the DCBus voltage
				buffer_full=2;						// it goes out of the PI algorithm
			}
		}
	}
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ Internal Algorithm ++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Internal_algo(void)
{
	asm (" setc OVM");       		//Overflow activated
	auxx0_iq=Adc_iq[0]-VoOff_iq;			//Vo-2048
	auxx1_iq=sin_ampl_out_iq-auxx0_iq;

	y_pi_iq[0]=y_pi_iq[1]+_IQmpy(kiT_iq,auxx1_iq)+auxx2_iq;	//y(k)=y(k-1)+ki*T*x(k)+Gsat*Sat(k)
		
	auxx3_iq=y_pi_iq[0]+_IQmpy(kp_iq,auxx1_iq);			//PI outpout

	auxx4_iq=_IQmpy(GILvGVO_iq,auxx3_iq);	//Multiply by GIL/GVO, must go to iq19 due to range +-15000

	auxx5_iq=Adc_iq[2]-VoOff_iq;			//Io-2048
	auxx6_iq=auxx4_iq+_IQmpy(GILvGIO_iq,auxx5_iq);				//Iref=PI*(GIL/GVO)+IO*GIL/GIO

	auxx7_iq=_IQsat(auxx6_iq, MaxSatCurrent_iq, MinSatCurrent_iq);

	auxx8_iq=auxx7_iq-auxx6_iq;						//Saturation limit for current reference

	auxx2_iq=_IQmpy(Gainsat_iq,auxx8_iq);				//Windup Gain

	auxx9_iq=Adc_iq[9]-VoOff_iq;			//IL-2048

	auxx10_iq=auxx7_iq-auxx9_iq;			//Ierr=Iref-IL

	auxx11_iq=_IQmpy(GP_iq,auxx10_iq);

	auxx12_iq=auxx11_iq+_IQmpy(rL_iq,auxx10_iq);

	auxx13_iq=_IQmpy(GEvGIL_iq,auxx12_iq);

	auxx14_iq=auxx13_iq+_IQmpy(GEvGVO_iq,auxx0_iq);
		
	auxx15_iq=Two_cnt_iq-_IQ30mpyIQX(Adc_iq[1],GLOBAL_Q,Ebusctn_iq,30);

	auxx16_iq=_IQ30mpy(auxx15_iq,Ebusctn_iq);

	auxx17_iq=_IQ30mpyIQX(auxx14_iq,GLOBAL_Q,auxx16_iq,30);

	auxx18_iq=_IQmpyIQX(auxx17_iq,30,GVH_iq,19);

	auxx19_iq=_IQsat(auxx18_iq, MaxVH_iq, MinVH_iq);	//Saturation for modulator

	PWM_out = _IQint(auxx19_iq);					// Modulation index. Extract interger part

	y_pi_iq[1]=y_pi_iq[0];
	auxx[1]=auxx[0];

	asm (" clrc OVM");
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ FLL+SOGI routine   ++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void FLLSOGI(void)
{
	asm (" setc OVM");       		//Overflow activated
	auxxx0_iq=VoOff_iq-Adc_iq[4];	//Vin voltage
									//FLL algo

	auxxx10_iq=ysogi_iq[0]-auxxx0_iq;						//VO-Vin
	auxxx10_iq=_IQsat(auxxx10_iq, SatsogiH, SatsogiL);
	auxxx11_iq=_IQ15mpyIQX(auxxx10_iq,19,y2sogi_iq[0],19);			//*qVo
	auxxx12_iq=_IQmpyIQX(auxxx11_iq,15,sogigain_iq,30);				//*0.1*1.41
	yfll_iq[0]=yfll_iq[1]+_IQmpy(auxxx12_iq,TS_iq);			//y(k)=y(k-1)+Ts*x(k)

									//SOGI algo
	auxxx2_iq=auxxx0_iq-ysogi_iq[0];
	auxxx3_iq=_IQmpy(auxxx2_iq,Twoshi_iq);		//2*Shi	= 2*0.707=1.414	
	auxxx4_iq=auxxx3_iq-y2sogi_iq[0];

   	xsogi_iq[0]=_IQ11mpyIQX(auxxx4_iq,19,yfll_iq[0],19);	  	//First Integrator
	auxxx5_iq=_IQmpyIQX(xsogi_iq[1],11,T1_iq,30);    	//(3*Ts/2)*u(k-1)
	auxxx6_iq=_IQmpyIQX(xsogi_iq[2],11,T2_iq,30);	  	//(Ts/2)*u(k-2)
	ysogi_iq[0]=ysogi_iq[1]+auxxx5_iq-auxxx6_iq;

	x2sogi_iq[0]=_IQ11mpyIQX(ysogi_iq[0],19,yfll_iq[0],19);	//Second Integrator	
	auxxx7_iq=_IQmpyIQX(x2sogi_iq[1],11,T1_iq,30);    	//(3*Ts/2)*u(k-1)
	auxxx8_iq=_IQmpyIQX(x2sogi_iq[2],11,T2_iq,30);	  	//(Ts/2)*u(k-2)
	y2sogi_iq[0]=y2sogi_iq[1]+auxxx7_iq-auxxx8_iq;

	if (startramp==0)
	{
		frequency_iq=_IQ25mpyIQX(yfll_iq[0],19,Inv2pi_iq,30);

		if (ysogi_iq[1]<0)
		{
			if (ysogi_iq[0]>0) 
			{
				sogi_reset_ramp=1;
			}
		} 
	}

// amplitude--------------------------------------

	if (startramp==0 && count_amplitude<=50)
	{
		if (sininput_iq[2]<Quarter_cnt_iq)
		{
			if (sininput_iq[0]>Quarter_cnt_iq) 
			{
			    
				 Amplitude_cnt_iq[0]= Amplitude_cnt_iq[1]+_IQtoIQ14(ysogi_iq[0]);
				 Amplitude_cnt_iq[1]= Amplitude_cnt_iq[0];
				count_amplitude++;
			}
   		}
   	}
	else if (startramp==0 && count_amplitude==51)
    {
        sinusamplitude_iq=_IQ19mpyIQX(Amplitude_cnt_iq[0],14,Inv3_iq,30);		
        count_amplitude=0;
		Amplitude_cnt_iq[1]=0;
	
    }

//-------------------------------------------------

	yfll_iq[1]=yfll_iq[0];
	
	ysogi_iq[1]=ysogi_iq[0];
	xsogi_iq[2]=xsogi_iq[1];
	xsogi_iq[1]=xsogi_iq[0];

	y2sogi_iq[1]=y2sogi_iq[0];
	x2sogi_iq[2]=x2sogi_iq[1];
	x2sogi_iq[1]=x2sogi_iq[0];

	asm (" clrc OVM");
}

//*****************************************************************************
//***********  ISR Routines****************************************************
//*****************************************************************************
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// INT1.1 --> PDPINTA Interruption for an Io overcurrent
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
interrupt void isr_pdpinta(void) 
{
	EvaRegs.CMPR1 = 1500 + 100; 
	EvaRegs.CMPR1 = 1500 - 100; 

	if (shortcircuit==0)
	{
		shortcircuit=1;										//Activate shorcircuit event
	}

	EvaRegs.EVAIFRA.bit.PDPINTA = 1;        //The EVAIFRA flag of PDPINTA interruption must be cleared by written a 1
	EvaRegs.COMCONA.bit.FCOMPOE = 1;		//Re-enabling all PWM thata are in high impedance 
   	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;	//Acknoledge PIE grup interruption
}




//#############################################################################
//=============================================================================
// Definitively, No more.
//=============================================================================
//#############################################################################



