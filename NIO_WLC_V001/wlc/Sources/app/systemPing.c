/*
 * systemPing.c
 *
 *  Created on: 2019Äê7ÔÂ3ÈÕ
 *      Author: jiangxl
 */

#include "Cpu.h"
#include "global.h"
#include "hal.h"
#include "systemTask.h"
#include "systemStatus.h"
#include "systemTimers.h"
#include "Qi_spec.h"
#include "systemDef.h"

static uint8_t  sigStrength;
static boolean  bStartSigTimer;
boolean bStatePing;

/*
 * TRUE: Object detect
 * FALSE: No Object
 */

boolean GetKeyCoilObjSts()
{
	return bStatePing;
}

/*=================================================================
                  Timing Spec.
1)T_PING:  Primary Celll current amplitude reashes 50% -> START of a Packet
2)T_FIRST: START of the first packet -> END of the first packet
====================================================================*/

Coils GetMaxStrengthCoil()
{
	Coils index,selectCoilIndex=0;
	uint8 SelsigStrength;
	uint8 maxSigStrength = 0;

	selectCoilIndex = CoilOne;
	for(index = (Coils)0; index < CoilsCount; index++)
	{
		SelectCoils(index);
		//TurnOnPWM();
		HAL_EnablePower();
		StartTimer2(T_PING + TIME_MARGIN);
		SelsigStrength = GetSSelectionSignal();
		if(maxSigStrength < SelsigStrength)
		{
			maxSigStrength = SelsigStrength;
			selectCoilIndex = index;
		}
		//TurnOffPWM();
		HAL_DisablePower();
		//ST_WaitMs(20);
	}
	StopTimer2();
	return selectCoilIndex;
}

uint8 GetSSelectionSignal()
{
	uint8	NsigStrength = 0;

	//Check the timing for T_PING
	while(!IsTimer2Expired())
	{
		if(bNewMessage)      //received a message successfully
		{
			bNewMessage = FALSE;
//			GetPacket(&newPacket);

			//check packet
			if(RxPacket[0] == HEADER_SIGNAL_STRENGTH)
			{
				bStatePing = TRUE;
				NsigStrength = RxPacket[1];//newPacket.message;
				break;
			}
		}
	}
	return  NsigStrength;

}

void SPingEntry(EventId eventId, uint8_t eventParam)
{

	Coils CoilIndex;

	ResetPID();
	InitFodLossValue();
	bStatePing = FALSE;

	//CoilIndex = GetMaxStrengthCoil();
	//if(bStatePing == TRUE)
	{
	//	SelectCoils(CoilIndex);
	//decoder header time
		HAL_EnablePower();


	//while(1);

	//StartTimer1(TPING); //timeout for not receiveing first packet, adding 5ms of margin
		StartTimer1(300);


	// PTB3 toggle for timing test
//	PINS_DRV_TogglePins(COIL1_EN_GPIO, 1 << COIL1_EN_PIN);

	//StartTimer2(T_MAX);                //Just Reset Timer2 for safety
		bStartSigTimer = TRUE;
	}
//	gTerminateCode = 0xff;

}


void SPingExit()
{
	StopAllTimers();
}



boolean SPingAction(EventInfo* pEvtInfo)
{
//  Packet  newPacket;
	if(IsTimer1Expired())
	{
		// PTB3 toggle for timing test
		//PINS_DRV_TogglePins(COIL1_EN_GPIO, 1 << COIL1_EN_PIN);

		pEvtInfo->eventId = EvtTimeOut;
//	  gTerminateCode = PING_TIME_OUT;
//		#if 1
//    if(Fod(StatePing))
//    {
//       pEvtInfo->eventId = EvtUnsafe;
//       pEvtInfo->param1 = UnsafePingFOD;
//    }
//		#endif
		//LED_RED_TOGGLE;//PA3
//    ResetPreRxDetectFlag();
		return TRUE;
	}

	if(bNewMessage)
	{
		bNewMessage = FALSE;
		if(RxPacket[0] == HEADER_SIGNAL_STRENGTH)
		{
			pEvtInfo->eventId = EvtMsgSigStrength;
			pEvtInfo->param1  = RxPacket[1];
			sigStrength =  RxPacket[1];
		}
		else if(RxPacket[0] == HEADER_END_POWER_TRANSFER)
		{
			pEvtInfo->eventId = EvtMsgEPT;
			pEvtInfo->param1  = RxPacket[1];
		}
		else
		{
			pEvtInfo->eventId = EvtMsgUnexpected;
		}
		//variable_clear();
		return TRUE;
	} //if(bNewMessage)
	return FALSE;

}


