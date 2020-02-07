/*
 * hal.c
 *
 *  Created on: 2019年6月28日
 *      Author: jiangxl
 */

#include "defines.h"
#include "Cpu.h"
#include "flexTimer_pwm1.h"
#include "flexTimer_mc1.h"
#include "ftm_hw_access.h"
#include "interrupt.h"
#include "hal.h"
#include "pins_driver.h"
#include "S32K144.h"
#include "systemDef.h"
#include "systemTimers.h"
#include "canCom1.h"

static uint16 current_offset;			//
static uint16_t ApCurrent;
uint16 CurTemp;
uint16 Cur;

void HAL_Init(void)
{
	ftm_state_t ftmStateStruct;

	/*
	 * Clock初始化
	 */
	CLOCK_SYS_Init(g_clockManConfigsArr, CLOCK_MANAGER_CONFIG_CNT,
                   g_clockManCallbacksArr, CLOCK_MANAGER_CALLBACK_CNT);
    CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

    /*
     * Pin初始化
     */
    PINS_DRV_Init(NUM_OF_CONFIGURED_PINS, g_pin_mux_InitConfigArr);

    PINS_DRV_SetPinIntSel(VDEMOD_GPIO,VDEMOD_PIN,PORT_INT_EITHER_EDGE);


	/*
	 *  初始化GPIO，设置方向为输出和初始值
	 */
	PINS_DRV_SetPinsDirection(TEST_GPIO0, (1 << TEST_PIN0));
	PINS_DRV_SetPins(TEST_GPIO0, (1 << TEST_PIN0));

	PINS_DRV_SetPinsDirection(COIL1_EN_GPIO, (1 << COIL1_EN_PIN));
	PINS_DRV_SetPins(COIL1_EN_GPIO, (1 << COIL1_EN_PIN));
	//PINS_DRV_ClearPins(COIL1_EN_GPIO, (1 << COIL1_EN_PIN));

	PINS_DRV_SetPinsDirection(COIL2_EN_GPIO, (1 << COIL2_EN_PIN));
	PINS_DRV_ClearPins(COIL2_EN_GPIO, (1 << COIL2_EN_PIN));

	//PINS_DRV_SetPins(COIL2_EN_GPIO, (1 << COIL2_EN_PIN));

    /*
     *  DMA初始化
     */

    EDMA_DRV_Init(&dmaController1_State,
        			  &dmaController1_InitConfig0,
    				  edmaChnStateArray,
    				  edmaChnConfigArray,
    				  EDMA_CONFIGURED_CHANNELS_COUNT);
    /*
     *  ADC初始化
     */

    ADC_DRV_ConfigConverter(INST_ADCONV1, &adConv1_ConvConfig0);


    /*
     * PWM初始化
     */
    FTM_DRV_Init(INST_FLEXTIMER_PWM1, &flexTimer_pwm1_InitConfig, &ftmStateStruct );
    FTM_DRV_InitPwm(INST_FLEXTIMER_PWM1, &flexTimer_pwm1_PwmConfig);

    /*
     * 1ms counter初始化
     */
    FTM_DRV_Init(INST_FLEXTIMER_MC1, &flexTimer_mc1_InitConfig,	&ftmStateStruct);
    FTM_DRV_InitCounter(INST_FLEXTIMER_MC1, &flexTimer_mc1_TimerConfig);
    FTM_DRV_CounterStart(INST_FLEXTIMER_MC1);


    /*
     * UART 初始化
     */
    LPUART_DRV_Init(INST_LPUART1, &lpuart1_State, &lpuart1_InitConfig0);

    /*
     * CAN 初始化
     */
    HAL_CANInit();

    /*
     * INT初始化
     */
    INT_SYS_InstallHandler(FTM0_Ovf_Reload_IRQn, &FTM1_Ovf_Reload_IRQHandler, (isr_t *)0);
    INT_SYS_EnableIRQ(FTM0_Ovf_Reload_IRQn);


    //INT_SYS_EnableIRQ(LPUART1_RxTx_IRQn);

    //INT_SYS_InstallHandler(PORTC_IRQn, &PORTC_IRQHandler, (isr_t *)0);
    INT_SYS_EnableIRQ(PORTC_IRQn);

}
/*add CAN Driver init
 *
 */
void HAL_CANInit()
{

	   FLEXCAN_DRV_Init(INST_CANCOM1, &canCom1_State, &canCom1_InitConfig0);

	    flexcan_data_info_t dataInfo =
	    {
	            .data_length = 1U,
	            .msg_id_type = FLEXCAN_MSG_ID_STD,
	            .enable_brs  = true,
	            .fd_enable   = true,
	            .fd_padding  = 0U
	    };

	    /* Configure RX message buffer with index RX_MSG_ID and RX_MAILBOX */
	    FLEXCAN_DRV_ConfigRxMb(INST_CANCOM1, 0, &dataInfo, 2);

}
/*
 *
 */
