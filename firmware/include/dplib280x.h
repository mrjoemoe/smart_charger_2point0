//----------------------------------------------------------------------------------
//	FILE:			dplib280x.h
//
//	Description:	C header for digital power library
//
//	$Revision: /main/1 $
//      $Date: August 3, 2006   17:52:14 $
//
//  Target:  		TMS320F280x (F2808, F2806, F2801).  
//
//	Type: 			Device dependent
//
//FILE_TAG: .\lib\dpslib280x\include\CntlPiMacro.h 
//============================================================================
//	CONTROL_LAW Macro module - PI
//============================================================================
#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             int16;
typedef long            int32;
typedef unsigned int    Uint16;
typedef unsigned long   Uint32;
typedef float           float32;
typedef long double     float64;
#endif

struct CNTL_PI_DATA_BUFFER_STRUCT
{	long int Error;
	long int Integral;
	long int IntegralTemp;
	int	 SatFlag;
};

typedef struct CNTL_PI_DATA_BUFFER_STRUCT CNTL_PI_DATA_BUFFER;

struct CNTL_PI_COEFF_STRUCT
{	long int IsatUpperLimit;
	long int IsatLowerLimit;
	long Ki;
	long Kp;
	long Kf;
	long int OutputUpperLimit;
	long int OutputLowerLimit;
};

typedef struct CNTL_PI_COEFF_STRUCT CNTL_PI_COEFF;

extern int *CNTL_PI_Ref1, *CNTL_PI_Fdbk1, *CNTL_PI_Out1;
extern struct CNTL_PI_COEFF_STRUCT *CNTL_PI_Coeff1;

 
extern int *CNTL_PI_Ref2, *CNTL_PI_Fdbk2, *CNTL_PI_Out2;
extern struct CNTL_PI_COEFF_STRUCT *CNTL_PI_Coeff2;

 
//FILE_TAG: .\lib\dpslib280x\include\Module_Terminals.h 

// ADC3CH_DRV & ADC1CH_DRV & ADC3CH_BI_DRV
extern int16	*ADC3CH_Rslt, *ADC2CH_Rslt, *ADC1CH_Rslt;

// ADCxCONT_DRV 
extern int16	*ADC6CH_Rslt, *ADC5CH_Rslt;


// PSFB_DRV
extern int16	*PSFB_phase1, *PSFB_dbLeft1, *PSFB_dbRight1;
extern int16	*PSFB_phase2, *PSFB_dbLeft2, *PSFB_dbRight2;
extern int16	*PSFB_phase3, *PSFB_dbLeft3, *PSFB_dbRight3;

// HR_PSFB_DRV
extern int16	*PSFB_phase, *PSFB_dbLeft, *PSFB_dbRight;
extern int16	SFPSFB;

// HRPWM_DAC_DRV
extern int16	*HRPWM_DAC_InPtr1, SFDAC1;
extern int16	*HRPWM_DAC_InPtr2, SFDAC2;
extern int16	*HRPWM_DAC_InPtr3, SFDAC3;
extern int16	*HRPWM_DAC_InPtr4, SFDAC4;


// D-CLASS_DRV
extern int16	*D_CLASS_In1, SF1;
extern int16	*D_CLASS_In2, SF2;

// BUCK_DRV
extern int16	*BUCK_InA1, *BUCK_InB1;
extern int16	*BUCK_InA2, *BUCK_InB2;
extern int16	*BUCK_InA3, *BUCK_InB3;
extern int16	*BUCK_InA4, *BUCK_InB4;

// HRBUCK_DRV
extern int16	*HRBUCK_In1, SFBUCK1;
extern int16	*HRBUCK_In2, SFBUCK2;
extern int16	*HRBUCK_In3, SFBUCK3;

// PWMDAC_DRV
extern int16	*PWMDAC_InA1, *PWMDAC_InB1;
extern int16	*PWMDAC_InA2, *PWMDAC_InB2;
extern int16	*PWMDAC_InA3, *PWMDAC_InB3;

// PFC2PHIL_DRV
extern int16	*PFC2PHIL_Duty, *PFC2PHIL_Adj;
extern int16	*PFC2PHIL_ONECH_Duty, *PFC2PHIL_ONECH_Adj;


// HHB_DRV
extern int16	*HHB_Duty;

// MPIL_DRV
extern int16	*MPIL_Duty1;
extern int16	*MPIL_Duty2;
extern int16	*MPIL_Duty3;

// SLEW_LIMIT
extern int16	*SLEW_LIMIT_In1, *SLEW_LIMIT_Incr1, *SLEW_LIMIT_Out1;
extern int16	*SLEW_LIMIT_In2, *SLEW_LIMIT_Incr2, *SLEW_LIMIT_Out2;

