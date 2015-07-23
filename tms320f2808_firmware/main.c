// AC/DC Converter
// Jordan Morris
// Nov. 7, 2013

// START

// Table of Contents

//  S0.1 	System Header Files Declarations

//  S1.1 	Function Defintions
//  S1.2 	Main Function
//  S1.2.1 	PLL,WatchDog,Clocks initialization
//  S1.2.2 	PIE initialization
//  S1.2.3 	Set GPIO as EPWM
//	S1.2.4 	Set GPIO as LEDS and switches
//	S1.2.5 	FLASH initialization
//	S1.2.6 	ePWM synchronization
//	S1.2.7 	ePWM initilization
//	S1.2.8 	ADC initialization
//	S1.2.9 	Interrupt Initilization Section

//	S2.0 	Main Control Run
//	S2.1 	PI Controller Algorithm
//	S2.2 	DQ Controller Algorithm
//  S2.3 	enable acdc igbts
//  S2.4 	protection function
//  S2.5 	ADC sampler function
//	S2.6 	ac dc gate driver function
//  S2.7 	RMS calculation
//  S2.8 	digital filter function
//  S2.9 	Proportional-Integral Block
//  S2.10 	Vd Correction Factor 
//  S2.11 	Vq correction Factor
//  S2.12 	Id correction factor
//	S2.13 	Iq correction factor
//	S2.14 	Vab-dq Transform
//  S2.15 	Iab-dq transform
//  S2.16 	Power Calculations
//	S2.17 	AC/DC reverse power flow
//	S2.18 	DC/DC gate drivers
//	S2.19 	Constant Voltage Charging Mode
//	S2.20 	Constant Current Charging Mode
//  S2.21 	Active Power Controller
//  S2.22 	Reactive Power Controller
// 	S2.23 	Mode Select
// 	S2.24 	DC/DC igbts ON
// 	S2.25 	DC/DC igbts OFF
//	S2.26	AC/DC variable reset
// 	S2.27	DC/DC variable reset
//	S2.28	Advanced Calculations
// 	S2.29	Total Harmonic Distortion Calculator
//	S2.30	Total demand distortion calculator
//	S2,31	Error Check
//	S2.32	DC Filter
//  S2,33	Battery Charge Mode
//  S2,34	Battery Discharge Mode 	


//===========================================================================
// S0.1 System Header Files Declarations
#include "dplib280x.h"
#include "dsp280x_compact.h"
#include "math.h"
#include "IQmathLib.h"
#include "variables.h"
//	Global IQ is 19
//---------------------------------------------------------------------------



//S1.1 Function Defintions


// These are system defined functions, needed for interrupt control
void InitSysCtrl(void);
void InitPieCtrl(void); // necessary to use EPWM, see TMS320F2808 Datasheet pg 55
void InitPieVectTable(void);
//---------------------------------------------------------------

// Interrupt
interrupt void control_run(void); // user defined interrupt
//---------------------------------------------------------------


////////////////////// User defined functions //////////////////////// 
void 	ADCsampling(void);		// user defined function
void 	dq_control(_iq nVdcRef , _iq nIqRef);
void 	acdc_gate_drivers(void);
void 	acdc_on(void);
void	acdc_off(void);
_iq		digital_filter(_iq nInput, _iq22 *x1 , _iq30 *x2 , _iq30 *x3);
_iq 	*ab_dq(_iq nAlpha , _iq nBeta , _iq theta);
_iq 	pi_controller(_iq kI , _iq kP , _iq input , _iq *Iold , _iq30 sTime);
_iq 	rms(_iq nInput , _iq *nInteg , _iq nDelayTerm[] , _iq *nCorrDelayTerm);
_iq 	*iab_dq(_iq nA , _iq nB , _iq nTheta , _iq nPhi);
_iq 	*vab_dq(_iq nA , _iq nB , _iq nQ , _iq *nTheta , _iq *pll_int);
_iq 	*power(void);
void 	reverse_power(void);
void 	dcdc_gate_drivers(void);
void 	cv_charging(_iq nRef);
void 	cc_charging(_iq nRef);
void 	cp_charging(_iq nPref);
_iq 	crp_charging(_iq nQref , _iq *reactive_int);
char 	mode_select(void);
void 	dcdc_on(void);
void 	dcdc_off(void);
void	acdc_variable_reset(void);
void	dcdc_variable_reset(void);
void	advanced_calcs(void);
char	overvoltage(void);
char 	overcurrent(void);
_iq		dc_filter(_iq nInput , _iq *x);
char	battery_mode(void);
void	battery_charge(void);
void	battery_discharge(void);
void	power_charge(void);


