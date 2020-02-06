/*
 * CommDec.c
 *
 *  Created on: 2019��7��5��
 *      Author: jiangxl
 */

//******************************************************************************
//  Wireless Power----power Transmitter
//  Author:  jiangxiaoliang(jiangxiaoliang@semi.crmicro.com)
//  Company: Dis co.
//  Date:    April 2016
//******************************************************************************
#include "Cpu.h"
#include "defines.h"
#include "global.h"
#include "systemDef.h"

//static BYTE number_detect=0;										// �������Ԫ����
//static BYTE data_detect=0;											// number_detect=1				data_detect=0 -> "0"		data_detect=1 -> "1"
																								// number_detect=2				0 -> "0""0"  1 -> "0""1"  2 -> "1""0"  3 -> "1""1"

//static BYTE judge = 0;													//		  CommDlyCnt[3]   [2]    [1]       [0]
																								//		 ______________         ______              _
																								//		|              |       |      |            |
																								//		|              |       |      |            |
																								// ___|              |_______|      |____________|
																								//                   ^       ^      ^            ^
																								//                   |       |      |            |
																								//       judge =     3       2      1            0
																								//
static uint8 data_method = 0;										// 0:Preamble  1:Header  2:Message  3:Checksum

uint8 preamble=0;
uint8 Header=0;
//unsigned char Message[16]={0};
uint8 ByteMessage=0;
uint8 checksum=1;
uint8 receive_counter=0;

//unsigned char data_temp = 0;
//unsigned char data_detect_old = 0xFF;	//ǰһ������

//unsigned short xor_temp =0;

//unsigned char checkout=0;
//unsigned short checkrow =0;

char message_numb = 0;				//Message����
char message_count = 0;				//Message����
//BYTE packet_count=0;
//BYTE out_count=0;

//static uint16 CommUsCountD=0;
static uint16 CommUsDelay=0;
//static BYTE CommDlyCnt[2]={0};
//static BYTE PacketNum=0;

DEC_DETECT_NUMTypeDef LastCode;

#if 1
uint16 GetCommUsDelay()
{
	return CommUsDelay;
}

#if 1
void variable_clear()
{
	data_method = 0;   // 0Ϊpreamble��1ΪHeader��2ΪMessage��3Ϊchecksum
	receive_counter = 0;
	preamble = 0;
	Header = 0;
	CommDlyCnt[0] = 0;
	CommDlyCnt[1] = 0;
	ByteMessage = 0;
	checksum =1;
	message_numb = 0;
	message_count = 0;
}
#endif

DEC_DETECT_NUMTypeDef CodeDecoder()
{
	if(CommDlyCnt[0] > LONG_1K_TWO)		//��ǰֵ����1K������ֵ
	{// �����ź�
		LastCode = CODE_DECODER_NULL;
		variable_clear();
		return CODE_DECODER_NULL;
	}
	else if((data_method == 0)&&((CommDlyCnt[0] > LONG_1K_MAX)||(CommDlyCnt[0] < LONG_2K_MIN)))
	{ // �������preamble����ǰֵ����1K�����ֵ����С��2K��С��ֵ���ж�Ϊ�����ź�
		LastCode = CODE_DECODER_NULL;
		variable_clear();
		return CODE_DECODER_NULL;
	}
	else if(CommDlyCnt[0]>LONG_1K_MIN && (CommDlyCnt[0]<LONG_1K_MAX))	//����1K��ֵ�жϷ�Χ��
	{ //ȷ����0ֵ
		LastCode = CODE_DECODER_0;
		//GPIOC->ODR ^= GPIO_PIN_3;
		return CODE_DECODER_0;
	}
	else if((CommDlyCnt[0]<LONG_2K_MAX) && (CommDlyCnt[0]>LONG_2K_MIN))	//����2K��ֵ�жϷ�Χ��
	{ //ȷ��Ϊ1�İ��ֵ
		if((CommDlyCnt[1] < LONG_2K_MAX) && (CommDlyCnt[1]>LONG_2K_MIN))	//
		{
			LastCode = CODE_DECODER_1;
			CommDlyCnt[0] = 0;
			CommDlyCnt[1] = 0;
//			GPIOC->ODR ^= GPIO_PIN_3;
			return CODE_DECODER_1;	//�ж�Ϊ1����Ԫ
		}
		else
		{
				return CODE_DECODER_NULL;
		}
	}
	return CODE_DECODER_NULL;
}

