/* Debug.CMD */
/*----------------------------------------------------------------------------------*/
/*	FILE:			F2808_RAM_DPS.CMD                                               */
/*                                                                                  */
/*	Description:	Linker command file for custom sections included in the         */
/*					DPS control library                                             */
/*                                                                                  */
/*	$Revision: /main/1 $                                                            */
/*      $Date: September 28, 2006   14:07:07 $                                         */
/*                                                                                  */
/*  Target:  		TMS320F280x                                                     */
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
/*  06/30/05  | New release.                                    					*/
/*  11/15/05  | Documentation and source cleanup.	            					*/
/*  08/11/06  | Updated for integration into the DPS 						project */
/*----------------------------------------------------------------------------------*/
 MEMORY
{
PAGE 0:
   /* For this example, H0 is split between PAGE 0 and PAGE 1 */  
   /* BEGIN is used for the "boot to SARAM" bootloader mode   */


   RAMM0      : origin = 0x000002, length = 0x0003FE
   PRAMH0     : origin = 0x3FA000, length = 0x001800 

   RAML0       : origin = 0x008000, length = 0x001000     /* on-chip RAM block L0 */
   OTP         : origin = 0x3D7800, length = 0x000800     /* on-chip OTP */
   FLASHD      : origin = 0x3E8000, length = 0x004000     /* on-chip FLASH */
   FLASHC      : origin = 0x3EC000, length = 0x004000     /* on-chip FLASH */
   FLASHA      : origin = 0x3F4000, length = 0x003F80     /* on-chip FLASH */
   CSM_RSVD    : origin = 0x3F7F80, length = 0x000076     /* Part of FLASHA.  Program with all 0x0000 when CSM is in use. */
   BEGIN       : origin = 0x3F7FF6, length = 0x000002     /* Part of FLASHA.  Used for "boot to Flash" bootloader mode. */
   CSM_PWL     : origin = 0x3F7FF8, length = 0x000008     /* Part of FLASHA.  CSM password locations in FLASHA */
   ROM         : origin = 0x3FF000, length = 0x000FC0     /* Boot ROM */
   RESET       : origin = 0x3FFFC0, length = 0x000002     /* part of boot ROM  */
   VECTORS     : origin = 0x3FFFC2, length = 0x00003E     /* part of boot ROM  */

PAGE 1: 

   /* For this example, H0 is split between PAGE 0 and PAGE 1 */

   RAMM1      : origin = 0x000400, length = 0x000400
   DRAMH0     : origin = 0x3FB800, length = 0x000600

}
 
 
SECTIONS
{
   /* Allocate program areas: */
   .cinit              	: > FLASHA,     PAGE = 0
   .pinit              	: > FLASHA,     PAGE = 0
   .text               	: > FLASHA,     PAGE = 0

   codestart           : > BEGIN       PAGE = 0
   
   
   ramfuncs            : LOAD = FLASHA, 
                         RUN = RAML0, 
                         LOAD_START(_RamfuncsLoadStart),
                         LOAD_END(_RamfuncsLoadEnd),
                         RUN_START(_RamfuncsRunStart),
                         PAGE = 0

   csmpasswds          : > CSM_PWL     PAGE = 0
   csm_rsvd            : > CSM_RSVD    PAGE = 0
   
   /* Allocate uninitalized data sections: */
   .stack           : > RAMM1,      PAGE = 1
   .ebss            : > DRAMH0,     PAGE = 1
   .esysmem         : > RAMM1,      PAGE = 1

   /* Initalized sections go in Flash */
   /* For SDFlash to program these, they must be allocated to page 0 */
   .econst             : > FLASHA      PAGE = 0
   .switch             : > FLASHA      PAGE = 0      

   /* Allocate IQ math areas: */
   IQmath              : > FLASHC      PAGE = 0                  /* Math Code */
   IQmathTables        : > ROM         PAGE = 0, TYPE = NOLOAD   /* Math Tables In ROM */

   /* .reset is a standard section used by the compiler.  It contains the */ 
   /* the address of the start of _c_int00 for C Code.   /*
   /* When using the boot ROM this section and the CPU vector */
   /* table is not needed.  Thus the default type is set here to  */
   /* DSECT  */ 
   .reset              : > RESET,      PAGE = 0, TYPE = DSECT
   vectors             : > VECTORS     PAGE = 0, TYPE = DSECT
}
    
    
SECTIONS
{
	Net_terminals			: block(0x40) > DRAMH0, PAGE = 1
	//SIN_DATA				: block(0x200) > DRAMH0, PAGE = 1
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
	PFCIL_data				: block(0x40) > DRAMH0, PAGE = 1
	PSFB_DRV_Data       	: block(0x40) > DRAMH0, PAGE = 1
	SINTBL       			: block(0x40) > DRAMH0, PAGE = 1
	ADC2CH_CONT_DRV_Data	: block(0x40) > DRAMH0, PAGE = 1
}



 