//S1.2 Main Function 
void main(void)
{

	int	j=0,k=0;


//  S1.2.1 PLL,WatchDog,Clocks initialization
	InitSysCtrl();
	DINT;									//Interrupt Forbiden 


//	S1.2.2 PIE initialization
	InitPieCtrl();							//Initialization of PIE controller memory 
	IER = 0x0000;	
	IFR = 0x0000;                           // Disable CPU interrupts and clear all CPU interrupt flags
	InitPieVectTable();						// Initialization of PIE interrupt lookup table 




//	S1.2.3 Set GPIO as EPWM
	EALLOW; 
    GpioCtrlRegs.GPAMUX1.bit.GPIO0		=0;	   	//sets GPIO0 to EPWM1A if bit is set to 1
	GpioCtrlRegs.GPADIR.bit.GPIO0		=1;	   
	GpioDataRegs.GPACLEAR.bit.GPIO0		=1;   

    GpioCtrlRegs.GPAMUX1.bit.GPIO1		=0;	   	//sets GPIO1 to EPWM1B if bit is set to 1
	GpioCtrlRegs.GPADIR.bit.GPIO1		=1;	   
	GpioDataRegs.GPACLEAR.bit.GPIO1		=1;    

    GpioCtrlRegs.GPAMUX1.bit.GPIO2		=0;	   	//sets GPIO2 to EPWM2A if bit is set to 1
	GpioCtrlRegs.GPADIR.bit.GPIO2		=1;	   
	GpioDataRegs.GPACLEAR.bit.GPIO2		=1;   	

    GpioCtrlRegs.GPAMUX1.bit.GPIO3		=0;	   	//sets GPIO3 to EPWM2B if bit is set to 1
	GpioCtrlRegs.GPADIR.bit.GPIO3		=1;	   
	GpioDataRegs.GPACLEAR.bit.GPIO3		=1;  

    GpioCtrlRegs.GPAMUX1.bit.GPIO4		=0;	   	//sets GPIO4 to EPW3A if bit is set to 1
	GpioCtrlRegs.GPADIR.bit.GPIO4		=1;	   
	GpioDataRegs.GPACLEAR.bit.GPIO4		=1;   	

    GpioCtrlRegs.GPAMUX1.bit.GPIO5		=0;	   	//sets GPIO5 to EPW3B if bit is set to 1
	GpioCtrlRegs.GPADIR.bit.GPIO5		=1;	   
	GpioDataRegs.GPACLEAR.bit.GPIO5		=1; 

	EDIS; 

//	S1.2.4 Set GPIO as LEDS and switches
	EALLOW;
		
	// LED1
	GpioCtrlRegs.GPAMUX2.bit.GPIO26		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO26		= 1; 
	GpioDataRegs.GPASET.bit.GPIO26		= 1;		

	// LED2
	GpioCtrlRegs.GPAMUX2.bit.GPIO24		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO24		= 1; 
	GpioDataRegs.GPASET.bit.GPIO24		= 1;	

	// LED3
	GpioCtrlRegs.GPAMUX1.bit.GPIO15		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO15		= 1; 
	GpioDataRegs.GPASET.bit.GPIO15		= 1;	

	// LED4
	GpioCtrlRegs.GPAMUX1.bit.GPIO12		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO12		= 1; 
	GpioDataRegs.GPASET.bit.GPIO12		= 1;

	// LED5
	GpioCtrlRegs.GPAMUX2.bit.GPIO29		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO29		= 1; 
	GpioDataRegs.GPASET.bit.GPIO29		= 1;	

	// LED6
	GpioCtrlRegs.GPAMUX2.bit.GPIO31		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO31		= 1;
	GpioDataRegs.GPASET.bit.GPIO31 		= 1;	


	// control switches
	// AC/DC ON/OFF Switch
	GpioCtrlRegs.GPAMUX1.bit.GPIO7		= 0; 	// configures as gpio pin
	GpioCtrlRegs.GPADIR.bit.GPIO7		= 0; 	// configures as input
	GpioDataRegs.GPASET.bit.GPIO7		= 0; 	// pin defaults to a low latch
	GpioCtrlRegs.GPAPUD.bit.GPIO7		= 1; 	// disable internal pullup resistors
	GpioCtrlRegs.GPAQSEL1.bit.GPIO7  	= 0x3;

	// DC/DC ON/OFF Switch
	GpioCtrlRegs.GPAMUX1.bit.GPIO9		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO9		= 0; 
	GpioDataRegs.GPASET.bit.GPIO9		= 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO9		= 1;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO9  	= 0x3;

	// Active Power Control ON/OFF Switch
	GpioCtrlRegs.GPAMUX1.bit.GPIO11		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO11		= 0; 
	GpioDataRegs.GPASET.bit.GPIO11		= 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO11		= 1;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO11  	= 0x3;

	// Reactive Power Control ON/OFF Switch
	GpioCtrlRegs.GPAMUX1.bit.GPIO13		= 0;
	GpioCtrlRegs.GPADIR.bit.GPIO13		= 0; 
	GpioDataRegs.GPASET.bit.GPIO13		= 0;
	GpioCtrlRegs.GPAPUD.bit.GPIO13		= 1;
	GpioCtrlRegs.GPAQSEL1.bit.GPIO13  	= 0x3;

	EDIS;




//	S1.2.5 FLASH initialization

#ifdef FLASH
// 	Copy time critical code and Flash setup code to RAM
// 	The  RamfuncsLoadStart, RamfuncsLoadEnd, and RamfuncsRunStart
// 	symbols are created by the linker. Refer to the linker files. 
	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
// 	Call Flash Initialization to setup flash waitstates
// 	This function must reside in RAM
	InitFlash();	// Call the flash wrapper init function
#endif


//	S1.2.6 ePWM synchronization
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;      //synchronize all the EPWMs, Peripheral Clock Control Register 0
	EDIS;


//	S1.2.7 ePWM initilization

	//  EPWM1 Initialization (IGBT1)
	// Time base Submodule initializations
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        // TBCLK=SYSCLKOUT=10ns if 100M
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;			
	EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;          // Shadow enabled
	EPwm1Regs.TBPRD = period;                       // T=2*TBPRD*TBCLK=2*2500*10ns=50us=20KHz
	EPwm1Regs.TBPHS.half.TBPHS = 0;                 // phase inactive
    EPwm1Regs.TBCTL.bit.SYNCOSEL =TB_CTR_ZERO;      // EPWM1 is the master bus, all other pwms will sync to 1
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;         // No phase difference for EPWM1
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;  // Up and down mode for counter register
   	EPwm1Regs.TBCTR = 0;	

	// Counter Compare Submodule initializations												// set time based register counter to zero
	EPwm1Regs.CMPA.half.CMPA = 0;		    		// Initialize CMPA=0
	EPwm1Regs.CMPB=0;								// Initialize CMPB=0
	EPwm1Regs.CMPCTL.bit.SHDWAMODE=TB_SHADOW;       // CPMA shadow mode	
	EPwm1Regs.CMPCTL.bit.LOADAMODE=CC_CTR_ZERO;		// Load on CTR = zero



	// Action Qualifier Submodule initializations
	EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;				// Output high when CMPA = counter when incrementing 
	EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;			// Output low when CMPA = counter when decrementing


	EPwm1Regs.DBCTL.bit.OUT_MODE = 0x3; 		    // s0=1,s1=1,s2=0,s3=0,s4=0,s5=0
	EPwm1Regs.DBCTL.bit.IN_MODE = 0x0;  			// see pg 52, ePWM reference guide
	EPwm1Regs.DBCTL.bit.POLSEL = 0x2;				// invert b module output       						
	EPwm1Regs.DBRED = db_delay; 				    // 2us rising edge delay
	EPwm1Regs.DBFED = db_delay;						// 2us falling edge delay

	EPwm1Regs.PCCTL.bit.CHPEN = 0;                  // Disable the PWM chopper

	EALLOW;
	EPwm1Regs.TZSEL.bit.OSHT1=1;                    // TZ1 is selected, a one shot trip source
	EPwm1Regs.TZEINT.bit.OST=1;                     // Enable interrupt when a trip event occurs
	EPwm1Regs.TZCTL.bit.TZA=TZ_FORCE_LO;            // Force the EMPW1A to 0 after trip event occurs
	EPwm1Regs.TZCLR.bit.INT=1;                      // Clear the trip-interrupt flag for this EPWM module
	EPwm1Regs.TZCLR.bit.OST=1;                      // Clear flag for one-shot trip latch
	EDIS;

	// EPWM2 Initialization (IGBT2)
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        
	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;
    EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;          
	EPwm2Regs.TBPRD = period;                       
	EPwm2Regs.TBPHS.half.TBPHS = 0;                 
	EPwm2Regs.TBCTL.bit.SYNCOSEL=TB_SYNC_IN;		// synchonize to epwm1
    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;         
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;  
	
	EPwm2Regs.CMPA.half.CMPA = 0;		    	
	EPwm2Regs.CMPB=0;								
	EPwm2Regs.CMPCTL.bit.SHDWAMODE=TB_SHADOW;       
	EPwm2Regs.CMPCTL.bit.LOADAMODE=CC_CTR_ZERO;		

	// Action Qualifier Submodule initializations
	EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;				// Output high when CMPA = counter when incrementing 
	EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;			// Output low when CMPA = counter when decrementing


	EPwm2Regs.DBCTL.bit.OUT_MODE = 0x3; 		    // s0=1,s1=1,s2=0,s3=0,s4=0,s5=0
	EPwm2Regs.DBCTL.bit.IN_MODE = 0x0;  			// see pg 52, ePWM reference guide
	EPwm2Regs.DBCTL.bit.POLSEL = 0x2;				// invert b module output       						
	EPwm2Regs.DBRED = db_delay; 				    // 2us rising edge delay
	EPwm2Regs.DBFED = db_delay;						// 2us falling edge delay	
	
	EPwm2Regs.PCCTL.bit.CHPEN = 0;                  // Disable the PWM chopper
	
	EALLOW;
	EPwm2Regs.TZSEL.bit.OSHT1=1;
	EPwm2Regs.TZEINT.bit.OST=1;
	EPwm2Regs.TZCTL.bit.TZA=TZ_FORCE_LO;
	EPwm2Regs.TZCLR.bit.INT=1;
	EPwm2Regs.TZCLR.bit.OST=1;
	EDIS;


	// EPWM3 Initialization (IGBT3)
	EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        
	EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;
    EPwm3Regs.TBCTL.bit.PRDLD = TB_SHADOW;          
	EPwm3Regs.TBPRD = period;                       
	EPwm3Regs.TBPHS.half.TBPHS = 0;                 
	EPwm3Regs.TBCTL.bit.SYNCOSEL=TB_SYNC_IN;		// synchonize to epwm1
    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;         
	EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;  
	
	EPwm3Regs.CMPA.half.CMPA = 0;		    	
	EPwm3Regs.CMPB=0;								
	EPwm3Regs.CMPCTL.bit.SHDWAMODE=TB_SHADOW;       
	EPwm3Regs.CMPCTL.bit.LOADAMODE=CC_CTR_ZERO;		

	// Action Qualifier Submodule initializations
	EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;				// Output high when CMPA = counter when incrementing 
	EPwm3Regs.AQCTLA.bit.CAD = AQ_SET;					// Output low when CMPA = counter when decrementing


	EPwm3Regs.DBCTL.bit.OUT_MODE = 0x3; 		    // s0=1,s1=1,s2=0,s3=0,s4=0,s5=0
	EPwm3Regs.DBCTL.bit.IN_MODE = 0x0;  			// see pg 52, ePWM reference guide
	EPwm3Regs.DBCTL.bit.POLSEL = 0x2;				// invert b module output       						
	EPwm3Regs.DBRED = db_delay; 				    // 2us rising edge delay
	EPwm3Regs.DBFED = db_delay;						// 2us falling edge delay						    // 2us rising edge delay, no falling edge delay	
	
	EPwm3Regs.PCCTL.bit.CHPEN = 0;                  // Disable the PWM chopper
	
	EALLOW;
	EPwm3Regs.TZSEL.bit.OSHT1=1;
	EPwm3Regs.TZEINT.bit.OST=1;
	EPwm3Regs.TZCTL.bit.TZA=TZ_FORCE_LO;
	EPwm3Regs.TZCLR.bit.INT=1;
	EPwm3Regs.TZCLR.bit.OST=1;
	EDIS;      	
	                                                         

//	S1.2.8 ADC initialization
		AdcRegs.ADCTRL3.bit.ADCBGRFDN = 0x3;	    // Power up bandgap/reference circuitry
		for(j=0;j<500;j++)                          // Delay before powering up rest of ADC,5ms
		{
	      for(k=0;k<1000;k++)
		  {		
			asm(" nop");
		  }
		}
		AdcRegs.ADCTRL3.bit.ADCPWDN = 1;		    	// Power up rest of ADC
		for(j=0;j<2000;j++)                         	// Delay after powering up ADC
		{
		  asm(" nop");
		}

		AdcRegs.ADCMAXCONV.all=15;						// 16 sampling channels
		AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x1;			// AC Voltage
		AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x1;
		AdcRegs.ADCCHSELSEQ1.bit.CONV02=0x1;
		AdcRegs.ADCCHSELSEQ1.bit.CONV03=0x2;			// DC Link Voltage
        AdcRegs.ADCCHSELSEQ2.bit.CONV04=0x2;            
        AdcRegs.ADCCHSELSEQ2.bit.CONV05=0x2;
		AdcRegs.ADCCHSELSEQ2.bit.CONV06=0x3;            // AC Current
		AdcRegs.ADCCHSELSEQ2.bit.CONV07=0x3;
		AdcRegs.ADCCHSELSEQ3.bit.CONV08=0x3;            
		AdcRegs.ADCCHSELSEQ3.bit.CONV09=0x3;			
		AdcRegs.ADCCHSELSEQ3.bit.CONV10=0x4;			// Battery Voltage
		AdcRegs.ADCCHSELSEQ3.bit.CONV11=0x4;
		AdcRegs.ADCCHSELSEQ4.bit.CONV12=0x4;			
		AdcRegs.ADCCHSELSEQ4.bit.CONV13=0x5;			// Battery Current
		AdcRegs.ADCCHSELSEQ4.bit.CONV14=0x5;
		AdcRegs.ADCCHSELSEQ4.bit.CONV15=0x5;

		AdcRegs.ADCTRL1.bit.CPS=0;	          //Core clock prescaler. The prescaler is applied to divided device peripheral clock				
		AdcRegs.ADCTRL3.bit.ADCCLKPS=1;	  	  // divide peripheral clock by 2			
		AdcRegs.ADCTRL1.bit.SEQ_CASC=1;				
		AdcRegs.ADCTRL3.bit.SMODE_SEL=0;      // sequential sampling mode selected      
		AdcRegs.ADCTRL1.bit.CONT_RUN = 1;	  // continuous conversion mode      
		AdcRegs.ADCTRL1.bit.ACQ_PS=5;		  // make a large aquisition window size	    
		AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;	  //		
		AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;														
		AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1=1;		





        EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;		// EPWM6 as the base clock for ADC
		EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV1;
		EPwm6Regs.TBCTL.bit.PRDLD = TB_SHADOW;			// set Immediate load
		EPwm6Regs.TBPRD = period;						// PWM frequency = 1 / period
		EPwm6Regs.TBPHS.all = 0;
		EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;

		EPwm6Regs.TBCTR = 0;
		EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
		EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;		
		EPwm6Regs.ETSEL.bit.SOCAEN  =  1;
		EPwm6Regs.ETSEL.bit.SOCASEL =  ET_CTRU_CMPA;	// Use CAU event as trigger 
		EPwm6Regs.CMPA.half.CMPA    = 1250;
		EPwm6Regs.CMPB    =  0;
		EPwm6Regs.CMPCTL.bit.SHDWAMODE=TB_SHADOW;       //采用影子寄存器	
	    EPwm6Regs.CMPCTL.bit.LOADAMODE=CC_CTR_ZERO;		//在CTR=PRD时装载

		// Event trigger submodule initialization
        EPwm6Regs.ETPS.bit.SOCAPRD  = 1;        		// Generate pulse on 1st event 
	    EPwm6Regs.ETSEL.bit.SOCAEN  =  1;				// enable pulse on generated event
	    EPwm6Regs.ETSEL.bit.SOCASEL =  ET_CTRU_CMPA;	// Use CAU event as trigger when increasing, ET_CTRU_CMPA = 0x4




//	S1.2.9 Interrupt Initilization Section

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// Interrupt Init section - System Level and Peripheral Level
// (best to run this section last, once all other initialization is done)
// Note: Make sure same selection is made in PWM-Eval-ISR.ASM
//===========================================================================
	IER |= (M_INT2 | M_INT3);                          // Enable CPU INT3 connected to EPWM1-6 INTs:
//---------------------------------------------------------------------
	EALLOW;
	PieVectTable.EPWM1_INT = &control_run;	           // Map Interrupt to control_run
	EDIS;

    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;	               // EPWM1 INT
	PieCtrlRegs.PIEIER2.bit.INTx1 = 1;                 // EPWM1 TZINT

// EPWM1 level event trigger submodule commands
// ET_CTRU_CMPB=0x6
	EPwm1Regs.ETSEL.bit.INTSEL = ET_CTRU_CMPB;	       // interrupt when TBCTR = CMPB and TBCTR is increasing
	EPwm1Regs.ETSEL.bit.INTEN = TB_ENABLE;			   // Enable INT
	EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;	               // Generate INT on every event


//---------------------------------------------------------------------
// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM


	dq_ramp = _IQmpy(dq_vdc_ref,_IQ(0.5)) + 20;
	cc_ramp = _IQ(0);
	ADCsampling();
	oc_voltage = vbatt_meas;

//---------------------------------------------------------------
//	mainloop 
//---------------------------------------------------------------  
	for(;;)
	{
		asm("  NOP"); // this is a line of inline assembly
	}

}	