void HAL_SetPwmPeriod(uint32_t newPeriod)
{
	FTM_DRV_UpdatePwmPeriod(INST_FLEXTIMER_PWM1, FTM_PWM_UPDATE_IN_TICKS, newPeriod, TRUE);
}


uint16 HAL_GetAdcSampleData(ADC_CHANNEL_TYPE adc_channel)
{
	uint32 ret=0;
	uint16 ADC_result;
	//uint16 i, j;

	switch(adc_channel)
	{
	case KeyCurrentSense:
		ADC_DRV_ConfigChan(INST_ADCONV1,0, &AdcKeyCurrentChannel);		//Input Current
		break;
	case RailA5VSense:
		ADC_DRV_ConfigChan(INST_ADCONV1,0, &AdcRailA5VChannel);		//Rail 5V ADC0_10
		break;
	case Temp5Sense:
		ADC_DRV_ConfigChan(INST_ADCONV1,0, &AdcTemp5Channel);		//TEMP5 ADC0_5
		break;
	case Temp6Sense:
		ADC_DRV_ConfigChan(INST_ADCONV1,0, &AdcTemp6Channel);		//TEMP6 ADC0_4
		break;
	case Temp7Sense:
		ADC_DRV_ConfigChan(INST_ADCONV1,0, &AdcTemp7Channel);		//TEMP6 ADC0_6
		break;
	case InputVbatSense:
		ADC_DRV_ConfigChan(INST_ADCONV1,0, &AdcVbatChannel);		//TEMP6 ADC0_3
		break;
	default:
		break;
	}
	/*
	 *  等待ADC转换完成
	 */
	ADC_DRV_WaitConvDone(INST_ADCONV1);
	/*
	 *  ADC转换延时
	 */
	//for(i = 0; i<0xFFFF; i++)
	//{
//	 	for(j = 0; j < 5; j++);
	//}
	//for(i = 0; i<0xFFFF; i++)
	//{
	// 	for(j = 0; j < 5; j++);
	//}


	/*
	 *  ADC转换成功则利用串口输出ADC转换结果
	 */
	ADC_DRV_GetChanResult(INST_ADCONV1, 0, &ADC_result);


	switch(adc_channel)
	{
	case KeyCurrentSense:		// amplify =  0.015*100 = 1.5, so  I=ADC/1.5
		ret = ADC_result *2*3300;
		ret /=3;
		ret /= 4096;
		break;

	case RailA5VSense:
		ret = ADC_result *3300;
		ret /= 4096;
		ret *= HAL_RAIL_SENSE_MULTI_U;
		ret >>= HAL_RAIL_SENSE_SHIFT_BITS;
		break;

	case Temp5Sense:
	case Temp6Sense:
	case Temp7Sense:
		ret = ADC_result;
		break;

	case InputVbatSense:
		ret = ADC_result *3300 ;
		ret /= 4096;
		ret *= HAL_BATTERY_SENSE_MULTI_U;
		ret >>= HAL_BATTERY_SENE_SHIFT_BITS;
		break;

	default:
		break;

	}

	return (uint16)ret;

}


uint16 HAL_GetBatteryVoltage(void)
{

	return HAL_GetAdcSampleData(InputVbatSense);

}

void HAL_GetCurrentOffset()
{
	current_offset = HAL_GetAdcSampleData(KeyCurrentSense);
}

uint16 HAL_GetInputCurrent(void)
{

	CurTemp = HAL_GetAdcSampleData(KeyCurrentSense);

	if(CurTemp>current_offset)
	{
		Cur = CurTemp - current_offset;
	}
	else
	{
		Cur = 0;
	}
	return Cur;
}


uint16 HAL_GetTemp5(void)
{
	return HAL_GetAdcSampleData(Temp5Sense);
}

uint16 HAL_GetTemp6(void)
{
	return HAL_GetAdcSampleData(Temp6Sense);
}

uint16 HAL_GetTemp7(void)
{

	return HAL_GetAdcSampleData(Temp7Sense);
}

uint16 HAL_GetVrailVoltage(void)
{

	return HAL_GetAdcSampleData(RailA5VSense);
}


static uint16 GetMaxValue(uint8 loops)
{
	uint8 i;
	uint16 currentValue;
	uint16 maxValue;
	maxValue = 0;
	for(i = 0; i < loops; i++ )
	{
		//urrentValue = GetInstantValue(type);
		currentValue = HAL_GetInputCurrent();
		if(currentValue > maxValue)
		{
			maxValue = currentValue;
		}
	}
	return maxValue;
}

