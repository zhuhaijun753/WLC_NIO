/*
 * hal.h
 *
 *  Created on: 2019Äê6ÔÂ28ÈÕ
 *      Author: jiangxl
 */

#ifndef HAL_H_
#define HAL_H_

#include "defines.h"
#include "Cpu.h"
#include "S32K144.h"
#include "systemStatus.h"
#include "systemDef.h"


#define HAL_RAIL_SENSE_SHIFT_BITS           10   //shift for better resolution
#define HAL_RAIL_SENSE_UP_RESISTOR     16200.0   //ohm
#define HAL_RAIL_SENSE_DOWN_RESISTOR    2000.0   //ohm
#define HAL_RAIL_SENSE_MULTI_F      ((HAL_RAIL_SENSE_UP_RESISTOR+HAL_RAIL_SENSE_DOWN_RESISTOR)*(1UL<<HAL_RAIL_SENSE_SHIFT_BITS))
#define HAL_RAIL_SENSE_MULTI_U      ((uint32)(HAL_RAIL_SENSE_MULTI_F/HAL_RAIL_SENSE_DOWN_RESISTOR))


#define HAL_BATTERY_SENE_SHIFT_BITS         10      //shift for better resolution
#define HAL_BATTERY_SENSE_UP_RESISTOR     16200//16200.0   //ohm
#define HAL_BATTERY_SENSE_DOWN_RESISTOR    2550//2550.0   //ohm
#define HAL_BATTERY_SENSE_MULTI_F      ((HAL_BATTERY_SENSE_UP_RESISTOR+HAL_BATTERY_SENSE_DOWN_RESISTOR)*(1UL<<HAL_BATTERY_SENE_SHIFT_BITS))
#define HAL_BATTERY_SENSE_MULTI_U      ((uint32)(HAL_BATTERY_SENSE_MULTI_F/(HAL_BATTERY_SENSE_DOWN_RESISTOR)))


#define HAL_INPUT_CURRENT_SENSE_SHIFT_BITS   10     //shift for better resolution
#define HAL_INPUT_CURRENT_SENSE_RESISTOR   0.015   //ohm
#define HAL_INPUT_CURRENT_AMPLIFY_MULTI     100.0   //current sensor gain
#define HAL_INPUT_CURRENT_MULTI_COEFF_U     ((uint32)((1UL<<HAL_INPUT_CURRENT_SENSE_SHIFT_BITS)/(HAL_INPUT_CURRENT_SENSE_RESISTOR*HAL_INPUT_CURRENT_AMPLIFY_MULTI)))

#define HAL_AP_CURRENT_THRC 1500//130
#define HAL_AP_FREQUENCY    140000//130000//150000


#define TEST_GPIO0		PTD
#define TEST_PIN0		0U

#define COIL1_EN_GPIO	PTD
#define COIL1_EN_PIN	5U
#define COIL2_EN_GPIO	PTB
#define COIL2_EN_PIN	3U
#define VDEMOD_GPIO		PORTC
#define VDEMOD_PIN		17

#define ISF_CLEAR		24

typedef enum
{
	KeyCurrentSense,
	RailA5VSense,
	Temp5Sense,
	Temp6Sense,
	Temp7Sense,
	InputVbatSense,
	AdcChannelTotal
} ADC_CHANNEL_TYPE;


typedef enum
{
	CoilOne,
	CoilTwo,
	CoilsCount
}Coils;

Coils GetMaxStrengthCoil(void);

void HAL_Init(void);
void HAL_SetPwmPeriod(uint32_t newPeriod);
void HAL_CANInit();
uint16 HAL_GetAdcSampleData(ADC_CHANNEL_TYPE adc_channel);
uint16 HAL_GetBatteryVoltage(void);
uint16 HAL_GetInputCurrent(void);
void HAL_GetCurrentOffset(void);
uint16 HAL_GetTemp5(void);
uint16 HAL_GetTemp6(void);
uint16 HAL_GetTemp7(void);
uint16 HAL_GetVrailVoltage(void);

uint16 HAL_GetPingCurrent(void);

void HAL_ToggleGpio(GPIO_Type * const base, pins_channel_type_t pins);

void HAL_EnablePower(void);
void HAL_DisablePower(void);
void HAL_SetPwmFreq(uint32_t FrequencyHz);

boolean HAL_DetectObject(void);
void HAL_Coil1En_Config(boolean conf);
void HAL_Coil2En_Config(boolean conf);

void GetPacketMessage(void);


void CalculateNewFrequency(uint8 controlError);
//boolean CalculateNewFrequency(uint8 controlError);
void ResetPID(void);
//uint16 GetNewFreq(void);
//uint16 GetNewDuty(void);

void GetPacketMessage(void);


boolean DetectObject(void);
uint16 GetTransmitterPower(void);
boolean GetAvgRevPower(void);
void StartAvgRevPower(void);
boolean Fod(StateId KeycurrentState);
void InitFodLossValue(void);
uint16 GetSubPower(void);
void ResetFodCounter(void);


boolean SafetyMonitor(EventInfo* pEvtInfo);


uint16 GetFilteredMeasurement(MeasurementType type);

void MeasureAll(void);

uint16 GetInstantValue(MeasurementType type);
void InitMeasurement(void);
uint16 FilterMeasurement(uint16 average, uint16 newValue);

uint32 FitRange(uint32 value, uint32 limitLow, uint32 limitHigh);


void SelectCoils(uint8 index);
void DeselectAllCoils(void);

void HAL_UartSendCommand(uint8 command);
uint8 HAL_UartRecvSts(void);


#endif /* HAL_H_ */
