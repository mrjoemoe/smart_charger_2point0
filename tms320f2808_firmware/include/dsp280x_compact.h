//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_Device.h 
// TI File $Revision: /main/1 $
// Checkin $Date: August 3, 2006   17:52:48 $
//###########################################################################
//
// FILE:   DSP280x_Device.h
//
// TITLE:  DSP280x Device Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_DEVICE_H
#define DSP280x_DEVICE_H


#ifdef __cplusplus
extern "C" {
#endif


#define   TARGET   1
//---------------------------------------------------------------------------
// User To Select Target Device:

#define   DSP28_2808   TARGET
#define   DSP28_2806   0
#define   DSP28_2801   0

//---------------------------------------------------------------------------
// Common CPU Definitions:
//

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;

#define  EINT   asm(" clrc INTM")
#define  DINT   asm(" setc INTM")
#define  ERTM   asm(" clrc DBGM")
#define  DRTM   asm(" setc DBGM")
#define  EALLOW asm(" EALLOW")
#define  EDIS   asm(" EDIS")
#define  ESTOP0 asm(" ESTOP0")

#define M_INT1  0x0001
#define M_INT2  0x0002
#define M_INT3  0x0004
#define M_INT4  0x0008
#define M_INT5  0x0010
#define M_INT6  0x0020
#define M_INT7  0x0040
#define M_INT8  0x0080
#define M_INT9  0x0100
#define M_INT10 0x0200
#define M_INT11 0x0400
#define M_INT12 0x0800
#define M_INT13 0x1000
#define M_INT14 0x2000
#define M_DLOG  0x4000
#define M_RTOS  0x8000

#define BIT0    0x0001
#define BIT1    0x0002
#define BIT2    0x0004
#define BIT3    0x0008
#define BIT4    0x0010
#define BIT5    0x0020
#define BIT6    0x0040
#define BIT7    0x0080
#define BIT8    0x0100
#define BIT9    0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000



//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use Following Data Type Size
// Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
//

#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             int16;
typedef long            int32;
typedef unsigned int    Uint16;
typedef unsigned long   Uint32;
typedef float           float32;
typedef long double     float64;
#endif


//---------------------------------------------------------------------------
// Include All Peripheral Header Files:
//

//  #include "DSP280x_Adc.h"                // ADC Registers
//#include "DSP280x_DevEmu.h"             // Device Emulation Registers
//#include "DSP280x_CpuTimers.h"          // 32-bit CPU Timers
//#include "DSP280x_ECan.h"               // Enhanced eCAN Registers
//#include "DSP280x_ECap.h"               // Enhanced Capture
//#include "DSP280x_EPwm.h"               // Enhanced PWM 
//#include "DSP280x_EQep.h"               // Enhanced QEP
//#include "DSP280x_Gpio.h"               // General Purpose I/O Registers
//#include "DSP280x_I2c.h"                // I2C Registers
//#include "DSP280x_PieCtrl.h"            // PIE Control Registers
//#include "DSP280x_PieVect.h"            // PIE Vector Table
//#include "DSP280x_Spi.h"                // SPI Registers
//#include "DSP280x_Sci.h"                // SCI Registers
//#include "DSP280x_SysCtrl.h"            // System Control/Power Modes
//#include "DSP280x_XIntrupt.h"           // External Interrupts
//#include "dplib280x.h"

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_DEVICE_H definition


//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_CpuTimers.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:31:30 $
//###########################################################################
//
// FILE:    DSP280x_CpuTimers.h
//
// TITLE:   DSP280x CPU 32-bit Timers Register Definitions.
//
// NOTES:   CpuTimer1 and CpuTimer2 are reserved for use with DSP BIOS and
//          other realtime operating systems.  
//
//          Do not use these two timers in your application if you ever plan
//          on integrating DSP-BIOS or another realtime OS. 
//
//          For this reason, the code to manipulate these two timers is
//          commented out and not used in these examples.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_CPU_TIMERS_H
#define DSP280x_CPU_TIMERS_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// CPU Timer Register Bit Definitions:
//
//
// TCR: Control register bit definitions:
struct  TCR_BITS {          // bits  description
   Uint16    rsvd1:4;       // 3:0   reserved
   Uint16    TSS:1;         // 4     Timer Start/Stop
   Uint16    TRB:1;         // 5     Timer reload
   Uint16    rsvd2:4;       // 9:6   reserved
   Uint16    SOFT:1;        // 10    Emulation modes
   Uint16    FREE:1;        // 11
   Uint16    rsvd3:2;       // 12:13 reserved
   Uint16    TIE:1;         // 14    Output enable
   Uint16    TIF:1;         // 15    Interrupt flag
}; 

union TCR_REG {
   Uint16           all;
   struct TCR_BITS  bit;
};

// TPR: Pre-scale low bit definitions:
struct  TPR_BITS {        // bits  description
   Uint16     TDDR:8;     // 7:0   Divide-down low
   Uint16     PSC:8;      // 15:8  Prescale counter low
};

union TPR_REG {
   Uint16           all;
   struct TPR_BITS  bit;
};

// TPRH: Pre-scale high bit definitions:
struct  TPRH_BITS {       // bits  description
   Uint16     TDDRH:8;      // 7:0   Divide-down high
   Uint16     PSCH:8;       // 15:8  Prescale counter high
};

union TPRH_REG {
   Uint16           all;
   struct TPRH_BITS bit;
};

// TIM, TIMH: Timer register definitions:
struct TIM_REG {
   Uint16  LSW;
   Uint16  MSW;
};

union TIM_GROUP {
   Uint32          all;
   struct TIM_REG  half;
};

// PRD, PRDH: Period register definitions:
struct PRD_REG {
   Uint16  LSW;
   Uint16  MSW;
};

union PRD_GROUP {
   Uint32          all;
   struct PRD_REG  half;
};

//---------------------------------------------------------------------------
// CPU Timer Register File:
//
struct CPUTIMER_REGS {
   union TIM_GROUP TIM;   // Timer counter register
   union PRD_GROUP PRD;   // Period register
   union TCR_REG   TCR;   // Timer control register
   Uint16          rsvd1; // reserved
   union TPR_REG   TPR;   // Timer pre-scale low
   union TPRH_REG  TPRH;  // Timer pre-scale high
};

//---------------------------------------------------------------------------
// CPU Timer Support Variables:
//
struct CPUTIMER_VARS {
   volatile struct  CPUTIMER_REGS  *RegsAddr;
   Uint32    InterruptCount;
   float   CPUFreqInMHz;
   float   PeriodInUSec;
};

//---------------------------------------------------------------------------
// Function prototypes and external definitions:
//
void InitCpuTimers(void);
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period);

extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern struct CPUTIMER_VARS CpuTimer0;

// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS
//extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
//extern volatile struct CPUTIMER_REGS CpuTimer2Regs;

//extern struct CPUTIMER_VARS CpuTimer1;
//extern struct CPUTIMER_VARS CpuTimer2;

//---------------------------------------------------------------------------
// Usefull Timer Operations:
//
// Start Timer:
#define StartCpuTimer0()  CpuTimer0Regs.TCR.bit.TSS = 0

// Stop Timer:
#define StopCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 1

// Reload Timer With period Value:
#define ReloadCpuTimer0() CpuTimer0Regs.TCR.bit.TRB = 1

// Read 32-Bit Timer Value:
#define ReadCpuTimer0Counter() CpuTimer0Regs.TIM.all

// Read 32-Bit Period Value:
#define ReadCpuTimer0Period() CpuTimer0Regs.PRD.all

// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS
// Do not use these two timers if you ever plan on integrating 
// DSP-BIOS or another realtime OS. 
//
// For this reason, the code to manipulate these two timers is
// commented out and not used in these examples.

// Start Timer:
//#define StartCpuTimer1()  CpuTimer1Regs.TCR.bit.TSS = 0
//#define StartCpuTimer2()  CpuTimer2Regs.TCR.bit.TSS = 0

// Stop Timer:
//#define StopCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 1
//#define StopCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 1

// Reload Timer With period Value:
//#define ReloadCpuTimer1() CpuTimer1Regs.TCR.bit.TRB = 1
//#define ReloadCpuTimer2() CpuTimer2Regs.TCR.bit.TRB = 1

// Read 32-Bit Timer Value:
//#define ReadCpuTimer1Counter() CpuTimer1Regs.TIM.all
//#define ReadCpuTimer2Counter() CpuTimer2Regs.TIM.all

// Read 32-Bit Period Value:
//#define ReadCpuTimer1Period() CpuTimer1Regs.PRD.all
//#define ReadCpuTimer2Period() CpuTimer2Regs.PRD.all


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_CPU_TIMERS_H definition


//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_DevEmu.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:31:33 $
//###########################################################################
//
// FILE:   DSP280x_DevEmu.h
//
// TITLE:  DSP280x Device Emulation Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_DEV_EMU_H
#define DSP280x_DEV_EMU_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// Device Emulation Register Bit Definitions:
//
// Device Configuration Register Bit Definitions
struct DEVICECNF_BITS  {     // bits  description
   Uint16 rsvd1:3;           // 2:0   reserved
   Uint16 VMAPS:1;           // 3     VMAP Status
   Uint16 rsvd2:1;           // 4     reserved
   Uint16 XRSn:1;            // 5     XRSn Signal Status
   Uint16 rsvd3:10;          // 15:6
   Uint16 rsvd4:3;           // 18:6
   Uint16 ENPROT:1;          // 19    Enable/Disable pipeline protection
   Uint16 MONPRIV:1;         // 20    MONPRIV enable bit
   Uint16 rsvd5:1;           // 21    reserved
   Uint16 EMU0SEL:2;         // 23,22 EMU0 Mux select
   Uint16 EMU1SEL:2;         // 25,24 EMU1 Mux select
   Uint16 rsvd6:6;           // 31:26 reserved
};

union DEVICECNF_REG {
   Uint32                 all;
   struct DEVICECNF_BITS  bit;
};

struct DEV_EMU_REGS {
   union DEVICECNF_REG DEVICECNF;  // device configuration
   Uint16              PARTID;     // Part ID
   Uint16              REVID;      // Device ID
   Uint16              PROTSTART;  // Write-Read protection start
   Uint16              PROTRANGE;  // Write-Read protection range
   Uint16              rsvd2[202];
};

//---------------------------------------------------------------------------
// Device Emulation Register References & Function Declarations:
//
extern volatile struct DEV_EMU_REGS DevEmuRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_DEV_EMU_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_Adc.h 
// TI File $Revision: /main/2 $
// Checkin $Date: December 2, 2004   13:40:05 $
//###########################################################################
//
// FILE:   DSP280x_Adc.h
//
// TITLE:  DSP280x Device ADC Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_ADC_H
#define DSP280x_ADC_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCTRL1_BITS {     // bits  description
    Uint16  rsvd1:4;      // 3:0   reserved
    Uint16  SEQ_CASC:1;   // 4     Cascaded sequencer mode
    Uint16  SEQ_OVRD:1;   // 5     Sequencer override 
    Uint16  CONT_RUN:1;   // 6     Continuous run
    Uint16  CPS:1;        // 7     ADC core clock pre-scalar
    Uint16  ACQ_PS:4;     // 11:8  Acquisition window size
    Uint16  SUSMOD:2;     // 13:12 Emulation suspend mode
    Uint16  RESET:1;      // 14    ADC reset
    Uint16  rsvd2:1;      // 15    reserved
};


union ADCTRL1_REG {
   Uint16                all;
   struct ADCTRL1_BITS   bit;
};


struct ADCTRL2_BITS {         // bits  description
    Uint16  EPWM_SOCB_SEQ2:1; // 0     EPWM compare B SOC mask for SEQ2
    Uint16  rsvd1:1;          // 1     reserved
    Uint16  INT_MOD_SEQ2:1;   // 2     SEQ2 Interrupt mode
    Uint16  INT_ENA_SEQ2:1;   // 3     SEQ2 Interrupt enable
    Uint16  rsvd2:1;          // 4     reserved
    Uint16  SOC_SEQ2:1;       // 5     Start of conversion for SEQ2
    Uint16  RST_SEQ2:1;       // 6     Reset SEQ2
    Uint16  EXT_SOC_SEQ1:1;   // 7     External start of conversion for SEQ1
    Uint16  EPWM_SOCA_SEQ1:1; // 8     EPWM compare B SOC mask for SEQ1
    Uint16  rsvd3:1;          // 9     reserved
    Uint16  INT_MOD_SEQ1:1;   // 10    SEQ1 Interrupt mode
    Uint16  INT_ENA_SEQ1:1;   // 11    SEQ1 Interrupt enable
    Uint16  rsvd4:1;          // 12    reserved
    Uint16  SOC_SEQ1:1;       // 13    Start of conversion trigger for SEQ1
    Uint16  RST_SEQ1:1;       // 14    Restart sequencer 1   
    Uint16  EPWM_SOCB_SEQ:1;  // 15    EPWM compare B SOC enable
};


union ADCTRL2_REG {
   Uint16                all;
   struct ADCTRL2_BITS   bit;
};


struct ADCASEQSR_BITS {       // bits   description
    Uint16  SEQ1_STATE:4;     // 3:0    SEQ1 state
    Uint16  SEQ2_STATE:3;     // 6:4    SEQ2 state
    Uint16  rsvd1:1;          // 7      reserved
    Uint16  SEQ_CNTR:4;       // 11:8   Sequencing counter status 
    Uint16  rsvd2:4;          // 15:12  reserved  
};

union ADCASEQSR_REG {
   Uint16                 all;
   struct ADCASEQSR_BITS  bit;
};


struct ADCMAXCONV_BITS {      // bits  description
    Uint16  MAX_CONV1:4;      // 3:0   Max number of conversions
    Uint16  MAX_CONV2:3;      // 6:4   Max number of conversions    
    Uint16  rsvd1:9;          // 15:7  reserved 
};

union ADCMAXCONV_REG {
   Uint16                  all;
   struct ADCMAXCONV_BITS  bit;
};


struct ADCCHSELSEQ1_BITS {    // bits   description
    Uint16  CONV00:4;         // 3:0    Conversion selection 00
    Uint16  CONV01:4;         // 7:4    Conversion selection 01
    Uint16  CONV02:4;         // 11:8   Conversion selection 02
    Uint16  CONV03:4;         // 15:12  Conversion selection 03
};

union  ADCCHSELSEQ1_REG{
   Uint16                    all;
   struct ADCCHSELSEQ1_BITS  bit;
};

struct ADCCHSELSEQ2_BITS {    // bits   description
    Uint16  CONV04:4;         // 3:0    Conversion selection 04
    Uint16  CONV05:4;         // 7:4    Conversion selection 05
    Uint16  CONV06:4;         // 11:8   Conversion selection 06
    Uint16  CONV07:4;         // 15:12  Conversion selection 07
};

union  ADCCHSELSEQ2_REG{
   Uint16                    all;
   struct ADCCHSELSEQ2_BITS  bit;
};

struct ADCCHSELSEQ3_BITS {    // bits   description
    Uint16  CONV08:4;         // 3:0    Conversion selection 08
    Uint16  CONV09:4;         // 7:4    Conversion selection 09
    Uint16  CONV10:4;         // 11:8   Conversion selection 10
    Uint16  CONV11:4;         // 15:12  Conversion selection 11
};

union  ADCCHSELSEQ3_REG{
   Uint16                    all;
   struct ADCCHSELSEQ3_BITS  bit;
};

struct ADCCHSELSEQ4_BITS {    // bits   description
    Uint16  CONV12:4;         // 3:0    Conversion selection 12
    Uint16  CONV13:4;         // 7:4    Conversion selection 13
    Uint16  CONV14:4;         // 11:8   Conversion selection 14
    Uint16  CONV15:4;         // 15:12  Conversion selection 15
};

union  ADCCHSELSEQ4_REG {
   Uint16                    all;
   struct ADCCHSELSEQ4_BITS  bit;
};

struct ADCTRL3_BITS {         // bits   description
    Uint16   SMODE_SEL:1;     // 0      Sampling mode select
    Uint16   ADCCLKPS:4;      // 4:1    ADC core clock divider
    Uint16   ADCPWDN:1;       // 5      ADC powerdown
    Uint16   ADCBGRFDN:2;     // 7:6    ADC bandgap/ref power down
    Uint16   rsvd1:8;         // 15:8   reserved
}; 

union  ADCTRL3_REG {
   Uint16                all;
   struct ADCTRL3_BITS   bit;
};


struct ADCST_BITS {           // bits   description
    Uint16   INT_SEQ1:1;      // 0      SEQ1 Interrupt flag  
    Uint16   INT_SEQ2:1;      // 1      SEQ2 Interrupt flag
    Uint16   SEQ1_BSY:1;      // 2      SEQ1 busy status
    Uint16   SEQ2_BSY:1;      // 3      SEQ2 busy status
    Uint16   INT_SEQ1_CLR:1;  // 4      SEQ1 Interrupt clear
    Uint16   INT_SEQ2_CLR:1;  // 5      SEQ2 Interrupt clear
    Uint16   EOS_BUF1:1;      // 6      End of sequence buffer1
    Uint16   EOS_BUF2:1;      // 7      End of sequence buffer2
    Uint16   rsvd1:8;         // 15:8   reserved
};

                             
union  ADCST_REG {            
   Uint16             all;    
   struct ADCST_BITS  bit;    
};                           

struct ADCREFSEL_BITS {       // bits   description
	Uint16   rsvd1:14;        // 13:0   reserved  
	Uint16   REF_SEL:2;       // 15:14  Reference select
};
union ADCREFSEL_REG {
	Uint16		all;
	struct ADCREFSEL_BITS bit;
};

struct ADCOFFTRIM_BITS{       // bits   description
	int16	OFFSET_TRIM:9;    // 8:0    Offset Trim  
	Uint16	rsvd1:7;          // 15:9   reserved
};

union ADCOFFTRIM_REG{
	Uint16		all;
	struct ADCOFFTRIM_BITS bit;
};
struct ADC_REGS {
    union ADCTRL1_REG      ADCTRL1;       // ADC Control 1
    union ADCTRL2_REG      ADCTRL2;       // ADC Control 2
    union ADCMAXCONV_REG   ADCMAXCONV;    // Max conversions
    union ADCCHSELSEQ1_REG ADCCHSELSEQ1;  // Channel select sequencing control 1
    union ADCCHSELSEQ2_REG ADCCHSELSEQ2;  // Channel select sequencing control 2
    union ADCCHSELSEQ3_REG ADCCHSELSEQ3;  // Channel select sequencing control 3
    union ADCCHSELSEQ4_REG ADCCHSELSEQ4;  // Channel select sequencing control 4
    union ADCASEQSR_REG    ADCASEQSR;     // Autosequence status register
    Uint16                 ADCRESULT0;    // Conversion Result Buffer 0
    Uint16                 ADCRESULT1;    // Conversion Result Buffer 1
    Uint16                 ADCRESULT2;    // Conversion Result Buffer 2
    Uint16                 ADCRESULT3;    // Conversion Result Buffer 3
    Uint16                 ADCRESULT4;    // Conversion Result Buffer 4
    Uint16                 ADCRESULT5;    // Conversion Result Buffer 5
    Uint16                 ADCRESULT6;    // Conversion Result Buffer 6
    Uint16                 ADCRESULT7;    // Conversion Result Buffer 7
    Uint16                 ADCRESULT8;    // Conversion Result Buffer 8
    Uint16                 ADCRESULT9;    // Conversion Result Buffer 9
    Uint16                 ADCRESULT10;   // Conversion Result Buffer 10
    Uint16                 ADCRESULT11;   // Conversion Result Buffer 11
    Uint16                 ADCRESULT12;   // Conversion Result Buffer 12
    Uint16                 ADCRESULT13;   // Conversion Result Buffer 13
    Uint16                 ADCRESULT14;   // Conversion Result Buffer 14
    Uint16                 ADCRESULT15;   // Conversion Result Buffer 15
    union ADCTRL3_REG      ADCTRL3;       // ADC Control 3  
    union ADCST_REG        ADCST;         // ADC Status Register
    Uint16				   rsvd1;
    Uint16                 rsvd2;
    union ADCREFSEL_REG    ADCREFSEL;     // Reference Select Register
    union ADCOFFTRIM_REG   ADCOFFTRIM;    // Offset Trim Register
};


struct ADC_RESULT_MIRROR_REGS
{
    Uint16                 ADCRESULT0;    // Conversion Result Buffer 0
    Uint16                 ADCRESULT1;    // Conversion Result Buffer 1
    Uint16                 ADCRESULT2;    // Conversion Result Buffer 2
    Uint16                 ADCRESULT3;    // Conversion Result Buffer 3
    Uint16                 ADCRESULT4;    // Conversion Result Buffer 4
    Uint16                 ADCRESULT5;    // Conversion Result Buffer 5
    Uint16                 ADCRESULT6;    // Conversion Result Buffer 6
    Uint16                 ADCRESULT7;    // Conversion Result Buffer 7
    Uint16                 ADCRESULT8;    // Conversion Result Buffer 8
    Uint16                 ADCRESULT9;    // Conversion Result Buffer 9
    Uint16                 ADCRESULT10;   // Conversion Result Buffer 10
    Uint16                 ADCRESULT11;   // Conversion Result Buffer 11
    Uint16                 ADCRESULT12;   // Conversion Result Buffer 12
    Uint16                 ADCRESULT13;   // Conversion Result Buffer 13
    Uint16                 ADCRESULT14;   // Conversion Result Buffer 14
    Uint16                 ADCRESULT15;   // Conversion Result Buffer 15
};

//---------------------------------------------------------------------------
// ADC External References & Function Declarations:
//
extern volatile struct ADC_REGS AdcRegs;
extern volatile struct ADC_RESULT_MIRROR_REGS AdcMirror;


#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of DSP280x_ADC_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_ECan.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:31:37 $
//###########################################################################
//
// FILE:   DSP280x_ECan.h
//
// TITLE:  DSP280x Device eCAN Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_ECAN_H
#define DSP280x_ECAN_H


#ifdef __cplusplus
extern "C" {
#endif


/* --------------------------------------------------- */
/* eCAN Control & Status Registers                     */
/* ----------------------------------------------------*/

/* eCAN Mailbox enable register (CANME) bit definitions */
struct  CANME_BITS {      // bit  description
   Uint16      ME0:1;     // 0   Enable Mailbox 0
   Uint16      ME1:1;     // 1   Enable Mailbox 1
   Uint16      ME2:1;     // 2   Enable Mailbox 2
   Uint16      ME3:1;     // 3   Enable Mailbox 3
   Uint16      ME4:1;     // 4   Enable Mailbox 4
   Uint16      ME5:1;     // 5   Enable Mailbox 5
   Uint16      ME6:1;     // 6   Enable Mailbox 6
   Uint16      ME7:1;     // 7   Enable Mailbox 7
   Uint16      ME8:1;     // 8   Enable Mailbox 8
   Uint16      ME9:1;     // 9   Enable Mailbox 9
   Uint16      ME10:1;    // 10  Enable Mailbox 10
   Uint16      ME11:1;    // 11  Enable Mailbox 11
   Uint16      ME12:1;    // 12  Enable Mailbox 12
   Uint16      ME13:1;    // 13  Enable Mailbox 13
   Uint16      ME14:1;    // 14  Enable Mailbox 14
   Uint16      ME15:1;    // 15  Enable Mailbox 15
   Uint16      ME16:1;    // 16  Enable Mailbox 16
   Uint16      ME17:1;    // 17  Enable Mailbox 17
   Uint16      ME18:1;    // 18  Enable Mailbox 18
   Uint16      ME19:1;    // 19  Enable Mailbox 19
   Uint16      ME20:1;    // 20  Enable Mailbox 20
   Uint16      ME21:1;    // 21  Enable Mailbox 21
   Uint16      ME22:1;    // 22  Enable Mailbox 22
   Uint16      ME23:1;    // 23  Enable Mailbox 23
   Uint16      ME24:1;    // 24  Enable Mailbox 24
   Uint16      ME25:1;    // 25  Enable Mailbox 25
   Uint16      ME26:1;    // 26  Enable Mailbox 26
   Uint16      ME27:1;    // 27  Enable Mailbox 27
   Uint16      ME28:1;    // 28  Enable Mailbox 28
   Uint16      ME29:1;    // 29  Enable Mailbox 29
   Uint16      ME30:1;    // 30  Enable Mailbox 30
   Uint16      ME31:1;    // 31  Enable Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANME_REG {
   Uint32             all;
   struct CANME_BITS  bit;
};

/* eCAN Mailbox direction register (CANMD) bit definitions */
struct  CANMD_BITS {      // bit  description
   Uint16      MD0:1;     // 0   0 -> Tx 1 -> Rx
   Uint16      MD1:1;     // 1   0 -> Tx 1 -> Rx
   Uint16      MD2:1;     // 2   0 -> Tx 1 -> Rx
   Uint16      MD3:1;     // 3   0 -> Tx 1 -> Rx
   Uint16      MD4:1;     // 4   0 -> Tx 1 -> Rx
   Uint16      MD5:1;     // 5   0 -> Tx 1 -> Rx
   Uint16      MD6:1;     // 6   0 -> Tx 1 -> Rx
   Uint16      MD7:1;     // 7   0 -> Tx 1 -> Rx
   Uint16      MD8:1;     // 8   0 -> Tx 1 -> Rx
   Uint16      MD9:1;     // 9   0 -> Tx 1 -> Rx
   Uint16      MD10:1;    // 10  0 -> Tx 1 -> Rx
   Uint16      MD11:1;    // 11  0 -> Tx 1 -> Rx
   Uint16      MD12:1;    // 12  0 -> Tx 1 -> Rx
   Uint16      MD13:1;    // 13  0 -> Tx 1 -> Rx
   Uint16      MD14:1;    // 14  0 -> Tx 1 -> Rx
   Uint16      MD15:1;    // 15  0 -> Tx 1 -> Rx
   Uint16      MD16:1;    // 16  0 -> Tx 1 -> Rx
   Uint16      MD17:1;    // 17  0 -> Tx 1 -> Rx
   Uint16      MD18:1;    // 18  0 -> Tx 1 -> Rx
   Uint16      MD19:1;    // 19  0 -> Tx 1 -> Rx
   Uint16      MD20:1;    // 20  0 -> Tx 1 -> Rx
   Uint16      MD21:1;    // 21  0 -> Tx 1 -> Rx
   Uint16      MD22:1;    // 22  0 -> Tx 1 -> Rx
   Uint16      MD23:1;    // 23  0 -> Tx 1 -> Rx
   Uint16      MD24:1;    // 24  0 -> Tx 1 -> Rx
   Uint16      MD25:1;    // 25  0 -> Tx 1 -> Rx
   Uint16      MD26:1;    // 26  0 -> Tx 1 -> Rx
   Uint16      MD27:1;    // 27  0 -> Tx 1 -> Rx
   Uint16      MD28:1;    // 28  0 -> Tx 1 -> Rx
   Uint16      MD29:1;    // 29  0 -> Tx 1 -> Rx
   Uint16      MD30:1;    // 30  0 -> Tx 1 -> Rx
   Uint16      MD31:1;    // 31  0 -> Tx 1 -> Rx

};

/* Allow access to the bit fields or entire register */
union CANMD_REG {
   Uint32             all;
   struct CANMD_BITS  bit;
};

/* eCAN Transmit Request Set register (CANTRS) bit definitions */
struct  CANTRS_BITS {      // bit  description
   Uint16      TRS0:1;     // 0   TRS for Mailbox 0
   Uint16      TRS1:1;     // 1   TRS for Mailbox 1
   Uint16      TRS2:1;     // 2   TRS for Mailbox 2
   Uint16      TRS3:1;     // 3   TRS for Mailbox 3
   Uint16      TRS4:1;     // 4   TRS for Mailbox 4
   Uint16      TRS5:1;     // 5   TRS for Mailbox 5
   Uint16      TRS6:1;     // 6   TRS for Mailbox 6
   Uint16      TRS7:1;     // 7   TRS for Mailbox 7
   Uint16      TRS8:1;     // 8   TRS for Mailbox 8
   Uint16      TRS9:1;     // 9   TRS for Mailbox 9
   Uint16      TRS10:1;    // 10  TRS for Mailbox 10
   Uint16      TRS11:1;    // 11  TRS for Mailbox 11
   Uint16      TRS12:1;    // 12  TRS for Mailbox 12
   Uint16      TRS13:1;    // 13  TRS for Mailbox 13
   Uint16      TRS14:1;    // 14  TRS for Mailbox 14
   Uint16      TRS15:1;    // 15  TRS for Mailbox 15
   Uint16      TRS16:1;    // 16  TRS for Mailbox 16
   Uint16      TRS17:1;    // 17  TRS for Mailbox 17
   Uint16      TRS18:1;    // 18  TRS for Mailbox 18
   Uint16      TRS19:1;    // 19  TRS for Mailbox 19
   Uint16      TRS20:1;    // 20  TRS for Mailbox 20
   Uint16      TRS21:1;    // 21  TRS for Mailbox 21
   Uint16      TRS22:1;    // 22  TRS for Mailbox 22
   Uint16      TRS23:1;    // 23  TRS for Mailbox 23
   Uint16      TRS24:1;    // 24  TRS for Mailbox 24
   Uint16      TRS25:1;    // 25  TRS for Mailbox 25
   Uint16      TRS26:1;    // 26  TRS for Mailbox 26
   Uint16      TRS27:1;    // 27  TRS for Mailbox 27
   Uint16      TRS28:1;    // 28  TRS for Mailbox 28
   Uint16      TRS29:1;    // 29  TRS for Mailbox 29
   Uint16      TRS30:1;    // 30  TRS for Mailbox 30
   Uint16      TRS31:1;    // 31  TRS for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTRS_REG {
   Uint32              all;
   struct CANTRS_BITS  bit;
};

/* eCAN Transmit Request Reset register (CANTRR) bit definitions */
struct  CANTRR_BITS {      // bit  description
   Uint16      TRR0:1;     // 0   TRR for Mailbox 0
   Uint16      TRR1:1;     // 1   TRR for Mailbox 1
   Uint16      TRR2:1;     // 2   TRR for Mailbox 2
   Uint16      TRR3:1;     // 3   TRR for Mailbox 3
   Uint16      TRR4:1;     // 4   TRR for Mailbox 4
   Uint16      TRR5:1;     // 5   TRR for Mailbox 5
   Uint16      TRR6:1;     // 6   TRR for Mailbox 6
   Uint16      TRR7:1;     // 7   TRR for Mailbox 7
   Uint16      TRR8:1;     // 8   TRR for Mailbox 8
   Uint16      TRR9:1;     // 9   TRR for Mailbox 9
   Uint16      TRR10:1;    // 10  TRR for Mailbox 10
   Uint16      TRR11:1;    // 11  TRR for Mailbox 11
   Uint16      TRR12:1;    // 12  TRR for Mailbox 12
   Uint16      TRR13:1;    // 13  TRR for Mailbox 13
   Uint16      TRR14:1;    // 14  TRR for Mailbox 14
   Uint16      TRR15:1;    // 15  TRR for Mailbox 15
   Uint16      TRR16:1;    // 16  TRR for Mailbox 16
   Uint16      TRR17:1;    // 17  TRR for Mailbox 17
   Uint16      TRR18:1;    // 18  TRR for Mailbox 18
   Uint16      TRR19:1;    // 19  TRR for Mailbox 19
   Uint16      TRR20:1;    // 20  TRR for Mailbox 20
   Uint16      TRR21:1;    // 21  TRR for Mailbox 21
   Uint16      TRR22:1;    // 22  TRR for Mailbox 22
   Uint16      TRR23:1;    // 23  TRR for Mailbox 23
   Uint16      TRR24:1;    // 24  TRR for Mailbox 24
   Uint16      TRR25:1;    // 25  TRR for Mailbox 25
   Uint16      TRR26:1;    // 26  TRR for Mailbox 26
   Uint16      TRR27:1;    // 27  TRR for Mailbox 27
   Uint16      TRR28:1;    // 28  TRR for Mailbox 28
   Uint16      TRR29:1;    // 29  TRR for Mailbox 29
   Uint16      TRR30:1;    // 30  TRR for Mailbox 30
   Uint16      TRR31:1;    // 31  TRR for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTRR_REG {
   Uint32              all;
   struct CANTRR_BITS  bit;
};

/* eCAN Transmit Acknowledge register (CANTA) bit definitions */
struct  CANTA_BITS {      // bit  description
   Uint16      TA0:1;     // 0   TA for Mailbox 0
   Uint16      TA1:1;     // 1   TA for Mailbox 1
   Uint16      TA2:1;     // 2   TA for Mailbox 2
   Uint16      TA3:1;     // 3   TA for Mailbox 3
   Uint16      TA4:1;     // 4   TA for Mailbox 4
   Uint16      TA5:1;     // 5   TA for Mailbox 5
   Uint16      TA6:1;     // 6   TA for Mailbox 6
   Uint16      TA7:1;     // 7   TA for Mailbox 7
   Uint16      TA8:1;     // 8   TA for Mailbox 8
   Uint16      TA9:1;     // 9   TA for Mailbox 9
   Uint16      TA10:1;    // 10  TA for Mailbox 10
   Uint16      TA11:1;    // 11  TA for Mailbox 11
   Uint16      TA12:1;    // 12  TA for Mailbox 12
   Uint16      TA13:1;    // 13  TA for Mailbox 13
   Uint16      TA14:1;    // 14  TA for Mailbox 14
   Uint16      TA15:1;    // 15  TA for Mailbox 15
   Uint16      TA16:1;    // 16  TA for Mailbox 16
   Uint16      TA17:1;    // 17  TA for Mailbox 17
   Uint16      TA18:1;    // 18  TA for Mailbox 18
   Uint16      TA19:1;    // 19  TA for Mailbox 19
   Uint16      TA20:1;    // 20  TA for Mailbox 20
   Uint16      TA21:1;    // 21  TA for Mailbox 21
   Uint16      TA22:1;    // 22  TA for Mailbox 22
   Uint16      TA23:1;    // 23  TA for Mailbox 23
   Uint16      TA24:1;    // 24  TA for Mailbox 24
   Uint16      TA25:1;    // 25  TA for Mailbox 25
   Uint16      TA26:1;    // 26  TA for Mailbox 26
   Uint16      TA27:1;    // 27  TA for Mailbox 27
   Uint16      TA28:1;    // 28  TA for Mailbox 28
   Uint16      TA29:1;    // 29  TA for Mailbox 29
   Uint16      TA30:1;    // 30  TA for Mailbox 30
   Uint16      TA31:1;    // 31  TA for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTA_REG {
   Uint32             all;
   struct CANTA_BITS  bit;
};

/* eCAN Transmit Abort Acknowledge register (CANAA) bit definitions */
struct  CANAA_BITS {      // bit  description
   Uint16      AA0:1;     // 0   AA for Mailbox 0
   Uint16      AA1:1;     // 1   AA for Mailbox 1
   Uint16      AA2:1;     // 2   AA for Mailbox 2
   Uint16      AA3:1;     // 3   AA for Mailbox 3
   Uint16      AA4:1;     // 4   AA for Mailbox 4
   Uint16      AA5:1;     // 5   AA for Mailbox 5
   Uint16      AA6:1;     // 6   AA for Mailbox 6
   Uint16      AA7:1;     // 7   AA for Mailbox 7
   Uint16      AA8:1;     // 8   AA for Mailbox 8
   Uint16      AA9:1;     // 9   AA for Mailbox 9
   Uint16      AA10:1;    // 10  AA for Mailbox 10
   Uint16      AA11:1;    // 11  AA for Mailbox 11
   Uint16      AA12:1;    // 12  AA for Mailbox 12
   Uint16      AA13:1;    // 13  AA for Mailbox 13
   Uint16      AA14:1;    // 14  AA for Mailbox 14
   Uint16      AA15:1;    // 15  AA for Mailbox 15
   Uint16      AA16:1;    // 16  AA for Mailbox 16
   Uint16      AA17:1;    // 17  AA for Mailbox 17
   Uint16      AA18:1;    // 18  AA for Mailbox 18
   Uint16      AA19:1;    // 19  AA for Mailbox 19
   Uint16      AA20:1;    // 20  AA for Mailbox 20
   Uint16      AA21:1;    // 21  AA for Mailbox 21
   Uint16      AA22:1;    // 22  AA for Mailbox 22
   Uint16      AA23:1;    // 23  AA for Mailbox 23
   Uint16      AA24:1;    // 24  AA for Mailbox 24
   Uint16      AA25:1;    // 25  AA for Mailbox 25
   Uint16      AA26:1;    // 26  AA for Mailbox 26
   Uint16      AA27:1;    // 27  AA for Mailbox 27
   Uint16      AA28:1;    // 28  AA for Mailbox 28
   Uint16      AA29:1;    // 29  AA for Mailbox 29
   Uint16      AA30:1;    // 30  AA for Mailbox 30
   Uint16      AA31:1;    // 31  AA for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANAA_REG {
   Uint32             all;
   struct CANAA_BITS  bit;
};

/* eCAN Received Message Pending register (CANRMP) bit definitions */
struct  CANRMP_BITS {      // bit  description
   Uint16      RMP0:1;     // 0   RMP for Mailbox 0
   Uint16      RMP1:1;     // 1   RMP for Mailbox 1
   Uint16      RMP2:1;     // 2   RMP for Mailbox 2
   Uint16      RMP3:1;     // 3   RMP for Mailbox 3
   Uint16      RMP4:1;     // 4   RMP for Mailbox 4
   Uint16      RMP5:1;     // 5   RMP for Mailbox 5
   Uint16      RMP6:1;     // 6   RMP for Mailbox 6
   Uint16      RMP7:1;     // 7   RMP for Mailbox 7
   Uint16      RMP8:1;     // 8   RMP for Mailbox 8
   Uint16      RMP9:1;     // 9   RMP for Mailbox 9
   Uint16      RMP10:1;    // 10  RMP for Mailbox 10
   Uint16      RMP11:1;    // 11  RMP for Mailbox 11
   Uint16      RMP12:1;    // 12  RMP for Mailbox 12
   Uint16      RMP13:1;    // 13  RMP for Mailbox 13
   Uint16      RMP14:1;    // 14  RMP for Mailbox 14
   Uint16      RMP15:1;    // 15  RMP for Mailbox 15
   Uint16      RMP16:1;    // 16  RMP for Mailbox 16
   Uint16      RMP17:1;    // 17  RMP for Mailbox 17
   Uint16      RMP18:1;    // 18  RMP for Mailbox 18
   Uint16      RMP19:1;    // 19  RMP for Mailbox 19
   Uint16      RMP20:1;    // 20  RMP for Mailbox 20
   Uint16      RMP21:1;    // 21  RMP for Mailbox 21
   Uint16      RMP22:1;    // 22  RMP for Mailbox 22
   Uint16      RMP23:1;    // 23  RMP for Mailbox 23
   Uint16      RMP24:1;    // 24  RMP for Mailbox 24
   Uint16      RMP25:1;    // 25  RMP for Mailbox 25
   Uint16      RMP26:1;    // 26  RMP for Mailbox 26
   Uint16      RMP27:1;    // 27  RMP for Mailbox 27
   Uint16      RMP28:1;    // 28  RMP for Mailbox 28
   Uint16      RMP29:1;    // 29  RMP for Mailbox 29
   Uint16      RMP30:1;    // 30  RMP for Mailbox 30
   Uint16      RMP31:1;    // 31  RMP for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANRMP_REG {
   Uint32              all;
   struct CANRMP_BITS  bit;
};

/* eCAN Received Message Lost register (CANRML) bit definitions */
struct  CANRML_BITS {      // bit  description
   Uint16      RML0:1;     // 0   RML for Mailbox 0
   Uint16      RML1:1;     // 1   RML for Mailbox 1
   Uint16      RML2:1;     // 2   RML for Mailbox 2
   Uint16      RML3:1;     // 3   RML for Mailbox 3
   Uint16      RML4:1;     // 4   RML for Mailbox 4
   Uint16      RML5:1;     // 5   RML for Mailbox 5
   Uint16      RML6:1;     // 6   RML for Mailbox 6
   Uint16      RML7:1;     // 7   RML for Mailbox 7
   Uint16      RML8:1;     // 8   RML for Mailbox 8
   Uint16      RML9:1;     // 9   RML for Mailbox 9
   Uint16      RML10:1;    // 10  RML for Mailbox 10
   Uint16      RML11:1;    // 11  RML for Mailbox 11
   Uint16      RML12:1;    // 12  RML for Mailbox 12
   Uint16      RML13:1;    // 13  RML for Mailbox 13
   Uint16      RML14:1;    // 14  RML for Mailbox 14
   Uint16      RML15:1;    // 15  RML for Mailbox 15
   Uint16      RML16:1;    // 16  RML for Mailbox 16
   Uint16      RML17:1;    // 17  RML for Mailbox 17
   Uint16      RML18:1;    // 18  RML for Mailbox 18
   Uint16      RML19:1;    // 19  RML for Mailbox 19
   Uint16      RML20:1;    // 20  RML for Mailbox 20
   Uint16      RML21:1;    // 21  RML for Mailbox 21
   Uint16      RML22:1;    // 22  RML for Mailbox 22
   Uint16      RML23:1;    // 23  RML for Mailbox 23
   Uint16      RML24:1;    // 24  RML for Mailbox 24
   Uint16      RML25:1;    // 25  RML for Mailbox 25
   Uint16      RML26:1;    // 26  RML for Mailbox 26
   Uint16      RML27:1;    // 27  RML for Mailbox 27
   Uint16      RML28:1;    // 28  RML for Mailbox 28
   Uint16      RML29:1;    // 29  RML for Mailbox 29
   Uint16      RML30:1;    // 30  RML for Mailbox 30
   Uint16      RML31:1;    // 31  RML for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANRML_REG {
   Uint32              all;
   struct CANRML_BITS  bit;
};

/* eCAN Remote Frame Pending register (CANRFP) bit definitions */
struct  CANRFP_BITS {      // bit  description
   Uint16      RFP0:1;     // 0   RFP for Mailbox 0
   Uint16      RFP1:1;     // 1   RFP for Mailbox 1
   Uint16      RFP2:1;     // 2   RFP for Mailbox 2
   Uint16      RFP3:1;     // 3   RFP for Mailbox 3
   Uint16      RFP4:1;     // 4   RFP for Mailbox 4
   Uint16      RFP5:1;     // 5   RFP for Mailbox 5
   Uint16      RFP6:1;     // 6   RFP for Mailbox 6
   Uint16      RFP7:1;     // 7   RFP for Mailbox 7
   Uint16      RFP8:1;     // 8   RFP for Mailbox 8
   Uint16      RFP9:1;     // 9   RFP for Mailbox 9
   Uint16      RFP10:1;    // 10  RFP for Mailbox 10
   Uint16      RFP11:1;    // 11  RFP for Mailbox 11
   Uint16      RFP12:1;    // 12  RFP for Mailbox 12
   Uint16      RFP13:1;    // 13  RFP for Mailbox 13
   Uint16      RFP14:1;    // 14  RFP for Mailbox 14
   Uint16      RFP15:1;    // 15  RFP for Mailbox 15
   Uint16      RFP16:1;    // 16  RFP for Mailbox 16
   Uint16      RFP17:1;    // 17  RFP for Mailbox 17
   Uint16      RFP18:1;    // 18  RFP for Mailbox 18
   Uint16      RFP19:1;    // 19  RFP for Mailbox 19
   Uint16      RFP20:1;    // 20  RFP for Mailbox 20
   Uint16      RFP21:1;    // 21  RFP for Mailbox 21
   Uint16      RFP22:1;    // 22  RFP for Mailbox 22
   Uint16      RFP23:1;    // 23  RFP for Mailbox 23
   Uint16      RFP24:1;    // 24  RFP for Mailbox 24
   Uint16      RFP25:1;    // 25  RFP for Mailbox 25
   Uint16      RFP26:1;    // 26  RFP for Mailbox 26
   Uint16      RFP27:1;    // 27  RFP for Mailbox 27
   Uint16      RFP28:1;    // 28  RFP for Mailbox 28
   Uint16      RFP29:1;    // 29  RFP for Mailbox 29
   Uint16      RFP30:1;    // 30  RFP for Mailbox 30
   Uint16      RFP31:1;    // 31  RFP for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANRFP_REG {
   Uint32              all;
   struct CANRFP_BITS  bit;
};

/* eCAN Global Acceptance Mask register (CANGAM) bit definitions */
struct  CANGAM_BITS {   // bits  description
   Uint16 GAM150:16;    // 15:0  Global acceptance mask bits 0-15
   Uint16 GAM2816:13;   // 28:16 Global acceptance mask bits 16-28    
   Uint16 rsvd:2;       // 30:29 reserved        
   Uint16 AMI:1;        // 31    AMI bit
};

/* Allow access to the bit fields or entire register */
union CANGAM_REG {
   Uint32              all;
   struct CANGAM_BITS  bit;
};


/* eCAN Master Control register (CANMC) bit definitions */
struct  CANMC_BITS {       // bits  description
   Uint16      MBNR:5;     // 4:0   MBX # for CDR bit
   Uint16      SRES:1;     // 5     Soft reset
   Uint16      STM:1;      // 6     Self-test mode
   Uint16      ABO:1;      // 7     Auto bus-on
   Uint16      CDR:1;      // 8     Change data request
   Uint16      WUBA:1;     // 9     Wake-up on bus activity
   Uint16      DBO:1;      // 10    Data-byte order
   Uint16      PDR:1;      // 11    Power-down mode request
   Uint16      CCR:1;      // 12    Change configuration request
   Uint16      SCB:1;      // 13    SCC compatibility bit      
   Uint16      TCC:1;      // 14    TSC MSB clear bit
   Uint16      MBCC:1;     // 15    TSC clear bit thru mailbox 16      
   Uint16      SUSP:1;     // 16    SUSPEND free/soft bit
   Uint16      rsvd:15;    // 31:17  reserved   
};

/* Allow access to the bit fields or entire register */
union CANMC_REG {
   Uint32             all;
   struct CANMC_BITS  bit;
};

/* eCAN Bit -timing configuration register (CANBTC) bit definitions */
struct  CANBTC_BITS {  // bits  description
   Uint16  TSEG2REG:3; // 2:0   TSEG2 register value
   Uint16  TSEG1REG:4; // 6:3   TSEG1 register value
   Uint16  SAM:1;      // 7     Sample-point setting
   Uint16  SJWREG:2;   // 9:8   Synchroniztion Jump Width register value
   Uint16  rsvd1:6;    // 15:10 reserved   
   Uint16  BRPREG:8;   // 23:16 Baudrate prescaler register value
   Uint16  rsvd2:8;    // 31:24 reserved   
};

/* Allow access to the bit fields or entire register */
union CANBTC_REG {
   Uint32              all;
   struct CANBTC_BITS  bit;
};

/* eCAN Error & Status register (CANES) bit definitions */
struct  CANES_BITS {    // bits  description
   Uint16   TM:1;       // 0     Transmit Mode
   Uint16   RM:1;       // 1     Receive Mode
   Uint16   rsvd1:1;    // 2     reserved   
   Uint16   PDA:1;      // 3     Power-down acknowledge
   Uint16   CCE:1;      // 4     Change Configuration Enable
   Uint16   SMA:1;      // 5     Suspend Mode Acknowledge
   Uint16   rsvd2:10;   // 15:6  reserved   
   Uint16   EW:1;       // 16    Warning status
   Uint16   EP:1;       // 17    Error Passive status
   Uint16   BO:1;       // 18    Bus-off status
   Uint16   ACKE:1;     // 19    Acknowledge error
   Uint16   SE:1;       // 20    Stuff error
   Uint16   CRCE:1;     // 21    CRC error
   Uint16   SA1:1;      // 22    Stuck at Dominant error
   Uint16   BE:1;       // 23    Bit error
   Uint16   FE:1;       // 24    Framing error
   Uint16   rsvd3:7;    // 31:25 reserved   
};

/* Allow access to the bit fields or entire register */
union CANES_REG {
   Uint32             all;
   struct CANES_BITS  bit;
};


/* eCAN Transmit Error Counter register (CANTEC) bit definitions */
struct  CANTEC_BITS {  // bits  description
   Uint16 TEC:8;       // 7:0   TEC
   Uint16 rsvd1:8;     // 15:8  reserved
   Uint16 rsvd2:16;    // 31:16  reserved      
};

/* Allow access to the bit fields or entire register */
union CANTEC_REG {
   Uint32              all;
   struct CANTEC_BITS  bit;
};

/* eCAN Receive Error Counter register (CANREC) bit definitions */
struct  CANREC_BITS {  // bits  description
   Uint16 REC:8;       // 7:0   REC
   Uint16 rsvd1:8;     // 15:8  reserved
   Uint16 rsvd2:16;    // 31:16 reserved      
};

/* Allow access to the bit fields or entire register */
union CANREC_REG {
   Uint32              all;
   struct CANREC_BITS  bit;
};

/* eCAN Global Interrupt Flag 0 (CANGIF0) bit definitions */
struct  CANGIF0_BITS {  // bits  description
   Uint16   MIV0:5;     // 4:0   Mailbox Interrupt Vector
   Uint16   rsvd1:3;    // 7:5   reserved   
   Uint16   WLIF0:1;    // 8     Warning level interrupt flag
   Uint16   EPIF0:1;    // 9     Error-passive interrupt flag
   Uint16   BOIF0:1;    // 10    Bus-off interrupt flag
   Uint16   RMLIF0:1;   // 11    Received message lost interrupt flag
   Uint16   WUIF0:1;    // 12    Wakeup interrupt flag
   Uint16   WDIF0:1;    // 13    Write denied interrupt flag
   Uint16   AAIF0:1;    // 14    Abort Ack interrupt flag
   Uint16   GMIF0:1;    // 15    Global MBX interrupt flag
   Uint16   TCOF0:1;    // 16    TSC Overflow flag
   Uint16   MTOF0:1;    // 17    Mailbox Timeout flag
   Uint16   rsvd2:14;   // 31:18 reserved   
};

/* Allow access to the bit fields or entire register */
union CANGIF0_REG {
   Uint32               all;
   struct CANGIF0_BITS  bit;
};

/* eCAN Global Interrupt Mask register (CANGIM) bit definitions */
struct  CANGIM_BITS { // bits  description
   Uint16  I0EN:1;    // 0      Interrupt 0 enable
   Uint16  I1EN:1;    // 1      Interrupt 1 enable
   Uint16  GIL:1;     // 2      Global Interrupt Level
   Uint16  rsvd1:5;   // 7:3    reserved   
   Uint16  WLIM:1;    // 8      Warning level interrupt mask 
   Uint16  EPIM:1;    // 9      Error-passive interrupt mask
   Uint16  BOIM:1;    // 10     Bus-off interrupt mask
   Uint16  RMLIM:1;   // 11     Received message lost interrupt mask
   Uint16  WUIM:1;    // 12     Wakeup interrupt mask
   Uint16  WDIM:1;    // 13     Write denied interrupt mask
   Uint16  AAIM:1;    // 14     Abort Ack interrupt mask
   Uint16  rsvd2:1;   // 15     reserved 
   Uint16  TCOM:1;    // 16     TSC overflow interrupt mask
   Uint16  MTOM:1;    // 17     MBX Timeout interrupt mask
   Uint16  rsvd3:14;  // 31:18  reserved   
};

/* Allow access to the bit fields or entire register */
union CANGIM_REG {
   Uint32              all;
   struct CANGIM_BITS  bit;
};


/* eCAN Global Interrupt Flag 1 (eCANGIF1) bit definitions */
struct  CANGIF1_BITS {     // bits  description
   Uint16      MIV1:5;     // 4:0   Mailbox Interrupt Vector
   Uint16      rsvd1:3;    // 7:5   reserved   
   Uint16      WLIF1:1;    // 8     Warning level interrupt flag
   Uint16      EPIF1:1;    // 9     Error-passive interrupt flag
   Uint16      BOIF1:1;    // 10    Bus-off interrupt flag
   Uint16      RMLIF1:1;   // 11    Received message lost interrupt flag
   Uint16      WUIF1:1;    // 12    Wakeup interrupt flag
   Uint16      WDIF1:1;    // 13    Write denied interrupt flag
   Uint16      AAIF1:1;    // 14    Abort Ack interrupt flag
   Uint16      GMIF1:1;    // 15    Global MBX interrupt flag
   Uint16      TCOF1:1;    // 16    TSC Overflow flag
   Uint16      MTOF1:1;    // 17    Mailbox Timeout flag
   Uint16      rsvd2:14;   // 31:18 reserved   
};

/* Allow access to the bit fields or entire register */
union CANGIF1_REG {
   Uint32               all;
   struct CANGIF1_BITS  bit;
};


/* eCAN Mailbox Interrupt Mask register (CANMIM) bit definitions */
struct  CANMIM_BITS {      // bit  description
   Uint16      MIM0:1;     // 0   MIM for Mailbox 0
   Uint16      MIM1:1;     // 1   MIM for Mailbox 1
   Uint16      MIM2:1;     // 2   MIM for Mailbox 2
   Uint16      MIM3:1;     // 3   MIM for Mailbox 3
   Uint16      MIM4:1;     // 4   MIM for Mailbox 4
   Uint16      MIM5:1;     // 5   MIM for Mailbox 5
   Uint16      MIM6:1;     // 6   MIM for Mailbox 6
   Uint16      MIM7:1;     // 7   MIM for Mailbox 7
   Uint16      MIM8:1;     // 8   MIM for Mailbox 8
   Uint16      MIM9:1;     // 9   MIM for Mailbox 9
   Uint16      MIM10:1;    // 10  MIM for Mailbox 10
   Uint16      MIM11:1;    // 11  MIM for Mailbox 11
   Uint16      MIM12:1;    // 12  MIM for Mailbox 12
   Uint16      MIM13:1;    // 13  MIM for Mailbox 13
   Uint16      MIM14:1;    // 14  MIM for Mailbox 14
   Uint16      MIM15:1;    // 15  MIM for Mailbox 15
   Uint16      MIM16:1;    // 16  MIM for Mailbox 16
   Uint16      MIM17:1;    // 17  MIM for Mailbox 17
   Uint16      MIM18:1;    // 18  MIM for Mailbox 18
   Uint16      MIM19:1;    // 19  MIM for Mailbox 19
   Uint16      MIM20:1;    // 20  MIM for Mailbox 20
   Uint16      MIM21:1;    // 21  MIM for Mailbox 21
   Uint16      MIM22:1;    // 22  MIM for Mailbox 22
   Uint16      MIM23:1;    // 23  MIM for Mailbox 23
   Uint16      MIM24:1;    // 24  MIM for Mailbox 24
   Uint16      MIM25:1;    // 25  MIM for Mailbox 25
   Uint16      MIM26:1;    // 26  MIM for Mailbox 26
   Uint16      MIM27:1;    // 27  MIM for Mailbox 27
   Uint16      MIM28:1;    // 28  MIM for Mailbox 28
   Uint16      MIM29:1;    // 29  MIM for Mailbox 29
   Uint16      MIM30:1;    // 30  MIM for Mailbox 30
   Uint16      MIM31:1;    // 31  MIM for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANMIM_REG {
   Uint32              all;
   struct CANMIM_BITS  bit;
};

/* eCAN Mailbox Interrupt Level register (CANMIL) bit definitions */
struct  CANMIL_BITS {      // bit  description
   Uint16      MIL0:1;     // 0   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL1:1;     // 1   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL2:1;     // 2   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL3:1;     // 3   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL4:1;     // 4   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL5:1;     // 5   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL6:1;     // 6   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL7:1;     // 7   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL8:1;     // 8   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL9:1;     // 9   0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL10:1;    // 10  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL11:1;    // 11  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL12:1;    // 12  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL13:1;    // 13  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL14:1;    // 14  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL15:1;    // 15  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL16:1;    // 16  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL17:1;    // 17  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL18:1;    // 18  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL19:1;    // 19  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL20:1;    // 20  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL21:1;    // 21  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL22:1;    // 22  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL23:1;    // 23  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL24:1;    // 24  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL25:1;    // 25  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL26:1;    // 26  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL27:1;    // 27  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL28:1;    // 28  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL29:1;    // 29  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL30:1;    // 30  0 -> Int 9.5   1 -> Int 9.6
   Uint16      MIL31:1;    // 31  0 -> Int 9.5   1 -> Int 9.6

};

/* Allow access to the bit fields or entire register */
union CANMIL_REG {
   Uint32              all;
   struct CANMIL_BITS  bit;
};


/* eCAN Overwrite Protection Control register (CANOPC) bit definitions */
struct  CANOPC_BITS {      // bit  description
   Uint16      OPC0:1;     // 0   OPC for Mailbox 0
   Uint16      OPC1:1;     // 1   OPC for Mailbox 1
   Uint16      OPC2:1;     // 2   OPC for Mailbox 2
   Uint16      OPC3:1;     // 3   OPC for Mailbox 3
   Uint16      OPC4:1;     // 4   OPC for Mailbox 4
   Uint16      OPC5:1;     // 5   OPC for Mailbox 5
   Uint16      OPC6:1;     // 6   OPC for Mailbox 6
   Uint16      OPC7:1;     // 7   OPC for Mailbox 7
   Uint16      OPC8:1;     // 8   OPC for Mailbox 8
   Uint16      OPC9:1;     // 9   OPC for Mailbox 9
   Uint16      OPC10:1;    // 10  OPC for Mailbox 10
   Uint16      OPC11:1;    // 11  OPC for Mailbox 11
   Uint16      OPC12:1;    // 12  OPC for Mailbox 12
   Uint16      OPC13:1;    // 13  OPC for Mailbox 13
   Uint16      OPC14:1;    // 14  OPC for Mailbox 14
   Uint16      OPC15:1;    // 15  OPC for Mailbox 15
   Uint16      OPC16:1;    // 16  OPC for Mailbox 16
   Uint16      OPC17:1;    // 17  OPC for Mailbox 17
   Uint16      OPC18:1;    // 18  OPC for Mailbox 18
   Uint16      OPC19:1;    // 19  OPC for Mailbox 19
   Uint16      OPC20:1;    // 20  OPC for Mailbox 20
   Uint16      OPC21:1;    // 21  OPC for Mailbox 21
   Uint16      OPC22:1;    // 22  OPC for Mailbox 22
   Uint16      OPC23:1;    // 23  OPC for Mailbox 23
   Uint16      OPC24:1;    // 24  OPC for Mailbox 24
   Uint16      OPC25:1;    // 25  OPC for Mailbox 25
   Uint16      OPC26:1;    // 26  OPC for Mailbox 26
   Uint16      OPC27:1;    // 27  OPC for Mailbox 27
   Uint16      OPC28:1;    // 28  OPC for Mailbox 28
   Uint16      OPC29:1;    // 29  OPC for Mailbox 29
   Uint16      OPC30:1;    // 30  OPC for Mailbox 30
   Uint16      OPC31:1;    // 31  OPC for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANOPC_REG {
   Uint32              all;
   struct CANOPC_BITS  bit;
};


/* eCAN TX I/O Control Register (CANTIOC) bit definitions */
struct  CANTIOC_BITS { // bits  description
   Uint16  rsvd1:3;    // 2:0   reserved
   Uint16  TXFUNC:1;   // 3     TXFUNC
   Uint16  rsvd2:12;   // 15:4  reserved   
   Uint16  rsvd3:16;   // 31:16 reserved   
};

/* Allow access to the bit fields or entire register */
union CANTIOC_REG {
   Uint32               all;
   struct CANTIOC_BITS  bit;
};

/* eCAN RX I/O Control Register (CANRIOC) bit definitions */
struct  CANRIOC_BITS { // bits  description
   Uint16  rsvd1:3;    // 2:0   reserved
   Uint16  RXFUNC:1;   // 3     RXFUNC
   Uint16  rsvd2:12;   // 15:4  reserved   
   Uint16  rsvd3:16;   // 31:16 reserved   
};

/* Allow access to the bit fields or entire register */
union CANRIOC_REG {
   Uint32               all;
   struct CANRIOC_BITS  bit;
};


/* eCAN Time-out Control register (CANTOC) bit definitions */
struct  CANTOC_BITS {      // bit  description
   Uint16      TOC0:1;     // 0   TOC for Mailbox 0
   Uint16      TOC1:1;     // 1   TOC for Mailbox 1
   Uint16      TOC2:1;     // 2   TOC for Mailbox 2
   Uint16      TOC3:1;     // 3   TOC for Mailbox 3
   Uint16      TOC4:1;     // 4   TOC for Mailbox 4
   Uint16      TOC5:1;     // 5   TOC for Mailbox 5
   Uint16      TOC6:1;     // 6   TOC for Mailbox 6
   Uint16      TOC7:1;     // 7   TOC for Mailbox 7
   Uint16      TOC8:1;     // 8   TOC for Mailbox 8
   Uint16      TOC9:1;     // 9   TOC for Mailbox 9
   Uint16      TOC10:1;    // 10  TOC for Mailbox 10
   Uint16      TOC11:1;    // 11  TOC for Mailbox 11
   Uint16      TOC12:1;    // 12  TOC for Mailbox 12
   Uint16      TOC13:1;    // 13  TOC for Mailbox 13
   Uint16      TOC14:1;    // 14  TOC for Mailbox 14
   Uint16      TOC15:1;    // 15  TOC for Mailbox 15
   Uint16      TOC16:1;    // 16  TOC for Mailbox 16
   Uint16      TOC17:1;    // 17  TOC for Mailbox 17
   Uint16      TOC18:1;    // 18  TOC for Mailbox 18
   Uint16      TOC19:1;    // 19  TOC for Mailbox 19
   Uint16      TOC20:1;    // 20  TOC for Mailbox 20
   Uint16      TOC21:1;    // 21  TOC for Mailbox 21
   Uint16      TOC22:1;    // 22  TOC for Mailbox 22
   Uint16      TOC23:1;    // 23  TOC for Mailbox 23
   Uint16      TOC24:1;    // 24  TOC for Mailbox 24
   Uint16      TOC25:1;    // 25  TOC for Mailbox 25
   Uint16      TOC26:1;    // 26  TOC for Mailbox 26
   Uint16      TOC27:1;    // 27  TOC for Mailbox 27
   Uint16      TOC28:1;    // 28  TOC for Mailbox 28
   Uint16      TOC29:1;    // 29  TOC for Mailbox 29
   Uint16      TOC30:1;    // 30  TOC for Mailbox 30
   Uint16      TOC31:1;    // 31  TOC for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTOC_REG {
   Uint32              all;
   struct CANTOC_BITS  bit;
};


/* eCAN Time-out Status register (CANTOS) bit definitions */
struct  CANTOS_BITS {            // bit  description
   Uint16      TOS0:1;     // 0   TOS for Mailbox 0
   Uint16      TOS1:1;     // 1   TOS for Mailbox 1
   Uint16      TOS2:1;     // 2   TOS for Mailbox 2
   Uint16      TOS3:1;     // 3   TOS for Mailbox 3
   Uint16      TOS4:1;     // 4   TOS for Mailbox 4
   Uint16      TOS5:1;     // 5   TOS for Mailbox 5
   Uint16      TOS6:1;     // 6   TOS for Mailbox 6
   Uint16      TOS7:1;     // 7   TOS for Mailbox 7
   Uint16      TOS8:1;     // 8   TOS for Mailbox 8
   Uint16      TOS9:1;     // 9   TOS for Mailbox 9
   Uint16      TOS10:1;    // 10  TOS for Mailbox 10
   Uint16      TOS11:1;    // 11  TOS for Mailbox 11
   Uint16      TOS12:1;    // 12  TOS for Mailbox 12
   Uint16      TOS13:1;    // 13  TOS for Mailbox 13
   Uint16      TOS14:1;    // 14  TOS for Mailbox 14
   Uint16      TOS15:1;    // 15  TOS for Mailbox 15
   Uint16      TOS16:1;    // 16  TOS for Mailbox 16
   Uint16      TOS17:1;    // 17  TOS for Mailbox 17
   Uint16      TOS18:1;    // 18  TOS for Mailbox 18
   Uint16      TOS19:1;    // 19  TOS for Mailbox 19
   Uint16      TOS20:1;    // 20  TOS for Mailbox 20
   Uint16      TOS21:1;    // 21  TOS for Mailbox 21
   Uint16      TOS22:1;    // 22  TOS for Mailbox 22
   Uint16      TOS23:1;    // 23  TOS for Mailbox 23
   Uint16      TOS24:1;    // 24  TOS for Mailbox 24
   Uint16      TOS25:1;    // 25  TOS for Mailbox 25
   Uint16      TOS26:1;    // 26  TOS for Mailbox 26
   Uint16      TOS27:1;    // 27  TOS for Mailbox 27
   Uint16      TOS28:1;    // 28  TOS for Mailbox 28
   Uint16      TOS29:1;    // 29  TOS for Mailbox 29
   Uint16      TOS30:1;    // 30  TOS for Mailbox 30
   Uint16      TOS31:1;    // 31  TOS for Mailbox 31

};

/* Allow access to the bit fields or entire register */
union CANTOS_REG {
   Uint32              all;
   struct CANTOS_BITS  bit;
};

/**************************************/
/* eCAN Control & Status register file */
/**************************************/

struct ECAN_REGS {
   union CANME_REG   CANME;          // Mailbox Enable
   union CANMD_REG   CANMD;          // Mailbox Direction
   union CANTRS_REG  CANTRS;         // Transmit Request Set
   union CANTRR_REG  CANTRR;         // Transmit Request Reset
   union CANTA_REG   CANTA;          // Transmit Acknowledge
   union CANAA_REG   CANAA;          // Abort Acknowledge
   union CANRMP_REG  CANRMP;         // Received Message Pending
   union CANRML_REG  CANRML;         // Received Message Lost
   union CANRFP_REG  CANRFP;         // Remote Frame Pending
   union CANGAM_REG  CANGAM;         // Global Acceptance Mask       
   union CANMC_REG   CANMC;          // Master Control
   union CANBTC_REG  CANBTC;         // Bit Timing
   union CANES_REG   CANES;          // Error Status
   union CANTEC_REG  CANTEC;         // Transmit Error Counter
   union CANREC_REG  CANREC;         // Receive Error Counter
   union CANGIF0_REG CANGIF0;        // Global Interrupt Flag 0
   union CANGIM_REG  CANGIM;         // Global Interrupt Mask 0
   union CANGIF1_REG CANGIF1;        // Global Interrupt Flag 1
   union CANMIM_REG  CANMIM;         // Mailbox Interrupt Mask
   union CANMIL_REG  CANMIL;         // Mailbox Interrupt Level
   union CANOPC_REG  CANOPC;         // Overwrite Protection Control
   union CANTIOC_REG CANTIOC;        // TX I/O Control
   union CANRIOC_REG CANRIOC;        // RX I/O Control
   Uint32            CANTSC;         // Time-stamp counter
   union CANTOC_REG  CANTOC;         // Time-out Control
   union CANTOS_REG  CANTOS;         // Time-out Status               
 
};

/* --------------------------------------------------- */
/* eCAN Mailbox Registers                               */
/* ----------------------------------------------------*/

/* eCAN Message ID (MSGID) bit definitions */
struct  CANMSGID_BITS {        // bits  description
   Uint16      EXTMSGID_L:16;  // 0:15
   Uint16      EXTMSGID_H:2;   // 16:17
   Uint16      STDMSGID:11;    // 18:28  
   Uint16      AAM:1;          // 29   
   Uint16      AME:1;          // 30
   Uint16      IDE:1;          // 31   
 
};

/* Allow access to the bit fields or entire register */ 
union CANMSGID_REG {
   Uint32                all;
   struct CANMSGID_BITS  bit;
};

/* eCAN Message Control Field (MSGCTRL) bit definitions */
struct  CANMSGCTRL_BITS {     // bits  description
   Uint16 DLC:4;          // 0:3  
   Uint16 RTR:1;          // 4  
   Uint16 rsvd1:3;        // 7:5   reserved   
   Uint16 TPL:5;          // 12:8  
   Uint16 rsvd2:3;        // 15:13 reserved 
   Uint16 rsvd3:16;       // 31:16 reserved     
};

/* Allow access to the bit fields or entire register */ 
union CANMSGCTRL_REG {
   Uint32                  all;
   struct CANMSGCTRL_BITS  bit;
};

/* eCAN Message Data Register low (MDR_L) word definitions */
struct  CANMDL_WORDS {      // bits  description
   Uint16      LOW_WORD:16; // 0:15  
   Uint16      HI_WORD:16;  // 31:16  
};

/* eCAN Message Data Register low (MDR_L) byte definitions */
struct  CANMDL_BYTES {      // bits   description
   Uint16      BYTE3:8;     // 31:24
   Uint16      BYTE2:8;     // 23:16
   Uint16      BYTE1:8;     // 15:8
   Uint16      BYTE0:8;     // 7:0             
};


/* Allow access to the bit fields or entire register */ 

union CANMDL_REG {
   Uint32                all;
   struct CANMDL_WORDS   word;
   struct CANMDL_BYTES   byte;      
};



/* eCAN Message Data Register high  (MDR_H) word definitions */
struct  CANMDH_WORDS {         // bits  description
   Uint16      LOW_WORD:16;    // 0:15  
   Uint16      HI_WORD:16;     // 31:16  
};

/* eCAN Message Data Register low (MDR_H) byte definitions */
struct  CANMDH_BYTES {      // bits   description
   Uint16      BYTE7:8;     // 63:56 
   Uint16      BYTE6:8;     // 55:48
   Uint16      BYTE5:8;     // 47:40    
   Uint16      BYTE4:8;     // 39:32    
};

/* Allow access to the bit fields or entire register */ 
union CANMDH_REG {
   Uint32                  all;
   struct CANMDH_WORDS     word;
   struct CANMDH_BYTES     byte;
};


struct MBOX {
   union CANMSGID_REG     MSGID;
   union CANMSGCTRL_REG   MSGCTRL;
   union CANMDL_REG       MDL;
   union CANMDH_REG       MDH;
};

/**************************************/
/*          eCAN Mailboxes             */
/**************************************/

struct ECAN_MBOXES {
   struct MBOX MBOX0;
   struct MBOX MBOX1;
   struct MBOX MBOX2;
   struct MBOX MBOX3;
   struct MBOX MBOX4;
   struct MBOX MBOX5;
   struct MBOX MBOX6;
   struct MBOX MBOX7;
   struct MBOX MBOX8;
   struct MBOX MBOX9;
   struct MBOX MBOX10;
   struct MBOX MBOX11;
   struct MBOX MBOX12;
   struct MBOX MBOX13;
   struct MBOX MBOX14;
   struct MBOX MBOX15;
   struct MBOX MBOX16;
   struct MBOX MBOX17;
   struct MBOX MBOX18;
   struct MBOX MBOX19;
   struct MBOX MBOX20;
   struct MBOX MBOX21;
   struct MBOX MBOX22;
   struct MBOX MBOX23;
   struct MBOX MBOX24;
   struct MBOX MBOX25;
   struct MBOX MBOX26;
   struct MBOX MBOX27;
   struct MBOX MBOX28;
   struct MBOX MBOX29;
   struct MBOX MBOX30;
   struct MBOX MBOX31;
};   

/* eCAN Local Acceptance Mask (LAM) bit definitions */
struct  CANLAM_BITS {                // bits  description
   Uint16      LAM_L:16;     // 0:15  
   Uint16      LAM_H:13;     // 16:28  
   Uint16 rsvd1:2;           // 29:30   reserved   
   Uint16      LAMI:1;       // 31 
};

/* Allow access to the bit fields or entire register */ 
union CANLAM_REG {
   Uint32        all;
   struct CANLAM_BITS  bit;
};


/**************************************/
/*    eCAN Local Acceptance Masks      */
/**************************************/

/* eCAN LAM File */
struct LAM_REGS {
   union CANLAM_REG LAM0;
   union CANLAM_REG LAM1;
   union CANLAM_REG LAM2;
   union CANLAM_REG LAM3;
   union CANLAM_REG LAM4;
   union CANLAM_REG LAM5;
   union CANLAM_REG LAM6;
   union CANLAM_REG LAM7;
   union CANLAM_REG LAM8;
   union CANLAM_REG LAM9;
   union CANLAM_REG LAM10;
   union CANLAM_REG LAM11;
   union CANLAM_REG LAM12;
   union CANLAM_REG LAM13;
   union CANLAM_REG LAM14;
   union CANLAM_REG LAM15;
   union CANLAM_REG LAM16;
   union CANLAM_REG LAM17;
   union CANLAM_REG LAM18;
   union CANLAM_REG LAM19;
   union CANLAM_REG LAM20;
   union CANLAM_REG LAM21;
   union CANLAM_REG LAM22;
   union CANLAM_REG LAM23;
   union CANLAM_REG LAM24;
   union CANLAM_REG LAM25;
   union CANLAM_REG LAM26;
   union CANLAM_REG LAM27;
   union CANLAM_REG LAM28;
   union CANLAM_REG LAM29;
   union CANLAM_REG LAM30;
   union CANLAM_REG LAM31;
};

/* Mailbox MOTS File */

struct MOTS_REGS {
   Uint32 MOTS0;
   Uint32 MOTS1;
   Uint32 MOTS2;
   Uint32 MOTS3;
   Uint32 MOTS4;
   Uint32 MOTS5;
   Uint32 MOTS6;
   Uint32 MOTS7;
   Uint32 MOTS8;
   Uint32 MOTS9;
   Uint32 MOTS10;
   Uint32 MOTS11;
   Uint32 MOTS12;
   Uint32 MOTS13;
   Uint32 MOTS14;
   Uint32 MOTS15;
   Uint32 MOTS16;
   Uint32 MOTS17;
   Uint32 MOTS18;
   Uint32 MOTS19;
   Uint32 MOTS20;
   Uint32 MOTS21;
   Uint32 MOTS22;
   Uint32 MOTS23;
   Uint32 MOTS24;
   Uint32 MOTS25;
   Uint32 MOTS26;
   Uint32 MOTS27;
   Uint32 MOTS28;
   Uint32 MOTS29;
   Uint32 MOTS30;
   Uint32 MOTS31;
};

/* Mailbox MOTO File */

struct MOTO_REGS {
   Uint32 MOTO0;
   Uint32 MOTO1;
   Uint32 MOTO2;
   Uint32 MOTO3;
   Uint32 MOTO4;
   Uint32 MOTO5;
   Uint32 MOTO6;
   Uint32 MOTO7;
   Uint32 MOTO8;
   Uint32 MOTO9;
   Uint32 MOTO10;
   Uint32 MOTO11;
   Uint32 MOTO12;
   Uint32 MOTO13;
   Uint32 MOTO14;
   Uint32 MOTO15;
   Uint32 MOTO16;
   Uint32 MOTO17;
   Uint32 MOTO18;
   Uint32 MOTO19;
   Uint32 MOTO20;
   Uint32 MOTO21;
   Uint32 MOTO22;
   Uint32 MOTO23;
   Uint32 MOTO24;
   Uint32 MOTO25;
   Uint32 MOTO26;
   Uint32 MOTO27;
   Uint32 MOTO28;
   Uint32 MOTO29;
   Uint32 MOTO30;
   Uint32 MOTO31;
};


//---------------------------------------------------------------------------
// eCAN External References & Function Declarations:
//
extern volatile struct ECAN_REGS ECanaRegs;
extern volatile struct ECAN_MBOXES ECanaMboxes;
extern volatile struct LAM_REGS ECanaLAMRegs;
extern volatile struct MOTO_REGS ECanaMOTORegs;
extern volatile struct MOTS_REGS ECanaMOTSRegs;

extern volatile struct ECAN_REGS ECanbRegs;
extern volatile struct ECAN_MBOXES ECanbMboxes;
extern volatile struct LAM_REGS ECanbLAMRegs;
extern volatile struct MOTO_REGS ECanbMOTORegs;
extern volatile struct MOTS_REGS ECanbMOTSRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_ECAN.H definition        

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_ECap.h 
// TI File $Revision: /main/3 $
// Checkin $Date: April 7, 2005   13:47:28 $
//###########################################################################
//
// FILE:   DSP280x_ECap.h
//
// TITLE:  DSP280x Enhanced Capture Module Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_ECAP_H
#define DSP280x_ECAP_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Capture control register 1 bit definitions */                                    
struct ECCTL1_BITS {          // bits   description
   Uint16 CAP1POL:1;          // 0      Capture Event 1 Polarity select
   Uint16 CTRRST1:1;          // 1      Counter Reset on Capture Event 1
   Uint16 CAP2POL:1;          // 2      Capture Event 2 Polarity select
   Uint16 CTRRST2:1;          // 3      Counter Reset on Capture Event 2
   Uint16 CAP3POL:1;          // 4      Capture Event 3 Polarity select
   Uint16 CTRRST3:1;          // 5      Counter Reset on Capture Event 3
   Uint16 CAP4POL:1;          // 6      Capture Event 4 Polarity select
   Uint16 CTRRST4:1;          // 7      Counter Reset on Capture Event 4
   Uint16 CAPLDEN:1;          // 8      Enable Loading CAP1-4 regs on a Cap Event
   Uint16 PRESCALE:5;         // 13:9   Event Filter prescale select
   Uint16 FREE_SOFT:2;        // 15:14  Emulation mode
};

union ECCTL1_REG {
   Uint16              all;
   struct ECCTL1_BITS  bit;
};


// In V1.1 the STOPVALUE bit field was changed to 
// STOP_WRAP.  This correlated to a silicon change from
// F280x Rev 0 to Rev A. 
//----------------------------------------------------
// Capture control register 2 bit definitions */                                    
struct ECCTL2_BITS {          // bits   description
   Uint16 CONT_ONESHT:1;      // 0      Continuous or one-shot
   Uint16 STOP_WRAP:2;        // 2:1    Stop value for one-shot, Wrap for continuous
   Uint16 REARM:1;            // 3      One-shot re-arm
   Uint16 TSCTRSTOP:1;        // 4      TSCNT counter stop
   Uint16 SYNCI_EN:1;         // 5      Counter sync-in select
   Uint16 SYNCO_SEL:2;        // 7:6    Sync-out mode
   Uint16 SWSYNC:1;           // 8      SW forced counter sync
   Uint16 CAP_APWM:1;         // 9      CAP/APWM operating mode select
   Uint16 APWMPOL:1;          // 10     APWM output polarity select
   Uint16 rsvd1:5;            // 15:11  
};


union ECCTL2_REG {
   Uint16              all;
   struct ECCTL2_BITS  bit;
};


//----------------------------------------------------
// ECAP interrupt enable register bit definitions */                                    
struct ECEINT_BITS {          // bits   description
   Uint16 rsvd1:1;            // 0      reserved
   Uint16 CEVT1:1;            // 1      Capture Event 1 Interrupt Enable
   Uint16 CEVT2:1;            // 2      Capture Event 2 Interrupt Enable
   Uint16 CEVT3:1;            // 3      Capture Event 3 Interrupt Enable
   Uint16 CEVT4:1;            // 4      Capture Event 4 Interrupt Enable         
   Uint16 CTROVF:1;           // 5      Counter Overflow Interrupt Enable
   Uint16 CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Enable
   Uint16 CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Enable
   Uint16 rsvd2:8;            // 15:8   reserved
};


union ECEINT_REG {
   Uint16              all;
   struct ECEINT_BITS  bit;
};

//----------------------------------------------------
// ECAP interrupt flag register bit definitions */                                    
struct ECFLG_BITS {           // bits   description
   Uint16 INT:1;              // 0      Global Flag
   Uint16 CEVT1:1;            // 1      Capture Event 1 Interrupt Flag
   Uint16 CEVT2:1;            // 2      Capture Event 2 Interrupt Flag
   Uint16 CEVT3:1;            // 3      Capture Event 3 Interrupt Flag
   Uint16 CEVT4:1;            // 4      Capture Event 4 Interrupt Flag         
   Uint16 CTROVF:1;           // 5      Counter Overflow Interrupt Flag
   Uint16 CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Flag
   Uint16 CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Flag
   Uint16 rsvd2:8;            // 15:8   reserved
};


union ECFLG_REG {
   Uint16              all;
   struct ECFLG_BITS   bit;
};


//----------------------------------------------------

struct ECAP_REGS {
   Uint32              TSCTR;    // Time stamp counter 
   Uint32              CTRPHS;   // Counter phase
   Uint32              CAP1;     // Capture 1 
   Uint32              CAP2;     // Capture 2    
   Uint32              CAP3;     // Capture 3 
   Uint32              CAP4;     // Capture 4   
   Uint16              rsvd1[8]; // reserved
   union   ECCTL1_REG  ECCTL1;   // Capture Control Reg 1
   union   ECCTL2_REG  ECCTL2;   // Capture Control Reg 2
   union   ECEINT_REG  ECEINT;   // ECAP interrupt enable
   union   ECFLG_REG   ECFLG;    // ECAP interrupt flags
   union   ECFLG_REG   ECCLR;    // ECAP interrupt clear
   union   ECEINT_REG  ECFRC;    // ECAP interrupt force
   Uint16              rsvd2[6]; // reserved   
};

    
 

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct ECAP_REGS ECap1Regs;
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;
extern volatile struct ECAP_REGS ECap4Regs;



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_ECAP_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_EPwm.h 
// TI File $Revision: /main/6 $
// Checkin $Date: April 7, 2005   14:00:43 $
//###########################################################################
//
// FILE:   DSP280x_EPwm.h
//
// TITLE:  DSP280x Enhanced PWM Module Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_EPWM_H
#define DSP280x_EPWM_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Time base control register bit definitions */                                    
struct TBCTL_BITS {          // bits   description
   Uint16 CTRMODE:2;         // 1:0    Counter Mode
   Uint16 PHSEN:1;           // 2      Phase load enable
   Uint16 PRDLD:1;           // 3      Active period load
   Uint16 SYNCOSEL:2;        // 5:4    Sync output select
   Uint16 SWFSYNC:1;         // 6      Software force sync pulse
   Uint16 HSPCLKDIV:3;       // 9:7    High speed time pre-scale
   Uint16 CLKDIV:3;          // 12:10  Timebase clock pre-scale
   Uint16 PHSDIR:1;          // 13     Phase Direction
   Uint16 FREE_SOFT:2;       // 15:14  Emulation mode 
};

union TBCTL_REG {
   Uint16              all;
   struct TBCTL_BITS   bit;
};

//----------------------------------------------------
// Time base status register bit definitions */                                    
struct TBSTS_BITS {          // bits   description
   Uint16 CTRDIR:1;          // 0      Counter direction status
   Uint16 SYNCI:1;           // 1      External input sync status
   Uint16 CTRMAX:1;          // 2      Counter max latched status
   Uint16 rsvd1:13;          // 15:3   reserved
};

union TBSTS_REG {
   Uint16              all;
   struct TBSTS_BITS   bit;
};

//----------------------------------------------------
// Compare control register bit definitions */                                    
struct CMPCTL_BITS {          // bits   description
   Uint16 LOADAMODE:2;        // 0:1    Active compare A
   Uint16 LOADBMODE:2;        // 3:2    Active compare B
   Uint16 SHDWAMODE:1;        // 4      Compare A block operating mode
   Uint16 rsvd1:1;            // 5      reserved
   Uint16 SHDWBMODE:1;        // 6      Compare B block operating mode
   Uint16 rsvd2:1;            // 7      reserved
   Uint16 SHDWAFULL:1;        // 8      Compare A Shadow registers full Status
   Uint16 SHDWBFULL:1;        // 9      Compare B Shadow registers full Status
   Uint16 rsvd3:6;            // 15:10  reserved
};


union CMPCTL_REG {
   Uint16                all;
   struct CMPCTL_BITS    bit;
};

//----------------------------------------------------
// Action qualifier register bit definitions */                                    
struct AQCTL_BITS {           // bits   description
   Uint16 ZRO:2;              // 1:0    Action Counter = Zero
   Uint16 PRD:2;              // 3:2    Action Counter = Period
   Uint16 CAU:2;              // 5:4    Action Counter = Compare A up
   Uint16 CAD:2;              // 7:6    Action Counter = Compare A down
   Uint16 CBU:2;              // 9:8    Action Counter = Compare B up
   Uint16 CBD:2;              // 11:10  Action Counter = Compare B down
   Uint16 rsvd:4;             // 15:12  reserved
};

union AQCTL_REG {
   Uint16                all;
   struct AQCTL_BITS     bit;
};

//----------------------------------------------------
// Action qualifier SW force register bit definitions */                                    
struct AQSFRC_BITS {           // bits   description
   Uint16 ACTSFA:2;            // 1:0    Action when One-time SW Force A invoked
   Uint16 OTSFA:1;             // 2      One-time SW Force A output
   Uint16 ACTSFB:2;            // 4:3    Action when One-time SW Force B invoked
   Uint16 OTSFB:1;             // 5      One-time SW Force A output
   Uint16 RLDCSF:2;            // 7:6    Reload from Shadow options
   Uint16 rsvd1:8;             // 15:8   reserved
};

union AQSFRC_REG {
   Uint16                 all;
   struct AQSFRC_BITS     bit;
};

//----------------------------------------------------
// Action qualifier continuous SW force register bit definitions */                                    
struct AQCSFRC_BITS {          // bits   description
   Uint16 CSFA:2;              // 1:0    Continuous Software Force on output A
   Uint16 CSFB:2;              // 3:2    Continuous Software Force on output B
   Uint16 rsvd1:12;            // 15:4   reserved
};

union AQCSFRC_REG {
   Uint16                  all;
   struct AQCSFRC_BITS     bit;
};


// As of version 1.1
// Changed the MODE bit-field to OUT_MODE
// Added the bit-field IN_MODE
// This corresponds to changes in silicon as of F280x devices
// Rev A silicon.
//----------------------------------------------------
// Dead-band generator control register bit definitions                                    
struct DBCTL_BITS {          // bits   description
   Uint16 OUT_MODE:2;      	 // 1:0    Dead Band Output Mode Control 
   Uint16 POLSEL:2;          // 3:2    Polarity Select Control 
   Uint16 IN_MODE:2;         // 5:4    Dead Band Input Select Mode Control
   Uint16 rsvd1:10;          // 15:4   reserved
};

union DBCTL_REG {
   Uint16                  all;
   struct DBCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone select register bit definitions                                   
struct TZSEL_BITS {           // bits   description
   Uint16  CBC1:1;            // 0      TZ1 CBC select
   Uint16  CBC2:1;            // 1      TZ2 CBC select
   Uint16  CBC3:1;            // 2      TZ3 CBC select
   Uint16  CBC4:1;            // 3      TZ4 CBC select
   Uint16  CBC5:1;            // 4      TZ5 CBC select
   Uint16  CBC6:1;            // 5      TZ6 CBC select
   Uint16  rsvd1:2;           // 7:6    reserved
   Uint16  OSHT1:1;           // 8      One-shot TZ1 select             
   Uint16  OSHT2:1;           // 9      One-shot TZ2 select             
   Uint16  OSHT3:1;           // 10     One-shot TZ3 select             
   Uint16  OSHT4:1;           // 11     One-shot TZ4 select             
   Uint16  OSHT5:1;           // 12     One-shot TZ5 select             
   Uint16  OSHT6:1;           // 13     One-shot TZ6 select             
   Uint16  rsvd2:2;           // 15:14  reserved
};

union TZSEL_REG {
   Uint16                  all;
   struct TZSEL_BITS       bit;
};


//----------------------------------------------------
// Trip zone control register bit definitions */                                    
struct TZCTL_BITS {         // bits   description
   Uint16 TZA:2;            // 1:0    TZ1 to TZ6 Trip Action On EPWMxA
   Uint16 TZB:2;            // 3:2    TZ1 to TZ6 Trip Action On EPWMxB
   Uint16 rsvd:12;          // 15:4   reserved
};

union TZCTL_REG {
   Uint16                  all;
   struct TZCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone control register bit definitions */                                    
struct TZEINT_BITS {         // bits   description
   Uint16  rsvd1:1;          // 0      reserved
   Uint16  CBC:1;            // 1      Trip Zones Cycle By Cycle Int Enable
   Uint16  OST:1;            // 2      Trip Zones One Shot Int Enable
   Uint16  rsvd2:13;         // 15:3   reserved
};   


union TZEINT_REG {
   Uint16                  all;
   struct TZEINT_BITS      bit;
};


//----------------------------------------------------
// Trip zone flag register bit definitions */                                    
struct TZFLG_BITS {         // bits   description
   Uint16  INT:1;           // 0      Global status
   Uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   Uint16  OST:1;           // 2      Trip Zones One Shot Int
   Uint16  rsvd2:13;        // 15:3   reserved
};

union TZFLG_REG {
   Uint16                  all;
   struct TZFLG_BITS       bit;
};

//----------------------------------------------------
// Trip zone flag clear register bit definitions */                                    
struct TZCLR_BITS {         // bits   description
   Uint16  INT:1;           // 0      Global status
   Uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   Uint16  OST:1;           // 2      Trip Zones One Shot Int
   Uint16  rsvd2:13;        // 15:3   reserved
};

union TZCLR_REG {
   Uint16                  all;
   struct TZCLR_BITS       bit;
};

//----------------------------------------------------
// Trip zone flag force register bit definitions */                                    
struct TZFRC_BITS {         // bits   description
   Uint16  rsvd1:1;         // 0      reserved
   Uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   Uint16  OST:1;           // 2      Trip Zones One Shot Int
   Uint16  rsvd2:13;        // 15:3   reserved
};

union TZFRC_REG {
   Uint16                  all;
   struct TZFRC_BITS       bit;
};

//----------------------------------------------------
// Event trigger select register bit definitions */                                    
struct ETSEL_BITS {         // bits   description
   Uint16  INTSEL:3;        // 2:0    EPWMxINTn Select
   Uint16  INTEN:1;         // 3      EPWMxINTn Enable
   Uint16  rsvd1:4;         // 7:4    reserved
   Uint16  SOCASEL:3;       // 10:8   Start of conversion A Select
   Uint16  SOCAEN:1;        // 11     Start of conversion A Enable
   Uint16  SOCBSEL:3;       // 14:12  Start of conversion B Select
   Uint16  SOCBEN:1;        // 15     Start of conversion B Enable
};

union ETSEL_REG {
   Uint16                  all;
   struct ETSEL_BITS       bit;
};


//----------------------------------------------------
// Event trigger pre-scale register bit definitions */                                    
struct ETPS_BITS {         // bits   description
   Uint16  INTPRD:2;       // 1:0    EPWMxINTn Period Select
   Uint16  INTCNT:2;       // 3:2    EPWMxINTn Counter Register
   Uint16  rsvd1:4;        // 7:4    reserved
   Uint16  SOCAPRD:2;      // 9:8    EPWMxSOCA Period Select
   Uint16  SOCACNT:2;      // 11:10  EPWMxSOCA Counter Register
   Uint16  SOCBPRD:2;      // 13:12  EPWMxSOCB Period Select
   Uint16  SOCBCNT:2;      // 15:14  EPWMxSOCB Counter Register
};

union ETPS_REG {
   Uint16                  all;
   struct ETPS_BITS        bit;
};

//----------------------------------------------------
// Event trigger Flag register bit definitions */                                    
struct ETFLG_BITS {         // bits   description
   Uint16  INT:1;           // 0	EPWMxINTn Flag
   Uint16  rsvd1:1;         // 1	reserved
   Uint16  SOCA:1;          // 2	EPWMxSOCA Flag
   Uint16  SOCB:1;          // 3	EPWMxSOCB Flag
   Uint16  rsvd2:12;        // 15:4	reserved
};

union ETFLG_REG {
   Uint16                   all;
   struct ETFLG_BITS        bit;
};


//----------------------------------------------------
// Event trigger Clear register bit definitions */                                    
struct ETCLR_BITS {         // bits   description
   Uint16  INT:1;           // 0	EPWMxINTn Clear
   Uint16  rsvd1:1;         // 1	reserved
   Uint16  SOCA:1;          // 2	EPWMxSOCA Clear
   Uint16  SOCB:1;          // 3	EPWMxSOCB Clear
   Uint16  rsvd2:12;        // 15:4	reserved
};

union ETCLR_REG {
   Uint16                   all;
   struct ETCLR_BITS        bit;
};

//----------------------------------------------------
// Event trigger Force register bit definitions */                                    
struct ETFRC_BITS {         // bits   description
   Uint16  INT:1;           // 0	EPWMxINTn Force
   Uint16  rsvd1:1;         // 1	reserved
   Uint16  SOCA:1;          // 2	EPWMxSOCA Force
   Uint16  SOCB:1;          // 3	EPWMxSOCB Force
   Uint16  rsvd2:12;        // 15:4	reserved
};

union ETFRC_REG {
   Uint16                  all;
   struct ETFRC_BITS        bit;
};
//----------------------------------------------------
// PWM chopper control register bit definitions */                                    
struct PCCTL_BITS {         // bits   description
   Uint16  CHPEN:1;         // 0      PWM chopping enable
   Uint16  OSHTWTH:4;       // 4:1    One-shot pulse width
   Uint16  CHPFREQ:3;       // 7:5    Chopping clock frequency
   Uint16  CHPDUTY:3;       // 10:8   Chopping clock Duty cycle
   Uint16  rsvd1:5;         // 15:11  reserved
};


union PCCTL_REG {
   Uint16                  all;
   struct PCCTL_BITS       bit;
};

struct HRCNFG_BITS {       	// bits   description
   Uint16  EDGMODE:2;     	// 1:0    Edge Mode select Bits
   Uint16  CTLMODE:1;     	// 2      Control mode Select Bit
   Uint16  HRLOAD:1;      	// 3      Shadow mode Select Bit
   Uint16  rsvd1:12;      	// 15:4   reserved
};

union HRCNFG_REG {
   Uint16                  	all;
   struct HRCNFG_BITS       bit;
};


struct TBPHS_HIRES_REG {   	// bits   description
   Uint16  TBPHSHR;     	// 15:0   Extension register for HiRes Phase (8 bits)
   Uint16  TBPHS;           // 31:16  Phase offset register
};

union TBPHS_HIRES_GROUP {
   Uint32                  all;
   struct TBPHS_HIRES_REG  half;
};

struct CMPA_HIRES_REG {   	// bits   description
   Uint16  CMPAHR;     	    // 15:0   Extension register for HiRes compare (8 bits)
   Uint16  CMPA;            // 31:16  Compare A reg
};

union CMPA_HIRES_GROUP {
   Uint32                 all;
   struct CMPA_HIRES_REG  half;
};


struct EPWM_REGS {
   union  TBCTL_REG           TBCTL;   // 
   union  TBSTS_REG           TBSTS;   // 
   union  TBPHS_HIRES_GROUP   TBPHS;   // Union of TBPHS:TBPHSHR
   Uint16                     TBCTR;   // Counter
   Uint16                     TBPRD;   // Period register set 
   Uint16                     rsvd1;   // 
   union  CMPCTL_REG          CMPCTL;  // Compare control
   union  CMPA_HIRES_GROUP    CMPA;    // Union of CMPA:CMPAHR
   Uint16                     CMPB;    // Compare B reg
   union  AQCTL_REG           AQCTLA;  // Action qual output A
   union  AQCTL_REG           AQCTLB;  // Action qual output B
   union  AQSFRC_REG          AQSFRC;  // Action qual SW force
   union  AQCSFRC_REG         AQCSFRC; // Action qualifier continuous SW force 
   union  DBCTL_REG           DBCTL;   // Dead-band control
   Uint16                     DBRED;   // Dead-band rising edge delay
   Uint16                     DBFED;   // Dead-band falling edge delay
   union  TZSEL_REG           TZSEL;   // Trip zone select
   Uint16                     rsvd2;   
   union  TZCTL_REG           TZCTL;   // Trip zone control
   union  TZEINT_REG          TZEINT;  // Trip zone interrupt enable
   union  TZFLG_REG           TZFLG;   // Trip zone interrupt flags
   union  TZCLR_REG           TZCLR;   // Trip zone clear   
   union  TZFRC_REG    	      TZFRC;   // Trip zone force interrupt
   union  ETSEL_REG           ETSEL;   // Event trigger selection
   union  ETPS_REG            ETPS;    // Event trigger pre-scaler
   union  ETFLG_REG           ETFLG;   // Event trigger flags
   union  ETCLR_REG           ETCLR;   // Event trigger clear   
   union  ETFRC_REG           ETFRC;   // Event trigger force
   union  PCCTL_REG           PCCTL;   // PWM chopper control
   Uint16                     rsvd3;   // 
   union  HRCNFG_REG          HRCNFG;  // HiRes Config Reg
};
    
 

//---------------------------------------------------------------------------
// External References & Function Declarations:
//
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_EPWM_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_EQep.h 
// TI File $Revision: /main/3 $
// Checkin $Date: April 8, 2005   12:39:38 $
//###########################################################################
//
// FILE:   DSP280x_EQep.h
//
// TITLE:  DSP280x Enhanced Quadrature Encoder Pulse Module 
//         Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_EQEP_H
#define DSP280x_EQEP_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Capture decoder control register bit definitions */                                    
struct QDECCTL_BITS {         // bits   description
   Uint16 rsvd1:5;            // 4:0    reserved
   Uint16 QSP:1;              // 5      QEPS input polarity
   Uint16 QIP:1;              // 6      QEPI input polarity
   Uint16 QBP:1;              // 7      QEPB input polarity
   Uint16 QAP:1;              // 8      QEPA input polarity
   Uint16 IGATE:1;            // 9      Index pulse gating option
   Uint16 SWAP:1;             // 10     CLK/DIR signal source for Position Counter
   Uint16 XCR:1;              // 11     External clock rate
   Uint16 SPSEL:1;            // 12     Sync output pin select
   Uint16 SOEN:1;             // 13     Enable position compare sync
   Uint16 QSRC:2;             // 15:14  Position counter source
};

union QDECCTL_REG {
   Uint16              all;
   struct QDECCTL_BITS   bit;
};


//----------------------------------------------------
// QEP control register bit definitions */                                    
struct QEPCTL_BITS {           // bits   description
   Uint16 WDE:1;               // 0      QEP watchdog enable
   Uint16 UTE:1;               // 1      QEP unit timer enable
   Uint16 QCLM:1;              // 2      QEP capture latch mode
   Uint16 QPEN:1;              // 3      Quadrature position counter enable
   Uint16 IEL:2;               // 5:4    Index event latch
   Uint16 SEL:1;               // 6      Strobe event latch
   Uint16 SWI:1;               // 7      Software init position counter
   Uint16 IEI:2;               // 9:8    Index event init of position count
   Uint16 SEI:2;               // 11:10  Strobe event init
   Uint16 PCRM:2;              // 13:12  Position counter reset
   Uint16 FREE_SOFT:2;         // 15:14  Emulation mode
};

union QEPCTL_REG {
   Uint16               all;
   struct QEPCTL_BITS   bit;
};         


//----------------------------------------------------
// Quadrature capture control register bit definitions */                                    
struct QCAPCTL_BITS {          // bits   description
   Uint16 UPPS:4;              // 3:0    Unit position pre-scale         
   Uint16 CCPS:3;              // 6:4    QEP capture timer pre-scale
   Uint16 rsvd1:8;             // 14:7   reserved
   Uint16 CEN:1;               // 15     Enable QEP capture
};


union QCAPCTL_REG {
   Uint16               all;
   struct QCAPCTL_BITS  bit;
}; 



//----------------------------------------------------
// Position compare control register bit definitions */                                    
struct QPOSCTL_BITS {          // bits   description
   Uint16 PCSPW:12;            // 11:0   Position compare sync pulse width
   Uint16 PCE:1;               // 12     Position compare enable/disable
   Uint16 PCPOL:1;             // 13     Polarity of sync output
   Uint16 PCLOAD:1;            // 14     Position compare of shadow load
   Uint16 PCSHDW:1;            // 15     Position compare shadow enable
};

union QPOSCTL_REG {
   Uint16               all;
   struct QPOSCTL_BITS  bit;
};         

//----------------------------------------------------
// QEP interrupt control register bit definitions */                                    
struct QEINT_BITS {          // bits   description
   Uint16 rsvd1:1;           // 0      reserved
   Uint16 PCE:1;             // 1      Position counter error
   Uint16 QPE:1;             // 2      Quadrature phase error
   Uint16 QDC:1;             // 3      Quadrature dir change
   Uint16 WTO:1;             // 4      Watchdog timeout
   Uint16 PCU:1;             // 5      Position counter underflow
   Uint16 PCO:1;             // 6      Position counter overflow
   Uint16 PCR:1;             // 7      Position compare ready
   Uint16 PCM:1;             // 8      Position compare match
   Uint16 SEL:1;             // 9      Strobe event latch
   Uint16 IEL:1;             // 10     Event latch
   Uint16 UTO:1;             // 11     Unit timeout
   Uint16 rsvd2:4;           // 15:12  reserved
};


union QEINT_REG {
   Uint16               all;
   struct QEINT_BITS    bit;
};


//----------------------------------------------------
// QEP interrupt status register bit definitions */                                    
struct QFLG_BITS {          // bits   description
   Uint16 INT:1;            // 0      Global interrupt 
   Uint16 PCE:1;            // 1      Position counter error
   Uint16 PHE:1;            // 2      Quadrature phase error
   Uint16 QDC:1;            // 3      Quadrature dir change
   Uint16 WTO:1;            // 4      Watchdog timeout
   Uint16 PCU:1;            // 5      Position counter underflow
   Uint16 PCO:1;            // 6      Position counter overflow
   Uint16 PCR:1;            // 7      Position compare ready
   Uint16 PCM:1;            // 8      Position compare match
   Uint16 SEL:1;            // 9      Strobe event latch
   Uint16 IEL:1;            // 10     Event latch
   Uint16 UTO:1;            // 11     Unit timeout
   Uint16 rsvd2:4;          // 15:12  reserved
};


union QFLG_REG {
   Uint16               all;
   struct QFLG_BITS     bit;
};

//----------------------------------------------------
// QEP interrupt force register bit definitions */                                    
struct QFRC_BITS {          // bits   description
   Uint16 reserved:1;       // 0      Reserved
   Uint16 PCE:1;            // 1      Position counter error
   Uint16 PHE:1;            // 2      Quadrature phase error
   Uint16 QDC:1;            // 3      Quadrature dir change
   Uint16 WTO:1;            // 4      Watchdog timeout
   Uint16 PCU:1;            // 5      Position counter underflow
   Uint16 PCO:1;            // 6      Position counter overflow
   Uint16 PCR:1;            // 7      Position compare ready
   Uint16 PCM:1;            // 8      Position compare match
   Uint16 SEL:1;            // 9      Strobe event latch
   Uint16 IEL:1;            // 10     Event latch
   Uint16 UTO:1;            // 11     Unit timeout
   Uint16 rsvd2:4;          // 15:12  reserved
};


union QFRC_REG {
   Uint16               all;
   struct QFRC_BITS     bit;
};

// V1.1 Added UPEVNT (bit 7) This reflects changes 
// made as of F280x Rev A devices
//----------------------------------------------------
// QEP status register bit definitions */                                    
struct QEPSTS_BITS {          // bits   description
   Uint16 PCEF:1;             // 0      Position counter error
   Uint16 FIMF:1;             // 1      First index marker
   Uint16 CDEF:1;             // 2      Capture direction error
   Uint16 COEF:1;             // 3      Capture overflow error
   Uint16 QDLF:1;             // 4      QEP direction latch
   Uint16 QDF:1;              // 5      Quadrature direction
   Uint16 FIDF:1;             // 6      Direction on first index marker
   Uint16 UPEVNT:1;           // 7      Unit position event flag
   Uint16 rsvd1:8;            // 15:8   reserved
};

union QEPSTS_REG {
   Uint16               all;
   struct QEPSTS_BITS   bit;
};

//----------------------------------------------------

struct EQEP_REGS {
   Uint32              QPOSCNT;   // Position counter 
   Uint32              QPOSINIT;  // Position counter init
   Uint32              QPOSMAX;   // Maximum position count
   Uint32              QPOSCMP;   // Position compare
   Uint32              QPOSILAT;  // Index position latch
   Uint32              QPOSSLAT;  // Strobe position latch
   Uint32              QPOSLAT;   // Position latch
   Uint32              QUTMR;     // Unit timer
   Uint32              QUPRD;     // Unit period
   Uint16              QWDTMR;    // QEP watchdog timer
   Uint16              QWDPRD;    // QEP watchdog period
   union  QDECCTL_REG  QDECCTL;   // Quadrature decoder control
   union  QEPCTL_REG   QEPCTL;    // QEP control 
   union  QCAPCTL_REG  QCAPCTL;   // Quadrature capture control     
   union  QPOSCTL_REG  QPOSCTL;   // Position compare control
   union  QEINT_REG    QEINT;     // QEP interrupt control        
   union  QFLG_REG     QFLG;      // QEP interrupt flag
   union  QFLG_REG     QCLR;      // QEP interrupt clear                   
   union  QFRC_REG     QFRC;      // QEP interrupt force                   
   union  QEPSTS_REG   QEPSTS;    // QEP status
   Uint16              QCTMR;     // QEP capture timer
   Uint16              QCPRD;     // QEP capture period
   Uint16              QCTMRLAT;  // QEP capture latch
   Uint16              QCPRDLAT;  // QEP capture period latch
   Uint16              rsvd1[30]; // reserved
};

    
 

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_EQEP_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_Gpio.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:31:48 $
//###########################################################################
//
// FILE:   DSP280x_Gpio.h
//
// TITLE:  DSP280x General Purpose I/O Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_GPIO_H
#define DSP280x_GPIO_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// GPIO A control register bit definitions */                                    
struct GPACTRL_BITS {        // bits   description
   Uint16 QUALPRD0:8;        // 7:0    Qual period 
   Uint16 QUALPRD1:8;        // 15:8   Qual period 
   Uint16 QUALPRD2:8;        // 23:16  Qual period 
   Uint16 QUALPRD3:8;        // 31:24  Qual period  
};

union GPACTRL_REG {
   Uint32              all;
   struct GPACTRL_BITS bit;
};

//----------------------------------------------------
// GPIO B control register bit definitions */                                    
struct GPBCTRL_BITS {        // bits   description
   Uint16 QUALPRD0:8;        // 7:0    Qual period
   Uint16 rsvd1:8;           // 15:8   reserved 
   Uint16 rsvd2:16;          // 31:16  reserved   
};

union GPBCTRL_REG {
   Uint32              all;
   struct GPBCTRL_BITS bit;
};

//----------------------------------------------------
// GPIO A Qual/MUX select register bit definitions */                                    
struct GPA1_BITS {            // bits   description
   Uint16 GPIO0:2;            // 1:0    GPIO0   
   Uint16 GPIO1:2;            // 3:2    GPIO1 
   Uint16 GPIO2:2;            // 5:4    GPIO2 
   Uint16 GPIO3:2;            // 7:6    GPIO3    
   Uint16 GPIO4:2;            // 9:8    GPIO4 
   Uint16 GPIO5:2;            // 11:10  GPIO5 
   Uint16 GPIO6:2;            // 13:12  GPIO6    
   Uint16 GPIO7:2;            // 15:14  GPIO7 
   Uint16 GPIO8:2;            // 17:16  GPIO8 
   Uint16 GPIO9:2;            // 19:18  GPIO9    
   Uint16 GPIO10:2;           // 21:20  GPIO10 
   Uint16 GPIO11:2;           // 23:22  GPIO11       
   Uint16 GPIO12:2;           // 25:24  GPIO12 
   Uint16 GPIO13:2;           // 27:26  GPIO13 
   Uint16 GPIO14:2;           // 29:28  GPIO14 
   Uint16 GPIO15:2;           // 31:30  GPIO15 
};


struct GPA2_BITS {            // bits   description
   Uint16 GPIO16:2;           // 1:0    GPIO16   
   Uint16 GPIO17:2;           // 3:2    GPIO17 
   Uint16 GPIO18:2;           // 5:4    GPIO18 
   Uint16 GPIO19:2;           // 7:6    GPIO19   
   Uint16 GPIO20:2;           // 9:8    GPIO20
   Uint16 GPIO21:2;           // 11:10  GPIO21 
   Uint16 GPIO22:2;           // 13:12  GPIO22    
   Uint16 GPIO23:2;           // 15:14  GPIO23
   Uint16 GPIO24:2;           // 17:16  GPIO24 
   Uint16 GPIO25:2;           // 19:18  GPIO25    
   Uint16 GPIO26:2;           // 21:20  GPIO26 
   Uint16 GPIO27:2;           // 23:22  GPIO27       
   Uint16 GPIO28:2;           // 25:24  GPIO28 
   Uint16 GPIO29:2;           // 27:26  GPIO29 
   Uint16 GPIO30:2;           // 29:28  GPIO30 
   Uint16 GPIO31:2;           // 31:30  GPIO31 
};

struct GPB1_BITS {            // bits   description
   Uint16 GPIO32:2;           // 1:0    GPIO32   
   Uint16 GPIO33:2;           // 3:2    GPIO33
   Uint16 GPIO34:2;           // 5:4    GPIO34   
   Uint16 rsvd1:2;            // 7:6    reserved  
   Uint16 rsvd2:8;            // 15:8   reserved
   Uint16 rsvd3:16;           // 31:16  reserved
};  

struct GPB2_BITS  {           // bits   description
   Uint16 rsvd1:16;           // 15:0   reserved
   Uint16 rsvd2:16;           // 31:16  reserved
};



union GPA1_REG {
   Uint32              all;
   struct GPA1_BITS    bit;
};

union GPA2_REG {
   Uint32              all;
   struct GPA2_BITS    bit;
};      

union GPB1_REG {
   Uint32              all;
   struct GPB1_BITS    bit;
};

union GPB2_REG {
   Uint32              all;
   struct GPB2_BITS    bit;
};


//----------------------------------------------------
// GPIO A DIR/TOGGLE/SET/CLEAR register bit definitions */                                    
struct GPADAT_BITS {          // bits   description
   Uint16 GPIO0:1;            // 0      GPIO0   
   Uint16 GPIO1:1;            // 1      GPIO1 
   Uint16 GPIO2:1;            // 2      GPIO2 
   Uint16 GPIO3:1;            // 3      GPIO3    
   Uint16 GPIO4:1;            // 4      GPIO4 
   Uint16 GPIO5:1;            // 5      GPIO5 
   Uint16 GPIO6:1;            // 6      GPIO6    
   Uint16 GPIO7:1;            // 7      GPIO7 
   Uint16 GPIO8:1;            // 8      GPIO8 
   Uint16 GPIO9:1;            // 9      GPIO9    
   Uint16 GPIO10:1;           // 10     GPIO10 
   Uint16 GPIO11:1;           // 11     GPIO11       
   Uint16 GPIO12:1;           // 12     GPIO12 
   Uint16 GPIO13:1;           // 13     GPIO13 
   Uint16 GPIO14:1;           // 14     GPIO14 
   Uint16 GPIO15:1;           // 15     GPIO15 
   Uint16 GPIO16:1;           // 16     GPIO16   
   Uint16 GPIO17:1;           // 17     GPIO17 
   Uint16 GPIO18:1;           // 18     GPIO18 
   Uint16 GPIO19:1;           // 19     GPIO19   
   Uint16 GPIO20:1;           // 20     GPIO20
   Uint16 GPIO21:1;           // 21     GPIO21 
   Uint16 GPIO22:1;           // 22     GPIO22    
   Uint16 GPIO23:1;           // 23     GPIO23
   Uint16 GPIO24:1;           // 24     GPIO24 
   Uint16 GPIO25:1;           // 25     GPIO25    
   Uint16 GPIO26:1;           // 26     GPIO26 
   Uint16 GPIO27:1;           // 27     GPIO27       
   Uint16 GPIO28:1;           // 28     GPIO28 
   Uint16 GPIO29:1;           // 29     GPIO29 
   Uint16 GPIO30:1;           // 30     GPIO30 
   Uint16 GPIO31:1;           // 31     GPIO31 
};

struct GPBDAT_BITS {          // bits   description
   Uint16 GPIO32:1;           // 0      GPIO32   
   Uint16 GPIO33:1;           // 1      GPIO33
   Uint16 GPIO34:1;           // 2      GPIO34   
   Uint16 rsvd1:1;            // 3      reserved   
   Uint16 rsvd2:12;           // 15:4   reserved
   Uint16 rsvd3:16;           // 31:16  reserved
};

union GPADAT_REG {
   Uint32              all;
   struct GPADAT_BITS  bit;
};

union GPBDAT_REG {
   Uint32              all;
   struct GPBDAT_BITS  bit;
};


//----------------------------------------------------
// GPIO XINT1/XINT2/XNMI select register bit definitions */                                    
struct GPIOXINT_BITS {        // bits   description
    Uint16 GPIOSEL:5;         // 4:0    Select GPIO interrupt input source
    Uint16 rsvd1:11;          // 15:5   reserved
};

union GPIOXINT_REG {
   Uint16                all;
   struct GPIOXINT_BITS  bit;
};


struct GPIO_CTRL_REGS {
   union  GPACTRL_REG  GPACTRL;   // GPIO A Control Register (GPIO0 to 31)
   union  GPA1_REG     GPAQSEL1;  // GPIO A Qualifier Select 1 Register (GPIO0 to 15)
   union  GPA2_REG     GPAQSEL2;  // GPIO A Qualifier Select 2 Register (GPIO16 to 31)
   union  GPA1_REG     GPAMUX1;   // GPIO A Mux 1 Register (GPIO0 to 15)
   union  GPA2_REG     GPAMUX2;   // GPIO A Mux 2 Register (GPIO16 to 31)
   union  GPADAT_REG   GPADIR;    // GPIO A Direction Register (GPIO0 to 31)
   union  GPADAT_REG   GPAPUD;    // GPIO A Pull Up Disable Register (GPIO0 to 31)
   Uint32              rsvd1;
   union  GPBCTRL_REG  GPBCTRL;   // GPIO B Control Register (GPIO32 to 63)
   union  GPB1_REG     GPBQSEL1;  // GPIO B Qualifier Select 1 Register (GPIO32 to 47)
   union  GPB2_REG     GPBQSEL2;  // GPIO B Qualifier Select 2 Register (GPIO48 to 63)
   union  GPB1_REG     GPBMUX1;   // GPIO B Mux 1 Register (GPIO32 to 47)
   union  GPB2_REG     GPBMUX2;   // GPIO B Mux 2 Register (GPIO48 to 63)
   union  GPBDAT_REG   GPBDIR;    // GPIO B Direction Register (GPIO32 to 63)
   union  GPBDAT_REG   GPBPUD;    // GPIO B Pull Up Disable Register (GPIO32 to 63)
   Uint16              rsvd2[33];
};

struct GPIO_DATA_REGS {
   union  GPADAT_REG       GPADAT;       // GPIO Data Register (GPIO0 to 31)
   union  GPADAT_REG       GPASET;       // GPIO Data Set Register (GPIO0 to 31)
   union  GPADAT_REG       GPACLEAR;     // GPIO Data Clear Register (GPIO0 to 31)
   union  GPADAT_REG       GPATOGGLE;    // GPIO Data Toggle Register (GPIO0 to 31) 
   union  GPBDAT_REG       GPBDAT;       // GPIO Data Register (GPIO32 to 63)
   union  GPBDAT_REG       GPBSET;       // GPIO Data Set Register (GPIO32 to 63)
   union  GPBDAT_REG       GPBCLEAR;     // GPIO Data Clear Register (GPIO32 to 63)
   union  GPBDAT_REG       GPBTOGGLE;    // GPIO Data Toggle Register (GPIO32 to 63)
   Uint16                  rsvd1[16];
};

struct GPIO_INT_REGS {
   union  GPIOXINT_REG     GPIOXINT1SEL; // XINT1 GPIO Input Selection
   union  GPIOXINT_REG     GPIOXINT2SEL; // XINT2 GPIO Input Selection
   union  GPIOXINT_REG     GPIOXNMISEL;  // XNMI_XINT13 GPIO Input Selection
   Uint16                  rsvd2[5];
   union  GPADAT_REG       GPIOLPMSEL;   // Low power modes GP I/O input select
};      
 

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS GpioIntRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_GPIO_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_I2c.h 
// TI File $Revision: /main/2 $
// Checkin $Date: December 2, 2004   13:43:02 $
//###########################################################################
//
// FILE:   DSP280x_I2c.h
//
// TITLE:  DSP280x Enhanced Quadrature Encoder Pulse Module 
//         Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_I2C_H
#define DSP280x_I2C_H


#ifdef __cplusplus
extern "C" {
#endif


//----------------------------------------------------
// I2C interrupt vector register bit definitions */                                    
struct I2CISRC_BITS {         // bits   description
   Uint16 INTCODE:3;          // 2:0    Interrupt code
   Uint16 rsvd1:13;           // 15:3   reserved
};

union I2CISRC_REG {
   Uint16                 all;
   struct I2CISRC_BITS    bit;
};

//----------------------------------------------------
// I2C interrupt mask register bit definitions */                                    
struct I2CIER_BITS {          // bits   description
   Uint16 AL:1;               // 0      Arbitration lost interrupt 
   Uint16 NACK:1;             // 1      No ack interrupt 
   Uint16 ARDY:1;             // 2      Register access ready interrupt
   Uint16 RRDY:1;             // 3      Recieve data ready interrupt
   Uint16 XRDY:1;             // 4      Transmit data ready interrupt
   Uint16 SCD:1;              // 5      Stop condition detection 
   Uint16 AAS:1;              // 6      Address as slave
   Uint16 rsvd:9;             // 15:7   reserved
};

union I2CIER_REG {
   Uint16                 all;
   struct I2CIER_BITS     bit;
};

//----------------------------------------------------
// I2C status register bit definitions */                                    
struct I2CSTR_BITS {          // bits   description
   Uint16 AL:1;               // 0      Arbitration lost interrupt 
   Uint16 NACK:1;             // 1      No ack interrupt 
   Uint16 ARDY:1;             // 2      Register access ready interrupt
   Uint16 RRDY:1;             // 3      Recieve data ready interrupt
   Uint16 XRDY:1;             // 4      Transmit data ready interrupt
   Uint16 SCD:1;              // 5      Stop condition detection
   Uint16 rsvd1:2;            // 7:6    reserved
   Uint16 AD0:1;              // 8      Address Zero
   Uint16 AAS:1;              // 9      Address as slave
   Uint16 XSMT:1;             // 10     XMIT shift empty
   Uint16 RSFULL:1;           // 11     Recieve shift full   
   Uint16 BB:1;               // 12     Bus busy
   Uint16 NACKSNT:1;          // 13     A no ack sent
   Uint16 SDIR:1;             // 14     Slave direction
   Uint16 rsvd2:1;            // 15     reserved
};        

union I2CSTR_REG {
   Uint16                 all;
   struct I2CSTR_BITS     bit;
};


//----------------------------------------------------
// I2C mode control register bit definitions */                                    
struct I2CMDR_BITS {          // bits   description
   Uint16 BC:3;               // 2:0    Bit count
   Uint16 FDF:1;              // 3      Free data format
   Uint16 STB:1;              // 4      Start byte
   Uint16 IRS:1;              // 5      I2C Reset not
   Uint16 DLB:1;              // 6      Digital loopback
   Uint16 RM:1;               // 7      Repeat mode
   Uint16 XA:1;               // 8      Expand address
   Uint16 TRX:1;              // 9      Transmitter/reciever
   Uint16 MST:1;              // 10     Master/slave
   Uint16 STP:1;              // 11     Stop condition
   Uint16 rsvd1:1;            // 12     reserved
   Uint16 STT:1;              // 13     Start condition
   Uint16 FREE:1;             // 14     Emulation mode
   Uint16 NACKMOD:1;          // 15     No Ack mode
};
 
union I2CMDR_REG {
   Uint16                 all;
   struct I2CMDR_BITS     bit;
};

//----------------------------------------------------
// I2C pre-scaler register bit definitions */                                    
struct I2CPSC_BITS {         // bits   description
   Uint16 IPSC:8;            // 7:0    pre-scaler
   Uint16 rsvd1:8;           // 15:8   reserved
};


union I2CPSC_REG {
   Uint16                 all;
   struct I2CPSC_BITS     bit;
};


//----------------------------------------------------
// TX FIFO control register bit definitions */                                    
struct I2CFFTX_BITS {         // bits   description
   Uint16 TXFFIL:5;           // 4:0    FIFO interrupt level
   Uint16 TXFFIENA:1;         // 5      FIFO interrupt enable/disable
   Uint16 TXFFINTCLR:1;       // 6      FIFO clear
   Uint16 TXFFINT:1;          // 7      FIFO interrupt flag
   Uint16 TXFFST:5;           // 12:8   FIFO level status
   Uint16 TXFFRST:1;          // 13     FIFO reset
   Uint16 I2CFFEN:1;          // 14     enable/disable TX & RX FIFOs
   Uint16 rsvd1:1;            // 15     reserved

};

union I2CFFTX_REG {
   Uint16                 all;
   struct I2CFFTX_BITS    bit;
};

//----------------------------------------------------
// RX FIFO control register bit definitions */                                    
struct I2CFFRX_BITS {         // bits   description
   Uint16 RXFFIL:5;           // 4:0    FIFO interrupt level
   Uint16 RXFFIENA:1;         // 5      FIFO interrupt enable/disable
   Uint16 RXFFINTCLR:1;       // 6      FIFO clear
   Uint16 RXFFINT:1;          // 7      FIFO interrupt flag
   Uint16 RXFFST:5;           // 12:8   FIFO level
   Uint16 RXFFRST:1;          // 13     FIFO reset
   Uint16 rsvd1:2;            // 15:14  reserved
};

union I2CFFRX_REG {
   Uint16                 all;
   struct I2CFFRX_BITS    bit;
};


//----------------------------------------------------

struct I2C_REGS {
   Uint16              I2COAR;    // Own address register
   union  I2CIER_REG   I2CIER;    // Interrupt enable
   union  I2CSTR_REG   I2CSTR;    // Interrupt status
   Uint16              I2CCLKL;   // Clock divider low
   Uint16              I2CCLKH;   // Clock divider high
   Uint16              I2CCNT;    // Data count
   Uint16              I2CDRR;    // Data recieve
   Uint16              I2CSAR;    // Slave address
   Uint16              I2CDXR;    // Data transmit
   union  I2CMDR_REG   I2CMDR;    // Mode
   union  I2CISRC_REG  I2CISRC;   // Interrupt source
   Uint16              rsvd1;     // reserved
   union  I2CPSC_REG   I2CPSC;    // Pre-scaler
   Uint16              rsvd2[19]; // reserved
   union  I2CFFTX_REG  I2CFFTX;   // Transmit FIFO
   union  I2CFFRX_REG  I2CFFRX;   // Recieve FIFO
};


 

//---------------------------------------------------------------------------
// External References & Function Declarations:
//
extern volatile struct I2C_REGS I2caRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_I2C_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_PieCtrl.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:31:54 $
//###########################################################################
//
// FILE:   DSP280x_PieCtrl.h
//
// TITLE:  DSP280x Device PIE Control Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################


#ifndef DSP280x_PIE_CTRL_H
#define DSP280x_PIE_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// PIE Control Register Bit Definitions:
//
// PIECTRL: Register bit definitions:
struct PIECTRL_BITS {      // bits description
   Uint16  ENPIE:1;        // 0    Enable PIE block
   Uint16  PIEVECT:15;     // 15:1 Fetched vector address
};

union PIECTRL_REG {
   Uint16                 all;
   struct PIECTRL_BITS  bit;
};  

// PIEIER: Register bit definitions:
struct PIEIER_BITS {       // bits description
   Uint16 INTx1:1;         // 0    INTx.1
   Uint16 INTx2:1;         // 1    INTx.2
   Uint16 INTx3:1;         // 2    INTx.3
   Uint16 INTx4:1;         // 3    INTx.4
   Uint16 INTx5:1;         // 4    INTx.5
   Uint16 INTx6:1;         // 5    INTx.6
   Uint16 INTx7:1;         // 6    INTx.7
   Uint16 INTx8:1;         // 7    INTx.8
   Uint16 rsvd:8;          // 15:8 reserved
};

union PIEIER_REG {
   Uint16              all;
   struct PIEIER_BITS  bit;
}; 

// PIEIFR: Register bit definitions:
struct PIEIFR_BITS {       // bits description
   Uint16 INTx1:1;         // 0    INTx.1
   Uint16 INTx2:1;         // 1    INTx.2
   Uint16 INTx3:1;         // 2    INTx.3
   Uint16 INTx4:1;         // 3    INTx.4
   Uint16 INTx5:1;         // 4    INTx.5
   Uint16 INTx6:1;         // 5    INTx.6
   Uint16 INTx7:1;         // 6    INTx.7
   Uint16 INTx8:1;         // 7    INTx.8
   Uint16 rsvd:8;          // 15:8 reserved
};

union PIEIFR_REG {
   Uint16              all;
   struct PIEIFR_BITS  bit;
};

// PIEACK: Register bit definitions:
struct PIEACK_BITS {       // bits description
   Uint16 ACK1:1;          // 0    Acknowledge PIE interrupt group 1
   Uint16 ACK2:1;          // 1    Acknowledge PIE interrupt group 2
   Uint16 ACK3:1;          // 2    Acknowledge PIE interrupt group 3
   Uint16 ACK4:1;          // 3    Acknowledge PIE interrupt group 4
   Uint16 ACK5:1;          // 4    Acknowledge PIE interrupt group 5
   Uint16 ACK6:1;          // 5    Acknowledge PIE interrupt group 6
   Uint16 ACK7:1;          // 6    Acknowledge PIE interrupt group 7
   Uint16 ACK8:1;          // 7    Acknowledge PIE interrupt group 8
   Uint16 ACK9:1;          // 8    Acknowledge PIE interrupt group 9
   Uint16 ACK10:1;         // 9    Acknowledge PIE interrupt group 10
   Uint16 ACK11:1;         // 10   Acknowledge PIE interrupt group 11
   Uint16 ACK12:1;         // 11   Acknowledge PIE interrupt group 12
   Uint16 rsvd:4;          // 15:12 reserved
};

union PIEACK_REG {
   Uint16              all;
   struct PIEACK_BITS  bit;
};

//---------------------------------------------------------------------------
// PIE Control Register File:
//
struct PIE_CTRL_REGS {
   union PIECTRL_REG PIECTRL;       // PIE control register
   union PIEACK_REG  PIEACK;        // PIE acknowledge
   union PIEIER_REG  PIEIER1;       // PIE INT1 IER register  
   union PIEIFR_REG  PIEIFR1;       // PIE INT1 IFR register
   union PIEIER_REG  PIEIER2;       // PIE INT2 IER register 
   union PIEIFR_REG  PIEIFR2;       // PIE INT2 IFR register
   union PIEIER_REG  PIEIER3;       // PIE INT3 IER register 
   union PIEIFR_REG  PIEIFR3;       // PIE INT3 IFR register
   union PIEIER_REG  PIEIER4;       // PIE INT4 IER register             
   union PIEIFR_REG  PIEIFR4;       // PIE INT4 IFR register
   union PIEIER_REG  PIEIER5;       // PIE INT5 IER register  
   union PIEIFR_REG  PIEIFR5;       // PIE INT5 IFR register
   union PIEIER_REG  PIEIER6;       // PIE INT6 IER register 
   union PIEIFR_REG  PIEIFR6;       // PIE INT6 IFR register
   union PIEIER_REG  PIEIER7;       // PIE INT7 IER register 
   union PIEIFR_REG  PIEIFR7;       // PIE INT7 IFR register
   union PIEIER_REG  PIEIER8;       // PIE INT8 IER register
   union PIEIFR_REG  PIEIFR8;       // PIE INT8 IFR register
   union PIEIER_REG  PIEIER9;       // PIE INT9 IER register  
   union PIEIFR_REG  PIEIFR9;       // PIE INT9 IFR register
   union PIEIER_REG  PIEIER10;      // PIE INT10 IER register 
   union PIEIFR_REG  PIEIFR10;      // PIE INT10 IFR register
   union PIEIER_REG  PIEIER11;      // PIE INT11 IER register 
   union PIEIFR_REG  PIEIFR11;      // PIE INT11 IFR register
   union PIEIER_REG  PIEIER12;      // PIE INT12 IER register
   union PIEIFR_REG  PIEIFR12;      // PIE INT12 IFR register
};     

#define PIEACK_GROUP1   0x0001;
#define PIEACK_GROUP2   0x0002;
#define PIEACK_GROUP3   0x0004;
#define PIEACK_GROUP4   0x0008;
#define PIEACK_GROUP5   0x0010;
#define PIEACK_GROUP6   0x0020;
#define PIEACK_GROUP7   0x0040;
#define PIEACK_GROUP8   0x0080;
#define PIEACK_GROUP9   0x0100;
#define PIEACK_GROUP10  0x0200;
#define PIEACK_GROUP11  0x0400;
#define PIEACK_GROUP12  0x0800;

//---------------------------------------------------------------------------
// PIE Control Registers External References & Function Declarations:
//
extern volatile struct PIE_CTRL_REGS PieCtrlRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_PIE_CTRL_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_PieVect.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:31:56 $
//###########################################################################
//
// FILE:   DSP280x_PieVect.h
//
// TITLE:  DSP280x Devices PIE Vector Table Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_PIE_VECT_H
#define DSP280x_PIE_VECT_H


#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// PIE Interrupt Vector Table Definition:
//
// Create a user type called PINT (pointer to interrupt):

typedef interrupt void(*PINT)(void);

// Define Vector Table:
struct PIE_VECT_TABLE {

// Reset is never fetched from this table.  
// It will always be fetched from 0x3FFFC0 in 
// boot ROM

      PINT     PIE1_RESERVED;  
      PINT     PIE2_RESERVED;
      PINT     PIE3_RESERVED;
      PINT     PIE4_RESERVED;
      PINT     PIE5_RESERVED;
      PINT     PIE6_RESERVED;
      PINT     PIE7_RESERVED;
      PINT     PIE8_RESERVED;
      PINT     PIE9_RESERVED;
      PINT     PIE10_RESERVED;
      PINT     PIE11_RESERVED;
      PINT     PIE12_RESERVED;
      PINT     PIE13_RESERVED;

// Non-Peripheral Interrupts:
      PINT     XINT13;    // XINT13
      PINT     TINT2;     // CPU-Timer2
      PINT     DATALOG;   // Datalogging interrupt
      PINT     RTOSINT;   // RTOS interrupt
      PINT     EMUINT;    // Emulation interrupt
      PINT     XNMI;      // Non-maskable interrupt
      PINT     ILLEGAL;   // Illegal operation TRAP
      PINT     USER1;     // User Defined trap 1
      PINT     USER2;     // User Defined trap 2
      PINT     USER3;     // User Defined trap 3
      PINT     USER4;     // User Defined trap 4
      PINT     USER5;     // User Defined trap 5
      PINT     USER6;     // User Defined trap 6
      PINT     USER7;     // User Defined trap 7
      PINT     USER8;     // User Defined trap 8
      PINT     USER9;     // User Defined trap 9
      PINT     USER10;    // User Defined trap 10
      PINT     USER11;    // User Defined trap 11
      PINT     USER12;    // User Defined trap 12
      
// Group 1 PIE Peripheral Vectors:
      PINT     SEQ1INT;
      PINT     SEQ2INT;
      PINT     rsvd1_3;
      PINT     XINT1;     
      PINT     XINT2;
      PINT     ADCINT;    // ADC
      PINT     TINT0;     // Timer 0
      PINT     WAKEINT;   // WD
           
// Group 2 PIE Peripheral Vectors:
      PINT     EPWM1_TZINT; // EPWM-1
      PINT     EPWM2_TZINT; // EPWM-2
      PINT     EPWM3_TZINT; // EPWM-3
      PINT     EPWM4_TZINT; // EPWM-4
      PINT     EPWM5_TZINT; // EPWM-5
      PINT     EPWM6_TZINT; // EPWM-6
      PINT     rsvd2_7;    
      PINT     rsvd2_8;
      
// Group 3 PIE Peripheral Vectors:
      PINT     EPWM1_INT;  // EPWM-1
      PINT     EPWM2_INT;  // EPWM-2
      PINT     EPWM3_INT;  // EPWM-3
      PINT     EPWM4_INT;  // EPWM-4
      PINT     EPWM5_INT;  // EPWM-5
      PINT     EPWM6_INT;  // EPWM-6
      PINT     rsvd3_7;   
      PINT     rsvd3_8;
      
// Group 4 PIE Peripheral Vectors:
      PINT     ECAP1_INT; // ECAP-1
      PINT     ECAP2_INT; // ECAP-2
      PINT     ECAP3_INT; // ECAP-3
      PINT     ECAP4_INT; // ECAP-4
      PINT     rsvd4_5;    
      PINT     rsvd4_6;   
      PINT     rsvd4_7;   
      PINT     rsvd4_8;      
     
// Group 5 PIE Peripheral Vectors:
      PINT     EQEP1_INT; // EQEP-1
      PINT     EQEP2_INT; // EQEP-2
      PINT     rsvd5_3;   
      PINT     rsvd5_4;   
      PINT     rsvd5_5;   
      PINT     rsvd5_6;   
      PINT     rsvd5_7;   
      PINT     rsvd5_8;      

// Group 6 PIE Peripheral Vectors:
      PINT     SPIRXINTA; // SPI-A
      PINT     SPITXINTA; // SPI-A
      PINT     SPIRXINTB; // SPI-B
      PINT     SPITXINTB; // SPI-B
      PINT     SPIRXINTC; // SPI-C
      PINT     SPITXINTC; // SPI-C         
      PINT     SPIRXINTD; // SPI-D
      PINT     SPITXINTD; // SPI-D
      
// Group 7 PIE Peripheral Vectors:
      PINT     rsvd7_1;
      PINT     rsvd7_2;
      PINT     rsvd7_3;
      PINT     rsvd7_4;
      PINT     rsvd7_5;
      PINT     rsvd7_6;
      PINT     rsvd7_7;
      PINT     rsvd7_8;

// Group 8 PIE Peripheral Vectors:
      PINT     I2CINT1A;  // I2C-A
      PINT     I2CINT2A;  // I2C-A
      PINT     rsvd8_3;
      PINT     rsvd8_4;
      PINT     rsvd8_5;
      PINT     rsvd8_6;
      PINT     rsvd8_7;
      PINT     rsvd8_8; 

// Group 9 PIE Peripheral Vectors:   
      PINT     SCIRXINTA;  // SCI-A
      PINT     SCITXINTA;  // SCI-A
      PINT     SCIRXINTB;  // SCI-B
      PINT     SCITXINTB;  // SCI-B
      PINT     ECAN0INTA;  // eCAN-A
      PINT     ECAN1INTA;  // eCAN-A
      PINT     ECAN0INTB;  // eCAN-B
      PINT     ECAN1INTB;  // eCAN-B

// Group 10 PIE Peripheral Vectors:
      PINT     rsvd10_1;
      PINT     rsvd10_2;
      PINT     rsvd10_3;
      PINT     rsvd10_4;
      PINT     rsvd10_5;
      PINT     rsvd10_6;
      PINT     rsvd10_7;
      PINT     rsvd10_8;
            
// Group 11 PIE Peripheral Vectors:
      PINT     rsvd11_1;
      PINT     rsvd11_2;
      PINT     rsvd11_3;
      PINT     rsvd11_4;
      PINT     rsvd11_5;
      PINT     rsvd11_6;
      PINT     rsvd11_7;
      PINT     rsvd11_8;

// Group 12 PIE Peripheral Vectors:
      PINT     rsvd12_1;
      PINT     rsvd12_2;
      PINT     rsvd12_3;
      PINT     rsvd12_4;
      PINT     rsvd12_5;
      PINT     rsvd12_6;
      PINT     rsvd12_7;
      PINT     rsvd12_8;
};

//---------------------------------------------------------------------------
// PIE Interrupt Vector Table External References & Function Declarations:
//
extern struct PIE_VECT_TABLE PieVectTable;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif    // end of DSP280x_PIE_VECT_H definition

//===========================================================================
// End of file.
//===========================================================================

//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_Sci.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:31:58 $
//###########################################################################
//
// FILE:	DSP280x_Sci.h
//
// TITLE:	DSP280x Device SCI Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_SCI_H
#define DSP280x_SCI_H


#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// SCI Individual Register Bit Definitions

//----------------------------------------------------------
// SCICCR communication control register bit definitions:
//

struct  SCICCR_BITS {        // bit    description
   Uint16 SCICHAR:3;         // 2:0    Character length control        
   Uint16 ADDRIDLE_MODE:1;   // 3      ADDR/IDLE Mode control
   Uint16 LOOPBKENA:1;       // 4      Loop Back enable
   Uint16 PARITYENA:1;       // 5      Parity enable   
   Uint16 PARITY:1;          // 6      Even or Odd Parity
   Uint16 STOPBITS:1;        // 7      Number of Stop Bits
   Uint16 rsvd1:8;           // 15:8   reserved
}; 


union SCICCR_REG {
   Uint16              all;
   struct SCICCR_BITS  bit;
};

//-------------------------------------------
// SCICTL1 control register 1 bit definitions:
//
                       
struct  SCICTL1_BITS {       // bit    description
   Uint16 RXENA:1;           // 0      SCI receiver enable
   Uint16 TXENA:1;           // 1      SCI transmitter enable
   Uint16 SLEEP:1;           // 2      SCI sleep  
   Uint16 TXWAKE:1;          // 3      Transmitter wakeup method
   Uint16 rsvd:1;            // 4      reserved
   Uint16 SWRESET:1;         // 5      Software reset   
   Uint16 RXERRINTENA:1;     // 6      Recieve interrupt enable
   Uint16 rsvd1:9;           // 15:7   reserved

}; 

union SCICTL1_REG {
   Uint16               all;
   struct SCICTL1_BITS  bit;
};

//---------------------------------------------
// SCICTL2 control register 2 bit definitions:
// 

struct  SCICTL2_BITS {       // bit    description
   Uint16 TXINTENA:1;        // 0      Transmit interrupt enable    
   Uint16 RXBKINTENA:1;      // 1      Receiver-buffer break enable
   Uint16 rsvd:4;            // 5:2    reserved
   Uint16 TXEMPTY:1;         // 6      Transmitter empty flag
   Uint16 TXRDY:1;           // 7      Transmitter ready flag  
   Uint16 rsvd1:8;           // 15:8   reserved

}; 

union SCICTL2_REG {
   Uint16               all;
   struct SCICTL2_BITS  bit;
};

//---------------------------------------------------
// SCIRXST Receiver status register bit definitions:
//

struct  SCIRXST_BITS {       // bit    description
   Uint16 rsvd:1;            // 0      reserved
   Uint16 RXWAKE:1;          // 1      Receiver wakeup detect flag
   Uint16 PE:1;              // 2      Parity error flag
   Uint16 OE:1;              // 3      Overrun error flag
   Uint16 FE:1;              // 4      Framing error flag
   Uint16 BRKDT:1;           // 5      Break-detect flag   
   Uint16 RXRDY:1;           // 6      Receiver ready flag
   Uint16 RXERROR:1;         // 7      Receiver error flag

}; 

union SCIRXST_REG {
   Uint16               all;
   struct SCIRXST_BITS  bit;
};

//----------------------------------------------------
// SCIRXBUF Receiver Data Buffer with FIFO bit definitions:
// 

struct  SCIRXBUF_BITS {      // bits   description
   Uint16 RXDT:8;            // 7:0    Receive word
   Uint16 rsvd:6;            // 13:8   reserved
   Uint16 SCIFFPE:1;         // 14     SCI PE error in FIFO mode
   Uint16 SCIFFFE:1;         // 15     SCI FE error in FIFO mode
};

union SCIRXBUF_REG {
   Uint16                all;
   struct SCIRXBUF_BITS  bit;
};

//--------------------------------------------------
// SCIPRI Priority control register bit definitions:
// 
//
                                                   
struct  SCIPRI_BITS {        // bit    description
   Uint16 rsvd:3;            // 2:0    reserved
   Uint16 FREE:1;            // 3      Free emulation suspend mode
   Uint16 SOFT:1;            // 4      Soft emulation suspend mode
   Uint16 rsvd1:3;           // 7:5    reserved
}; 

union SCIPRI_REG {
   Uint16              all;
   struct SCIPRI_BITS  bit;
};

//-------------------------------------------------
// SCI FIFO Transmit register bit definitions:
// 
//
                                                  
struct  SCIFFTX_BITS {       // bit    description
   Uint16 TXFFIL:5;          // 4:0    Interrupt level
   Uint16 TXFFIENA:1;        // 5      Interrupt enable
   Uint16 TXFFINTCLR:1;      // 6      Clear INT flag
   Uint16 TXFFINT:1;         // 7      INT flag
   Uint16 TXFFST:5;          // 12:8   FIFO status
   Uint16 TXFIFOXRESET:1;    // 13     FIFO reset
   Uint16 SCIFFENA:1;        // 14     Enhancement enable
   Uint16 SCIRST:1;          // 15     SCI reset rx/tx channels 

}; 

union SCIFFTX_REG {
   Uint16               all;
   struct SCIFFTX_BITS  bit;
};

//------------------------------------------------
// SCI FIFO recieve register bit definitions:
// 
//
                                               
struct  SCIFFRX_BITS {       // bits   description
   Uint16 RXFFIL:5;          // 4:0    Interrupt level
   Uint16 RXFFIENA:1;        // 5      Interrupt enable
   Uint16 RXFFINTCLR:1;      // 6      Clear INT flag
   Uint16 RXFFINT:1;         // 7      INT flag
   Uint16 RXFFST:5;          // 12:8   FIFO status
   Uint16 RXFIFORESET:1;     // 13     FIFO reset
   Uint16 RXFFOVRCLR:1;      // 14     Clear overflow
   Uint16 RXFFOVF:1;         // 15     FIFO overflow

}; 

union SCIFFRX_REG {
   Uint16               all;
   struct SCIFFRX_BITS  bit;
};

// SCI FIFO control register bit definitions:
struct  SCIFFCT_BITS {     // bits   description
   Uint16 FFTXDLY:8;         // 7:0    FIFO transmit delay
   Uint16 rsvd:5;            // 12:8   reserved
   Uint16 CDC:1;             // 13     Auto baud mode enable
   Uint16 ABDCLR:1;          // 14     Auto baud clear
   Uint16 ABD:1;             // 15     Auto baud detect
};

union SCIFFCT_REG {
   Uint16               all;
   struct SCIFFCT_BITS  bit;
};

//---------------------------------------------------------------------------
// SCI Register File:
//
struct  SCI_REGS {
   union SCICCR_REG     SCICCR;     // Communications control register
   union SCICTL1_REG    SCICTL1;    // Control register 1
   Uint16               SCIHBAUD;   // Baud rate (high) register
   Uint16               SCILBAUD;   // Baud rate (low) register
   union SCICTL2_REG    SCICTL2;    // Control register 2
   union SCIRXST_REG    SCIRXST;    // Recieve status register
   Uint16               SCIRXEMU;   // Recieve emulation buffer register
   union SCIRXBUF_REG   SCIRXBUF;   // Recieve data buffer  
   Uint16               rsvd1;      // reserved
   Uint16               SCITXBUF;   // Transmit data buffer 
   union SCIFFTX_REG    SCIFFTX;    // FIFO transmit register
   union SCIFFRX_REG    SCIFFRX;    // FIFO recieve register
   union SCIFFCT_REG    SCIFFCT;    // FIFO control register
   Uint16               rsvd2;      // reserved
   Uint16               rsvd3;      // reserved
   union SCIPRI_REG     SCIPRI;     // FIFO Priority control   
};

//---------------------------------------------------------------------------
// SCI External References & Function Declarations:
//
extern volatile struct SCI_REGS SciaRegs;
extern volatile struct SCI_REGS ScibRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_SCI_H definition

//===========================================================================
// End of file.
//===========================================================================

//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_Spi.h 
// TI File $Revision: /main/2 $
// Checkin $Date: April 18, 2005   09:43:45 $
//###########################################################################
//
// FILE:   DSP280x_Spi.h
//
// TITLE:  DSP280x Device SPI Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_SPI_H
#define DSP280x_SPI_H


#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SPI Individual Register Bit Definitions:
//
// SPI FIFO Transmit register bit    definitions:
struct  SPIFFTX_BITS {       // bit    description
   Uint16 TXFFIL:5;          // 4:0    Interrupt level
   Uint16 TXFFIENA:1;        // 5      Interrupt enable
   Uint16 TXFFINTCLR:1;      // 6      Clear INT flag
   Uint16 TXFFINT:1;         // 7      INT flag
   Uint16 TXFFST:5;          // 12:8   FIFO status
   Uint16 TXFIFO:1;          // 13     FIFO reset
   Uint16 SPIFFENA:1;        // 14     Enhancement enable
   Uint16 SPIRST:1;          // 15     Reset SPI
}; 

union SPIFFTX_REG {
   Uint16               all;
   struct SPIFFTX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO recieve register bit definitions:
// 
//
struct  SPIFFRX_BITS {       // bits   description
   Uint16 RXFFIL:5;          // 4:0    Interrupt level
   Uint16 RXFFIENA:1;        // 5      Interrupt enable
   Uint16 RXFFINTCLR:1;      // 6      Clear INT flag
   Uint16 RXFFINT:1;         // 7      INT flag
   Uint16 RXFFST:5;          // 12:8   FIFO status
   Uint16 RXFIFORESET:1;     // 13     FIFO reset
   Uint16 RXFFOVFCLR:1;      // 14     Clear overflow
   Uint16 RXFFOVF:1;         // 15     FIFO overflow

}; 

union SPIFFRX_REG {
   Uint16               all;
   struct SPIFFRX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO control register bit definitions:
// 
//
struct  SPIFFCT_BITS {       // bits   description
   Uint16 TXDLY:8;           // 7:0    FIFO transmit delay
   Uint16 rsvd:8;            // 15:8   reserved
};

union SPIFFCT_REG {
   Uint16               all;
   struct SPIFFCT_BITS  bit;
};
   
//---------------------------------------------
// SPI configuration register bit definitions:
// 
//
struct  SPICCR_BITS {        // bits   description
   Uint16 SPICHAR:4;         // 3:0    Character length control
   Uint16 SPILBK:1;          // 4      Loop-back enable/disable
   Uint16 rsvd1:1;           // 5      reserved
   Uint16 CLKPOLARITY:1;     // 6      Clock polarity
   Uint16 SPISWRESET:1;      // 7      SPI SW Reset
   Uint16 rsvd2:8;           // 15:8   reserved   
};

union SPICCR_REG {
   Uint16              all;
   struct SPICCR_BITS  bit;
};

//-------------------------------------------------
// SPI operation control register bit definitions:
// 
//
struct  SPICTL_BITS {        // bits   description
   Uint16 SPIINTENA:1;       // 0      Interrupt enable
   Uint16 TALK:1;            // 1      Master/Slave transmit enable
   Uint16 MASTER_SLAVE:1;    // 2      Network control mode
   Uint16 CLK_PHASE:1;       // 3      Clock phase select
   Uint16 OVERRUNINTENA:1;   // 4      Overrun interrupt enable
   Uint16 rsvd:11;           // 15:5   reserved      
};

union SPICTL_REG {
   Uint16              all;
   struct SPICTL_BITS  bit;
};

//--------------------------------------
// SPI status register bit definitions:
// 
//
struct  SPISTS_BITS {        // bits   description
   Uint16 rsvd1:5;           // 4:0    reserved
   Uint16 BUFFULL_FLAG:1;    // 5      SPI transmit buffer full flag
   Uint16 INT_FLAG:1;        // 6      SPI interrupt flag
   Uint16 OVERRUN_FLAG:1;    // 7      SPI reciever overrun flag
   Uint16 rsvd2:8;           // 15:8   reserved   
};

union SPISTS_REG {
   Uint16              all;
   struct SPISTS_BITS  bit;
}; 

//------------------------------------------------
// SPI priority control register bit definitions:
// 
//
struct  SPIPRI_BITS {        // bits   description
   Uint16 rsvd1:4;           // 3:0    reserved
   Uint16 FREE:1;            // 4      Free emulation mode control
   Uint16 SOFT:1;            // 5      Soft emulation mode control
   Uint16 PRIORITY:1;        // 6      Interrupt priority select
   Uint16 rsvd2:9;           // 15:7   reserved
};

union SPIPRI_REG {
   Uint16              all;
   struct SPIPRI_BITS  bit;
};       

//---------------------------------------------------------------------------
// SPI Register File:
//
struct  SPI_REGS { 
   union SPICCR_REG     SPICCR;      // Configuration register 
   union SPICTL_REG     SPICTL;      // Operation control register
   union SPISTS_REG     SPISTS;      // Status register
   Uint16               rsvd1;       // reserved
   Uint16               SPIBRR;      // Baud Rate
   Uint16               rsvd2;       // reserved
   Uint16               SPIRXEMU;    // Emulation buffer
   Uint16               SPIRXBUF;    // Serial input buffer
   Uint16               SPITXBUF;    // Serial output buffer
   Uint16               SPIDAT;      // Serial data 
   union SPIFFTX_REG    SPIFFTX;     // FIFO transmit register
   union SPIFFRX_REG    SPIFFRX;     // FIFO recieve register
   union SPIFFCT_REG    SPIFFCT;     // FIFO control register
   Uint16               rsvd3[2];    // reserved
   union SPIPRI_REG     SPIPRI;      // FIFO Priority control
};

//---------------------------------------------------------------------------
// SPI External References & Function Declarations:
//
extern volatile struct SPI_REGS SpiaRegs;
extern volatile struct SPI_REGS SpibRegs;
extern volatile struct SPI_REGS SpicRegs;
extern volatile struct SPI_REGS SpidRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_SPI_H definition

//===========================================================================
// End of file.
//===========================================================================

//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_SysCtrl.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:32:04 $
//###########################################################################
//
// FILE:   DSP280x_SysCtrl.h
//
// TITLE:  DSP280x Device System Control Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_SYS_CTRL_H
#define DSP280x_SYS_CTRL_H


#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// System Control Individual Register Bit Definitions:
//

// XCLKOUT Control
struct XCLK_BITS   {    // bits  description
   Uint16 XCLKOUTDIV:2; // 1:0   XCLKOUT Divide Ratio
   Uint16 XCLKOUTDAT:1; // 2     Status of XCLKOUT
   Uint16 X1DAT:1;      // 3     Output of the oscillator cell
   Uint16 XCLKINDAT:1;  // 4     Status of the XCLKIN pin
   Uint16 rsvd1:3;      // 7:5   reserved
   Uint16 X1CNT:4;      // 11:8  4-bit counter
   Uint16 XCLKINCNT:4;  // 15:12 4-bit counter
};

union XCLK_REG {
   Uint16              all;
   struct XCLK_BITS    bit;
};

// PLL Status Register
struct PLLSTS_BITS   {    // bits  description
   Uint16 PLLLOCKS:1;     // 0     PLL lock status
   Uint16 rsvd1:1;        // 1     reserved
   Uint16 PLLOFF:1;       // 2     PLL off bit
   Uint16 MCLKSTS:1;      // 3     Missing clock status bit
   Uint16 MCLKCLR:1;      // 4     Missing clock clear bit
   Uint16 OSCOFF:1;       // 5     Oscillator clock off
   Uint16 MCLKOFF:1;      // 6     Missing clock detect
   Uint16 rsvd2:9;        // 15:7  reserved
};
   
union PLLSTS_REG {
   Uint16              all;
   struct PLLSTS_BITS  bit;
};   

// High speed peripheral clock register bit definitions:
struct HISPCP_BITS  {   // bits  description
   Uint16 HSPCLK:3;     // 2:0   Rate relative to SYSCLKOUT
   Uint16 rsvd1:13;     // 15:3  reserved
};

union HISPCP_REG {
   Uint16              all;
   struct HISPCP_BITS  bit;
};

// Low speed peripheral clock register bit definitions:
struct LOSPCP_BITS  {   // bits  description
   Uint16 LSPCLK:3;     // 2:0   Rate relative to SYSCLKOUT
   Uint16 rsvd1:13;     // 15:3  reserved
};

union LOSPCP_REG {
   Uint16              all;
   struct LOSPCP_BITS  bit;
};

// Peripheral clock control register 0 bit definitions:
struct PCLKCR0_BITS  {  // bits  description
   Uint16 rsvd1:2;      // 1:0   reserved
   Uint16 TBCLKSYNC:1;  // 2     EWPM Module TBCLK enable/sync 
   Uint16 ADCENCLK:1;   // 3     Enable high speed clk to ADC
   Uint16 I2CAENCLK:1;  // 4     Enable SYSCLKOUT to I2C-A
   Uint16 rsvd2:1;      // 5     reserved
   Uint16 SPICENCLK:1;  // 6     Enable low speed clk to SPI-C
   Uint16 SPIDENCLK:1;  // 7     Enable low speed clk to SPI-D
   Uint16 SPIAENCLK:1;  // 8     Enable low speed clk to SPI-A
   Uint16 SPIBENCLK:1;  // 9     Enable low speed clk to SPI-B   
   Uint16 SCIAENCLK:1;  // 10    Enable low speed clk to SCI-A
   Uint16 SCIBENCLK:1;  // 11    Enable low speed clk to SCI-B
   Uint16 rsvd3:2;      // 13:12 reserved
   Uint16 ECANAENCLK:1; // 14    Enable system clk to eCAN-A
   Uint16 ECANBENCLK:1; // 15    Enable system clk to eCAN-B
};

union PCLKCR0_REG {
   Uint16              all;
   struct PCLKCR0_BITS bit;
};   

// Peripheral clock control register 1 bit definitions:
struct PCLKCR1_BITS  {    // bits  description
   Uint16 EPWM1ENCLK:1;   // 0     Enable SYSCLKOUT to EPWM1
   Uint16 EPWM2ENCLK:1;   // 1     Enable SYSCLKOUT to EPWM2
   Uint16 EPWM3ENCLK:1;   // 2     Enable SYSCLKOUT to EPWM3
   Uint16 EPWM4ENCLK:1;   // 3     Enable SYSCLKOUT to EPWM4
   Uint16 EPWM5ENCLK:1;   // 4     Enable SYSCLKOUT to EPWM5
   Uint16 EPWM6ENCLK:1;   // 5     Enable SYSCLKOUT to EPWM6               
   Uint16 rsvd1:2;        // 7:6   reserved
   Uint16 ECAP1ENCLK:1;   // 8     Enable SYSCLKOUT to ECAP1   
   Uint16 ECAP2ENCLK:1;   // 9     Enable SYSCLKOUT to ECAP2   
   Uint16 ECAP3ENCLK:1;   // 10    Enable SYSCLKOUT to ECAP3   
   Uint16 ECAP4ENCLK:1;   // 11    Enable SYSCLKOUT to ECAP4   
   Uint16 rsvd2:2;        // 13:12 reserved
   Uint16 EQEP1ENCLK:1;   // 11    Enable SYSCLKOUT to EQEP1      
   Uint16 EQEP2ENCLK:1;   // 11    Enable SYSCLKOUT to EQEP2         
};

union PCLKCR1_REG {
   Uint16              all;
   struct PCLKCR1_BITS bit;
}; 


// PLL control register bit definitions:
struct PLLCR_BITS {      // bits  description
   Uint16 DIV:4;         // 3:0   Set clock ratio for the PLL
   Uint16 rsvd1:12;      // 15:4  reserved
};

union PLLCR_REG {
   Uint16             all;
   struct PLLCR_BITS  bit;
};

// Low Power Mode 0 control register bit definitions:
struct LPMCR0_BITS {     // bits  description
   Uint16 LPM:2;         // 1:0   Set the low power mode
   Uint16 QUALSTDBY:6;   // 7:2   Qualification   
   Uint16 rsvd1:7;       // 14:8  reserved
   Uint16 WDINTE:1;      // 15    Enables WD to wake the device from STANDBY
};

union LPMCR0_REG {
   Uint16              all;
   struct LPMCR0_BITS  bit;
};

//---------------------------------------------------------------------------
// System Control Register File:
//
struct SYS_CTRL_REGS {
   union   XCLK_REG    XCLK;      // 0
   union   PLLSTS_REG  PLLSTS;    // 1
   Uint16              rsvd1[8];  // 2-9
   union   HISPCP_REG  HISPCP;    // 10: High-speed peripheral clock pre-scaler
   union   LOSPCP_REG  LOSPCP;    // 11: Low-speed peripheral clock pre-scaler
   union   PCLKCR0_REG PCLKCR0;   // 12: Peripheral clock control register
   union   PCLKCR1_REG PCLKCR1;   // 13: Peripheral clock control register
   union   LPMCR0_REG  LPMCR0;    // 14: Low-power mode control register 0
   Uint16              rsvd2;     // 15: reserved
   Uint16              rsvd3;     // 16: reserved
   union   PLLCR_REG   PLLCR;     // 17: PLL control register
   // No bit definitions are defined for SCSR because
   // a read-modify-write instruction can clear the WDOVERRIDE bit
   Uint16              SCSR;      // 18: System control and status register
   Uint16              WDCNTR;    // 19: WD counter register
   Uint16              rsvd4;     // 20
   Uint16              WDKEY;     // 21: WD reset key register
   Uint16              rsvd5[3];  // 22-24
   // No bit definitions are defined for WDCR because
   // the proper value must be written to the WDCHK field
   // whenever writing to this register. 
   Uint16              WDCR;      // 25: WD timer control register
   Uint16              rsvd6[6];  // 26-31
};


/* --------------------------------------------------- */
/* CSM Registers                                       */
/*                                                     */
/* ----------------------------------------------------*/

/* CSM Status & Control register bit definitions */
struct  CSMSCR_BITS {      // bit   description
   Uint16     SECURE:1;    // 0     Secure flag
   Uint16     rsvd1:14;    // 14-1  reserved
   Uint16     FORCESEC:1;  // 15    Force Secure control bit

}; 

/* Allow access to the bit fields or entire register */
union CSMSCR_REG {
   Uint16             all;
   struct CSMSCR_BITS bit;
};

/* CSM Register File */ 
struct  CSM_REGS {      
   Uint16           KEY0;    // KEY reg bits 15-0 
   Uint16           KEY1;    // KEY reg bits 31-16 
   Uint16           KEY2;    // KEY reg bits 47-32
   Uint16           KEY3;    // KEY reg bits 63-48
   Uint16           KEY4;    // KEY reg bits 79-64
   Uint16           KEY5;    // KEY reg bits 95-80
   Uint16           KEY6;    // KEY reg bits 111-96
   Uint16           KEY7;    // KEY reg bits 127-112
   Uint16           rsvd1;   // reserved
   Uint16           rsvd2;   // reserved
   Uint16           rsvd3;   // reserved
   Uint16           rsvd4;   // reserved
   Uint16           rsvd5;   // reserved
   Uint16           rsvd6;   // reserved
   Uint16           rsvd7;   // reserved 
   union CSMSCR_REG CSMSCR;  // CSM Status & Control register
};

/* Password locations */
struct  CSM_PWL {
   Uint16   PSWD0;  // PSWD bits 15-0
   Uint16   PSWD1;  // PSWD bits 31-16
   Uint16   PSWD2;  // PSWD bits 47-32
   Uint16   PSWD3;  // PSWD bits 63-48
   Uint16   PSWD4;  // PSWD bits 79-64
   Uint16   PSWD5;  // PSWD bits 95-80
   Uint16   PSWD6;  // PSWD bits 111-96
   Uint16   PSWD7;  // PSWD bits 127-112
};



/* Flash Registers */

#define FLASH_SLEEP   0x0000;
#define FLASH_STANDBY 0x0001;
#define FLASH_ACTIVE  0x0003;


/* Flash Option Register bit definitions */
struct  FOPT_BITS {       // bit   description
   Uint16     ENPIPE:1;   // 0     Enable Pipeline Mode
   Uint16     rsvd:15;    // 1-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOPT_REG {
   Uint16           all;
   struct FOPT_BITS bit;
};

/* Flash Power Modes Register bit definitions */
struct  FPWR_BITS {       // bit   description
   Uint16     PWR:2;      // 0-1   Power Mode bits
   Uint16     rsvd:14;    // 2-15  reserved
};

/* Allow access to the bit fields or entire register */
union FPWR_REG {
   Uint16           all;
   struct FPWR_BITS bit;
};


/* Flash Status Register bit definitions */
struct  FSTATUS_BITS {       // bit   description
   Uint16     PWRS:2;        // 0-1   Power Mode Status bits
   Uint16     STDBYWAITS:1;  // 2     Bank/Pump Sleep to Standby Wait Counter Status bits
   Uint16     ACTIVEWAITS:1; // 3     Bank/Pump Standby to Active Wait Counter Status bits
   Uint16     rsvd1:4;       // 4-7   reserved
   Uint16     V3STAT:1;      // 8     VDD3V Status Latch bit
   Uint16     rsvd2:7;       // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTATUS_REG {
   Uint16              all;
   struct FSTATUS_BITS bit;
};

/* Flash Sleep to Standby Wait Counter Register bit definitions */
struct  FSTDBYWAIT_BITS {    // bit   description
   Uint16     STDBYWAIT:8;   // 0-7   Bank/Pump Sleep to Standby Wait Count bits
   Uint16     rsvd:8;        // 8-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTDBYWAIT_REG {
   Uint16                 all;
   struct FSTDBYWAIT_BITS bit;
};

/* Flash Standby to Active Wait Counter Register bit definitions */
struct  FACTIVEWAIT_BITS {   // bit   description
   Uint16     ACTIVEWAIT:8;  // 0-7   Bank/Pump Standby to Active Wait Count bits
   Uint16     rsvd:8;        // 8-15  reserved
};

/* Allow access to the bit fields or entire register */
union FACTIVEWAIT_REG {
   Uint16                  all;
   struct FACTIVEWAIT_BITS bit;
};

/* Bank Read Access Wait State Register bit definitions */
struct  FBANKWAIT_BITS {     // bit   description
   Uint16     RANDWAIT:4;    // 0-3   Flash Random Read Wait State bits
   Uint16     rsvd1:4;       // 4-7   reserved
   Uint16     PAGEWAIT:4;    // 8-11  Flash Paged Read Wait State bits
   Uint16     rsvd2:4;       // 12-15 reserved
};

/* Allow access to the bit fields or entire register */
union FBANKWAIT_REG {
   Uint16                all;
   struct FBANKWAIT_BITS bit;
};

/* OTP Read Access Wait State Register bit definitions */
struct  FOTPWAIT_BITS {      // bit   description
   Uint16     OTPWAIT:5;     // 0-4   OTP Read Wait State bits
   Uint16     rsvd:11;       // 5-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOTPWAIT_REG {
   Uint16               all;
   struct FOTPWAIT_BITS bit;
};


struct FLASH_REGS {
   union FOPT_REG        FOPT;        // Option Register
   Uint16                rsvd1;       // reserved
   union FPWR_REG        FPWR;        // Power Modes Register
   union FSTATUS_REG     FSTATUS;     // Status Register
   union FSTDBYWAIT_REG  FSTDBYWAIT;  // Pump/Bank Sleep to Standby Wait State Register
   union FACTIVEWAIT_REG FACTIVEWAIT; // Pump/Bank Standby to Active Wait State Register
   union FBANKWAIT_REG   FBANKWAIT;   // Bank Read Access Wait State Register
   union FOTPWAIT_REG    FOTPWAIT;    // OTP Read Access Wait State Register
};

//---------------------------------------------------------------------------
// System Control External References & Function Declarations:
//
extern volatile struct SYS_CTRL_REGS SysCtrlRegs;
extern volatile struct CSM_REGS CsmRegs;
extern volatile struct CSM_PWL CsmPwl;
extern volatile struct FLASH_REGS FlashRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_SYS_CTRL_H definition

//===========================================================================
// End of file.
//===========================================================================

//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_headers\include\DSP280x_XIntrupt.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   12:32:06 $
//###########################################################################
//
// FILE:  DSP280x_XIntrupt.h
//
// TITLE: DSP280x Device External Interrupt Register Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_XINTRUPT_H
#define DSP280x_XINTRUPT_H


#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------

struct XINTCR_BITS {
    Uint16   ENABLE:1;    // 0      enable/disable
    Uint16   rsvd1:1;     // 1      reserved
    Uint16   POLARITY:2;  // 3:2    pos/neg, both triggered
    Uint16   rsvd2:12;    //15:4    reserved
};

union XINTCR_REG {
   Uint16               all;
   struct XINTCR_BITS   bit;
};  

struct XNMICR_BITS {
    Uint16   ENABLE:1;    // 0      enable/disable
    Uint16   SELECT:1;    // 1      Timer 1 or XNMI connected to INT13
    Uint16   POLARITY:2;  // 3:2    pos/neg, or both triggered
    Uint16   rsvd2:12;    // 15:4   reserved
};

union XNMICR_REG {
   Uint16               all;
   struct XNMICR_BITS   bit;
};  




//---------------------------------------------------------------------------
// External Interrupt Register File:
//
struct XINTRUPT_REGS {
   union XINTCR_REG XINT1CR;
   union XINTCR_REG XINT2CR;
   Uint16           rsvd1[5];
   union XNMICR_REG XNMICR;
   Uint16           XINT1CTR;
   Uint16           XINT2CTR;
   Uint16           rsvd[5];
   Uint16           XNMICTR;
};

//---------------------------------------------------------------------------
// External Interrupt References & Function Declarations:
//
extern volatile struct XINTRUPT_REGS XIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_XINTF_H definition

//===========================================================================
// End of file.
//===========================================================================

//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\DSP280x_DefaultIsr.h 
// TI File $Revision: /main/2 $
// Checkin $Date: December 1, 2004   16:21:01 $
//###########################################################################
//
// FILE:    DSP280x_DefaultIsr.h
//
// TITLE:   DSP280x Devices Default Interrupt Service Routines Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280X_DEFAULT_ISR_H
#define DSP280X_DEFAULT_ISR_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// Default Interrupt Service Routine Declarations:
// 
// The following function prototypes are for the 
// default ISR routines used with the default PIE vector table.
// This default vector table is found in the DSP280x_PieVect.h 
// file.  
//

// Non-Peripheral Interrupts:
interrupt void INT13_ISR(void);     // XINT13 or CPU-Timer 1
interrupt void INT14_ISR(void);     // CPU-Timer2
interrupt void DATALOG_ISR(void);   // Datalogging interrupt
interrupt void RTOSINT_ISR(void);   // RTOS interrupt
interrupt void EMUINT_ISR(void);    // Emulation interrupt
interrupt void NMI_ISR(void);       // Non-maskable interrupt
interrupt void ILLEGAL_ISR(void);   // Illegal operation TRAP
interrupt void USER1_ISR(void);     // User Defined trap 1
interrupt void USER2_ISR(void);     // User Defined trap 2
interrupt void USER3_ISR(void);     // User Defined trap 3
interrupt void USER4_ISR(void);     // User Defined trap 4
interrupt void USER5_ISR(void);     // User Defined trap 5
interrupt void USER6_ISR(void);     // User Defined trap 6
interrupt void USER7_ISR(void);     // User Defined trap 7
interrupt void USER8_ISR(void);     // User Defined trap 8
interrupt void USER9_ISR(void);     // User Defined trap 9
interrupt void USER10_ISR(void);    // User Defined trap 10
interrupt void USER11_ISR(void);    // User Defined trap 11
interrupt void USER12_ISR(void);    // User Defined trap 12

// Group 1 PIE Interrupt Service Routines:
interrupt void  SEQ1INT_ISR(void);   // ADC Sequencer 1 ISR
interrupt void  SEQ2INT_ISR(void);   // ADC Sequencer 2 ISR
interrupt void  XINT1_ISR(void);     // External interrupt 1
interrupt void  XINT2_ISR(void);     // External interrupt 2
interrupt void  ADCINT_ISR(void);    // ADC
interrupt void  TINT0_ISR(void);     // Timer 0
interrupt void  WAKEINT_ISR(void);   // WD

// Group 2 PIE Interrupt Service Routines:
interrupt void EPWM1_TZINT_ISR(void);    // EPWM-1
interrupt void EPWM2_TZINT_ISR(void);    // EPWM-2
interrupt void EPWM3_TZINT_ISR(void);    // EPWM-3
interrupt void EPWM4_TZINT_ISR(void);    // EPWM-4
interrupt void EPWM5_TZINT_ISR(void);    // EPWM-5
interrupt void EPWM6_TZINT_ISR(void);    // EPWM-6
      
// Group 3 PIE Interrupt Service Routines:
interrupt void EPWM1_INT_ISR(void);    // EPWM-1
interrupt void EPWM2_INT_ISR(void);    // EPWM-2
interrupt void EPWM3_INT_ISR(void);    // EPWM-3
interrupt void EPWM4_INT_ISR(void);    // EPWM-4
interrupt void EPWM5_INT_ISR(void);    // EPWM-5
interrupt void EPWM6_INT_ISR(void);    // EPWM-6
      
// Group 4 PIE Interrupt Service Routines:
interrupt void ECAP1_INT_ISR(void);    // ECAP-1
interrupt void ECAP2_INT_ISR(void);    // ECAP-2
interrupt void ECAP3_INT_ISR(void);    // ECAP-3
interrupt void ECAP4_INT_ISR(void);    // ECAP-4
     
// Group 5 PIE Interrupt Service Routines:
interrupt void EQEP1_INT_ISR(void);    // EQEP-1
interrupt void EQEP2_INT_ISR(void);    // EQEP-2

// Group 6 PIE Interrupt Service Routines:
interrupt void SPIRXINTA_ISR(void);   // SPI-A
interrupt void SPITXINTA_ISR(void);   // SPI-A
interrupt void SPIRXINTB_ISR(void);   // SPI-B
interrupt void SPITXINTB_ISR(void);   // SPI-B
interrupt void SPIRXINTC_ISR(void);   // SPI-C
interrupt void SPITXINTC_ISR(void);   // SPI-C
interrupt void SPIRXINTD_ISR(void);   // SPI-D
interrupt void SPITXINTD_ISR(void);   // SPI-D

// Group 7 PIE Interrupt Service Routines: 

// Group 8 PIE Interrupt Service Routines: 
interrupt void I2CINT1A_ISR(void);     // I2C-A
interrupt void I2CINT2A_ISR(void);     // I2C-A
   
// Group 9 PIE Interrupt Service Routines:
interrupt void SCIRXINTA_ISR(void); // SCI-A
interrupt void SCITXINTA_ISR(void); // SCI-A
interrupt void SCIRXINTB_ISR(void); // SCI-B
interrupt void SCITXINTB_ISR(void); // SCI-B
interrupt void ECAN0INTA_ISR(void); // eCAN-A
interrupt void ECAN1INTA_ISR(void); // eCAN-A
interrupt void ECAN0INTB_ISR(void); // eCAN-B
interrupt void ECAN1INTB_ISR(void); // eCAN-B

// Group 10 PIE Interrupt Service Routines:
 
// Group 11 PIE Interrupt Service Routines: 

// Group 12 PIE Interrupt Service Routines: 

// Catch-all for Reserved Locations For testing purposes:
interrupt void PIE_RESERVED(void);       // Reserved for test
interrupt void rsvd_ISR(void);           // for test
interrupt void INT_NOTUSED_ISR(void);    // for unused interrupts

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif    // end of DSP280x_DEFAULT_ISR_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\DSP280x_EPwm_defines.h 
// TI File $Revision: /main/4 $
// Checkin $Date: April 8, 2005   15:29:44 $
//###########################################################################
//
// FILE:   DSP280X_EPwm_defines.h
//
// TITLE:  #defines used in ePWM examples examples
// 
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280X_EPWM_DEFINES_H
#define DSP280X_EPWM_DEFINES_H


#ifdef __cplusplus
extern "C" {
#endif

// TBCTL (Time-Base Control)
//==========================
// CTRMODE bits
#define	TB_COUNT_UP		0x0
#define	TB_COUNT_DOWN	0x1
#define	TB_COUNT_UPDOWN	0x2
#define	TB_FREEZE		0x3
// PHSEN bit
#define	TB_DISABLE		0x0
#define	TB_ENABLE		0x1
// PRDLD bit
#define	TB_SHADOW		0x0
#define	TB_IMMEDIATE	0x1
// SYNCOSEL bits
#define	TB_SYNC_IN		0x0
#define	TB_CTR_ZERO		0x1
#define	TB_CTR_CMPB		0x2
#define	TB_SYNC_DISABLE	0x3
// HSPCLKDIV and CLKDIV bits
#define	TB_DIV1			0x0
#define	TB_DIV2			0x1
#define	TB_DIV4			0x2
// PHSDIR bit
#define	TB_DOWN			0x0
#define	TB_UP			0x1

// CMPCTL (Compare Control)
//==========================
// LOADAMODE and LOADBMODE bits
#define	CC_CTR_ZERO		0x0
#define	CC_CTR_PRD		0x1
#define	CC_CTR_ZERO_PRD	0x2
#define	CC_LD_DISABLE	0x3
// SHDWAMODE and SHDWBMODE bits
#define	CC_SHADOW		0x0
#define	CC_IMMEDIATE	0x1

// AQCTLA and AQCTLB (Action Qualifier Control)
//=============================================
// ZRO, PRD, CAU, CAD, CBU, CBD bits
#define	AQ_NO_ACTION	0x0
#define	AQ_CLEAR		0x1
#define	AQ_SET			0x2
#define	AQ_TOGGLE		0x3

// DBCTL (Dead-Band Control)
//==========================
// OUT MODE bits
#define	DB_DISABLE		0x0
#define	DBA_ENABLE		0x1
#define	DBB_ENABLE		0x2
#define	DB_FULL_ENABLE	0x3
// POLSEL bits
#define	DB_ACTV_HI		0x0
#define	DB_ACTV_LOC		0x1
#define	DB_ACTV_HIC		0x2
#define	DB_ACTV_LO		0x3
// IN MODE
#define DBA_ALL         0x0
#define DBB_RED_DBA_FED 0x1
#define DBA_RED_DBB_FED 0x2
#define DBB_ALL         0x3

// CHPCTL (chopper control)
//==========================
// CHPEN bit
#define	CHP_DISABLE		0x0
#define	CHP_ENABLE		0x1
// CHPFREQ bits
#define	CHP_DIV1		0x0
#define	CHP_DIV2		0x1
#define	CHP_DIV3		0x2
#define	CHP_DIV4		0x3
#define	CHP_DIV5		0x4
#define	CHP_DIV6		0x5
#define	CHP_DIV7		0x6
#define	CHP_DIV8		0x7
// CHPDUTY bits
#define	CHP1_8TH		0x0
#define	CHP2_8TH		0x1
#define	CHP3_8TH		0x2
#define	CHP4_8TH		0x3
#define	CHP5_8TH		0x4
#define	CHP6_8TH		0x5
#define	CHP7_8TH		0x6

// TZSEL (Trip Zone Select)
//==========================
// CBCn and OSHTn bits
#define	TZ_DISABLE		0x0
#define	TZ_ENABLE		0x1

// TZCTL (Trip Zone Control)
//==========================
// TZA and TZB bits
#define	TZ_HIZ			0x0
#define	TZ_FORCE_HI		0x1
#define	TZ_FORCE_LO		0x2
#define	TZ_NO_CHANGE	0x3

// ETSEL (Event Trigger Select)
//=============================
#define	ET_CTR_ZERO		0x1
#define	ET_CTR_PRD		0x2
#define	ET_CTRU_CMPA	0x4
#define	ET_CTRD_CMPA	0x5
#define	ET_CTRU_CMPB	0x6
#define	ET_CTRD_CMPB	0x7

// ETPS (Event Trigger Pre-scale)
//===============================
// INTPRD, SOCAPRD, SOCBPRD bits
#define	ET_DISABLE		0x0
#define	ET_1ST			0x1
#define	ET_2ND			0x2
#define	ET_3RD			0x3


//--------------------------------
// HRPWM (High Resolution PWM)
//================================
// HRCNFG
#define	HR_Disable		0x0
#define	HR_REP			0x1
#define	HR_FEP			0x2
#define	HR_BEP			0x3

#define	HR_CMP			0x0
#define	HR_PHS			0x1

#define	HR_CTR_ZERO		0x0
#define	HR_CTR_PRD		0x1


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP280X_EPWM_DEFINES_H

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\DSP280x_Examples.h 
// TI File $Revision: /main/2 $
// Checkin $Date: December 1, 2004   13:29:45 $
//###########################################################################
//
// FILE:   DSP280x_Examples.h
//
// TITLE:  DSP280x Device Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280X_EXAMPLES_H
#define DSP280X_EXAMPLES_H


#ifdef __cplusplus
extern "C" {
#endif


/*-----------------------------------------------------------------------------
      Specify the clock rate of the CPU (SYSCLKOUT) in nS.

      Take into account the input clock frequency and the PLL multiplier
      selected in step 1.
 
      Use one of the values provided, or define your own.
      The trailing L is required tells the compiler to treat 
      the number as a 64-bit value.  

      Only one statement should be uncommented.

      Example:  CLKIN is a 10MHz crystal. 
 
                In step 1 the user specified PLLCR = 0xA for a 
                100Mhz CPU clock (SYSCLKOUT = 100MHz).  

                In this case, the CPU_RATE will be 10.000L
                Uncomment the line:  #define CPU_RATE   10.000L
-----------------------------------------------------------------------------*/

#define CPU_RATE   10.000L   // for a 100MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   13.330L   // for a 75MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   20.000L   // for a 50MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   33.333L   // for a 30MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   41.667L   // for a 24MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   50.000L   // for a 20MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   66.667L   // for a 15MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE  100.000L   // for a 10MHz CPU clock speed  (SYSCLKOUT)

//----------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Include Example Header Files:
//

//#include "DSP280x_GlobalPrototypes.h"         // Prototypes for global functions within the 
                                              // .c files.

//#include "DSP280x_ePwm_defines.h"             // Macros used for PWM examples. 
//#include "DSP280x_I2C_defines.h"              // Macros used for I2C examples.

// Include files not used with DSP/BIOS
#ifndef DSP28_BIOS
//#include "DSP280x_DefaultISR.h"
#endif


// DO NOT MODIFY THIS LINE.  
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP280x_EXAMPLES_H definition


//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\DSP280x_GlobalPrototypes.h 
// TI File $Revision: /main/3 $
// Checkin $Date: January 11, 2005   13:56:21 $
//###########################################################################
//
// FILE:   DSP280x_GlobalPrototypes.h
//
// TITLE:  Global prototypes for DSP280x Examples
// 
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280X_GLOBALPROTOTYPES_H
#define DSP280X_GLOBALPROTOTYPES_H


#ifdef __cplusplus
extern "C" {
#endif

/*---- shared global function prototypes -----------------------------------*/
extern void InitAdc(void);
extern void InitPeripherals(void);
extern void InitECan(void);
extern void InitECana(void);
extern void InitECanGpio(void);
extern void InitECanaGpio(void);
#if DSP28_2808
extern void InitECanb(void);
extern void InitECanbGpio(void);
#endif // if DSP28_2808

extern void InitECap(void);
extern void InitECapGpio(void);
extern void InitECap1Gpio(void);
extern void InitECap2Gpio(void);
#if DSP28_2808 || DSP28_2806 
extern void InitECap3Gpio(void);
extern void InitECap4Gpio(void);
#endif // if DSP28_2808 || DSP28_2806 

extern void InitEPwm(void);
extern void InitEPwmGpio(void);
extern void InitEPwm1Gpio(void);
extern void InitEPwm2Gpio(void);
extern void InitEPwm3Gpio(void);
#if DSP28_2808 || DSP28_2806 
extern void InitEPwm4Gpio(void);
extern void InitEPwm5Gpio(void);
extern void InitEPwm6Gpio(void);
#endif // if DSP28_2808 || DSP28_2806 

extern void InitEQep(void);
extern void InitEQepGpio(void);
extern void InitEQep1Gpio(void);
#if DSP28_2808 || DSP28_2806 
extern void InitEQep2Gpio(void);
#endif // if DSP28_2808 || DSP28_2806 


extern void InitGpio(void);

extern void InitI2CGpio(void);

extern void InitPieCtrl(void);
extern void InitPieVectTable(void);

extern void InitSci(void);
extern void InitSciGpio(void);
extern void InitSciaGpio(void);
#if DSP28_2808 || DSP28_2806 
extern void InitScibGpio(void);
#endif // if DSP28_2808 || DSP28_2806 

extern void InitSpi(void);
extern void InitSpiGpio(void);
extern void InitSpiaGpio(void);
extern void InitSpibGpio(void);
#if DSP28_2808 || DSP28_2806
extern void InitSpicGpio(void);
extern void InitSpidGpio(void);
#endif

extern void InitSysCtrl(void);
extern void InitTzGpio(void);
extern void InitXIntrupt(void);
extern void InitPll(Uint16 val);
extern void InitPeripheralClocks(void);
extern void EnableInterrupts(void);
extern void DSP28x_usDelay(Uint32 Count);




// Watchdog functions
// DSP28_SysCtrl.c
extern void KickDog(void);
extern void DisableDog(void);

// DSP28_DBGIER.asm
extern void SetDBGIER(Uint16 dbgier);




//                 CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
extern void InitFlash(void);


void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);


//---------------------------------------------------------------------------
// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location 
// in either Flash or XINTF to a different RUN location in internal
// RAM
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP280X_GLOBALPROTOTYPES_H

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\DSP280x_I2c_defines.h 
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   11:10:51 $
//###########################################################################
//
// FILE:	DSP280x_I2cExample.h
//
// TITLE:	280x I2C Example Code Definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280X_I2C_DEFINES_H
#define DSP280X_I2C_DEINFES_H

//--------------------------------------------
// Defines
//--------------------------------------------

// Error Messages
#define I2C_ERROR               0xFFFF
#define I2C_ARB_LOST_ERROR      0x0001
#define I2C_NACK_ERROR          0x0002
#define I2C_BUS_BUSY_ERROR      0x1000
#define I2C_STP_NOT_READY_ERROR 0x5555
#define I2C_NO_FLAGS            0xAAAA
#define I2C_SUCCESS             0x0000

// Clear Status Flags
#define I2C_CLR_AL_BIT          0x0001
#define I2C_CLR_NACK_BIT        0x0002
#define I2C_CLR_ARDY_BIT        0x0004
#define I2C_CLR_RRDY_BIT        0x0008
#define I2C_CLR_SCD_BIT         0x0020

// Interrupt Source Messages
#define I2C_NO_ISRC             0x0000
#define I2C_ARB_ISRC            0x0001
#define I2C_NACK_ISRC           0x0002
#define I2C_ARDY_ISRC           0x0003
#define I2C_RX_ISRC             0x0004
#define I2C_TX_ISRC             0x0005
#define I2C_SCD_ISRC            0x0006
#define I2C_AAS_ISRC            0x0007

// I2CMSG structure defines
#define I2C_NO_STOP  0
#define I2C_YES_STOP 1
#define I2C_RECEIVE  0
#define I2C_TRANSMIT 1
#define I2C_MAX_BUFFER_SIZE 16

// I2C Slave State defines
#define I2C_NOTSLAVE      0
#define I2C_ADDR_AS_SLAVE 1
#define I2C_ST_MSG_READY  2

// I2C Slave Receiver messages defines
#define I2C_SND_MSG1 1
#define I2C_SND_MSG2 2

// I2C State defines
#define I2C_IDLE               0
#define I2C_SLAVE_RECEIVER     1
#define I2C_SLAVE_TRANSMITTER  2
#define I2C_MASTER_RECEIVER    3
#define I2C_MASTER_TRANSMITTER 4

// I2C  Message Commands for I2CMSG struct
#define I2C_MSGSTAT_INACTIVE          0x0000
#define I2C_MSGSTAT_SEND_WITHSTOP     0x0010
#define I2C_MSGSTAT_WRITE_BUSY        0x0011
#define I2C_MSGSTAT_SEND_NOSTOP       0x0020
#define I2C_MSGSTAT_SEND_NOSTOP_BUSY  0x0021
#define I2C_MSGSTAT_RESTART           0x0022
#define I2C_MSGSTAT_READ_BUSY         0x0023

// Generic defines
#define I2C_TRUE  1
#define I2C_FALSE 0
#define I2C_YES   1
#define I2C_NO    0
#define I2C_DUMMY_BYTE 0


//--------------------------------------------
// Structures
//--------------------------------------------

// I2C Message Structure
struct I2CMSG {
  Uint16 MsgStatus;				// Word stating what state msg is in:
  								//   I2C_MSGCMD_INACTIVE = do not send msg
  								//   I2C_MSGCMD_BUSY = msg start has been sent,
  								//                     awaiting stop
  								//   I2C_MSGCMD_SEND_WITHSTOP = command to send
  								//       master trans msg complete with a stop bit
  								//   I2C_MSGCMD_SEND_NOSTOP = command to send
  								//       master trans msg without the stop bit
  								//   I2C_MSGCMD_RESTART = command to send a restart
  								//       as a master receiver with a stop bit
  Uint16 SlaveAddress;			// I2C address of slave msg is intended for
  Uint16 NumOfBytes;			// Num of valid bytes in (or to be put in MsgBuffer)
  Uint16 MemoryHighAddr;		// EEPROM address of data associated with msg (high byte)
  Uint16 MemoryLowAddr;			// EEPROM address of data associated with msg (low byte)
  Uint16 MsgBuffer[I2C_MAX_BUFFER_SIZE];	// Array holding msg data - max that
  										    // MAX_BUFFER_SIZE can be is 16 due to
  										    // the FIFO's
};


#endif  // end of DSP280X_I2C_DEFINES_H definition

//===========================================================================
// End of file.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\DSP280x_SWPrioritizedIsrLevels.h 
// TI File $Revision: /main/2 $
// Checkin $Date: December 1, 2004   16:20:44 $
//###########################################################################
//
// FILE:    DSP280x_SWPrioritizedIsrLevels.h
//
// TITLE:   DSP28 Devices Software Prioritized Interrupt Service Routine 
//          Level definitions.
//
//###########################################################################
// $TI Release: DSP280x V1.10 $
// $Release Date: April 18, 2005 $
//###########################################################################

#ifndef DSP280x_SW_PRIORITZIED_ISR_H
#define DSP280x_SW_PRIORITZIED_ISR_H


#ifdef __cplusplus
extern "C" {
#endif


//-------------------------------------------------------------------------------
// Interrupt Enable Register Allocation For 280x Devices:
//-------------------------------------------------------------------------------
// Interrupts can be enabled/disabled using the CPU interrupt enable register
// (IER) and the PIE interrupt enable registers (PIEIER1 to PIEIER12). 
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
// Set "Global" Interrupt Priority Level (IER register):
//-------------------------------------------------------------------------------
// The user must set the appropriate priority level for each of the CPU
// interrupts. This is termed as the "global" priority. The priority level
// must be a number between 1 (highest) to 16 (lowest). A value of 0 must
// be entered for reserved interrupts or interrupts that are not used. This
// will also reduce code size by not including ISR's that are not used.
//
// Note: The priority levels below are used to calculate the IER register
//       interrupt masks MINT1 to MINT16.
//
//
// Note: The priority levels shown here may not make sense in a 
//       real application.  This is for demonstration purposes only!!!
// 
//       The user should change these to values that make sense for 
//       their application.
//
// 0  = not used
// 1  = highest priority
// ...
// 16 = lowest priority
#define	INT1PL      2        // Group1 Interrupts (PIEIER1)
#define	INT2PL      1        // Group2 Interrupts (PIEIER2)
#define	INT3PL      4        // Group3 Interrupts (PIEIER3)
#define	INT4PL      2        // Group4 Interrupts (PIEIER4)
#define	INT5PL      2        // Group5 Interrupts (PIEIER5)
#define	INT6PL      3        // Group6 Interrupts (PIEIER6)
#define	INT7PL      0        // reserved
#define	INT8PL      0        // reserved
#define	INT9PL      3        // Group9 Interrupts (PIEIER9)
#define	INT10PL     0        // reserved
#define	INT11PL     0        // reserved
#define	INT12PL     0        // reserved
#define	INT13PL     4        // XINT13
#define	INT14PL     4        // INT14 (TINT2)
#define	INT15PL     4        // DATALOG
#define	INT16PL     4        // RTOSINT

//-------------------------------------------------------------------------------
// Set "Group" Interrupt Priority Level (PIEIER1 to PIEIER12 registers):
//-------------------------------------------------------------------------------
// The user must set the appropriate priority level for each of the PIE
// interrupts. This is termed as the "group" priority. The priority level
// must be a number between 1 (highest) to 8 (lowest). A value of 0 must
// be entered for reserved interrupts or interrupts that are not used. This
// will also reduce code size by not including ISR's that are not used:
//
// Note: The priority levels below are used to calculate the following
//       PIEIER register interrupt masks:
//                           MG11 to MG18
//                           MG21 to MG28
//                           MG31 to MG38
//                           MG41 to MG48
//                           MG51 to MG58
//                           MG61 to MG68
//                           MG71 to MG78
//                           MG81 to MG88
//                           MG91 to MG98
//                           MG101 to MG108
//                           MG111 to MG118
//                           MG121 to MG128
//
// Note: The priority levels shown here may not make sense in a 
//       real application.  This is for demonstration purposes only!!!
// 
//       The user should change these to values that make sense for 
//       their application.
//
// 0  = not used
// 1  = highest priority
// ...
// 8  = lowest priority
//
#define	G11PL       7        // SEQ1INT     (ADC)
#define	G12PL       6        // SEQ2INT     (ADC)
#define	G13PL       0        // reserved
#define	G14PL       1        // XINT1       (External)
#define	G15PL       3        // XINT2       (External)
#define	G16PL       2        // ADCINT      (ADC)
#define	G17PL       1        // TINT0       (CPU Timer 0)
#define	G18PL       5        // WAKEINT     (WD/LPM)

#define	G21PL       4        // EPWM1_TZINT (ePWM1 Trip)
#define	G22PL       3        // EPWM2_TZINT (ePWM2 Trip)
#define	G23PL       2        // EPWM3_TZINT (ePWM3 Trip)
#define	G24PL       1        // EPWM4_TZINT (ePWM4 Trip)
#define	G25PL       5        // EPWM5_TZINT (ePWM5 Trip)
#define	G26PL       6        // EPWM6_TZINT (ePWM6 Trip)
#define	G27PL       0        // reserved
#define	G28PL       0        // reserved

#define	G31PL       4        // EPWM1_INT   (ePWM1 Int)
#define	G32PL       1        // EPWM2_INT   (ePWM2 Int)
#define	G33PL       1        // EPWM3_INT   (ePWM3 Int)
#define	G34PL       2        // EPWM4_INT   (ePWM4 Int)
#define	G35PL       2        // EPWM5_INT   (ePWM5 Int)
#define	G36PL       1        // EPWM6_INT   (ePWM6 Int)
#define	G37PL       0        // reserved
#define	G38PL       0        // reserved

#define	G41PL       2        // ECAP1_INT   (eCAP1 Int)
#define	G42PL       1        // ECAP2_INT   (eCAP2 Int)
#define	G43PL       3        // ECAP3_INT   (eCAP3 Int)
#define	G44PL       3        // ECAP4_INT   (eCAP4 Int)
#define	G45PL       0        // reserved
#define	G46PL       0        // reserved
#define	G47PL       0        // reserved
#define	G48PL       0        // reserved

#define	G51PL       2        // EQEP1_INT   (eQEP1 Int)
#define	G52PL       1        // EQEP2_INT   (eQEP2 Int)
#define	G53PL       0        // reserved
#define	G54PL       0        // reserved
#define	G55PL       0        // reserved
#define	G56PL       0        // reserved
#define	G57PL       0        // reserved
#define	G58PL       0        // reserved

#define	G61PL       3        // SPIRXINTA (SPI-A)
#define	G62PL       1        // SPITXINTA (SPI-A)
#define	G63PL       4        // SPIRXINTB (SPI-B)
#define	G64PL       6        // SPITXINTB (SPI-B)          
#define	G65PL       2        // SPIRXINTC (SPI-C)
#define	G66PL       1        // SPITXINTC (SPI-C)                  
#define	G67PL       5        // SPIRXINTD (SPI-D)
#define	G68PL       7        // SPITXINTD (SPI-D)          

#define	G71PL       0        // reserved
#define	G72PL       0        // reserved
#define	G73PL       0        // reserved
#define	G74PL       0        // reserved
#define	G75PL       0        // reserved
#define	G76PL       0        // reserved
#define	G77PL       0        // reserved
#define	G78PL       0        // reserved

#define	G81PL       1        // I2CINT1A  (I2C-A)
#define	G82PL       2        // I2CINT2A  (I2C-A)
#define	G83PL       0        // reserved
#define	G84PL       0        // reserved
#define	G85PL       0        // reserved
#define	G86PL       0        // reserved
#define	G87PL       0        // reserved
#define	G88PL       0        // reserved

#define	G91PL       1        // SCIRXINTA (SCI-A)
#define	G92PL       5        // SCITXINTA (SCI-A)
#define	G93PL       3        // SCIRXINTB (SCI-B)
#define	G94PL       4        // SCITXINTB (SCI-B)
#define	G95PL       1        // ECAN0INTA (ECAN-A)
#define	G96PL       1        // ECAN1INTA (ECAN-A)
#define	G97PL       2        // ECAN0INTB (ECAN-B)
#define	G98PL       4        // ECAN1INTB (ECAN-B)          

#define	G101PL      0        // reserved
#define	G102PL      0        // reserved
#define	G103PL      0        // reserved
#define	G104PL      0        // reserved
#define	G105PL      0        // reserved
#define	G106PL      0        // reserved
#define	G107PL      0        // reserved
#define	G108PL      0        // reserved

#define	G111PL      0        // reserved
#define	G112PL      0        // reserved
#define	G113PL      0        // reserved
#define	G114PL      0        // reserved
#define	G115PL      0        // reserved
#define	G116PL      0        // reserved
#define	G117PL      0        // reserved
#define	G118PL      0        // reserved

#define	G121PL      0        // reserved
#define	G122PL      0        // reserved
#define	G123PL      0        // reserved
#define	G124PL      0        // reserved
#define	G125PL      0        // reserved
#define	G126PL      0        // reserved
#define	G127PL      0        // reserved
#define	G128PL      0        // reserved


// There should be no need to modify code below this line 
//-------------------------------------------------------------------------------
// Automatically generate IER interrupt masks MINT1 to MINT16:
//

// Beginning of MINT1:
#if (INT1PL == 0)
#define  MINT1_1PL    ~(1 << 0)
#else
#define  MINT1_1PL    0xFFFF
#endif

#if (INT2PL >= INT1PL) || (INT2PL == 0)
#define  MINT1_2PL   ~(1 << 1)
#else
#define  MINT1_2PL   0xFFFF
#endif

#if (INT3PL >= INT1PL) || (INT3PL == 0)
#define  MINT1_3PL   ~(1 << 2)
#else
#define  MINT1_3PL   0xFFFF
#endif

#if (INT4PL >= INT1PL) || (INT4PL == 0)
#define  MINT1_4PL   ~(1 << 3)
#else
#define  MINT1_4PL   0xFFFF
#endif

#if (INT5PL >= INT1PL) || (INT5PL == 0)
#define  MINT1_5PL   ~(1 << 4)
#else
#define  MINT1_5PL   0xFFFF
#endif

#if (INT6PL >= INT1PL) || (INT6PL == 0)
#define  MINT1_6PL   ~(1 << 5)
#else
#define  MINT1_6PL   0xFFFF
#endif

#if (INT7PL >= INT1PL) || (INT7PL == 0)
#define  MINT1_7PL   ~(1 << 6)
#else
#define  MINT1_7PL   0xFFFF
#endif

#if (INT8PL >= INT1PL) || (INT8PL == 0)
#define  MINT1_8PL   ~(1 << 7)
#else
#define  MINT1_8PL   0xFFFF
#endif

#if (INT9PL >= INT1PL) || (INT9PL == 0)
#define  MINT1_9PL   ~(1 << 8)
#else
#define  MINT1_9PL   0xFFFF
#endif

#if (INT10PL >= INT1PL) || (INT10PL == 0)
#define  MINT1_10PL   ~(1 << 9)
#else
#define  MINT1_10PL   0xFFFF
#endif

#if (INT11PL >= INT1PL) || (INT11PL == 0)
#define  MINT1_11PL   ~(1 << 10)
#else
#define  MINT1_11PL   0xFFFF
#endif

#if (INT12PL >= INT1PL) || (INT12PL == 0)
#define  MINT1_12PL   ~(1 << 11)
#else
#define  MINT1_12PL   0xFFFF
#endif

#if (INT13PL >= INT1PL) || (INT13PL == 0)
#define  MINT1_13PL   ~(1 << 12)
#else
#define  MINT1_13PL   0xFFFF
#endif

#if (INT14PL >= INT1PL) || (INT14PL == 0)
#define  MINT1_14PL   ~(1 << 13)
#else
#define  MINT1_14PL   0xFFFF
#endif

#if (INT15PL >= INT1PL) || (INT15PL == 0)
#define  MINT1_15PL   ~(1 << 14)
#else
#define  MINT1_15PL   0xFFFF
#endif

#if (INT16PL >= INT1PL) || (INT16PL == 0)
#define  MINT1_16PL   ~(1 << 15)
#else
#define  MINT1_16PL   0xFFFF
#endif

#define  MINT1    (MINT1_1PL  & MINT1_2PL  & MINT1_3PL  & MINT1_4PL  & \
                   MINT1_5PL  & MINT1_6PL  & MINT1_7PL  & MINT1_8PL  & \
                   MINT1_9PL  & MINT1_10PL & MINT1_11PL & MINT1_12PL & \
                   MINT1_13PL & MINT1_14PL & MINT1_15PL & MINT1_16PL)
// End Of MINT1.

// Beginning of MINT2:
#if (INT1PL >= INT2PL) || (INT1PL == 0)
#define  MINT2_1PL    ~(1 << 0)
#else
#define  MINT2_1PL    0xFFFF
#endif

#if (INT2PL == 0)
#define  MINT2_2PL   ~(1 << 1)
#else
#define  MINT2_2PL   0xFFFF
#endif

#if (INT3PL >= INT2PL) || (INT3PL == 0)
#define  MINT2_3PL   ~(1 << 2)
#else
#define  MINT2_3PL   0xFFFF
#endif

#if (INT4PL >= INT2PL) || (INT4PL == 0)
#define  MINT2_4PL   ~(1 << 3)
#else
#define  MINT2_4PL   0xFFFF
#endif

#if (INT5PL >= INT2PL) || (INT5PL == 0)
#define  MINT2_5PL   ~(1 << 4)
#else
#define  MINT2_5PL   0xFFFF
#endif

#if (INT6PL >= INT2PL) || (INT6PL == 0)
#define  MINT2_6PL   ~(1 << 5)
#else
#define  MINT2_6PL   0xFFFF
#endif

#if (INT7PL >= INT2PL) || (INT7PL == 0)
#define  MINT2_7PL   ~(1 << 6)
#else
#define  MINT2_7PL   0xFFFF
#endif

#if (INT8PL >= INT2PL) || (INT8PL == 0)
#define  MINT2_8PL   ~(1 << 7)
#else
#define  MINT2_8PL   0xFFFF
#endif

#if (INT9PL >= INT2PL) || (INT9PL == 0)
#define  MINT2_9PL   ~(1 << 8)
#else
#define  MINT2_9PL   0xFFFF
#endif

#if (INT10PL >= INT2PL) || (INT10PL == 0)
#define  MINT2_10PL   ~(1 << 9)
#else
#define  MINT2_10PL   0xFFFF
#endif

#if (INT11PL >= INT2PL) || (INT11PL == 0)
#define  MINT2_11PL   ~(1 << 10)
#else
#define  MINT2_11PL   0xFFFF
#endif

#if (INT12PL >= INT2PL) || (INT12PL == 0)
#define  MINT2_12PL   ~(1 << 11)
#else
#define  MINT2_12PL   0xFFFF
#endif

#if (INT13PL >= INT2PL) || (INT13PL == 0)
#define  MINT2_13PL   ~(1 << 12)
#else
#define  MINT2_13PL   0xFFFF
#endif

#if (INT14PL >= INT2PL) || (INT14PL == 0)
#define  MINT2_14PL   ~(1 << 13)
#else
#define  MINT2_14PL   0xFFFF
#endif

#if (INT15PL >= INT2PL) || (INT15PL == 0)
#define  MINT2_15PL   ~(1 << 14)
#else
#define  MINT2_15PL   0xFFFF
#endif

#if (INT16PL >= INT2PL) || (INT16PL == 0)
#define  MINT2_16PL   ~(1 << 15)
#else
#define  MINT2_16PL   0xFFFF
#endif

#define  MINT2    (MINT2_1PL  & MINT2_2PL  & MINT2_3PL  & MINT2_4PL  & \
                   MINT2_5PL  & MINT2_6PL  & MINT2_7PL  & MINT2_8PL  & \
                   MINT2_9PL  & MINT2_10PL & MINT2_11PL & MINT2_12PL & \
                   MINT2_13PL & MINT2_14PL & MINT2_15PL & MINT2_16PL)
// End Of MINT2.

// Beginning of MINT3:
#if (INT1PL >= INT3PL) || (INT1PL == 0)
#define  MINT3_1PL    ~(1 << 0)
#else
#define  MINT3_1PL    0xFFFF
#endif

#if (INT2PL >= INT3PL) || (INT2PL == 0)
#define  MINT3_2PL   ~(1 << 1)
#else
#define  MINT3_2PL   0xFFFF
#endif

#if (INT3PL == 0)
#define  MINT3_3PL   ~(1 << 2)
#else
#define  MINT3_3PL   0xFFFF
#endif

#if (INT4PL >= INT3PL) || (INT4PL == 0)
#define  MINT3_4PL   ~(1 << 3)
#else
#define  MINT3_4PL   0xFFFF
#endif

#if (INT5PL >= INT3PL) || (INT5PL == 0)
#define  MINT3_5PL   ~(1 << 4)
#else
#define  MINT3_5PL   0xFFFF
#endif

#if (INT6PL >= INT3PL) || (INT6PL == 0)
#define  MINT3_6PL   ~(1 << 5)
#else
#define  MINT3_6PL   0xFFFF
#endif

#if (INT7PL >= INT3PL) || (INT7PL == 0)
#define  MINT3_7PL   ~(1 << 6)
#else
#define  MINT3_7PL   0xFFFF
#endif

#if (INT8PL >= INT3PL) || (INT8PL == 0)
#define  MINT3_8PL   ~(1 << 7)
#else
#define  MINT3_8PL   0xFFFF
#endif

#if (INT9PL >= INT3PL) || (INT9PL == 0)
#define  MINT3_9PL   ~(1 << 8)
#else
#define  MINT3_9PL   0xFFFF
#endif

#if (INT10PL >= INT3PL) || (INT10PL == 0)
#define  MINT3_10PL   ~(1 << 9)
#else
#define  MINT3_10PL   0xFFFF
#endif

#if (INT11PL >= INT3PL) || (INT11PL == 0)
#define  MINT3_11PL   ~(1 << 10)
#else
#define  MINT3_11PL   0xFFFF
#endif

#if (INT12PL >= INT3PL) || (INT12PL == 0)
#define  MINT3_12PL   ~(1 << 11)
#else
#define  MINT3_12PL   0xFFFF
#endif

#if (INT13PL >= INT3PL) || (INT13PL == 0)
#define  MINT3_13PL   ~(1 << 12)
#else
#define  MINT3_13PL   0xFFFF
#endif

#if (INT14PL >= INT3PL) || (INT14PL == 0)
#define  MINT3_14PL   ~(1 << 13)
#else
#define  MINT3_14PL   0xFFFF
#endif

#if (INT15PL >= INT3PL) || (INT15PL == 0)
#define  MINT3_15PL   ~(1 << 14)
#else
#define  MINT3_15PL   0xFFFF
#endif

#if (INT16PL >= INT3PL) || (INT16PL == 0)
#define  MINT3_16PL   ~(1 << 15)
#else
#define  MINT3_16PL   0xFFFF
#endif

#define  MINT3    (MINT3_1PL  & MINT3_2PL  & MINT3_3PL  & MINT3_4PL  & \
                   MINT3_5PL  & MINT3_6PL  & MINT3_7PL  & MINT3_8PL  & \
                   MINT3_9PL  & MINT3_10PL & MINT3_11PL & MINT3_12PL & \
                   MINT3_13PL & MINT3_14PL & MINT3_15PL & MINT3_16PL)
// End Of MINT3.

// Beginning of MINT4:
#if (INT1PL >= INT4PL) || (INT1PL == 0)
#define  MINT4_1PL    ~(1 << 0)
#else
#define  MINT4_1PL    0xFFFF
#endif

#if (INT2PL >= INT4PL) || (INT2PL == 0)
#define  MINT4_2PL   ~(1 << 1)
#else
#define  MINT4_2PL   0xFFFF
#endif

#if (INT3PL >= INT4PL) || (INT3PL == 0)
#define  MINT4_3PL   ~(1 << 2)
#else
#define  MINT4_3PL   0xFFFF
#endif

#if (INT4PL == 0)
#define  MINT4_4PL   ~(1 << 3)
#else
#define  MINT4_4PL   0xFFFF
#endif

#if (INT5PL >= INT4PL) || (INT5PL == 0)
#define  MINT4_5PL   ~(1 << 4)
#else
#define  MINT4_5PL   0xFFFF
#endif

#if (INT6PL >= INT4PL) || (INT6PL == 0)
#define  MINT4_6PL   ~(1 << 5)
#else
#define  MINT4_6PL   0xFFFF
#endif

#if (INT7PL >= INT4PL) || (INT7PL == 0)
#define  MINT4_7PL   ~(1 << 6)
#else
#define  MINT4_7PL   0xFFFF
#endif

#if (INT8PL >= INT4PL) || (INT8PL == 0)
#define  MINT4_8PL   ~(1 << 7)
#else
#define  MINT4_8PL   0xFFFF
#endif

#if (INT9PL >= INT4PL) || (INT9PL == 0)
#define  MINT4_9PL   ~(1 << 8)
#else
#define  MINT4_9PL   0xFFFF
#endif

#if (INT10PL >= INT4PL) || (INT10PL == 0)
#define  MINT4_10PL   ~(1 << 9)
#else
#define  MINT4_10PL   0xFFFF
#endif

#if (INT11PL >= INT4PL) || (INT11PL == 0)
#define  MINT4_11PL   ~(1 << 10)
#else
#define  MINT4_11PL   0xFFFF
#endif

#if (INT12PL >= INT4PL) || (INT12PL == 0)
#define  MINT4_12PL   ~(1 << 11)
#else
#define  MINT4_12PL   0xFFFF
#endif

#if (INT13PL >= INT4PL) || (INT13PL == 0)
#define  MINT4_13PL   ~(1 << 12)
#else
#define  MINT4_13PL   0xFFFF
#endif

#if (INT14PL >= INT4PL) || (INT14PL == 0)
#define  MINT4_14PL   ~(1 << 13)
#else
#define  MINT4_14PL   0xFFFF
#endif

#if (INT15PL >= INT4PL) || (INT15PL == 0)
#define  MINT4_15PL   ~(1 << 14)
#else
#define  MINT4_15PL   0xFFFF
#endif

#if (INT16PL >= INT4PL) || (INT16PL == 0)
#define  MINT4_16PL   ~(1 << 15)
#else
#define  MINT4_16PL   0xFFFF
#endif

#define  MINT4    (MINT4_1PL  & MINT4_2PL  & MINT4_3PL  & MINT4_4PL  & \
                   MINT4_5PL  & MINT4_6PL  & MINT4_7PL  & MINT4_8PL  & \
                   MINT4_9PL  & MINT4_10PL & MINT4_11PL & MINT4_12PL & \
                   MINT4_13PL & MINT4_14PL & MINT4_15PL & MINT4_16PL)
// End Of MINT4.

// Beginning of MINT5:
#if (INT1PL >= INT5PL) || (INT1PL == 0)
#define  MINT5_1PL    ~(1 << 0)
#else
#define  MINT5_1PL    0xFFFF
#endif

#if (INT2PL >= INT5PL) || (INT2PL == 0)
#define  MINT5_2PL   ~(1 << 1)
#else
#define  MINT5_2PL   0xFFFF
#endif

#if (INT3PL >= INT5PL) || (INT3PL == 0)
#define  MINT5_3PL   ~(1 << 2)
#else
#define  MINT5_3PL   0xFFFF
#endif

#if (INT4PL >= INT5PL) || (INT4PL == 0)
#define  MINT5_4PL   ~(1 << 3)
#else
#define  MINT5_4PL   0xFFFF
#endif

#if (INT5PL == 0)
#define  MINT5_5PL   ~(1 << 4)
#else
#define  MINT5_5PL   0xFFFF
#endif

#if (INT6PL >= INT5PL) || (INT6PL == 0)
#define  MINT5_6PL   ~(1 << 5)
#else
#define  MINT5_6PL   0xFFFF
#endif

#if (INT7PL >= INT5PL) || (INT7PL == 0)
#define  MINT5_7PL   ~(1 << 6)
#else
#define  MINT5_7PL   0xFFFF
#endif

#if (INT8PL >= INT5PL) || (INT8PL == 0)
#define  MINT5_8PL   ~(1 << 7)
#else
#define  MINT5_8PL   0xFFFF
#endif

#if (INT9PL >= INT5PL) || (INT9PL == 0)
#define  MINT5_9PL   ~(1 << 8)
#else
#define  MINT5_9PL   0xFFFF
#endif

#if (INT10PL >= INT5PL) || (INT10PL == 0)
#define  MINT5_10PL   ~(1 << 9)
#else
#define  MINT5_10PL   0xFFFF
#endif

#if (INT11PL >= INT5PL) || (INT11PL == 0)
#define  MINT5_11PL   ~(1 << 10)
#else
#define  MINT5_11PL   0xFFFF
#endif

#if (INT12PL >= INT5PL) || (INT12PL == 0)
#define  MINT5_12PL   ~(1 << 11)
#else
#define  MINT5_12PL   0xFFFF
#endif

#if (INT13PL >= INT5PL) || (INT13PL == 0)
#define  MINT5_13PL   ~(1 << 12)
#else
#define  MINT5_13PL   0xFFFF
#endif

#if (INT14PL >= INT5PL) || (INT14PL == 0)
#define  MINT5_14PL   ~(1 << 13)
#else
#define  MINT5_14PL   0xFFFF
#endif

#if (INT15PL >= INT5PL) || (INT15PL == 0)
#define  MINT5_15PL   ~(1 << 14)
#else
#define  MINT5_15PL   0xFFFF
#endif

#if (INT16PL >= INT5PL) || (INT16PL == 0)
#define  MINT5_16PL   ~(1 << 15)
#else
#define  MINT5_16PL   0xFFFF
#endif

#define  MINT5    (MINT5_1PL  & MINT5_2PL  & MINT5_3PL  & MINT5_4PL  & \
                   MINT5_5PL  & MINT5_6PL  & MINT5_7PL  & MINT5_8PL  & \
                   MINT5_9PL  & MINT5_10PL & MINT5_11PL & MINT5_12PL & \
                   MINT5_13PL & MINT5_14PL & MINT5_15PL & MINT5_16PL)
// End Of MINT5.

// Beginning of MINT6:
#if (INT1PL >= INT6PL) || (INT1PL == 0)
#define  MINT6_1PL    ~(1 << 0)
#else
#define  MINT6_1PL    0xFFFF
#endif

#if (INT2PL >= INT6PL) || (INT2PL == 0)
#define  MINT6_2PL   ~(1 << 1)
#else
#define  MINT6_2PL   0xFFFF
#endif

#if (INT3PL >= INT6PL) || (INT3PL == 0)
#define  MINT6_3PL   ~(1 << 2)
#else
#define  MINT6_3PL   0xFFFF
#endif

#if (INT4PL >= INT6PL) || (INT4PL == 0)
#define  MINT6_4PL   ~(1 << 3)
#else
#define  MINT6_4PL   0xFFFF
#endif

#if (INT5PL >= INT6PL) || (INT5PL == 0)
#define  MINT6_5PL   ~(1 << 4)
#else
#define  MINT6_5PL   0xFFFF
#endif

#if (INT6PL == 0)
#define  MINT6_6PL   ~(1 << 5)
#else
#define  MINT6_6PL   0xFFFF
#endif

#if (INT7PL >= INT6PL) || (INT7PL == 0)
#define  MINT6_7PL   ~(1 << 6)
#else
#define  MINT6_7PL   0xFFFF
#endif

#if (INT8PL >= INT6PL) || (INT8PL == 0)
#define  MINT6_8PL   ~(1 << 7)
#else
#define  MINT6_8PL   0xFFFF
#endif

#if (INT9PL >= INT6PL) || (INT9PL == 0)
#define  MINT6_9PL   ~(1 << 8)
#else
#define  MINT6_9PL   0xFFFF
#endif

#if (INT10PL >= INT6PL) || (INT10PL == 0)
#define  MINT6_10PL   ~(1 << 9)
#else
#define  MINT6_10PL   0xFFFF
#endif

#if (INT11PL >= INT6PL) || (INT11PL == 0)
#define  MINT6_11PL   ~(1 << 10)
#else
#define  MINT6_11PL   0xFFFF
#endif

#if (INT12PL >= INT6PL) || (INT12PL == 0)
#define  MINT6_12PL   ~(1 << 11)
#else
#define  MINT6_12PL   0xFFFF
#endif

#if (INT13PL >= INT6PL) || (INT13PL == 0)
#define  MINT6_13PL   ~(1 << 12)
#else
#define  MINT6_13PL   0xFFFF
#endif

#if (INT14PL >= INT6PL) || (INT14PL == 0)
#define  MINT6_14PL   ~(1 << 13)
#else
#define  MINT6_14PL   0xFFFF
#endif

#if (INT15PL >= INT6PL) || (INT15PL == 0)
#define  MINT6_15PL   ~(1 << 14)
#else
#define  MINT6_15PL   0xFFFF
#endif

#if (INT16PL >= INT6PL) || (INT16PL == 0)
#define  MINT6_16PL   ~(1 << 15)
#else
#define  MINT6_16PL   0xFFFF
#endif

#define  MINT6    (MINT6_1PL  & MINT6_2PL  & MINT6_3PL  & MINT6_4PL  & \
                   MINT6_5PL  & MINT6_6PL  & MINT6_7PL  & MINT6_8PL  & \
                   MINT6_9PL  & MINT6_10PL & MINT6_11PL & MINT6_12PL & \
                   MINT6_13PL & MINT6_14PL & MINT6_15PL & MINT6_16PL)
// End Of MINT6.

// Beginning of MINT7:
#if (INT1PL >= INT7PL) || (INT1PL == 0)
#define  MINT7_1PL    ~(1 << 0)
#else
#define  MINT7_1PL    0xFFFF
#endif

#if (INT2PL >= INT7PL) || (INT2PL == 0)
#define  MINT7_2PL   ~(1 << 1)
#else
#define  MINT7_2PL   0xFFFF
#endif

#if (INT3PL >= INT7PL) || (INT3PL == 0)
#define  MINT7_3PL   ~(1 << 2)
#else
#define  MINT7_3PL   0xFFFF
#endif

#if (INT4PL >= INT7PL) || (INT4PL == 0)
#define  MINT7_4PL   ~(1 << 3)
#else
#define  MINT7_4PL   0xFFFF
#endif

#if (INT5PL >= INT7PL) || (INT5PL == 0)
#define  MINT7_5PL   ~(1 << 4)
#else
#define  MINT7_5PL   0xFFFF
#endif

#if (INT6PL >= INT7PL) || (INT6PL == 0)
#define  MINT7_6PL   ~(1 << 5)
#else
#define  MINT7_6PL   0xFFFF
#endif

#if (INT7PL == 0)
#define  MINT7_7PL   ~(1 << 6)
#else
#define  MINT7_7PL   0xFFFF
#endif

#if (INT8PL >= INT7PL) || (INT8PL == 0)
#define  MINT7_8PL   ~(1 << 7)
#else
#define  MINT7_8PL   0xFFFF
#endif

#if (INT9PL >= INT7PL) || (INT9PL == 0)
#define  MINT7_9PL   ~(1 << 8)
#else
#define  MINT7_9PL   0xFFFF
#endif

#if (INT10PL >= INT7PL) || (INT10PL == 0)
#define  MINT7_10PL   ~(1 << 9)
#else
#define  MINT7_10PL   0xFFFF
#endif

#if (INT11PL >= INT7PL) || (INT11PL == 0)
#define  MINT7_11PL   ~(1 << 10)
#else
#define  MINT7_11PL   0xFFFF
#endif

#if (INT12PL >= INT7PL) || (INT12PL == 0)
#define  MINT7_12PL   ~(1 << 11)
#else
#define  MINT7_12PL   0xFFFF
#endif

#if (INT13PL >= INT7PL) || (INT13PL == 0)
#define  MINT7_13PL   ~(1 << 12)
#else
#define  MINT7_13PL   0xFFFF
#endif

#if (INT14PL >= INT7PL) || (INT14PL == 0)
#define  MINT7_14PL   ~(1 << 13)
#else
#define  MINT7_14PL   0xFFFF
#endif

#if (INT15PL >= INT7PL) || (INT15PL == 0)
#define  MINT7_15PL   ~(1 << 14)
#else
#define  MINT7_15PL   0xFFFF
#endif

#if (INT16PL >= INT7PL) || (INT16PL == 0)
#define  MINT7_16PL   ~(1 << 15)
#else
#define  MINT7_16PL   0xFFFF
#endif

#define  MINT7    (MINT7_1PL  & MINT7_2PL  & MINT7_3PL  & MINT7_4PL  & \
                   MINT7_5PL  & MINT7_6PL  & MINT7_7PL  & MINT7_8PL  & \
                   MINT7_9PL  & MINT7_10PL & MINT7_11PL & MINT7_12PL & \
                   MINT7_13PL & MINT7_14PL & MINT7_15PL & MINT7_16PL)
// End Of MINT7.

// Beginning of MINT8:
#if (INT1PL >= INT8PL) || (INT1PL == 0)
#define  MINT8_1PL    ~(1 << 0)
#else
#define  MINT8_1PL    0xFFFF
#endif

#if (INT2PL >= INT8PL) || (INT2PL == 0)
#define  MINT8_2PL   ~(1 << 1)
#else
#define  MINT8_2PL   0xFFFF
#endif

#if (INT3PL >= INT8PL) || (INT3PL == 0)
#define  MINT8_3PL   ~(1 << 2)
#else
#define  MINT8_3PL   0xFFFF
#endif

#if (INT4PL >= INT8PL) || (INT4PL == 0)
#define  MINT8_4PL   ~(1 << 3)
#else
#define  MINT8_4PL   0xFFFF
#endif

#if (INT5PL >= INT8PL) || (INT5PL == 0)
#define  MINT8_5PL   ~(1 << 4)
#else
#define  MINT8_5PL   0xFFFF
#endif

#if (INT6PL >= INT8PL) || (INT6PL == 0)
#define  MINT8_6PL   ~(1 << 5)
#else
#define  MINT8_6PL   0xFFFF
#endif

#if (INT7PL >= INT8PL) || (INT7PL == 0)
#define  MINT8_7PL   ~(1 << 6)
#else
#define  MINT8_7PL   0xFFFF
#endif

#if (INT8PL == 0)
#define  MINT8_8PL   ~(1 << 7)
#else
#define  MINT8_8PL   0xFFFF
#endif

#if (INT9PL >= INT8PL) || (INT9PL == 0)
#define  MINT8_9PL   ~(1 << 8)
#else
#define  MINT8_9PL   0xFFFF
#endif

#if (INT10PL >= INT8PL) || (INT10PL == 0)
#define  MINT8_10PL   ~(1 << 9)
#else
#define  MINT8_10PL   0xFFFF
#endif

#if (INT11PL >= INT8PL) || (INT11PL == 0)
#define  MINT8_11PL   ~(1 << 10)
#else
#define  MINT8_11PL   0xFFFF
#endif

#if (INT12PL >= INT8PL) || (INT12PL == 0)
#define  MINT8_12PL   ~(1 << 11)
#else
#define  MINT8_12PL   0xFFFF
#endif

#if (INT13PL >= INT8PL) || (INT13PL == 0)
#define  MINT8_13PL   ~(1 << 12)
#else
#define  MINT8_13PL   0xFFFF
#endif

#if (INT14PL >= INT8PL) || (INT14PL == 0)
#define  MINT8_14PL   ~(1 << 13)
#else
#define  MINT8_14PL   0xFFFF
#endif

#if (INT15PL >= INT8PL) || (INT15PL == 0)
#define  MINT8_15PL   ~(1 << 14)
#else
#define  MINT8_15PL   0xFFFF
#endif

#if (INT16PL >= INT8PL) || (INT16PL == 0)
#define  MINT8_16PL   ~(1 << 15)
#else
#define  MINT8_16PL   0xFFFF
#endif

#define  MINT8    (MINT8_1PL  & MINT8_2PL  & MINT8_3PL  & MINT8_4PL  & \
                   MINT8_5PL  & MINT8_6PL  & MINT8_7PL  & MINT8_8PL  & \
                   MINT8_9PL  & MINT8_10PL & MINT8_11PL & MINT8_12PL & \
                   MINT8_13PL & MINT8_14PL & MINT8_15PL & MINT8_16PL)
// End Of MINT8.

// Beginning of MINT9:
#if (INT1PL >= INT9PL) || (INT1PL == 0)
#define  MINT9_1PL    ~(1 << 0)
#else
#define  MINT9_1PL    0xFFFF
#endif

#if (INT2PL >= INT9PL) || (INT2PL == 0)
#define  MINT9_2PL   ~(1 << 1)
#else
#define  MINT9_2PL   0xFFFF
#endif

#if (INT3PL >= INT9PL) || (INT3PL == 0)
#define  MINT9_3PL   ~(1 << 2)
#else
#define  MINT9_3PL   0xFFFF
#endif

#if (INT4PL >= INT9PL) || (INT4PL == 0)
#define  MINT9_4PL   ~(1 << 3)
#else
#define  MINT9_4PL   0xFFFF
#endif

#if (INT5PL >= INT9PL) || (INT5PL == 0)
#define  MINT9_5PL   ~(1 << 4)
#else
#define  MINT9_5PL   0xFFFF
#endif

#if (INT6PL >= INT9PL) || (INT6PL == 0)
#define  MINT9_6PL   ~(1 << 5)
#else
#define  MINT9_6PL   0xFFFF
#endif

#if (INT7PL >= INT9PL) || (INT7PL == 0)
#define  MINT9_7PL   ~(1 << 6)
#else
#define  MINT9_7PL   0xFFFF
#endif

#if (INT8PL >= INT9PL) || (INT8PL == 0)
#define  MINT9_8PL   ~(1 << 7)
#else
#define  MINT9_8PL   0xFFFF
#endif

#if (INT9PL == 0)
#define  MINT9_9PL   ~(1 << 8)
#else
#define  MINT9_9PL   0xFFFF
#endif

#if (INT10PL >= INT9PL) || (INT10PL == 0)
#define  MINT9_10PL   ~(1 << 9)
#else
#define  MINT9_10PL   0xFFFF
#endif

#if (INT11PL >= INT9PL) || (INT11PL == 0)
#define  MINT9_11PL   ~(1 << 10)
#else
#define  MINT9_11PL   0xFFFF
#endif

#if (INT12PL >= INT9PL) || (INT12PL == 0)
#define  MINT9_12PL   ~(1 << 11)
#else
#define  MINT9_12PL   0xFFFF
#endif

#if (INT13PL >= INT9PL) || (INT13PL == 0)
#define  MINT9_13PL   ~(1 << 12)
#else
#define  MINT9_13PL   0xFFFF
#endif

#if (INT14PL >= INT9PL) || (INT14PL == 0)
#define  MINT9_14PL   ~(1 << 13)
#else
#define  MINT9_14PL   0xFFFF
#endif

#if (INT15PL >= INT9PL) || (INT15PL == 0)
#define  MINT9_15PL   ~(1 << 14)
#else
#define  MINT9_15PL   0xFFFF
#endif

#if (INT16PL >= INT9PL) || (INT16PL == 0)
#define  MINT9_16PL   ~(1 << 15)
#else
#define  MINT9_16PL   0xFFFF
#endif

#define  MINT9    (MINT9_1PL  & MINT9_2PL  & MINT9_3PL  & MINT9_4PL  & \
                   MINT9_5PL  & MINT9_6PL  & MINT9_7PL  & MINT9_8PL  & \
                   MINT9_9PL  & MINT9_10PL & MINT9_11PL & MINT9_12PL & \
                   MINT9_13PL & MINT9_14PL & MINT9_15PL & MINT9_16PL)
// End Of MINT9.

// Beginning of MINT10:
#if (INT1PL >= INT10PL) || (INT1PL == 0)
#define  MINT10_1PL    ~(1 << 0)
#else
#define  MINT10_1PL    0xFFFF
#endif

#if (INT2PL >= INT10PL) || (INT2PL == 0)
#define  MINT10_2PL   ~(1 << 1)
#else
#define  MINT10_2PL   0xFFFF
#endif

#if (INT3PL >= INT10PL) || (INT3PL == 0)
#define  MINT10_3PL   ~(1 << 2)
#else
#define  MINT10_3PL   0xFFFF
#endif

#if (INT4PL >= INT10PL) || (INT4PL == 0)
#define  MINT10_4PL   ~(1 << 3)
#else
#define  MINT10_4PL   0xFFFF
#endif

#if (INT5PL >= INT10PL) || (INT5PL == 0)
#define  MINT10_5PL   ~(1 << 4)
#else
#define  MINT10_5PL   0xFFFF
#endif

#if (INT6PL >= INT10PL) || (INT6PL == 0)
#define  MINT10_6PL   ~(1 << 5)
#else
#define  MINT10_6PL   0xFFFF
#endif

#if (INT7PL >= INT10PL) || (INT7PL == 0)
#define  MINT10_7PL   ~(1 << 6)
#else
#define  MINT10_7PL   0xFFFF
#endif

#if (INT8PL >= INT10PL) || (INT8PL == 0)
#define  MINT10_8PL   ~(1 << 7)
#else
#define  MINT10_8PL   0xFFFF
#endif

#if (INT9PL >= INT10PL) || (INT9PL == 0)
#define  MINT10_9PL   ~(1 << 8)
#else
#define  MINT10_9PL   0xFFFF
#endif

#if (INT10PL == 0)
#define  MINT10_10PL   ~(1 << 9)
#else
#define  MINT10_10PL   0xFFFF
#endif

#if (INT11PL >= INT10PL) || (INT11PL == 0)
#define  MINT10_11PL   ~(1 << 10)
#else
#define  MINT10_11PL   0xFFFF
#endif

#if (INT12PL >= INT10PL) || (INT12PL == 0)
#define  MINT10_12PL   ~(1 << 11)
#else
#define  MINT10_12PL   0xFFFF
#endif

#if (INT13PL >= INT10PL) || (INT13PL == 0)
#define  MINT10_13PL   ~(1 << 12)
#else
#define  MINT10_13PL   0xFFFF
#endif

#if (INT14PL >= INT10PL) || (INT14PL == 0)
#define  MINT10_14PL   ~(1 << 13)
#else
#define  MINT10_14PL   0xFFFF
#endif

#if (INT15PL >= INT10PL) || (INT15PL == 0)
#define  MINT10_15PL   ~(1 << 14)
#else
#define  MINT10_15PL   0xFFFF
#endif

#if (INT16PL >= INT10PL) || (INT16PL == 0)
#define  MINT10_16PL   ~(1 << 15)
#else
#define  MINT10_16PL   0xFFFF
#endif

#define  MINT10   (MINT10_1PL  & MINT10_2PL  & MINT10_3PL  & MINT10_4PL  & \
                   MINT10_5PL  & MINT10_6PL  & MINT10_7PL  & MINT10_8PL  & \
                   MINT10_9PL  & MINT10_10PL & MINT10_11PL & MINT10_12PL & \
                   MINT10_13PL & MINT10_14PL & MINT10_15PL & MINT10_16PL)
// End Of MINT10.

// Beginning of MINT11:
#if (INT1PL >= INT11PL) || (INT1PL == 0)
#define  MINT11_1PL    ~(1 << 0)
#else
#define  MINT11_1PL    0xFFFF
#endif

#if (INT2PL >= INT11PL) || (INT2PL == 0)
#define  MINT11_2PL   ~(1 << 1)
#else
#define  MINT11_2PL   0xFFFF
#endif

#if (INT3PL >= INT11PL) || (INT3PL == 0)
#define  MINT11_3PL   ~(1 << 2)
#else
#define  MINT11_3PL   0xFFFF
#endif

#if (INT4PL >= INT11PL) || (INT4PL == 0)
#define  MINT11_4PL   ~(1 << 3)
#else
#define  MINT11_4PL   0xFFFF
#endif

#if (INT5PL >= INT11PL) || (INT5PL == 0)
#define  MINT11_5PL   ~(1 << 4)
#else
#define  MINT11_5PL   0xFFFF
#endif

#if (INT6PL >= INT11PL) || (INT6PL == 0)
#define  MINT11_6PL   ~(1 << 5)
#else
#define  MINT11_6PL   0xFFFF
#endif

#if (INT7PL >= INT11PL) || (INT7PL == 0)
#define  MINT11_7PL   ~(1 << 6)
#else
#define  MINT11_7PL   0xFFFF
#endif

#if (INT8PL >= INT11PL) || (INT8PL == 0)
#define  MINT11_8PL   ~(1 << 7)
#else
#define  MINT11_8PL   0xFFFF
#endif

#if (INT9PL >= INT11PL) || (INT9PL == 0)
#define  MINT11_9PL   ~(1 << 8)
#else
#define  MINT11_9PL   0xFFFF
#endif

#if (INT10PL >= INT11PL) || (INT10PL == 0)
#define  MINT11_10PL   ~(1 << 9)
#else
#define  MINT11_10PL   0xFFFF
#endif

#if (INT11PL == 0)
#define  MINT11_11PL   ~(1 << 10)
#else
#define  MINT11_11PL   0xFFFF
#endif

#if (INT12PL >= INT11PL) || (INT12PL == 0)
#define  MINT11_12PL   ~(1 << 11)
#else
#define  MINT11_12PL   0xFFFF
#endif

#if (INT13PL >= INT11PL) || (INT13PL == 0)
#define  MINT11_13PL   ~(1 << 12)
#else
#define  MINT11_13PL   0xFFFF
#endif

#if (INT14PL >= INT11PL) || (INT14PL == 0)
#define  MINT11_14PL   ~(1 << 13)
#else
#define  MINT11_14PL   0xFFFF
#endif

#if (INT15PL >= INT11PL) || (INT15PL == 0)
#define  MINT11_15PL   ~(1 << 14)
#else
#define  MINT11_15PL   0xFFFF
#endif

#if (INT16PL >= INT11PL) || (INT16PL == 0)
#define  MINT11_16PL   ~(1 << 15)
#else
#define  MINT11_16PL   0xFFFF
#endif

#define  MINT11   (MINT11_1PL  & MINT11_2PL  & MINT11_3PL  & MINT11_4PL  & \
                   MINT11_5PL  & MINT11_6PL  & MINT11_7PL  & MINT11_8PL  & \
                   MINT11_9PL  & MINT11_10PL & MINT11_11PL & MINT11_12PL & \
                   MINT11_13PL & MINT11_14PL & MINT11_15PL & MINT11_16PL)
// End Of MINT11.

// Beginning of MINT12:
#if (INT1PL >= INT12PL) || (INT1PL == 0)
#define  MINT12_1PL    ~(1 << 0)
#else
#define  MINT12_1PL    0xFFFF
#endif

#if (INT2PL >= INT12PL) || (INT2PL == 0)
#define  MINT12_2PL   ~(1 << 1)
#else
#define  MINT12_2PL   0xFFFF
#endif

#if (INT3PL >= INT12PL) || (INT3PL == 0)
#define  MINT12_3PL   ~(1 << 2)
#else
#define  MINT12_3PL   0xFFFF
#endif

#if (INT4PL >= INT12PL) || (INT4PL == 0)
#define  MINT12_4PL   ~(1 << 3)
#else
#define  MINT12_4PL   0xFFFF
#endif

#if (INT5PL >= INT12PL) || (INT5PL == 0)
#define  MINT12_5PL   ~(1 << 4)
#else
#define  MINT12_5PL   0xFFFF
#endif

#if (INT6PL >= INT12PL) || (INT6PL == 0)
#define  MINT12_6PL   ~(1 << 5)
#else
#define  MINT12_6PL   0xFFFF
#endif

#if (INT7PL >= INT12PL) || (INT7PL == 0)
#define  MINT12_7PL   ~(1 << 6)
#else
#define  MINT12_7PL   0xFFFF
#endif

#if (INT8PL >= INT12PL) || (INT8PL == 0)
#define  MINT12_8PL   ~(1 << 7)
#else
#define  MINT12_8PL   0xFFFF
#endif

#if (INT9PL >= INT12PL) || (INT9PL == 0)
#define  MINT12_9PL   ~(1 << 8)
#else
#define  MINT12_9PL   0xFFFF
#endif

#if (INT10PL >= INT12PL) || (INT10PL == 0)
#define  MINT12_10PL   ~(1 << 9)
#else
#define  MINT12_10PL   0xFFFF
#endif

#if (INT11PL >= INT12PL) || (INT11PL == 0)
#define  MINT12_11PL   ~(1 << 10)
#else
#define  MINT12_11PL   0xFFFF
#endif

#if (INT12PL == 0)
#define  MINT12_12PL   ~(1 << 11)
#else
#define  MINT12_12PL   0xFFFF
#endif

#if (INT13PL >= INT12PL) || (INT13PL == 0)
#define  MINT12_13PL   ~(1 << 12)
#else
#define  MINT12_13PL   0xFFFF
#endif

#if (INT14PL >= INT12PL) || (INT14PL == 0)
#define  MINT12_14PL   ~(1 << 13)
#else
#define  MINT12_14PL   0xFFFF
#endif

#if (INT15PL >= INT12PL) || (INT15PL == 0)
#define  MINT12_15PL   ~(1 << 14)
#else
#define  MINT12_15PL   0xFFFF
#endif

#if (INT16PL >= INT12PL) || (INT16PL == 0)
#define  MINT12_16PL   ~(1 << 15)
#else
#define  MINT12_16PL   0xFFFF
#endif

#define  MINT12   (MINT12_1PL  & MINT12_2PL  & MINT12_3PL  & MINT12_4PL  & \
                   MINT12_5PL  & MINT12_6PL  & MINT12_7PL  & MINT12_8PL  & \
                   MINT12_9PL  & MINT12_10PL & MINT12_11PL & MINT12_12PL & \
                   MINT12_13PL & MINT12_14PL & MINT12_15PL & MINT12_16PL)
// End Of MINT12.

// Beginning of MINT13:
#if (INT1PL >= INT13PL) || (INT1PL == 0)
#define  MINT13_1PL    ~(1 << 0)
#else
#define  MINT13_1PL    0xFFFF
#endif

#if (INT2PL >= INT13PL) || (INT2PL == 0)
#define  MINT13_2PL   ~(1 << 1)
#else
#define  MINT13_2PL   0xFFFF
#endif

#if (INT3PL >= INT13PL) || (INT3PL == 0)
#define  MINT13_3PL   ~(1 << 2)
#else
#define  MINT13_3PL   0xFFFF
#endif

#if (INT4PL >= INT13PL) || (INT4PL == 0)
#define  MINT13_4PL   ~(1 << 3)
#else
#define  MINT13_4PL   0xFFFF
#endif

#if (INT5PL >= INT13PL) || (INT5PL == 0)
#define  MINT13_5PL   ~(1 << 4)
#else
#define  MINT13_5PL   0xFFFF
#endif

#if (INT6PL >= INT13PL) || (INT6PL == 0)
#define  MINT13_6PL   ~(1 << 5)
#else
#define  MINT13_6PL   0xFFFF
#endif

#if (INT7PL >= INT13PL) || (INT7PL == 0)
#define  MINT13_7PL   ~(1 << 6)
#else
#define  MINT13_7PL   0xFFFF
#endif

#if (INT8PL >= INT13PL) || (INT8PL == 0)
#define  MINT13_8PL   ~(1 << 7)
#else
#define  MINT13_8PL   0xFFFF
#endif

#if (INT9PL >= INT13PL) || (INT9PL == 0)
#define  MINT13_9PL   ~(1 << 8)
#else
#define  MINT13_9PL   0xFFFF
#endif

#if (INT10PL >= INT13PL) || (INT10PL == 0)
#define  MINT13_10PL   ~(1 << 9)
#else
#define  MINT13_10PL   0xFFFF
#endif

#if (INT11PL >= INT13PL) || (INT11PL == 0)
#define  MINT13_11PL   ~(1 << 10)
#else
#define  MINT13_11PL   0xFFFF
#endif

#define  MINT13_12PL   ~(1 << 11)

#if (INT13PL == 0)
#define  MINT13_13PL   ~(1 << 12)
#else
#define  MINT13_13PL   0xFFFF
#endif

#if (INT14PL >= INT13PL) || (INT14PL == 0)
#define  MINT13_14PL   ~(1 << 13)
#else
#define  MINT13_14PL   0xFFFF
#endif

#if (INT15PL >= INT13PL) || (INT15PL == 0)
#define  MINT13_15PL   ~(1 << 14)
#else
#define  MINT13_15PL   0xFFFF
#endif

#if (INT16PL >= INT13PL) || (INT16PL == 0)
#define  MINT13_16PL   ~(1 << 15)
#else
#define  MINT13_16PL   0xFFFF
#endif

#define  MINT13   (MINT13_1PL  & MINT13_2PL  & MINT13_3PL  & MINT13_4PL  & \
                   MINT13_5PL  & MINT13_6PL  & MINT13_7PL  & MINT13_8PL  & \
                   MINT13_9PL  & MINT13_10PL & MINT13_11PL & MINT13_12PL & \
                   MINT13_13PL & MINT13_14PL & MINT13_15PL & MINT13_16PL)
// End Of MINT13.

// Beginning of MINT14:
#if (INT1PL >= INT14PL) || (INT1PL == 0)
#define  MINT14_1PL    ~(1 << 0)
#else
#define  MINT14_1PL    0xFFFF
#endif

#if (INT2PL >= INT14PL) || (INT2PL == 0)
#define  MINT14_2PL   ~(1 << 1)
#else
#define  MINT14_2PL   0xFFFF
#endif

#if (INT3PL >= INT14PL) || (INT3PL == 0)
#define  MINT14_3PL   ~(1 << 2)
#else
#define  MINT14_3PL   0xFFFF
#endif

#if (INT4PL >= INT14PL) || (INT4PL == 0)
#define  MINT14_4PL   ~(1 << 3)
#else
#define  MINT14_4PL   0xFFFF
#endif

#if (INT5PL >= INT14PL) || (INT5PL == 0)
#define  MINT14_5PL   ~(1 << 4)
#else
#define  MINT14_5PL   0xFFFF
#endif

#if (INT6PL >= INT14PL) || (INT6PL == 0)
#define  MINT14_6PL   ~(1 << 5)
#else
#define  MINT14_6PL   0xFFFF
#endif

#if (INT7PL >= INT14PL) || (INT7PL == 0)
#define  MINT14_7PL   ~(1 << 6)
#else
#define  MINT14_7PL   0xFFFF
#endif

#if (INT8PL >= INT14PL) || (INT8PL == 0)
#define  MINT14_8PL   ~(1 << 7)
#else
#define  MINT14_8PL   0xFFFF
#endif

#if (INT9PL >= INT14PL) || (INT9PL == 0)
#define  MINT14_9PL   ~(1 << 8)
#else
#define  MINT14_9PL   0xFFFF
#endif

#if (INT10PL >= INT14PL) || (INT10PL == 0)
#define  MINT14_10PL   ~(1 << 9)
#else
#define  MINT14_10PL   0xFFFF
#endif

#if (INT11PL >= INT14PL) || (INT11PL == 0)
#define  MINT14_11PL   ~(1 << 10)
#else
#define  MINT14_11PL   0xFFFF
#endif

#if (INT12PL >= INT14PL) || (INT12PL == 0)
#define  MINT14_12PL   ~(1 << 11)
#else
#define  MINT14_12PL   0xFFFF
#endif

#if (INT13PL >= INT14PL) || (INT13PL == 0)
#define  MINT14_13PL   ~(1 << 12)
#else
#define  MINT14_13PL   0xFFFF
#endif

#define  MINT14_14PL   ~(1 << 13)

#if (INT15PL >= INT14PL) || (INT15PL == 0)
#define  MINT14_15PL   ~(1 << 14)
#else
#define  MINT14_15PL   0xFFFF
#endif

#if (INT16PL >= INT14PL) || (INT16PL == 0)
#define  MINT14_16PL   ~(1 << 15)
#else
#define  MINT14_16PL   0xFFFF
#endif

#define  MINT14   (MINT14_1PL  & MINT14_2PL  & MINT14_3PL  & MINT14_4PL  & \
                   MINT14_5PL  & MINT14_6PL  & MINT14_7PL  & MINT14_8PL  & \
                   MINT14_9PL  & MINT14_10PL & MINT14_11PL & MINT14_12PL & \
                   MINT14_13PL & MINT14_14PL & MINT14_15PL & MINT14_16PL)
// End Of MINT14.

// Beginning of MINT15:
#if (INT1PL >= INT15PL) || (INT1PL == 0)
#define  MINT15_1PL    ~(1 << 0)
#else
#define  MINT15_1PL    0xFFFF
#endif

#if (INT2PL >= INT15PL) || (INT2PL == 0)
#define  MINT15_2PL   ~(1 << 1)
#else
#define  MINT15_2PL   0xFFFF
#endif

#if (INT3PL >= INT15PL) || (INT3PL == 0)
#define  MINT15_3PL   ~(1 << 2)
#else
#define  MINT15_3PL   0xFFFF
#endif

#if (INT4PL >= INT15PL) || (INT4PL == 0)
#define  MINT15_4PL   ~(1 << 3)
#else
#define  MINT15_4PL   0xFFFF
#endif

#if (INT5PL >= INT15PL) || (INT5PL == 0)
#define  MINT15_5PL   ~(1 << 4)
#else
#define  MINT15_5PL   0xFFFF
#endif

#if (INT6PL >= INT15PL) || (INT6PL == 0)
#define  MINT15_6PL   ~(1 << 5)
#else
#define  MINT15_6PL   0xFFFF
#endif

#if (INT7PL >= INT15PL) || (INT7PL == 0)
#define  MINT15_7PL   ~(1 << 6)
#else
#define  MINT15_7PL   0xFFFF
#endif

#if (INT8PL >= INT15PL) || (INT8PL == 0)
#define  MINT15_8PL   ~(1 << 7)
#else
#define  MINT15_8PL   0xFFFF
#endif

#if (INT9PL >= INT15PL) || (INT9PL == 0)
#define  MINT15_9PL   ~(1 << 8)
#else
#define  MINT15_9PL   0xFFFF
#endif

#if (INT10PL >= INT15PL) || (INT10PL == 0)
#define  MINT15_10PL   ~(1 << 9)
#else
#define  MINT15_10PL   0xFFFF
#endif

#if (INT11PL >= INT15PL) || (INT11PL == 0)
#define  MINT15_11PL   ~(1 << 10)
#else
#define  MINT15_11PL   0xFFFF
#endif

#if (INT12PL >= INT15PL) || (INT12PL == 0)
#define  MINT15_12PL   ~(1 << 11)
#else
#define  MINT15_12PL   0xFFFF
#endif

#if (INT13PL >= INT15PL) || (INT13PL == 0)
#define  MINT15_13PL   ~(1 << 12)
#else
#define  MINT15_13PL   0xFFFF
#endif

#if (INT14PL >= INT15PL) || (INT14PL == 0)
#define  MINT15_14PL   ~(1 << 13)
#else
#define  MINT15_14PL   0xFFFF
#endif

#define  MINT15_15PL   ~(1 << 14)

#if (INT16PL >= INT15PL) || (INT16PL == 0)
#define  MINT15_16PL   ~(1 << 15)
#else
#define  MINT15_16PL   0xFFFF
#endif

#define  MINT15   (MINT15_1PL  & MINT15_2PL  & MINT15_3PL  & MINT15_4PL  & \
                   MINT15_5PL  & MINT15_6PL  & MINT15_7PL  & MINT15_8PL  & \
                   MINT15_9PL  & MINT15_10PL & MINT15_11PL & MINT15_12PL & \
                   MINT15_13PL & MINT15_14PL & MINT15_15PL & MINT15_16PL)
// End Of MINT15.

// Beginning of MINT16:
#if (INT1PL >= INT16PL) || (INT1PL == 0)
#define  MINT16_1PL    ~(1 << 0)
#else
#define  MINT16_1PL    0xFFFF
#endif

#if (INT2PL >= INT16PL) || (INT2PL == 0)
#define  MINT16_2PL   ~(1 << 1)
#else
#define  MINT16_2PL   0xFFFF
#endif

#if (INT3PL >= INT16PL) || (INT3PL == 0)
#define  MINT16_3PL   ~(1 << 2)
#else
#define  MINT16_3PL   0xFFFF
#endif

#if (INT4PL >= INT16PL) || (INT4PL == 0)
#define  MINT16_4PL   ~(1 << 3)
#else
#define  MINT16_4PL   0xFFFF
#endif

#if (INT5PL >= INT16PL) || (INT5PL == 0)
#define  MINT16_5PL   ~(1 << 4)
#else
#define  MINT16_5PL   0xFFFF
#endif

#if (INT6PL >= INT16PL) || (INT6PL == 0)
#define  MINT16_6PL   ~(1 << 5)
#else
#define  MINT16_6PL   0xFFFF
#endif

#if (INT7PL >= INT16PL) || (INT7PL == 0)
#define  MINT16_7PL   ~(1 << 6)
#else
#define  MINT16_7PL   0xFFFF
#endif

#if (INT8PL >= INT16PL) || (INT8PL == 0)
#define  MINT16_8PL   ~(1 << 7)
#else
#define  MINT16_8PL   0xFFFF
#endif

#if (INT9PL >= INT16PL) || (INT9PL == 0)
#define  MINT16_9PL   ~(1 << 8)
#else
#define  MINT16_9PL   0xFFFF
#endif

#if (INT10PL >= INT16PL) || (INT10PL == 0)
#define  MINT16_10PL   ~(1 << 9)
#else
#define  MINT16_10PL   0xFFFF
#endif

#if (INT11PL >= INT16PL) || (INT11PL == 0)
#define  MINT16_11PL   ~(1 << 10)
#else
#define  MINT16_11PL   0xFFFF
#endif

#if (INT12PL >= INT16PL) || (INT12PL == 0)
#define  MINT16_12PL   ~(1 << 11)
#else
#define  MINT16_12PL   0xFFFF
#endif

#if (INT13PL >= INT16PL) || (INT13PL == 0)
#define  MINT16_13PL   ~(1 << 12)
#else
#define  MINT16_13PL   0xFFFF
#endif

#if (INT14PL >= INT16PL) || (INT14PL == 0)
#define  MINT16_14PL   ~(1 << 13)
#else
#define  MINT16_14PL   0xFFFF
#endif

#if (INT15PL >= INT16PL) || (INT15PL == 0)
#define  MINT16_15PL   ~(1 << 14)
#else
#define  MINT16_15PL   0xFFFF
#endif

#define  MINT16_16PL   ~(1 << 15)

#define  MINT16   (MINT16_1PL  & MINT16_2PL  & MINT16_3PL  & MINT16_4PL  & \
                   MINT16_5PL  & MINT16_6PL  & MINT16_7PL  & MINT16_8PL  & \
                   MINT16_9PL  & MINT16_10PL & MINT16_11PL & MINT16_12PL & \
                   MINT16_13PL & MINT16_14PL & MINT16_15PL & MINT16_16PL)
// End Of MINT16.

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG11 to MG18:

// Beginning of MG11:
#if (G12PL >= G11PL) || (G12PL == 0)
#define  MG11_12PL   ~(1 << 1)
#else
#define  MG11_12PL   0xFFFF
#endif

#if (G13PL >= G11PL) || (G13PL == 0)
#define  MG11_13PL   ~(1 << 2)
#else
#define  MG11_13PL   0xFFFF
#endif

#if (G14PL >= G11PL) || (G14PL == 0)
#define  MG11_14PL   ~(1 << 3)
#else
#define  MG11_14PL   0xFFFF
#endif

#if (G15PL >= G11PL) || (G15PL == 0)
#define  MG11_15PL   ~(1 << 4)
#else
#define  MG11_15PL   0xFFFF
#endif

#if (G16PL >= G11PL) || (G16PL == 0)
#define  MG11_16PL   ~(1 << 5)
#else
#define  MG11_16PL   0xFFFF
#endif

#if (G17PL >= G11PL) || (G17PL == 0)
#define  MG11_17PL   ~(1 << 6)
#else
#define  MG11_17PL   0xFFFF
#endif

#if (G18PL >= G11PL) || (G18PL == 0)
#define  MG11_18PL   ~(1 << 7)
#else
#define  MG11_18PL   0xFFFF
#endif

#define  MG11_11PL   0x00FE
#define  MG11    (MG11_11PL & MG11_12PL & MG11_13PL & MG11_14PL & \
                  MG11_15PL & MG11_16PL & MG11_17PL & MG11_18PL)
// End of MG11:

// Beginning of MG12:
#if (G11PL >= G12PL) || (G11PL == 0)
#define  MG12_11PL   ~(1)
#else
#define  MG12_11PL   0xFFFF
#endif
#if (G13PL >= G12PL) || (G13PL == 0)
#define  MG12_13PL   ~(1 << 2)
#else
#define  MG12_13PL   0xFFFF
#endif
#if (G14PL >= G12PL) || (G14PL == 0)
#define  MG12_14PL   ~(1 << 3)
#else
#define  MG12_14PL   0xFFFF
#endif
#if (G15PL >= G12PL) || (G15PL == 0)
#define  MG12_15PL   ~(1 << 4)
#else
#define  MG12_15PL   0xFFFF
#endif
#if (G16PL >= G12PL) || (G16PL == 0)
#define  MG12_16PL   ~(1 << 5)
#else
#define  MG12_16PL   0xFFFF
#endif
#if (G17PL >= G12PL) || (G17PL == 0)
#define  MG12_17PL   ~(1 << 6)
#else
#define  MG12_17PL   0xFFFF
#endif
#if (G18PL >= G12PL) || (G18PL == 0)
#define  MG12_18PL   ~(1 << 7)
#else
#define  MG12_18PL   0xFFFF
#endif
#define  MG12_12PL   0x00FD
#define  MG12    (MG12_11PL & MG12_12PL & MG12_13PL & MG12_14PL & \
                  MG12_15PL & MG12_16PL & MG12_17PL & MG12_18PL)
// End of MG12:

// Beginning of MG13:
#if (G11PL >= G13PL) || (G11PL == 0)
#define  MG13_11PL   ~(1)
#else
#define  MG13_11PL   0xFFFF
#endif
#if (G12PL >= G13PL) || (G12PL == 0)
#define  MG13_12PL   ~(1 << 1)
#else
#define  MG13_12PL   0xFFFF
#endif
#if (G14PL >= G13PL) || (G14PL == 0)
#define  MG13_14PL   ~(1 << 3)
#else
#define  MG13_14PL   0xFFFF
#endif
#if (G15PL >= G13PL) || (G15PL == 0)
#define  MG13_15PL   ~(1 << 4)
#else
#define  MG13_15PL   0xFFFF
#endif
#if (G16PL >= G13PL) || (G16PL == 0)
#define  MG13_16PL   ~(1 << 5)
#else
#define  MG13_16PL   0xFFFF
#endif
#if (G17PL >= G13PL) || (G17PL == 0)
#define  MG13_17PL   ~(1 << 6)
#else
#define  MG13_17PL   0xFFFF
#endif
#if (G18PL >= G13PL) || (G18PL == 0)
#define  MG13_18PL   ~(1 << 7)
#else
#define  MG13_18PL   0xFFFF
#endif
#define  MG13_13PL   0x00FB
#define  MG13    (MG13_11PL & MG13_12PL & MG13_13PL & MG13_14PL & \
                  MG13_15PL & MG13_16PL & MG13_17PL & MG13_18PL)
// End of MG13:

// Beginning of MG14:
#if (G11PL >= G14PL) || (G11PL == 0)
#define  MG14_11PL   ~(1)
#else
#define  MG14_11PL   0xFFFF
#endif
#if (G12PL >= G14PL) || (G12PL == 0)
#define  MG14_12PL   ~(1 << 1)
#else
#define  MG14_12PL   0xFFFF
#endif
#if (G13PL >= G14PL) || (G13PL == 0)
#define  MG14_13PL   ~(1 << 2)
#else
#define  MG14_13PL   0xFFFF
#endif
#if (G15PL >= G14PL) || (G15PL == 0)
#define  MG14_15PL   ~(1 << 4)
#else
#define  MG14_15PL   0xFFFF
#endif
#if (G16PL >= G14PL) || (G16PL == 0)
#define  MG14_16PL   ~(1 << 5)
#else
#define  MG14_16PL   0xFFFF
#endif
#if (G17PL >= G14PL) || (G17PL == 0)
#define  MG14_17PL   ~(1 << 6)
#else
#define  MG14_17PL   0xFFFF
#endif
#if (G18PL >= G14PL) || (G18PL == 0)
#define  MG14_18PL   ~(1 << 7)
#else
#define  MG14_18PL   0xFFFF
#endif
#define  MG14_14PL   0x00F7
#define  MG14    (MG14_11PL & MG14_12PL & MG14_13PL & MG14_14PL & \
                  MG14_15PL & MG14_16PL & MG14_17PL & MG14_18PL)
// End of MG14:

// Beginning of MG15:
#if (G11PL >= G15PL) || (G11PL == 0)
#define  MG15_11PL   ~(1)
#else
#define  MG15_11PL   0xFFFF
#endif
#if (G12PL >= G15PL) || (G12PL == 0)
#define  MG15_12PL   ~(1 << 1)
#else
#define  MG15_12PL   0xFFFF
#endif
#if (G13PL >= G15PL) || (G13PL == 0)
#define  MG15_13PL   ~(1 << 2)
#else
#define  MG15_13PL   0xFFFF
#endif
#if (G14PL >= G15PL) || (G14PL == 0)
#define  MG15_14PL   ~(1 << 3)
#else
#define  MG15_14PL   0xFFFF
#endif
#if (G16PL >= G15PL) || (G16PL == 0)
#define  MG15_16PL   ~(1 << 5)
#else
#define  MG15_16PL   0xFFFF
#endif
#if (G17PL >= G15PL) || (G17PL == 0)
#define  MG15_17PL   ~(1 << 6)
#else
#define  MG15_17PL   0xFFFF
#endif
#if (G18PL >= G15PL) || (G18PL == 0)
#define  MG15_18PL   ~(1 << 7)
#else
#define  MG15_18PL   0xFFFF
#endif
#define  MG15_15PL   0x00EF
#define  MG15    (MG15_11PL & MG15_12PL & MG15_13PL & MG15_14PL & \
                  MG15_15PL & MG15_16PL & MG15_17PL & MG15_18PL)
// End of MG15:

// Beginning of MG16:
#if (G11PL >= G16PL) || (G11PL == 0)
#define  MG16_11PL   ~(1)
#else
#define  MG16_11PL   0xFFFF
#endif
#if (G12PL >= G16PL) || (G12PL == 0)
#define  MG16_12PL   ~(1 << 1)
#else
#define  MG16_12PL   0xFFFF
#endif
#if (G13PL >= G16PL) || (G13PL == 0)
#define  MG16_13PL   ~(1 << 2)
#else
#define  MG16_13PL   0xFFFF
#endif
#if (G14PL >= G16PL) || (G14PL == 0)
#define  MG16_14PL   ~(1 << 3)
#else
#define  MG16_14PL   0xFFFF
#endif
#if (G15PL >= G16PL) || (G15PL == 0)
#define  MG16_15PL   ~(1 << 4)
#else
#define  MG16_15PL   0xFFFF
#endif
#if (G17PL >= G16PL) || (G17PL == 0)
#define  MG16_17PL   ~(1 << 6)
#else
#define  MG16_17PL   0xFFFF
#endif
#if (G18PL >= G16PL) || (G18PL == 0)
#define  MG16_18PL   ~(1 << 7)
#else
#define  MG16_18PL   0xFFFF
#endif
#define  MG16_16PL   0x00DF
#define  MG16    (MG16_11PL & MG16_12PL & MG16_13PL & MG16_14PL & \
                  MG16_15PL & MG16_16PL & MG16_17PL & MG16_18PL)
// End of MG16:

// Beginning of MG17:
#if (G11PL >= G17PL) || (G11PL == 0)
#define  MG17_11PL   ~(1)
#else
#define  MG17_11PL   0xFFFF
#endif
#if (G12PL >= G17PL) || (G12PL == 0)
#define  MG17_12PL   ~(1 << 1)
#else
#define  MG17_12PL   0xFFFF
#endif
#if (G13PL >= G17PL) || (G13PL == 0)
#define  MG17_13PL   ~(1 << 2)
#else
#define  MG17_13PL   0xFFFF
#endif
#if (G14PL >= G17PL) || (G14PL == 0)
#define  MG17_14PL   ~(1 << 3)
#else
#define  MG17_14PL   0xFFFF
#endif
#if (G15PL >= G17PL) || (G15PL == 0)
#define  MG17_15PL   ~(1 << 4)
#else
#define  MG17_15PL   0xFFFF
#endif
#if (G16PL >= G17PL) || (G16PL == 0)
#define  MG17_16PL   ~(1 << 5)
#else
#define  MG17_16PL   0xFFFF
#endif
#if (G18PL >= G17PL) || (G18PL == 0)
#define  MG17_18PL   ~(1 << 7)
#else
#define  MG17_18PL   0xFFFF
#endif
#define  MG17_17PL   0x00BF
#define  MG17    (MG17_11PL & MG17_12PL & MG17_13PL & MG17_14PL & \
                  MG17_15PL & MG17_16PL & MG17_17PL & MG17_18PL)
// End of MG17:

// Beginning of MG18:
#if (G11PL >= G18PL) || (G11PL == 0)
#define  MG18_11PL   ~(1)
#else
#define  MG18_11PL   0xFFFF
#endif
#if (G12PL >= G18PL) || (G12PL == 0)
#define  MG18_12PL   ~(1 << 1)
#else
#define  MG18_12PL   0xFFFF
#endif
#if (G13PL >= G18PL) || (G13PL == 0)
#define  MG18_13PL   ~(1 << 2)
#else
#define  MG18_13PL   0xFFFF
#endif
#if (G14PL >= G18PL) || (G14PL == 0)
#define  MG18_14PL   ~(1 << 3)
#else
#define  MG18_14PL   0xFFFF
#endif
#if (G15PL >= G18PL) || (G15PL == 0)
#define  MG18_15PL   ~(1 << 4)
#else
#define  MG18_15PL   0xFFFF
#endif
#if (G16PL >= G18PL) || (G16PL == 0)
#define  MG18_16PL   ~(1 << 5)
#else
#define  MG18_16PL   0xFFFF
#endif
#if (G17PL >= G18PL) || (G17PL == 0)
#define  MG18_17PL   ~(1 << 6)
#else
#define  MG18_17PL   0xFFFF
#endif
#define  MG18_18PL   0x007F
#define  MG18    (MG18_11PL & MG18_12PL & MG18_13PL & MG18_14PL & \
                  MG18_15PL & MG18_16PL & MG18_17PL & MG18_18PL)
// End of MG18:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG21 to MG28:
//

// Beginning of MG21:
#if (G22PL >= G21PL) || (G22PL == 0)
#define  MG21_12PL   ~(1 << 1)
#else
#define  MG21_12PL   0xFFFF
#endif
#if (G23PL >= G21PL) || (G23PL == 0)
#define  MG21_13PL   ~(1 << 2)
#else
#define  MG21_13PL   0xFFFF
#endif
#if (G24PL >= G21PL) || (G24PL == 0)
#define  MG21_14PL   ~(1 << 3)
#else
#define  MG21_14PL   0xFFFF
#endif
#if (G25PL >= G21PL) || (G25PL == 0)
#define  MG21_15PL   ~(1 << 4)
#else
#define  MG21_15PL   0xFFFF
#endif
#if (G26PL >= G21PL) || (G26PL == 0)
#define  MG21_16PL   ~(1 << 5)
#else
#define  MG21_16PL   0xFFFF
#endif
#if (G27PL >= G21PL) || (G27PL == 0)
#define  MG21_17PL   ~(1 << 6)
#else
#define  MG21_17PL   0xFFFF
#endif
#if (G28PL >= G21PL) || (G28PL == 0)
#define  MG21_18PL   ~(1 << 7)
#else
#define  MG21_18PL   0xFFFF
#endif
#define  MG21_11PL   0x00FE
#define  MG21    (MG21_11PL & MG21_12PL & MG21_13PL & MG21_14PL & \
                  MG21_15PL & MG21_16PL & MG21_17PL & MG21_18PL)
// End of MG21:

// Beginning of MG22:
#if (G21PL >= G22PL) || (G21PL == 0)
#define  MG22_11PL   ~(1)
#else
#define  MG22_11PL   0xFFFF
#endif
#if (G23PL >= G22PL) || (G23PL == 0)
#define  MG22_13PL   ~(1 << 2)
#else
#define  MG22_13PL   0xFFFF
#endif
#if (G24PL >= G22PL) || (G24PL == 0)
#define  MG22_14PL   ~(1 << 3)
#else
#define  MG22_14PL   0xFFFF
#endif
#if (G25PL >= G22PL) || (G25PL == 0)
#define  MG22_15PL   ~(1 << 4)
#else
#define  MG22_15PL   0xFFFF
#endif
#if (G26PL >= G22PL) || (G26PL == 0)
#define  MG22_16PL   ~(1 << 5)
#else
#define  MG22_16PL   0xFFFF
#endif
#if (G27PL >= G22PL) || (G27PL == 0)
#define  MG22_17PL   ~(1 << 6)
#else
#define  MG22_17PL   0xFFFF
#endif
#if (G28PL >= G22PL) || (G28PL == 0)
#define  MG22_18PL   ~(1 << 7)
#else
#define  MG22_18PL   0xFFFF
#endif
#define  MG22_12PL   0x00FD
#define  MG22    (MG22_11PL & MG22_12PL & MG22_13PL & MG22_14PL & \
                  MG22_15PL & MG22_16PL & MG22_17PL & MG22_18PL)
// End of MG22:

// Beginning of MG23:
#if (G21PL >= G23PL) || (G21PL == 0)
#define  MG23_11PL   ~(1)
#else
#define  MG23_11PL   0xFFFF
#endif
#if (G22PL >= G23PL) || (G22PL == 0)
#define  MG23_12PL   ~(1 << 1)
#else
#define  MG23_12PL   0xFFFF
#endif
#if (G24PL >= G23PL) || (G24PL == 0)
#define  MG23_14PL   ~(1 << 3)
#else
#define  MG23_14PL   0xFFFF
#endif
#if (G25PL >= G23PL) || (G25PL == 0)
#define  MG23_15PL   ~(1 << 4)
#else
#define  MG23_15PL   0xFFFF
#endif
#if (G26PL >= G23PL) || (G26PL == 0)
#define  MG23_16PL   ~(1 << 5)
#else
#define  MG23_16PL   0xFFFF
#endif
#if (G27PL >= G23PL) || (G27PL == 0)
#define  MG23_17PL   ~(1 << 6)
#else
#define  MG23_17PL   0xFFFF
#endif
#if (G28PL >= G23PL) || (G28PL == 0)
#define  MG23_18PL   ~(1 << 7)
#else
#define  MG23_18PL   0xFFFF
#endif
#define  MG23_13PL   0x00FB
#define  MG23    (MG23_11PL & MG23_12PL & MG23_13PL & MG23_14PL & \
                  MG23_15PL & MG23_16PL & MG23_17PL & MG23_18PL)
// End of MG23:

// Beginning of MG24:
#if (G21PL >= G24PL) || (G21PL == 0)
#define  MG24_11PL   ~(1)
#else
#define  MG24_11PL   0xFFFF
#endif
#if (G22PL >= G24PL) || (G22PL == 0)
#define  MG24_12PL   ~(1 << 1)
#else
#define  MG24_12PL   0xFFFF
#endif
#if (G23PL >= G24PL) || (G23PL == 0)
#define  MG24_13PL   ~(1 << 2)
#else
#define  MG24_13PL   0xFFFF
#endif
#if (G25PL >= G24PL) || (G25PL == 0)
#define  MG24_15PL   ~(1 << 4)
#else
#define  MG24_15PL   0xFFFF
#endif
#if (G26PL >= G24PL) || (G26PL == 0)
#define  MG24_16PL   ~(1 << 5)
#else
#define  MG24_16PL   0xFFFF
#endif
#if (G27PL >= G24PL) || (G27PL == 0)
#define  MG24_17PL   ~(1 << 6)
#else
#define  MG24_17PL   0xFFFF
#endif
#if (G28PL >= G24PL) || (G28PL == 0)
#define  MG24_18PL   ~(1 << 7)
#else
#define  MG24_18PL   0xFFFF
#endif
#define  MG24_14PL   0x00F7
#define  MG24    (MG24_11PL & MG24_12PL & MG24_13PL & MG24_14PL & \
                  MG24_15PL & MG24_16PL & MG24_17PL & MG24_18PL)
// End of MG24:

// Beginning of MG25:
#if (G21PL >= G25PL) || (G21PL == 0)
#define  MG25_11PL   ~(1)
#else
#define  MG25_11PL   0xFFFF
#endif
#if (G22PL >= G25PL) || (G22PL == 0)
#define  MG25_12PL   ~(1 << 1)
#else
#define  MG25_12PL   0xFFFF
#endif
#if (G23PL >= G25PL) || (G23PL == 0)
#define  MG25_13PL   ~(1 << 2)
#else
#define  MG25_13PL   0xFFFF
#endif
#if (G24PL >= G25PL) || (G24PL == 0)
#define  MG25_14PL   ~(1 << 3)
#else
#define  MG25_14PL   0xFFFF
#endif
#if (G26PL >= G25PL) || (G26PL == 0)
#define  MG25_16PL   ~(1 << 5)
#else
#define  MG25_16PL   0xFFFF
#endif
#if (G27PL >= G25PL) || (G27PL == 0)
#define  MG25_17PL   ~(1 << 6)
#else
#define  MG25_17PL   0xFFFF
#endif
#if (G28PL >= G25PL) || (G28PL == 0)
#define  MG25_18PL   ~(1 << 7)
#else
#define  MG25_18PL   0xFFFF
#endif
#define  MG25_15PL   0x00EF
#define  MG25    (MG25_11PL & MG25_12PL & MG25_13PL & MG25_14PL & \
                  MG25_15PL & MG25_16PL & MG25_17PL & MG25_18PL)
// End of MG25:

// Beginning of MG26:
#if (G21PL >= G26PL) || (G21PL == 0)
#define  MG26_11PL   ~(1)
#else
#define  MG26_11PL   0xFFFF
#endif
#if (G22PL >= G26PL) || (G22PL == 0)
#define  MG26_12PL   ~(1 << 1)
#else
#define  MG26_12PL   0xFFFF
#endif
#if (G23PL >= G26PL) || (G23PL == 0)
#define  MG26_13PL   ~(1 << 2)
#else
#define  MG26_13PL   0xFFFF
#endif
#if (G24PL >= G26PL) || (G24PL == 0)
#define  MG26_14PL   ~(1 << 3)
#else
#define  MG26_14PL   0xFFFF
#endif
#if (G25PL >= G26PL) || (G25PL == 0)
#define  MG26_15PL   ~(1 << 4)
#else
#define  MG26_15PL   0xFFFF
#endif
#if (G27PL >= G26PL) || (G27PL == 0)
#define  MG26_17PL   ~(1 << 6)
#else
#define  MG26_17PL   0xFFFF
#endif
#if (G28PL >= G26PL) || (G28PL == 0)
#define  MG26_18PL   ~(1 << 7)
#else
#define  MG26_18PL   0xFFFF
#endif
#define  MG26_16PL   0x00DF
#define  MG26    (MG26_11PL & MG26_12PL & MG26_13PL & MG26_14PL & \
                  MG26_15PL & MG26_16PL & MG26_17PL & MG26_18PL)
// End of MG26:

// Beginning of MG27:
#if (G21PL >= G27PL) || (G21PL == 0)
#define  MG27_11PL   ~(1)
#else
#define  MG27_11PL   0xFFFF
#endif
#if (G22PL >= G27PL) || (G22PL == 0)
#define  MG27_12PL   ~(1 << 1)
#else
#define  MG27_12PL   0xFFFF
#endif
#if (G23PL >= G27PL) || (G23PL == 0)
#define  MG27_13PL   ~(1 << 2)
#else
#define  MG27_13PL   0xFFFF
#endif
#if (G24PL >= G27PL) || (G24PL == 0)
#define  MG27_14PL   ~(1 << 3)
#else
#define  MG27_14PL   0xFFFF
#endif
#if (G25PL >= G27PL) || (G25PL == 0)
#define  MG27_15PL   ~(1 << 4)
#else
#define  MG27_15PL   0xFFFF
#endif
#if (G26PL >= G27PL) || (G26PL == 0)
#define  MG27_16PL   ~(1 << 5)
#else
#define  MG27_16PL   0xFFFF
#endif
#if (G28PL >= G27PL) || (G28PL == 0)
#define  MG27_18PL   ~(1 << 7)
#else
#define  MG27_18PL   0xFFFF
#endif
#define  MG27_17PL   0x00BF
#define  MG27    (MG27_11PL & MG27_12PL & MG27_13PL & MG27_14PL & \
                  MG27_15PL & MG27_16PL & MG27_17PL & MG27_18PL)
// End of MG27:

// Beginning of MG28:
#if (G21PL >= G28PL) || (G21PL == 0)
#define  MG28_11PL   ~(1)
#else
#define  MG28_11PL   0xFFFF
#endif
#if (G22PL >= G28PL) || (G22PL == 0)
#define  MG28_12PL   ~(1 << 1)
#else
#define  MG28_12PL   0xFFFF
#endif
#if (G23PL >= G28PL) || (G23PL == 0)
#define  MG28_13PL   ~(1 << 2)
#else
#define  MG28_13PL   0xFFFF
#endif
#if (G24PL >= G28PL) || (G24PL == 0)
#define  MG28_14PL   ~(1 << 3)
#else
#define  MG28_14PL   0xFFFF
#endif
#if (G25PL >= G28PL) || (G25PL == 0)
#define  MG28_15PL   ~(1 << 4)
#else
#define  MG28_15PL   0xFFFF
#endif
#if (G26PL >= G28PL) || (G26PL == 0)
#define  MG28_16PL   ~(1 << 5)
#else
#define  MG28_16PL   0xFFFF
#endif
#if (G27PL >= G28PL) || (G27PL == 0)
#define  MG28_17PL   ~(1 << 6)
#else
#define  MG28_17PL   0xFFFF
#endif
#define  MG28_18PL   0x007F
#define  MG28    (MG28_11PL & MG28_12PL & MG28_13PL & MG28_14PL & \
                  MG28_15PL & MG28_16PL & MG28_17PL & MG28_18PL)
// End of MG28:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG31 to MG38:
//

// Beginning of MG31:
#if (G32PL >= G31PL) || (G32PL == 0)
#define  MG31_12PL   ~(1 << 1)
#else
#define  MG31_12PL   0xFFFF
#endif
#if (G33PL >= G31PL) || (G33PL == 0)
#define  MG31_13PL   ~(1 << 2)
#else
#define  MG31_13PL   0xFFFF
#endif
#if (G34PL >= G31PL) || (G34PL == 0)
#define  MG31_14PL   ~(1 << 3)
#else
#define  MG31_14PL   0xFFFF
#endif
#if (G35PL >= G31PL) || (G35PL == 0)
#define  MG31_15PL   ~(1 << 4)
#else
#define  MG31_15PL   0xFFFF
#endif
#if (G36PL >= G31PL) || (G36PL == 0)
#define  MG31_16PL   ~(1 << 5)
#else
#define  MG31_16PL   0xFFFF
#endif
#if (G37PL >= G31PL) || (G37PL == 0)
#define  MG31_17PL   ~(1 << 6)
#else
#define  MG31_17PL   0xFFFF
#endif
#if (G38PL >= G31PL) || (G38PL == 0)
#define  MG31_18PL   ~(1 << 7)
#else
#define  MG31_18PL   0xFFFF
#endif
#define  MG31_11PL   0x00FE
#define  MG31    (MG31_11PL & MG31_12PL & MG31_13PL & MG31_14PL & \
                  MG31_15PL & MG31_16PL & MG31_17PL & MG31_18PL)
// End of MG31:

// Beginning of MG32:
#if (G31PL >= G32PL) || (G31PL == 0)
#define  MG32_11PL   ~(1)
#else
#define  MG32_11PL   0xFFFF
#endif
#if (G33PL >= G32PL) || (G33PL == 0)
#define  MG32_13PL   ~(1 << 2)
#else
#define  MG32_13PL   0xFFFF
#endif
#if (G34PL >= G32PL) || (G34PL == 0)
#define  MG32_14PL   ~(1 << 3)
#else
#define  MG32_14PL   0xFFFF
#endif
#if (G35PL >= G32PL) || (G35PL == 0)
#define  MG32_15PL   ~(1 << 4)
#else
#define  MG32_15PL   0xFFFF
#endif
#if (G36PL >= G32PL) || (G36PL == 0)
#define  MG32_16PL   ~(1 << 5)
#else
#define  MG32_16PL   0xFFFF
#endif
#if (G37PL >= G32PL) || (G37PL == 0)
#define  MG32_17PL   ~(1 << 6)
#else
#define  MG32_17PL   0xFFFF
#endif
#if (G38PL >= G32PL) || (G38PL == 0)
#define  MG32_18PL   ~(1 << 7)
#else
#define  MG32_18PL   0xFFFF
#endif
#define  MG32_12PL   0x00FD
#define  MG32    (MG32_11PL & MG32_12PL & MG32_13PL & MG32_14PL & \
                  MG32_15PL & MG32_16PL & MG32_17PL & MG32_18PL)
// End of MG32:

// Beginning of MG33:
#if (G31PL >= G33PL) || (G31PL == 0)
#define  MG33_11PL   ~(1)
#else
#define  MG33_11PL   0xFFFF
#endif
#if (G32PL >= G33PL) || (G32PL == 0)
#define  MG33_12PL   ~(1 << 1)
#else
#define  MG33_12PL   0xFFFF
#endif
#if (G34PL >= G33PL) || (G34PL == 0)
#define  MG33_14PL   ~(1 << 3)
#else
#define  MG33_14PL   0xFFFF
#endif
#if (G35PL >= G33PL) || (G35PL == 0)
#define  MG33_15PL   ~(1 << 4)
#else
#define  MG33_15PL   0xFFFF
#endif
#if (G36PL >= G33PL) || (G36PL == 0)
#define  MG33_16PL   ~(1 << 5)
#else
#define  MG33_16PL   0xFFFF
#endif
#if (G37PL >= G33PL) || (G37PL == 0)
#define  MG33_17PL   ~(1 << 6)
#else
#define  MG33_17PL   0xFFFF
#endif
#if (G38PL >= G33PL) || (G38PL == 0)
#define  MG33_18PL   ~(1 << 7)
#else
#define  MG33_18PL   0xFFFF
#endif
#define  MG33_13PL   0x00FB
#define  MG33    (MG33_11PL & MG33_12PL & MG33_13PL & MG33_14PL & \
                  MG33_15PL & MG33_16PL & MG33_17PL & MG33_18PL)
// End of MG33:

// Beginning of MG34:
#if (G31PL >= G34PL) || (G31PL == 0)
#define  MG34_11PL   ~(1)
#else
#define  MG34_11PL   0xFFFF
#endif
#if (G32PL >= G34PL) || (G32PL == 0)
#define  MG34_12PL   ~(1 << 1)
#else
#define  MG34_12PL   0xFFFF
#endif
#if (G33PL >= G34PL) || (G33PL == 0)
#define  MG34_13PL   ~(1 << 2)
#else
#define  MG34_13PL   0xFFFF
#endif
#if (G35PL >= G34PL) || (G35PL == 0)
#define  MG34_15PL   ~(1 << 4)
#else
#define  MG34_15PL   0xFFFF
#endif
#if (G36PL >= G34PL) || (G36PL == 0)
#define  MG34_16PL   ~(1 << 5)
#else
#define  MG34_16PL   0xFFFF
#endif
#if (G37PL >= G34PL) || (G37PL == 0)
#define  MG34_17PL   ~(1 << 6)
#else
#define  MG34_17PL   0xFFFF
#endif
#if (G38PL >= G34PL) || (G38PL == 0)
#define  MG34_18PL   ~(1 << 7)
#else
#define  MG34_18PL   0xFFFF
#endif
#define  MG34_14PL   0x00F7
#define  MG34    (MG34_11PL & MG34_12PL & MG34_13PL & MG34_14PL & \
                  MG34_15PL & MG34_16PL & MG34_17PL & MG34_18PL)
// End of MG34:

// Beginning of MG35:
#if (G31PL >= G35PL) || (G31PL == 0)
#define  MG35_11PL   ~(1)
#else
#define  MG35_11PL   0xFFFF
#endif
#if (G32PL >= G35PL) || (G32PL == 0)
#define  MG35_12PL   ~(1 << 1)
#else
#define  MG35_12PL   0xFFFF
#endif
#if (G33PL >= G35PL) || (G33PL == 0)
#define  MG35_13PL   ~(1 << 2)
#else
#define  MG35_13PL   0xFFFF
#endif
#if (G34PL >= G35PL) || (G34PL == 0)
#define  MG35_14PL   ~(1 << 3)
#else
#define  MG35_14PL   0xFFFF
#endif
#if (G36PL >= G35PL) || (G36PL == 0)
#define  MG35_16PL   ~(1 << 5)
#else
#define  MG35_16PL   0xFFFF
#endif
#if (G37PL >= G35PL) || (G37PL == 0)
#define  MG35_17PL   ~(1 << 6)
#else
#define  MG35_17PL   0xFFFF
#endif
#if (G38PL >= G35PL) || (G38PL == 0)
#define  MG35_18PL   ~(1 << 7)
#else
#define  MG35_18PL   0xFFFF
#endif
#define  MG35_15PL   0x00EF
#define  MG35    (MG35_11PL & MG35_12PL & MG35_13PL & MG35_14PL & \
                  MG35_15PL & MG35_16PL & MG35_17PL & MG35_18PL)
// End of MG35:

// Beginning of MG36:
#if (G31PL >= G36PL) || (G31PL == 0)
#define  MG36_11PL   ~(1)
#else
#define  MG36_11PL   0xFFFF
#endif
#if (G32PL >= G36PL) || (G32PL == 0)
#define  MG36_12PL   ~(1 << 1)
#else
#define  MG36_12PL   0xFFFF
#endif
#if (G33PL >= G36PL) || (G33PL == 0)
#define  MG36_13PL   ~(1 << 2)
#else
#define  MG36_13PL   0xFFFF
#endif
#if (G34PL >= G36PL) || (G34PL == 0)
#define  MG36_14PL   ~(1 << 3)
#else
#define  MG36_14PL   0xFFFF
#endif
#if (G35PL >= G36PL) || (G35PL == 0)
#define  MG36_15PL   ~(1 << 4)
#else
#define  MG36_15PL   0xFFFF
#endif
#if (G37PL >= G36PL) || (G37PL == 0)
#define  MG36_17PL   ~(1 << 6)
#else
#define  MG36_17PL   0xFFFF
#endif
#if (G38PL >= G36PL) || (G38PL == 0)
#define  MG36_18PL   ~(1 << 7)
#else
#define  MG36_18PL   0xFFFF
#endif
#define  MG36_16PL   0x00DF
#define  MG36    (MG36_11PL & MG36_12PL & MG36_13PL & MG36_14PL & \
                  MG36_15PL & MG36_16PL & MG36_17PL & MG36_18PL)
// End of MG36:

// Beginning of MG37:
#if (G31PL >= G37PL) || (G31PL == 0)
#define  MG37_11PL   ~(1)
#else
#define  MG37_11PL   0xFFFF
#endif
#if (G32PL >= G37PL) || (G32PL == 0)
#define  MG37_12PL   ~(1 << 1)
#else
#define  MG37_12PL   0xFFFF
#endif
#if (G33PL >= G37PL) || (G33PL == 0)
#define  MG37_13PL   ~(1 << 2)
#else
#define  MG37_13PL   0xFFFF
#endif
#if (G34PL >= G37PL) || (G34PL == 0)
#define  MG37_14PL   ~(1 << 3)
#else
#define  MG37_14PL   0xFFFF
#endif
#if (G35PL >= G37PL) || (G35PL == 0)
#define  MG37_15PL   ~(1 << 4)
#else
#define  MG37_15PL   0xFFFF
#endif
#if (G36PL >= G37PL) || (G36PL == 0)
#define  MG37_16PL   ~(1 << 5)
#else
#define  MG37_16PL   0xFFFF
#endif
#if (G38PL >= G37PL) || (G38PL == 0)
#define  MG37_18PL   ~(1 << 7)
#else
#define  MG37_18PL   0xFFFF
#endif
#define  MG37_17PL   0x00BF
#define  MG37    (MG37_11PL & MG37_12PL & MG37_13PL & MG37_14PL & \
                  MG37_15PL & MG37_16PL & MG37_17PL & MG37_18PL)
// End of MG37:

// Beginning of MG38:
#if (G31PL >= G38PL) || (G31PL == 0)
#define  MG38_11PL   ~(1)
#else
#define  MG38_11PL   0xFFFF
#endif
#if (G32PL >= G38PL) || (G32PL == 0)
#define  MG38_12PL   ~(1 << 1)
#else
#define  MG38_12PL   0xFFFF
#endif
#if (G33PL >= G38PL) || (G33PL == 0)
#define  MG38_13PL   ~(1 << 2)
#else
#define  MG38_13PL   0xFFFF
#endif
#if (G34PL >= G38PL) || (G34PL == 0)
#define  MG38_14PL   ~(1 << 3)
#else
#define  MG38_14PL   0xFFFF
#endif
#if (G35PL >= G38PL) || (G35PL == 0)
#define  MG38_15PL   ~(1 << 4)
#else
#define  MG38_15PL   0xFFFF
#endif
#if (G36PL >= G38PL) || (G36PL == 0)
#define  MG38_16PL   ~(1 << 5)
#else
#define  MG38_16PL   0xFFFF
#endif
#if (G37PL >= G38PL) || (G37PL == 0)
#define  MG38_17PL   ~(1 << 6)
#else
#define  MG38_17PL   0xFFFF
#endif
#define  MG38_18PL   0x007F
#define  MG38    (MG38_11PL & MG38_12PL & MG38_13PL & MG38_14PL & \
                  MG38_15PL & MG38_16PL & MG38_17PL & MG38_18PL)
// End of MG38:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG41 to MG48:
//

// Beginning of MG41:
#if (G42PL >= G41PL) || (G42PL == 0)
#define  MG41_12PL   ~(1 << 1)
#else
#define  MG41_12PL   0xFFFF
#endif
#if (G43PL >= G41PL) || (G43PL == 0)
#define  MG41_13PL   ~(1 << 2)
#else
#define  MG41_13PL   0xFFFF
#endif
#if (G44PL >= G41PL) || (G44PL == 0)
#define  MG41_14PL   ~(1 << 3)
#else
#define  MG41_14PL   0xFFFF
#endif
#if (G45PL >= G41PL) || (G45PL == 0)
#define  MG41_15PL   ~(1 << 4)
#else
#define  MG41_15PL   0xFFFF
#endif
#if (G46PL >= G41PL) || (G46PL == 0)
#define  MG41_16PL   ~(1 << 5)
#else
#define  MG41_16PL   0xFFFF
#endif
#if (G47PL >= G41PL) || (G47PL == 0)
#define  MG41_17PL   ~(1 << 6)
#else
#define  MG41_17PL   0xFFFF
#endif
#if (G48PL >= G41PL) || (G48PL == 0)
#define  MG41_18PL   ~(1 << 7)
#else
#define  MG41_18PL   0xFFFF
#endif
#define  MG41_11PL   0x00FE
#define  MG41    (MG41_11PL & MG41_12PL & MG41_13PL & MG41_14PL & \
                  MG41_15PL & MG41_16PL & MG41_17PL & MG41_18PL)
// End of MG41:

// Beginning of MG42:
#if (G41PL >= G42PL) || (G41PL == 0)
#define  MG42_11PL   ~(1)
#else
#define  MG42_11PL   0xFFFF
#endif
#if (G43PL >= G42PL) || (G43PL == 0)
#define  MG42_13PL   ~(1 << 2)
#else
#define  MG42_13PL   0xFFFF
#endif
#if (G44PL >= G42PL) || (G44PL == 0)
#define  MG42_14PL   ~(1 << 3)
#else
#define  MG42_14PL   0xFFFF
#endif
#if (G45PL >= G42PL) || (G45PL == 0)
#define  MG42_15PL   ~(1 << 4)
#else
#define  MG42_15PL   0xFFFF
#endif
#if (G46PL >= G42PL) || (G46PL == 0)
#define  MG42_16PL   ~(1 << 5)
#else
#define  MG42_16PL   0xFFFF
#endif
#if (G47PL >= G42PL) || (G47PL == 0)
#define  MG42_17PL   ~(1 << 6)
#else
#define  MG42_17PL   0xFFFF
#endif
#if (G48PL >= G42PL) || (G48PL == 0)
#define  MG42_18PL   ~(1 << 7)
#else
#define  MG42_18PL   0xFFFF
#endif
#define  MG42_12PL   0x00FD
#define  MG42    (MG42_11PL & MG42_12PL & MG42_13PL & MG42_14PL & \
                  MG42_15PL & MG42_16PL & MG42_17PL & MG42_18PL)
// End of MG42:

// Beginning of MG43:
#if (G41PL >= G43PL) || (G41PL == 0)
#define  MG43_11PL   ~(1)
#else
#define  MG43_11PL   0xFFFF
#endif
#if (G42PL >= G43PL) || (G42PL == 0)
#define  MG43_12PL   ~(1 << 1)
#else
#define  MG43_12PL   0xFFFF
#endif
#if (G44PL >= G43PL) || (G44PL == 0)
#define  MG43_14PL   ~(1 << 3)
#else
#define  MG43_14PL   0xFFFF
#endif
#if (G45PL >= G43PL) || (G45PL == 0)
#define  MG43_15PL   ~(1 << 4)
#else
#define  MG43_15PL   0xFFFF
#endif
#if (G46PL >= G43PL) || (G46PL == 0)
#define  MG43_16PL   ~(1 << 5)
#else
#define  MG43_16PL   0xFFFF
#endif
#if (G47PL >= G43PL) || (G47PL == 0)
#define  MG43_17PL   ~(1 << 6)
#else
#define  MG43_17PL   0xFFFF
#endif
#if (G48PL >= G43PL) || (G48PL == 0)
#define  MG43_18PL   ~(1 << 7)
#else
#define  MG43_18PL   0xFFFF
#endif
#define  MG43_13PL   0x00FB
#define  MG43    (MG43_11PL & MG43_12PL & MG43_13PL & MG43_14PL & \
                  MG43_15PL & MG43_16PL & MG43_17PL & MG43_18PL)
// End of MG43:

// Beginning of MG44:
#if (G41PL >= G44PL) || (G41PL == 0)
#define  MG44_11PL   ~(1)
#else
#define  MG44_11PL   0xFFFF
#endif
#if (G42PL >= G44PL) || (G42PL == 0)
#define  MG44_12PL   ~(1 << 1)
#else
#define  MG44_12PL   0xFFFF
#endif
#if (G43PL >= G44PL) || (G43PL == 0)
#define  MG44_13PL   ~(1 << 2)
#else
#define  MG44_13PL   0xFFFF
#endif
#if (G45PL >= G44PL) || (G45PL == 0)
#define  MG44_15PL   ~(1 << 4)
#else
#define  MG44_15PL   0xFFFF
#endif
#if (G46PL >= G44PL) || (G46PL == 0)
#define  MG44_16PL   ~(1 << 5)
#else
#define  MG44_16PL   0xFFFF
#endif
#if (G47PL >= G44PL) || (G47PL == 0)
#define  MG44_17PL   ~(1 << 6)
#else
#define  MG44_17PL   0xFFFF
#endif
#if (G48PL >= G44PL) || (G48PL == 0)
#define  MG44_18PL   ~(1 << 7)
#else
#define  MG44_18PL   0xFFFF
#endif
#define  MG44_14PL   0x00F7
#define  MG44    (MG44_11PL & MG44_12PL & MG44_13PL & MG44_14PL & \
                  MG44_15PL & MG44_16PL & MG44_17PL & MG44_18PL)
// End of MG44:

// Beginning of MG45:
#if (G41PL >= G45PL) || (G41PL == 0)
#define  MG45_11PL   ~(1)
#else
#define  MG45_11PL   0xFFFF
#endif
#if (G42PL >= G45PL) || (G42PL == 0)
#define  MG45_12PL   ~(1 << 1)
#else
#define  MG45_12PL   0xFFFF
#endif
#if (G43PL >= G45PL) || (G43PL == 0)
#define  MG45_13PL   ~(1 << 2)
#else
#define  MG45_13PL   0xFFFF
#endif
#if (G44PL >= G45PL) || (G44PL == 0)
#define  MG45_14PL   ~(1 << 3)
#else
#define  MG45_14PL   0xFFFF
#endif
#if (G46PL >= G45PL) || (G46PL == 0)
#define  MG45_16PL   ~(1 << 5)
#else
#define  MG45_16PL   0xFFFF
#endif
#if (G47PL >= G45PL) || (G47PL == 0)
#define  MG45_17PL   ~(1 << 6)
#else
#define  MG45_17PL   0xFFFF
#endif
#if (G48PL >= G45PL) || (G48PL == 0)
#define  MG45_18PL   ~(1 << 7)
#else
#define  MG45_18PL   0xFFFF
#endif
#define  MG45_15PL   0x00EF
#define  MG45    (MG45_11PL & MG45_12PL & MG45_13PL & MG45_14PL & \
                  MG45_15PL & MG45_16PL & MG45_17PL & MG45_18PL)
// End of MG45:

// Beginning of MG46:
#if (G41PL >= G46PL) || (G41PL == 0)
#define  MG46_11PL   ~(1)
#else
#define  MG46_11PL   0xFFFF
#endif
#if (G42PL >= G46PL) || (G42PL == 0)
#define  MG46_12PL   ~(1 << 1)
#else
#define  MG46_12PL   0xFFFF
#endif
#if (G43PL >= G46PL) || (G43PL == 0)
#define  MG46_13PL   ~(1 << 2)
#else
#define  MG46_13PL   0xFFFF
#endif
#if (G44PL >= G46PL) || (G44PL == 0)
#define  MG46_14PL   ~(1 << 3)
#else
#define  MG46_14PL   0xFFFF
#endif
#if (G45PL >= G46PL) || (G45PL == 0)
#define  MG46_15PL   ~(1 << 4)
#else
#define  MG46_15PL   0xFFFF
#endif
#if (G47PL >= G46PL) || (G47PL == 0)
#define  MG46_17PL   ~(1 << 6)
#else
#define  MG46_17PL   0xFFFF
#endif
#if (G48PL >= G46PL) || (G48PL == 0)
#define  MG46_18PL   ~(1 << 7)
#else
#define  MG46_18PL   0xFFFF
#endif
#define  MG46_16PL   0x00DF
#define  MG46    (MG46_11PL & MG46_12PL & MG46_13PL & MG46_14PL & \
                  MG46_15PL & MG46_16PL & MG46_17PL & MG46_18PL)
// End of MG46:

// Beginning of MG47:
#if (G41PL >= G47PL) || (G41PL == 0)
#define  MG47_11PL   ~(1)
#else
#define  MG47_11PL   0xFFFF
#endif
#if (G42PL >= G47PL) || (G42PL == 0)
#define  MG47_12PL   ~(1 << 1)
#else
#define  MG47_12PL   0xFFFF
#endif
#if (G43PL >= G47PL) || (G43PL == 0)
#define  MG47_13PL   ~(1 << 2)
#else
#define  MG47_13PL   0xFFFF
#endif
#if (G44PL >= G47PL) || (G44PL == 0)
#define  MG47_14PL   ~(1 << 3)
#else
#define  MG47_14PL   0xFFFF
#endif
#if (G45PL >= G47PL) || (G45PL == 0)
#define  MG47_15PL   ~(1 << 4)
#else
#define  MG47_15PL   0xFFFF
#endif
#if (G46PL >= G47PL) || (G46PL == 0)
#define  MG47_16PL   ~(1 << 5)
#else
#define  MG47_16PL   0xFFFF
#endif
#if (G48PL >= G47PL) || (G48PL == 0)
#define  MG47_18PL   ~(1 << 7)
#else
#define  MG47_18PL   0xFFFF
#endif
#define  MG47_17PL   0x00BF
#define  MG47    (MG47_11PL & MG47_12PL & MG47_13PL & MG47_14PL & \
                  MG47_15PL & MG47_16PL & MG47_17PL & MG47_18PL)
// End of MG47:

// Beginning of MG48:
#if (G41PL >= G48PL) || (G41PL == 0)
#define  MG48_11PL   ~(1)
#else
#define  MG48_11PL   0xFFFF
#endif
#if (G42PL >= G48PL) || (G42PL == 0)
#define  MG48_12PL   ~(1 << 1)
#else
#define  MG48_12PL   0xFFFF
#endif
#if (G43PL >= G48PL) || (G43PL == 0)
#define  MG48_13PL   ~(1 << 2)
#else
#define  MG48_13PL   0xFFFF
#endif
#if (G44PL >= G48PL) || (G44PL == 0)
#define  MG48_14PL   ~(1 << 3)
#else
#define  MG48_14PL   0xFFFF
#endif
#if (G45PL >= G48PL) || (G45PL == 0)
#define  MG48_15PL   ~(1 << 4)
#else
#define  MG48_15PL   0xFFFF
#endif
#if (G46PL >= G48PL) || (G46PL == 0)
#define  MG48_16PL   ~(1 << 5)
#else
#define  MG48_16PL   0xFFFF
#endif
#if (G47PL >= G48PL) || (G47PL == 0)
#define  MG48_17PL   ~(1 << 6)
#else
#define  MG48_17PL   0xFFFF
#endif
#define  MG48_18PL   0x007F
#define  MG48    (MG48_11PL & MG48_12PL & MG48_13PL & MG48_14PL & \
                  MG48_15PL & MG48_16PL & MG48_17PL & MG48_18PL)
// End of MG48:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG51 to MG58:
//

// Beginning of MG51:
#if (G52PL >= G51PL) || (G52PL == 0)
#define  MG51_12PL   ~(1 << 1)
#else
#define  MG51_12PL   0xFFFF
#endif
#if (G53PL >= G51PL) || (G53PL == 0)
#define  MG51_13PL   ~(1 << 2)
#else
#define  MG51_13PL   0xFFFF
#endif
#if (G54PL >= G51PL) || (G54PL == 0)
#define  MG51_14PL   ~(1 << 3)
#else
#define  MG51_14PL   0xFFFF
#endif
#if (G55PL >= G51PL) || (G55PL == 0)
#define  MG51_15PL   ~(1 << 4)
#else
#define  MG51_15PL   0xFFFF
#endif
#if (G56PL >= G51PL) || (G56PL == 0)
#define  MG51_16PL   ~(1 << 5)
#else
#define  MG51_16PL   0xFFFF
#endif
#if (G57PL >= G51PL) || (G57PL == 0)
#define  MG51_17PL   ~(1 << 6)
#else
#define  MG51_17PL   0xFFFF
#endif
#if (G58PL >= G51PL) || (G58PL == 0)
#define  MG51_18PL   ~(1 << 7)
#else
#define  MG51_18PL   0xFFFF
#endif
#define  MG51_11PL   0x00FE
#define  MG51    (MG51_11PL & MG51_12PL & MG51_13PL & MG51_14PL & \
                  MG51_15PL & MG51_16PL & MG51_17PL & MG51_18PL)
// End of MG51:

// Beginning of MG52:
#if (G51PL >= G52PL) || (G51PL == 0)
#define  MG52_11PL   ~(1)
#else
#define  MG52_11PL   0xFFFF
#endif
#if (G53PL >= G52PL) || (G53PL == 0)
#define  MG52_13PL   ~(1 << 2)
#else
#define  MG52_13PL   0xFFFF
#endif
#if (G54PL >= G52PL) || (G54PL == 0)
#define  MG52_14PL   ~(1 << 3)
#else
#define  MG52_14PL   0xFFFF
#endif
#if (G55PL >= G52PL) || (G55PL == 0)
#define  MG52_15PL   ~(1 << 4)
#else
#define  MG52_15PL   0xFFFF
#endif
#if (G56PL >= G52PL) || (G56PL == 0)
#define  MG52_16PL   ~(1 << 5)
#else
#define  MG52_16PL   0xFFFF
#endif
#if (G57PL >= G52PL) || (G57PL == 0)
#define  MG52_17PL   ~(1 << 6)
#else
#define  MG52_17PL   0xFFFF
#endif
#if (G58PL >= G52PL) || (G58PL == 0)
#define  MG52_18PL   ~(1 << 7)
#else
#define  MG52_18PL   0xFFFF
#endif
#define  MG52_12PL   0x00FD
#define  MG52    (MG52_11PL & MG52_12PL & MG52_13PL & MG52_14PL & \
                  MG52_15PL & MG52_16PL & MG52_17PL & MG52_18PL)
// End of MG52:

// Beginning of MG53:
#if (G51PL >= G53PL) || (G51PL == 0)
#define  MG53_11PL   ~(1)
#else
#define  MG53_11PL   0xFFFF
#endif
#if (G52PL >= G53PL) || (G52PL == 0)
#define  MG53_12PL   ~(1 << 1)
#else
#define  MG53_12PL   0xFFFF
#endif
#if (G54PL >= G53PL) || (G54PL == 0)
#define  MG53_14PL   ~(1 << 3)
#else
#define  MG53_14PL   0xFFFF
#endif
#if (G55PL >= G53PL) || (G55PL == 0)
#define  MG53_15PL   ~(1 << 4)
#else
#define  MG53_15PL   0xFFFF
#endif
#if (G56PL >= G53PL) || (G56PL == 0)
#define  MG53_16PL   ~(1 << 5)
#else
#define  MG53_16PL   0xFFFF
#endif
#if (G57PL >= G53PL) || (G57PL == 0)
#define  MG53_17PL   ~(1 << 6)
#else
#define  MG53_17PL   0xFFFF
#endif
#if (G58PL >= G53PL) || (G58PL == 0)
#define  MG53_18PL   ~(1 << 7)
#else
#define  MG53_18PL   0xFFFF
#endif
#define  MG53_13PL   0x00FB
#define  MG53    (MG53_11PL & MG53_12PL & MG53_13PL & MG53_14PL & \
                  MG53_15PL & MG53_16PL & MG53_17PL & MG53_18PL)
// End of MG53:

// Beginning of MG54:
#if (G51PL >= G54PL) || (G51PL == 0)
#define  MG54_11PL   ~(1)
#else
#define  MG54_11PL   0xFFFF
#endif
#if (G52PL >= G54PL) || (G52PL == 0)
#define  MG54_12PL   ~(1 << 1)
#else
#define  MG54_12PL   0xFFFF
#endif
#if (G53PL >= G54PL) || (G53PL == 0)
#define  MG54_13PL   ~(1 << 2)
#else
#define  MG54_13PL   0xFFFF
#endif
#if (G55PL >= G54PL) || (G55PL == 0)
#define  MG54_15PL   ~(1 << 4)
#else
#define  MG54_15PL   0xFFFF
#endif
#if (G56PL >= G54PL) || (G56PL == 0)
#define  MG54_16PL   ~(1 << 5)
#else
#define  MG54_16PL   0xFFFF
#endif
#if (G57PL >= G54PL) || (G57PL == 0)
#define  MG54_17PL   ~(1 << 6)
#else
#define  MG54_17PL   0xFFFF
#endif
#if (G58PL >= G54PL) || (G58PL == 0)
#define  MG54_18PL   ~(1 << 7)
#else
#define  MG54_18PL   0xFFFF
#endif
#define  MG54_14PL   0x00F7
#define  MG54    (MG54_11PL & MG54_12PL & MG54_13PL & MG54_14PL & \
                  MG54_15PL & MG54_16PL & MG54_17PL & MG54_18PL)
// End of MG54:

// Beginning of MG55:
#if (G51PL >= G55PL) || (G51PL == 0)
#define  MG55_11PL   ~(1)
#else
#define  MG55_11PL   0xFFFF
#endif
#if (G52PL >= G55PL) || (G52PL == 0)
#define  MG55_12PL   ~(1 << 1)
#else
#define  MG55_12PL   0xFFFF
#endif
#if (G53PL >= G55PL) || (G53PL == 0)
#define  MG55_13PL   ~(1 << 2)
#else
#define  MG55_13PL   0xFFFF
#endif
#if (G54PL >= G55PL) || (G54PL == 0)
#define  MG55_14PL   ~(1 << 3)
#else
#define  MG55_14PL   0xFFFF
#endif
#if (G56PL >= G55PL) || (G56PL == 0)
#define  MG55_16PL   ~(1 << 5)
#else
#define  MG55_16PL   0xFFFF
#endif
#if (G57PL >= G55PL) || (G57PL == 0)
#define  MG55_17PL   ~(1 << 6)
#else
#define  MG55_17PL   0xFFFF
#endif
#if (G58PL >= G55PL) || (G58PL == 0)
#define  MG55_18PL   ~(1 << 7)
#else
#define  MG55_18PL   0xFFFF
#endif
#define  MG55_15PL   0x00EF
#define  MG55    (MG55_11PL & MG55_12PL & MG55_13PL & MG55_14PL & \
                  MG55_15PL & MG55_16PL & MG55_17PL & MG55_18PL)
// End of MG55:

// Beginning of MG56:
#if (G51PL >= G56PL) || (G51PL == 0)
#define  MG56_11PL   ~(1)
#else
#define  MG56_11PL   0xFFFF
#endif
#if (G52PL >= G56PL) || (G52PL == 0)
#define  MG56_12PL   ~(1 << 1)
#else
#define  MG56_12PL   0xFFFF
#endif
#if (G53PL >= G56PL) || (G53PL == 0)
#define  MG56_13PL   ~(1 << 2)
#else
#define  MG56_13PL   0xFFFF
#endif
#if (G54PL >= G56PL) || (G54PL == 0)
#define  MG56_14PL   ~(1 << 3)
#else
#define  MG56_14PL   0xFFFF
#endif
#if (G55PL >= G56PL) || (G55PL == 0)
#define  MG56_15PL   ~(1 << 4)
#else
#define  MG56_15PL   0xFFFF
#endif
#if (G57PL >= G56PL) || (G57PL == 0)
#define  MG56_17PL   ~(1 << 6)
#else
#define  MG56_17PL   0xFFFF
#endif
#if (G58PL >= G56PL) || (G58PL == 0)
#define  MG56_18PL   ~(1 << 7)
#else
#define  MG56_18PL   0xFFFF
#endif
#define  MG56_16PL   0x00DF
#define  MG56    (MG56_11PL & MG56_12PL & MG56_13PL & MG56_14PL & \
                  MG56_15PL & MG56_16PL & MG56_17PL & MG56_18PL)
// End of MG56:

// Beginning of MG57:
#if (G51PL >= G57PL) || (G51PL == 0)
#define  MG57_11PL   ~(1)
#else
#define  MG57_11PL   0xFFFF
#endif
#if (G52PL >= G57PL) || (G52PL == 0)
#define  MG57_12PL   ~(1 << 1)
#else
#define  MG57_12PL   0xFFFF
#endif
#if (G53PL >= G57PL) || (G53PL == 0)
#define  MG57_13PL   ~(1 << 2)
#else
#define  MG57_13PL   0xFFFF
#endif
#if (G54PL >= G57PL) || (G54PL == 0)
#define  MG57_14PL   ~(1 << 3)
#else
#define  MG57_14PL   0xFFFF
#endif
#if (G55PL >= G57PL) || (G55PL == 0)
#define  MG57_15PL   ~(1 << 4)
#else
#define  MG57_15PL   0xFFFF
#endif
#if (G56PL >= G57PL) || (G56PL == 0)
#define  MG57_16PL   ~(1 << 5)
#else
#define  MG57_16PL   0xFFFF
#endif
#if (G58PL >= G57PL) || (G58PL == 0)
#define  MG57_18PL   ~(1 << 7)
#else
#define  MG57_18PL   0xFFFF
#endif
#define  MG57_17PL   0x00BF
#define  MG57    (MG57_11PL & MG57_12PL & MG57_13PL & MG57_14PL & \
                  MG57_15PL & MG57_16PL & MG57_17PL & MG57_18PL)
// End of MG57:

// Beginning of MG58:
#if (G51PL >= G58PL) || (G51PL == 0)
#define  MG58_11PL   ~(1)
#else
#define  MG58_11PL   0xFFFF
#endif
#if (G52PL >= G58PL) || (G52PL == 0)
#define  MG58_12PL   ~(1 << 1)
#else
#define  MG58_12PL   0xFFFF
#endif
#if (G53PL >= G58PL) || (G53PL == 0)
#define  MG58_13PL   ~(1 << 2)
#else
#define  MG58_13PL   0xFFFF
#endif
#if (G54PL >= G58PL) || (G54PL == 0)
#define  MG58_14PL   ~(1 << 3)
#else
#define  MG58_14PL   0xFFFF
#endif
#if (G55PL >= G58PL) || (G55PL == 0)
#define  MG58_15PL   ~(1 << 4)
#else
#define  MG58_15PL   0xFFFF
#endif
#if (G56PL >= G58PL) || (G56PL == 0)
#define  MG58_16PL   ~(1 << 5)
#else
#define  MG58_16PL   0xFFFF
#endif
#if (G57PL >= G58PL) || (G57PL == 0)
#define  MG58_17PL   ~(1 << 6)
#else
#define  MG58_17PL   0xFFFF
#endif
#define  MG58_18PL   0x007F
#define  MG58    (MG58_11PL & MG58_12PL & MG58_13PL & MG58_14PL & \
                  MG58_15PL & MG58_16PL & MG58_17PL & MG58_18PL)
// End of MG58:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG61 to MG68:
//

// Beginning of MG61:
#if (G62PL >= G61PL) || (G62PL == 0)
#define  MG61_12PL   ~(1 << 1)
#else
#define  MG61_12PL   0xFFFF
#endif
#if (G63PL >= G61PL) || (G63PL == 0)
#define  MG61_13PL   ~(1 << 2)
#else
#define  MG61_13PL   0xFFFF
#endif
#if (G64PL >= G61PL) || (G64PL == 0)
#define  MG61_14PL   ~(1 << 3)
#else
#define  MG61_14PL   0xFFFF
#endif
#if (G65PL >= G61PL) || (G65PL == 0)
#define  MG61_15PL   ~(1 << 4)
#else
#define  MG61_15PL   0xFFFF
#endif
#if (G66PL >= G61PL) || (G66PL == 0)
#define  MG61_16PL   ~(1 << 5)
#else
#define  MG61_16PL   0xFFFF
#endif
#if (G67PL >= G61PL) || (G67PL == 0)
#define  MG61_17PL   ~(1 << 6)
#else
#define  MG61_17PL   0xFFFF
#endif
#if (G68PL >= G61PL) || (G68PL == 0)
#define  MG61_18PL   ~(1 << 7)
#else
#define  MG61_18PL   0xFFFF
#endif
#define  MG61_11PL   0x00FE
#define  MG61    (MG61_11PL & MG61_12PL & MG61_13PL & MG61_14PL & \
                  MG61_15PL & MG61_16PL & MG61_17PL & MG61_18PL)
// End of MG61:

// Beginning of MG62:
#if (G61PL >= G62PL) || (G61PL == 0)
#define  MG62_11PL   ~(1)
#else
#define  MG62_11PL   0xFFFF
#endif
#if (G63PL >= G62PL) || (G63PL == 0)
#define  MG62_13PL   ~(1 << 2)
#else
#define  MG62_13PL   0xFFFF
#endif
#if (G64PL >= G62PL) || (G64PL == 0)
#define  MG62_14PL   ~(1 << 3)
#else
#define  MG62_14PL   0xFFFF
#endif
#if (G65PL >= G62PL) || (G65PL == 0)
#define  MG62_15PL   ~(1 << 4)
#else
#define  MG62_15PL   0xFFFF
#endif
#if (G66PL >= G62PL) || (G66PL == 0)
#define  MG62_16PL   ~(1 << 5)
#else
#define  MG62_16PL   0xFFFF
#endif
#if (G67PL >= G62PL) || (G67PL == 0)
#define  MG62_17PL   ~(1 << 6)
#else
#define  MG62_17PL   0xFFFF
#endif
#if (G68PL >= G62PL) || (G68PL == 0)
#define  MG62_18PL   ~(1 << 7)
#else
#define  MG62_18PL   0xFFFF
#endif
#define  MG62_12PL   0x00FD
#define  MG62    (MG62_11PL & MG62_12PL & MG62_13PL & MG62_14PL & \
                  MG62_15PL & MG62_16PL & MG62_17PL & MG62_18PL)
// End of MG62:

// Beginning of MG63:
#if (G61PL >= G63PL) || (G61PL == 0)
#define  MG63_11PL   ~(1)
#else
#define  MG63_11PL   0xFFFF
#endif
#if (G62PL >= G63PL) || (G62PL == 0)
#define  MG63_12PL   ~(1 << 1)
#else
#define  MG63_12PL   0xFFFF
#endif
#if (G64PL >= G63PL) || (G64PL == 0)
#define  MG63_14PL   ~(1 << 3)
#else
#define  MG63_14PL   0xFFFF
#endif
#if (G65PL >= G63PL) || (G65PL == 0)
#define  MG63_15PL   ~(1 << 4)
#else
#define  MG63_15PL   0xFFFF
#endif
#if (G66PL >= G63PL) || (G66PL == 0)
#define  MG63_16PL   ~(1 << 5)
#else
#define  MG63_16PL   0xFFFF
#endif
#if (G67PL >= G63PL) || (G67PL == 0)
#define  MG63_17PL   ~(1 << 6)
#else
#define  MG63_17PL   0xFFFF
#endif
#if (G68PL >= G63PL) || (G68PL == 0)
#define  MG63_18PL   ~(1 << 7)
#else
#define  MG63_18PL   0xFFFF
#endif
#define  MG63_13PL   0x00FB
#define  MG63    (MG63_11PL & MG63_12PL & MG63_13PL & MG63_14PL & \
                  MG63_15PL & MG63_16PL & MG63_17PL & MG63_18PL)
// End of MG63:

// Beginning of MG64:
#if (G61PL >= G64PL) || (G61PL == 0)
#define  MG64_11PL   ~(1)
#else
#define  MG64_11PL   0xFFFF
#endif
#if (G62PL >= G64PL) || (G62PL == 0)
#define  MG64_12PL   ~(1 << 1)
#else
#define  MG64_12PL   0xFFFF
#endif
#if (G63PL >= G64PL) || (G63PL == 0)
#define  MG64_13PL   ~(1 << 2)
#else
#define  MG64_13PL   0xFFFF
#endif
#if (G65PL >= G64PL) || (G65PL == 0)
#define  MG64_15PL   ~(1 << 4)
#else
#define  MG64_15PL   0xFFFF
#endif
#if (G66PL >= G64PL) || (G66PL == 0)
#define  MG64_16PL   ~(1 << 5)
#else
#define  MG64_16PL   0xFFFF
#endif
#if (G67PL >= G64PL) || (G67PL == 0)
#define  MG64_17PL   ~(1 << 6)
#else
#define  MG64_17PL   0xFFFF
#endif
#if (G68PL >= G64PL) || (G68PL == 0)
#define  MG64_18PL   ~(1 << 7)
#else
#define  MG64_18PL   0xFFFF
#endif
#define  MG64_14PL   0x00F7
#define  MG64    (MG64_11PL & MG64_12PL & MG64_13PL & MG64_14PL & \
                  MG64_15PL & MG64_16PL & MG64_17PL & MG64_18PL)
// End of MG64:

// Beginning of MG65:
#if (G61PL >= G65PL) || (G61PL == 0)
#define  MG65_11PL   ~(1)
#else
#define  MG65_11PL   0xFFFF
#endif
#if (G62PL >= G65PL) || (G62PL == 0)
#define  MG65_12PL   ~(1 << 1)
#else
#define  MG65_12PL   0xFFFF
#endif
#if (G63PL >= G65PL) || (G63PL == 0)
#define  MG65_13PL   ~(1 << 2)
#else
#define  MG65_13PL   0xFFFF
#endif
#if (G64PL >= G65PL) || (G64PL == 0)
#define  MG65_14PL   ~(1 << 3)
#else
#define  MG65_14PL   0xFFFF
#endif
#if (G66PL >= G65PL) || (G66PL == 0)
#define  MG65_16PL   ~(1 << 5)
#else
#define  MG65_16PL   0xFFFF
#endif
#if (G67PL >= G65PL) || (G67PL == 0)
#define  MG65_17PL   ~(1 << 6)
#else
#define  MG65_17PL   0xFFFF
#endif
#if (G68PL >= G65PL) || (G68PL == 0)
#define  MG65_18PL   ~(1 << 7)
#else
#define  MG65_18PL   0xFFFF
#endif
#define  MG65_15PL   0x00EF
#define  MG65    (MG65_11PL & MG65_12PL & MG65_13PL & MG65_14PL & \
                  MG65_15PL & MG65_16PL & MG65_17PL & MG65_18PL)
// End of MG65:

// Beginning of MG66:
#if (G61PL >= G66PL) || (G61PL == 0)
#define  MG66_11PL   ~(1)
#else
#define  MG66_11PL   0xFFFF
#endif
#if (G62PL >= G66PL) || (G62PL == 0)
#define  MG66_12PL   ~(1 << 1)
#else
#define  MG66_12PL   0xFFFF
#endif
#if (G63PL >= G66PL) || (G63PL == 0)
#define  MG66_13PL   ~(1 << 2)
#else
#define  MG66_13PL   0xFFFF
#endif
#if (G64PL >= G66PL) || (G64PL == 0)
#define  MG66_14PL   ~(1 << 3)
#else
#define  MG66_14PL   0xFFFF
#endif
#if (G65PL >= G66PL) || (G65PL == 0)
#define  MG66_15PL   ~(1 << 4)
#else
#define  MG66_15PL   0xFFFF
#endif
#if (G67PL >= G66PL) || (G67PL == 0)
#define  MG66_17PL   ~(1 << 6)
#else
#define  MG66_17PL   0xFFFF
#endif
#if (G68PL >= G66PL) || (G68PL == 0)
#define  MG66_18PL   ~(1 << 7)
#else
#define  MG66_18PL   0xFFFF
#endif
#define  MG66_16PL   0x00DF
#define  MG66    (MG66_11PL & MG66_12PL & MG66_13PL & MG66_14PL & \
                  MG66_15PL & MG66_16PL & MG66_17PL & MG66_18PL)
// End of MG66:

// Beginning of MG67:
#if (G61PL >= G67PL) || (G61PL == 0)
#define  MG67_11PL   ~(1)
#else
#define  MG67_11PL   0xFFFF
#endif
#if (G62PL >= G67PL) || (G62PL == 0)
#define  MG67_12PL   ~(1 << 1)
#else
#define  MG67_12PL   0xFFFF
#endif
#if (G63PL >= G67PL) || (G63PL == 0)
#define  MG67_13PL   ~(1 << 2)
#else
#define  MG67_13PL   0xFFFF
#endif
#if (G64PL >= G67PL) || (G64PL == 0)
#define  MG67_14PL   ~(1 << 3)
#else
#define  MG67_14PL   0xFFFF
#endif
#if (G65PL >= G67PL) || (G65PL == 0)
#define  MG67_15PL   ~(1 << 4)
#else
#define  MG67_15PL   0xFFFF
#endif
#if (G66PL >= G67PL) || (G66PL == 0)
#define  MG67_16PL   ~(1 << 5)
#else
#define  MG67_16PL   0xFFFF
#endif
#if (G68PL >= G67PL) || (G68PL == 0)
#define  MG67_18PL   ~(1 << 7)
#else
#define  MG67_18PL   0xFFFF
#endif
#define  MG67_17PL   0x00BF
#define  MG67    (MG67_11PL & MG67_12PL & MG67_13PL & MG67_14PL & \
                  MG67_15PL & MG67_16PL & MG67_17PL & MG67_18PL)
// End of MG67:

// Beginning of MG68:
#if (G61PL >= G68PL) || (G61PL == 0)
#define  MG68_11PL   ~(1)
#else
#define  MG68_11PL   0xFFFF
#endif
#if (G62PL >= G68PL) || (G62PL == 0)
#define  MG68_12PL   ~(1 << 1)
#else
#define  MG68_12PL   0xFFFF
#endif
#if (G63PL >= G68PL) || (G63PL == 0)
#define  MG68_13PL   ~(1 << 2)
#else
#define  MG68_13PL   0xFFFF
#endif
#if (G64PL >= G68PL) || (G64PL == 0)
#define  MG68_14PL   ~(1 << 3)
#else
#define  MG68_14PL   0xFFFF
#endif
#if (G65PL >= G68PL) || (G65PL == 0)
#define  MG68_15PL   ~(1 << 4)
#else
#define  MG68_15PL   0xFFFF
#endif
#if (G66PL >= G68PL) || (G66PL == 0)
#define  MG68_16PL   ~(1 << 5)
#else
#define  MG68_16PL   0xFFFF
#endif
#if (G67PL >= G68PL) || (G67PL == 0)
#define  MG68_17PL   ~(1 << 6)
#else
#define  MG68_17PL   0xFFFF
#endif
#define  MG68_18PL   0x007F
#define  MG68    (MG68_11PL & MG68_12PL & MG68_13PL & MG68_14PL & \
                  MG68_15PL & MG68_16PL & MG68_17PL & MG68_18PL)
// End of MG68:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG71 to MG78:
//

// Beginning of MG71:
#if (G72PL >= G71PL) || (G72PL == 0)
#define  MG71_12PL   ~(1 << 1)
#else
#define  MG71_12PL   0xFFFF
#endif
#if (G73PL >= G71PL) || (G73PL == 0)
#define  MG71_13PL   ~(1 << 2)
#else
#define  MG71_13PL   0xFFFF
#endif
#if (G74PL >= G71PL) || (G74PL == 0)
#define  MG71_14PL   ~(1 << 3)
#else
#define  MG71_14PL   0xFFFF
#endif
#if (G75PL >= G71PL) || (G75PL == 0)
#define  MG71_15PL   ~(1 << 4)
#else
#define  MG71_15PL   0xFFFF
#endif
#if (G76PL >= G71PL) || (G76PL == 0)
#define  MG71_16PL   ~(1 << 5)
#else
#define  MG71_16PL   0xFFFF
#endif
#if (G77PL >= G71PL) || (G77PL == 0)
#define  MG71_17PL   ~(1 << 6)
#else
#define  MG71_17PL   0xFFFF
#endif
#if (G78PL >= G71PL) || (G78PL == 0)
#define  MG71_18PL   ~(1 << 7)
#else
#define  MG71_18PL   0xFFFF
#endif
#define  MG71_11PL   0x00FE
#define  MG71    (MG71_11PL & MG71_12PL & MG71_13PL & MG71_14PL & \
                  MG71_15PL & MG71_16PL & MG71_17PL & MG71_18PL)
// End of MG71:

// Beginning of MG72:
#if (G71PL >= G72PL) || (G71PL == 0)
#define  MG72_11PL   ~(1)
#else
#define  MG72_11PL   0xFFFF
#endif
#if (G73PL >= G72PL) || (G73PL == 0)
#define  MG72_13PL   ~(1 << 2)
#else
#define  MG72_13PL   0xFFFF
#endif
#if (G74PL >= G72PL) || (G74PL == 0)
#define  MG72_14PL   ~(1 << 3)
#else
#define  MG72_14PL   0xFFFF
#endif
#if (G75PL >= G72PL) || (G75PL == 0)
#define  MG72_15PL   ~(1 << 4)
#else
#define  MG72_15PL   0xFFFF
#endif
#if (G76PL >= G72PL) || (G76PL == 0)
#define  MG72_16PL   ~(1 << 5)
#else
#define  MG72_16PL   0xFFFF
#endif
#if (G77PL >= G72PL) || (G77PL == 0)
#define  MG72_17PL   ~(1 << 6)
#else
#define  MG72_17PL   0xFFFF
#endif
#if (G78PL >= G72PL) || (G78PL == 0)
#define  MG72_18PL   ~(1 << 7)
#else
#define  MG72_18PL   0xFFFF
#endif
#define  MG72_12PL   0x00FD
#define  MG72    (MG72_11PL & MG72_12PL & MG72_13PL & MG72_14PL & \
                  MG72_15PL & MG72_16PL & MG72_17PL & MG72_18PL)
// End of MG72:

// Beginning of MG73:
#if (G71PL >= G73PL) || (G71PL == 0)
#define  MG73_11PL   ~(1)
#else
#define  MG73_11PL   0xFFFF
#endif
#if (G72PL >= G73PL) || (G72PL == 0)
#define  MG73_12PL   ~(1 << 1)
#else
#define  MG73_12PL   0xFFFF
#endif
#if (G74PL >= G73PL) || (G74PL == 0)
#define  MG73_14PL   ~(1 << 3)
#else
#define  MG73_14PL   0xFFFF
#endif
#if (G75PL >= G73PL) || (G75PL == 0)
#define  MG73_15PL   ~(1 << 4)
#else
#define  MG73_15PL   0xFFFF
#endif
#if (G76PL >= G73PL) || (G76PL == 0)
#define  MG73_16PL   ~(1 << 5)
#else
#define  MG73_16PL   0xFFFF
#endif
#if (G77PL >= G73PL) || (G77PL == 0)
#define  MG73_17PL   ~(1 << 6)
#else
#define  MG73_17PL   0xFFFF
#endif
#if (G78PL >= G73PL) || (G78PL == 0)
#define  MG73_18PL   ~(1 << 7)
#else
#define  MG73_18PL   0xFFFF
#endif
#define  MG73_13PL   0x00FB
#define  MG73    (MG73_11PL & MG73_12PL & MG73_13PL & MG73_14PL & \
                  MG73_15PL & MG73_16PL & MG73_17PL & MG73_18PL)
// End of MG73:

// Beginning of MG74:
#if (G71PL >= G74PL) || (G71PL == 0)
#define  MG74_11PL   ~(1)
#else
#define  MG74_11PL   0xFFFF
#endif
#if (G72PL >= G74PL) || (G72PL == 0)
#define  MG74_12PL   ~(1 << 1)
#else
#define  MG74_12PL   0xFFFF
#endif
#if (G73PL >= G74PL) || (G73PL == 0)
#define  MG74_13PL   ~(1 << 2)
#else
#define  MG74_13PL   0xFFFF
#endif
#if (G75PL >= G74PL) || (G75PL == 0)
#define  MG74_15PL   ~(1 << 4)
#else
#define  MG74_15PL   0xFFFF
#endif
#if (G76PL >= G74PL) || (G76PL == 0)
#define  MG74_16PL   ~(1 << 5)
#else
#define  MG74_16PL   0xFFFF
#endif
#if (G77PL >= G74PL) || (G77PL == 0)
#define  MG74_17PL   ~(1 << 6)
#else
#define  MG74_17PL   0xFFFF
#endif
#if (G78PL >= G74PL) || (G78PL == 0)
#define  MG74_18PL   ~(1 << 7)
#else
#define  MG74_18PL   0xFFFF
#endif
#define  MG74_14PL   0x00F7
#define  MG74    (MG74_11PL & MG74_12PL & MG74_13PL & MG74_14PL & \
                  MG74_15PL & MG74_16PL & MG74_17PL & MG74_18PL)
// End of MG74:

// Beginning of MG75:
#if (G71PL >= G75PL) || (G71PL == 0)
#define  MG75_11PL   ~(1)
#else
#define  MG75_11PL   0xFFFF
#endif
#if (G72PL >= G75PL) || (G72PL == 0)
#define  MG75_12PL   ~(1 << 1)
#else
#define  MG75_12PL   0xFFFF
#endif
#if (G73PL >= G75PL) || (G73PL == 0)
#define  MG75_13PL   ~(1 << 2)
#else
#define  MG75_13PL   0xFFFF
#endif
#if (G74PL >= G75PL) || (G74PL == 0)
#define  MG75_14PL   ~(1 << 3)
#else
#define  MG75_14PL   0xFFFF
#endif
#if (G76PL >= G75PL) || (G76PL == 0)
#define  MG75_16PL   ~(1 << 5)
#else
#define  MG75_16PL   0xFFFF
#endif
#if (G77PL >= G75PL) || (G77PL == 0)
#define  MG75_17PL   ~(1 << 6)
#else
#define  MG75_17PL   0xFFFF
#endif
#if (G78PL >= G75PL) || (G78PL == 0)
#define  MG75_18PL   ~(1 << 7)
#else
#define  MG75_18PL   0xFFFF
#endif
#define  MG75_15PL   0x00EF
#define  MG75    (MG75_11PL & MG75_12PL & MG75_13PL & MG75_14PL & \
                  MG75_15PL & MG75_16PL & MG75_17PL & MG75_18PL)
// End of MG75:

// Beginning of MG76:
#if (G71PL >= G76PL) || (G71PL == 0)
#define  MG76_11PL   ~(1)
#else
#define  MG76_11PL   0xFFFF
#endif
#if (G72PL >= G76PL) || (G72PL == 0)
#define  MG76_12PL   ~(1 << 1)
#else
#define  MG76_12PL   0xFFFF
#endif
#if (G73PL >= G76PL) || (G73PL == 0)
#define  MG76_13PL   ~(1 << 2)
#else
#define  MG76_13PL   0xFFFF
#endif
#if (G74PL >= G76PL) || (G74PL == 0)
#define  MG76_14PL   ~(1 << 3)
#else
#define  MG76_14PL   0xFFFF
#endif
#if (G75PL >= G76PL) || (G75PL == 0)
#define  MG76_15PL   ~(1 << 4)
#else
#define  MG76_15PL   0xFFFF
#endif
#if (G77PL >= G76PL) || (G77PL == 0)
#define  MG76_17PL   ~(1 << 6)
#else
#define  MG76_17PL   0xFFFF
#endif
#if (G78PL >= G76PL) || (G78PL == 0)
#define  MG76_18PL   ~(1 << 7)
#else
#define  MG76_18PL   0xFFFF
#endif
#define  MG76_16PL   0x00DF
#define  MG76    (MG76_11PL & MG76_12PL & MG76_13PL & MG76_14PL & \
                  MG76_15PL & MG76_16PL & MG76_17PL & MG76_18PL)
// End of MG76:

// Beginning of MG77:
#if (G71PL >= G77PL) || (G71PL == 0)
#define  MG77_11PL   ~(1)
#else
#define  MG77_11PL   0xFFFF
#endif
#if (G72PL >= G77PL) || (G72PL == 0)
#define  MG77_12PL   ~(1 << 1)
#else
#define  MG77_12PL   0xFFFF
#endif
#if (G73PL >= G77PL) || (G73PL == 0)
#define  MG77_13PL   ~(1 << 2)
#else
#define  MG77_13PL   0xFFFF
#endif
#if (G74PL >= G77PL) || (G74PL == 0)
#define  MG77_14PL   ~(1 << 3)
#else
#define  MG77_14PL   0xFFFF
#endif
#if (G75PL >= G77PL) || (G75PL == 0)
#define  MG77_15PL   ~(1 << 4)
#else
#define  MG77_15PL   0xFFFF
#endif
#if (G76PL >= G77PL) || (G76PL == 0)
#define  MG77_16PL   ~(1 << 5)
#else
#define  MG77_16PL   0xFFFF
#endif
#if (G78PL >= G77PL) || (G78PL == 0)
#define  MG77_18PL   ~(1 << 7)
#else
#define  MG77_18PL   0xFFFF
#endif
#define  MG77_17PL   0x00BF
#define  MG77    (MG77_11PL & MG77_12PL & MG77_13PL & MG77_14PL & \
                  MG77_15PL & MG77_16PL & MG77_17PL & MG77_18PL)
// End of MG77:

// Beginning of MG78:
#if (G71PL >= G78PL) || (G71PL == 0)
#define  MG78_11PL   ~(1)
#else
#define  MG78_11PL   0xFFFF
#endif
#if (G72PL >= G78PL) || (G72PL == 0)
#define  MG78_12PL   ~(1 << 1)
#else
#define  MG78_12PL   0xFFFF
#endif
#if (G73PL >= G78PL) || (G73PL == 0)
#define  MG78_13PL   ~(1 << 2)
#else
#define  MG78_13PL   0xFFFF
#endif
#if (G74PL >= G78PL) || (G74PL == 0)
#define  MG78_14PL   ~(1 << 3)
#else
#define  MG78_14PL   0xFFFF
#endif
#if (G75PL >= G78PL) || (G75PL == 0)
#define  MG78_15PL   ~(1 << 4)
#else
#define  MG78_15PL   0xFFFF
#endif
#if (G76PL >= G78PL) || (G76PL == 0)
#define  MG78_16PL   ~(1 << 5)
#else
#define  MG78_16PL   0xFFFF
#endif
#if (G77PL >= G78PL) || (G77PL == 0)
#define  MG78_17PL   ~(1 << 6)
#else
#define  MG78_17PL   0xFFFF
#endif
#define  MG78_18PL   0x007F
#define  MG78    (MG78_11PL & MG78_12PL & MG78_13PL & MG78_14PL & \
                  MG78_15PL & MG78_16PL & MG78_17PL & MG78_18PL)
// End of MG78:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG81 to MG88:
//

// Beginning of MG81:
#if (G82PL >= G81PL) || (G82PL == 0)
#define  MG81_12PL   ~(1 << 1)
#else
#define  MG81_12PL   0xFFFF
#endif
#if (G83PL >= G81PL) || (G83PL == 0)
#define  MG81_13PL   ~(1 << 2)
#else
#define  MG81_13PL   0xFFFF
#endif
#if (G84PL >= G81PL) || (G84PL == 0)
#define  MG81_14PL   ~(1 << 3)
#else
#define  MG81_14PL   0xFFFF
#endif
#if (G85PL >= G81PL) || (G85PL == 0)
#define  MG81_15PL   ~(1 << 4)
#else
#define  MG81_15PL   0xFFFF
#endif
#if (G86PL >= G81PL) || (G86PL == 0)
#define  MG81_16PL   ~(1 << 5)
#else
#define  MG81_16PL   0xFFFF
#endif
#if (G87PL >= G81PL) || (G87PL == 0)
#define  MG81_17PL   ~(1 << 6)
#else
#define  MG81_17PL   0xFFFF
#endif
#if (G88PL >= G81PL) || (G88PL == 0)
#define  MG81_18PL   ~(1 << 7)
#else
#define  MG81_18PL   0xFFFF
#endif
#define  MG81_11PL   0x00FE
#define  MG81    (MG81_11PL & MG81_12PL & MG81_13PL & MG81_14PL & \
                  MG81_15PL & MG81_16PL & MG81_17PL & MG81_18PL)
// End of MG81:

// Beginning of MG82:
#if (G81PL >= G82PL) || (G81PL == 0)
#define  MG82_11PL   ~(1)
#else
#define  MG82_11PL   0xFFFF
#endif
#if (G83PL >= G82PL) || (G83PL == 0)
#define  MG82_13PL   ~(1 << 2)
#else
#define  MG82_13PL   0xFFFF
#endif
#if (G84PL >= G82PL) || (G84PL == 0)
#define  MG82_14PL   ~(1 << 3)
#else
#define  MG82_14PL   0xFFFF
#endif
#if (G85PL >= G82PL) || (G85PL == 0)
#define  MG82_15PL   ~(1 << 4)
#else
#define  MG82_15PL   0xFFFF
#endif
#if (G86PL >= G82PL) || (G86PL == 0)
#define  MG82_16PL   ~(1 << 5)
#else
#define  MG82_16PL   0xFFFF
#endif
#if (G87PL >= G82PL) || (G87PL == 0)
#define  MG82_17PL   ~(1 << 6)
#else
#define  MG82_17PL   0xFFFF
#endif
#if (G88PL >= G82PL) || (G88PL == 0)
#define  MG82_18PL   ~(1 << 7)
#else
#define  MG82_18PL   0xFFFF
#endif
#define  MG82_12PL   0x00FD
#define  MG82    (MG82_11PL & MG82_12PL & MG82_13PL & MG82_14PL & \
                  MG82_15PL & MG82_16PL & MG82_17PL & MG82_18PL)
// End of MG82:

// Beginning of MG83:
#if (G81PL >= G83PL) || (G81PL == 0)
#define  MG83_11PL   ~(1)
#else
#define  MG83_11PL   0xFFFF
#endif
#if (G82PL >= G83PL) || (G82PL == 0)
#define  MG83_12PL   ~(1 << 1)
#else
#define  MG83_12PL   0xFFFF
#endif
#if (G84PL >= G83PL) || (G84PL == 0)
#define  MG83_14PL   ~(1 << 3)
#else
#define  MG83_14PL   0xFFFF
#endif
#if (G85PL >= G83PL) || (G85PL == 0)
#define  MG83_15PL   ~(1 << 4)
#else
#define  MG83_15PL   0xFFFF
#endif
#if (G86PL >= G83PL) || (G86PL == 0)
#define  MG83_16PL   ~(1 << 5)
#else
#define  MG83_16PL   0xFFFF
#endif
#if (G87PL >= G83PL) || (G87PL == 0)
#define  MG83_17PL   ~(1 << 6)
#else
#define  MG83_17PL   0xFFFF
#endif
#if (G88PL >= G83PL) || (G88PL == 0)
#define  MG83_18PL   ~(1 << 7)
#else
#define  MG83_18PL   0xFFFF
#endif
#define  MG83_13PL   0x00FB
#define  MG83    (MG83_11PL & MG83_12PL & MG83_13PL & MG83_14PL & \
                  MG83_15PL & MG83_16PL & MG83_17PL & MG83_18PL)
// End of MG83:

// Beginning of MG84:
#if (G81PL >= G84PL) || (G81PL == 0)
#define  MG84_11PL   ~(1)
#else
#define  MG84_11PL   0xFFFF
#endif
#if (G82PL >= G84PL) || (G82PL == 0)
#define  MG84_12PL   ~(1 << 1)
#else
#define  MG84_12PL   0xFFFF
#endif
#if (G83PL >= G84PL) || (G83PL == 0)
#define  MG84_13PL   ~(1 << 2)
#else
#define  MG84_13PL   0xFFFF
#endif
#if (G85PL >= G84PL) || (G85PL == 0)
#define  MG84_15PL   ~(1 << 4)
#else
#define  MG84_15PL   0xFFFF
#endif
#if (G86PL >= G84PL) || (G86PL == 0)
#define  MG84_16PL   ~(1 << 5)
#else
#define  MG84_16PL   0xFFFF
#endif
#if (G87PL >= G84PL) || (G87PL == 0)
#define  MG84_17PL   ~(1 << 6)
#else
#define  MG84_17PL   0xFFFF
#endif
#if (G88PL >= G84PL) || (G88PL == 0)
#define  MG84_18PL   ~(1 << 7)
#else
#define  MG84_18PL   0xFFFF
#endif
#define  MG84_14PL   0x00F7
#define  MG84    (MG84_11PL & MG84_12PL & MG84_13PL & MG84_14PL & \
                  MG84_15PL & MG84_16PL & MG84_17PL & MG84_18PL)
// End of MG84:

// Beginning of MG85:
#if (G81PL >= G85PL) || (G81PL == 0)
#define  MG85_11PL   ~(1)
#else
#define  MG85_11PL   0xFFFF
#endif
#if (G82PL >= G85PL) || (G82PL == 0)
#define  MG85_12PL   ~(1 << 1)
#else
#define  MG85_12PL   0xFFFF
#endif
#if (G83PL >= G85PL) || (G83PL == 0)
#define  MG85_13PL   ~(1 << 2)
#else
#define  MG85_13PL   0xFFFF
#endif
#if (G84PL >= G85PL) || (G84PL == 0)
#define  MG85_14PL   ~(1 << 3)
#else
#define  MG85_14PL   0xFFFF
#endif
#if (G86PL >= G85PL) || (G86PL == 0)
#define  MG85_16PL   ~(1 << 5)
#else
#define  MG85_16PL   0xFFFF
#endif
#if (G87PL >= G85PL) || (G87PL == 0)
#define  MG85_17PL   ~(1 << 6)
#else
#define  MG85_17PL   0xFFFF
#endif
#if (G88PL >= G85PL) || (G88PL == 0)
#define  MG85_18PL   ~(1 << 7)
#else
#define  MG85_18PL   0xFFFF
#endif
#define  MG85_15PL   0x00EF
#define  MG85    (MG85_11PL & MG85_12PL & MG85_13PL & MG85_14PL & \
                  MG85_15PL & MG85_16PL & MG85_17PL & MG85_18PL)
// End of MG85:

// Beginning of MG86:
#if (G81PL >= G86PL) || (G81PL == 0)
#define  MG86_11PL   ~(1)
#else
#define  MG86_11PL   0xFFFF
#endif
#if (G82PL >= G86PL) || (G82PL == 0)
#define  MG86_12PL   ~(1 << 1)
#else
#define  MG86_12PL   0xFFFF
#endif
#if (G83PL >= G86PL) || (G83PL == 0)
#define  MG86_13PL   ~(1 << 2)
#else
#define  MG86_13PL   0xFFFF
#endif
#if (G84PL >= G86PL) || (G84PL == 0)
#define  MG86_14PL   ~(1 << 3)
#else
#define  MG86_14PL   0xFFFF
#endif
#if (G85PL >= G86PL) || (G85PL == 0)
#define  MG86_15PL   ~(1 << 4)
#else
#define  MG86_15PL   0xFFFF
#endif
#if (G87PL >= G86PL) || (G87PL == 0)
#define  MG86_17PL   ~(1 << 6)
#else
#define  MG86_17PL   0xFFFF
#endif
#if (G88PL >= G86PL) || (G88PL == 0)
#define  MG86_18PL   ~(1 << 7)
#else
#define  MG86_18PL   0xFFFF
#endif
#define  MG86_16PL   0x00DF
#define  MG86    (MG86_11PL & MG86_12PL & MG86_13PL & MG86_14PL & \
                  MG86_15PL & MG86_16PL & MG86_17PL & MG86_18PL)
// End of MG86:

// Beginning of MG87:
#if (G81PL >= G87PL) || (G81PL == 0)
#define  MG87_11PL   ~(1)
#else
#define  MG87_11PL   0xFFFF
#endif
#if (G82PL >= G87PL) || (G82PL == 0)
#define  MG87_12PL   ~(1 << 1)
#else
#define  MG87_12PL   0xFFFF
#endif
#if (G83PL >= G87PL) || (G83PL == 0)
#define  MG87_13PL   ~(1 << 2)
#else
#define  MG87_13PL   0xFFFF
#endif
#if (G84PL >= G87PL) || (G84PL == 0)
#define  MG87_14PL   ~(1 << 3)
#else
#define  MG87_14PL   0xFFFF
#endif
#if (G85PL >= G87PL) || (G85PL == 0)
#define  MG87_15PL   ~(1 << 4)
#else
#define  MG87_15PL   0xFFFF
#endif
#if (G86PL >= G87PL) || (G86PL == 0)
#define  MG87_16PL   ~(1 << 5)
#else
#define  MG87_16PL   0xFFFF
#endif
#if (G88PL >= G87PL) || (G88PL == 0)
#define  MG87_18PL   ~(1 << 7)
#else
#define  MG87_18PL   0xFFFF
#endif
#define  MG87_17PL   0x00BF
#define  MG87    (MG87_11PL & MG87_12PL & MG87_13PL & MG87_14PL & \
                  MG87_15PL & MG87_16PL & MG87_17PL & MG87_18PL)
// End of MG87:

// Beginning of MG88:
#if (G81PL >= G88PL) || (G81PL == 0)
#define  MG88_11PL   ~(1)
#else
#define  MG88_11PL   0xFFFF
#endif
#if (G82PL >= G88PL) || (G82PL == 0)
#define  MG88_12PL   ~(1 << 1)
#else
#define  MG88_12PL   0xFFFF
#endif
#if (G83PL >= G88PL) || (G83PL == 0)
#define  MG88_13PL   ~(1 << 2)
#else
#define  MG88_13PL   0xFFFF
#endif
#if (G84PL >= G88PL) || (G84PL == 0)
#define  MG88_14PL   ~(1 << 3)
#else
#define  MG88_14PL   0xFFFF
#endif
#if (G85PL >= G88PL) || (G85PL == 0)
#define  MG88_15PL   ~(1 << 4)
#else
#define  MG88_15PL   0xFFFF
#endif
#if (G86PL >= G88PL) || (G86PL == 0)
#define  MG88_16PL   ~(1 << 5)
#else
#define  MG88_16PL   0xFFFF
#endif
#if (G87PL >= G88PL) || (G87PL == 0)
#define  MG88_17PL   ~(1 << 6)
#else
#define  MG88_17PL   0xFFFF
#endif
#define  MG88_18PL   0x007F
#define  MG88    (MG88_11PL & MG88_12PL & MG88_13PL & MG88_14PL & \
                  MG88_15PL & MG88_16PL & MG88_17PL & MG88_18PL)
// End of MG88:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG91 to MG98:
//

// Beginning of MG91:
#if (G92PL >= G91PL) || (G92PL == 0)
#define  MG91_12PL   ~(1 << 1)
#else
#define  MG91_12PL   0xFFFF
#endif
#if (G93PL >= G91PL) || (G93PL == 0)
#define  MG91_13PL   ~(1 << 2)
#else
#define  MG91_13PL   0xFFFF
#endif
#if (G94PL >= G91PL) || (G94PL == 0)
#define  MG91_14PL   ~(1 << 3)
#else
#define  MG91_14PL   0xFFFF
#endif
#if (G95PL >= G91PL) || (G95PL == 0)
#define  MG91_15PL   ~(1 << 4)
#else
#define  MG91_15PL   0xFFFF
#endif
#if (G96PL >= G91PL) || (G96PL == 0)
#define  MG91_16PL   ~(1 << 5)
#else
#define  MG91_16PL   0xFFFF
#endif
#if (G97PL >= G91PL) || (G97PL == 0)
#define  MG91_17PL   ~(1 << 6)
#else
#define  MG91_17PL   0xFFFF
#endif
#if (G98PL >= G91PL) || (G98PL == 0)
#define  MG91_18PL   ~(1 << 7)
#else
#define  MG91_18PL   0xFFFF
#endif
#define  MG91_11PL   0x00FE
#define  MG91    (MG91_11PL & MG91_12PL & MG91_13PL & MG91_14PL & \
                  MG91_15PL & MG91_16PL & MG91_17PL & MG91_18PL)
// End of MG91:

// Beginning of MG92:
#if (G91PL >= G92PL) || (G91PL == 0)
#define  MG92_11PL   ~(1)
#else
#define  MG92_11PL   0xFFFF
#endif
#if (G93PL >= G92PL) || (G93PL == 0)
#define  MG92_13PL   ~(1 << 2)
#else
#define  MG92_13PL   0xFFFF
#endif
#if (G94PL >= G92PL) || (G94PL == 0)
#define  MG92_14PL   ~(1 << 3)
#else
#define  MG92_14PL   0xFFFF
#endif
#if (G95PL >= G92PL) || (G95PL == 0)
#define  MG92_15PL   ~(1 << 4)
#else
#define  MG92_15PL   0xFFFF
#endif
#if (G96PL >= G92PL) || (G96PL == 0)
#define  MG92_16PL   ~(1 << 5)
#else
#define  MG92_16PL   0xFFFF
#endif
#if (G97PL >= G92PL) || (G97PL == 0)
#define  MG92_17PL   ~(1 << 6)
#else
#define  MG92_17PL   0xFFFF
#endif
#if (G98PL >= G92PL) || (G98PL == 0)
#define  MG92_18PL   ~(1 << 7)
#else
#define  MG92_18PL   0xFFFF
#endif
#define  MG92_12PL   0x00FD
#define  MG92    (MG92_11PL & MG92_12PL & MG92_13PL & MG92_14PL & \
                  MG92_15PL & MG92_16PL & MG92_17PL & MG92_18PL)
// End of MG92:

// Beginning of MG93:
#if (G91PL >= G93PL) || (G91PL == 0)
#define  MG93_11PL   ~(1)
#else
#define  MG93_11PL   0xFFFF
#endif
#if (G92PL >= G93PL) || (G92PL == 0)
#define  MG93_12PL   ~(1 << 1)
#else
#define  MG93_12PL   0xFFFF
#endif
#if (G94PL >= G93PL) || (G94PL == 0)
#define  MG93_14PL   ~(1 << 3)
#else
#define  MG93_14PL   0xFFFF
#endif
#if (G95PL >= G93PL) || (G95PL == 0)
#define  MG93_15PL   ~(1 << 4)
#else
#define  MG93_15PL   0xFFFF
#endif
#if (G96PL >= G93PL) || (G96PL == 0)
#define  MG93_16PL   ~(1 << 5)
#else
#define  MG93_16PL   0xFFFF
#endif
#if (G97PL >= G93PL) || (G97PL == 0)
#define  MG93_17PL   ~(1 << 6)
#else
#define  MG93_17PL   0xFFFF
#endif
#if (G98PL >= G93PL) || (G98PL == 0)
#define  MG93_18PL   ~(1 << 7)
#else
#define  MG93_18PL   0xFFFF
#endif
#define  MG93_13PL   0x00FB
#define  MG93    (MG93_11PL & MG93_12PL & MG93_13PL & MG93_14PL & \
                  MG93_15PL & MG93_16PL & MG93_17PL & MG93_18PL)
// End of MG93:

// Beginning of MG94:
#if (G91PL >= G94PL) || (G91PL == 0)
#define  MG94_11PL   ~(1)
#else
#define  MG94_11PL   0xFFFF
#endif
#if (G92PL >= G94PL) || (G92PL == 0)
#define  MG94_12PL   ~(1 << 1)
#else
#define  MG94_12PL   0xFFFF
#endif
#if (G93PL >= G94PL) || (G93PL == 0)
#define  MG94_13PL   ~(1 << 2)
#else
#define  MG94_13PL   0xFFFF
#endif
#if (G95PL >= G94PL) || (G95PL == 0)
#define  MG94_15PL   ~(1 << 4)
#else
#define  MG94_15PL   0xFFFF
#endif
#if (G96PL >= G94PL) || (G96PL == 0)
#define  MG94_16PL   ~(1 << 5)
#else
#define  MG94_16PL   0xFFFF
#endif
#if (G97PL >= G94PL) || (G97PL == 0)
#define  MG94_17PL   ~(1 << 6)
#else
#define  MG94_17PL   0xFFFF
#endif
#if (G98PL >= G94PL) || (G98PL == 0)
#define  MG94_18PL   ~(1 << 7)
#else
#define  MG94_18PL   0xFFFF
#endif
#define  MG94_14PL   0x00F7
#define  MG94    (MG94_11PL & MG94_12PL & MG94_13PL & MG94_14PL & \
                  MG94_15PL & MG94_16PL & MG94_17PL & MG94_18PL)
// End of MG94:

// Beginning of MG95:
#if (G91PL >= G95PL) || (G91PL == 0)
#define  MG95_11PL   ~(1)
#else
#define  MG95_11PL   0xFFFF
#endif
#if (G92PL >= G95PL) || (G92PL == 0)
#define  MG95_12PL   ~(1 << 1)
#else
#define  MG95_12PL   0xFFFF
#endif
#if (G93PL >= G95PL) || (G93PL == 0)
#define  MG95_13PL   ~(1 << 2)
#else
#define  MG95_13PL   0xFFFF
#endif
#if (G94PL >= G95PL) || (G94PL == 0)
#define  MG95_14PL   ~(1 << 3)
#else
#define  MG95_14PL   0xFFFF
#endif
#if (G96PL >= G95PL) || (G96PL == 0)
#define  MG95_16PL   ~(1 << 5)
#else
#define  MG95_16PL   0xFFFF
#endif
#if (G97PL >= G95PL) || (G97PL == 0)
#define  MG95_17PL   ~(1 << 6)
#else
#define  MG95_17PL   0xFFFF
#endif
#if (G98PL >= G95PL) || (G98PL == 0)
#define  MG95_18PL   ~(1 << 7)
#else
#define  MG95_18PL   0xFFFF
#endif
#define  MG95_15PL   0x00EF
#define  MG95    (MG95_11PL & MG95_12PL & MG95_13PL & MG95_14PL & \
                  MG95_15PL & MG95_16PL & MG95_17PL & MG95_18PL)
// End of MG95:

// Beginning of MG96:
#if (G91PL >= G96PL) || (G91PL == 0)
#define  MG96_11PL   ~(1)
#else
#define  MG96_11PL   0xFFFF
#endif
#if (G92PL >= G96PL) || (G92PL == 0)
#define  MG96_12PL   ~(1 << 1)
#else
#define  MG96_12PL   0xFFFF
#endif
#if (G93PL >= G96PL) || (G93PL == 0)
#define  MG96_13PL   ~(1 << 2)
#else
#define  MG96_13PL   0xFFFF
#endif
#if (G94PL >= G96PL) || (G94PL == 0)
#define  MG96_14PL   ~(1 << 3)
#else
#define  MG96_14PL   0xFFFF
#endif
#if (G95PL >= G96PL) || (G95PL == 0)
#define  MG96_15PL   ~(1 << 4)
#else
#define  MG96_15PL   0xFFFF
#endif
#if (G97PL >= G96PL) || (G97PL == 0)
#define  MG96_17PL   ~(1 << 6)
#else
#define  MG96_17PL   0xFFFF
#endif
#if (G98PL >= G96PL) || (G98PL == 0)
#define  MG96_18PL   ~(1 << 7)
#else
#define  MG96_18PL   0xFFFF
#endif
#define  MG96_16PL   0x00DF
#define  MG96    (MG96_11PL & MG96_12PL & MG96_13PL & MG96_14PL & \
                  MG96_15PL & MG96_16PL & MG96_17PL & MG96_18PL)
// End of MG96:

// Beginning of MG97:
#if (G91PL >= G97PL) || (G91PL == 0)
#define  MG97_11PL   ~(1)
#else
#define  MG97_11PL   0xFFFF
#endif
#if (G92PL >= G97PL) || (G92PL == 0)
#define  MG97_12PL   ~(1 << 1)
#else
#define  MG97_12PL   0xFFFF
#endif
#if (G93PL >= G97PL) || (G93PL == 0)
#define  MG97_13PL   ~(1 << 2)
#else
#define  MG97_13PL   0xFFFF
#endif
#if (G94PL >= G97PL) || (G94PL == 0)
#define  MG97_14PL   ~(1 << 3)
#else
#define  MG97_14PL   0xFFFF
#endif
#if (G95PL >= G97PL) || (G95PL == 0)
#define  MG97_15PL   ~(1 << 4)
#else
#define  MG97_15PL   0xFFFF
#endif
#if (G96PL >= G97PL) || (G96PL == 0)
#define  MG97_16PL   ~(1 << 5)
#else
#define  MG97_16PL   0xFFFF
#endif
#if (G98PL >= G97PL) || (G98PL == 0)
#define  MG97_18PL   ~(1 << 7)
#else
#define  MG97_18PL   0xFFFF
#endif
#define  MG97_17PL   0x00BF
#define  MG97    (MG97_11PL & MG97_12PL & MG97_13PL & MG97_14PL & \
                  MG97_15PL & MG97_16PL & MG97_17PL & MG97_18PL)
// End of MG97:

// Beginning of MG98:
#if (G91PL >= G98PL) || (G91PL == 0)
#define  MG98_11PL   ~(1)
#else
#define  MG98_11PL   0xFFFF
#endif
#if (G92PL >= G98PL) || (G92PL == 0)
#define  MG98_12PL   ~(1 << 1)
#else
#define  MG98_12PL   0xFFFF
#endif
#if (G93PL >= G98PL) || (G93PL == 0)
#define  MG98_13PL   ~(1 << 2)
#else
#define  MG98_13PL   0xFFFF
#endif
#if (G94PL >= G98PL) || (G94PL == 0)
#define  MG98_14PL   ~(1 << 3)
#else
#define  MG98_14PL   0xFFFF
#endif
#if (G95PL >= G98PL) || (G95PL == 0)
#define  MG98_15PL   ~(1 << 4)
#else
#define  MG98_15PL   0xFFFF
#endif
#if (G96PL >= G98PL) || (G96PL == 0)
#define  MG98_16PL   ~(1 << 5)
#else
#define  MG98_16PL   0xFFFF
#endif
#if (G97PL >= G98PL) || (G97PL == 0)
#define  MG98_17PL   ~(1 << 6)
#else
#define  MG98_17PL   0xFFFF
#endif
#define  MG98_18PL   0x007F
#define  MG98    (MG98_11PL & MG98_12PL & MG98_13PL & MG98_14PL & \
                  MG98_15PL & MG98_16PL & MG98_17PL & MG98_18PL)
// End of MG98:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG101 to MG108:
//

// Beginning of MG101:
#if (G102PL >= G101PL) || (G102PL == 0)
#define  MG101_12PL   ~(1 << 1)
#else
#define  MG101_12PL   0xFFFF
#endif
#if (G103PL >= G101PL) || (G103PL == 0)
#define  MG101_13PL   ~(1 << 2)
#else
#define  MG101_13PL   0xFFFF
#endif
#if (G104PL >= G101PL) || (G104PL == 0)
#define  MG101_14PL   ~(1 << 3)
#else
#define  MG101_14PL   0xFFFF
#endif
#if (G105PL >= G101PL) || (G105PL == 0)
#define  MG101_15PL   ~(1 << 4)
#else
#define  MG101_15PL   0xFFFF
#endif
#if (G106PL >= G101PL) || (G106PL == 0)
#define  MG101_16PL   ~(1 << 5)
#else
#define  MG101_16PL   0xFFFF
#endif
#if (G107PL >= G101PL) || (G107PL == 0)
#define  MG101_17PL   ~(1 << 6)
#else
#define  MG101_17PL   0xFFFF
#endif
#if (G108PL >= G101PL) || (G108PL == 0)
#define  MG101_18PL   ~(1 << 7)
#else
#define  MG101_18PL   0xFFFF
#endif
#define  MG101_11PL   0x00FE
#define  MG101   (MG101_11PL & MG101_12PL & MG101_13PL & MG101_14PL & \
                  MG101_15PL & MG101_16PL & MG101_17PL & MG101_18PL)
// End of MG101:

// Beginning of MG102:
#if (G101PL >= G102PL) || (G101PL == 0)
#define  MG102_11PL   ~(1)
#else
#define  MG102_11PL   0xFFFF
#endif
#if (G103PL >= G102PL) || (G103PL == 0)
#define  MG102_13PL   ~(1 << 2)
#else
#define  MG102_13PL   0xFFFF
#endif
#if (G104PL >= G102PL) || (G104PL == 0)
#define  MG102_14PL   ~(1 << 3)
#else
#define  MG102_14PL   0xFFFF
#endif
#if (G105PL >= G102PL) || (G105PL == 0)
#define  MG102_15PL   ~(1 << 4)
#else
#define  MG102_15PL   0xFFFF
#endif
#if (G106PL >= G102PL) || (G106PL == 0)
#define  MG102_16PL   ~(1 << 5)
#else
#define  MG102_16PL   0xFFFF
#endif
#if (G107PL >= G102PL) || (G107PL == 0)
#define  MG102_17PL   ~(1 << 6)
#else
#define  MG102_17PL   0xFFFF
#endif
#if (G108PL >= G102PL) || (G108PL == 0)
#define  MG102_18PL   ~(1 << 7)
#else
#define  MG102_18PL   0xFFFF
#endif
#define  MG102_12PL   0x00FD
#define  MG102   (MG102_11PL & MG102_12PL & MG102_13PL & MG102_14PL & \
                  MG102_15PL & MG102_16PL & MG102_17PL & MG102_18PL)
// End of MG102:

// Beginning of MG103:
#if (G101PL >= G103PL) || (G101PL == 0)
#define  MG103_11PL   ~(1)
#else
#define  MG103_11PL   0xFFFF
#endif
#if (G102PL >= G103PL) || (G102PL == 0)
#define  MG103_12PL   ~(1 << 1)
#else
#define  MG103_12PL   0xFFFF
#endif
#if (G104PL >= G103PL) || (G104PL == 0)
#define  MG103_14PL   ~(1 << 3)
#else
#define  MG103_14PL   0xFFFF
#endif
#if (G105PL >= G103PL) || (G105PL == 0)
#define  MG103_15PL   ~(1 << 4)
#else
#define  MG103_15PL   0xFFFF
#endif
#if (G106PL >= G103PL) || (G106PL == 0)
#define  MG103_16PL   ~(1 << 5)
#else
#define  MG103_16PL   0xFFFF
#endif
#if (G107PL >= G103PL) || (G107PL == 0)
#define  MG103_17PL   ~(1 << 6)
#else
#define  MG103_17PL   0xFFFF
#endif
#if (G108PL >= G103PL) || (G108PL == 0)
#define  MG103_18PL   ~(1 << 7)
#else
#define  MG103_18PL   0xFFFF
#endif
#define  MG103_13PL   0x00FB
#define  MG103    (MG103_11PL & MG103_12PL & MG103_13PL & MG103_14PL & \
                  MG103_15PL & MG103_16PL & MG103_17PL & MG103_18PL)
// End of MG103:

// Beginning of MG104:
#if (G101PL >= G104PL) || (G101PL == 0)
#define  MG104_11PL   ~(1)
#else
#define  MG104_11PL   0xFFFF
#endif
#if (G102PL >= G104PL) || (G102PL == 0)
#define  MG104_12PL   ~(1 << 1)
#else
#define  MG104_12PL   0xFFFF
#endif
#if (G103PL >= G104PL) || (G103PL == 0)
#define  MG104_13PL   ~(1 << 2)
#else
#define  MG104_13PL   0xFFFF
#endif
#if (G105PL >= G104PL) || (G105PL == 0)
#define  MG104_15PL   ~(1 << 4)
#else
#define  MG104_15PL   0xFFFF
#endif
#if (G106PL >= G104PL) || (G106PL == 0)
#define  MG104_16PL   ~(1 << 5)
#else
#define  MG104_16PL   0xFFFF
#endif
#if (G107PL >= G104PL) || (G107PL == 0)
#define  MG104_17PL   ~(1 << 6)
#else
#define  MG104_17PL   0xFFFF
#endif
#if (G108PL >= G104PL) || (G108PL == 0)
#define  MG104_18PL   ~(1 << 7)
#else
#define  MG104_18PL   0xFFFF
#endif
#define  MG104_14PL   0x00F7
#define  MG104   (MG104_11PL & MG104_12PL & MG104_13PL & MG104_14PL & \
                  MG104_15PL & MG104_16PL & MG104_17PL & MG104_18PL)
// End of MG104:

// Beginning of MG105:
#if (G101PL >= G105PL) || (G101PL == 0)
#define  MG105_11PL   ~(1)
#else
#define  MG105_11PL   0xFFFF
#endif
#if (G102PL >= G105PL) || (G102PL == 0)
#define  MG105_12PL   ~(1 << 1)
#else
#define  MG105_12PL   0xFFFF
#endif
#if (G103PL >= G105PL) || (G103PL == 0)
#define  MG105_13PL   ~(1 << 2)
#else
#define  MG105_13PL   0xFFFF
#endif
#if (G104PL >= G105PL) || (G104PL == 0)
#define  MG105_14PL   ~(1 << 3)
#else
#define  MG105_14PL   0xFFFF
#endif
#if (G106PL >= G105PL) || (G106PL == 0)
#define  MG105_16PL   ~(1 << 5)
#else
#define  MG105_16PL   0xFFFF
#endif
#if (G107PL >= G105PL) || (G107PL == 0)
#define  MG105_17PL   ~(1 << 6)
#else
#define  MG105_17PL   0xFFFF
#endif
#if (G108PL >= G105PL) || (G108PL == 0)
#define  MG105_18PL   ~(1 << 7)
#else
#define  MG105_18PL   0xFFFF
#endif
#define  MG105_15PL   0x00EF
#define  MG105   (MG105_11PL & MG105_12PL & MG105_13PL & MG105_14PL & \
                  MG105_15PL & MG105_16PL & MG105_17PL & MG105_18PL)
// End of MG105:

// Beginning of MG106:
#if (G101PL >= G106PL) || (G101PL == 0)
#define  MG106_11PL   ~(1)
#else
#define  MG106_11PL   0xFFFF
#endif
#if (G102PL >= G106PL) || (G102PL == 0)
#define  MG106_12PL   ~(1 << 1)
#else
#define  MG106_12PL   0xFFFF
#endif
#if (G103PL >= G106PL) || (G103PL == 0)
#define  MG106_13PL   ~(1 << 2)
#else
#define  MG106_13PL   0xFFFF
#endif
#if (G104PL >= G106PL) || (G104PL == 0)
#define  MG106_14PL   ~(1 << 3)
#else
#define  MG106_14PL   0xFFFF
#endif
#if (G105PL >= G106PL) || (G105PL == 0)
#define  MG106_15PL   ~(1 << 4)
#else
#define  MG106_15PL   0xFFFF
#endif
#if (G107PL >= G106PL) || (G107PL == 0)
#define  MG106_17PL   ~(1 << 6)
#else
#define  MG106_17PL   0xFFFF
#endif
#if (G108PL >= G106PL) || (G108PL == 0)
#define  MG106_18PL   ~(1 << 7)
#else
#define  MG106_18PL   0xFFFF
#endif
#define  MG106_16PL   0x00DF
#define  MG106   (MG106_11PL & MG106_12PL & MG106_13PL & MG106_14PL & \
                  MG106_15PL & MG106_16PL & MG106_17PL & MG106_18PL)
// End of MG106:

// Beginning of MG107:
#if (G101PL >= G107PL) || (G101PL == 0)
#define  MG107_11PL   ~(1)
#else
#define  MG107_11PL   0xFFFF
#endif
#if (G102PL >= G107PL) || (G102PL == 0)
#define  MG107_12PL   ~(1 << 1)
#else
#define  MG107_12PL   0xFFFF
#endif
#if (G103PL >= G107PL) || (G103PL == 0)
#define  MG107_13PL   ~(1 << 2)
#else
#define  MG107_13PL   0xFFFF
#endif
#if (G104PL >= G107PL) || (G104PL == 0)
#define  MG107_14PL   ~(1 << 3)
#else
#define  MG107_14PL   0xFFFF
#endif
#if (G105PL >= G107PL) || (G105PL == 0)
#define  MG107_15PL   ~(1 << 4)
#else
#define  MG107_15PL   0xFFFF
#endif
#if (G106PL >= G107PL) || (G106PL == 0)
#define  MG107_16PL   ~(1 << 5)
#else
#define  MG107_16PL   0xFFFF
#endif
#if (G108PL >= G107PL) || (G108PL == 0)
#define  MG107_18PL   ~(1 << 7)
#else
#define  MG107_18PL   0xFFFF
#endif
#define  MG107_17PL   0x00BF
#define  MG107   (MG107_11PL & MG107_12PL & MG107_13PL & MG107_14PL & \
                  MG107_15PL & MG107_16PL & MG107_17PL & MG107_18PL)
// End of MG107:

// Beginning of MG108:
#if (G101PL >= G108PL) || (G101PL == 0)
#define  MG108_11PL   ~(1)
#else
#define  MG108_11PL   0xFFFF
#endif
#if (G102PL >= G108PL) || (G102PL == 0)
#define  MG108_12PL   ~(1 << 1)
#else
#define  MG108_12PL   0xFFFF
#endif
#if (G103PL >= G108PL) || (G103PL == 0)
#define  MG108_13PL   ~(1 << 2)
#else
#define  MG108_13PL   0xFFFF
#endif
#if (G104PL >= G108PL) || (G104PL == 0)
#define  MG108_14PL   ~(1 << 3)
#else
#define  MG108_14PL   0xFFFF
#endif
#if (G105PL >= G108PL) || (G105PL == 0)
#define  MG108_15PL   ~(1 << 4)
#else
#define  MG108_15PL   0xFFFF
#endif
#if (G106PL >= G108PL) || (G106PL == 0)
#define  MG108_16PL   ~(1 << 5)
#else
#define  MG108_16PL   0xFFFF
#endif
#if (G107PL >= G108PL) || (G107PL == 0)
#define  MG108_17PL   ~(1 << 6)
#else
#define  MG108_17PL   0xFFFF
#endif
#define  MG108_18PL   0x007F
#define  MG108    (MG108_11PL & MG108_12PL & MG108_13PL & MG108_14PL & \
                  MG108_15PL & MG108_16PL & MG108_17PL & MG108_18PL)
// End of MG108:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG111 to MG118:
//

// Beginning of MG111:
#if (G112PL >= G111PL) || (G112PL == 0)
#define  MG111_12PL   ~(1 << 1)
#else
#define  MG111_12PL   0xFFFF
#endif
#if (G113PL >= G111PL) || (G113PL == 0)
#define  MG111_13PL   ~(1 << 2)
#else
#define  MG111_13PL   0xFFFF
#endif
#if (G114PL >= G111PL) || (G114PL == 0)
#define  MG111_14PL   ~(1 << 3)
#else
#define  MG111_14PL   0xFFFF
#endif
#if (G115PL >= G111PL) || (G115PL == 0)
#define  MG111_15PL   ~(1 << 4)
#else
#define  MG111_15PL   0xFFFF
#endif
#if (G116PL >= G111PL) || (G116PL == 0)
#define  MG111_16PL   ~(1 << 5)
#else
#define  MG111_16PL   0xFFFF
#endif
#if (G117PL >= G111PL) || (G117PL == 0)
#define  MG111_17PL   ~(1 << 6)
#else
#define  MG111_17PL   0xFFFF
#endif
#if (G118PL >= G111PL) || (G118PL == 0)
#define  MG111_18PL   ~(1 << 7)
#else
#define  MG111_18PL   0xFFFF
#endif
#define  MG111_11PL   0x00FE
#define  MG111   (MG111_11PL & MG111_12PL & MG111_13PL & MG111_14PL & \
                  MG111_15PL & MG111_16PL & MG111_17PL & MG111_18PL)
// End of MG111:

// Beginning of MG112:
#if (G111PL >= G112PL) || (G111PL == 0)
#define  MG112_11PL   ~(1)
#else
#define  MG112_11PL   0xFFFF
#endif
#if (G113PL >= G112PL) || (G113PL == 0)
#define  MG112_13PL   ~(1 << 2)
#else
#define  MG112_13PL   0xFFFF
#endif
#if (G114PL >= G112PL) || (G114PL == 0)
#define  MG112_14PL   ~(1 << 3)
#else
#define  MG112_14PL   0xFFFF
#endif
#if (G115PL >= G112PL) || (G115PL == 0)
#define  MG112_15PL   ~(1 << 4)
#else
#define  MG112_15PL   0xFFFF
#endif
#if (G116PL >= G112PL) || (G116PL == 0)
#define  MG112_16PL   ~(1 << 5)
#else
#define  MG112_16PL   0xFFFF
#endif
#if (G117PL >= G112PL) || (G117PL == 0)
#define  MG112_17PL   ~(1 << 6)
#else
#define  MG112_17PL   0xFFFF
#endif
#if (G118PL >= G112PL) || (G118PL == 0)
#define  MG112_18PL   ~(1 << 7)
#else
#define  MG112_18PL   0xFFFF
#endif
#define  MG112_12PL   0x00FD
#define  MG112   (MG112_11PL & MG112_12PL & MG112_13PL & MG112_14PL & \
                  MG112_15PL & MG112_16PL & MG112_17PL & MG112_18PL)
// End of MG112:

// Beginning of MG113:
#if (G111PL >= G113PL) || (G111PL == 0)
#define  MG113_11PL   ~(1)
#else
#define  MG113_11PL   0xFFFF
#endif
#if (G112PL >= G113PL) || (G112PL == 0)
#define  MG113_12PL   ~(1 << 1)
#else
#define  MG113_12PL   0xFFFF
#endif
#if (G114PL >= G113PL) || (G114PL == 0)
#define  MG113_14PL   ~(1 << 3)
#else
#define  MG113_14PL   0xFFFF
#endif
#if (G115PL >= G113PL) || (G115PL == 0)
#define  MG113_15PL   ~(1 << 4)
#else
#define  MG113_15PL   0xFFFF
#endif
#if (G116PL >= G113PL) || (G116PL == 0)
#define  MG113_16PL   ~(1 << 5)
#else
#define  MG113_16PL   0xFFFF
#endif
#if (G117PL >= G113PL) || (G117PL == 0)
#define  MG113_17PL   ~(1 << 6)
#else
#define  MG113_17PL   0xFFFF
#endif
#if (G118PL >= G113PL) || (G118PL == 0)
#define  MG113_18PL   ~(1 << 7)
#else
#define  MG113_18PL   0xFFFF
#endif
#define  MG113_13PL   0x00FB
#define  MG113   (MG113_11PL & MG113_12PL & MG113_13PL & MG113_14PL & \
                  MG113_15PL & MG113_16PL & MG113_17PL & MG113_18PL)
// End of MG113:

// Beginning of MG114:
#if (G111PL >= G114PL) || (G111PL == 0)
#define  MG114_11PL   ~(1)
#else
#define  MG114_11PL   0xFFFF
#endif
#if (G112PL >= G114PL) || (G112PL == 0)
#define  MG114_12PL   ~(1 << 1)
#else
#define  MG114_12PL   0xFFFF
#endif
#if (G113PL >= G114PL) || (G113PL == 0)
#define  MG114_13PL   ~(1 << 2)
#else
#define  MG114_13PL   0xFFFF
#endif
#if (G115PL >= G114PL) || (G115PL == 0)
#define  MG114_15PL   ~(1 << 4)
#else
#define  MG114_15PL   0xFFFF
#endif
#if (G116PL >= G114PL) || (G116PL == 0)
#define  MG114_16PL   ~(1 << 5)
#else
#define  MG114_16PL   0xFFFF
#endif
#if (G117PL >= G114PL) || (G117PL == 0)
#define  MG114_17PL   ~(1 << 6)
#else
#define  MG114_17PL   0xFFFF
#endif
#if (G118PL >= G114PL) || (G118PL == 0)
#define  MG114_18PL   ~(1 << 7)
#else
#define  MG114_18PL   0xFFFF
#endif
#define  MG114_14PL   0x00F7
#define  MG114   (MG114_11PL & MG114_12PL & MG114_13PL & MG114_14PL & \
                  MG114_15PL & MG114_16PL & MG114_17PL & MG114_18PL)
// End of MG114:

// Beginning of MG115:
#if (G111PL >= G115PL) || (G111PL == 0)
#define  MG115_11PL   ~(1)
#else
#define  MG115_11PL   0xFFFF
#endif
#if (G112PL >= G115PL) || (G112PL == 0)
#define  MG115_12PL   ~(1 << 1)
#else
#define  MG115_12PL   0xFFFF
#endif
#if (G113PL >= G115PL) || (G113PL == 0)
#define  MG115_13PL   ~(1 << 2)
#else
#define  MG115_13PL   0xFFFF
#endif
#if (G114PL >= G115PL) || (G114PL == 0)
#define  MG115_14PL   ~(1 << 3)
#else
#define  MG115_14PL   0xFFFF
#endif
#if (G116PL >= G115PL) || (G116PL == 0)
#define  MG115_16PL   ~(1 << 5)
#else
#define  MG115_16PL   0xFFFF
#endif
#if (G117PL >= G115PL) || (G117PL == 0)
#define  MG115_17PL   ~(1 << 6)
#else
#define  MG115_17PL   0xFFFF
#endif
#if (G118PL >= G115PL) || (G118PL == 0)
#define  MG115_18PL   ~(1 << 7)
#else
#define  MG115_18PL   0xFFFF
#endif
#define  MG115_15PL   0x00EF
#define  MG115    (MG115_11PL & MG115_12PL & MG115_13PL & MG115_14PL & \
                  MG115_15PL & MG115_16PL & MG115_17PL & MG115_18PL)
// End of MG115:

// Beginning of MG116:
#if (G111PL >= G116PL) || (G111PL == 0)
#define  MG116_11PL   ~(1)
#else
#define  MG116_11PL   0xFFFF
#endif
#if (G112PL >= G116PL) || (G112PL == 0)
#define  MG116_12PL   ~(1 << 1)
#else
#define  MG116_12PL   0xFFFF
#endif
#if (G113PL >= G116PL) || (G113PL == 0)
#define  MG116_13PL   ~(1 << 2)
#else
#define  MG116_13PL   0xFFFF
#endif
#if (G114PL >= G116PL) || (G114PL == 0)
#define  MG116_14PL   ~(1 << 3)
#else
#define  MG116_14PL   0xFFFF
#endif
#if (G115PL >= G116PL) || (G115PL == 0)
#define  MG116_15PL   ~(1 << 4)
#else
#define  MG116_15PL   0xFFFF
#endif
#if (G117PL >= G116PL) || (G117PL == 0)
#define  MG116_17PL   ~(1 << 6)
#else
#define  MG116_17PL   0xFFFF
#endif
#if (G118PL >= G116PL) || (G118PL == 0)
#define  MG116_18PL   ~(1 << 7)
#else
#define  MG116_18PL   0xFFFF
#endif
#define  MG116_16PL   0x00DF
#define  MG116   (MG116_11PL & MG116_12PL & MG116_13PL & MG116_14PL & \
                  MG116_15PL & MG116_16PL & MG116_17PL & MG116_18PL)
// End of MG116:

// Beginning of MG117:
#if (G111PL >= G117PL) || (G111PL == 0)
#define  MG117_11PL   ~(1)
#else
#define  MG117_11PL   0xFFFF
#endif
#if (G112PL >= G117PL) || (G112PL == 0)
#define  MG117_12PL   ~(1 << 1)
#else
#define  MG117_12PL   0xFFFF
#endif
#if (G113PL >= G117PL) || (G113PL == 0)
#define  MG117_13PL   ~(1 << 2)
#else
#define  MG117_13PL   0xFFFF
#endif
#if (G114PL >= G117PL) || (G114PL == 0)
#define  MG117_14PL   ~(1 << 3)
#else
#define  MG117_14PL   0xFFFF
#endif
#if (G115PL >= G117PL) || (G115PL == 0)
#define  MG117_15PL   ~(1 << 4)
#else
#define  MG117_15PL   0xFFFF
#endif
#if (G116PL >= G117PL) || (G116PL == 0)
#define  MG117_16PL   ~(1 << 5)
#else
#define  MG117_16PL   0xFFFF
#endif
#if (G118PL >= G117PL) || (G118PL == 0)
#define  MG117_18PL   ~(1 << 7)
#else
#define  MG117_18PL   0xFFFF
#endif
#define  MG117_17PL   0x00BF
#define  MG117   (MG117_11PL & MG117_12PL & MG117_13PL & MG117_14PL & \
                  MG117_15PL & MG117_16PL & MG117_17PL & MG117_18PL)
// End of MG117:

// Beginning of MG118:
#if (G111PL >= G118PL) || (G111PL == 0)
#define  MG118_11PL   ~(1)
#else
#define  MG118_11PL   0xFFFF
#endif
#if (G112PL >= G118PL) || (G112PL == 0)
#define  MG118_12PL   ~(1 << 1)
#else
#define  MG118_12PL   0xFFFF
#endif
#if (G113PL >= G118PL) || (G113PL == 0)
#define  MG118_13PL   ~(1 << 2)
#else
#define  MG118_13PL   0xFFFF
#endif
#if (G114PL >= G118PL) || (G114PL == 0)
#define  MG118_14PL   ~(1 << 3)
#else
#define  MG118_14PL   0xFFFF
#endif
#if (G115PL >= G118PL) || (G115PL == 0)
#define  MG118_15PL   ~(1 << 4)
#else
#define  MG118_15PL   0xFFFF
#endif
#if (G116PL >= G118PL) || (G116PL == 0)
#define  MG118_16PL   ~(1 << 5)
#else
#define  MG118_16PL   0xFFFF
#endif
#if (G117PL >= G118PL) || (G117PL == 0)
#define  MG118_17PL   ~(1 << 6)
#else
#define  MG118_17PL   0xFFFF
#endif
#define  MG118_18PL   0x007F
#define  MG118   (MG118_11PL & MG118_12PL & MG118_13PL & MG118_14PL & \
                  MG118_15PL & MG118_16PL & MG118_17PL & MG118_18PL)
// End of MG118:

//-------------------------------------------------------------------------------
// Automatically generate PIEIER1 interrupt masks MG121 to MG128:
//

// Beginning of MG121:
#if (G122PL >= G121PL) || (G122PL == 0)
#define  MG121_12PL   ~(1 << 1)
#else
#define  MG121_12PL   0xFFFF
#endif
#if (G123PL >= G121PL) || (G123PL == 0)
#define  MG121_13PL   ~(1 << 2)
#else
#define  MG121_13PL   0xFFFF
#endif
#if (G124PL >= G121PL) || (G124PL == 0)
#define  MG121_14PL   ~(1 << 3)
#else
#define  MG121_14PL   0xFFFF
#endif
#if (G125PL >= G121PL) || (G125PL == 0)
#define  MG121_15PL   ~(1 << 4)
#else
#define  MG121_15PL   0xFFFF
#endif
#if (G126PL >= G121PL) || (G126PL == 0)
#define  MG121_16PL   ~(1 << 5)
#else
#define  MG121_16PL   0xFFFF
#endif
#if (G127PL >= G121PL) || (G127PL == 0)
#define  MG121_17PL   ~(1 << 6)
#else
#define  MG121_17PL   0xFFFF
#endif
#if (G128PL >= G121PL) || (G128PL == 0)
#define  MG121_18PL   ~(1 << 7)
#else
#define  MG121_18PL   0xFFFF
#endif
#define  MG121_11PL   0x00FE
#define  MG121   (MG121_11PL & MG121_12PL & MG121_13PL & MG121_14PL & \
                  MG121_15PL & MG121_16PL & MG121_17PL & MG121_18PL)
// End of MG121:

// Beginning of MG121:
#if (G121PL >= G122PL) || (G121PL == 0)
#define  MG122_11PL   ~(1)
#else
#define  MG122_11PL   0xFFFF
#endif
#if (G123PL >= G122PL) || (G123PL == 0)
#define  MG122_13PL   ~(1 << 2)
#else
#define  MG122_13PL   0xFFFF
#endif
#if (G124PL >= G122PL) || (G124PL == 0)
#define  MG122_14PL   ~(1 << 3)
#else
#define  MG122_14PL   0xFFFF
#endif
#if (G125PL >= G122PL) || (G125PL == 0)
#define  MG122_15PL   ~(1 << 4)
#else
#define  MG122_15PL   0xFFFF
#endif
#if (G126PL >= G122PL) || (G126PL == 0)
#define  MG122_16PL   ~(1 << 5)
#else
#define  MG122_16PL   0xFFFF
#endif
#if (G127PL >= G122PL) || (G127PL == 0)
#define  MG122_17PL   ~(1 << 6)
#else
#define  MG122_17PL   0xFFFF
#endif
#if (G128PL >= G122PL) || (G128PL == 0)
#define  MG122_18PL   ~(1 << 7)
#else
#define  MG122_18PL   0xFFFF
#endif
#define  MG122_12PL   0x00FD
#define  MG122   (MG122_11PL & MG122_12PL & MG122_13PL & MG122_14PL & \
                  MG122_15PL & MG122_16PL & MG122_17PL & MG122_18PL)
// End of MG122:

// Beginning of MG123:
#if (G121PL >= G123PL) || (G121PL == 0)
#define  MG123_11PL   ~(1)
#else
#define  MG123_11PL   0xFFFF
#endif
#if (G122PL >= G123PL) || (G122PL == 0)
#define  MG123_12PL   ~(1 << 1)
#else
#define  MG123_12PL   0xFFFF
#endif
#if (G124PL >= G123PL) || (G124PL == 0)
#define  MG123_14PL   ~(1 << 3)
#else
#define  MG123_14PL   0xFFFF
#endif
#if (G125PL >= G123PL) || (G125PL == 0)
#define  MG123_15PL   ~(1 << 4)
#else
#define  MG123_15PL   0xFFFF
#endif
#if (G126PL >= G123PL) || (G126PL == 0)
#define  MG123_16PL   ~(1 << 5)
#else
#define  MG123_16PL   0xFFFF
#endif
#if (G127PL >= G123PL) || (G127PL == 0)
#define  MG123_17PL   ~(1 << 6)
#else
#define  MG123_17PL   0xFFFF
#endif
#if (G128PL >= G123PL) || (G128PL == 0)
#define  MG123_18PL   ~(1 << 7)
#else
#define  MG123_18PL   0xFFFF
#endif
#define  MG123_13PL   0x00FB
#define  MG123    (MG123_11PL & MG123_12PL & MG123_13PL & MG123_14PL & \
                  MG123_15PL & MG123_16PL & MG123_17PL & MG123_18PL)
// End of MG123:

// Beginning of MG124:
#if (G121PL >= G124PL) || (G121PL == 0)
#define  MG124_11PL   ~(1)
#else
#define  MG124_11PL   0xFFFF
#endif
#if (G122PL >= G124PL) || (G122PL == 0)
#define  MG124_12PL   ~(1 << 1)
#else
#define  MG124_12PL   0xFFFF
#endif
#if (G123PL >= G124PL) || (G123PL == 0)
#define  MG124_13PL   ~(1 << 2)
#else
#define  MG124_13PL   0xFFFF
#endif
#if (G125PL >= G124PL) || (G125PL == 0)
#define  MG124_15PL   ~(1 << 4)
#else
#define  MG124_15PL   0xFFFF
#endif
#if (G126PL >= G124PL) || (G126PL == 0)
#define  MG124_16PL   ~(1 << 5)
#else
#define  MG124_16PL   0xFFFF
#endif
#if (G127PL >= G124PL) || (G127PL == 0)
#define  MG124_17PL   ~(1 << 6)
#else
#define  MG124_17PL   0xFFFF
#endif
#if (G128PL >= G124PL) || (G128PL == 0)
#define  MG124_18PL   ~(1 << 7)
#else
#define  MG124_18PL   0xFFFF
#endif
#define  MG124_14PL   0x00F7
#define  MG124   (MG124_11PL & MG124_12PL & MG124_13PL & MG124_14PL & \
                  MG124_15PL & MG124_16PL & MG124_17PL & MG124_18PL)
// End of MG124:

// Beginning of MG125:
#if (G121PL >= G125PL) || (G121PL == 0)
#define  MG125_11PL   ~(1)
#else
#define  MG125_11PL   0xFFFF
#endif
#if (G122PL >= G125PL) || (G122PL == 0)
#define  MG125_12PL   ~(1 << 1)
#else
#define  MG125_12PL   0xFFFF
#endif
#if (G123PL >= G125PL) || (G123PL == 0)
#define  MG125_13PL   ~(1 << 2)
#else
#define  MG125_13PL   0xFFFF
#endif
#if (G124PL >= G125PL) || (G124PL == 0)
#define  MG125_14PL   ~(1 << 3)
#else
#define  MG125_14PL   0xFFFF
#endif
#if (G126PL >= G125PL) || (G126PL == 0)
#define  MG125_16PL   ~(1 << 5)
#else
#define  MG125_16PL   0xFFFF
#endif
#if (G127PL >= G125PL) || (G127PL == 0)
#define  MG125_17PL   ~(1 << 6)
#else
#define  MG125_17PL   0xFFFF
#endif
#if (G128PL >= G125PL) || (G128PL == 0)
#define  MG125_18PL   ~(1 << 7)
#else
#define  MG125_18PL   0xFFFF
#endif
#define  MG125_15PL   0x00EF
#define  MG125   (MG125_11PL & MG125_12PL & MG125_13PL & MG125_14PL & \
                  MG125_15PL & MG125_16PL & MG125_17PL & MG125_18PL)
// End of MG125:

// Beginning of MG126:
#if (G121PL >= G126PL) || (G121PL == 0)
#define  MG126_11PL   ~(1)
#else
#define  MG126_11PL   0xFFFF
#endif
#if (G122PL >= G126PL) || (G122PL == 0)
#define  MG126_12PL   ~(1 << 1)
#else
#define  MG126_12PL   0xFFFF
#endif
#if (G123PL >= G126PL) || (G123PL == 0)
#define  MG126_13PL   ~(1 << 2)
#else
#define  MG126_13PL   0xFFFF
#endif
#if (G124PL >= G126PL) || (G124PL == 0)
#define  MG126_14PL   ~(1 << 3)
#else
#define  MG126_14PL   0xFFFF
#endif
#if (G125PL >= G126PL) || (G125PL == 0)
#define  MG126_15PL   ~(1 << 4)
#else
#define  MG126_15PL   0xFFFF
#endif
#if (G127PL >= G126PL) || (G127PL == 0)
#define  MG126_17PL   ~(1 << 6)
#else
#define  MG126_17PL   0xFFFF
#endif
#if (G128PL >= G126PL) || (G128PL == 0)
#define  MG126_18PL   ~(1 << 7)
#else
#define  MG126_18PL   0xFFFF
#endif
#define  MG126_16PL   0x00DF
#define  MG126   (MG126_11PL & MG126_12PL & MG126_13PL & MG126_14PL & \
                  MG126_15PL & MG126_16PL & MG126_17PL & MG126_18PL)
// End of MG126:

// Beginning of MG127:
#if (G121PL >= G127PL) || (G121PL == 0)
#define  MG127_11PL   ~(1)
#else
#define  MG127_11PL   0xFFFF
#endif
#if (G122PL >= G127PL) || (G122PL == 0)
#define  MG127_12PL   ~(1 << 1)
#else
#define  MG127_12PL   0xFFFF
#endif
#if (G123PL >= G127PL) || (G123PL == 0)
#define  MG127_13PL   ~(1 << 2)
#else
#define  MG127_13PL   0xFFFF
#endif
#if (G124PL >= G127PL) || (G124PL == 0)
#define  MG127_14PL   ~(1 << 3)
#else
#define  MG127_14PL   0xFFFF
#endif
#if (G125PL >= G127PL) || (G125PL == 0)
#define  MG127_15PL   ~(1 << 4)
#else
#define  MG127_15PL   0xFFFF
#endif
#if (G126PL >= G127PL) || (G126PL == 0)
#define  MG127_16PL   ~(1 << 5)
#else
#define  MG127_16PL   0xFFFF
#endif
#if (G128PL >= G127PL) || (G128PL == 0)
#define  MG127_18PL   ~(1 << 7)
#else
#define  MG127_18PL   0xFFFF
#endif
#define  MG127_17PL   0x00BF
#define  MG127   (MG127_11PL & MG127_12PL & MG127_13PL & MG127_14PL & \
                  MG127_15PL & MG127_16PL & MG127_17PL & MG127_18PL)
// End of MG127:

// Beginning of MG128:
#if (G121PL >= G128PL) || (G121PL == 0)
#define  MG128_11PL   ~(1)
#else
#define  MG128_11PL   0xFFFF
#endif
#if (G122PL >= G128PL) || (G122PL == 0)
#define  MG128_12PL   ~(1 << 1)
#else
#define  MG128_12PL   0xFFFF
#endif
#if (G123PL >= G128PL) || (G123PL == 0)
#define  MG128_13PL   ~(1 << 2)
#else
#define  MG128_13PL   0xFFFF
#endif
#if (G124PL >= G128PL) || (G124PL == 0)
#define  MG128_14PL   ~(1 << 3)
#else
#define  MG128_14PL   0xFFFF
#endif
#if (G125PL >= G128PL) || (G125PL == 0)
#define  MG128_15PL   ~(1 << 4)
#else
#define  MG128_15PL   0xFFFF
#endif
#if (G126PL >= G128PL) || (G126PL == 0)
#define  MG128_16PL   ~(1 << 5)
#else
#define  MG128_16PL   0xFFFF
#endif
#if (G127PL >= G128PL) || (G127PL == 0)
#define  MG128_17PL   ~(1 << 6)
#else
#define  MG128_17PL   0xFFFF
#endif
#define  MG128_18PL   0x007F
#define  MG128   (MG128_11PL & MG128_12PL & MG128_13PL & MG128_14PL & \
                  MG128_15PL & MG128_16PL & MG128_17PL & MG128_18PL)
// End of MG128:


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif // eof

//===========================================================================
// No more.
//===========================================================================
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\IQmathLib.h 
//###########################################################################
//
// FILE:	IQmathLib.h
//
// TITLE:	IQ Math library functions definitions.
//
//###########################################################################
//
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|==============================================
//  1.3 | 19 Nov 2001 | A. T. | Original Release.
// -----|-------------|-------|----------------------------------------------
//  1.4 | 17 May 2002 | A. T. | Added new functions and support for
//      |             |       | intrinsics IQmpy, IQxmpy, IQsat.
// -----|-------------|-------|----------------------------------------------
//  1.4a| 12 Jun 2002 | A. T. | Fixed problem with _IQ() operation on
//      |             |       | variables.
// -----|-------------|-------|----------------------------------------------
//  1.4b| 18 Jun 2002 | A. T. | Fixed bug with _IQtoIQN() and _IQNtoIQ()
//      |             |       | operations.
// -----|-------------|-------|----------------------------------------------
//  1.4d| 30 Mar 2003 | DA/SD | 1. Added macro parameters in parentheses 
//      |             |       |    in number of places where it matters
//      |             |       | 2. Added macro definition to include header 
//      |             |       |    file multiple times in the program.     
// -----|-------------|-------|----------------------------------------------
//
//###########################################################################
// 
// User needs to configure "MATH_TYPE" and "GLOBAL_Q" values:
//
//---------------------------------------------------------------------------
// Select math type, IQ_MATH or FLOAT_MATH:
//

#ifndef __IQMATHLIB_H_INCLUDED__
#define __IQMATHLIB_H_INCLUDED__


#define   FLOAT_MATH     1
#define   IQ_MATH        0

#ifndef   MATH_TYPE
#define   MATH_TYPE      IQ_MATH
#endif

//---------------------------------------------------------------------------
// Select global Q value and scaling. The Q value is limited to the 
// following range for all functions:
//
//        30 <= GLOBAL_Q <=  1
//
#ifndef   GLOBAL_Q
#define   GLOBAL_Q       19
#endif

//---------------------------------------------------------------------------
// Various Usefull Constant Definitions:
//
#define   QG          GLOBAL_Q
#define   Q30         30
#define   Q29         29
#define   Q28         28
#define   Q27         27
#define   Q26         26
#define   Q25         25
#define   Q24         24
#define   Q23         23
#define   Q22         22
#define   Q21         21
#define   Q20         20
#define   Q19         19
#define   Q18         18
#define   Q17         17
#define   Q16         16
#define   Q15         15
#define   Q14         14
#define   Q13         13
#define   Q12         12
#define   Q11         11
#define   Q10         10
#define   Q9          9
#define   Q8          8
#define   Q7          7
#define   Q6          6
#define   Q5          5
#define   Q4          4
#define   Q3          3
#define   Q2          2
#define   Q1          1

#define   MAX_IQ_POS  2147483647 
#define   MAX_IQ_NEG  -2147483648
#define   MIN_IQ_POS  1
#define   MIN_IQ_NEG  -1

//###########################################################################
#if MATH_TYPE == IQ_MATH
//###########################################################################
// If IQ_MATH is used, the following IQmath library function definitions
// are used:
//===========================================================================
typedef   long    _iq;
typedef   long    _iq30;
typedef   long    _iq29;
typedef   long    _iq28;
typedef   long    _iq27;
typedef   long    _iq26;
typedef   long    _iq25;
typedef   long    _iq24;
typedef   long    _iq23;
typedef   long    _iq22;
typedef   long    _iq21;
typedef   long    _iq20;
typedef   long    _iq19;
typedef   long    _iq18;
typedef   long    _iq17;
typedef   long    _iq16;
typedef   long    _iq15;
typedef   long    _iq14;
typedef   long    _iq13;
typedef   long    _iq12;
typedef   long    _iq11;
typedef   long    _iq10;
typedef   long    _iq9;
typedef   long    _iq8;
typedef   long    _iq7;
typedef   long    _iq6;
typedef   long    _iq5;
typedef   long    _iq4;
typedef   long    _iq3;
typedef   long    _iq2;
typedef   long    _iq1;
//---------------------------------------------------------------------------
#define   _IQ30(A)      (long) ((A) * 1073741824.0L)
#define   _IQ29(A)      (long) ((A) * 536870912.0L)
#define   _IQ28(A)      (long) ((A) * 268435456.0L)
#define   _IQ27(A)      (long) ((A) * 134217728.0L)
#define   _IQ26(A)      (long) ((A) * 67108864.0L)
#define   _IQ25(A)      (long) ((A) * 33554432.0L)
#define   _IQ24(A)      (long) ((A) * 16777216.0L)
#define   _IQ23(A)      (long) ((A) * 8388608.0L)
#define   _IQ22(A)      (long) ((A) * 4194304.0L)
#define   _IQ21(A)      (long) ((A) * 2097152.0L)
#define   _IQ20(A)      (long) ((A) * 1048576.0L)
#define   _IQ19(A)      (long) ((A) * 524288.0L)
#define   _IQ18(A)      (long) ((A) * 262144.0L)
#define   _IQ17(A)      (long) ((A) * 131072.0L)
#define   _IQ16(A)      (long) ((A) * 65536.0L)
#define   _IQ15(A)      (long) ((A) * 32768.0L)
#define   _IQ14(A)      (long) ((A) * 16384.0L)
#define   _IQ13(A)      (long) ((A) * 8192.0L)
#define   _IQ12(A)      (long) ((A) * 4096.0L)
#define   _IQ11(A)      (long) ((A) * 2048.0L)
#define   _IQ10(A)      (long) ((A) * 1024.0L)
#define   _IQ9(A)       (long) ((A) * 512.0L)
#define   _IQ8(A)       (long) ((A) * 256.0L)
#define   _IQ7(A)       (long) ((A) * 128.0L)
#define   _IQ6(A)       (long) ((A) * 64.0L)
#define   _IQ5(A)       (long) ((A) * 32.0L)
#define   _IQ4(A)       (long) ((A) * 16.0L)
#define   _IQ3(A)       (long) ((A) * 8.0L)
#define   _IQ2(A)       (long) ((A) * 4.0L)
#define   _IQ1(A)       (long) ((A) * 2.0L)

#if GLOBAL_Q == 30
#define   _IQ(A)  _IQ30(A)
#endif
#if GLOBAL_Q == 29
#define   _IQ(A)  _IQ29(A)
#endif
#if GLOBAL_Q == 28
#define   _IQ(A)  _IQ28(A)
#endif
#if GLOBAL_Q == 27
#define   _IQ(A)  _IQ27(A)
#endif
#if GLOBAL_Q == 26
#define   _IQ(A)  _IQ26(A)
#endif
#if GLOBAL_Q == 25
#define   _IQ(A)  _IQ25(A)
#endif
#if GLOBAL_Q == 24
#define   _IQ(A)  _IQ24(A)
#endif
#if GLOBAL_Q == 23
#define   _IQ(A)  _IQ23(A)
#endif
#if GLOBAL_Q == 22
#define   _IQ(A)  _IQ22(A)
#endif
#if GLOBAL_Q == 21
#define   _IQ(A)  _IQ21(A)
#endif
#if GLOBAL_Q == 20
#define   _IQ(A)  _IQ20(A)
#endif
#if GLOBAL_Q == 19
#define   _IQ(A)  _IQ19(A)
#endif
#if GLOBAL_Q == 18
#define   _IQ(A)  _IQ18(A)
#endif
#if GLOBAL_Q == 17
#define   _IQ(A)  _IQ17(A)
#endif
#if GLOBAL_Q == 16
#define   _IQ(A)  _IQ16(A)
#endif
#if GLOBAL_Q == 15
#define   _IQ(A)  _IQ15(A)
#endif
#if GLOBAL_Q == 14
#define   _IQ(A)  _IQ14(A)
#endif
#if GLOBAL_Q == 13
#define   _IQ(A)  _IQ13(A)
#endif
#if GLOBAL_Q == 12
#define   _IQ(A)  _IQ12(A)
#endif
#if GLOBAL_Q == 11
#define   _IQ(A)  _IQ11(A)
#endif
#if GLOBAL_Q == 10
#define   _IQ(A)  _IQ10(A)
#endif
#if GLOBAL_Q == 9
#define   _IQ(A)  _IQ9(A)
#endif
#if GLOBAL_Q == 8
#define   _IQ(A)  _IQ8(A)
#endif
#if GLOBAL_Q == 7
#define   _IQ(A)  _IQ7(A)
#endif
#if GLOBAL_Q == 6
#define   _IQ(A)  _IQ6(A)
#endif
#if GLOBAL_Q == 5
#define   _IQ(A)  _IQ5(A)
#endif
#if GLOBAL_Q == 4
#define   _IQ(A)  _IQ4(A)
#endif
#if GLOBAL_Q == 3
#define   _IQ(A)  _IQ3(A)
#endif
#if GLOBAL_Q == 2
#define   _IQ(A)  _IQ2(A)
#endif
#if GLOBAL_Q == 1
#define   _IQ(A)  _IQ1(A)
#endif
//---------------------------------------------------------------------------
extern    float _IQ30toF(long A);
extern    float _IQ29toF(long A);
extern    float _IQ28toF(long A);
extern    float _IQ27toF(long A);
extern    float _IQ26toF(long A);
extern    float _IQ25toF(long A);
extern    float _IQ24toF(long A);
extern    float _IQ23toF(long A);
extern    float _IQ22toF(long A);
extern    float _IQ21toF(long A);
extern    float _IQ20toF(long A);
extern    float _IQ19toF(long A);
extern    float _IQ18toF(long A);
extern    float _IQ17toF(long A);
extern    float _IQ16toF(long A);
extern    float _IQ15toF(long A);
extern    float _IQ14toF(long A);
extern    float _IQ13toF(long A);
extern    float _IQ12toF(long A);
extern    float _IQ11toF(long A);
extern    float _IQ10toF(long A);
extern    float _IQ9toF(long A);
extern    float _IQ8toF(long A);
extern    float _IQ7toF(long A);
extern    float _IQ6toF(long A);
extern    float _IQ5toF(long A);
extern    float _IQ4toF(long A);
extern    float _IQ3toF(long A);
extern    float _IQ2toF(long A);
extern    float _IQ1toF(long A);

#if GLOBAL_Q == 30
#define   _IQtoF(A)  _IQ30toF(A)
#endif
#if GLOBAL_Q == 29
#define   _IQtoF(A)  _IQ29toF(A)
#endif
#if GLOBAL_Q == 28
#define   _IQtoF(A)  _IQ28toF(A)
#endif
#if GLOBAL_Q == 27
#define   _IQtoF(A)  _IQ27toF(A)
#endif
#if GLOBAL_Q == 26
#define   _IQtoF(A)  _IQ26toF(A)
#endif
#if GLOBAL_Q == 25
#define   _IQtoF(A)  _IQ25toF(A)
#endif
#if GLOBAL_Q == 24
#define   _IQtoF(A)  _IQ24toF(A)
#endif
#if GLOBAL_Q == 23
#define   _IQtoF(A)  _IQ23toF(A)
#endif
#if GLOBAL_Q == 22
#define   _IQtoF(A)  _IQ22toF(A)
#endif
#if GLOBAL_Q == 21
#define   _IQtoF(A)  _IQ21toF(A)
#endif
#if GLOBAL_Q == 20
#define   _IQtoF(A)  _IQ20toF(A)
#endif
#if GLOBAL_Q == 19
#define   _IQtoF(A)  _IQ19toF(A)
#endif
#if GLOBAL_Q == 18
#define   _IQtoF(A)  _IQ18toF(A)
#endif
#if GLOBAL_Q == 17
#define   _IQtoF(A)  _IQ17toF(A)
#endif
#if GLOBAL_Q == 16
#define   _IQtoF(A)  _IQ16toF(A)
#endif
#if GLOBAL_Q == 15
#define   _IQtoF(A)  _IQ15toF(A)
#endif
#if GLOBAL_Q == 14
#define   _IQtoF(A)  _IQ14toF(A)
#endif
#if GLOBAL_Q == 13
#define   _IQtoF(A)  _IQ13toF(A)
#endif
#if GLOBAL_Q == 12
#define   _IQtoF(A)  _IQ12toF(A)
#endif
#if GLOBAL_Q == 11
#define   _IQtoF(A)  _IQ11toF(A)
#endif
#if GLOBAL_Q == 10
#define   _IQtoF(A)  _IQ10toF(A)
#endif
#if GLOBAL_Q == 9
#define   _IQtoF(A)  _IQ9toF(A)
#endif
#if GLOBAL_Q == 8
#define   _IQtoF(A)  _IQ8toF(A)
#endif
#if GLOBAL_Q == 7
#define   _IQtoF(A)  _IQ7toF(A)
#endif
#if GLOBAL_Q == 6
#define   _IQtoF(A)  _IQ6toF(A)
#endif
#if GLOBAL_Q == 5
#define   _IQtoF(A)  _IQ5toF(A)
#endif
#if GLOBAL_Q == 4
#define   _IQtoF(A)  _IQ4toF(A)
#endif
#if GLOBAL_Q == 3
#define   _IQtoF(A)  _IQ3toF(A)
#endif
#if GLOBAL_Q == 2
#define   _IQtoF(A)  _IQ2toF(A)
#endif
#if GLOBAL_Q == 1
#define   _IQtoF(A)  _IQ1toF(A)
#endif
//---------------------------------------------------------------------------
#define   _IQsat(A, Pos, Neg)  __IQsat(A, Pos, Neg)
//---------------------------------------------------------------------------
#define   _IQtoIQ30(A)  ((long) (A) << (30 - GLOBAL_Q))
#define   _IQ30toIQ(A)  ((long) (A) >> (30 - GLOBAL_Q))

#define   _IQtoIQ29(A)  ((GLOBAL_Q >= 29) ? ((long) (A) >> (GLOBAL_Q - 29)):((long) (A) << (29 - GLOBAL_Q)))
#define   _IQ29toIQ(A)  ((GLOBAL_Q >= 29) ? ((long) (A) << (GLOBAL_Q - 29)):((long) (A) >> (29 - GLOBAL_Q)))

#define   _IQtoIQ28(A)  ((GLOBAL_Q >= 28) ? ((long) (A) >> (GLOBAL_Q - 28)):((long) (A) << (28 - GLOBAL_Q)))
#define   _IQ28toIQ(A)  ((GLOBAL_Q >= 28) ? ((long) (A) << (GLOBAL_Q - 28)):((long) (A) >> (28 - GLOBAL_Q)))

#define   _IQtoIQ27(A)  ((GLOBAL_Q >= 27) ? ((long) (A) >> (GLOBAL_Q - 27)):((long) (A) << (27 - GLOBAL_Q)))
#define   _IQ27toIQ(A)  ((GLOBAL_Q >= 27) ? ((long) (A) << (GLOBAL_Q - 27)):((long) (A) >> (27 - GLOBAL_Q)))

#define   _IQtoIQ26(A)  ((GLOBAL_Q >= 26) ? ((long) (A) >> (GLOBAL_Q - 26)):((long) (A) << (26 - GLOBAL_Q)))
#define   _IQ26toIQ(A)  ((GLOBAL_Q >= 26) ? ((long) (A) << (GLOBAL_Q - 26)):((long) (A) >> (26 - GLOBAL_Q)))

#define   _IQtoIQ25(A)  ((GLOBAL_Q >= 25) ? ((long) (A) >> (GLOBAL_Q - 25)):((long) (A) << (25 - GLOBAL_Q)))
#define   _IQ25toIQ(A)  ((GLOBAL_Q >= 25) ? ((long) (A) << (GLOBAL_Q - 25)):((long) (A) >> (25 - GLOBAL_Q)))

#define   _IQtoIQ24(A)  ((GLOBAL_Q >= 24) ? ((long) (A) >> (GLOBAL_Q - 24)):((long) (A) << (24 - GLOBAL_Q)))
#define   _IQ24toIQ(A)  ((GLOBAL_Q >= 24) ? ((long) (A) << (GLOBAL_Q - 24)):((long) (A) >> (24 - GLOBAL_Q)))

#define   _IQtoIQ23(A)  ((GLOBAL_Q >= 23) ? ((long) (A) >> (GLOBAL_Q - 23)):((long) (A) << (23 - GLOBAL_Q)))
#define   _IQ23toIQ(A)  ((GLOBAL_Q >= 23) ? ((long) (A) << (GLOBAL_Q - 23)):((long) (A) >> (23 - GLOBAL_Q)))

#define   _IQtoIQ22(A)  ((GLOBAL_Q >= 22) ? ((long) (A) >> (GLOBAL_Q - 22)):((long) (A) << (22 - GLOBAL_Q)))
#define   _IQ22toIQ(A)  ((GLOBAL_Q >= 22) ? ((long) (A) << (GLOBAL_Q - 22)):((long) (A) >> (22 - GLOBAL_Q)))

#define   _IQtoIQ21(A)  ((GLOBAL_Q >= 21) ? ((long) (A) >> (GLOBAL_Q - 21)):((long) (A) << (21 - GLOBAL_Q)))
#define   _IQ21toIQ(A)  ((GLOBAL_Q >= 21) ? ((long) (A) << (GLOBAL_Q - 21)):((long) (A) >> (21 - GLOBAL_Q)))

#define   _IQtoIQ20(A)  ((GLOBAL_Q >= 20) ? ((long) (A) >> (GLOBAL_Q - 20)):((long) (A) << (20 - GLOBAL_Q)))
#define   _IQ20toIQ(A)  ((GLOBAL_Q >= 20) ? ((long) (A) << (GLOBAL_Q - 20)):((long) (A) >> (20 - GLOBAL_Q)))

#define   _IQtoIQ19(A)  ((GLOBAL_Q >= 19) ? ((long) (A) >> (GLOBAL_Q - 19)):((long) (A) << (19 - GLOBAL_Q)))
#define   _IQ19toIQ(A)  ((GLOBAL_Q >= 19) ? ((long) (A) << (GLOBAL_Q - 19)):((long) (A) >> (19 - GLOBAL_Q)))

#define   _IQtoIQ18(A)  ((GLOBAL_Q >= 18) ? ((long) (A) >> (GLOBAL_Q - 18)):((long) (A) << (18 - GLOBAL_Q)))
#define   _IQ18toIQ(A)  ((GLOBAL_Q >= 18) ? ((long) (A) << (GLOBAL_Q - 18)):((long) (A) >> (18 - GLOBAL_Q)))

#define   _IQtoIQ17(A)  ((GLOBAL_Q >= 17) ? ((long) (A) >> (GLOBAL_Q - 17)):((long) (A) << (17 - GLOBAL_Q)))
#define   _IQ17toIQ(A)  ((GLOBAL_Q >= 17) ? ((long) (A) << (GLOBAL_Q - 17)):((long) (A) >> (17 - GLOBAL_Q)))

#define   _IQtoIQ16(A)  ((GLOBAL_Q >= 16) ? ((long) (A) >> (GLOBAL_Q - 16)):((long) (A) << (16 - GLOBAL_Q)))
#define   _IQ16toIQ(A)  ((GLOBAL_Q >= 16) ? ((long) (A) << (GLOBAL_Q - 16)):((long) (A) >> (16 - GLOBAL_Q)))

#define   _IQtoIQ15(A)  ((GLOBAL_Q >= 15) ? ((long) (A) >> (GLOBAL_Q - 15)):((long) (A) << (15 - GLOBAL_Q)))
#define   _IQ15toIQ(A)  ((GLOBAL_Q >= 15) ? ((long) (A) << (GLOBAL_Q - 15)):((long) (A) >> (15 - GLOBAL_Q)))

#define   _IQtoIQ14(A)  ((GLOBAL_Q >= 14) ? ((long) (A) >> (GLOBAL_Q - 14)):((long) (A) << (14 - GLOBAL_Q)))
#define   _IQ14toIQ(A)  ((GLOBAL_Q >= 14) ? ((long) (A) << (GLOBAL_Q - 14)):((long) (A) >> (14 - GLOBAL_Q)))

#define   _IQtoIQ13(A)  ((GLOBAL_Q >= 13) ? ((long) (A) >> (GLOBAL_Q - 13)):((long) (A) << (13 - GLOBAL_Q)))
#define   _IQ13toIQ(A)  ((GLOBAL_Q >= 13) ? ((long) (A) << (GLOBAL_Q - 13)):((long) (A) >> (13 - GLOBAL_Q)))

#define   _IQtoIQ12(A)  ((GLOBAL_Q >= 12) ? ((long) (A) >> (GLOBAL_Q - 12)):((long) (A) << (12 - GLOBAL_Q)))
#define   _IQ12toIQ(A)  ((GLOBAL_Q >= 12) ? ((long) (A) << (GLOBAL_Q - 12)):((long) (A) >> (12 - GLOBAL_Q)))

#define   _IQtoIQ11(A)  ((GLOBAL_Q >= 11) ? ((long) (A) >> (GLOBAL_Q - 11)):((long) (A) << (11 - GLOBAL_Q)))
#define   _IQ11toIQ(A)  ((GLOBAL_Q >= 11) ? ((long) (A) << (GLOBAL_Q - 11)):((long) (A) >> (11 - GLOBAL_Q)))

#define   _IQtoIQ10(A)  ((GLOBAL_Q >= 10) ? ((long) (A) >> (GLOBAL_Q - 10)):((long) (A) << (10 - GLOBAL_Q)))
#define   _IQ10toIQ(A)  ((GLOBAL_Q >= 10) ? ((long) (A) << (GLOBAL_Q - 10)):((long) (A) >> (10 - GLOBAL_Q)))

#define   _IQtoIQ9(A)   ((GLOBAL_Q >= 9) ? ((long) (A) >> (GLOBAL_Q - 9)):((long) (A) << (9 - GLOBAL_Q)))
#define   _IQ9toIQ(A)   ((GLOBAL_Q >= 9) ? ((long) (A) << (GLOBAL_Q - 9)):((long) (A) >> (9 - GLOBAL_Q)))

#define   _IQtoIQ8(A)   ((GLOBAL_Q >= 8) ? ((long) (A) >> (GLOBAL_Q - 8)):((long) (A) << (8 - GLOBAL_Q)))
#define   _IQ8toIQ(A)   ((GLOBAL_Q >= 8) ? ((long) (A) << (GLOBAL_Q - 8)):((long) (A) >> (8 - GLOBAL_Q)))

#define   _IQtoIQ7(A)   ((GLOBAL_Q >= 7) ? ((long) (A) >> (GLOBAL_Q - 7)):((long) (A) << (7 - GLOBAL_Q)))
#define   _IQ7toIQ(A)   ((GLOBAL_Q >= 7) ? ((long) (A) << (GLOBAL_Q - 7)):((long) (A) >> (7 - GLOBAL_Q)))

#define   _IQtoIQ6(A)   ((GLOBAL_Q >= 6) ? ((long) (A) >> (GLOBAL_Q - 6)):((long) (A) << (6 - GLOBAL_Q)))
#define   _IQ6toIQ(A)   ((GLOBAL_Q >= 6) ? ((long) (A) << (GLOBAL_Q - 6)):((long) (A) >> (6 - GLOBAL_Q)))

#define   _IQtoIQ5(A)   ((GLOBAL_Q >= 5) ? ((long) (A) >> (GLOBAL_Q - 5)):((long) (A) << (5 - GLOBAL_Q)))
#define   _IQ5toIQ(A)   ((GLOBAL_Q >= 5) ? ((long) (A) << (GLOBAL_Q - 5)):((long) (A) >> (5 - GLOBAL_Q)))

#define   _IQtoIQ4(A)   ((GLOBAL_Q >= 4) ? ((long) (A) >> (GLOBAL_Q - 4)):((long) (A) << (4 - GLOBAL_Q)))
#define   _IQ4toIQ(A)   ((GLOBAL_Q >= 4) ? ((long) (A) << (GLOBAL_Q - 4)):((long) (A) >> (4 - GLOBAL_Q)))

#define   _IQtoIQ3(A)   ((GLOBAL_Q >= 3) ? ((long) (A) >> (GLOBAL_Q - 3)):((long) (A) << (3 - GLOBAL_Q)))
#define   _IQ3toIQ(A)   ((GLOBAL_Q >= 3) ? ((long) (A) << (GLOBAL_Q - 3)):((long) (A) >> (3 - GLOBAL_Q)))

#define   _IQtoIQ2(A)   ((GLOBAL_Q >= 2) ? ((long) (A) >> (GLOBAL_Q - 2)):((long) (A) << (2 - GLOBAL_Q)))
#define   _IQ2toIQ(A)   ((GLOBAL_Q >= 2) ? ((long) (A) << (GLOBAL_Q - 2)):((long) (A) >> (2 - GLOBAL_Q)))

#define   _IQtoIQ1(A)   ((long) (A) >> (GLOBAL_Q - 1))
#define   _IQ1toIQ(A)   ((long) (A) << (GLOBAL_Q - 1))
//---------------------------------------------------------------------------
#define   _IQtoQ15(A)   ((GLOBAL_Q >= 15) ? ((long) (A) >> (GLOBAL_Q - 15)):((long) (A) << (15 - GLOBAL_Q)))
#define   _Q15toIQ(A)   ((GLOBAL_Q >= 15) ? ((long) (A) << (GLOBAL_Q - 15)):((long) (A) >> (15 - GLOBAL_Q)))

#define   _IQtoQ14(A)   ((GLOBAL_Q >= 14) ? ((long) (A) >> (GLOBAL_Q - 14)):((long) (A) << (14 - GLOBAL_Q)))
#define   _Q14toIQ(A)   ((GLOBAL_Q >= 14) ? ((long) (A) << (GLOBAL_Q - 14)):((long) (A) >> (14 - GLOBAL_Q)))

#define   _IQtoQ13(A)   ((GLOBAL_Q >= 13) ? ((long) (A) >> (GLOBAL_Q - 13)):((long) (A) << (13 - GLOBAL_Q)))
#define   _Q13toIQ(A)   ((GLOBAL_Q >= 13) ? ((long) (A) << (GLOBAL_Q - 13)):((long) (A) >> (13 - GLOBAL_Q)))

#define   _IQtoQ12(A)   ((GLOBAL_Q >= 12) ? ((long) (A) >> (GLOBAL_Q - 12)):((long) (A) << (12 - GLOBAL_Q)))
#define   _Q12toIQ(A)   ((GLOBAL_Q >= 12) ? ((long) (A) << (GLOBAL_Q - 12)):((long) (A) >> (12 - GLOBAL_Q)))

#define   _IQtoQ11(A)   ((GLOBAL_Q >= 11) ? ((long) (A) >> (GLOBAL_Q - 11)):((long) (A) << (11 - GLOBAL_Q)))
#define   _Q11toIQ(A)   ((GLOBAL_Q >= 11) ? ((long) (A) << (GLOBAL_Q - 11)):((long) (A) >> (11 - GLOBAL_Q)))

#define   _IQtoQ10(A)   ((GLOBAL_Q >= 10) ? ((long) (A) >> (GLOBAL_Q - 10)):((long) (A) << (10 - GLOBAL_Q)))
#define   _Q10toIQ(A)   ((GLOBAL_Q >= 10) ? ((long) (A) << (GLOBAL_Q - 10)):((long) (A) >> (10 - GLOBAL_Q)))

#define   _IQtoQ9(A)    ((GLOBAL_Q >= 9) ? ((long) (A) >> (GLOBAL_Q - 9)):((long) (A) << (9 - GLOBAL_Q)))
#define   _Q9toIQ(A)    ((GLOBAL_Q >= 9) ? ((long) (A) << (GLOBAL_Q - 9)):((long) (A) >> (9 - GLOBAL_Q)))

#define   _IQtoQ8(A)    ((GLOBAL_Q >= 8) ? ((long) (A) >> (GLOBAL_Q - 8)):((long) (A) << (8 - GLOBAL_Q)))
#define   _Q8toIQ(A)    ((GLOBAL_Q >= 8) ? ((long) (A) << (GLOBAL_Q - 8)):((long) (A) >> (8 - GLOBAL_Q)))

#define   _IQtoQ7(A)    ((GLOBAL_Q >= 7) ? ((long) (A) >> (GLOBAL_Q - 7)):((long) (A) << (7 - GLOBAL_Q)))
#define   _Q7toIQ(A)    ((GLOBAL_Q >= 7) ? ((long) (A) << (GLOBAL_Q - 7)):((long) (A) >> (7 - GLOBAL_Q)))

#define   _IQtoQ6(A)    ((GLOBAL_Q >= 6) ? ((long) (A) >> (GLOBAL_Q - 6)):((long) (A) << (6 - GLOBAL_Q)))
#define   _Q6toIQ(A)    ((GLOBAL_Q >= 6) ? ((long) (A) << (GLOBAL_Q - 6)):((long) (A) >> (6 - GLOBAL_Q)))

#define   _IQtoQ5(A)    ((GLOBAL_Q >= 5) ? ((long) (A) >> (GLOBAL_Q - 5)):((long) (A) << (5 - GLOBAL_Q)))
#define   _Q5toIQ(A)    ((GLOBAL_Q >= 5) ? ((long) (A) << (GLOBAL_Q - 5)):((long) (A) >> (5 - GLOBAL_Q)))

#define   _IQtoQ5(A)    ((GLOBAL_Q >= 5) ? ((long) (A) >> (GLOBAL_Q - 5)):((long) (A) << (5 - GLOBAL_Q)))
#define   _Q5toIQ(A)    ((GLOBAL_Q >= 5) ? ((long) (A) << (GLOBAL_Q - 5)):((long) (A) >> (5 - GLOBAL_Q)))

#define   _IQtoQ4(A)    ((GLOBAL_Q >= 4) ? ((long) (A) >> (GLOBAL_Q - 4)):((long) (A) << (4 - GLOBAL_Q)))
#define   _Q4toIQ(A)    ((GLOBAL_Q >= 4) ? ((long) (A) << (GLOBAL_Q - 4)):((long) (A) >> (4 - GLOBAL_Q)))

#define   _IQtoQ3(A)    ((GLOBAL_Q >= 3) ? ((long) (A) >> (GLOBAL_Q - 3)):((long) (A) << (3 - GLOBAL_Q)))
#define   _Q3toIQ(A)    ((GLOBAL_Q >= 3) ? ((long) (A) << (GLOBAL_Q - 3)):((long) (A) >> (3 - GLOBAL_Q)))

#define   _IQtoQ2(A)    ((GLOBAL_Q >= 2) ? ((long) (A) >> (GLOBAL_Q - 2)):((long) (A) << (2 - GLOBAL_Q)))
#define   _Q2toIQ(A)    ((GLOBAL_Q >= 2) ? ((long) (A) << (GLOBAL_Q - 2)):((long) (A) >> (2 - GLOBAL_Q)))

#define   _IQtoQ1(A)    ((GLOBAL_Q >= 1) ? ((long) (A) >> (GLOBAL_Q - 1)):((long) (A) << (1 - GLOBAL_Q)))
#define   _Q1toIQ(A)    ((GLOBAL_Q >= 1) ? ((long) (A) << (GLOBAL_Q - 1)):((long) (A) >> (1 - GLOBAL_Q)))
//---------------------------------------------------------------------------
#define   _IQmpy(A,B)    __IQmpy(A,B,GLOBAL_Q)
#define   _IQ30mpy(A,B)  __IQmpy(A,B,30)
#define   _IQ29mpy(A,B)  __IQmpy(A,B,29)
#define   _IQ28mpy(A,B)  __IQmpy(A,B,28)
#define   _IQ27mpy(A,B)  __IQmpy(A,B,27)
#define   _IQ26mpy(A,B)  __IQmpy(A,B,26)
#define   _IQ25mpy(A,B)  __IQmpy(A,B,25)
#define   _IQ24mpy(A,B)  __IQmpy(A,B,24)
#define   _IQ23mpy(A,B)  __IQmpy(A,B,23)
#define   _IQ22mpy(A,B)  __IQmpy(A,B,22)
#define   _IQ21mpy(A,B)  __IQmpy(A,B,21)
#define   _IQ20mpy(A,B)  __IQmpy(A,B,20)
#define   _IQ19mpy(A,B)  __IQmpy(A,B,19)
#define   _IQ18mpy(A,B)  __IQmpy(A,B,18)
#define   _IQ17mpy(A,B)  __IQmpy(A,B,17)
#define   _IQ16mpy(A,B)  __IQmpy(A,B,16)
#define   _IQ15mpy(A,B)  __IQmpy(A,B,15)
#define   _IQ14mpy(A,B)  __IQmpy(A,B,14)
#define   _IQ13mpy(A,B)  __IQmpy(A,B,13)
#define   _IQ12mpy(A,B)  __IQmpy(A,B,12)
#define   _IQ11mpy(A,B)  __IQmpy(A,B,11)
#define   _IQ10mpy(A,B)  __IQmpy(A,B,10)
#define   _IQ9mpy(A,B)   __IQmpy(A,B,9)
#define   _IQ8mpy(A,B)   __IQmpy(A,B,8)
#define   _IQ7mpy(A,B)   __IQmpy(A,B,7)
#define   _IQ6mpy(A,B)   __IQmpy(A,B,6)
#define   _IQ5mpy(A,B)   __IQmpy(A,B,5)
#define   _IQ4mpy(A,B)   __IQmpy(A,B,4)
#define   _IQ3mpy(A,B)   __IQmpy(A,B,3)
#define   _IQ2mpy(A,B)   __IQmpy(A,B,2)
#define   _IQ1mpy(A,B)   __IQmpy(A,B,1)
//---------------------------------------------------------------------------
extern    long _IQ30rmpy(long A, long B);
extern    long _IQ29rmpy(long A, long B);
extern    long _IQ28rmpy(long A, long B);
extern    long _IQ27rmpy(long A, long B);
extern    long _IQ26rmpy(long A, long B);
extern    long _IQ25rmpy(long A, long B);
extern    long _IQ24rmpy(long A, long B);
extern    long _IQ23rmpy(long A, long B);
extern    long _IQ22rmpy(long A, long B);
extern    long _IQ21rmpy(long A, long B);
extern    long _IQ20rmpy(long A, long B);
extern    long _IQ19rmpy(long A, long B);
extern    long _IQ18rmpy(long A, long B);
extern    long _IQ17rmpy(long A, long B);
extern    long _IQ16rmpy(long A, long B);
extern    long _IQ15rmpy(long A, long B);
extern    long _IQ14rmpy(long A, long B);
extern    long _IQ13rmpy(long A, long B);
extern    long _IQ12rmpy(long A, long B);
extern    long _IQ11rmpy(long A, long B);
extern    long _IQ10rmpy(long A, long B);
extern    long _IQ9rmpy(long A, long B);
extern    long _IQ8rmpy(long A, long B);
extern    long _IQ7rmpy(long A, long B);
extern    long _IQ6rmpy(long A, long B);
extern    long _IQ5rmpy(long A, long B);
extern    long _IQ4rmpy(long A, long B);
extern    long _IQ3rmpy(long A, long B);
extern    long _IQ2rmpy(long A, long B);
extern    long _IQ1rmpy(long A, long B);

#if GLOBAL_Q == 30
#define   _IQrmpy(A,B)  _IQ30rmpy(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQrmpy(A,B)  _IQ29rmpy(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQrmpy(A,B)  _IQ28rmpy(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQrmpy(A,B)  _IQ27rmpy(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQrmpy(A,B)  _IQ26rmpy(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQrmpy(A,B)  _IQ25rmpy(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQrmpy(A,B)  _IQ24rmpy(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQrmpy(A,B)  _IQ23rmpy(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQrmpy(A,B)  _IQ22rmpy(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQrmpy(A,B)  _IQ21rmpy(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQrmpy(A,B)  _IQ20rmpy(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQrmpy(A,B)  _IQ19rmpy(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQrmpy(A,B)  _IQ18rmpy(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQrmpy(A,B)  _IQ17rmpy(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQrmpy(A,B)  _IQ16rmpy(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQrmpy(A,B)  _IQ15rmpy(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQrmpy(A,B)  _IQ14rmpy(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQrmpy(A,B)  _IQ13rmpy(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQrmpy(A,B)  _IQ12rmpy(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQrmpy(A,B)  _IQ11rmpy(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQrmpy(A,B)  _IQ10rmpy(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQrmpy(A,B)  _IQ9rmpy(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQrmpy(A,B)  _IQ8rmpy(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQrmpy(A,B)  _IQ7rmpy(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQrmpy(A,B)  _IQ6rmpy(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQrmpy(A,B)  _IQ5rmpy(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQrmpy(A,B)  _IQ4rmpy(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQrmpy(A,B)  _IQ3rmpy(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQrmpy(A,B)  _IQ2rmpy(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQrmpy(A,B)  _IQ1rmpy(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30rsmpy(long A, long B);
extern    long _IQ29rsmpy(long A, long B);
extern    long _IQ28rsmpy(long A, long B);
extern    long _IQ27rsmpy(long A, long B);
extern    long _IQ26rsmpy(long A, long B);
extern    long _IQ25rsmpy(long A, long B);
extern    long _IQ24rsmpy(long A, long B);
extern    long _IQ23rsmpy(long A, long B);
extern    long _IQ22rsmpy(long A, long B);
extern    long _IQ21rsmpy(long A, long B);
extern    long _IQ20rsmpy(long A, long B);
extern    long _IQ19rsmpy(long A, long B);
extern    long _IQ18rsmpy(long A, long B);
extern    long _IQ17rsmpy(long A, long B);
extern    long _IQ16rsmpy(long A, long B);
extern    long _IQ15rsmpy(long A, long B);
extern    long _IQ14rsmpy(long A, long B);
extern    long _IQ13rsmpy(long A, long B);
extern    long _IQ12rsmpy(long A, long B);
extern    long _IQ11rsmpy(long A, long B);
extern    long _IQ10rsmpy(long A, long B);
extern    long _IQ9rsmpy(long A, long B);
extern    long _IQ8rsmpy(long A, long B);
extern    long _IQ7rsmpy(long A, long B);
extern    long _IQ6rsmpy(long A, long B);
extern    long _IQ5rsmpy(long A, long B);
extern    long _IQ4rsmpy(long A, long B);
extern    long _IQ3rsmpy(long A, long B);
extern    long _IQ2rsmpy(long A, long B);
extern    long _IQ1rsmpy(long A, long B);

#if GLOBAL_Q == 30
#define   _IQrsmpy(A,B)  _IQ30rsmpy(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQrsmpy(A,B)  _IQ29rsmpy(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQrsmpy(A,B)  _IQ28rsmpy(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQrsmpy(A,B)  _IQ27rsmpy(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQrsmpy(A,B)  _IQ26rsmpy(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQrsmpy(A,B)  _IQ25rsmpy(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQrsmpy(A,B)  _IQ24rsmpy(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQrsmpy(A,B)  _IQ23rsmpy(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQrsmpy(A,B)  _IQ22rsmpy(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQrsmpy(A,B)  _IQ21rsmpy(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQrsmpy(A,B)  _IQ20rsmpy(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQrsmpy(A,B)  _IQ19rsmpy(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQrsmpy(A,B)  _IQ18rsmpy(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQrsmpy(A,B)  _IQ17rsmpy(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQrsmpy(A,B)  _IQ16rsmpy(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQrsmpy(A,B)  _IQ15rsmpy(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQrsmpy(A,B)  _IQ14rsmpy(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQrsmpy(A,B)  _IQ13rsmpy(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQrsmpy(A,B)  _IQ12rsmpy(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQrsmpy(A,B)  _IQ11rsmpy(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQrsmpy(A,B)  _IQ10rsmpy(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQrsmpy(A,B)  _IQ9rsmpy(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQrsmpy(A,B)  _IQ8rsmpy(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQrsmpy(A,B)  _IQ7rsmpy(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQrsmpy(A,B)  _IQ6rsmpy(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQrsmpy(A,B)  _IQ5rsmpy(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQrsmpy(A,B)  _IQ4rsmpy(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQrsmpy(A,B)  _IQ3rsmpy(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQrsmpy(A,B)  _IQ2rsmpy(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQrsmpy(A,B)  _IQ1rsmpy(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30div(long A, long B);
extern    long _IQ29div(long A, long B);
extern    long _IQ28div(long A, long B);
extern    long _IQ27div(long A, long B);
extern    long _IQ26div(long A, long B);
extern    long _IQ25div(long A, long B);
extern    long _IQ24div(long A, long B);
extern    long _IQ23div(long A, long B);
extern    long _IQ22div(long A, long B);
extern    long _IQ21div(long A, long B);
extern    long _IQ20div(long A, long B);
extern    long _IQ19div(long A, long B);
extern    long _IQ18div(long A, long B);
extern    long _IQ17div(long A, long B);
extern    long _IQ16div(long A, long B);
extern    long _IQ15div(long A, long B);
extern    long _IQ14div(long A, long B);
extern    long _IQ13div(long A, long B);
extern    long _IQ12div(long A, long B);
extern    long _IQ11div(long A, long B);
extern    long _IQ10div(long A, long B);
extern    long _IQ9div(long A, long B);
extern    long _IQ8div(long A, long B);
extern    long _IQ7div(long A, long B);
extern    long _IQ6div(long A, long B);
extern    long _IQ5div(long A, long B);
extern    long _IQ4div(long A, long B);
extern    long _IQ3div(long A, long B);
extern    long _IQ2div(long A, long B);
extern    long _IQ1div(long A, long B);

#if GLOBAL_Q == 30
#define   _IQdiv(A,B)  _IQ30div(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQdiv(A,B)  _IQ29div(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQdiv(A,B)  _IQ28div(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQdiv(A,B)  _IQ27div(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQdiv(A,B)  _IQ26div(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQdiv(A,B)  _IQ25div(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQdiv(A,B)  _IQ24div(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQdiv(A,B)  _IQ23div(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQdiv(A,B)  _IQ22div(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQdiv(A,B)  _IQ21div(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQdiv(A,B)  _IQ20div(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQdiv(A,B)  _IQ19div(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQdiv(A,B)  _IQ18div(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQdiv(A,B)  _IQ17div(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQdiv(A,B)  _IQ16div(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQdiv(A,B)  _IQ15div(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQdiv(A,B)  _IQ14div(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQdiv(A,B)  _IQ13div(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQdiv(A,B)  _IQ12div(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQdiv(A,B)  _IQ11div(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQdiv(A,B)  _IQ10div(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQdiv(A,B)  _IQ9div(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQdiv(A,B)  _IQ8div(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQdiv(A,B)  _IQ7div(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQdiv(A,B)  _IQ6div(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQdiv(A,B)  _IQ5div(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQdiv(A,B)  _IQ4div(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQdiv(A,B)  _IQ3div(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQdiv(A,B)  _IQ2div(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQdiv(A,B)  _IQ1div(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30sin(long A);
extern    long _IQ29sin(long A);
extern    long _IQ28sin(long A);
extern    long _IQ27sin(long A);
extern    long _IQ26sin(long A);
extern    long _IQ25sin(long A);
extern    long _IQ24sin(long A);
extern    long _IQ23sin(long A);
extern    long _IQ22sin(long A);
extern    long _IQ21sin(long A);
extern    long _IQ20sin(long A);
extern    long _IQ19sin(long A);
extern    long _IQ18sin(long A);
extern    long _IQ17sin(long A);
extern    long _IQ16sin(long A);
extern    long _IQ15sin(long A);
extern    long _IQ14sin(long A);
extern    long _IQ13sin(long A);
extern    long _IQ12sin(long A);
extern    long _IQ11sin(long A);
extern    long _IQ10sin(long A);
extern    long _IQ9sin(long A);
extern    long _IQ8sin(long A);
extern    long _IQ7sin(long A);
extern    long _IQ6sin(long A);
extern    long _IQ5sin(long A);
extern    long _IQ4sin(long A);
extern    long _IQ3sin(long A);
extern    long _IQ2sin(long A);
extern    long _IQ1sin(long A);

#if GLOBAL_Q == 30
#define   _IQsin(A)  _IQ30sin(A)
#endif
#if GLOBAL_Q == 29
#define   _IQsin(A)  _IQ29sin(A)
#endif
#if GLOBAL_Q == 28
#define   _IQsin(A)  _IQ28sin(A)
#endif
#if GLOBAL_Q == 27
#define   _IQsin(A)  _IQ27sin(A)
#endif
#if GLOBAL_Q == 26
#define   _IQsin(A)  _IQ26sin(A)
#endif
#if GLOBAL_Q == 25
#define   _IQsin(A)  _IQ25sin(A)
#endif
#if GLOBAL_Q == 24
#define   _IQsin(A)  _IQ24sin(A)
#endif
#if GLOBAL_Q == 23
#define   _IQsin(A)  _IQ23sin(A)
#endif
#if GLOBAL_Q == 22
#define   _IQsin(A)  _IQ22sin(A)
#endif
#if GLOBAL_Q == 21
#define   _IQsin(A)  _IQ21sin(A)
#endif
#if GLOBAL_Q == 20
#define   _IQsin(A)  _IQ20sin(A)
#endif
#if GLOBAL_Q == 19
#define   _IQsin(A)  _IQ19sin(A)
#endif
#if GLOBAL_Q == 18
#define   _IQsin(A)  _IQ18sin(A)
#endif
#if GLOBAL_Q == 17
#define   _IQsin(A)  _IQ17sin(A)
#endif
#if GLOBAL_Q == 16
#define   _IQsin(A)  _IQ16sin(A)
#endif
#if GLOBAL_Q == 15
#define   _IQsin(A)  _IQ15sin(A)
#endif
#if GLOBAL_Q == 14
#define   _IQsin(A)  _IQ14sin(A)
#endif
#if GLOBAL_Q == 13
#define   _IQsin(A)  _IQ13sin(A)
#endif
#if GLOBAL_Q == 12
#define   _IQsin(A)  _IQ12sin(A)
#endif
#if GLOBAL_Q == 11
#define   _IQsin(A)  _IQ11sin(A)
#endif
#if GLOBAL_Q == 10
#define   _IQsin(A)  _IQ10sin(A)
#endif
#if GLOBAL_Q == 9
#define   _IQsin(A)  _IQ9sin(A)
#endif
#if GLOBAL_Q == 8
#define   _IQsin(A)  _IQ8sin(A)
#endif
#if GLOBAL_Q == 7
#define   _IQsin(A)  _IQ7sin(A)
#endif
#if GLOBAL_Q == 6
#define   _IQsin(A)  _IQ6sin(A)
#endif
#if GLOBAL_Q == 5
#define   _IQsin(A)  _IQ5sin(A)
#endif
#if GLOBAL_Q == 4
#define   _IQsin(A)  _IQ4sin(A)
#endif
#if GLOBAL_Q == 3
#define   _IQsin(A)  _IQ3sin(A)
#endif
#if GLOBAL_Q == 2
#define   _IQsin(A)  _IQ2sin(A)
#endif
#if GLOBAL_Q == 1
#define   _IQsin(A)  _IQ1sin(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30sinPU(long A);
extern    long _IQ29sinPU(long A);
extern    long _IQ28sinPU(long A);
extern    long _IQ27sinPU(long A);
extern    long _IQ26sinPU(long A);
extern    long _IQ25sinPU(long A);
extern    long _IQ24sinPU(long A);
extern    long _IQ23sinPU(long A);
extern    long _IQ22sinPU(long A);
extern    long _IQ21sinPU(long A);
extern    long _IQ20sinPU(long A);
extern    long _IQ19sinPU(long A);
extern    long _IQ18sinPU(long A);
extern    long _IQ17sinPU(long A);
extern    long _IQ16sinPU(long A);
extern    long _IQ15sinPU(long A);
extern    long _IQ14sinPU(long A);
extern    long _IQ13sinPU(long A);
extern    long _IQ12sinPU(long A);
extern    long _IQ11sinPU(long A);
extern    long _IQ10sinPU(long A);
extern    long _IQ9sinPU(long A);
extern    long _IQ8sinPU(long A);
extern    long _IQ7sinPU(long A);
extern    long _IQ6sinPU(long A);
extern    long _IQ5sinPU(long A);
extern    long _IQ4sinPU(long A);
extern    long _IQ3sinPU(long A);
extern    long _IQ2sinPU(long A);
extern    long _IQ1sinPU(long A);

#if GLOBAL_Q == 30
#define   _IQsinPU(A)  _IQ30sinPU(A)
#endif
#if GLOBAL_Q == 29
#define   _IQsinPU(A)  _IQ29sinPU(A)
#endif
#if GLOBAL_Q == 28
#define   _IQsinPU(A)  _IQ28sinPU(A)
#endif
#if GLOBAL_Q == 27
#define   _IQsinPU(A)  _IQ27sinPU(A)
#endif
#if GLOBAL_Q == 26
#define   _IQsinPU(A)  _IQ26sinPU(A)
#endif
#if GLOBAL_Q == 25
#define   _IQsinPU(A)  _IQ25sinPU(A)
#endif
#if GLOBAL_Q == 24
#define   _IQsinPU(A)  _IQ24sinPU(A)
#endif
#if GLOBAL_Q == 23
#define   _IQsinPU(A)  _IQ23sinPU(A)
#endif
#if GLOBAL_Q == 22
#define   _IQsinPU(A)  _IQ22sinPU(A)
#endif
#if GLOBAL_Q == 21
#define   _IQsinPU(A)  _IQ21sinPU(A)
#endif
#if GLOBAL_Q == 20
#define   _IQsinPU(A)  _IQ20sinPU(A)
#endif
#if GLOBAL_Q == 19
#define   _IQsinPU(A)  _IQ19sinPU(A)
#endif
#if GLOBAL_Q == 18
#define   _IQsinPU(A)  _IQ18sinPU(A)
#endif
#if GLOBAL_Q == 17
#define   _IQsinPU(A)  _IQ17sinPU(A)
#endif
#if GLOBAL_Q == 16
#define   _IQsinPU(A)  _IQ16sinPU(A)
#endif
#if GLOBAL_Q == 15
#define   _IQsinPU(A)  _IQ15sinPU(A)
#endif
#if GLOBAL_Q == 14
#define   _IQsinPU(A)  _IQ14sinPU(A)
#endif
#if GLOBAL_Q == 13
#define   _IQsinPU(A)  _IQ13sinPU(A)
#endif
#if GLOBAL_Q == 12
#define   _IQsinPU(A)  _IQ12sinPU(A)
#endif
#if GLOBAL_Q == 11
#define   _IQsinPU(A)  _IQ11sinPU(A)
#endif
#if GLOBAL_Q == 10
#define   _IQsinPU(A)  _IQ10sinPU(A)
#endif
#if GLOBAL_Q == 9
#define   _IQsinPU(A)  _IQ9sinPU(A)
#endif
#if GLOBAL_Q == 8
#define   _IQsinPU(A)  _IQ8sinPU(A)
#endif
#if GLOBAL_Q == 7
#define   _IQsinPU(A)  _IQ7sinPU(A)
#endif
#if GLOBAL_Q == 6
#define   _IQsinPU(A)  _IQ6sinPU(A)
#endif
#if GLOBAL_Q == 5
#define   _IQsinPU(A)  _IQ5sinPU(A)
#endif
#if GLOBAL_Q == 4
#define   _IQsinPU(A)  _IQ4sinPU(A)
#endif
#if GLOBAL_Q == 3
#define   _IQsinPU(A)  _IQ3sinPU(A)
#endif
#if GLOBAL_Q == 2
#define   _IQsinPU(A)  _IQ2sinPU(A)
#endif
#if GLOBAL_Q == 1
#define   _IQsinPU(A)  _IQ1sinPU(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30cos(long A);
extern    long _IQ29cos(long A);
extern    long _IQ28cos(long A);
extern    long _IQ27cos(long A);
extern    long _IQ26cos(long A);
extern    long _IQ25cos(long A);
extern    long _IQ24cos(long A);
extern    long _IQ23cos(long A);
extern    long _IQ22cos(long A);
extern    long _IQ21cos(long A);
extern    long _IQ20cos(long A);
extern    long _IQ19cos(long A);
extern    long _IQ18cos(long A);
extern    long _IQ17cos(long A);
extern    long _IQ16cos(long A);
extern    long _IQ15cos(long A);
extern    long _IQ14cos(long A);
extern    long _IQ13cos(long A);
extern    long _IQ12cos(long A);
extern    long _IQ11cos(long A);
extern    long _IQ10cos(long A);
extern    long _IQ9cos(long A);
extern    long _IQ8cos(long A);
extern    long _IQ7cos(long A);
extern    long _IQ6cos(long A);
extern    long _IQ5cos(long A);
extern    long _IQ4cos(long A);
extern    long _IQ3cos(long A);
extern    long _IQ2cos(long A);
extern    long _IQ1cos(long A);

#if GLOBAL_Q == 30
#define   _IQcos(A)  _IQ30cos(A)
#endif
#if GLOBAL_Q == 29
#define   _IQcos(A)  _IQ29cos(A)
#endif
#if GLOBAL_Q == 28
#define   _IQcos(A)  _IQ28cos(A)
#endif
#if GLOBAL_Q == 27
#define   _IQcos(A)  _IQ27cos(A)
#endif
#if GLOBAL_Q == 26
#define   _IQcos(A)  _IQ26cos(A)
#endif
#if GLOBAL_Q == 25
#define   _IQcos(A)  _IQ25cos(A)
#endif
#if GLOBAL_Q == 24
#define   _IQcos(A)  _IQ24cos(A)
#endif
#if GLOBAL_Q == 23
#define   _IQcos(A)  _IQ23cos(A)
#endif
#if GLOBAL_Q == 22
#define   _IQcos(A)  _IQ22cos(A)
#endif
#if GLOBAL_Q == 21
#define   _IQcos(A)  _IQ21cos(A)
#endif
#if GLOBAL_Q == 20
#define   _IQcos(A)  _IQ20cos(A)
#endif
#if GLOBAL_Q == 19
#define   _IQcos(A)  _IQ19cos(A)
#endif
#if GLOBAL_Q == 18
#define   _IQcos(A)  _IQ18cos(A)
#endif
#if GLOBAL_Q == 17
#define   _IQcos(A)  _IQ17cos(A)
#endif
#if GLOBAL_Q == 16
#define   _IQcos(A)  _IQ16cos(A)
#endif
#if GLOBAL_Q == 15
#define   _IQcos(A)  _IQ15cos(A)
#endif
#if GLOBAL_Q == 14
#define   _IQcos(A)  _IQ14cos(A)
#endif
#if GLOBAL_Q == 13
#define   _IQcos(A)  _IQ13cos(A)
#endif
#if GLOBAL_Q == 12
#define   _IQcos(A)  _IQ12cos(A)
#endif
#if GLOBAL_Q == 11
#define   _IQcos(A)  _IQ11cos(A)
#endif
#if GLOBAL_Q == 10
#define   _IQcos(A)  _IQ10cos(A)
#endif
#if GLOBAL_Q == 9
#define   _IQcos(A)  _IQ9cos(A)
#endif
#if GLOBAL_Q == 8
#define   _IQcos(A)  _IQ8cos(A)
#endif
#if GLOBAL_Q == 7
#define   _IQcos(A)  _IQ7cos(A)
#endif
#if GLOBAL_Q == 6
#define   _IQcos(A)  _IQ6cos(A)
#endif
#if GLOBAL_Q == 5
#define   _IQcos(A)  _IQ5cos(A)
#endif
#if GLOBAL_Q == 4
#define   _IQcos(A)  _IQ4cos(A)
#endif
#if GLOBAL_Q == 3
#define   _IQcos(A)  _IQ3cos(A)
#endif
#if GLOBAL_Q == 2
#define   _IQcos(A)  _IQ2cos(A)
#endif
#if GLOBAL_Q == 1
#define   _IQcos(A)  _IQ1cos(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30cosPU(long A);
extern    long _IQ29cosPU(long A);
extern    long _IQ28cosPU(long A);
extern    long _IQ27cosPU(long A);
extern    long _IQ26cosPU(long A);
extern    long _IQ25cosPU(long A);
extern    long _IQ24cosPU(long A);
extern    long _IQ23cosPU(long A);
extern    long _IQ22cosPU(long A);
extern    long _IQ21cosPU(long A);
extern    long _IQ20cosPU(long A);
extern    long _IQ19cosPU(long A);
extern    long _IQ18cosPU(long A);
extern    long _IQ17cosPU(long A);
extern    long _IQ16cosPU(long A);
extern    long _IQ15cosPU(long A);
extern    long _IQ14cosPU(long A);
extern    long _IQ13cosPU(long A);
extern    long _IQ12cosPU(long A);
extern    long _IQ11cosPU(long A);
extern    long _IQ10cosPU(long A);
extern    long _IQ9cosPU(long A);
extern    long _IQ8cosPU(long A);
extern    long _IQ7cosPU(long A);
extern    long _IQ6cosPU(long A);
extern    long _IQ5cosPU(long A);
extern    long _IQ4cosPU(long A);
extern    long _IQ3cosPU(long A);
extern    long _IQ2cosPU(long A);
extern    long _IQ1cosPU(long A);

#if GLOBAL_Q == 30
#define   _IQcosPU(A)  _IQ30cosPU(A)
#endif
#if GLOBAL_Q == 29
#define   _IQcosPU(A)  _IQ29cosPU(A)
#endif
#if GLOBAL_Q == 28
#define   _IQcosPU(A)  _IQ28cosPU(A)
#endif
#if GLOBAL_Q == 27
#define   _IQcosPU(A)  _IQ27cosPU(A)
#endif
#if GLOBAL_Q == 26
#define   _IQcosPU(A)  _IQ26cosPU(A)
#endif
#if GLOBAL_Q == 25
#define   _IQcosPU(A)  _IQ25cosPU(A)
#endif
#if GLOBAL_Q == 24
#define   _IQcosPU(A)  _IQ24cosPU(A)
#endif
#if GLOBAL_Q == 23
#define   _IQcosPU(A)  _IQ23cosPU(A)
#endif
#if GLOBAL_Q == 22
#define   _IQcosPU(A)  _IQ22cosPU(A)
#endif
#if GLOBAL_Q == 21
#define   _IQcosPU(A)  _IQ21cosPU(A)
#endif
#if GLOBAL_Q == 20
#define   _IQcosPU(A)  _IQ20cosPU(A)
#endif
#if GLOBAL_Q == 19
#define   _IQcosPU(A)  _IQ19cosPU(A)
#endif
#if GLOBAL_Q == 18
#define   _IQcosPU(A)  _IQ18cosPU(A)
#endif
#if GLOBAL_Q == 17
#define   _IQcosPU(A)  _IQ17cosPU(A)
#endif
#if GLOBAL_Q == 16
#define   _IQcosPU(A)  _IQ16cosPU(A)
#endif
#if GLOBAL_Q == 15
#define   _IQcosPU(A)  _IQ15cosPU(A)
#endif
#if GLOBAL_Q == 14
#define   _IQcosPU(A)  _IQ14cosPU(A)
#endif
#if GLOBAL_Q == 13
#define   _IQcosPU(A)  _IQ13cosPU(A)
#endif
#if GLOBAL_Q == 12
#define   _IQcosPU(A)  _IQ12cosPU(A)
#endif
#if GLOBAL_Q == 11
#define   _IQcosPU(A)  _IQ11cosPU(A)
#endif
#if GLOBAL_Q == 10
#define   _IQcosPU(A)  _IQ10cosPU(A)
#endif
#if GLOBAL_Q == 9
#define   _IQcosPU(A)  _IQ9cosPU(A)
#endif
#if GLOBAL_Q == 8
#define   _IQcosPU(A)  _IQ8cosPU(A)
#endif
#if GLOBAL_Q == 7
#define   _IQcosPU(A)  _IQ7cosPU(A)
#endif
#if GLOBAL_Q == 6
#define   _IQcosPU(A)  _IQ6cosPU(A)
#endif
#if GLOBAL_Q == 5
#define   _IQcosPU(A)  _IQ5cosPU(A)
#endif
#if GLOBAL_Q == 4
#define   _IQcosPU(A)  _IQ4cosPU(A)
#endif
#if GLOBAL_Q == 3
#define   _IQcosPU(A)  _IQ3cosPU(A)
#endif
#if GLOBAL_Q == 2
#define   _IQcosPU(A)  _IQ2cosPU(A)
#endif
#if GLOBAL_Q == 1
#define   _IQcosPU(A)  _IQ1cosPU(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30atan2(long A, long B);
extern    long _IQ29atan2(long A, long B);
extern    long _IQ28atan2(long A, long B);
extern    long _IQ27atan2(long A, long B);
extern    long _IQ26atan2(long A, long B);
extern    long _IQ25atan2(long A, long B);
extern    long _IQ24atan2(long A, long B);
extern    long _IQ23atan2(long A, long B);
extern    long _IQ22atan2(long A, long B);
extern    long _IQ21atan2(long A, long B);
extern    long _IQ20atan2(long A, long B);
extern    long _IQ19atan2(long A, long B);
extern    long _IQ18atan2(long A, long B);
extern    long _IQ17atan2(long A, long B);
extern    long _IQ16atan2(long A, long B);
extern    long _IQ15atan2(long A, long B);
extern    long _IQ14atan2(long A, long B);
extern    long _IQ13atan2(long A, long B);
extern    long _IQ12atan2(long A, long B);
extern    long _IQ11atan2(long A, long B);
extern    long _IQ10atan2(long A, long B);
extern    long _IQ9atan2(long A, long B);
extern    long _IQ8atan2(long A, long B);
extern    long _IQ7atan2(long A, long B);
extern    long _IQ6atan2(long A, long B);
extern    long _IQ5atan2(long A, long B);
extern    long _IQ4atan2(long A, long B);
extern    long _IQ3atan2(long A, long B);
extern    long _IQ2atan2(long A, long B);
extern    long _IQ1atan2(long A, long B);

#if GLOBAL_Q == 30
#define   _IQatan2(A,B)  _IQ30atan2(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQatan2(A,B)  _IQ29atan2(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQatan2(A,B)  _IQ28atan2(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQatan2(A,B)  _IQ27atan2(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQatan2(A,B)  _IQ26atan2(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQatan2(A,B)  _IQ25atan2(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQatan2(A,B)  _IQ24atan2(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQatan2(A,B)  _IQ23atan2(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQatan2(A,B)  _IQ22atan2(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQatan2(A,B)  _IQ21atan2(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQatan2(A,B)  _IQ20atan2(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQatan2(A,B)  _IQ19atan2(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQatan2(A,B)  _IQ18atan2(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQatan2(A,B)  _IQ17atan2(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQatan2(A,B)  _IQ16atan2(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQatan2(A,B)  _IQ15atan2(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQatan2(A,B)  _IQ14atan2(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQatan2(A,B)  _IQ13atan2(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQatan2(A,B)  _IQ12atan2(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQatan2(A,B)  _IQ11atan2(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQatan2(A,B)  _IQ10atan2(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQatan2(A,B)  _IQ9atan2(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQatan2(A,B)  _IQ8atan2(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQatan2(A,B)  _IQ7atan2(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQatan2(A,B)  _IQ6atan2(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQatan2(A,B)  _IQ5atan2(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQatan2(A,B)  _IQ4atan2(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQatan2(A,B)  _IQ3atan2(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQatan2(A,B)  _IQ2atan2(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQatan2(A,B)  _IQ1atan2(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30atan2PU(long A, long B);
extern    long _IQ29atan2PU(long A, long B);
extern    long _IQ28atan2PU(long A, long B);
extern    long _IQ27atan2PU(long A, long B);
extern    long _IQ26atan2PU(long A, long B);
extern    long _IQ25atan2PU(long A, long B);
extern    long _IQ24atan2PU(long A, long B);
extern    long _IQ23atan2PU(long A, long B);
extern    long _IQ22atan2PU(long A, long B);
extern    long _IQ21atan2PU(long A, long B);
extern    long _IQ20atan2PU(long A, long B);
extern    long _IQ19atan2PU(long A, long B);
extern    long _IQ18atan2PU(long A, long B);
extern    long _IQ17atan2PU(long A, long B);
extern    long _IQ16atan2PU(long A, long B);
extern    long _IQ15atan2PU(long A, long B);
extern    long _IQ14atan2PU(long A, long B);
extern    long _IQ13atan2PU(long A, long B);
extern    long _IQ12atan2PU(long A, long B);
extern    long _IQ11atan2PU(long A, long B);
extern    long _IQ10atan2PU(long A, long B);
extern    long _IQ9atan2PU(long A, long B);
extern    long _IQ8atan2PU(long A, long B);
extern    long _IQ7atan2PU(long A, long B);
extern    long _IQ6atan2PU(long A, long B);
extern    long _IQ5atan2PU(long A, long B);
extern    long _IQ4atan2PU(long A, long B);
extern    long _IQ3atan2PU(long A, long B);
extern    long _IQ2atan2PU(long A, long B);
extern    long _IQ1atan2PU(long A, long B);

#if GLOBAL_Q == 30
#define   _IQatan2PU(A,B)  _IQ30atan2PU(A,B)
#endif
#if GLOBAL_Q == 29
#define   _IQatan2PU(A,B)  _IQ29atan2PU(A,B)
#endif
#if GLOBAL_Q == 28
#define   _IQatan2PU(A,B)  _IQ28atan2PU(A,B)
#endif
#if GLOBAL_Q == 27
#define   _IQatan2PU(A,B)  _IQ27atan2PU(A,B)
#endif
#if GLOBAL_Q == 26
#define   _IQatan2PU(A,B)  _IQ26atan2PU(A,B)
#endif
#if GLOBAL_Q == 25
#define   _IQatan2PU(A,B)  _IQ25atan2PU(A,B)
#endif
#if GLOBAL_Q == 24
#define   _IQatan2PU(A,B)  _IQ24atan2PU(A,B)
#endif
#if GLOBAL_Q == 23
#define   _IQatan2PU(A,B)  _IQ23atan2PU(A,B)
#endif
#if GLOBAL_Q == 22
#define   _IQatan2PU(A,B)  _IQ22atan2PU(A,B)
#endif
#if GLOBAL_Q == 21
#define   _IQatan2PU(A,B)  _IQ21atan2PU(A,B)
#endif
#if GLOBAL_Q == 20
#define   _IQatan2PU(A,B)  _IQ20atan2PU(A,B)
#endif
#if GLOBAL_Q == 19
#define   _IQatan2PU(A,B)  _IQ19atan2PU(A,B)
#endif
#if GLOBAL_Q == 18
#define   _IQatan2PU(A,B)  _IQ18atan2PU(A,B)
#endif
#if GLOBAL_Q == 17
#define   _IQatan2PU(A,B)  _IQ17atan2PU(A,B)
#endif
#if GLOBAL_Q == 16
#define   _IQatan2PU(A,B)  _IQ16atan2PU(A,B)
#endif
#if GLOBAL_Q == 15
#define   _IQatan2PU(A,B)  _IQ15atan2PU(A,B)
#endif
#if GLOBAL_Q == 14
#define   _IQatan2PU(A,B)  _IQ14atan2PU(A,B)
#endif
#if GLOBAL_Q == 13
#define   _IQatan2PU(A,B)  _IQ13atan2PU(A,B)
#endif
#if GLOBAL_Q == 12
#define   _IQatan2PU(A,B)  _IQ12atan2PU(A,B)
#endif
#if GLOBAL_Q == 11
#define   _IQatan2PU(A,B)  _IQ11atan2PU(A,B)
#endif
#if GLOBAL_Q == 10
#define   _IQatan2PU(A,B)  _IQ10atan2PU(A,B)
#endif
#if GLOBAL_Q == 9
#define   _IQatan2PU(A,B)  _IQ9atan2PU(A,B)
#endif
#if GLOBAL_Q == 8
#define   _IQatan2PU(A,B)  _IQ8atan2PU(A,B)
#endif
#if GLOBAL_Q == 7
#define   _IQatan2PU(A,B)  _IQ7atan2PU(A,B)
#endif
#if GLOBAL_Q == 6
#define   _IQatan2PU(A,B)  _IQ6atan2PU(A,B)
#endif
#if GLOBAL_Q == 5
#define   _IQatan2PU(A,B)  _IQ5atan2PU(A,B)
#endif
#if GLOBAL_Q == 4
#define   _IQatan2PU(A,B)  _IQ4atan2PU(A,B)
#endif
#if GLOBAL_Q == 3
#define   _IQatan2PU(A,B)  _IQ3atan2PU(A,B)
#endif
#if GLOBAL_Q == 2
#define   _IQatan2PU(A,B)  _IQ2atan2PU(A,B)
#endif
#if GLOBAL_Q == 1
#define   _IQatan2PU(A,B)  _IQ1atan2PU(A,B)
#endif
//---------------------------------------------------------------------------
#if GLOBAL_Q == 30
#define   _IQatan(A)  _IQ30atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 29
#define   _IQatan(A)  _IQ29atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 28
#define   _IQatan(A)  _IQ28atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 27
#define   _IQatan(A)  _IQ27atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 26
#define   _IQatan(A)  _IQ26atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 25
#define   _IQatan(A)  _IQ25atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 24
#define   _IQatan(A)  _IQ24atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 23
#define   _IQatan(A)  _IQ23atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 22
#define   _IQatan(A)  _IQ22atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 21
#define   _IQatan(A)  _IQ21atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 20
#define   _IQatan(A)  _IQ20atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 19
#define   _IQatan(A)  _IQ19atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 18
#define   _IQatan(A)  _IQ18atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 17
#define   _IQatan(A)  _IQ17atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 16
#define   _IQatan(A)  _IQ16atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 15
#define   _IQatan(A)  _IQ15atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 14
#define   _IQatan(A)  _IQ14atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 13
#define   _IQatan(A)  _IQ13atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 12
#define   _IQatan(A)  _IQ12atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 11
#define   _IQatan(A)  _IQ11atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 10
#define   _IQatan(A)  _IQ10atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 9
#define   _IQatan(A)  _IQ9atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 8
#define   _IQatan(A)  _IQ8atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 7
#define   _IQatan(A)  _IQ7atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 6
#define   _IQatan(A)  _IQ6atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 5
#define   _IQatan(A)  _IQ5atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 4
#define   _IQatan(A)  _IQ4atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 3
#define   _IQatan(A)  _IQ3atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 2
#define   _IQatan(A)  _IQ2atan2(A,_IQ(1.0))
#endif
#if GLOBAL_Q == 1
#define   _IQatan(A)  _IQ1atan2(A,_IQ(1.0))
#endif
//---------------------------------------------------------------------------
extern    long _IQ30sqrt(long A);
extern    long _IQ29sqrt(long A);
extern    long _IQ28sqrt(long A);
extern    long _IQ27sqrt(long A);
extern    long _IQ26sqrt(long A);
extern    long _IQ25sqrt(long A);
extern    long _IQ24sqrt(long A);
extern    long _IQ23sqrt(long A);
extern    long _IQ22sqrt(long A);
extern    long _IQ21sqrt(long A);
extern    long _IQ20sqrt(long A);
extern    long _IQ19sqrt(long A);
extern    long _IQ18sqrt(long A);
extern    long _IQ17sqrt(long A);
extern    long _IQ16sqrt(long A);
extern    long _IQ15sqrt(long A);
extern    long _IQ14sqrt(long A);
extern    long _IQ13sqrt(long A);
extern    long _IQ12sqrt(long A);
extern    long _IQ11sqrt(long A);
extern    long _IQ10sqrt(long A);
extern    long _IQ9sqrt(long A);
extern    long _IQ8sqrt(long A);
extern    long _IQ7sqrt(long A);
extern    long _IQ6sqrt(long A);
extern    long _IQ5sqrt(long A);
extern    long _IQ4sqrt(long A);
extern    long _IQ3sqrt(long A);
extern    long _IQ2sqrt(long A);
extern    long _IQ1sqrt(long A);

#if GLOBAL_Q == 30
#define   _IQsqrt(A)  _IQ30sqrt(A)
#endif
#if GLOBAL_Q == 29
#define   _IQsqrt(A)  _IQ29sqrt(A)
#endif
#if GLOBAL_Q == 28
#define   _IQsqrt(A)  _IQ28sqrt(A)
#endif
#if GLOBAL_Q == 27
#define   _IQsqrt(A)  _IQ27sqrt(A)
#endif
#if GLOBAL_Q == 26
#define   _IQsqrt(A)  _IQ26sqrt(A)
#endif
#if GLOBAL_Q == 25
#define   _IQsqrt(A)  _IQ25sqrt(A)
#endif
#if GLOBAL_Q == 24
#define   _IQsqrt(A)  _IQ24sqrt(A)
#endif
#if GLOBAL_Q == 23
#define   _IQsqrt(A)  _IQ23sqrt(A)
#endif
#if GLOBAL_Q == 22
#define   _IQsqrt(A)  _IQ22sqrt(A)
#endif
#if GLOBAL_Q == 21
#define   _IQsqrt(A)  _IQ21sqrt(A)
#endif
#if GLOBAL_Q == 20
#define   _IQsqrt(A)  _IQ20sqrt(A)
#endif
#if GLOBAL_Q == 19
#define   _IQsqrt(A)  _IQ19sqrt(A)
#endif
#if GLOBAL_Q == 18
#define   _IQsqrt(A)  _IQ18sqrt(A)
#endif
#if GLOBAL_Q == 17
#define   _IQsqrt(A)  _IQ17sqrt(A)
#endif
#if GLOBAL_Q == 16
#define   _IQsqrt(A)  _IQ16sqrt(A)
#endif
#if GLOBAL_Q == 15
#define   _IQsqrt(A)  _IQ15sqrt(A)
#endif
#if GLOBAL_Q == 14
#define   _IQsqrt(A)  _IQ14sqrt(A)
#endif
#if GLOBAL_Q == 13
#define   _IQsqrt(A)  _IQ13sqrt(A)
#endif
#if GLOBAL_Q == 12
#define   _IQsqrt(A)  _IQ12sqrt(A)
#endif
#if GLOBAL_Q == 11
#define   _IQsqrt(A)  _IQ11sqrt(A)
#endif
#if GLOBAL_Q == 10
#define   _IQsqrt(A)  _IQ10sqrt(A)
#endif
#if GLOBAL_Q == 9
#define   _IQsqrt(A)  _IQ9sqrt(A)
#endif
#if GLOBAL_Q == 8
#define   _IQsqrt(A)  _IQ8sqrt(A)
#endif
#if GLOBAL_Q == 7
#define   _IQsqrt(A)  _IQ7sqrt(A)
#endif
#if GLOBAL_Q == 6
#define   _IQsqrt(A)  _IQ6sqrt(A)
#endif
#if GLOBAL_Q == 5
#define   _IQsqrt(A)  _IQ5sqrt(A)
#endif
#if GLOBAL_Q == 4
#define   _IQsqrt(A)  _IQ4sqrt(A)
#endif
#if GLOBAL_Q == 3
#define   _IQsqrt(A)  _IQ3sqrt(A)
#endif
#if GLOBAL_Q == 2
#define   _IQsqrt(A)  _IQ2sqrt(A)
#endif
#if GLOBAL_Q == 1
#define   _IQsqrt(A)  _IQ1sqrt(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30isqrt(long A);
extern    long _IQ29isqrt(long A);
extern    long _IQ28isqrt(long A);
extern    long _IQ27isqrt(long A);
extern    long _IQ26isqrt(long A);
extern    long _IQ25isqrt(long A);
extern    long _IQ24isqrt(long A);
extern    long _IQ23isqrt(long A);
extern    long _IQ22isqrt(long A);
extern    long _IQ21isqrt(long A);
extern    long _IQ20isqrt(long A);
extern    long _IQ19isqrt(long A);
extern    long _IQ18isqrt(long A);
extern    long _IQ17isqrt(long A);
extern    long _IQ16isqrt(long A);
extern    long _IQ15isqrt(long A);
extern    long _IQ14isqrt(long A);
extern    long _IQ13isqrt(long A);
extern    long _IQ12isqrt(long A);
extern    long _IQ11isqrt(long A);
extern    long _IQ10isqrt(long A);
extern    long _IQ9isqrt(long A);
extern    long _IQ8isqrt(long A);
extern    long _IQ7isqrt(long A);
extern    long _IQ6isqrt(long A);
extern    long _IQ5isqrt(long A);
extern    long _IQ4isqrt(long A);
extern    long _IQ3isqrt(long A);
extern    long _IQ2isqrt(long A);
extern    long _IQ1isqrt(long A);

#if GLOBAL_Q == 30
#define   _IQisqrt(A)  _IQ30isqrt(A)
#endif
#if GLOBAL_Q == 29
#define   _IQisqrt(A)  _IQ29isqrt(A)
#endif
#if GLOBAL_Q == 28
#define   _IQisqrt(A)  _IQ28isqrt(A)
#endif
#if GLOBAL_Q == 27
#define   _IQisqrt(A)  _IQ27isqrt(A)
#endif
#if GLOBAL_Q == 26
#define   _IQisqrt(A)  _IQ26isqrt(A)
#endif
#if GLOBAL_Q == 25
#define   _IQisqrt(A)  _IQ25isqrt(A)
#endif
#if GLOBAL_Q == 24
#define   _IQisqrt(A)  _IQ24isqrt(A)
#endif
#if GLOBAL_Q == 23
#define   _IQisqrt(A)  _IQ23isqrt(A)
#endif
#if GLOBAL_Q == 22
#define   _IQisqrt(A)  _IQ22isqrt(A)
#endif
#if GLOBAL_Q == 21
#define   _IQisqrt(A)  _IQ21isqrt(A)
#endif
#if GLOBAL_Q == 20
#define   _IQisqrt(A)  _IQ20isqrt(A)
#endif
#if GLOBAL_Q == 19
#define   _IQisqrt(A)  _IQ19isqrt(A)
#endif
#if GLOBAL_Q == 18
#define   _IQisqrt(A)  _IQ18isqrt(A)
#endif
#if GLOBAL_Q == 17
#define   _IQisqrt(A)  _IQ17isqrt(A)
#endif
#if GLOBAL_Q == 16
#define   _IQisqrt(A)  _IQ16isqrt(A)
#endif
#if GLOBAL_Q == 15
#define   _IQisqrt(A)  _IQ15isqrt(A)
#endif
#if GLOBAL_Q == 14
#define   _IQisqrt(A)  _IQ14isqrt(A)
#endif
#if GLOBAL_Q == 13
#define   _IQisqrt(A)  _IQ13isqrt(A)
#endif
#if GLOBAL_Q == 12
#define   _IQisqrt(A)  _IQ12isqrt(A)
#endif
#if GLOBAL_Q == 11
#define   _IQisqrt(A)  _IQ11isqrt(A)
#endif
#if GLOBAL_Q == 10
#define   _IQisqrt(A)  _IQ10isqrt(A)
#endif
#if GLOBAL_Q == 9
#define   _IQisqrt(A)  _IQ9isqrt(A)
#endif
#if GLOBAL_Q == 8
#define   _IQisqrt(A)  _IQ8isqrt(A)
#endif
#if GLOBAL_Q == 7
#define   _IQisqrt(A)  _IQ7isqrt(A)
#endif
#if GLOBAL_Q == 6
#define   _IQisqrt(A)  _IQ6isqrt(A)
#endif
#if GLOBAL_Q == 5
#define   _IQisqrt(A)  _IQ5isqrt(A)
#endif
#if GLOBAL_Q == 4
#define   _IQisqrt(A)  _IQ4isqrt(A)
#endif
#if GLOBAL_Q == 3
#define   _IQisqrt(A)  _IQ3isqrt(A)
#endif
#if GLOBAL_Q == 2
#define   _IQisqrt(A)  _IQ2isqrt(A)
#endif
#if GLOBAL_Q == 1
#define   _IQisqrt(A)  _IQ1isqrt(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30int(long A);
extern    long _IQ29int(long A);
extern    long _IQ28int(long A);
extern    long _IQ27int(long A);
extern    long _IQ26int(long A);
extern    long _IQ25int(long A);
extern    long _IQ24int(long A);
extern    long _IQ23int(long A);
extern    long _IQ22int(long A);
extern    long _IQ21int(long A);
extern    long _IQ20int(long A);
extern    long _IQ19int(long A);
extern    long _IQ18int(long A);
extern    long _IQ17int(long A);
extern    long _IQ16int(long A);
extern    long _IQ15int(long A);
extern    long _IQ14int(long A);
extern    long _IQ13int(long A);
extern    long _IQ12int(long A);
extern    long _IQ11int(long A);
extern    long _IQ10int(long A);
extern    long _IQ9int(long A);
extern    long _IQ8int(long A);
extern    long _IQ7int(long A);
extern    long _IQ6int(long A);
extern    long _IQ5int(long A);
extern    long _IQ4int(long A);
extern    long _IQ3int(long A);
extern    long _IQ2int(long A);
extern    long _IQ1int(long A);

#if GLOBAL_Q == 30
#define   _IQint(A)  _IQ30int(A)
#endif
#if GLOBAL_Q == 29
#define   _IQint(A)  _IQ29int(A)
#endif
#if GLOBAL_Q == 28
#define   _IQint(A)  _IQ28int(A)
#endif
#if GLOBAL_Q == 27
#define   _IQint(A)  _IQ27int(A)
#endif
#if GLOBAL_Q == 26
#define   _IQint(A)  _IQ26int(A)
#endif
#if GLOBAL_Q == 25
#define   _IQint(A)  _IQ25int(A)
#endif
#if GLOBAL_Q == 24
#define   _IQint(A)  _IQ24int(A)
#endif
#if GLOBAL_Q == 23
#define   _IQint(A)  _IQ23int(A)
#endif
#if GLOBAL_Q == 22
#define   _IQint(A)  _IQ22int(A)
#endif
#if GLOBAL_Q == 21
#define   _IQint(A)  _IQ21int(A)
#endif
#if GLOBAL_Q == 20
#define   _IQint(A)  _IQ20int(A)
#endif
#if GLOBAL_Q == 19
#define   _IQint(A)  _IQ19int(A)
#endif
#if GLOBAL_Q == 18
#define   _IQint(A)  _IQ18int(A)
#endif
#if GLOBAL_Q == 17
#define   _IQint(A)  _IQ17int(A)
#endif
#if GLOBAL_Q == 16
#define   _IQint(A)  _IQ16int(A)
#endif
#if GLOBAL_Q == 15
#define   _IQint(A)  _IQ15int(A)
#endif
#if GLOBAL_Q == 14
#define   _IQint(A)  _IQ14int(A)
#endif
#if GLOBAL_Q == 13
#define   _IQint(A)  _IQ13int(A)
#endif
#if GLOBAL_Q == 12
#define   _IQint(A)  _IQ12int(A)
#endif
#if GLOBAL_Q == 11
#define   _IQint(A)  _IQ11int(A)
#endif
#if GLOBAL_Q == 10
#define   _IQint(A)  _IQ10int(A)
#endif
#if GLOBAL_Q == 9
#define   _IQint(A)  _IQ9int(A)
#endif
#if GLOBAL_Q == 8
#define   _IQint(A)  _IQ8int(A)
#endif
#if GLOBAL_Q == 7
#define   _IQint(A)  _IQ7int(A)
#endif
#if GLOBAL_Q == 6
#define   _IQint(A)  _IQ6int(A)
#endif
#if GLOBAL_Q == 5
#define   _IQint(A)  _IQ5int(A)
#endif
#if GLOBAL_Q == 4
#define   _IQint(A)  _IQ4int(A)
#endif
#if GLOBAL_Q == 3
#define   _IQint(A)  _IQ3int(A)
#endif
#if GLOBAL_Q == 2
#define   _IQint(A)  _IQ2int(A)
#endif
#if GLOBAL_Q == 1
#define   _IQint(A)  _IQ1int(A)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30frac(long A);
extern    long _IQ29frac(long A);
extern    long _IQ28frac(long A);
extern    long _IQ27frac(long A);
extern    long _IQ26frac(long A);
extern    long _IQ25frac(long A);
extern    long _IQ24frac(long A);
extern    long _IQ23frac(long A);
extern    long _IQ22frac(long A);
extern    long _IQ21frac(long A);
extern    long _IQ20frac(long A);
extern    long _IQ19frac(long A);
extern    long _IQ18frac(long A);
extern    long _IQ17frac(long A);
extern    long _IQ16frac(long A);
extern    long _IQ15frac(long A);
extern    long _IQ14frac(long A);
extern    long _IQ13frac(long A);
extern    long _IQ12frac(long A);
extern    long _IQ11frac(long A);
extern    long _IQ10frac(long A);
extern    long _IQ9frac(long A);
extern    long _IQ8frac(long A);
extern    long _IQ7frac(long A);
extern    long _IQ6frac(long A);
extern    long _IQ5frac(long A);
extern    long _IQ4frac(long A);
extern    long _IQ3frac(long A);
extern    long _IQ2frac(long A);
extern    long _IQ1frac(long A);

#if GLOBAL_Q == 30
#define   _IQfrac(A)  _IQ30frac(A)
#endif
#if GLOBAL_Q == 29
#define   _IQfrac(A)  _IQ29frac(A)
#endif
#if GLOBAL_Q == 28
#define   _IQfrac(A)  _IQ28frac(A)
#endif
#if GLOBAL_Q == 27
#define   _IQfrac(A)  _IQ27frac(A)
#endif
#if GLOBAL_Q == 26
#define   _IQfrac(A)  _IQ26frac(A)
#endif
#if GLOBAL_Q == 25
#define   _IQfrac(A)  _IQ25frac(A)
#endif
#if GLOBAL_Q == 24
#define   _IQfrac(A)  _IQ24frac(A)
#endif
#if GLOBAL_Q == 23
#define   _IQfrac(A)  _IQ23frac(A)
#endif
#if GLOBAL_Q == 22
#define   _IQfrac(A)  _IQ22frac(A)
#endif
#if GLOBAL_Q == 21
#define   _IQfrac(A)  _IQ21frac(A)
#endif
#if GLOBAL_Q == 20
#define   _IQfrac(A)  _IQ20frac(A)
#endif
#if GLOBAL_Q == 19
#define   _IQfrac(A)  _IQ19frac(A)
#endif
#if GLOBAL_Q == 18
#define   _IQfrac(A)  _IQ18frac(A)
#endif
#if GLOBAL_Q == 17
#define   _IQfrac(A)  _IQ17frac(A)
#endif
#if GLOBAL_Q == 16
#define   _IQfrac(A)  _IQ16frac(A)
#endif
#if GLOBAL_Q == 15
#define   _IQfrac(A)  _IQ15frac(A)
#endif
#if GLOBAL_Q == 14
#define   _IQfrac(A)  _IQ14frac(A)
#endif
#if GLOBAL_Q == 13
#define   _IQfrac(A)  _IQ13frac(A)
#endif
#if GLOBAL_Q == 12
#define   _IQfrac(A)  _IQ12frac(A)
#endif
#if GLOBAL_Q == 11
#define   _IQfrac(A)  _IQ11frac(A)
#endif
#if GLOBAL_Q == 10
#define   _IQfrac(A)  _IQ10frac(A)
#endif
#if GLOBAL_Q == 9
#define   _IQfrac(A)  _IQ9frac(A)
#endif
#if GLOBAL_Q == 8
#define   _IQfrac(A)  _IQ8frac(A)
#endif
#if GLOBAL_Q == 7
#define   _IQfrac(A)  _IQ7frac(A)
#endif
#if GLOBAL_Q == 6
#define   _IQfrac(A)  _IQ6frac(A)
#endif
#if GLOBAL_Q == 5
#define   _IQfrac(A)  _IQ5frac(A)
#endif
#if GLOBAL_Q == 4
#define   _IQfrac(A)  _IQ4frac(A)
#endif
#if GLOBAL_Q == 3
#define   _IQfrac(A)  _IQ3frac(A)
#endif
#if GLOBAL_Q == 2
#define   _IQfrac(A)  _IQ2frac(A)
#endif
#if GLOBAL_Q == 1
#define   _IQfrac(A)  _IQ1frac(A)
#endif
//---------------------------------------------------------------------------
#define   _IQmpyIQX(A, IQA, B, IQB)    __IQxmpy(A, B, (GLOBAL_Q + 32 - IQA - IQB))
#define   _IQ30mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (30 + 32 - IQA - IQB))
#define   _IQ29mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (29 + 32 - IQA - IQB))
#define   _IQ28mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (28 + 32 - IQA - IQB))
#define   _IQ27mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (27 + 32 - IQA - IQB))
#define   _IQ26mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (26 + 32 - IQA - IQB))
#define   _IQ25mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (25 + 32 - IQA - IQB))
#define   _IQ24mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (24 + 32 - IQA - IQB))
#define   _IQ23mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (23 + 32 - IQA - IQB))
#define   _IQ22mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (22 + 32 - IQA - IQB))
#define   _IQ21mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (21 + 32 - IQA - IQB))
#define   _IQ20mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (20 + 32 - IQA - IQB))
#define   _IQ19mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (19 + 32 - IQA - IQB))
#define   _IQ18mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (18 + 32 - IQA - IQB))
#define   _IQ17mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (17 + 32 - IQA - IQB))
#define   _IQ16mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (16 + 32 - IQA - IQB))
#define   _IQ15mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (15 + 32 - IQA - IQB))
#define   _IQ14mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (14 + 32 - IQA - IQB))
#define   _IQ13mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (13 + 32 - IQA - IQB))
#define   _IQ12mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (12 + 32 - IQA - IQB))
#define   _IQ11mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (11 + 32 - IQA - IQB))
#define   _IQ10mpyIQX(A, IQA, B, IQB)  __IQxmpy(A, B, (10 + 32 - IQA - IQB))
#define   _IQ9mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (9 + 32 - IQA - IQB))
#define   _IQ8mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (8 + 32 - IQA - IQB))
#define   _IQ7mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (7 + 32 - IQA - IQB))
#define   _IQ6mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (6 + 32 - IQA - IQB))
#define   _IQ5mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (5 + 32 - IQA - IQB))
#define   _IQ4mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (4 + 32 - IQA - IQB))
#define   _IQ3mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (3 + 32 - IQA - IQB))
#define   _IQ2mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (2 + 32 - IQA - IQB))
#define   _IQ1mpyIQX(A, IQA, B, IQB)   __IQxmpy(A, B, (1 + 32 - IQA - IQB))
//---------------------------------------------------------------------------
#define   _IQmpyI32(A,B)    ((A)*(B))
#define   _IQ30mpyI32(A,B)  ((A)*(B))
#define   _IQ29mpyI32(A,B)  ((A)*(B))
#define   _IQ28mpyI32(A,B)  ((A)*(B))
#define   _IQ27mpyI32(A,B)  ((A)*(B))
#define   _IQ26mpyI32(A,B)  ((A)*(B))
#define   _IQ25mpyI32(A,B)  ((A)*(B))
#define   _IQ24mpyI32(A,B)  ((A)*(B))
#define   _IQ23mpyI32(A,B)  ((A)*(B))
#define   _IQ22mpyI32(A,B)  ((A)*(B))
#define   _IQ21mpyI32(A,B)  ((A)*(B))
#define   _IQ20mpyI32(A,B)  ((A)*(B))
#define   _IQ19mpyI32(A,B)  ((A)*(B))
#define   _IQ18mpyI32(A,B)  ((A)*(B))
#define   _IQ17mpyI32(A,B)  ((A)*(B))
#define   _IQ16mpyI32(A,B)  ((A)*(B))
#define   _IQ15mpyI32(A,B)  ((A)*(B))
#define   _IQ14mpyI32(A,B)  ((A)*(B))
#define   _IQ13mpyI32(A,B)  ((A)*(B))
#define   _IQ12mpyI32(A,B)  ((A)*(B))
#define   _IQ11mpyI32(A,B)  ((A)*(B))
#define   _IQ10mpyI32(A,B)  ((A)*(B))
#define   _IQ9mpyI32(A,B)   ((A)*(B))
#define   _IQ8mpyI32(A,B)   ((A)*(B))
#define   _IQ7mpyI32(A,B)   ((A)*(B))
#define   _IQ6mpyI32(A,B)   ((A)*(B))
#define   _IQ5mpyI32(A,B)   ((A)*(B))
#define   _IQ4mpyI32(A,B)   ((A)*(B))
#define   _IQ3mpyI32(A,B)   ((A)*(B))
#define   _IQ2mpyI32(A,B)   ((A)*(B))
#define   _IQ1mpyI32(A,B)   ((A)*(B))
//---------------------------------------------------------------------------
extern    long _IQ30mpyI32int(long A, long B);
extern    long _IQ29mpyI32int(long A, long B);
extern    long _IQ28mpyI32int(long A, long B);
extern    long _IQ27mpyI32int(long A, long B);
extern    long _IQ26mpyI32int(long A, long B);
extern    long _IQ25mpyI32int(long A, long B);
extern    long _IQ24mpyI32int(long A, long B);
extern    long _IQ23mpyI32int(long A, long B);
extern    long _IQ22mpyI32int(long A, long B);
extern    long _IQ21mpyI32int(long A, long B);
extern    long _IQ20mpyI32int(long A, long B);
extern    long _IQ19mpyI32int(long A, long B);
extern    long _IQ18mpyI32int(long A, long B);
extern    long _IQ17mpyI32int(long A, long B);
extern    long _IQ16mpyI32int(long A, long B);
extern    long _IQ15mpyI32int(long A, long B);
extern    long _IQ14mpyI32int(long A, long B);
extern    long _IQ13mpyI32int(long A, long B);
extern    long _IQ12mpyI32int(long A, long B);
extern    long _IQ11mpyI32int(long A, long B);
extern    long _IQ10mpyI32int(long A, long B);
extern    long _IQ9mpyI32int(long A, long B);
extern    long _IQ8mpyI32int(long A, long B);
extern    long _IQ7mpyI32int(long A, long B);
extern    long _IQ6mpyI32int(long A, long B);
extern    long _IQ5mpyI32int(long A, long B);
extern    long _IQ4mpyI32int(long A, long B);
extern    long _IQ3mpyI32int(long A, long B);
extern    long _IQ2mpyI32int(long A, long B);
extern    long _IQ1mpyI32int(long A, long B);

#if GLOBAL_Q == 30
#define   _IQmpyI32int(A, B)  _IQ30mpyI32int(A, B)
#endif
#if GLOBAL_Q == 29
#define   _IQmpyI32int(A, B)  _IQ29mpyI32int(A, B)
#endif
#if GLOBAL_Q == 28
#define   _IQmpyI32int(A, B)  _IQ28mpyI32int(A, B)
#endif
#if GLOBAL_Q == 27
#define   _IQmpyI32int(A, B)  _IQ27mpyI32int(A, B)
#endif
#if GLOBAL_Q == 26
#define   _IQmpyI32int(A, B)  _IQ26mpyI32int(A, B)
#endif
#if GLOBAL_Q == 25
#define   _IQmpyI32int(A, B)  _IQ25mpyI32int(A, B)
#endif
#if GLOBAL_Q == 24
#define   _IQmpyI32int(A, B)  _IQ24mpyI32int(A, B)
#endif
#if GLOBAL_Q == 23
#define   _IQmpyI32int(A, B)  _IQ23mpyI32int(A, B)
#endif
#if GLOBAL_Q == 22
#define   _IQmpyI32int(A, B)  _IQ22mpyI32int(A, B)
#endif
#if GLOBAL_Q == 21
#define   _IQmpyI32int(A, B)  _IQ21mpyI32int(A, B)
#endif
#if GLOBAL_Q == 20
#define   _IQmpyI32int(A, B)  _IQ20mpyI32int(A, B)
#endif
#if GLOBAL_Q == 19
#define   _IQmpyI32int(A, B)  _IQ19mpyI32int(A, B)
#endif
#if GLOBAL_Q == 18
#define   _IQmpyI32int(A, B)  _IQ18mpyI32int(A, B)
#endif
#if GLOBAL_Q == 17
#define   _IQmpyI32int(A, B)  _IQ17mpyI32int(A, B)
#endif
#if GLOBAL_Q == 16
#define   _IQmpyI32int(A, B)  _IQ16mpyI32int(A, B)
#endif
#if GLOBAL_Q == 15
#define   _IQmpyI32int(A, B)  _IQ15mpyI32int(A, B)
#endif
#if GLOBAL_Q == 14
#define   _IQmpyI32int(A, B)  _IQ14mpyI32int(A, B)
#endif
#if GLOBAL_Q == 13
#define   _IQmpyI32int(A, B)  _IQ13mpyI32int(A, B)
#endif
#if GLOBAL_Q == 12
#define   _IQmpyI32int(A, B)  _IQ12mpyI32int(A, B)
#endif
#if GLOBAL_Q == 11
#define   _IQmpyI32int(A, B)  _IQ11mpyI32int(A, B)
#endif
#if GLOBAL_Q == 10
#define   _IQmpyI32int(A, B)  _IQ10mpyI32int(A, B)
#endif
#if GLOBAL_Q == 9
#define   _IQmpyI32int(A, B)  _IQ9mpyI32int(A, B)
#endif
#if GLOBAL_Q == 8
#define   _IQmpyI32int(A, B)  _IQ8mpyI32int(A, B)
#endif
#if GLOBAL_Q == 7
#define   _IQmpyI32int(A, B)  _IQ7mpyI32int(A, B)
#endif
#if GLOBAL_Q == 6
#define   _IQmpyI32int(A, B)  _IQ6mpyI32int(A, B)
#endif
#if GLOBAL_Q == 5
#define   _IQmpyI32int(A, B)  _IQ5mpyI32int(A, B)
#endif
#if GLOBAL_Q == 4
#define   _IQmpyI32int(A, B)  _IQ4mpyI32int(A, B)
#endif
#if GLOBAL_Q == 3
#define   _IQmpyI32int(A, B)  _IQ3mpyI32int(A, B)
#endif
#if GLOBAL_Q == 2
#define   _IQmpyI32int(A, B)  _IQ2mpyI32int(A, B)
#endif
#if GLOBAL_Q == 1
#define   _IQmpyI32int(A, B)  _IQ1mpyI32int(A, B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30mpyI32frac(long A, long B);
extern    long _IQ29mpyI32frac(long A, long B);
extern    long _IQ28mpyI32frac(long A, long B);
extern    long _IQ27mpyI32frac(long A, long B);
extern    long _IQ26mpyI32frac(long A, long B);
extern    long _IQ25mpyI32frac(long A, long B);
extern    long _IQ24mpyI32frac(long A, long B);
extern    long _IQ23mpyI32frac(long A, long B);
extern    long _IQ22mpyI32frac(long A, long B);
extern    long _IQ21mpyI32frac(long A, long B);
extern    long _IQ20mpyI32frac(long A, long B);
extern    long _IQ19mpyI32frac(long A, long B);
extern    long _IQ18mpyI32frac(long A, long B);
extern    long _IQ17mpyI32frac(long A, long B);
extern    long _IQ16mpyI32frac(long A, long B);
extern    long _IQ15mpyI32frac(long A, long B);
extern    long _IQ14mpyI32frac(long A, long B);
extern    long _IQ13mpyI32frac(long A, long B);
extern    long _IQ12mpyI32frac(long A, long B);
extern    long _IQ11mpyI32frac(long A, long B);
extern    long _IQ10mpyI32frac(long A, long B);
extern    long _IQ9mpyI32frac(long A, long B);
extern    long _IQ8mpyI32frac(long A, long B);
extern    long _IQ7mpyI32frac(long A, long B);
extern    long _IQ6mpyI32frac(long A, long B);
extern    long _IQ5mpyI32frac(long A, long B);
extern    long _IQ4mpyI32frac(long A, long B);
extern    long _IQ3mpyI32frac(long A, long B);
extern    long _IQ2mpyI32frac(long A, long B);
extern    long _IQ1mpyI32frac(long A, long B);

#if GLOBAL_Q == 30
#define   _IQmpyI32frac(A, B)  _IQ30mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 29
#define   _IQmpyI32frac(A, B)  _IQ29mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 28
#define   _IQmpyI32frac(A, B)  _IQ28mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 27
#define   _IQmpyI32frac(A, B)  _IQ27mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 26
#define   _IQmpyI32frac(A, B)  _IQ26mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 25
#define   _IQmpyI32frac(A, B)  _IQ25mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 24
#define   _IQmpyI32frac(A, B)  _IQ24mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 23
#define   _IQmpyI32frac(A, B)  _IQ23mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 22
#define   _IQmpyI32frac(A, B)  _IQ22mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 21
#define   _IQmpyI32frac(A, B)  _IQ21mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 20
#define   _IQmpyI32frac(A, B)  _IQ20mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 19
#define   _IQmpyI32frac(A, B)  _IQ19mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 18
#define   _IQmpyI32frac(A, B)  _IQ18mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 17
#define   _IQmpyI32frac(A, B)  _IQ17mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 16
#define   _IQmpyI32frac(A, B)  _IQ16mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 15
#define   _IQmpyI32frac(A, B)  _IQ15mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 14
#define   _IQmpyI32frac(A, B)  _IQ14mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 13
#define   _IQmpyI32frac(A, B)  _IQ13mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 12
#define   _IQmpyI32frac(A, B)  _IQ12mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 11
#define   _IQmpyI32frac(A, B)  _IQ11mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 10
#define   _IQmpyI32frac(A, B)  _IQ10mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 9
#define   _IQmpyI32frac(A, B)  _IQ9mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 8
#define   _IQmpyI32frac(A, B)  _IQ8mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 7
#define   _IQmpyI32frac(A, B)  _IQ7mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 6
#define   _IQmpyI32frac(A, B)  _IQ6mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 5
#define   _IQmpyI32frac(A, B)  _IQ5mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 4
#define   _IQmpyI32frac(A, B)  _IQ4mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 3
#define   _IQmpyI32frac(A, B)  _IQ3mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 2
#define   _IQmpyI32frac(A, B)  _IQ2mpyI32frac(A, B)
#endif
#if GLOBAL_Q == 1
#define   _IQmpyI32frac(A, B)  _IQ1mpyI32frac(A, B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30mag(long A, long B);
extern    long _IQ29mag(long A, long B);
extern    long _IQ28mag(long A, long B);
extern    long _IQ27mag(long A, long B);
extern    long _IQ26mag(long A, long B);
extern    long _IQ25mag(long A, long B);
extern    long _IQ24mag(long A, long B);
extern    long _IQ23mag(long A, long B);
extern    long _IQ22mag(long A, long B);
extern    long _IQ21mag(long A, long B);
extern    long _IQ20mag(long A, long B);
extern    long _IQ19mag(long A, long B);
extern    long _IQ18mag(long A, long B);
extern    long _IQ17mag(long A, long B);
extern    long _IQ16mag(long A, long B);
extern    long _IQ15mag(long A, long B);
extern    long _IQ14mag(long A, long B);
extern    long _IQ13mag(long A, long B);
extern    long _IQ12mag(long A, long B);
extern    long _IQ11mag(long A, long B);
extern    long _IQ10mag(long A, long B);
extern    long _IQ9mag(long A, long B);
extern    long _IQ8mag(long A, long B);
extern    long _IQ7mag(long A, long B);
extern    long _IQ6mag(long A, long B);
extern    long _IQ5mag(long A, long B);
extern    long _IQ4mag(long A, long B);
extern    long _IQ3mag(long A, long B);
extern    long _IQ2mag(long A, long B);
extern    long _IQ1mag(long A, long B);

#if GLOBAL_Q == 30
#define   _IQmag(A, B)  _IQ30mag(A, B)
#endif
#if GLOBAL_Q == 29
#define   _IQmag(A, B)  _IQ29mag(A, B)
#endif
#if GLOBAL_Q == 28
#define   _IQmag(A, B)  _IQ28mag(A, B)
#endif
#if GLOBAL_Q == 27
#define   _IQmag(A, B)  _IQ27mag(A, B)
#endif
#if GLOBAL_Q == 26
#define   _IQmag(A, B)  _IQ26mag(A, B)
#endif
#if GLOBAL_Q == 25
#define   _IQmag(A, B)  _IQ25mag(A, B)
#endif
#if GLOBAL_Q == 24
#define   _IQmag(A, B)  _IQ24mag(A, B)
#endif
#if GLOBAL_Q == 23
#define   _IQmag(A, B)  _IQ23mag(A, B)
#endif
#if GLOBAL_Q == 22
#define   _IQmag(A, B)  _IQ22mag(A, B)
#endif
#if GLOBAL_Q == 21
#define   _IQmag(A, B)  _IQ21mag(A, B)
#endif
#if GLOBAL_Q == 20
#define   _IQmag(A, B)  _IQ20mag(A, B)
#endif
#if GLOBAL_Q == 19
#define   _IQmag(A, B)  _IQ19mag(A, B)
#endif
#if GLOBAL_Q == 18
#define   _IQmag(A, B)  _IQ18mag(A, B)
#endif
#if GLOBAL_Q == 17
#define   _IQmag(A, B)  _IQ17mag(A, B)
#endif
#if GLOBAL_Q == 16
#define   _IQmag(A, B)  _IQ16mag(A, B)
#endif
#if GLOBAL_Q == 15
#define   _IQmag(A, B)  _IQ15mag(A, B)
#endif
#if GLOBAL_Q == 14
#define   _IQmag(A, B)  _IQ14mag(A, B)
#endif
#if GLOBAL_Q == 13
#define   _IQmag(A, B)  _IQ13mag(A, B)
#endif
#if GLOBAL_Q == 12
#define   _IQmag(A, B)  _IQ12mag(A, B)
#endif
#if GLOBAL_Q == 11
#define   _IQmag(A, B)  _IQ11mag(A, B)
#endif
#if GLOBAL_Q == 10
#define   _IQmag(A, B)  _IQ10mag(A, B)
#endif
#if GLOBAL_Q == 9
#define   _IQmag(A, B)  _IQ9mag(A, B)
#endif
#if GLOBAL_Q == 8
#define   _IQmag(A, B)  _IQ8mag(A, B)
#endif
#if GLOBAL_Q == 7
#define   _IQmag(A, B)  _IQ7mag(A, B)
#endif
#if GLOBAL_Q == 6
#define   _IQmag(A, B)  _IQ6mag(A, B)
#endif
#if GLOBAL_Q == 5
#define   _IQmag(A, B)  _IQ5mag(A, B)
#endif
#if GLOBAL_Q == 4
#define   _IQmag(A, B)  _IQ4mag(A, B)
#endif
#if GLOBAL_Q == 3
#define   _IQmag(A, B)  _IQ3mag(A, B)
#endif
#if GLOBAL_Q == 2
#define   _IQmag(A, B)  _IQ2mag(A, B)
#endif
#if GLOBAL_Q == 1
#define   _IQmag(A, B)  _IQ1mag(A, B)
#endif
//---------------------------------------------------------------------------
extern    long _atoIQN(const char *A, long q_value);
#define   _atoIQ(A)    _atoIQN(A, GLOBAL_Q)
#define   _atoIQ30(A)  _atoIQN(A, 30)
#define   _atoIQ29(A)  _atoIQN(A, 29)
#define   _atoIQ28(A)  _atoIQN(A, 28)
#define   _atoIQ27(A)  _atoIQN(A, 27)
#define   _atoIQ26(A)  _atoIQN(A, 26)
#define   _atoIQ25(A)  _atoIQN(A, 25)
#define   _atoIQ24(A)  _atoIQN(A, 24)
#define   _atoIQ23(A)  _atoIQN(A, 23)
#define   _atoIQ22(A)  _atoIQN(A, 22)
#define   _atoIQ21(A)  _atoIQN(A, 21)
#define   _atoIQ20(A)  _atoIQN(A, 20)
#define   _atoIQ19(A)  _atoIQN(A, 19)
#define   _atoIQ18(A)  _atoIQN(A, 18)
#define   _atoIQ17(A)  _atoIQN(A, 17)
#define   _atoIQ16(A)  _atoIQN(A, 16)
#define   _atoIQ15(A)  _atoIQN(A, 15)
#define   _atoIQ14(A)  _atoIQN(A, 14)
#define   _atoIQ13(A)  _atoIQN(A, 13)
#define   _atoIQ12(A)  _atoIQN(A, 12)
#define   _atoIQ11(A)  _atoIQN(A, 11)
#define   _atoIQ10(A)  _atoIQN(A, 10)
#define   _atoIQ9(A)   _atoIQN(A, 9)
#define   _atoIQ8(A)   _atoIQN(A, 8)
#define   _atoIQ7(A)   _atoIQN(A, 7)
#define   _atoIQ6(A)   _atoIQN(A, 6)
#define   _atoIQ5(A)   _atoIQN(A, 5)
#define   _atoIQ4(A)   _atoIQN(A, 4)
#define   _atoIQ3(A)   _atoIQN(A, 3)
#define   _atoIQ2(A)   _atoIQN(A, 2)
#define   _atoIQ1(A)   _atoIQN(A, 1)
//---------------------------------------------------------------------------
#define   _IQabs(A)    labs(A)
#define   _IQ30abs(A)  labs(A)
#define   _IQ29abs(A)  labs(A)
#define   _IQ28abs(A)  labs(A)
#define   _IQ27abs(A)  labs(A)
#define   _IQ26abs(A)  labs(A)
#define   _IQ25abs(A)  labs(A)
#define   _IQ24abs(A)  labs(A)
#define   _IQ23abs(A)  labs(A)
#define   _IQ22abs(A)  labs(A)
#define   _IQ21abs(A)  labs(A)
#define   _IQ20abs(A)  labs(A)
#define   _IQ19abs(A)  labs(A)
#define   _IQ18abs(A)  labs(A)
#define   _IQ17abs(A)  labs(A)
#define   _IQ16abs(A)  labs(A)
#define   _IQ15abs(A)  labs(A)
#define   _IQ14abs(A)  labs(A)
#define   _IQ13abs(A)  labs(A)
#define   _IQ12abs(A)  labs(A)
#define   _IQ11abs(A)  labs(A)
#define   _IQ10abs(A)  labs(A)
#define   _IQ9abs(A)   labs(A)
#define   _IQ8abs(A)   labs(A)
#define   _IQ7abs(A)   labs(A)
#define   _IQ6abs(A)   labs(A)
#define   _IQ5abs(A)   labs(A)
#define   _IQ4abs(A)   labs(A)
#define   _IQ3abs(A)   labs(A)
#define   _IQ2abs(A)   labs(A)
#define   _IQ1abs(A)   labs(A)
//###########################################################################
#else   // MATH_TYPE == FLOAT_MATH
//###########################################################################
// If FLOAT_MATH is used, the IQmath library function are replaced by
// equivalent floating point operations:
//===========================================================================
typedef   float   _iq;
typedef   float   _iq30;
typedef   float   _iq29;
typedef   float   _iq28;
typedef   float   _iq27;
typedef   float   _iq26;
typedef   float   _iq25;
typedef   float   _iq24;
typedef   float   _iq23;
typedef   float   _iq22;
typedef   float   _iq21;
typedef   float   _iq20;
typedef   float   _iq19;
typedef   float   _iq18;
typedef   float   _iq17;
typedef   float   _iq16;
typedef   float   _iq15;
typedef   float   _iq14;
typedef   float   _iq13;
typedef   float   _iq12;
typedef   float   _iq11;
typedef   float   _iq10;
typedef   float   _iq9;
typedef   float   _iq8;
typedef   float   _iq7;
typedef   float   _iq6;
typedef   float   _iq5;
typedef   float   _iq4;
typedef   float   _iq3;
typedef   float   _iq2;
typedef   float   _iq1;
//---------------------------------------------------------------------------
#define   _IQ(A)         (A)
#define   _IQ30(A)       (A)
#define   _IQ29(A)       (A)
#define   _IQ28(A)       (A)
#define   _IQ27(A)       (A)
#define   _IQ26(A)       (A)
#define   _IQ25(A)       (A)
#define   _IQ24(A)       (A)
#define   _IQ23(A)       (A)
#define   _IQ22(A)       (A)
#define   _IQ21(A)       (A)
#define   _IQ20(A)       (A)
#define   _IQ19(A)       (A)
#define   _IQ18(A)       (A)
#define   _IQ17(A)       (A)
#define   _IQ16(A)       (A)
#define   _IQ15(A)       (A)
#define   _IQ14(A)       (A)
#define   _IQ13(A)       (A)
#define   _IQ12(A)       (A)
#define   _IQ10(A)       (A)
#define   _IQ9(A)        (A)
#define   _IQ8(A)        (A)
#define   _IQ7(A)        (A)
#define   _IQ6(A)        (A)
#define   _IQ5(A)        (A)
#define   _IQ4(A)        (A)
#define   _IQ3(A)        (A)
#define   _IQ2(A)        (A)
#define   _IQ1(A)        (A)
//---------------------------------------------------------------------------
#define   _IQtoF(A)      (A)
#define   _IQ30toF(A)    (A)
#define   _IQ29toF(A)    (A)
#define   _IQ28toF(A)    (A)
#define   _IQ27toF(A)    (A)
#define   _IQ26toF(A)    (A)
#define   _IQ25toF(A)    (A)
#define   _IQ24toF(A)    (A)
#define   _IQ23toF(A)    (A)
#define   _IQ22toF(A)    (A)
#define   _IQ21toF(A)    (A)
#define   _IQ20toF(A)    (A)
#define   _IQ19toF(A)    (A)
#define   _IQ18toF(A)    (A)
#define   _IQ17toF(A)    (A)
#define   _IQ16toF(A)    (A)
#define   _IQ15toF(A)    (A)
#define   _IQ14toF(A)    (A)
#define   _IQ13toF(A)    (A)
#define   _IQ12toF(A)    (A)
#define   _IQ11toF(A)    (A)
#define   _IQ10toF(A)    (A)
#define   _IQ9toF(A)     (A)
#define   _IQ8toF(A)     (A)
#define   _IQ7toF(A)     (A)
#define   _IQ6toF(A)     (A)
#define   _IQ5toF(A)     (A)
#define   _IQ4toF(A)     (A)
#define   _IQ3toF(A)     (A)
#define   _IQ2toF(A)     (A)
#define   _IQ1toF(A)     (A)
//---------------------------------------------------------------------------
extern  float _satf(float A, float Pos, float Neg);
#define   _IQsat(A, Pos, Neg)    _satf(A, Pos, Neg)
//---------------------------------------------------------------------------
#define   _IQtoIQ30(A)   (A)
#define   _IQtoIQ29(A)   (A)
#define   _IQtoIQ28(A)   (A)
#define   _IQtoIQ27(A)   (A)
#define   _IQtoIQ26(A)   (A)
#define   _IQtoIQ25(A)   (A)
#define   _IQtoIQ24(A)   (A)
#define   _IQtoIQ23(A)   (A)
#define   _IQtoIQ22(A)   (A)
#define   _IQtoIQ21(A)   (A)
#define   _IQtoIQ20(A)   (A)
#define   _IQtoIQ19(A)   (A)
#define   _IQtoIQ18(A)   (A)
#define   _IQtoIQ17(A)   (A)
#define   _IQtoIQ16(A)   (A)
#define   _IQtoIQ15(A)   (A)
#define   _IQtoIQ14(A)   (A)
#define   _IQtoIQ13(A)   (A)
#define   _IQtoIQ12(A)   (A)
#define   _IQtoIQ11(A)   (A)
#define   _IQtoIQ10(A)   (A)
#define   _IQtoIQ9(A)    (A)
#define   _IQtoIQ8(A)    (A)
#define   _IQtoIQ7(A)    (A)
#define   _IQtoIQ6(A)    (A)
#define   _IQtoIQ5(A)    (A)
#define   _IQtoIQ4(A)    (A)
#define   _IQtoIQ3(A)    (A)
#define   _IQtoIQ2(A)    (A)
#define   _IQtoIQ1(A)    (A)
//---------------------------------------------------------------------------
#define   _IQ30toIQ(A)   (A)
#define   _IQ29toIQ(A)   (A)
#define   _IQ28toIQ(A)   (A)
#define   _IQ27toIQ(A)   (A)
#define   _IQ26toIQ(A)   (A)
#define   _IQ25toIQ(A)   (A)
#define   _IQ24toIQ(A)   (A)
#define   _IQ23toIQ(A)   (A)
#define   _IQ22toIQ(A)   (A)
#define   _IQ21toIQ(A)   (A)
#define   _IQ20toIQ(A)   (A)
#define   _IQ19toIQ(A)   (A)
#define   _IQ18toIQ(A)   (A)
#define   _IQ17toIQ(A)   (A)
#define   _IQ16toIQ(A)   (A)
#define   _IQ15toIQ(A)   (A)
#define   _IQ14toIQ(A)   (A)
#define   _IQ13toIQ(A)   (A)
#define   _IQ12toIQ(A)   (A)
#define   _IQ11toIQ(A)   (A)
#define   _IQ10toIQ(A)   (A)
#define   _IQ9toIQ(A)    (A)
#define   _IQ8toIQ(A)    (A)
#define   _IQ7toIQ(A)    (A)
#define   _IQ6toIQ(A)    (A)
#define   _IQ5toIQ(A)    (A)
#define   _IQ4toIQ(A)    (A)
#define   _IQ3toIQ(A)    (A)
#define   _IQ2toIQ(A)    (A)
#define   _IQ1toIQ(A)    (A)
//---------------------------------------------------------------------------
#define   _IQtoQ15(A)    (short) ((long)((A) * 32768.0L))
#define   _IQtoQ14(A)    (short) ((long)((A) * 16384.0L))
#define   _IQtoQ13(A)    (short) ((long)((A) * 8192.0L))
#define   _IQtoQ12(A)    (short) ((long)((A) * 4096.0L))
#define   _IQtoQ11(A)    (short) ((long)((A) * 2048.0L))
#define   _IQtoQ10(A)    (short) ((long)((A) * 1024.0L))
#define   _IQtoQ9(A)     (short) ((long)((A) * 512.0L))
#define   _IQtoQ8(A)     (short) ((long)((A) * 256.0L))
#define   _IQtoQ7(A)     (short) ((long)((A) * 128.0L))
#define   _IQtoQ6(A)     (short) ((long)((A) * 64.0L))
#define   _IQtoQ5(A)     (short) ((long)((A) * 32.0L))
#define   _IQtoQ4(A)     (short) ((long)((A) * 16.0L))
#define   _IQtoQ3(A)     (short) ((long)((A) * 8.0L))
#define   _IQtoQ2(A)     (short) ((long)((A) * 4.0L))
#define   _IQtoQ1(A)     (short) ((long)((A) * 2.0L))

//---------------------------------------------------------------------------
#define   _Q15toIQ(A)    (((float) (A)) * 0.000030518)
#define   _Q14toIQ(A)    (((float) (A)) * 0.000061035)
#define   _Q13toIQ(A)    (((float) (A)) * 0.000122070)
#define   _Q12toIQ(A)    (((float) (A)) * 0.000244141)
#define   _Q11toIQ(A)    (((float) (A)) * 0.000488281)
#define   _Q10toIQ(A)    (((float) (A)) * 0.000976563)
#define   _Q9toIQ(A)     (((float) (A)) * 0.001953125)
#define   _Q8toIQ(A)     (((float) (A)) * 0.003906250)
#define   _Q7toIQ(A)     (((float) (A)) * 0.007812500)
#define   _Q6toIQ(A)     (((float) (A)) * 0.015625000)
#define   _Q5toIQ(A)     (((float) (A)) * 0.031250000)
#define   _Q4toIQ(A)     (((float) (A)) * 0.062500000)
#define   _Q3toIQ(A)     (((float) (A)) * 0.125000000)
#define   _Q2toIQ(A)     (((float) (A)) * 0.250000000)
#define   _Q1toIQ(A)     (((float) (A)) * 0.500000000)
//---------------------------------------------------------------------------
#define   _IQmpy(A,B)         ((A) * (B))
#define   _IQ30mpy(A,B)       ((A) * (B))
#define   _IQ29mpy(A,B)       ((A) * (B))
#define   _IQ28mpy(A,B)       ((A) * (B))
#define   _IQ27mpy(A,B)       ((A) * (B))
#define   _IQ26mpy(A,B)       ((A) * (B))
#define   _IQ25mpy(A,B)       ((A) * (B))
#define   _IQ24mpy(A,B)       ((A) * (B))
#define   _IQ23mpy(A,B)       ((A) * (B))
#define   _IQ22mpy(A,B)       ((A) * (B))
#define   _IQ21mpy(A,B)       ((A) * (B))
#define   _IQ20mpy(A,B)       ((A) * (B))
#define   _IQ19mpy(A,B)       ((A) * (B))
#define   _IQ18mpy(A,B)       ((A) * (B))
#define   _IQ17mpy(A,B)       ((A) * (B))
#define   _IQ16mpy(A,B)       ((A) * (B))
#define   _IQ15mpy(A,B)       ((A) * (B))
#define   _IQ14mpy(A,B)       ((A) * (B))
#define   _IQ13mpy(A,B)       ((A) * (B))
#define   _IQ12mpy(A,B)       ((A) * (B))
#define   _IQ11mpy(A,B)       ((A) * (B))
#define   _IQ10mpy(A,B)       ((A) * (B))
#define   _IQ9mpy(A,B)        ((A) * (B))
#define   _IQ8mpy(A,B)        ((A) * (B))
#define   _IQ7mpy(A,B)        ((A) * (B))
#define   _IQ6mpy(A,B)        ((A) * (B))
#define   _IQ5mpy(A,B)        ((A) * (B))
#define   _IQ4mpy(A,B)        ((A) * (B))
#define   _IQ3mpy(A,B)        ((A) * (B))
#define   _IQ2mpy(A,B)        ((A) * (B))
#define   _IQ1mpy(A,B)        ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQrmpy(A,B)        ((A) * (B))
#define   _IQ30rmpy(A,B)      ((A) * (B))
#define   _IQ29rmpy(A,B)      ((A) * (B))
#define   _IQ28rmpy(A,B)      ((A) * (B))
#define   _IQ27rmpy(A,B)      ((A) * (B))
#define   _IQ26rmpy(A,B)      ((A) * (B))
#define   _IQ25rmpy(A,B)      ((A) * (B))
#define   _IQ24rmpy(A,B)      ((A) * (B))
#define   _IQ23rmpy(A,B)      ((A) * (B))
#define   _IQ22rmpy(A,B)      ((A) * (B))
#define   _IQ21rmpy(A,B)      ((A) * (B))
#define   _IQ20rmpy(A,B)      ((A) * (B))
#define   _IQ19rmpy(A,B)      ((A) * (B))
#define   _IQ18rmpy(A,B)      ((A) * (B))
#define   _IQ17rmpy(A,B)      ((A) * (B))
#define   _IQ16rmpy(A,B)      ((A) * (B))
#define   _IQ15rmpy(A,B)      ((A) * (B))
#define   _IQ14rmpy(A,B)      ((A) * (B))
#define   _IQ13rmpy(A,B)      ((A) * (B))
#define   _IQ12rmpy(A,B)      ((A) * (B))
#define   _IQ11rmpy(A,B)      ((A) * (B))
#define   _IQ10rmpy(A,B)      ((A) * (B))
#define   _IQ9rmpy(A,B)       ((A) * (B))
#define   _IQ8rmpy(A,B)       ((A) * (B))
#define   _IQ7rmpy(A,B)       ((A) * (B))
#define   _IQ6rmpy(A,B)       ((A) * (B))
#define   _IQ5rmpy(A,B)       ((A) * (B))
#define   _IQ4rmpy(A,B)       ((A) * (B))
#define   _IQ3rmpy(A,B)       ((A) * (B))
#define   _IQ2rmpy(A,B)       ((A) * (B))
#define   _IQ1rmpy(A,B)       ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQrsmpy(A,B)       ((A) * (B))
#define   _IQ30rsmpy(A,B)     ((A) * (B))
#define   _IQ29rsmpy(A,B)     ((A) * (B))
#define   _IQ28rsmpy(A,B)     ((A) * (B))
#define   _IQ27rsmpy(A,B)     ((A) * (B))
#define   _IQ26rsmpy(A,B)     ((A) * (B))
#define   _IQ25rsmpy(A,B)     ((A) * (B))
#define   _IQ24rsmpy(A,B)     ((A) * (B))
#define   _IQ23rsmpy(A,B)     ((A) * (B))
#define   _IQ22rsmpy(A,B)     ((A) * (B))
#define   _IQ21rsmpy(A,B)     ((A) * (B))
#define   _IQ20rsmpy(A,B)     ((A) * (B))
#define   _IQ19rsmpy(A,B)     ((A) * (B))
#define   _IQ18rsmpy(A,B)     ((A) * (B))
#define   _IQ17rsmpy(A,B)     ((A) * (B))
#define   _IQ16rsmpy(A,B)     ((A) * (B))
#define   _IQ15rsmpy(A,B)     ((A) * (B))
#define   _IQ14rsmpy(A,B)     ((A) * (B))
#define   _IQ13rsmpy(A,B)     ((A) * (B))
#define   _IQ12rsmpy(A,B)     ((A) * (B))
#define   _IQ11rsmpy(A,B)     ((A) * (B))
#define   _IQ10rsmpy(A,B)     ((A) * (B))
#define   _IQ9rsmpy(A,B)      ((A) * (B))
#define   _IQ8rsmpy(A,B)      ((A) * (B))
#define   _IQ7rsmpy(A,B)      ((A) * (B))
#define   _IQ6rsmpy(A,B)      ((A) * (B))
#define   _IQ5rsmpy(A,B)      ((A) * (B))
#define   _IQ4rsmpy(A,B)      ((A) * (B))
#define   _IQ3rsmpy(A,B)      ((A) * (B))
#define   _IQ2rsmpy(A,B)      ((A) * (B))
#define   _IQ1rsmpy(A,B)      ((A) * (B))
//---------------------------------------------------------------------------
#define   _IQdiv(A,B)         ((A) / (B))
#define   _IQ30div(A,B)       ((A) / (B))
#define   _IQ29div(A,B)       ((A) / (B))
#define   _IQ28div(A,B)       ((A) / (B))
#define   _IQ27div(A,B)       ((A) / (B))
#define   _IQ26div(A,B)       ((A) / (B))
#define   _IQ25div(A,B)       ((A) / (B))
#define   _IQ24div(A,B)       ((A) / (B))
#define   _IQ23div(A,B)       ((A) / (B))
#define   _IQ22div(A,B)       ((A) / (B))
#define   _IQ21div(A,B)       ((A) / (B))
#define   _IQ20div(A,B)       ((A) / (B))
#define   _IQ19div(A,B)       ((A) / (B))
#define   _IQ18div(A,B)       ((A) / (B))
#define   _IQ17div(A,B)       ((A) / (B))
#define   _IQ16div(A,B)       ((A) / (B))
#define   _IQ15div(A,B)       ((A) / (B))
#define   _IQ14div(A,B)       ((A) / (B))
#define   _IQ13div(A,B)       ((A) / (B))
#define   _IQ12div(A,B)       ((A) / (B))
#define   _IQ11div(A,B)       ((A) / (B))
#define   _IQ10div(A,B)       ((A) / (B))
#define   _IQ9div(A,B)        ((A) / (B))
#define   _IQ8div(A,B)        ((A) / (B))
#define   _IQ7div(A,B)        ((A) / (B))
#define   _IQ6div(A,B)        ((A) / (B))
#define   _IQ5div(A,B)        ((A) / (B))
#define   _IQ4div(A,B)        ((A) / (B))
#define   _IQ3div(A,B)        ((A) / (B))
#define   _IQ2div(A,B)        ((A) / (B))
#define   _IQ1div(A,B)        ((A) / (B))
//---------------------------------------------------------------------------
#define   _IQsin(A)           sin(A)
#define   _IQ30sin(A)         sin(A)
#define   _IQ29sin(A)         sin(A)
#define   _IQ28sin(A)         sin(A)
#define   _IQ27sin(A)         sin(A)
#define   _IQ26sin(A)         sin(A)
#define   _IQ25sin(A)         sin(A)
#define   _IQ24sin(A)         sin(A)
#define   _IQ23sin(A)         sin(A)
#define   _IQ22sin(A)         sin(A)
#define   _IQ21sin(A)         sin(A)
#define   _IQ20sin(A)         sin(A)
#define   _IQ19sin(A)         sin(A)
#define   _IQ18sin(A)         sin(A)
#define   _IQ17sin(A)         sin(A)
#define   _IQ16sin(A)         sin(A)
#define   _IQ15sin(A)         sin(A)
#define   _IQ14sin(A)         sin(A)
#define   _IQ13sin(A)         sin(A)
#define   _IQ12sin(A)         sin(A)
#define   _IQ11sin(A)         sin(A)
#define   _IQ10sin(A)         sin(A)
#define   _IQ9sin(A)          sin(A)
#define   _IQ8sin(A)          sin(A)
#define   _IQ7sin(A)          sin(A)
#define   _IQ6sin(A)          sin(A)
#define   _IQ5sin(A)          sin(A)
#define   _IQ4sin(A)          sin(A)
#define   _IQ3sin(A)          sin(A)
#define   _IQ2sin(A)          sin(A)
#define   _IQ1sin(A)          sin(A)
//---------------------------------------------------------------------------
#define   _IQsinPU(A)         sin((A)*6.283185307)
#define   _IQ30sinPU(A)       sin((A)*6.283185307)
#define   _IQ29sinPU(A)       sin((A)*6.283185307)
#define   _IQ28sinPU(A)       sin((A)*6.283185307)
#define   _IQ27sinPU(A)       sin((A)*6.283185307)
#define   _IQ26sinPU(A)       sin((A)*6.283185307)
#define   _IQ25sinPU(A)       sin((A)*6.283185307)
#define   _IQ24sinPU(A)       sin((A)*6.283185307)
#define   _IQ23sinPU(A)       sin((A)*6.283185307)
#define   _IQ22sinPU(A)       sin((A)*6.283185307)
#define   _IQ21sinPU(A)       sin((A)*6.283185307)
#define   _IQ20sinPU(A)       sin((A)*6.283185307)
#define   _IQ19sinPU(A)       sin((A)*6.283185307)
#define   _IQ18sinPU(A)       sin((A)*6.283185307)
#define   _IQ17sinPU(A)       sin((A)*6.283185307)
#define   _IQ16sinPU(A)       sin((A)*6.283185307)
#define   _IQ15sinPU(A)       sin((A)*6.283185307)
#define   _IQ14sinPU(A)       sin((A)*6.283185307)
#define   _IQ13sinPU(A)       sin((A)*6.283185307)
#define   _IQ12sinPU(A)       sin((A)*6.283185307)
#define   _IQ11sinPU(A)       sin((A)*6.283185307)
#define   _IQ10sinPU(A)       sin((A)*6.283185307)
#define   _IQ9sinPU(A)        sin((A)*6.283185307)
#define   _IQ8sinPU(A)        sin((A)*6.283185307)
#define   _IQ7sinPU(A)        sin((A)*6.283185307)
#define   _IQ6sinPU(A)        sin((A)*6.283185307)
#define   _IQ5sinPU(A)        sin((A)*6.283185307)
#define   _IQ4sinPU(A)        sin((A)*6.283185307)
#define   _IQ3sinPU(A)        sin((A)*6.283185307)
#define   _IQ2sinPU(A)        sin((A)*6.283185307)
#define   _IQ1sinPU(A)        sin((A)*6.283185307)
//---------------------------------------------------------------------------
#define   _IQcos(A)           cos(A)
#define   _IQ30cos(A)         cos(A)
#define   _IQ29cos(A)         cos(A)
#define   _IQ28cos(A)         cos(A)
#define   _IQ27cos(A)         cos(A)
#define   _IQ26cos(A)         cos(A)
#define   _IQ25cos(A)         cos(A)
#define   _IQ24cos(A)         cos(A)
#define   _IQ23cos(A)         cos(A)
#define   _IQ22cos(A)         cos(A)
#define   _IQ21cos(A)         cos(A)
#define   _IQ20cos(A)         cos(A)
#define   _IQ19cos(A)         cos(A)
#define   _IQ18cos(A)         cos(A)
#define   _IQ17cos(A)         cos(A)
#define   _IQ16cos(A)         cos(A)
#define   _IQ15cos(A)         cos(A)
#define   _IQ14cos(A)         cos(A)
#define   _IQ13cos(A)         cos(A)
#define   _IQ12cos(A)         cos(A)
#define   _IQ11cos(A)         cos(A)
#define   _IQ10cos(A)         cos(A)
#define   _IQ9cos(A)          cos(A)
#define   _IQ8cos(A)          cos(A)
#define   _IQ7cos(A)          cos(A)
#define   _IQ6cos(A)          cos(A)
#define   _IQ5cos(A)          cos(A)
#define   _IQ4cos(A)          cos(A)
#define   _IQ3cos(A)          cos(A)
#define   _IQ2cos(A)          cos(A)
#define   _IQ1cos(A)          cos(A)
//---------------------------------------------------------------------------
#define   _IQcosPU(A)         cos((A)*6.283185307)
#define   _IQ30cosPU(A)       cos((A)*6.283185307)
#define   _IQ29cosPU(A)       cos((A)*6.283185307)
#define   _IQ28cosPU(A)       cos((A)*6.283185307)
#define   _IQ27cosPU(A)       cos((A)*6.283185307)
#define   _IQ26cosPU(A)       cos((A)*6.283185307)
#define   _IQ25cosPU(A)       cos((A)*6.283185307)
#define   _IQ24cosPU(A)       cos((A)*6.283185307)
#define   _IQ23cosPU(A)       cos((A)*6.283185307)
#define   _IQ22cosPU(A)       cos((A)*6.283185307)
#define   _IQ21cosPU(A)       cos((A)*6.283185307)
#define   _IQ20cosPU(A)       cos((A)*6.283185307)
#define   _IQ19cosPU(A)       cos((A)*6.283185307)
#define   _IQ18cosPU(A)       cos((A)*6.283185307)
#define   _IQ17cosPU(A)       cos((A)*6.283185307)
#define   _IQ16cosPU(A)       cos((A)*6.283185307)
#define   _IQ15cosPU(A)       cos((A)*6.283185307)
#define   _IQ14cosPU(A)       cos((A)*6.283185307)
#define   _IQ13cosPU(A)       cos((A)*6.283185307)
#define   _IQ12cosPU(A)       cos((A)*6.283185307)
#define   _IQ11cosPU(A)       cos((A)*6.283185307)
#define   _IQ10cosPU(A)       cos((A)*6.283185307)
#define   _IQ9cosPU(A)        cos((A)*6.283185307)
#define   _IQ8cosPU(A)        cos((A)*6.283185307)
#define   _IQ7cosPU(A)        cos((A)*6.283185307)
#define   _IQ6cosPU(A)        cos((A)*6.283185307)
#define   _IQ5cosPU(A)        cos((A)*6.283185307)
#define   _IQ4cosPU(A)        cos((A)*6.283185307)
#define   _IQ3cosPU(A)        cos((A)*6.283185307)
#define   _IQ2cosPU(A)        cos((A)*6.283185307)
#define   _IQ1cosPU(A)        cos((A)*6.283185307)
//---------------------------------------------------------------------------
#define   _IQatan(A)          atan(A)
#define   _IQ30atan(A)        atan(A)
#define   _IQ29atan(A)        atan(A)
#define   _IQ28atan(A)        atan(A)
#define   _IQ27atan(A)        atan(A)
#define   _IQ26atan(A)        atan(A)
#define   _IQ25atan(A)        atan(A)
#define   _IQ24atan(A)        atan(A)
#define   _IQ23atan(A)        atan(A)
#define   _IQ22atan(A)        atan(A)
#define   _IQ21atan(A)        atan(A)
#define   _IQ20atan(A)        atan(A)
#define   _IQ19atan(A)        atan(A)
#define   _IQ18atan(A)        atan(A)
#define   _IQ17atan(A)        atan(A)
#define   _IQ16atan(A)        atan(A)
#define   _IQ15atan(A)        atan(A)
#define   _IQ14atan(A)        atan(A)
#define   _IQ13atan(A)        atan(A)
#define   _IQ12atan(A)        atan(A)
#define   _IQ11atan(A)        atan(A)
#define   _IQ10atan(A)        atan(A)
#define   _IQ9atan(A)         atan(A)
#define   _IQ8atan(A)         atan(A)
#define   _IQ7atan(A)         atan(A)
#define   _IQ6atan(A)         atan(A)
#define   _IQ5atan(A)         atan(A)
#define   _IQ4atan(A)         atan(A)
#define   _IQ3atan(A)         atan(A)
#define   _IQ2atan(A)         atan(A)
#define   _IQ1atan(A)         atan(A)
//---------------------------------------------------------------------------
#define   _IQatan2(A,B)       atan2(A,B)
#define   _IQ30atan2(A,B)     atan2(A,B)
#define   _IQ29atan2(A,B)     atan2(A,B)
#define   _IQ28atan2(A,B)     atan2(A,B)
#define   _IQ27atan2(A,B)     atan2(A,B)
#define   _IQ26atan2(A,B)     atan2(A,B)
#define   _IQ25atan2(A,B)     atan2(A,B)
#define   _IQ24atan2(A,B)     atan2(A,B)
#define   _IQ23atan2(A,B)     atan2(A,B)
#define   _IQ22atan2(A,B)     atan2(A,B)
#define   _IQ21atan2(A,B)     atan2(A,B)
#define   _IQ20atan2(A,B)     atan2(A,B)
#define   _IQ19atan2(A,B)     atan2(A,B)
#define   _IQ18atan2(A,B)     atan2(A,B)
#define   _IQ17atan2(A,B)     atan2(A,B)
#define   _IQ16atan2(A,B)     atan2(A,B)
#define   _IQ15atan2(A,B)     atan2(A,B)
#define   _IQ14atan2(A,B)     atan2(A,B)
#define   _IQ13atan2(A,B)     atan2(A,B)
#define   _IQ12atan2(A,B)     atan2(A,B)
#define   _IQ11atan2(A,B)     atan2(A,B)
#define   _IQ10atan2(A,B)     atan2(A,B)
#define   _IQ9atan2(A,B)      atan2(A,B)
#define   _IQ8atan2(A,B)      atan2(A,B)
#define   _IQ7atan2(A,B)      atan2(A,B)
#define   _IQ6atan2(A,B)      atan2(A,B)
#define   _IQ5atan2(A,B)      atan2(A,B)
#define   _IQ4atan2(A,B)      atan2(A,B)
#define   _IQ3atan2(A,B)      atan2(A,B)
#define   _IQ2atan2(A,B)      atan2(A,B)
#define   _IQ1atan2(A,B)      atan2(A,B)
//---------------------------------------------------------------------------
#define   _IQatan2PU(A,B)     ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ30atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ29atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ28atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ27atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ26atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ25atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ24atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ23atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ22atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ21atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ20atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ19atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ18atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ17atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ16atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ15atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ14atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ13atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ12atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ11atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ10atan2PU(A,B)   ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ9atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ8atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ7atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ6atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ5atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ4atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ3atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ2atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
#define   _IQ1atan2PU(A,B)    ((atan2(A,B)/6.283185307) >= 0.0 ? (atan2(A,B)/6.283185307):1.0 + (atan2(A,B)/6.283185307))
//---------------------------------------------------------------------------
#define   _IQsqrt(A)          sqrt(A)
#define   _IQ30sqrt(A)        sqrt(A)
#define   _IQ29sqrt(A)        sqrt(A)
#define   _IQ28sqrt(A)        sqrt(A)
#define   _IQ27sqrt(A)        sqrt(A)
#define   _IQ26sqrt(A)        sqrt(A)
#define   _IQ25sqrt(A)        sqrt(A)
#define   _IQ24sqrt(A)        sqrt(A)
#define   _IQ23sqrt(A)        sqrt(A)
#define   _IQ22sqrt(A)        sqrt(A)
#define   _IQ21sqrt(A)        sqrt(A)
#define   _IQ20sqrt(A)        sqrt(A)
#define   _IQ19sqrt(A)        sqrt(A)
#define   _IQ18sqrt(A)        sqrt(A)
#define   _IQ17sqrt(A)        sqrt(A)
#define   _IQ16sqrt(A)        sqrt(A)
#define   _IQ15sqrt(A)        sqrt(A)
#define   _IQ14sqrt(A)        sqrt(A)
#define   _IQ13sqrt(A)        sqrt(A)
#define   _IQ12sqrt(A)        sqrt(A)
#define   _IQ11sqrt(A)        sqrt(A)
#define   _IQ10sqrt(A)        sqrt(A)
#define   _IQ9sqrt(A)         sqrt(A)
#define   _IQ8sqrt(A)         sqrt(A)
#define   _IQ7sqrt(A)         sqrt(A)
#define   _IQ6sqrt(A)         sqrt(A)
#define   _IQ5sqrt(A)         sqrt(A)
#define   _IQ4sqrt(A)         sqrt(A)
#define   _IQ3sqrt(A)         sqrt(A)
#define   _IQ2sqrt(A)         sqrt(A)
#define   _IQ1sqrt(A)         sqrt(A)
//---------------------------------------------------------------------------
#define   _IQisqrt(A)         (1.0/sqrt(A))
#define   _IQ30isqrt(A)       (1.0/sqrt(A))
#define   _IQ29isqrt(A)       (1.0/sqrt(A))
#define   _IQ28isqrt(A)       (1.0/sqrt(A))
#define   _IQ27isqrt(A)       (1.0/sqrt(A))
#define   _IQ26isqrt(A)       (1.0/sqrt(A))
#define   _IQ25isqrt(A)       (1.0/sqrt(A))
#define   _IQ24isqrt(A)       (1.0/sqrt(A))
#define   _IQ23isqrt(A)       (1.0/sqrt(A))
#define   _IQ22isqrt(A)       (1.0/sqrt(A))
#define   _IQ21isqrt(A)       (1.0/sqrt(A))
#define   _IQ20isqrt(A)       (1.0/sqrt(A))
#define   _IQ19isqrt(A)       (1.0/sqrt(A))
#define   _IQ18isqrt(A)       (1.0/sqrt(A))
#define   _IQ17isqrt(A)       (1.0/sqrt(A))
#define   _IQ16isqrt(A)       (1.0/sqrt(A))
#define   _IQ15isqrt(A)       (1.0/sqrt(A))
#define   _IQ14isqrt(A)       (1.0/sqrt(A))
#define   _IQ13isqrt(A)       (1.0/sqrt(A))
#define   _IQ12isqrt(A)       (1.0/sqrt(A))
#define   _IQ11isqrt(A)       (1.0/sqrt(A))
#define   _IQ10isqrt(A)       (1.0/sqrt(A))
#define   _IQ9isqrt(A)        (1.0/sqrt(A))
#define   _IQ8isqrt(A)        (1.0/sqrt(A))
#define   _IQ7isqrt(A)        (1.0/sqrt(A))
#define   _IQ6isqrt(A)        (1.0/sqrt(A))
#define   _IQ5isqrt(A)        (1.0/sqrt(A))
#define   _IQ4isqrt(A)        (1.0/sqrt(A))
#define   _IQ3isqrt(A)        (1.0/sqrt(A))
#define   _IQ2isqrt(A)        (1.0/sqrt(A))
#define   _IQ1isqrt(A)        (1.0/sqrt(A))
//---------------------------------------------------------------------------
#define   _IQint(A)           ((long) (A))
#define   _IQ30int(A)         ((long) (A))
#define   _IQ29int(A)         ((long) (A))
#define   _IQ28int(A)         ((long) (A))
#define   _IQ27int(A)         ((long) (A))
#define   _IQ26int(A)         ((long) (A))
#define   _IQ25int(A)         ((long) (A))
#define   _IQ24int(A)         ((long) (A))
#define   _IQ23int(A)         ((long) (A))
#define   _IQ22int(A)         ((long) (A))
#define   _IQ21int(A)         ((long) (A))
#define   _IQ20int(A)         ((long) (A))
#define   _IQ19int(A)         ((long) (A))
#define   _IQ18int(A)         ((long) (A))
#define   _IQ17int(A)         ((long) (A))
#define   _IQ16int(A)         ((long) (A))
#define   _IQ15int(A)         ((long) (A))
#define   _IQ14int(A)         ((long) (A))
#define   _IQ13int(A)         ((long) (A))
#define   _IQ12int(A)         ((long) (A))
#define   _IQ11int(A)         ((long) (A))
#define   _IQ10int(A)         ((long) (A))
#define   _IQ9int(A)          ((long) (A))
#define   _IQ8int(A)          ((long) (A))
#define   _IQ7int(A)          ((long) (A))
#define   _IQ6int(A)          ((long) (A))
#define   _IQ5int(A)          ((long) (A))
#define   _IQ4int(A)          ((long) (A))
#define   _IQ3int(A)          ((long) (A))
#define   _IQ2int(A)          ((long) (A))
#define   _IQ1int(A)          ((long) (A))
//---------------------------------------------------------------------------
#define   _IQfrac(A)          ((A) - (float)((long) (A)))
#define   _IQ30frac(A)        ((A) - (float)((long) (A)))
#define   _IQ29frac(A)        ((A) - (float)((long) (A)))
#define   _IQ28frac(A)        ((A) - (float)((long) (A)))
#define   _IQ27frac(A)        ((A) - (float)((long) (A)))
#define   _IQ26frac(A)        ((A) - (float)((long) (A)))
#define   _IQ25frac(A)        ((A) - (float)((long) (A)))
#define   _IQ24frac(A)        ((A) - (float)((long) (A)))
#define   _IQ23frac(A)        ((A) - (float)((long) (A)))
#define   _IQ22frac(A)        ((A) - (float)((long) (A)))
#define   _IQ21frac(A)        ((A) - (float)((long) (A)))
#define   _IQ20frac(A)        ((A) - (float)((long) (A)))
#define   _IQ19frac(A)        ((A) - (float)((long) (A)))
#define   _IQ18frac(A)        ((A) - (float)((long) (A)))
#define   _IQ17frac(A)        ((A) - (float)((long) (A)))
#define   _IQ16frac(A)        ((A) - (float)((long) (A)))
#define   _IQ15frac(A)        ((A) - (float)((long) (A)))
#define   _IQ14frac(A)        ((A) - (float)((long) (A)))
#define   _IQ13frac(A)        ((A) - (float)((long) (A)))
#define   _IQ12frac(A)        ((A) - (float)((long) (A)))
#define   _IQ11frac(A)        ((A) - (float)((long) (A)))
#define   _IQ10frac(A)        ((A) - (float)((long) (A)))
#define   _IQ9frac(A)         ((A) - (float)((long) (A)))
#define   _IQ8frac(A)         ((A) - (float)((long) (A)))
#define   _IQ7frac(A)         ((A) - (float)((long) (A)))
#define   _IQ6frac(A)         ((A) - (float)((long) (A)))
#define   _IQ5frac(A)         ((A) - (float)((long) (A)))
#define   _IQ4frac(A)         ((A) - (float)((long) (A)))
#define   _IQ3frac(A)         ((A) - (float)((long) (A)))
#define   _IQ2frac(A)         ((A) - (float)((long) (A)))
#define   _IQ1frac(A)         ((A) - (float)((long) (A)))
//---------------------------------------------------------------------------
#define   _IQmpyIQX(A, IQA, B, IQB)    ((A)*(B))    
#define   _IQ30mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ29mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ28mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ27mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ26mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ25mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ24mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ23mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ22mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ21mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ20mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ19mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ18mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ17mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ16mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ15mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ14mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ13mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ12mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ11mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ10mpyIQX(A, IQA, B, IQB)  ((A)*(B))    
#define   _IQ9mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ8mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ7mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ6mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ5mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ4mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ3mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ2mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
#define   _IQ1mpyIQX(A, IQA, B, IQB)   ((A)*(B))    
//---------------------------------------------------------------------------
#define   _IQmpyI32(A,B)      ((A) * (float) (B))    
#define   _IQ30mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ29mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ28mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ27mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ26mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ25mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ24mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ23mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ22mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ21mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ20mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ19mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ18mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ17mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ16mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ15mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ14mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ13mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ12mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ11mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ10mpyI32(A,B)    ((A) * (float) (B))
#define   _IQ9mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ8mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ7mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ6mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ5mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ4mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ3mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ2mpyI32(A,B)     ((A) * (float) (B))
#define   _IQ1mpyI32(A,B)     ((A) * (float) (B))
//---------------------------------------------------------------------------
#define   _IQmpyI32int(A,B)   ((long) ((A) * (float) (B)))
#define   _IQ30mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ29mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ28mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ27mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ26mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ25mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ24mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ23mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ22mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ21mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ20mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ19mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ18mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ17mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ16mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ15mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ14mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ13mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ12mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ11mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ10mpyI32int(A,B) ((long) ((A) * (float) (B)))
#define   _IQ9mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ8mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ7mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ6mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ5mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ4mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ3mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ2mpyI32int(A,B)  ((long) ((A) * (float) (B)))
#define   _IQ1mpyI32int(A,B)  ((long) ((A) * (float) (B)))
//---------------------------------------------------------------------------
#define   _IQmpyI32frac(A,B)    ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ30mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ29mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ28mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ27mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ26mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ25mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ24mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ23mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ22mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ21mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ20mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ19mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ18mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ17mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ16mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ15mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ14mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ13mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ12mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ11mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ10mpyI32frac(A,B)  ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ9mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ8mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ7mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ6mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ5mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ4mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ3mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ2mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
#define   _IQ1mpyI32frac(A,B)   ((A) - (float)((long) ((A) * (float) (B))))
//---------------------------------------------------------------------------
#define   _IQmag(A,B)         sqrt((A)*(A) + (B)*(B))
#define   _IQ30mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ29mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ28mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ27mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ26mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ25mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ24mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ23mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ22mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ21mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ20mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ19mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ18mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ17mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ16mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ15mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ14mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ13mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ12mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ11mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ10mag(A,B)       sqrt((A)*(A) + (B)*(B))
#define   _IQ9mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ8mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ7mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ6mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ5mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ4mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ3mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ2mag(A,B)        sqrt((A)*(A) + (B)*(B))
#define   _IQ1mag(A,B)        sqrt((A)*(A) + (B)*(B))
//---------------------------------------------------------------------------
#define   _atoIQ(A)           atof(A)
#define   _atoIQ30(A)         atof(A)
#define   _atoIQ29(A)         atof(A)
#define   _atoIQ28(A)         atof(A)
#define   _atoIQ27(A)         atof(A)
#define   _atoIQ26(A)         atof(A)
#define   _atoIQ25(A)         atof(A)
#define   _atoIQ24(A)         atof(A)
#define   _atoIQ23(A)         atof(A)
#define   _atoIQ22(A)         atof(A)
#define   _atoIQ21(A)         atof(A)
#define   _atoIQ20(A)         atof(A)
#define   _atoIQ19(A)         atof(A)
#define   _atoIQ18(A)         atof(A)
#define   _atoIQ17(A)         atof(A)
#define   _atoIQ16(A)         atof(A)
#define   _atoIQ15(A)         atof(A)
#define   _atoIQ14(A)         atof(A)
#define   _atoIQ13(A)         atof(A)
#define   _atoIQ12(A)         atof(A)
#define   _atoIQ11(A)         atof(A)
#define   _atoIQ10(A)         atof(A)
#define   _atoIQ9(A)          atof(A)
#define   _atoIQ8(A)          atof(A)
#define   _atoIQ7(A)          atof(A)
#define   _atoIQ6(A)          atof(A)
#define   _atoIQ5(A)          atof(A)
#define   _atoIQ4(A)          atof(A)
#define   _atoIQ3(A)          atof(A)
#define   _atoIQ2(A)          atof(A)
#define   _atoIQ1(A)          atof(A)
//###########################################################################
#endif  // No more.
//###########################################################################

#endif /* __IQMATHLIB_H_INCLUDED__ */
//FILE_TAG: C:\tidcs\c28\dsp280x\v110\DSP280x_common\include\SFO.h 
//###########################################################################
//
// FILE:   SFO.H
//
// TITLE:  Scale Factor Optimizer Library Interface Header
//         
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.01| 09 Jan 2004 | TI   | New module
//###########################################################################


//============================================================================
// Description:		This header provides the function call interface
// 			for the scale factor optimizer for the 'F280x.
//============================================================================


//============================================================================
// Multiple include Guard
//============================================================================
#ifndef __4090522384024n8273240x3438jx43087401r34ru32r0___ 
#define __4090522384024n8273240x3438jx43087401r34ru32r0___

//============================================================================
// C++ namespace
//============================================================================
#ifdef __cplusplus
extern "C" {
#endif


//============================================================================
// Function prototypes for MEP SFO
//============================================================================
void SFO_MepEn(int nEpwmModule);
void SFO_MepDis(int nEpwmModule);

//============================================================================
// Multiple include Guard
//============================================================================
#endif // End: Multiple include Guard

//============================================================================
// C++ namespace
//============================================================================
#ifdef __cplusplus
}
#endif /* extern "C" */
