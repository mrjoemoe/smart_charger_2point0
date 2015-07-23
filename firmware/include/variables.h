
_iq		ptemp = _IQ(0);
_iq		qtemp = _IQ(0);





#define LED1ON 		GpioDataRegs.GPACLEAR.bit.GPIO26
#define LED1OFF 	GpioDataRegs.GPASET.bit.GPIO26
#define LED2ON 		GpioDataRegs.GPACLEAR.bit.GPIO24
#define LED2OFF 	GpioDataRegs.GPASET.bit.GPIO24
#define LED3ON 		GpioDataRegs.GPACLEAR.bit.GPIO15
#define LED3OFF		GpioDataRegs.GPASET.bit.GPIO15
#define LED4ON		GpioDataRegs.GPACLEAR.bit.GPIO12
#define LED4OFF		GpioDataRegs.GPASET.bit.GPIO12
#define LED5ON		GpioDataRegs.GPACLEAR.bit.GPIO29
#define LED5OFF		GpioDataRegs.GPASET.bit.GPIO29
#define LED6ON		GpioDataRegs.GPACLEAR.bit.GPIO31
#define LED6OFF		GpioDataRegs.GPASET.bit.GPIO31

#define ACDC_SWITCH GpioDataRegs.GPADAT.bit.GPIO7
#define DCDC_SWITCH GpioDataRegs.GPADAT.bit.GPIO9
#define P_SWITCH 	GpioDataRegs.GPADAT.bit.GPIO11
#define Q_SWITCH 	GpioDataRegs.GPADAT.bit.GPIO13



void	led_indicators(char led);





////////////////////// VARIABLES //////////////////////////////////
/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////



char	i 		= 0;
_iq		S 		= _IQ(3300); // charger kVA rating



///////////////////// Constants //////////////////////////////////
_iq 	pi 		= _IQ(3.141592654);
_iq 	pi2 	= _IQ(6.283185307);
_iq 	pi2f	= _IQ(376.9911184);

//////////////////// System State Variables //////////////////////
char	prev_state = 0;


////////////////////// General Controller Variables//////////////////

_iq30 	Ts 				= _IQ30(0.00005);
_iq		vdc_meas 		= _IQ(0);
_iq		vac_meas 		= _IQ(0);
_iq		iac_meas 		= _IQ(0);
_iq		vbatt_meas 		= _IQ(0);
_iq		ibatt_meas 		= _IQ(0);
_iq 	vac_delay[84] 	= {_IQ(0)};
_iq 	iac_delay[84] 	= {_IQ(0)};
_iq 	iacf_delay[84] 	= {_IQ(0)};
_iq		iacf 			= _IQ(0);
_iq		iac_rms 		= _IQ(0);
_iq		iacf_rms 		= _IQ(0); // filtered rms value
_iq		vac_rms 		= _IQ(0);
_iq		iac_peak 		= _IQ(0);
_iq		vac_peak 		= _IQ(0);
_iq 	theta 			= _IQ(0); //reference angle for AC voltage waveform
_iq		phi 			= _IQ(0); // angle between current and voltage
_iq     *dq_result;
_iq		*power_result;
_iq		real_power 		= _IQ(0);
_iq		reactive_power 	= _IQ(0);
char 	dcounter 		= 0;
char 	current_mode 	= 0;
char	prev_mode 		= 0;
char	mode[5] 		= {0};


/////////////////////////// ADC Variables //////////////////////////
long int RESULT0,RESULT1,RESULT2,RESULT3;
_iq			ADC_fk_iq[5] ={
								_IQ(0.102580094), 	// Vac multiplier -> ADC_out_iq[0]
					 			_IQ(0.113995622),   // Vdc multiplier -> ADC_out_iq[1]
                                _IQ(0.014652014),	// Iac multiplier -> ADC_out_iq[2]
								_IQ(0.027322404), 	// Vbatt multiplier ->ADC_out_iq[3]
								_IQ(0.014652014),	// Ibatt multiplier ->ADC_out_iq[4]

                          };
_iq			ADC_out_iq[5]={_IQ(0)}; // ADC outputs
_iq			ADC_in_iq[5]={_IQ(0)};	// ADC inputs
_iq18		ADC_base_iq[5]={_IQ(0)}; //ADC register values

_iq			ADC_res_corr[5] = {						// correction factors for inexact resistors
								_IQ(1.04166667),	// Vac
								_IQ(1.03012073),	// Vdc
								_IQ(1.006),			// Iac
								_IQ(0.8228),		// Vbatt
								_IQ(1.006)			// Ibatt
							};



////////////////// AB-DQ Correction Variables /////////////////////////////
_iq30 L1 					= _IQ30(0.012566039);
_iq30 L2 					= _IQ30(0.000078956);



////////////// RMS calculation variables /////////////////////////////////////

