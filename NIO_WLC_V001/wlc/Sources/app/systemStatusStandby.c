/*
 * systemStatusStandby.c
 *
 *  Created on: 2020年1月10日
 *      Author: jiangxl
 */


/*
 * systemSelection.c
 *
 *  Created on: 2019年7月3日
 *      Author: jiangxl
 */

#include "Cpu.h"
#include "hal.h"
#include "systemTask.h"
#include "systemStatus.h"
#include "systemTimers.h"

//
//static uint8_t   APCounter =0;


void SysStandbyEntry(SysEventId eventId, uint8_t eventParam)
{

}


void SysStandbyExit()
{


}


boolean SysStandbyAction(SysEventInfo* pEvtInfo)
{
	uint8 ret;

	ret = FALSE;

	//NFC_Task_LPCD_Cail();
	//if(NxpNci_LPCD_Cail_Results_Success==NFC_Task_LPCD_Detect())
	//{

	//	if(ImobEnaReq || CdcBtReq || CdcWifiReq)
	//	{
	//		pEvtInfo->SyseventId= EvtSysTransNext;
	//		pEvtInfo->Sysparam1 = SysStateNfc;
	//		ret = TRUE;
	//	}
	//	else if(!HmiMute)
		{
			pEvtInfo->SyseventId= EvtSysTransNext;
			pEvtInfo->Sysparam1 = SysStateCharge;
			ret = TRUE;
		}
	//}


	return ret;

}