//	S2.0 Main Control Run
interrupt void control_run(void)
{

	current_mode = 0;
	for (i=0 ; i < 10 ; i++)
	{
		mode[i] = mode_select();
		current_mode += mode[i];
	}

	if ((mode[0] * 10) == current_mode)
	{
		prev_mode = mode[0];	
	}

	if	(overvoltage() == 1){prev_mode = 0x00;}
	if	(fault_count > 10) 
	{
		prev_mode = 0x00;
		LED5ON = 1;
	}


	switch(prev_state | prev_mode)
	{
		// AC/DC turn on
		case (0x01):
		fault_count++;
		acdc_on();
		dcdc_off();
		advanced_calcs();
		ADCsampling();
		dq_control(dq_ramp,_IQ(0));
		acdc_gate_drivers();
		prev_state = 0x10;
		break;

		// AC/DC on
		case(0x11):
		advanced_calcs();
		ADCsampling();
		dq_control(dq_ramp,_IQ(0));
		acdc_gate_drivers();
		if (dq_ramp < dq_vdc_ref){ dq_ramp += _IQ(0.0005);}
		prev_state = 0x10;
		led_indicators(0x1);
		break;

		// DC/DC turn on to standard charge charge (0x13)
		case(0x13):
		dcdc_on();
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref,_IQ(0));
		acdc_gate_drivers();
		prev_state = 0x30;
		break;

		// reactive control (0x15)
		case(0x15):
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref,crp_charging(reactive_ref , &Q_int));
		acdc_gate_drivers();
		prev_state = 0x10;
		led_indicators(0x5);
		break;

		// DC/DC turn on to standard charging with reactive control
		case(0x17):
		dcdc_on();
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref, crp_charging(reactive_ref , &Q_int));
		acdc_gate_drivers();
		prev_state = 0x30;
		break;

		// DC/DC turn on to power charging
		case(0x19):
		dcdc_on();
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref,_IQ(0));
		acdc_gate_drivers();
		prev_state = 0x90;
		break;

		// DC/DC turn on to power charging with reactive control
		case(0x1D):
		dcdc_on();
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref , crp_charging(reactive_ref , &Q_int));
		acdc_gate_drivers();
		prev_state = 0x90;
		break;

		// DC/DC off from standard charging
		case(0x31):
		dcdc_off();
		dcdc_variable_reset();
		prev_state = 0x10;
		break;

		// standard charging
		case(0x33):
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref,_IQ(0));
		cc_charging(cc_ref);
		acdc_gate_drivers();
		dcdc_gate_drivers();
		prev_state = 0x30;
		led_indicators(0x3);
		break;

		// DC/DC turn off from standard charging and reactive control
		case(0x35):
		dcdc_off();
		dcdc_variable_reset();
		prev_state = 0x10;
		break;

		// standard charging and reactive control
		case(0x37):
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref , crp_charging(reactive_ref , &Q_int));
		cc_charging(cc_ref);
		acdc_gate_drivers();
		dcdc_gate_drivers();
		prev_state = 0x30;
		led_indicators(0x7);
		break;

		// switch from power charging to standard charging
		case(0x39):
		prev_state = 0x90;
		break;

		// switch from standard charging with reactive control to power charging with reactive control
		case(0x3D):
		prev_state = 0x90;
		break;

		// DC/DC off from power charging
		case(0x91):
		dcdc_off();
		dcdc_variable_reset();
		prev_state = 0x10;
		break;

		// switch from power charging to standard charging
		case(0x93):
		prev_state = 0x30;
		break;

		// DC/DC off from power charging with reactive control
		case(0x95):
		dcdc_off();
		dcdc_variable_reset();
		prev_state = 0x10;
		break;

		// switch from power charging with reactive control to standard charging with reactive control
		case(0x97):
		prev_state = 0x30;
		break;

		// power charging
		case(0x99):
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref , _IQ(0));
		cp_charging(power_ref);
		acdc_gate_drivers();
		dcdc_gate_drivers();
		prev_state = 0x90;
		led_indicators(0x9);
		break;

		// power charging with reactive control
		case(0x9D):
		advanced_calcs();
		ADCsampling();
		dq_control(dq_vdc_ref , crp_charging(reactive_ref , &Q_int));
		cp_charging(power_ref);
		acdc_gate_drivers();
		dcdc_gate_drivers();
		prev_state = 0x90;
		led_indicators(0xD);
		break;

		default:
		acdc_variable_reset();
		acdc_off();
		dcdc_off();
		prev_state = 0x00;
		led_indicators(0x0);
		break;

	}


	//clear interrupt flag and return	
	EPwm1Regs.ETCLR.bit.INT=1;				  // clear interrupt flag			
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;   // Acknowledge interrupt to PIE
	return;	

}