// correction factors for RMS calculations
_iq30 	K1 					= _IQ30(0.0013333333);  
_iq30 	K2 					= _IQ30(-0.0066666667);

// rms cycle counters
char 	rms_cycle_counter 	= 0; // to count to 16
char 	rms_data_counter 	= 0; // to count to 21

// rms data storage variables
_iq16 	vrms_delay[21] 		= {_IQ16(0)};
_iq16 	irms_delay[21] 		= {_IQ16(0)};
_iq16	ifrms_delay[21] 	= {_IQ16(0)};

// rms calc integrator outputs
_iq16 	vrms_int_output 	= _IQ16(0);
_iq16	irms_int_output 	= _IQ16(0);
_iq16	ifrms_int_output 	= _IQ16(0);

// correction delay values
_iq16	vrms_corr_delay 	= _IQ16(0);
_iq16 	irms_corr_delay 	= _IQ16(0);
_iq16	ifrms_corr_delay 	= _IQ16(0);


////////////// Digital Low Pass Filter Variables//////////////////////////////////

// state space variables

// third order filter
_iq29 	a11 	= _IQ29(0.8852);
_iq23 	a12 	= _IQ23(-125.0779);
_iq14 	a13 	= _IQ14(-44036);
_iq30 	a21 	= _IQ30(0.000047131);
_iq29 	a22 	= _IQ29(0.9969);
_iq29 	a23 	= _IQ29(-1.1009);
_iq30 	a31 	= _IQ30(0.0000000011783);      //_IQ(0.0000000011783);
_iq30 	a32 	= _IQ30(0.000049922);
_iq29 	a33 	= _IQ29(1);
_iq29 	b1 		= _IQ29(0.9426);
_iq30 	b2 		= _IQ30(0.000023566);
_iq30 	b3 		= _IQ30(0.000000001);      //_IQ(0.00000000058914);
_iq30 	c1 		= _IQ30(0.0029);
_iq23 	c2 		= _IQ23(124.9691);
_iq15 	c3 		= _IQ15(29817);
_iq30 	d 		= _IQ30(0.0015);

//state variables

_iq23 	i_x1 	= _IQ23(0);
_iq30 	i_x2 	= _IQ30(0);
_iq30 	i_x3 	= _IQ30(0);

_iq30	dcA 	= _IQ30(0.999);
_iq30 	dcB 	= _IQ30(0.9995);
_iq30	dcC 	= _IQ30(0.0009995);
_iq30	dcD 	= _IQ30(0.00049975);


////////////////////// Power Calculation Variables //////////////////////////////
_iq		idf = _IQ(0);
_iq		iqf = _IQ(0);




/////////////////////// Protection Variables //////////////////////////////////////
char	prot_toggle = 0 ; 

///////////////////// PI controller variables //////////////////////
// all PI control variables begin with pi


///////////////// DQ controller variables /////////////////////////////
// all dq control variables begin with dq

// General DQ Variables

_iq 	dq_res 				= _IQ(0.504);
_iq 	pi2fL 				= _IQ(0.3888576);
_iq 	dq_id_corr 			= _IQ(0);
_iq 	dq_id_corr_scale 	= _IQ(0);
_iq 	dq_iq_corr 			= _IQ(0);
_iq 	dq_iq_corr_scale 	= _IQ(0);
_iq 	dq_id 				= _IQ(0);
_iq 	dq_iq 				= _IQ(0);
_iq 	dq_vd 				= _IQ(0);
_iq 	dq_vq 				= _IQ(0);


// dq pll control variables
_iq 	vq_ref 				= _IQ(0);
_iq 	dq_pll_int 			= _IQ(0);

// dq vdc control loop variables
_iq		dq_vdc_error 		= _IQ(0);
_iq		dq_vdc_ref 			= _IQ(100);
_iq		dq_ramp 			= _IQ(0);
_iq		dq_vdc_int 			= _IQ(0);
_iq		dq_vdc_pi 			= _IQ(0);

// id control loop variables
_iq		dq_id_error 		= _IQ(0);
_iq		dq_id_int 			= _IQ(0);
_iq		dq_id_pi 			= _IQ(0);

// iq control loop variables
_iq		dq_iq_error 		= _IQ(0);
_iq		dq_iq_int 			= _IQ(0);
_iq		dq_iq_pi 			= _IQ(0);





//////////// Constant Voltage Charging Control Variables ///////
// all constant voltage variables begin with cv
_iq		cv_max 		= _IQ(15);
_iq		cv_ref		= _IQ(14);
_iq		cv_min 		= _IQ(10.8);
_iq		cv_error 	= _IQ(0);
_iq		cv_int 		= _IQ(0);
_iq		cv_pi 		= _IQ(0);
_iq		cv_ramp		= _IQ(0);


