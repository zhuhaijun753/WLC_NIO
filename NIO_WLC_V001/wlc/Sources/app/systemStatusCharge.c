/*
 * systemStatusCharge.c
 *
 *  Created on: 2020Äê1ÔÂ10ÈÕ
 *      Author: jiangxl
 */


#include "Cpu.h"
#include "hal.h"
#include "systemTask.h"
#include "systemStatus.h"
#include "systemTimers.h"

static uint8	bChargeFlag=0;
PWctStatus PChargeSts;
KWctStatus KChargeSts;

uint8 GetChargeFlag()
{
	return bChargeFlag;
}


void SysChargeEntry(SysEventId eventId, uint8_t eventParam)
{


	bChargeFlag = 0;
	GetMaxStrengthCoil();
	if(TRUE==GetKeyCoilObjSts())
	{
		bChargeFlag = 1;
	}
	else
	{
		HAL_UartSendCommand(1);
		bChargeFlag = 2;
		StartTimer3(500);
	}

}


void SysChargeExit()
{
	StopAllTimers();

}


boolean SysChargeAction(SysEventInfo* pEvtInfo)
{
	uint8 ret;
	ret = FALSE;

	if(IsTimer3Expired())
	{
		StartTimer3(500);
		if(bChargeFlag==0)
		{
			pEvtInfo->SyseventId= EvtSysTransNext;
			pEvtInfo->Sysparam1 = SysStateStandby;
			ret = TRUE;
		}

	}


/*
	if(ImobEnaReq || CdcBtReq || CdcWifiReq)
	{
		pEvtInfo->SyseventId= EvtSysTransNext;
		pEvtInfo->Sysparam1 = SysStateNfc;
		ret = TRUE;
	}
	else if(HmiMute)
	{
		pEvtInfo->SyseventId= EvtSysTransNext;
		pEvtInfo->Sysparam1 = SysStateStandby;
		ret = TRUE;
	}

	if(IsTimer3Expired())
	{
		PChargeSts = HAL_UartRecvSts();
		KChargeSts = GetKeyChargeSts();
		StartTimer3();

		if(bChargeFlag==1)
		{
			switch(KChargeSts)
			{
			case KChargeNoCharge:
				break;
			case KChargeOnCharging:
				break;
			case KChargePowerTransferFOD:
				break;
			default:
				break;
			}
		}
		else if(bChargeFlag==2)
		{
			switch(PChargests)
			{
			case PChargeNoCharge:
				HAL_UartSendCommand(0);
				pEvtInfo->SyseventId= EvtSysTransNext;
				pEvtInfo->Sysparam1 = SysStateStandby;
				ret = TRUE;
				break;
			case PChargeOnCharging:
				break;

			case PChargeOVP:
				HAL_UartSendCommand(0);
				pEvtInfo->SyseventId= EvtSysTransNext;
				pEvtInfo->Sysparam1 = SysStateFault;
				ret = TRUE;
				break;
			case PChargeOCP:
				HAL_UartSendCommand(0);
				pEvtInfo->SyseventId= EvtSysTransNext;
				pEvtInfo->Sysparam1 = SysStateFault;
				ret = TRUE;
				break;
			case PChargeOTP:
				HAL_UartSendCommand(0);
				pEvtInfo->SyseventId= EvtSysTransNext;
				pEvtInfo->Sysparam1 = SysStateFault;
				ret = TRUE;
				break;
			case PChargeInternalErr:
				HAL_UartSendCommand(0);
				pEvtInfo->SyseventId= EvtSysTransNext;
				pEvtInfo->Sysparam1 = SysStateFault;
				ret = TRUE;
				break;
			case PChargePreFOD:
			case PChargePowerTransferFOD:
				HAL_UartSendCommand(0);
				pEvtInfo->SyseventId= EvtSysTransNext;
				pEvtInfo->Sysparam1 = SysStateFault;
				ret = TRUE;
				break;
			case PChargeRxChargeComplete:
				//pEvtInfo->SyseventId= EvtSysTransNext;
				//pEvtInfo->Sysparam1 = SysStatePause;
				break;
			default:
				break;

			}
		}
	}
*/



	return ret;

}


