/* ###################################################################
**     Filename    : main.c
**     Processor   : S32K14x
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary module. Cpu.h contains other modules needed for compiling.*/
#include "Cpu.h"
#include "hal.h"
#include "systemTask.h"
#include "systemTimers.h"

  volatile int exit_code = 0;


uint8			RxPacket[16] ={0};    //
boolean			bNewMessage = FALSE;
uint8			CommDlyCnt[2] = {0};
uint8			gCountOptConfig;
boolean			gExt;

uint8 			gMaxPower;
uint8 			gWindowSize;

uint16 			ginitCurrent;

uint32			freq;

//static uint16_t vbat, vrail, cur;

/* User includes (#include below this line is not maintained by Processor Expert) */

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

    HAL_Init();
    KeyChargeStateInit();
    KeyChargeSelectionEntry();
    InitMeasurement();
    HAL_DisablePower();
    HAL_UartSendCommand(0);

    //StartTimer1(5);
    //freq = 170000;

  /* For example: for(;;) { } */
    while(1)
    {
    	AppTask_Poll();

    	//if(IsTimer1Expired())
    	//{
    	//	//HAL_SetPwmPeriod(24000000/freq);
    	//	HAL_SetPwmFreq(freq);
    	//	HAL_EnablePower();
    	//	HAL_DetectObject();
    	//	// PTB3 toggle for timing test
    	//	//PINS_DRV_TogglePins(COIL1_EN_GPIO, 1 << COIL1_EN_PIN);
    	//	StartTimer1(500);
    	//	if(freq<190000)
    	//	{
    	//		freq += 500;
    	//	}
    	//	else
    	//	{
    	//		freq = 120000;
    	//	}

    	//}

    	//ST_WaitMs(500);
    	//HAL_EnablePower();
    	//ST_WaitMs(500);
    	//HAL_DisablePower();
    	//vbat  = HAL_GetBatteryVoltage();
    	//vrail = HAL_GetVrailVoltage();
    	//cur   = HAL_GetInputCurrent();
    	//vbat = HAL_GetTemp5();
    	//vbat = HAL_GetTemp6();
    	//vbat = HAL_GetTemp7();


    }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
    if(exit_code != 0) {
      break;
    }
  }
  return exit_code;
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.1 [05.21]
**     for the Freescale S32K series of microcontrollers.
**
** ###################################################################
*/
