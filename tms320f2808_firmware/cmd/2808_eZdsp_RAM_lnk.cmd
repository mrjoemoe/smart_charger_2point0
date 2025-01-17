/*
// TI File $Revision: /main/1 $
// Checkin $Date: December 1, 2004   11:04:54 $
//###########################################################################
//
// FILE:    2808_eZdsp_RAM_lnk.cmd
//
// TITLE:   Linker Command File For 2808 examples that run out of RAM
//
//          This ONLY includes SARAM that is not secure on the 2808 device.
//          This was done so all of these examples would run on 
//          a 2808 eZdsp "out of the box".  
//
//          What this means is in most cases you will want to move to 
//          another memory map file which has more memory defined.  
//
//###########################################################################
// $TI Release: DSP280x V1.30 $
// $Release Date: February 10, 2006 $
//###########################################################################
*/

/* ======================================================
// For Code Composer Studio V2.2 and later
// ---------------------------------------
// In addition to this memory linker command file, 
// add the header linker command file directly to the project. 
// The header linker command file is required to link the
// peripheral structures to the proper locations within 
// the memory map.
//
// The header linker files are found in <base>\DSP281x_Headers\cmd
//   
// For BIOS applications add:      DSP280x_Headers_BIOS.cmd
// For nonBIOS applications add:   DSP280x_Headers_nonBIOS.cmd    
========================================================= */

/* ======================================================
// For Code Composer Studio prior to V2.2
// --------------------------------------
// 1) Use one of the following -l statements to include the 
// header linker command file in the project. The header linker
// file is required to link the peripheral structures to the proper 
// locations within the memory map                                    */

/* Uncomment this line to include file only for non-BIOS applications */
/* -l DSP280x_Headers_nonBIOS.cmd */

/* Uncomment this line to include file only for BIOS applications */
/* -l DSP280x_Headers_BIOS.cmd */

/* 2) In your project add the path to <base>\DSP280x_headers\cmd to the
   library search path under project->build options, linker tab, 
   library search path (-i).
/*========================================================= */



MEMORY
{
PAGE 0 :
   /* For this example, H0 is split between PAGE 0 and PAGE 1 */  
   /* BEGIN is used for the "boot to SARAM" bootloader mode   */
   
   BEGIN      : origin = 0x000000, length = 0x000002             
   RAMM0      : origin = 0x000002, length = 0x0003FE
   RAMH0      : origin = 0x3FA000, length = 0x002000 
   RESET      : origin = 0x3FFFC0, length = 0x000002
   BOOTROM    : origin = 0x3FF000, length = 0x000FC0               

         
PAGE 1 : 

   /* For this example, H0 is split between PAGE 0 and PAGE 1 */

   RAMM1    : origin = 0x000400, length = 0x000400
   RAML0L1	: origin = 0x3F8000, length = 0x002000        
}
 
 
SECTIONS
{
   /* Setup for "boot to SARAM" mode: 
      The codestart section (found in DSP28_CodeStartBranch.asm)
      re-directs execution to the start of user code.  */
   codestart        : > BEGIN,      PAGE = 0
   ramfuncs         : > RAMM0       PAGE = 0  
   .text            : > RAMH0,      PAGE = 0
   .cinit           : > RAMM0,      PAGE = 0
   .pinit           : > RAMM0,      PAGE = 0
   .switch          : > RAMM0,      PAGE = 0
   .reset           : > RESET,      PAGE = 0, TYPE = DSECT /* not used, */
   
   .stack           : > RAMM1,      PAGE = 1
   .ebss            : > RAML0L1,    PAGE = 1
   .econst          : > RAML0L1,    PAGE = 1      
   .esysmem         : > RAMM1,      PAGE = 1
   .sysmem          : > RAML0L1,    PAGE = 1
   .cio				: > RAML0L1,	PAGE = 1

   IQmath           : >  RAMH0,   PAGE = 0
   IQmathTables     : >  BOOTROM, type = NOLOAD, PAGE = 0

     
}

/*
//===========================================================================
// End of file.
//===========================================================================
*/