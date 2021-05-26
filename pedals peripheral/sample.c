/*----------------------------------------------------------------------------
 * Name:    sample.c
 * Purpose: to control brake and gas pedals through EINT buttons
 * Note(s):
 *----------------------------------------------------------------------------
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2017 Politecnico di Torino. All rights reserved.
 *----------------------------------------------------------------------------*/
                  
#include <stdio.h>
#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "RIT/RIT.h"
#include "adc/adc.h"
#include "GLCD/GLCD.h"
#include "TouchPanel/TouchPanel.h"

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {
  	
	SystemInit();  												/* System Initialization (i.e., PLL)  */
  LED_init();                           /* LED Initialization                 */
  
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec       	*/
	enable_RIT();													/* RIT enabled												*/
	ADC_init();
	
	LCD_Initialization();
	LCD_Clear(bgnd);
	
	TP_Init();
	
	GUI_Text(50, 292, "Gas", writ, bgnd);
	GUI_Text(155, 292, "Brake", writ, bgnd);
	
	BUTTON_init();												/* BUTTON Initialization              */		
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);						
		
	
	
  while (1) {                           /* Loop forever                       */	
		__ASM("wfi");
  }

}