//	S2.1 PI Controller Algorithm
// DELETED TO FREE UP SPACE


//	S2.2 DQ Controller Algorithm
void dq_control(_iq nVdcRef , _iq nIqRef)
{
	asm(" setc OVM");

	// Vd , Vq , Id , Iq calculations
	dq_result = vab_dq(vac_meas , vac_delay[dcounter] , dq_vq , &theta , &dq_pll_int);
	dq_vd = *dq_result;
	dq_vq = *(dq_result + 1);

	dq_result = iab_dq(iac_meas , iac_delay[dcounter] , theta , phi);
	dq_id = *dq_result;
	dq_iq = *(dq_result + 1);

	//////////////////////////////// DQ control module///////////////////////////////////
	
	// Vdc PI Controller
	dq_vdc_error = nVdcRef - vdc_meas;
	dq_vdc_pi = pi_controller(_IQ(3.7),_IQ(0.37),dq_vdc_error, &dq_vdc_int , Ts); //3.7 0.37

	// Id PI Controller
	dq_id_error = dq_vdc_pi - dq_id;
	dq_id_pi = pi_controller(_IQ(200),_IQ(1),dq_id_error,&dq_id_int, Ts); //200 , 20

	// Iq PI Controller
	dq_iq_error = nIqRef - dq_iq;
	dq_iq_pi = pi_controller(_IQ(80),_IQ(4),dq_iq_error, &dq_iq_int , Ts); //50 , 5
	//dq_iq_pi = _IQsat(dq_iq_pi,_IQ(500),_IQ(-500));

	// Scale Id for DQ to AB transform
	dq_id_corr = dq_id_pi + dq_vd + _IQmpy(pi2fL,dq_iq_error) - _IQmpy(dq_res,dq_id_error);
	if(vdc_meas < 1){vdc_meas = 1;} // to eliminate the div by 0 possibility
	dq_id_corr_scale = _IQdiv(dq_id_corr,vdc_meas);

	// Scale Iq for DQ to AB transform
	dq_iq_corr = dq_iq_pi - _IQmpy(pi2fL,dq_id_error) - _IQmpy(dq_res,dq_iq_error);
	dq_iq_corr_scale = _IQdiv(dq_iq_corr,vdc_meas);

	// calculate v_controller

	v_cont_acdc = _IQmpy(dq_id_corr_scale,_IQcos(theta)) - _IQmpy(dq_iq_corr_scale,_IQsin(theta));
	v_cont_acdc = _IQsat(v_cont_acdc,_IQ(0.75),_IQ(-0.75));

	asm(" clrc OVM");
	return;
}