#if 1
DEC_RESULT_TypeDef CommDecoder(uint8 *packet)
{
//	char error = 0;
	int i;


	if(CODE_DECODER_NULL != CodeDecoder())
	{
				// data_method:0Ϊpreamble��1ΪHeader��2ΪMessage��3Ϊchecksum
		switch(data_method)
		{
			case 0: // preamble
				if(LastCode == CODE_DECODER_0)	//�����⵽"0"
				{
					if((preamble&0x7F)==0x7F)
					{ //preamble����7��"1"��Ԫ
						data_method = 1;		//��ת��Header
					}
					else
					{		//���������7��"1"
						preamble = 0;				//�������
					}
				}
				else if(LastCode == CODE_DECODER_1)		//�����⵽"1"
				{
					preamble = (preamble << 1) + 1;
				}
				break;
			case 1: // 1ΪHeader
				receive_counter++;
								//����message�ĳ���
				if(receive_counter == 10)
				{
					if(LastCode==CODE_DECODER_1)						//�ж�Stop
					{
						data_method = 2;		// ��ת��Message
						checksum = 1;
					}
					else
					{
						variable_clear();
					}

					if(Header < 0x20)
					{
						message_numb = 1;
					}
					else if(Header < 0x80)
					{
						message_numb = Header/16;
					}
					else if(Header < 0xE0)
					{
						message_numb = Header/8 - 8;
					}
					else
					{
						message_numb = Header/4 - 36;
					}
//					PacketNum = 0;
					packet[0] = Header;			//��Header���뻺��
//					PacketNum++;
					receive_counter = 0;
				}
				else if(receive_counter<9)
				{
					if(LastCode==CODE_DECODER_0)
					{
						Header = Header>>1;
					}
					else if(LastCode==CODE_DECODER_1)
					{
						Header = Header>>1 | 0x80;
						checksum += 1;
					}
				}
				else if(receive_counter==9)
				{
					if(LastCode!=(checksum&0x01))
					{
						variable_clear();
					}
				}
				break;
			case 2: //Message
				if((receive_counter == 0)&&(LastCode != CODE_DECODER_0))		// first "0"
				{
					variable_clear();
				}
				else if(receive_counter < 9)
				{
					if(LastCode == CODE_DECODER_1)
					{
						//Message[message_count] += (1 << (receive_counter-1));
						ByteMessage += 1 << (receive_counter-1);
//						checkout++;
						checksum++;
					}
				}
				else if(receive_counter == 9)
				{
					if(LastCode != (checksum&0x01))
					{
						variable_clear();
					}
				}


				if(receive_counter == 10)
				{
					if(LastCode != CODE_DECODER_1)		// stop bit
					{
						variable_clear();
					}
					else
					{
						//Message[message_count] += (1 << receive_counter);
						packet[message_count+1] = ByteMessage;
						receive_counter = 0;
						ByteMessage = 0;
						checksum = 1;
						message_count++;

//						if(message_count==6)
//						{
//							ByteMessage = ByteMessage;
//						}

						if(message_count >= message_numb)
						{
							data_method = 3;
							message_count = 0;
						}
					}
				}
				else
				{
					receive_counter++;
				}
				break;
			case 3://checksum
				if((receive_counter == 0)&&(LastCode != CODE_DECODER_0))
				{
//					error = 1;
					variable_clear();
				}
				else if(receive_counter < 9)
				{
					if(LastCode == CODE_DECODER_1)
					{
						//checksum += (1 << receive_counter);
						ByteMessage += 1<<(receive_counter-1);
//						checkout++;
						checksum++;
					}
				}
				else if(receive_counter == 9)
				{
					if(LastCode != (checksum&0x01))
					{
						//checksum += (1 << receive_counter);
						variable_clear();
					}
				}

				if(receive_counter == 10)
				{
					if(LastCode != CODE_DECODER_1)		// stop bit
					{
						variable_clear();
					}
					else
					{
						packet[message_numb+1] = ByteMessage;
						data_method = 4;
						ByteMessage = packet[0];
						for(i = 1; i < message_numb+1; i++)
						{
							ByteMessage ^= packet[i];
						}

						if(ByteMessage == packet[message_numb+1])
						{ //У��ͨ��
							return DECODER_SUCCESS;
						}
						else
						{ //У��ʧ��
							return DECODER_SUCCESS_CHECKSUMFAIL;
						}

						checksum = 1;
					}
					receive_counter = 0;
				}
				else
				{
					receive_counter++;
				}
				break;

//			case 4:
//				ByteMessage = packet[0];
//				for(i = 1; i < message_numb+1; i++)
//				{
//					ByteMessage ^= packet[i];
//				}
//
//				if(ByteMessage == packet[message_numb+1])
//				{ //У��ͨ��
//					return DECODER_SUCCESS;
//				}
//				else
//				{ //У��ʧ��
//					return DECODER_SUCCESS_CHECKSUMFAIL;
//				}

//			break;

			default: //error
//				error = 1;
				variable_clear();
				break;
		}
	}
	return DECODER_FAIL;

}

#endif

#endif

#if 0

/***********************************************/
/*  COMM Interrupt Handler                     */
/*                                             */
/***********************************************/

@near @interrupt void EXTI3 (void)
{
	WORD tmp;
//  disableInterrupts();
	//GPIO_Init(GPIOD,GPIO_PIN_5,GPIO_MODE_OUT_PP_LOW_FAST);//��PD5����Ϊ���ģʽ��������IO�ж�
	//GPIO_Init(GPIOD,GPIO_PIN_5,GPIO_MODE_IN_PU_IT);				//��PD5����Ϊ�����ж�ģʽ
	tmp = GetUsCount();

	CommUsDelay = tmp-CommUsCountD;
	CommUsCountD = tmp;

  if(CommUsDelay>3)				// ȥë�̣�С��30us�ļ����ʶ��Ϊë�̣��������
  {
//		CommDlyCnt[3] = CommDlyCnt[2];
//		CommDlyCnt[2] = CommDlyCnt[1];
		CommDlyCnt[1] = CommDlyCnt[0];
		CommDlyCnt[0] = CommUsDelay;
	}

//  enableInterrupts();
	#if 1
	if(DECODER_SUCCESS==CommDecoder(RxPacket))
	{
		variable_clear();
		DecoderFinish = 1;
		GPIOC->ODR ^= GPIO_PIN_3;		// TEST_PIN, if decode successfully, toggle pc3
	}
	#endif
}

#endif