//////////// Constant Current Charging Control Variables ///////
// all constant current variables begin with cc
_iq		cc_max 		= _IQ(5);
_iq		cc_ref		= _IQ(2);
_iq		cc_min 		= _IQ(-5);
_iq		cc_ramp 	= _IQ(0);
_iq		cc_error 	= _IQ(0);
_iq		cc_int 		= _IQ(0);	// integrator result
_iq		cc_pi 		= _IQ(0);		// pi controller result


////////////////////// EPWM Variables ////////////////////////////

_iq		v_cont_acdc 		= _IQ(0.5);
_iq		v_cont_dcdc 		= _IQ(0.5);
short 	igbt_control_pos 	= 0;
short 	igbt_control_neg 	= 0;
short 	igbt_dcdc 			= 0;
short	period				= 2500; 			// Frequency (Sys clk=10ns) 20kHz
short 	half_period 		= 1250;
short	db_delay 			= 100;			// 100 = 1us

//////////////////////////////////////////////////////////////////////

/////////////////Battery Control Variables //////////////////////
_iq		oc_voltage = _IQ(0);
char	overv_counter = 0;
char	overc_counter = 0;


//////////////// Power Control Variables ///////////////////////
_iq 	power_ref 		= _IQ(150);
_iq		cp_error 		= _IQ(0);
_iq		cp_int 			= _IQ(0);
_iq		cp_pi 			= _IQ(0);	
_iq		cp_ramp 		= _IQ(0);	

_iq		reactive_ref 	= _IQ(250);
_iq		Q_int 			= _IQ(0);



_iq8	dcXp 			= _IQ8(0);
_iq8	dcXq 			= _IQ8(0);


///////////////// Protection Variables ///////////////
short	prot_counter 	= 0;		
char	fault_count 	= 0;

///////////////// END VARIABLES ///////////////////////////////
///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////









// 2.33 Led indicators
void	led_indicators(char led)
{
	switch(led)
	{
		case(0x00):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x01):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x02):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x03):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x04):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x05):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x06):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x07):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x08):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x09):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x0A):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x0B):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x0C):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x0D):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x0E):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;

		case(0x0F):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break;


/*

		case(0x10):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x11):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x12):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x13):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x14):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x15):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x16):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x17):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x18):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x19):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x1A):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x1B):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x1C):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x1D):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x1E):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x1F):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6OFF = 1;
		break;

		case(0x20):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x21):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x22):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x23):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x24):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x25):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x26):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x27):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x28):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x29):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x2A):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x2B):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x2C):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x2D):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x2E):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x2F):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5OFF = 1;
		LED6ON = 1;
		break;

		case(0x30):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x31):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x32):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x33):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x34):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x35):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x36):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x37):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4OFF = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x38):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x39):
		LED1ON = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x3A):
		LED1OFF = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x3B):
		LED1ON = 1;
		LED2ON = 1;
		LED3OFF = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x3C):
		LED1OFF = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x3D):
		LED1ON = 1;
		LED2OFF = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x3E):
		LED1OFF = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		case(0x3F):
		LED1ON = 1;
		LED2ON = 1;
		LED3ON = 1;
		LED4ON = 1;
		LED5ON = 1;
		LED6ON = 1;
		break;

		default:
		LED1OFF = 1;
		LED2OFF = 1;
		LED3OFF = 1;
		LED4OFF = 1;
		LED5OFF = 1;
		LED6OFF = 1;
		break; */
	}
	
}












////// GENERAL INFORMATION ////////////////////////

// (1)
// Initialize interrupt functions
// PIE: Peripherial Interrupt Expansion, this muxes 96 possible interrupts into
// 12 interrupt lines
// The 96 interrupts are grouped into blocks of 8 and each group is fed into 1 of
// 12 CPU interrupt lines (INT1 to INT12).
// Each of the 96 interrupts is supported by its own vector stored in a
// dedicated RAM block that can be overwritten by the user.(PIE Vector Table)

 
// (2) 
// EALLOW is an assembly instruction that gives access to registers that are EALLOW protected
// to modify registers that are EALLOW protected you must write EALLOW before accesssing these registers
// and when done modifying the register you write EDIS to disallow modify these registers when the
// program is running.

// (3)
// GPIO registers are general purpose registers. These registers must be configured before using. 
// to use the ePWM modules some of the GPIO pins must be set as ePWM pins

//(4)
// The relationship between the epwm registers with the ADC and gate driving signals is as follows:
// The system clock is 10 ns and the epwm counter is set to 2500. Therefore the system period is
// 10ns * 2500 * 2 = 50us. The ADC starts a conversion when the time based counter = 1000 and is 
// increasing. This sampled value is then held until the next ADC-start of conversion, which takes
// place on the next cycle when the counter = 1000 and is increasing. An interrupt, which starts the
// control_run process is triggered when the time based counter = 0 and is increasing. During the
// control_run the current ADC sampled value is used (which would have been calculated during the
// last iteration) and the gate driving signals are updated to a value between 0 and 2500. The gate
// drivers are then fired according to their control scheme. 