// S2.3 enable ePWM output function
void acdc_on(void)
{                                             
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0	= 1;		//EPWM1A
	GpioCtrlRegs.GPAMUX1.bit.GPIO1	= 1;		//EPWM1B
	GpioCtrlRegs.GPAMUX1.bit.GPIO2	= 1;		//EPWM2A
	GpioCtrlRegs.GPAMUX1.bit.GPIO3	= 1;		//EPWM2B
	EDIS;

	return;
}


// S2.4 AC/DC OFF
void acdc_off(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;

	GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;
	EDIS;

	return;
}

// S2.5 ADC sampler function
// Samples ADC, calculates filtered values, rms values and power values on current iteration
void ADCsampling(void)
{
	long int RESULT0=0,RESULT1=0,RESULT2=0,RESULT3=0,RESULT4=0;

	// Sample Vac channels
	RESULT0=AdcRegs.ADCRESULT0>>4;  
	RESULT0+=AdcRegs.ADCRESULT1>>4;
	RESULT0+=AdcRegs.ADCRESULT2>>4;
	RESULT0=RESULT0/3;

	// Sample Vdc channels
	RESULT1=AdcRegs.ADCRESULT3>>4; 
    RESULT1+=AdcRegs.ADCRESULT4>>4;
	RESULT1+=AdcRegs.ADCRESULT5>>4;
	RESULT1=RESULT1/3;

	// Sample Iac channels
	RESULT2=AdcRegs.ADCRESULT6>>4; 
	RESULT2+=AdcRegs.ADCRESULT7>>4;
	RESULT2+=AdcRegs.ADCRESULT8>>4;
	RESULT2+=AdcRegs.ADCRESULT9>>4;
	RESULT2=RESULT2/4;

	// Sample Vbatt channels
	RESULT3=AdcRegs.ADCRESULT10>>4; 
    RESULT3+=AdcRegs.ADCRESULT11>>4;
	RESULT3+=AdcRegs.ADCRESULT12>>4;
	RESULT3=RESULT3/3;

	// Sample Ibatt channels
	RESULT4=AdcRegs.ADCRESULT13>>4; 
    RESULT4+=AdcRegs.ADCRESULT14>>4;
	RESULT4+=AdcRegs.ADCRESULT15>>4;
	RESULT4=RESULT4/3;

	// Measure and calculate Vac
	ADC_base_iq[0] = 4096 - RESULT0;
	ADC_out_iq[0]=_IQmpyIQX(_IQ18(ADC_base_iq[0]),18,ADC_fk_iq[0],19);		// Vac
	ADC_out_iq[0]+=_IQ(-210.184);
	ADC_out_iq[0] = _IQmpy(ADC_out_iq[0],ADC_res_corr[0]);  
	vac_meas = ADC_out_iq[0];
	vac_delay[dcounter] = vac_meas;

	// Measure and calculate Vdc
	ADC_base_iq[1] = RESULT1; // _IQmpy(RESULT1,ADC_res_corr[1]);
	ADC_out_iq[1]=_IQmpyIQX(_IQ18(ADC_base_iq[1]),18,ADC_fk_iq[1],19);		// Vdc
	ADC_out_iq[1]+=_IQ(0);     
	ADC_out_iq[1] = _IQmpy(ADC_out_iq[1],ADC_res_corr[1]);
	vdc_meas = ADC_out_iq[1];

	// Measure and calculate Iac
	ADC_base_iq[2] = 4096 - RESULT2;
    ADC_out_iq[2]=_IQmpyIQX(_IQ18(ADC_base_iq[2]),18,ADC_fk_iq[2],19);		//Iac
	ADC_out_iq[2]+=_IQ(-30.15);
	ADC_out_iq[2] = _IQmpy(ADC_out_iq[2],ADC_res_corr[2]);
	iac_meas = ADC_out_iq[2];
	iac_delay[dcounter] = iac_meas;

	// Measure and calculate Vbatt
	ADC_base_iq[3] = RESULT3; // _IQmpy(RESULT1,ADC_res_corr[1]);
	ADC_out_iq[3]=_IQmpyIQX(_IQ18(ADC_base_iq[3]),18,ADC_fk_iq[3],19);		// Vbatt
	ADC_out_iq[3]+=_IQ(0);     
	ADC_out_iq[3] = _IQmpy(ADC_out_iq[3],ADC_res_corr[3]);
	vbatt_meas = ADC_out_iq[3];

	// Measure and calculate Ibatt
	ADC_base_iq[4] = 4096 - RESULT4;
    ADC_out_iq[4]=_IQmpyIQX(_IQ18(ADC_base_iq[4]),18,ADC_fk_iq[4],19);		//Ibatt
	ADC_out_iq[4]+=_IQ(-30);
	ADC_out_iq[4] = _IQmpy(ADC_out_iq[4],ADC_res_corr[4]);
	ibatt_meas = ADC_out_iq[4];

	// increment delay counters for AB-DQ transform
	dcounter += 1;
	if (dcounter >= 84) {dcounter = 0;}

	return;
}


