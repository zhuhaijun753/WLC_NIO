/*
 * systemSafe.c
 *
 *  Created on: 2019��7��3��
 *      Author: jiangxl
 */
#include "Cpu.h"
#include "hal.h"
#include "systemDef.h"
#include "Qi_spec.h"
#include "systemTask.h"
#include "systemStatus.h"
#include "systemTimers.h"


static UnsafeCode  unsafeCode;
static EventId  evtId;

void SSafeEntry(EventId eventId, uint8_t eventParam)
{
	//RemovePowerTransfer();
	HAL_DisablePower();
	//InitLEDs();
	StopAllTimers();
	unsafeCode = eventParam;
	evtId = eventId;
	ResetFodCounter();
	if(unsafeCode == UnsafeFOD || unsafeCode == UnsafePingFOD)
	{
      //StartTimer1(3000);
      //SetBuzzer(ToneAlways);
		StartTimer1(350);
        StartTimer2(3000);
        //SetBuzzer(ToneAlways);
	}
	else if(unsafeCode == UnsafeOverCurrent )
	{
		StartTimer1(350);
	}

//  InitSoftwarePing();

  #ifdef _I2C_MONITOR
  gTerminateCode = (BYTE)(unsafeCode + 15);
  SetI2CData(StatePowerTrans);
  #endif

}


void SSafeExit( )
{
  StopAllTimers();
}

boolean IsRxDetected()
{
    boolean bOverCurrent = TRUE;
    uint16 current;
    current = HAL_GetPingCurrent();
    if((unsafeCode == UnsafePingFOD)&&(evtId == EvtUnsafe))
    {
        if(current < FOD_OUT_CURRENT_THRC)
        {
           bOverCurrent = FALSE;
        }
    }
    else

    {
        if(current < FOD2_OUT_CURRENT_THRC)

    	//if(current < DETECT_CURRENT_THRC)
        {
           bOverCurrent = FALSE;
        }
    }
    return bOverCurrent;
}


static boolean IsOverCurrent()
{
    boolean bOverCurrent = TRUE;

    if(IsTimer1Expired())
    {
        RestartTimer1();

        bOverCurrent = IsRxDetected();//�������ֵС�ڵ���������ֵbOverCurrent = 0
    }

    if(IsTimer2Expired() || !bOverCurrent )
    {
        //StopBuzzer();   //����������رշ�����
    }

    return bOverCurrent;
}


boolean SSafeAction(EventInfo* pEvtInfo)
{
	EventInfo evtInfo;

	switch(unsafeCode)
 	{
 	//case UnsafeOverCurrent:
	//	//SetLEDs(LED_OverCurrent);
	//	if(IsOverCurrent())
	//	{
	//		return FALSE;
	//	}
	//	break;

	case UnsafePingFOD:
	case UnsafeFOD:
		//SetLEDs(LED_FOD);
		if(IsOverCurrent())
		{
			return FALSE;
		}
		break;

  //OverVoltage, OverCoiltemperature and OverIcTemperature are rechecked by SafetyMonitor

	case UnsafeOverVoltage:
		//SetLEDs(LED_OverVoltage);
		break;

	case UnsafeOverCoilTemperature:
		//SetLEDs(LED_OverCoilTemperature);
		break;

	case UnsafeOverIcTemperature:
		//SetLEDs(LED_OverIcTemperature);
		break;

	default:
		//SetLEDs(LED_Standby);
		//pEvtInfo->eventId = EvtRestart;
		//return TRUE;
		break;

	}


	if(!SafetyMonitor(&evtInfo))   //make sure ALL are good now, then exit the safe state
	{
		pEvtInfo->eventId = EvtRestart;
		//SetLEDs(LED_Standby);
		return TRUE;
	}


	return FALSE;

}

