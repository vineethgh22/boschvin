/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z32VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-09-30, 11:08, # CodeGen: 0
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
#include "LED_CC.h"
#include "BitsIoLdd2.h"
#include "LED_CA.h"
#include "BitsIoLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

void LLDD_CC_LED(unsigned char);
void LLDD_CA_LED(unsigned char);
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int waterrise(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  unsigned char i; 
  long int z;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  while(1)
  {
	  LLDD_CA_LED(0);
	  for(z=0;z<0xfffff;z++);
	  for(i=0x1;i<=0x8;i=i<<1)
	  	  {
	  	  	  LLDD_CC_LED(i);
	  	  	  for(z=0;z<0xfffff;z++);
	  	  	  LLDD_CC_LED(0);
	  	  	  for(z=0;z<0xfffff;z++); 
	  	  }
	  for(i=0x1;i<=0x8;i=i<<1)
	  {
		  LLDD_CA_LED(i);
		  for(z=0;z<0xfffff;z++);
		  LLDD_CA_LED(0);
		  for(z=0;z<0xfffff;z++);
	  }
	  
	  
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


void LLDD_CC_LED(unsigned char c)
{
	LED_CC_PutVal(c);
}
void LLDD_CA_LED(unsigned char c)
{
	LED_CA_PutVal(~c);
}
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