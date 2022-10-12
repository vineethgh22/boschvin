/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z32VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-12, 14:57, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "row.h"
#include "BitsIoLdd1.h"
#include "col.h"
#include "BitsIoLdd2.h"
#include "trigger.h"
#include "BitsIoLdd3.h"
#include "segment7_CA.h"
#include "BitsIoLdd4.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	unsigned char c1, c2,c3;
	long int z;
	int i=0;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
 // unsigned char acvar2[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e}; 
  /* Write your code here */
  /* For example: for(;;) { } */
   while(1)
   {
	  row_SetDir(1);
	  col_SetDir(1);
	  row_PutVal(0x0);
	  col_PutVal(0xf);
	  col_SetDir(0);
	  c1 = col_GetVal();
	  row_SetDir(1);
	  col_SetDir(1);
	  row_PutVal(0xf);
	  col_PutVal(0x0);
	  row_SetDir(0);
	  c2 = row_GetVal();
	  
	  if(c1==0xe && c2==0xe)
	  {
		  segment7_CA_PutVal(0xc0);
	  }
	  else if(c1==0xe && c2==0xd)
	  {
		  segment7_CA_PutVal(0xf9);
	  }
	  else if(c1==0xe && c2==0xb)
	  {
		  segment7_CA_PutVal(0xa4);
	  }
	  else if(c1==0xe && c2==0x7)
	  {
		  segment7_CA_PutVal(0xb0);
	  }
	  else if(c1==0xd && c2==0xe)
	  {
		  segment7_CA_PutVal(0x99);
	  }
	  else if(c1==0xd && c2==0xd)
	  {
		  segment7_CA_PutVal(0x92);
	  }
	  else if(c1==0xd && c2==0xb)
	  {
		  segment7_CA_PutVal(0x82);
	  }
	  else if(c1==0xd && c2==0x7)
	  {
		  segment7_CA_PutVal(0xf8);
	  }	  
	  else if(c1==0xb && c2==0xe)
	  {
		  segment7_CA_PutVal(0x80);
	  }
	  else if(c1==0xb && c2==0xd)
	  {
		  segment7_CA_PutVal(0x90);
	  }
	  else if(c1==0xb && c2==0xb)
	  {
		  segment7_CA_PutVal(0x88);
	  }
	  else if(c1==0xb && c2==0x7)
	  {
		  segment7_CA_PutVal(0x83);
	  }	
	  else if(c1==0x7 && c2==0xe)
	  {
		  segment7_CA_PutVal(0xc6);
	  }
	  else if(c1==0x7 && c2==0xd)
	  {
		  segment7_CA_PutVal(0xa1);
	  }
	  else if(c1==0x7 && c2==0xb)
	  {
		  segment7_CA_PutVal(0x86);
	  }
	  else if(c1==0x7 && c2==0x7)
	  {
		  segment7_CA_PutVal(0x8e);
	  }
	  else
	  {
		  
	  }
	  trigger_PutVal(0xE);
	  //segment7_CA_PutVal(acvar2[i]);
	  //for(z=0;z<ffff;z++);
   }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/


/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
