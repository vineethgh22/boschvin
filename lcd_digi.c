/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z32VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-10-13, 11:47, # CodeGen: 0
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
#include "LCD_REG_SELECT.h"
#include "BitIoLdd1.h"
#include "LCD_READ_WRITE.h"
#include "BitIoLdd2.h"
#include "LCD_ENABLE.h"
#include "BitIoLdd3.h"
#include "LCD_DATA_CMD_PINS.h"
#include "BitsIoLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
void LCD_delay(unsigned char);
void LCD_command(unsigned char);
void LCD_data(unsigned char );
void LCD_puts(unsigned char *);
void LCD_init();
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	int i,k,j,m,p,q;
	unsigned char acvar3[]={48, 49, 50 ,51 ,52 ,53 ,54 ,55, 56, 57};
	int st=0;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  LCD_init();
  LCD_command(0x01);
  LCD_command(0x82);
  LCD_data(':');
  LCD_command(0x85);
  LCD_data(':');
  LCD_command(0x89);
  LCD_puts("AM");
  LCD_command(0x0c);
		for(p=0;p<2;p++)
		{
			LCD_command(0x80);
			LCD_data(acvar3[p]);
			
			for(q=0;q<=9;q++)
			{
				LCD_command(0x81);
				LCD_data(acvar3[q]);
				for(i=0;i<6;i++)
				{
					LCD_command(0x83);
					LCD_data(acvar3[i]);
					for(k=0;k<=9;k++)
					{
						LCD_command(0x84);
						LCD_data(acvar3[k]);
						for(j=0;j<6;j++)
						{
							LCD_command(0x86);
							LCD_data(acvar3[j]);
							for(m=0;m<=9;m++)
							{
								LCD_command(0x87);
								LCD_data(acvar3[m]);
								LCD_delay(50);
								
							}
						}
					}	
				}
				if(p==1 && q==2)
				{
					p=0;
					q=0;
				}
				if(st==0)
				{
					LCD_command(0x89);
					LCD_puts("PM");
					st=1;
				}
				else
				{
					LCD_command(0x89);
					LCD_puts("AM");
					st=0;						
				}
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
void LCD_init()
{
	LCD_command(0x38);
	LCD_command(0x0F);
	LCD_command(0x06);
	LCD_command(0x01);
	LCD_command(0x80);
	LCD_delay(1);
}
void LCD_delay(unsigned char ms)
{
	unsigned char n;
	unsigned int i;
	for(n=0;n<ms;n++)
		for(i=0;i<0X7fff;i++);
}
void LCD_command(unsigned char command)
{
	LCD_DATA_CMD_PINS_PutVal(command);
	LCD_REG_SELECT_PutVal(0);
	LCD_READ_WRITE_PutVal(0);
	LCD_ENABLE_PutVal(1);
	LCD_delay(1);
	LCD_ENABLE_PutVal(0);
}
void LCD_data(unsigned char ascii)
{
	LCD_DATA_CMD_PINS_PutVal(ascii);
	LCD_REG_SELECT_PutVal(1);
	LCD_READ_WRITE_PutVal(0);
	LCD_ENABLE_PutVal(1);
	LCD_delay(1);
	LCD_ENABLE_PutVal(0);
}
void LCD_puts(unsigned char *lcd_string)
{
	while(*lcd_string)
	{
		LCD_data(*lcd_string++);
	}
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
