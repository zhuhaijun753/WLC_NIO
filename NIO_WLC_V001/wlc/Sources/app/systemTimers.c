/*
 * systemTimers.c
 *
 *  Created on: 2019Äê6ÔÂ28ÈÕ
 *      Author: jiangxl
 */


#include "Cpu.h"
#include "hal.h"

#include "systemTimers.h"


volatile static uint16_t  msGenTimeoutPeriod1;// = 0;
volatile static uint16_t  msGenStartPoint1;// = 0;
volatile static boolean   bStartTimer1;// = FALSE;


volatile static uint16_t  msGenTimeoutPeriod2;// = 0;
volatile static uint16_t  msGenStartPoint2;// = 0;
volatile static boolean   bStartTimer2;// = FALSE;


volatile static uint16_t  msGenTimeoutPeriod3;// = 0;
volatile static uint16_t  msGenStartPoint3;// = 0;
volatile static boolean   bStartTimer3;// = FALSE;

volatile static uint16_t  msGenTimeoutPeriod4;// = 0;
volatile static uint16_t  msGenStartPoint4;// = 0;
volatile static boolean   bStartTimer4;// = FALSE;

volatile static uint16_t gST_wTimerTick;
volatile static uint16_t gST_wUsTimerTick;


void ST_TimerUpdate(void)
{
	//
	gST_wUsTimerTick++;
	if(gST_wUsTimerTick%100==0)
	{
		gST_wTimerTick++;
		// PTB3 toggle for 1ms test
		//PINS_DRV_TogglePins(COIL1_EN_GPIO, 1 << COIL1_EN_PIN);

	}

}

uint16_t ST_GetTimerTick(void)
{
	return gST_wTimerTick;
}

uint16_t ST_GetUsTimerTick(void)
{
	return gST_wUsTimerTick;
}

void ST_AddTickTimer(uint16_t wTicks)
{
	//uint8 sts = HAL_DisableIRQ();
	gST_wTimerTick += wTicks;
	//HAL_RestoreIRQ(sts);
}

uint16_t ST_GetElapasedTime(uint16_t wLastTick)
{
	uint16_t ticks = ST_GetTimerTick();
	uint16_t wElapsedTime;

	if (ticks >= wLastTick)
	{
		wElapsedTime = ticks - wLastTick;
	}
	else
	{
	    //counter wrap
		wElapsedTime = ticks + (65536UL - wLastTick);
	}

	return wElapsedTime;
}

void ST_WaitMs(uint16_t wNumMs)
{
	uint16_t ticks = ST_GetTimerTick();

	while (ST_GetElapasedTime(ticks) < wNumMs)
	{
	    //Kick the watch dog
		//HAL_KickWatchDog();

	}
}


void StopAllTimers()
{
  bStartTimer1 = FALSE;
  bStartTimer2 = FALSE;
  bStartTimer3 = FALSE;
  bStartTimer4 = FALSE;
}

//==================  Timer1 ===========================

void StopTimer1()
{
  bStartTimer1= FALSE;
}

void StartTimer1(uint16_t msTimeOutPeriod)
{
  msGenTimeoutPeriod1 = msTimeOutPeriod;
  msGenStartPoint1 = ST_GetTimerTick();
  bStartTimer1 = TRUE;
}

void RestartTimer1()
{
  msGenStartPoint1 = ST_GetTimerTick();
}


boolean IsTimer1Expired()
{

  if(bStartTimer1)
  {
    if(ST_GetElapasedTime(msGenStartPoint1) > msGenTimeoutPeriod1)
    {
    	// PTB3 toggle for timing test
    	//PINS_DRV_TogglePins(COIL1_EN_GPIO, 1 << COIL1_EN_PIN);
      return TRUE;
    }
  }

  return FALSE;
}


//================== Timer2 ===========================

void StopTimer2()
{
  bStartTimer2= FALSE;
}

void StartTimer2(uint16_t msTimeOutPeriod)
{
  msGenTimeoutPeriod2 = msTimeOutPeriod;
  msGenStartPoint2 = ST_GetTimerTick();
  bStartTimer2 = TRUE;
}

void RestartTimer2()
{
  msGenStartPoint2 = ST_GetTimerTick();
}


boolean IsTimer2Expired()
{

  if(bStartTimer2)
  {
    if(ST_GetElapasedTime(msGenStartPoint2) > msGenTimeoutPeriod2)
    {
      return TRUE;
    }
  }

  return FALSE;
}



//================== Timer3 ===========================

void StopTimer3()
{
  bStartTimer3= FALSE;
}

void StartTimer3(uint16_t msTimeOutPeriod)
{
  msGenTimeoutPeriod3 = msTimeOutPeriod;
  msGenStartPoint3 = ST_GetTimerTick();
  bStartTimer3 = TRUE;
}


void RestartTimer3()
{
  msGenStartPoint3 = ST_GetTimerTick();
}


boolean IsTimer3Expired()
{

  if(bStartTimer3)
  {
    if(ST_GetElapasedTime(msGenStartPoint3) > msGenTimeoutPeriod3)
    {
      return TRUE;
    }
  }

  return FALSE;
}


//================== Timer4 ===========================

void StopTimer4()
{
  bStartTimer4= FALSE;
}

void StartTimer4(uint16_t msTimeOutPeriod)
{
  msGenTimeoutPeriod4 = msTimeOutPeriod;
  msGenStartPoint4 = ST_GetTimerTick();
  bStartTimer4 = TRUE;
}


void RestartTimer4()
{
  msGenStartPoint4 = ST_GetTimerTick();
}


boolean IsTimer4Expired()
{

  if(bStartTimer4)
  {
    if(ST_GetElapasedTime(msGenStartPoint4) > msGenTimeoutPeriod4)
    {
      return TRUE;
    }
  }

  return FALSE;
}

