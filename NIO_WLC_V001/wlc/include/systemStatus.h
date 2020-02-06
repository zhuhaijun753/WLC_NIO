/*
 * systemStatus.h
 *
 *  Created on: 2019年6月28日
 *      Author: jiangxl
 */

#ifndef SYSTEMSTATUS_H_
#define SYSTEMSTATUS_H_

#include "defines.h"


typedef enum
{
  StateSelection,
  StatePing,
  StateIdentConfig,
  StatePowerTrans,
  StateTerminate,
  StateSafe,
  StateCount,
  StateInvalid
}StateId;

typedef enum
{
  EvtMsgSigStrength,
  EvtMsgConfig,
  EvtMsgErrorCtrl,
  EvtMsgEPT,
  EvtMsgTerminate,
  EvtMsgUnexpected,
  EvtMsgWrongValue,
  EvtReconfig,
  EvtRestart,
  EvtObjectDetected,
  EvtObjectRemoved,
  EvtTimeOut,
  EvtUnsafe,
  EventCount ,
  EvtNull                      //for marking the end of a transition tabele
}EventId;

typedef struct
{
  EventId       eventId;
  uint8_t       param1;
}EventInfo;

typedef void (*HStateEntry)(EventId id, uint8 eventParam);
typedef void (*HStateExit)(void);
typedef boolean (*HStateAction)(EventInfo* pEvtInfo);

typedef struct
{
  EventId               eventId;
  StateId               nextState;
}StateTransit;

typedef struct
{
  HStateEntry           hStateEntry;
  HStateExit            hStateExit;
  HStateAction          hStateAction;
  StateTransit*         pStateTransit;
}StateSet;



/*******************************************************************************

各状态机处理函数
*********************************************************************************/
void SSelectionEntry(EventId eventId, uint8_t eventParam);
void SSelectionExit();
boolean SSelectionAction(EventInfo* pEvtInfo);

void SPingEntry(EventId eventId, uint8_t eventParam);
void SPingExit();
boolean SPingAction(EventInfo* pEvtInfo);
uint8 GetSSelectionSignal(void);
boolean GetKeyCoilObjSts(void);

void SIdentConfigEntry(EventId eventId, uint8_t eventParam);
void SIdentConfigExit();
boolean SIdentConfigAction(EventInfo* pEvtInfo);

void SPowerTransEntry(EventId eventId, uint8_t eventParam);
void SPowerTransExit();
boolean SPowerTransAction(EventInfo* pEvtInfo);

void SPowerTansSetHoldOfftime(uint8_t holdOffTimeMsg);
uint8_t GetRecvPower(void);
uint16 GetActCurrent(void);
uint16 GetActVol(void);
uint8 GetchargeStatus(void);
//void ResetPreRxDetectFlag(void);
uint8_t GetControlError(void);


void STerminateEntry(EventId eventId, uint8_t eventParam);
void STerminateExit();
boolean STerminateAction(EventInfo* pEvtInfo);

uint8 GetCodeEPT(void);
void SetCodeEPT(void);

void SSafeEntry(EventId eventId, uint8_t eventParam);
void SSafeExit();
boolean SSafeAction(EventInfo* pEvtInfo);
boolean IsRxDetected(void);


boolean GetEvent(StateId KeycurrentState, EventInfo* pEventInfo);
void InitSystemStatus(void);
void ResetSystemStatus(void);
void SysStatusRun(void);


/*
 * system status
 */
typedef enum
{
  SysStateStandby,
  SysStateNfc,
  SysStateCharge,
  SysStateFault,
  SysStatePause,
  SysStateCount,
  SysStateInvalid
}SysStateId;

typedef enum
{
  EvtSysTransNext,
  EvtLpcdObjExist,
  EvtSysChargeDone,
  EvtSysSearchKey,

  EvtSysCount ,
  EvtSysNull                      //for marking the end of a transition tabele
}SysEventId;

typedef struct
{
  SysEventId    SyseventId;
  uint8_t       Sysparam1;
}SysEventInfo;

typedef void (*SysHStateEntry)(SysEventId id, uint8 eventParam);
typedef void (*SysHStateExit)(void);
typedef boolean (*SysHStateAction)(SysEventInfo* pEvtInfo);

typedef struct
{
  SysEventId               SyseventId;
  SysStateId               SysnextState;
}SysStateTransit;

typedef struct
{
  SysHStateEntry           SyshStateEntry;
  SysHStateExit            SyshStateExit;
  SysHStateAction          SyshStateAction;
  SysStateTransit*         SyspStateTransit;
}SysStateSet;

/*******************************************************************************

各状态机处理函数
*********************************************************************************/
void SysStandbyEntry(SysEventId eventId, uint8_t eventParam);
void SysStandbyExit();
boolean SysStandbyAction(SysEventInfo* pEvtInfo);

void SysNfcEntry(SysEventId eventId, uint8_t eventParam);
void SysNfcExit();
boolean SysNfcAction(SysEventInfo* pEvtInfo);

void SysChargeEntry(SysEventId eventId, uint8_t eventParam);
void SysChargeExit();
boolean SysChargeAction(SysEventInfo* pEvtInfo);

void SysFaultEntry(SysEventId eventId, uint8_t eventParam);
void SysFaultExit();
boolean SysFaultAction(SysEventInfo* pEvtInfo);

void SysPauseEntry(SysEventId eventId, uint8_t eventParam);
void SysPauseExit();
boolean SysPauseAction(SysEventInfo* pEvtInfo);


typedef enum
{
  PChargeDisable,
  PChargeEnable,
  PChargeCount
}WctCommand;

typedef enum
{
  PChargeNoCharge,
  PChargeOnCharging,
  PChargeOVP,
  PChargeOCP,
  PChargeOTP,
  PChargeInternalErr,
  PChargePreFOD,
  PChargePowerTransferFOD,
  PChargeRxUnknow,
  PChargeRxChargeComplete,
  PChargeRxInternalErr,
  PChargeRxOVP,
  PChargeRxOCP,
  PChargeRxOTP,
  PChargeRxBatteryFailure,
  PChargeRxNoResp,
  PChargeRxNegotFail,
  PChargeStsCount

}PWctStatus;

uint8 GetChargeFlag(void);

typedef enum
{
  KChargeNoCharge,
  KChargeOnCharging,
  KChargeOVP,
  KChargeOCP,
  KChargeOTP,
  KChargeInternalErr,
  KChargePowerTransferFOD,
  KChargeRxUnknow,
  KChargeRxChargeComplete,
  KChargeRxInternalErr,
  KChargeRxOVP,
  KChargeRxOCP,
  KChargeRxOTP,
  KChargeRxBatteryFailure,
  KChargeRxNoResp,
  KChargeStsCount

}KWctStatus;



#endif /* SYSTEMSTATUS_H_ */