//	S2.6 ac/dc gate driver function
void acdc_gate_drivers(void)
{
	asm(" setc OVM");

	igbt_control_pos = _IQmpyI32int(v_cont_acdc,half_period) + half_period;
	igbt_control_neg = _IQmpyI32int(v_cont_acdc,(half_period*-1)) + half_period;

	EPwm1Regs.CMPA.half.CMPA = igbt_control_pos;		// Setting comparison value for 1A
	EPwm2Regs.CMPA.half.CMPA = igbt_control_neg;		// Setting comparison value for 2A

	asm(" clrc OVM");
	return;
}


// S2.7 RMS calculation 
// (only works for 64PP , need to change iq types later
_iq rms(_iq nInput , _iq16 *nInteg , _iq16 nDelayTerm[] , _iq16 *nCorrDelayTerm)
{
	_iq rms_result = _IQ(0);
	_iq16 rms_result16 = _IQ16(0);
	_iq16 in_square = _IQ16(0);
	_iq6 corr = _IQ16(0);
	

	in_square = _IQ16mpyIQX(nInput , 19 , nInput , 19); // sqaure the input value
	*nInteg = _IQ16mpyIQX(in_square , 16 , _IQ(0.0004) , 19) + *nInteg; // Integrate squared input

	
	// calculate correction factor
	// v_corr_delay is in_square value from previous iteration, it is updated at the end of function
	corr = _IQ16mpyIQX(in_square , 16 , K2 , 30) - _IQ16mpyIQX(*nCorrDelayTerm , 16 , K1 , 30);
	
	// add correction factor to rms calculation (see matlab schematic for details)
	rms_result16 = corr + _IQ16mpy(*nInteg - nDelayTerm[rms_data_counter] , _IQ16(60));
	// saturate to avoid negative values and set take square root
	rms_result16 = _IQ16sqrt(_IQsat(rms_result16,_IQ16(32768),_IQ16(0)));
	rms_result = _IQmpyIQX(16,rms_result16,19,_IQ(1));

	// update in_square delay value
	*nCorrDelayTerm = in_square;

	// calculate and update delay values
	nDelayTerm[rms_data_counter] = *nInteg;

	// return result
	return rms_result;
}


// S2.8 digital filter function
_iq	digital_filter(_iq nInput , _iq22 *x1 , _iq30 *x2 , _iq30 *x3)
{
	_iq filter_result = _IQ(0);

	_iq22 x1next = _IQ(0);
	_iq30 x2next = _IQ(0);
	_iq30 x3next = _IQ(0);
	_iq22 a1 = _IQ(0);
	_iq30 a2 = _IQ(0);
	_iq30 a3 = _IQ(0);
	_iq c = _IQ(0);

	// calculate A matrix outputs
	a1 = 	  _IQ22mpyIQX(a11,29,*x1,22);
	a1 = a1 + _IQ22mpyIQX(a12,23,*x2,30);
	a1 = a1 + _IQ22mpyIQX(a13,14,*x3,30);
	a2 =      _IQ30mpyIQX(a21,30,*x1,22); 
	a2 = a2 + _IQ30mpyIQX(a22,29,*x2,30);
	a2 = a2 + _IQ30mpyIQX(a23,29,*x3,30);
	a3 =      _IQ30mpyIQX(a31,30,*x1,22);
	a3 = a3 + _IQ30mpyIQX(a32,30,*x2,30);
	a3 = a3 + _IQ30mpyIQX(a33,29,*x3,30);


	// calculate x[n+1] values
	x1next = _IQ22mpyIQX(nInput,19,b1,29) + a1;
	x2next = _IQ30mpyIQX(nInput,19,b2,30) + a2;
	x3next = _IQ30mpyIQX(nInput,19,b3,30) + a3;
	
	// calculate C matrix output
	c =     _IQmpyIQX(c1,30,*x1,22);
	c = c + _IQmpyIQX(c2,23,*x2,30);
	c = c + _IQmpyIQX(c3,15,*x3,30);
	
	// calculate filter output
	filter_result = c + _IQmpyIQX(nInput,19,d,30);

	// update x[n+1] matrix to x[n] matrix for use in next iteration
	*x1 = x1next;
	*x2 = x2next;
	*x3 = x3next;

	return filter_result;

}




