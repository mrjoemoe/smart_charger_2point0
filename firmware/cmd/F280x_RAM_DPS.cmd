/*----------------------------------------------------------------------------------*/
/*	FILE:			F2808_RAM_DPS.CMD                                               */
/*                                                                                  */
/*	Description:	Linker command file for custom sections included in the         */
/*					DPS control library                                             */
/*                                                                                  */
/*	$Revision: /main/2 $                                                                  */
/*      $Date: September 28, 2006   14:07:11 $                                                                      */
/*                                                                                  */
/*      Target:  		TMS320F280x                                                     */
/*                                                                                  */
/*	Type: 			Device dependent                                                */
/*                                                                                  */
/*----------------------------------------------------------------------------------*/
/*  Copyright Texas Instruments © 2004-2005                                			*/	
/*----------------------------------------------------------------------------------*/
/*  Revision History:                                                               */
/*----------------------------------------------------------------------------------*/
/*  Date	  | Description                                                         */
/*----------------------------------------------------------------------------------*/
/*  06/30/05  | Release 1.0  		New release.                                    */
/*  11/15/05  | Release 1.1  		Documentation and source cleanup.	    */
/*----------------------------------------------------------------------------------*/
 MEMORY
{
PAGE 0:
   /* For this example, H0 is split between PAGE 0 and PAGE 1 */  
   /* BEGIN is used for the "boot to SARAM" bootloader mode   */
   
   BEGIN      : origin = 0x000000, length = 0x000002             
   RAMM0      : origin = 0x000002, length = 0x0003FE
   PRAMH0     : origin = 0x3FA000, length = 0x001800 
   RESET      : origin = 0x3FFFC0, length = 0x000002
   BOOTROM    : origin = 0x3FF000, length = 0x000FC0               

         
PAGE 1: 

   /* For this example, H0 is split between PAGE 0 and PAGE 1 */

   RAMM1      : origin = 0x000400, length = 0x000400
   DRAMH0     : origin = 0x3FB800, length = 0x000600
}
 
 
SECTIONS
{
   /* Setup for "boot to SARAM" mode: 
      The codestart section (found in DSP28_CodeStartBranch.asm)
      re-directs execution to the start of user code.  */

   codestart        : > BEGIN,      PAGE = 0
   ramfuncs         : > RAMM0       PAGE = 0  
   .text            : > PRAMH0,     PAGE = 0
   .cinit           : > RAMM0,      PAGE = 0
   .pinit           : > RAMM0,      PAGE = 0
   .switch          : > RAMM0,      PAGE = 0
   .reset           : > RESET,      PAGE = 0, TYPE = DSECT /* not used, */
   
   .stack           : > RAMM1,      PAGE = 1
   .ebss            : > DRAMH0,     PAGE = 1
   .econst          : > DRAMH0,     PAGE = 1      
   .esysmem         : > RAMM1,      PAGE = 1

   IQmath           : > PRAMH0,   PAGE = 0
   IQmathTables     : > BOOTROM, type = NOLOAD, PAGE = 0

	cldata          : > RAMM1,     PAGE = 1
  	clcoeff         : > RAMM0,     PAGE = 0      
}
    
    
SECTIONS
{
	Net_terminals			: block(0x40) > DRAMH0, PAGE = 1
	SINData					: block(0x40) > DRAMH0, PAGE = 1
	CNTL_coeff				: block(0x40) > DRAMH0, PAGE = 1
	PFC2PHIL_data 			: block(0x40) > DRAMH0, PAGE = 1
	CNTL_2P2Z_Data1			: block(0x40) > DRAMH0, PAGE = 1
	CNTL_2P2Z_Data2			: block(0x40) > DRAMH0, PAGE = 1
	FW1data 				: block(0x40) > DRAMH0, PAGE = 1
	ADC5CH_CONT_DRV_Data    : block(0x40) > DRAMH0, PAGE = 1
	CNTL_PI_Data1    		: block(0x40) > DRAMH0, PAGE = 1
	CNTL_PI_Data2    		: block(0x40) > DRAMH0, PAGE = 1
	ALR_data				: block(0x40) > DRAMH0, PAGE = 1
	BIQUAD_data				: block(0x40) > DRAMH0, PAGE = 1
	ISQR_data				: block(0x40) > DRAMH0, PAGE = 1
	BCA_data				: block(0x40) > DRAMH0, PAGE = 1
	PIC_data				: block(0x40) > DRAMH0, PAGE = 1
	SL_data					: block(0x40) > DRAMH0, PAGE = 1
 	HRPWMDAC_DRV_Data		: block(0x40) > DRAMH0, PAGE = 1
	SINTBL       			: block(0x40) > DRAMH0, PAGE = 1
	HRBUCK_DRV_Data    		: block(0x40) > DRAMH0, PAGE = 1
	ADC2CH_CONT_DRV_Data	: block(0x40) > DRAMH0, PAGE = 1
	ADC1CH_CONT_DRV_Data	: block(0x40) > DRAMH0, PAGE = 1
	PSFB_DRV_Data			: block(0x40) > DRAMH0, PAGE = 1
	Controller				: block(0x40) > DRAMH0, PAGE = 1
}



 
