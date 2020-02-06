/*
 * systemTimers.h
 *
 *  Created on: 2019Äê6ÔÂ28ÈÕ
 *      Author: jiangxl
 */

#ifndef SYSTEMTIMERS_H_
#define SYSTEMTIMERS_H_

#include "defines.h"

void ST_TimerUpdate(void);
uint16_t ST_GetTimerTick(void);
uint16_t ST_GetUsTimerTick(void);
void ST_AddTickTimer(uint16_t wTicks);
uint16_t ST_GetElapasedTime(uint16_t wLastTick);
void ST_WaitMs(uint16_t wNumMs);

void StopAllTimers(void);
void StopTimer1(void);
void StartTimer1(uint16_t msTimeOutPeriod);
void RestartTimer1(void);
boolean IsTimer1Expired(void);
void StopTimer2(void);
void StartTimer2(uint16_t msTimeOutPeriod);
void RestartTimer2(void);
boolean IsTimer2Expired(void);

void StopTimer3(void);
void StartTimer3(uint16_t msTimeOutPeriod);
void RestartTimer3(void);
boolean IsTimer3Expired(void);

void StopTimer4(void);
void StartTimer4(uint16_t msTimeOutPeriod);
void RestartTimer4(void);
boolean IsTimer4Expired(void);


#endif /* SYSTEMTIMERS_H_ */