uint16 HAL_GetPingCurrent()
{

	uint16 MaxCurrent;

	uint32	tmp;

	tmp = PWM_MCLOCK/HAL_AP_FREQUENCY;

	//HAL_SetPwmFreq(HAL_AP_FREQUENCY);
	HAL_SetPwmPeriod(tmp);

	HAL_EnablePower();

	MaxCurrent = GetMaxValue(LOOP_NUMER);//,CurrentMeasurement);

	HAL_DisablePower();

	return MaxCurrent;
}


void HAL_EnablePower()
{
	//uint8_t index;
	//ftm_pwm_param_t param;

	/*for (index = 0U; index < flexTimer_pwm1_PwmConfig.nNumCombinedPwmChannels; index++)

	{

		FTM_DRV_EnablePwmChannelOutputs(g_ftmBase[INST_FLEXTIMER_PWM1],
				flexTimer_pwm1_PwmConfig.pwmCombinedChannelConfig[index].hwChannelId);

		FTM_DRV_EnablePwmChannelOutputs(g_ftmBase[INST_FLEXTIMER_PWM1],
				flexTimer_pwm1_PwmConfig.pwmCombinedChannelConfig[index].hwChannelId+1);
	}*/

	g_ftmBase[INST_FLEXTIMER_PWM1]->SC |= FTM_SC_PWMEN0_MASK | FTM_SC_PWMEN1_MASK | FTM_SC_PWMEN6_MASK | FTM_SC_PWMEN7_MASK;


}


void HAL_DisablePower()
{
	//uint8_t index;
	//ftm_pwm_param_t param;

	/*for (index = 0U; index < flexTimer_pwm1_PwmConfig.nNumCombinedPwmChannels; index++)

	{

		FTM_DRV_DisablePwmChannelOutputs(g_ftmBase[INST_FLEXTIMER_PWM1],
				flexTimer_pwm1_PwmConfig.pwmCombinedChannelConfig[index].hwChannelId);

		FTM_DRV_DisablePwmChannelOutputs(g_ftmBase[INST_FLEXTIMER_PWM1],
				flexTimer_pwm1_PwmConfig.pwmCombinedChannelConfig[index].hwChannelId+1);
	}
	*/

	g_ftmBase[INST_FLEXTIMER_PWM1]->SC &= ~(FTM_SC_PWMEN0_MASK | FTM_SC_PWMEN1_MASK | FTM_SC_PWMEN6_MASK | FTM_SC_PWMEN7_MASK);
	//FTM_DRV_DisablePwm(INST_FLEXTIMER_PWM1, &flexTimer_pwm1_PwmConfig);
}

boolean HAL_DetectObject()
{
	uint32 tmp;
	tmp = PWM_MCLOCK/HAL_AP_FREQUENCY;
	//SetPwmDutyDiv(AP_FREQ_DIV, AP_DUTY_DIV);
	//HAL_SetPwmFreq(HAL_AP_FREQUENCY);
	HAL_SetPwmPeriod(tmp);
	HAL_EnablePower();
	ST_WaitMs(2);
	ApCurrent = HAL_GetInputCurrent();
	HAL_DisablePower();

	if(ApCurrent > HAL_AP_CURRENT_THRC )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

void HAL_Coil1En_Config(boolean conf)
{
	if(conf==TRUE)
	{
		PINS_DRV_SetPins(COIL1_EN_GPIO, (1 << COIL1_EN_PIN));
	}
	else
	{
		PINS_DRV_ClearPins(COIL1_EN_GPIO, (1 << COIL1_EN_PIN));
	}

}

void HAL_Coil2En_Config(boolean conf)
{
	if(conf==TRUE)
	{
		PINS_DRV_SetPins(COIL2_EN_GPIO, (1 << COIL2_EN_PIN));
	}
	else
	{
		PINS_DRV_ClearPins(COIL2_EN_GPIO, (1 << COIL2_EN_PIN));
	}

}

void DeselectAllCoils()
{
	HAL_Coil2En_Config(FALSE);
	HAL_Coil1En_Config(FALSE);
}


void SelectCoils(uint8 index)
{

	if(index == CoilOne)
	{
		HAL_Coil2En_Config(FALSE);
		HAL_Coil1En_Config(TRUE);
	}
	else if(index == CoilTwo)
	{
		HAL_Coil1En_Config(FALSE);
		HAL_Coil2En_Config(TRUE);
	}

}

void HAL_UartSendCommand(uint8 command)
{
	LPUART_DRV_SendData(INST_LPUART1,&command,1);
}

uint8 HAL_UartRecvSts()
{
	uint8 receive_data;

	LPUART_DRV_ReceiveData(INST_LPUART1,&receive_data,1);

	return receive_data;
}