// S2.9 Proportional-Integral Block
_iq pi_controller(_iq kI , _iq kP , _iq input , _iq *Iold , _iq30 sTime)
{
	_iq result = _IQ(0);
	_iq kiTs = _IQmpyIQX(kI , 19 , sTime , 30);
		
	*Iold = _IQmpy(kiTs,input) + *Iold;   					// integral term
	result = *Iold + _IQmpy(kP,input);	// proportional integral term
	return result;
}



// S2.10 Vd Correction Factor                                                                                        
// DELETED TO FREE UP SPACE

// S2.11 Vq correction Factor
// DELETED TO FREE UP SPACE

// S2.12 Id correction factor
// DELETED TO FREE UP SPACE

//	S2.13 Iq correction factor
// DELETED TO FREE UP SPACE


//	S2.14 Vab-dq Transform
_iq *vab_dq(_iq nA , _iq nB , _iq nQ , _iq *nTheta , _iq *pll_int)
{
	_iq pll_error = _IQ(0);
	_iq pll_pi = _IQ(0);

	_iq vdTemp = _IQ(0);
	_iq vqTemp = _IQ(0);

	static _iq nDQ[2] = {_IQ(0),_IQ(0)};

	// first calculate theta from pll	
	pll_error = nQ - vq_ref;
	pll_pi = pi_controller(_IQ(500),_IQ(10),pll_error, pll_int , Ts); // ki, kp
	*nTheta = pi_controller(_IQ(1),_IQ(0),pll_pi,nTheta , Ts);
	if (*nTheta >= pi2) {*nTheta -= pi2;}


	vdTemp = _IQmpy(nA,_IQcos(*nTheta)) + _IQmpy(nB,_IQsin(*nTheta));
	vqTemp = _IQmpy(nB,_IQcos(*nTheta)) - _IQmpy(nA,_IQsin(*nTheta));


	nDQ[0] = vdTemp;
	nDQ[1] = vqTemp;

	
	return nDQ;	
}

// S2.15 Iab-dq transform
_iq *iab_dq(_iq nA , _iq nB , _iq nTheta , _iq nPhi)
{
	_iq idTemp = _IQ(0);
	_iq iqTemp = _IQ(0);
	static _iq nDQ[2] = {_IQ(0),_IQ(0)};
	
	// calculate Id
	idTemp = _IQmpy(nA,_IQcos(nTheta)) + _IQmpy(nB,_IQsin(nTheta));

	// calculate Iq
	iqTemp = _IQmpy(nB,_IQcos(nTheta)) - _IQmpy(nA,_IQsin(nTheta));

	nDQ[0] = idTemp;
	nDQ[1] = iqTemp;
	
	return nDQ;
}


// S2.16 Power Calculations
_iq *power(void)
{
	static _iq power_result[3];

	_iq temp1 = _IQ(0);
	_iq temp2 = _IQ(0);
	_iq P = _IQ(0);
	_iq Q = _IQ(0);
	_iq angle = _IQ(0);

	// calculate real power
	temp1 = _IQmpy(dq_vd,dq_id) + _IQmpy(dq_vq,dq_iq);
	P = _IQmpy(temp1,_IQ(0.5));

	// calculate reactive power
	temp2 = _IQmpy(dq_vq,dq_id) - _IQmpy(dq_vd,dq_iq);
	Q = _IQmpy(temp2,_IQ(0.5));

	// calculate power factor angle phi
	if (P != 0) {angle = _IQatan2(Q,P);} // need to verify that this outputs the correct value
	else if (P == 0 & Q != 0) {angle = _IQ(1.570796327);}
	else angle = _IQ(0);

	// compile results into return array
	power_result[0] = P;
	power_result[1] = Q;
	power_result[2] = angle; // phi

	return power_result;
}


////////////////////DC/DC Controllers//////////////////////////

//	S2.18 DC/DC gate drivers
void dcdc_gate_drivers(void)
{
	asm(" setc OVM");
	igbt_dcdc = _IQmpyI32int(v_cont_dcdc,half_period) + half_period;
	EPwm3Regs.CMPA.half.CMPA = igbt_dcdc;	
	asm(" clrc OVM");
	return;		
}

//	S2.19 Constant Voltage Charging Mode
void cv_charging(_iq nRef)
{
	cv_error = nRef - vbatt_meas;  // calculate vbatt error
	cv_pi = pi_controller(_IQ(1),_IQ(0.001),cv_error, &cv_int , Ts); // ki, kp
	v_cont_dcdc = _IQsat(cv_pi,_IQ(0.8),_IQ(-0.8));
	return;
}

//	S2.20 Constant Current Charging Mode
void cc_charging(_iq nRef)
{
	cc_error = nRef - ibatt_meas;  // calculate vbatt error
	cc_pi = pi_controller(_IQ(1),_IQ(0.001),cc_error, &cc_int , Ts); // ki, kp
	v_cont_dcdc = _IQsat(cc_pi,_IQ(0.8),_IQ(-0.8));
	return;
}

// S2.21 Active Power Controller
void cp_charging(_iq nPref)
{
	cp_error = nPref - real_power;  // calculate vbatt error
	cp_pi = pi_controller(_IQ(0.05),_IQ(0.01),cp_error, &cp_int , Ts); // ki, kp
	cc_charging(cp_pi);
	return;
}

// S2.22 Reactive Power Controller
_iq crp_charging(_iq nQref , _iq *reactive_int)
{
	_iq q_error;
	_iq	iq_error;
	_iq vdref;
	_iq iqref;

	vdref = _IQmpy(_IQ(0.5),_IQsat(dq_vd,_IQ(4000),_IQ(1))); // to avoid divide by zero 
	q_error = _IQmpy(_IQ(-1),nQref - reactive_power);
	iq_error = _IQdiv(q_error,vdref);
	iqref = pi_controller(_IQ(5),_IQ(0.07),iq_error, reactive_int , Ts);

	return iqref;
}

// S2.23 Mode Select
char mode_select(void)
{
	char state;
	state = (Q_SWITCH << 3) | (P_SWITCH << 2) | (DCDC_SWITCH << 1) | ACDC_SWITCH;
	return state;
}

// S2.24 DC/DC ON
void dcdc_on(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;
	EDIS;

	return;
}

// S2.25 DC/DC OFF
void dcdc_off(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;

	GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO5 = 1;
	EDIS;

	return;
}

