/*
 * measure.c
 *
 *  Created on: 2019��7��15��
 *      Author: jiangxl
 */

#include "global.h"
#include "Cpu.h"
#include "Qi_Spec.h"
#include "systemDef.h"
#include "hal.h"
#include "systemTimers.h"


static uint16  filteredMeasurements[CountMeasurementType];

static uint16 FilterMeasurementByWeight(uint16 average, uint16 newValue,uint8 weight)
{
  return ( average + ( ((sint16)newValue - (sint16)average ) >> weight ) );
}

uint16 FilterMeasurement(uint16 average, uint16 newValue)
{

	return   FilterMeasurementByWeight(average,newValue,1);
}

uint16 GetInstantValue(MeasurementType type)
{
	//uint16 current;
	uint16 FilteredValue = 0;

	if(type == CurrentMeasurement)
	{
		FilteredValue = HAL_GetInputCurrent();
		//if(current > ginitCurrent)
		//{
		//	FilteredValue = current;// - ginitCurrent;

		//}
	}
	else if(type == VoltageMeasurement)
	{
		FilteredValue = HAL_GetBatteryVoltage();
	}
	return FilteredValue;
}

void InitMeasurement()
{
	filteredMeasurements[VoltageMeasurement] = HAL_GetBatteryVoltage();
	filteredMeasurements[Coil5TempMeasurement] = HAL_GetTemp5();//GetInstantCoilTemperatureADC();
	filteredMeasurements[Coil6TempMeasurement] = HAL_GetTemp6();//GetInstantCoilTemperatureADC();
	filteredMeasurements[Coil7TempMeasurement] = HAL_GetTemp7();//GetInstantCoilTemperatureADC();
	//filteredMeasurements[IcTempMeasurement] = GetInstantIcTemperatureADC();
	//delayMs_hd(150);
	//ginitCurrent = HAL_GetInputCurrent();//GetInstantValue(CurrentMeasurement);
	HAL_GetCurrentOffset();
	filteredMeasurements[CurrentMeasurement] = HAL_GetInputCurrent();//GetInstantValue(CurrentMeasurement);//
}

void MeasureAll()
{
  	static uint16  tickLastMeasureVoltage = 0;
  	static uint16  tickLastMeasureTemperature = 0;
  	static uint16  tickLastMeasureCurrent = 0;

  	uint16 currentTick = ST_GetTimerTick();

  	if((currentTick - tickLastMeasureVoltage)> VOLTAGE_MEASURE_INTERVAL)
  	{
  		filteredMeasurements[VoltageMeasurement]= HAL_GetBatteryVoltage();
  		tickLastMeasureVoltage = currentTick;
  	}

	if((currentTick - tickLastMeasureTemperature)> TEMPERATURE_MEASURE_INTERVAL)
	{
		filteredMeasurements[Coil5TempMeasurement] = HAL_GetTemp5();//GetInstantCoilTemperatureADC();
		filteredMeasurements[Coil6TempMeasurement] = HAL_GetTemp6();//GetInstantCoilTemperatureADC();
		filteredMeasurements[Coil7TempMeasurement] = HAL_GetTemp7();//GetInstantCoilTemperatureADC();
		tickLastMeasureTemperature = currentTick;
	}

  	if((currentTick - tickLastMeasureCurrent)> CURRENT_MEASURE_INTERVAL)
  	{
  		filteredMeasurements[CurrentMeasurement]= GetInstantValue(CurrentMeasurement);//HAL_GetInputCurrent();//
  		tickLastMeasureCurrent = currentTick;
  	}

}

/*

// function name : get_VIN_SENSE
// description : ���������Դ��ѹ
//
// input :
//
// global variable : VIN_sense_voltage : ��ѹ,��λmv
//
// return : NONE
//
// note :
//

WORD  GetInstantVoltage()
{
    //return HwAdcSample(VOL_AVERAGE_NUMER,VSENSE_CHANNEL);
		return HwAdcSampleVS(VOL_AVERAGE_NUMER);
}

// function name : get_current
// description : ������Ȧ����
//
// input :
//
// global variable : curCurrent : ��Ȧ����,��λma
//
// return : NONE
//
// note :
//

WORD  GetInstantCurrent()
{
    return HwAdcSample(CUR_AVERAGE_NUMER,ISENSE_CHANNEL);
}


#if 0

// function name : GetInstantTemperatureADC
// description : �����������
//
// input :
// return : ADC reading

WORD GetInstantCoilTemperatureADC()
{
	return HwAdcSample(TEMP_AVERAGE_NUMER,TEMPEX_CHANNEL);
}



// function name : get_IC_temperature
// description : оƬ�ڲ������¶�(��ѹ)
//
// input :
//
// global variable : IcTempAdcValue : �ڲ��¶Ȳ�������adc����ֵ
//
// return : NONE
//
// note :
//          оƬ�¶Ƚӵ�adc0 0ͨ��,ʾ����������100mv
//          �¶�����-40 - 100��,��ѹ�仯1.304-2.114
//          ���ѹ1.95v����(1950mv)
//

WORD GetInstantIcTemperatureADC()
{
   return HwAdcSample(TEMP_AVERAGE_NUMER,TEMPIC_CHANNEL);
}


// function name :  GetFODSetADC()
// description : get ADC reading for the FOD loss threshold setting
//
// input : None//

//
// return : ADC 12-bit data
//
//
//


WORD GetFODSetADC()
{
  return HwAdcSample(FOD_AVERAGE_NUMER,FOD_CHANNEL);
}
#endif

WORD GetMaxValue(BYTE loops,MeasurementType type)
{
	BYTE i;
	WORD currentValue;
	WORD maxValue;
	maxValue = 0;
	for(i = 0; i < loops; i++ )
	{
		currentValue = GetInstantValue(type);
		//currentValue = GetInstantCurrent();
		if(currentValue > maxValue)
		{
			maxValue = currentValue;
		}
	}
	return maxValue;
}

WORD GetPingCurrent()
{
   WORD avgCurrent;

   SetPwmDutyDiv(DP_FREQ_DIV, DP_DUTY_DIV);
   //StartPWMPing();
	 EnablePower();


	 //delayMs_hd(PWMSTART_DELAY);


   avgCurrent = GetMaxValue(LOOP_NUMER,CurrentMeasurement);
	 //avgCurrent = GetInstantValue(CurrentMeasurement);

	 //delayMs_hd(PWMCLOSE_DELAY);

   //StopPWMPing();
	 DisablePower();
   return avgCurrent;
}
*/

uint16 GetFilteredMeasurement(MeasurementType type)
{
  	return filteredMeasurements[type];
}


