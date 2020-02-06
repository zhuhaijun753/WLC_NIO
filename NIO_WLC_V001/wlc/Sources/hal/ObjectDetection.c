/*
 * ObjectDetection.c
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

static sint16		subPower = 0;
static uint16		preTmTick;// = 0;
static uint16		fodLossThreshold;
static boolean		bFodEnable;// = TRUE;
static boolean   	bStartAvg = FALSE;
static uint16   	avgReceivePower;// = 0;
//static uint16   	avgTransmitPower;// = 0;
static uint8   		fodCounter =0;

static uint16 		fod_powerloss;

static uint16 		avgCurrent;// = 0;    //average current in window time
static uint16	 	avgVoltage;// = 0;

static uint8 		fodFlag;// = FALSE;

#if 0
@tiny WORD fod_powerloss_Qi1_1[10][2]


={
  50,100,
  100,150,
  150,200,
  200,250,
  250,300,
  300,350,
  350,400,
  400,450,
  450,500,
  500,550
};
#endif


//******************************************************************************
// function name : DetectObject
// description : ���������ж��Ƿ��н��ն˺ͽ�������,���ϻ�ȡ��
//
// input : pObjectStatus : ObjectAppear      - ����Ƿ��н��ն˻�����������
//                         ObjectDisappear   - ����Ƿ��н��ն˻��������ȡ��
//
// global variable : gCurrentAnalogpingAppear : ���RX���ϵ�����ֵ
//                   gCurrentAnalogpingDisppear : ���RXȡ�µ�����ֵ
//
//
// return : ����mode, ����TRUE  ��ʾ�н��ն˺ͽ������� ���ϻ�ȡ��
//                        FALSE ��ʾû�н��ն˺ͽ������� ���ϻ�ȡ��
// note : ���ô˺���ǰ���pwm�ر�һ��ʱ��
//
//******************************************************************************

boolean DetectObject()
{
		uint16 adcData = 0;

		uint32	tmp;

		tmp = PWM_MCLOCK/HAL_AP_FREQUENCY;
		//WORD adcDataMax = 0;
		//StopPWMPing();

		//adcDataMax = GetMaxCurrent(MEASURE_TIME);
		//DisablePower();

		//InitMCU();
		//bLowPowerFlg = FALSE;
		//DPToAPFlg = TRUE;
		//InitClock();
		//InitTimer2(); //1ms���r

		//SetPwmDutyDiv(AP_FREQ_DIV, AP_DUTY_DIV);
		//HAL_SetPwmFreq(HAL_AP_FREQUENCY);
		HAL_SetPwmPeriod(tmp);
		HAL_EnablePower();

		adcData = HAL_GetInputCurrent();
		if(adcData > AP_CURRENT_THRC )
		{
			 return TRUE;
		}
		else
		{
			return FALSE;
		}

}


uint16 GetTransmitterPower()
{

	uint16 transmitterPower;

	transmitterPower = ((uint32) ((uint32)avgVoltage * (uint32)avgCurrent)) / 1000;

	return (uint16)transmitterPower;
}

static uint16 GetReceiverPower()
{

	uint16 receiverPower = 0;
	uint16 transmitterPower;
	uint16 recvPower;
	uint8 fodIndex;
	//BYTE fod_powerlossH;
	//BYTE fod_powerlossL;
	//WORD fod_powerloss;
	transmitterPower = GetTransmitterPower();
	fodIndex = (uint8)(transmitterPower /250 - 1);
	if(fodIndex <= 8)
	{
		 fod_powerloss = 355;
	}
	else if(fodIndex > 23)
	{
		fod_powerloss = 4200;
	}
	else
	{
		fodIndex = (uint8)((fodIndex - 9)*2);
		//fod_powerloss = (StmReadEEPROM(0x4020 + fodIndex)<<8) | StmReadEEPROM(0x4021 + fodIndex);

	}

	recvPower = (uint16)GetRecvPower();
	receiverPower = (uint16)(((uint32) ((uint32)recvPower * (uint32)gMaxPower * 1000)) / 128) ;
	receiverPower += fod_powerloss;

   	return receiverPower;
}

boolean GetAvgRevPower()
{
	uint16 curTick = ST_GetTimerTick();
	uint16 transmitterPower;
	uint8 windowSize = 10;  //10ms
    if(bStartAvg)
    {
    	if(gWindowSize != 0)
    	{
    		windowSize = gWindowSize;
    	}

    	if((curTick - preTmTick) <= windowSize)
    	{
    		avgVoltage = HAL_GetBatteryVoltage();
    		avgCurrent = GetInstantValue(CurrentMeasurement);//HAL_GetInputCurrent();
    	}
    	else
    	{
    		bStartAvg = FALSE;
    		preTmTick = curTick;
    		transmitterPower = GetTransmitterPower();
    		subPower = transmitterPower - avgReceivePower;
    		if(subPower < 0)
    		{
    			subPower = 0;
    		}
    		return TRUE;
    	}

    }

    return FALSE;
}

void StartAvgRevPower()
{
	preTmTick = ST_GetTimerTick();

	avgVoltage = HAL_GetBatteryVoltage();
	avgCurrent = GetInstantValue(CurrentMeasurement);//HAL_GetInputCurrent();

	avgReceivePower = GetReceiverPower();

	bStartAvg = TRUE;
}


static boolean IsFodCounterOverflow(uint16 current,uint16 threshold)
{

	if(current > threshold && !fodFlag)
	{
		fodCounter++;
		if(fodCounter >= FOD_COUNTER_MAX)
		{
			fodFlag = TRUE;
			fodCounter = 0;
		}
	}
	else
	{
		fodCounter = 0;
	}

	if(fodFlag)
	{
		return TRUE;
	}

	return FALSE;
}

//******************************************************************************
// function name : Fod_NoPowerTransfer
// description : fodû��Power Transfering�����,�ȼ�һ��ʱ��pwm��,������Ȧ����,
//               Ȼ�����ֵ�����Ƚ�;������ֵʱ,fod������1;
//               ��fod�������ڸ�����ֵ����ʱ,�ж�fod����
//
// input :
//
// return : TRUE : fod
//          FALSE : ��fod
//
// note :
//
//******************************************************************************

static boolean Fod_NoPowerTransfer()
{
    uint16 current = HAL_GetPingCurrent();
    return IsFodCounterOverflow(current, FOD_IN_CURRENT_THRC);

}

//******************************************************************************
// function name : FodPowerNotzero
// description : fod during power trasfering stage, and received power is not 0�����.//
//                  gRectifiedPowerValueֵ��Ϊ0,���㹦�����=TX-RX-LOSS_TABLE[]
//                      Ȼ����fod���������ֵ�Ƚ�
//                  �������δ�����ֵʱ,fod������1;
//                  ��fod�������ڸ�����ֵ����ʱ,�ж�fod����
//
// input : NONE
//
// global variable : gMaxPower : RX�����//
//                   gQiVersion : Qi�汾��
//                   gFodTableQi1p0[] gFodTableQi1p1[] : ��֪ĳ�����¹������
//
// return : FALSE : ��fod
//          TRUE : fod
//
// note :
//
//******************************************************************************

static boolean FodPowerNotzero()
{
   return IsFodCounterOverflow(subPower,fodLossThreshold);
}


//******************************************************************************
// function name : Fod
// description : fod��Ϊ3�����
//                 ���1 û��ͨѶ����� �������Ƿ񳬹�fod������ֵ
//                 ���2 ��ͨѶ����� �����ʰ�ֵ
//                   Ϊ0 �������Ƿ񳬹�fod������ֵ
//                   ��Ϊ0 ��fod�򿪵������,����������Ƿ񳬹���ֵ
//
// input : NONE
//
// global variable : receivedPower : �յ��Ĺ��ʰ�
//
// return :
//
// note :
//
//******************************************************************************

boolean Fod(StateId KeycurrentState)
{

	if(!bFodEnable)// || (gQiVersion == 0x10 && currentState != StatePing))
	{
		return FALSE;
	}

	if(KeycurrentState == StatePowerTrans)
	{

		return FodPowerNotzero();
		//return FALSE;
	}
	else
	{
		return Fod_NoPowerTransfer();
		 //return FALSE;
	}

}


//******************************************************************************
// function name : getFodLossValue
// description : ��fod adc�ŵõ�fod�򿪻�ر�,�Լ�fod loss value
//
// input :
//
// global variable : fodFunctionOnOff : fod���ܴ򿪻�ر�;0:�ر�;1:��
//                   fodLossValue : fod loss value,��λmw
//
// return : NONE
//
// note :
//
//******************************************************************************

void InitFodLossValue()
{

	//BYTE i;
	bFodEnable = FALSE;//TRUE;
	/*
	for(i = 0;i < 10;i++)
    {
        if((avgCurrent < fod_powerloss_Qi1_1[i][0])||(avgCurrent == fod_powerloss_Qi1_1[i][0]))
        {
            fodLossThreshold = fod_powerloss_Qi1_1[i][1];
            break;
        }
    }
	*/
	fodLossThreshold =700;//default

}

uint16 GetSubPower()
{
  return subPower;
}

void ResetFodCounter()
{
  fodCounter = 0;
  fodFlag = FALSE;
}