//	S2.26 AC/DC variable reset
void acdc_variable_reset(void)
{
	char i;

	dq_ramp = _IQmpy(dq_vdc_ref,_IQ(0.5)) + 20;

	rms_cycle_counter 	= 0; // to count to 16
 	rms_data_counter 	= 0; // to count to 21

// rms calc integrator outputs
 	vrms_int_output 	= _IQ16(0);
	irms_int_output 	= _IQ16(0);
	ifrms_int_output 	= _IQ16(0);

// correction delay values
	vrms_corr_delay 	= _IQ16(0);
 	irms_corr_delay 	= _IQ16(0);
	ifrms_corr_delay 	= _IQ16(0);
	
	i_x1 				= _IQ23(0);
	i_x2 				= _IQ30(0);
	i_x3 				= _IQ30(0);

	dq_pll_int 			= _IQ(0);
	dq_vdc_int 			= _IQ(0);
	dq_id_int 			= _IQ(0);
	dq_iq_int 			= _IQ(0);

	Q_int 				= _IQ(0);

	for (i = 0 ; i < 22 ; i++)
	{
		vrms_delay[i] 	= 0;
		irms_delay[i] 	= 0;
		ifrms_delay[i] 	= 0;
	}


	for (i = 0 ; i < 85 ; i++)
	{
		vac_delay[i] 	= 0;
		iac_delay[i] 	= 0;
		iacf_delay[i] 	= 0;
	}

	dcdc_variable_reset();

	return;
}

// S2.27 dcdc variable reset
void dcdc_variable_reset(void)
{
	cc_ramp 			= _IQ(0);
	cc_error 			= _IQ(0);
	cc_int 				= _IQ(0);
	cc_pi 				= _IQ(0);	

	cv_error 			= _IQ(0);
	cv_int 				= _IQ(0);
	cv_pi 				= _IQ(0);
	cv_ramp 			= _IQ(0);

	cp_pi 				= _IQ(0);
	cp_int 				= _IQ(0);
	cp_error 			= _IQ(0);
	cp_ramp				= _IQ(0);

	return;
}

// S2.28 advanced calculations
void advanced_calcs(void)
{

	// update counters , calculate filtered voltages and currents, rms, peak and thd values

	iacf = digital_filter(iac_meas , &i_x1 , &i_x2 , &i_x3);
	iacf_delay[dcounter] = iacf;

	// call rms functions
	rms_cycle_counter += 1;
	if (rms_cycle_counter >= 16) 
	{
		// vrms must be called before irms
		vac_rms = rms(vac_meas , &vrms_int_output , vrms_delay , &vrms_corr_delay);
		iac_rms = rms(iac_meas , &irms_int_output , irms_delay , &irms_corr_delay);
		iacf_rms = rms(iacf , &ifrms_int_output , ifrms_delay , &ifrms_corr_delay);
		rms_cycle_counter = 0;
		rms_data_counter += 1;
		if (rms_data_counter >= 21) {rms_data_counter = 0;}
	}

	vac_peak = _IQmpy(vac_rms , _IQsqrt(_IQ(2)));
	iac_peak = _IQmpy(iacf_rms , _IQsqrt(_IQ(2)));


	power_result = power();
	real_power = dc_filter(*power_result , &dcXq);
	reactive_power = dc_filter(*(power_result + 1) , &dcXp);
	phi = *(power_result + 2);

	return;
	
}



// S2.31 Error Check (returns 1 if THD is > 50% for 50 ms
char overvoltage(void)
{
	char result = 0;
	if (vdc_meas > (dq_vdc_ref + _IQ(50))){prot_counter++;}
	else {prot_counter = 0;}

	if (prot_counter >= 500) 
	{
		result = 1;
	}
	else {result = 0;}

	return result;
}

char overcurrent(void)
{
	return 0;
}

// S2.32 DC Filter
_iq	dc_filter(_iq nInput , _iq8 *x)
{
	_iq 	result = _IQ(0);
	_iq8	temp1 = *x;

	result = _IQmpyIQX(nInput,19,dcD,30) + _IQmpyIQX(dcC,30,temp1,8);
	*x = _IQ8mpyIQX(dcB,30,nInput,19) + _IQ8mpyIQX(dcA,30,temp1,8);
	return result;
}


// S2.33 Battery Charge Mode
void battery_charge(void)
{

	// if within limits ramp up current to reference
	// if current is at ref and voltage is above limits lower current
	//

	// within limits
	if (vbatt_meas < cv_max && ibatt_meas < cc_max)
	{
		if (cc_ramp < cc_ref) {cc_ramp += _IQ(0.00005);}
		cc_charging(cc_ramp);
		cv_ramp = vbatt_meas;
	}

	// current is out of limit
	if (vbatt_meas < cv_max && ibatt_meas >= cc_max)
	{
		cc_charging(cc_ref);
		cv_ramp = vbatt_meas;
		cc_ramp = ibatt_meas;
	}

	// voltage is out of limit
	if (vbatt_meas >= cv_max && ibatt_meas < cc_max)
	{
		cv_charging(cv_ref);
		cv_ramp = vbatt_meas;
		cc_ramp = ibatt_meas;
	}

	// current is out of limit
	if (vbatt_meas >= cv_max && ibatt_meas >= cc_max)
	{
		cv_charging(cv_ramp);
		cv_ramp -= _IQ(0.001);
	}

}


// S2.34 Battery Discharge Mode Control
void battery_discharge(void)
{
	// regular discharge mode
	if (vbatt_meas > cv_min)
	{
		cc_ramp -= _IQ(0.00001);
		if (cc_ramp < cc_min){cc_ramp = cc_min;}
		cc_charging(cc_ramp);
	}

	// voltage limited discharging
	else
	{
		cv_charging(cv_min);
		cc_ramp = ibatt_meas;
	}
}

//	S2.35 Constant Power Charging Mode Control (currently only works for charging modes)
void power_charge(void)
{
	// battery parameters are within range, battery won't be damaged, power control is allowed
	if ((vbatt_meas < cv_max) && (vbatt_meas > cv_min) && (ibatt_meas < cc_max) && (ibatt_meas > cc_min))
	{
		if (cp_ramp < power_ref) { cp_ramp += _IQ(0.001); }
		if (cp_ramp > power_ref) { cp_ramp -= _IQ(0.001); }
		cp_charging(cp_ramp);
		LED6OFF = 1;
	}
	// power control is not allowed, standard charging algorithms will be applied
	else 
	{
		battery_charge();
		LED6ON = 1;
	}

}
