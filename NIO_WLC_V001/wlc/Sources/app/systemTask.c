/*
 * systemTask.c
 *
 *  Created on: 2019年6月28日
 *      Author: jiangxl
 */


#include "defines.h"
#include "cpu.h"
#include "hal.h"
#include "systemTimers.h"
#include "systemStatus.h"
#include "systemSmSetting.h"

#define NUM_1MS_COUNTS_FOR_10MS         10U
#define NUM_10MS_COUNTS_FOR_100MS       10U
#define NUM_100MS_COUNTS_FOR_1SEC       10U
#define NUM_1SEC_COUNTS_FOR_1MIN        60U

StateId KeycurrentState,KeynextState;

EventInfo eventInfo;
StateTransit* pStateTransit;

SysStateId SyscurrentState,SysnextState;

SysEventInfo SyseventInfo;
SysStateTransit* SyspStateTransit;

typedef struct
{
	uint16 w1msCount;
	uint16 w10msCount;
	uint16 w100msCount;
	uint16 w1secCount;
	uint16 w1minCount;
} TIMER_DATA;

//APP_ERROR_TYPE gApp_error = APP_SUCCESS;
boolean GetEvent(StateId KeycurrentState, EventInfo* pEventInfo)
{
	boolean ret = FALSE;

	if(SafetyMonitor(pEventInfo))
    {
       ret = TRUE;		//关闭安全监测
    }
    //LED_TEST_TOGGLE;
    if((*(SM_Table[KeycurrentState].hStateAction))(pEventInfo))
    {
       ret = TRUE;
    }

    return ret;
}

static void KeyChargeRun()
{
	uint8_t i;

	if(GetEvent(KeycurrentState, &eventInfo))
	{
		if((KeycurrentState < StateCount)&&(eventInfo.eventId < EventCount))
		{
			pStateTransit = SM_Table[KeycurrentState].pStateTransit;               //Get current state's transaction table 'StateTrans'
			i=0;
			while(pStateTransit[i].eventId != EvtNull)
			{
				if(pStateTransit[i].eventId == eventInfo.eventId)                 //search for the state transition for the current event
				{
					KeynextState = pStateTransit[i].nextState;
					if(KeynextState != KeycurrentState)                                 //if the state changes, call exit function of current state, and entry function of next state
					{
						(*SM_Table[KeycurrentState].hStateExit)();
						(*SM_Table[KeynextState].hStateEntry)(eventInfo.eventId, eventInfo.param1);
						KeycurrentState = KeynextState;
					}
					break;
				}
				i++;
			}//for
		}// if((currentState < StateCount)&&(eventInfo.eventId < EventCount))
	}//if(GetEvent(...))
}

boolean GetSysEvent(SysStateId SyscurrentState, SysEventInfo* pEventInfo)
{
	boolean ret = FALSE;

	//if(SafetyMonitor(pEventInfo))
   // {
   //    ret = TRUE;		//关闭安全监测
   // }
    //LED_TEST_TOGGLE;
    if((*(Sys_SM_Table[KeycurrentState].SyshStateAction))(pEventInfo))
    {
       ret = TRUE;
    }

    return ret;
}

static void SystemStsRun()
{
	//uint8_t i;

	if(GetSysEvent(SyscurrentState, &SyseventInfo))
	{
		switch(SyseventInfo.SyseventId)
		{
		case EvtSysTransNext:
	    	   SysnextState = (SysStateId) SyseventInfo.Sysparam1;
	           break;

	       //case EvtFod:
	       //case Evtprotect:
	       //case EvtInternalError:
	    //	   nextState = StateFault;
	    //	   break;
		case EvtSysChargeDone:
		case EvtSysSearchKey:
			SysnextState = SysStatePause;
			break;
		default:
			break;

		}
	}
}

static void AppTask_1msHandle(uint16 wNumTicks)
{
	//GetMaxStrengthCoil();
	//if(TRUE==GetKeyCoilObjSts())
//	{
//		KeyChargeRun();
//	}
//	else
//	{
//		HAL_UartSendCommand(1);
//	}
	//SystemStsRun();
	//if(GetChargeFlag()==1)
	{
		KeyChargeRun();
	}

}

static void AppTask_10msHandle(uint16 wNumTicks)
{
	//PROT_CheckBoardParams(wNumTicks);
	//DISP_Handler(wNumTicks);

}

static void AppTask_100msHandle(void)
{
	//HAL_KickWatchDog();
	MeasureAll();
}

static void AppTask_1secHandler(void)
{

}

static void AppTask_1minHandler(void)
{


}



void AppTask_Poll(void)
{
    static TIMER_DATA TimerData;
    static uint16 wAppLastTimerTicks;

	uint16 wSecondsToAdd;
	uint16 wNumTicks;

	wNumTicks = ST_GetElapasedTime(wAppLastTimerTicks);
	wAppLastTimerTicks += wNumTicks;
	wAppLastTimerTicks &= 0xffffu;

	if (wNumTicks)
	{
		// 1 ms Tick
		if (1U <= wNumTicks)
		{
			TimerData.w1msCount += wNumTicks;

			AppTask_1msHandle(wNumTicks);

			// 10 MS Tick
			if (NUM_1MS_COUNTS_FOR_10MS <= TimerData.w1msCount)
			{
				wNumTicks = TimerData.w1msCount;
				TimerData.w10msCount += (TimerData.w1msCount / NUM_1MS_COUNTS_FOR_10MS);
				TimerData.w1msCount %= NUM_1MS_COUNTS_FOR_10MS;

				AppTask_10msHandle(wNumTicks);

				// 100 MS Tick
				if (NUM_10MS_COUNTS_FOR_100MS <= TimerData.w10msCount)
				{
					TimerData.w100msCount += (TimerData.w10msCount / NUM_10MS_COUNTS_FOR_100MS);
					TimerData.w10msCount %= NUM_10MS_COUNTS_FOR_100MS;

					AppTask_100msHandle();

					// 1 SEC Tick
					if (NUM_100MS_COUNTS_FOR_1SEC <= TimerData.w100msCount)
					{
						wSecondsToAdd = (TimerData.w100msCount / NUM_100MS_COUNTS_FOR_1SEC);
						TimerData.w100msCount %= NUM_100MS_COUNTS_FOR_1SEC;
						TimerData.w1secCount += wSecondsToAdd;

						AppTask_1secHandler();

						if (NUM_1SEC_COUNTS_FOR_1MIN <= TimerData.w1secCount)
						{
							TimerData.w1minCount += (TimerData.w1secCount / NUM_1SEC_COUNTS_FOR_1MIN);
							TimerData.w1secCount %= NUM_1SEC_COUNTS_FOR_1MIN;

							AppTask_1minHandler();
						}
					}
				}
			}
		}
	}
}

void KeyChargeStateInit()
{

	KeycurrentState = StateSelection;
}

void KeyChargeSelectionEntry()
{
	(*SM_Table[StateSelection].hStateEntry)(eventInfo.eventId, eventInfo.param1);
}


