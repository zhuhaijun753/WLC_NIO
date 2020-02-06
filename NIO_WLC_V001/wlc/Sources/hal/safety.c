/*
 * safety.c
 *
 *  Created on: 2019Äê7ÔÂ15ÈÕ
 *      Author: jiangxl
 */
#include "global.h"
#include "Cpu.h"
#include "Qi_Spec.h"
#include "systemDef.h"
#include "hal.h"
#include "systemTimers.h"



#define TOTAL_SAFETY_TYPE       (CountMeasurementType)
//static DPMType dpmType = Normal;

typedef struct
{
  boolean		bIsOver;
  uint16        lowLimit;
  uint16        upLimit;
  UnsafeCode  	unsafeCode;
}DetectContext;

static  DetectContext  SafetyDectectTable[TOTAL_SAFETY_TYPE] = //must  be the same order defined in enum MeasurementType
{
  {FALSE,       VOLTAGE_LOW_LIMIT,              VOLTAGE_HIGH_LIMIT,             UnsafeOverVoltage},
  //{FALSE,       TEMPERATURE_IC_ADC_LOW_LIMIT,   TEMPERATURE_IC_ADC_UP_LIMIT,    UnsafeOverIcTemperature},
  {FALSE,       TEMPERATURE_COIL5_ADC_LOW_LIMIT, TEMPERATURE_COIL5_ADC_UP_LIMIT,  UnsafeOverCoilTemperature},
  {FALSE,       TEMPERATURE_COIL6_ADC_LOW_LIMIT, TEMPERATURE_COIL6_ADC_UP_LIMIT,  UnsafeOverCoilTemperature},
  {FALSE,       TEMPERATURE_COIL7_ADC_LOW_LIMIT, TEMPERATURE_COIL7_ADC_UP_LIMIT,  UnsafeOverCoilTemperature},
  {FALSE,       CURRENT_LOW_LIMIT,              CURRENT_HIGH_LIMIT,             UnsafeOverCurrent}
};


static boolean IsOver(sint16 value, MeasurementType type)
{

	boolean bOver = SafetyDectectTable[type].bIsOver;

	if(bOver)
	{
		/*if(type == Coil5TempMeasurement)
		{
			if( value > (sint16)SafetyDectectTable[type].lowLimit)
			{
				bOver = FALSE;
			}
		}
		else if(type == Coil6TempMeasurement)
		{
			if( value > (sint16)SafetyDectectTable[type].lowLimit)
			{
				bOver = FALSE;
			}
		}
		else if(type == Coil7TempMeasurement)
		{
			if( value > (sint16)SafetyDectectTable[type].lowLimit)
			{
				bOver = FALSE;
			}
		}
		else*/
		{
			if(value < (sint16)SafetyDectectTable[type].lowLimit)
			{
				bOver = FALSE;
			}
		}
	}
	else
	{
		/*if(type == Coil5TempMeasurement)
		{
			if(value < (sint16)SafetyDectectTable[type].upLimit)
			{
				bOver = TRUE;
			}
		}
		else if(type == Coil6TempMeasurement)
		{
			if(value < (sint16)SafetyDectectTable[type].upLimit)
			{
				bOver = TRUE;
			}
		}
		else if(type == Coil7TempMeasurement)
		{
			if(value < (sint16)SafetyDectectTable[type].upLimit)
			{
				bOver = TRUE;
			}
		}
		else*/
		{
			if(value > (sint16)SafetyDectectTable[type].upLimit)
			{
				bOver = TRUE;
			}
		}
	}

	SafetyDectectTable[type].bIsOver = bOver;
	return bOver;
}


boolean SafetyMonitor(EventInfo* pEvtInfo)
{

	MeasurementType type;
	UnsafeCode unSafeCode;

	for(type=(MeasurementType)0; type<TOTAL_SAFETY_TYPE;type++)
	{
    //if(IsOver((SWORD)GetFilteredMeasurement(type), type))

		if(IsOver((sint16)GetFilteredMeasurement(type), type))
		{
			unSafeCode =  SafetyDectectTable[type].unsafeCode;
			pEvtInfo->eventId = EvtUnsafe;
			pEvtInfo->param1 = unSafeCode;
			return TRUE;
		}
	}

	return FALSE;
}