// CNTL_2P2Z
extern int16	*CNTL_2P2Z_Ref1, *CNTL_2P2Z_Fdbk1, *CNTL_2P2Z_Out1;
extern int16	*CNTL_2P2Z_Ref2, *CNTL_2P2Z_Fdbk2, *CNTL_2P2Z_Out2;
extern int16	*CNTL_2P2Z_Ref3, *CNTL_2P2Z_Fdbk3, *CNTL_2P2Z_Out3;
extern int16	*CNTL_2P2Z_Ref4, *CNTL_2P2Z_Fdbk4, *CNTL_2P2Z_Out4;

// PFC_OVP
extern int16	*PFC_OVP_In1, *PFC_OVP_Vmon1, *PFC_OVP_Out1;

// PFC_ICMD
extern int16	*PFC_ICMD_V11, *PFC_ICMD_V21, *PFC_ICMD_Vac1, *PFC_ICMD_Out1;

// FILT_2P2Z
extern int16	*FILT_2P2Z_In1, *FILT_2P2Z_Out1;

// AC_LINE_RECT
extern int16	*AC_LINE_RECT_In1, *AC_LINE_RECT_Out1;

// FILT_BIQUAD
extern int16	*FILT_BIQUAD_In1, *FILT_BIQUAD_Out1;

// INV_SQR
extern int16	*INV_SQR_In1, *INV_SQR_Out1;

// BOXCAR_AVG
extern int16	*BOXCAR_AVG_In1, *BOXCAR_AVG_Out1;
extern int16	*BOXCAR_AVG_In2, *BOXCAR_AVG_Out2;

// EMA
extern int16    *EMA_In1, *EMA_Out1;
extern int16    *EMA_In2, *EMA_Out2;

// PFC_ISHARE
extern int16	*PFC_ISHARE_Ia, *PFC_ISHARE_Ib, *PFC_ISHARE_Out;

// SINGEN_1CH
extern int16	*SINGEN_1CH_Gain1, *SINGEN_1CH_Offset1, *SINGEN_1CH_Freq1, *SINGEN_1CH_Out1;
extern int16	*SINGEN_1CH_Gain2, *SINGEN_1CH_Offset2, *SINGEN_1CH_Freq2, *SINGEN_1CH_Out2;

// RAMPGEN_1CH
extern int16	*RAMPGEN_1CH_Gain1, *RAMPGEN_1CH_Offset1, *RAMPGEN_1CH_Freq1, *RAMPGEN_1CH_Out1;
extern int16	*RAMPGEN_1CH_Gain2, *RAMPGEN_1CH_Offset2, *RAMPGEN_1CH_Freq2, *RAMPGEN_1CH_Out2;

// HRPWM_DAC
extern int 		*HRPWM_DAC_InPtr1, *HRPWM_DAC_InPtr2, *HRPWM_DAC_InPtr3, *HRPWM_DAC_InPtr4;

// HRFULLBDG_BIPOLAR
extern int16	*HRFullBdg_BI_In, SFFullBdg_BI;

// HRFULLBDG_UNIPOLAR1
extern int16	*HRFullBdg_UNI1_In, SFFullBdg_UNI1;

// HRFULLBDG_UNIPOLAR2
extern int16	*HRFullBdg_UNI2_In, SFFullBdg_UNI2;
extern Uint16   *HRFullBdg_UNI2_Polarity;

//FILE_TAG: .\lib\drvlib280x\include\PWM_Drivers.h 

// Function prototypes / function interface

#ifndef _052605_PWM_DRIVERS_H_DEFINED_834543523465792346592347623957657365753629563
#define _052605_PWM_DRIVERS_H_DEFINED_834543523465792346592347623957657365753629563


void InitPWM_ModulePtr(void);
void TimeBasePeriodCnf(int16 n, int16 period);
void BuckDrvCnf(int16 n, int16 period);
void MPILDrvCnf(int16 n, int16 N, int16 period);
void Pfc2philDrvCnf(int16 n, int16 period);
void HHbDrvCnf(void);
void PSFBDrvCnf(int16 n, int16 period);
void HrBuckDrvCnf(int16 n, int16 period);
void HrBuckDrvCnfV2(int16 nEPWMChannel, int16 nPeriod, int16 nMode, int16 nPhase);
void HrPSFBDrvCnf(int16 n, int16 period);
void HrPwmDacDrvCnf(int16 n, int16 period);
void ADC5CONTCnf(int16 nChannel0, int16 nChannel1, int16 nChannel2, int16 nChannel3, int16 nChannel4, int16 nAcqWidth);

#endif
