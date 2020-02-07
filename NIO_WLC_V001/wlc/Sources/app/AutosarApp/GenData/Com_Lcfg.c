/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Com
 *           Program: VAG AR4 (MSR_Vag_SLP5)
 *          Customer: SAIC Volkswagen Automotive Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016393AFP-C
 *    License Scope : The usage is restricted to CBD1900162_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2019-12-01 17:02:51
 *           Project: WLC - Version 1.0
 *          Delivery: CBD1900162_D00
 *      Tool Version: DaVinci Configurator (beta) 5.19.29
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 1882 EOF */ /* MD_MSR_AutosarBoolean */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"


#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x0000u   /* [/ActiveEcuC/Com/ComConfig/VehSpd_oBCU_04_oNIO_ES6_RF_CAN_SR_V3_0_91cf0813_RxInitValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt32
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt32Type, COM_CONST) Com_ConstValueUInt32[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt32      Referable Keys */
  /*     0 */       0x00000000u   /* [/ActiveEcuC/Com/ComConfig/VehOdometer_oCDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_c4f897da_RxInitValue] */
};
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x00u   /* [/ActiveEcuC/Com/ComConfig/CGW_03_CRC_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_bd877a03_RxInitValue, /ActiveEcuC/Com/ComConfig/CGW_03_MsgCntr_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e603ff9_RxInitValue, /ActiveEcuC/Com/ComConfig/CGW_WLC_CRC_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_67a87047_RxInitValue, /ActiveEcuC/Com/ComConfig/CGW_WLC_MsgCntr_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_2e39b55e_RxInitValue, /ActiveEcuC/Com/ComConfig/ComfEna_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_daac19b6_RxInitValue, /ActiveEcuC/Com/ComConfig/ComfEna_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_1a60ba8c_RxInitValue, /ActiveEcuC/Com/ComConfig/Day_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_76626f65_RxInitValue, /ActiveEcuC/Com/ComConfig/Hr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_f5c3e99f_RxInitValue, /ActiveEcuC/Com/ComConfig/ImobEnaReq_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a2f30745_RxInitValue, /ActiveEcuC/Com/ComConfig/Min_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_c05ffcb3_RxInitValue, /ActiveEcuC/Com/ComConfig/Mth_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a0768b21_RxInitValue, /ActiveEcuC/Com/ComConfig/Sec_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_48a1d09a_RxInitValue, /ActiveEcuC/Com/ComConfig/VehState_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e049202_RxInitValue, /ActiveEcuC/Com/ComConfig/VehState_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_70d412f9_RxInitValue, /ActiveEcuC/Com/ComConfig/WLCChrgFctEnaReq_oCDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_e37de241_RxInitValue, /ActiveEcuC/Com/ComConfig/Yr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_cdf9e710_RxInitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PduGrpVector      Referable Keys */
  /*     0 */         0x02u,  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
  /*     1 */         0x01u   /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx, /ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx, /ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx, /ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx, /ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx, /ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx, /ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                   Description
  InitValueUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BufferIdx                 the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  InitValueIdx              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  RxPduInfoIdx              the index of the 1:1 relation pointing to Com_RxPduInfo
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[18] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitValueUsed  ApplType                           BitLength  BitPosition  BufferIdx  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*     0 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,        0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,           4u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/CGW_03_CRC_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_bd877a03_Rx, /ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*     1 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         12u,        1u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           4u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/CGW_03_MsgCntr_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e603ff9_Rx, /ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*     2 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,        2u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,           6u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_CRC_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_67a87047_Rx, /ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
  { /*     3 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,         12u,        3u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           6u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_MsgCntr_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_2e39b55e_Rx, /ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
  { /*     4 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         16u,        4u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           4u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/ComfEna_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_daac19b6_Rx, /ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*     5 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,          2u,        5u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,           3u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/ComfEna_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_1a60ba8c_Rx, /ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  { /*     6 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        5u,         16u,        6u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           2u,           0u,           5u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/Day_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_76626f65_Rx, /ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*     7 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        5u,         24u,        7u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           3u,           0u,           5u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Hr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_f5c3e99f_Rx, /ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*     8 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         14u,        8u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           3u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/ImobEnaReq_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a2f30745_Rx, /ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  { /*     9 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        6u,         32u,        9u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           4u,           0u,           5u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Min_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_c05ffcb3_Rx, /ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    10 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,          8u,       10u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           5u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Mth_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a0768b21_Rx, /ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    11 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        6u,         40u,       11u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           5u,           0u,           5u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sec_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_48a1d09a_Rx, /ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    12 */          TRUE, COM_UINT32_APPLTYPEOFRXACCESSINFO,       24u,         16u,        0u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         3u,           2u,           0u,           1u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/VehOdometer_oCDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_c4f897da_Rx, /ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx] */
  { /*    13 */          TRUE, COM_UINT16_APPLTYPEOFRXACCESSINFO,       13u,         24u,        0u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           3u,           0u,           0u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/VehSpd_oBCU_04_oNIO_ES6_RF_CAN_SR_V3_0_91cf0813_Rx, /ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx] */
  { /*    14 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,          8u,       12u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           1u,           0u,           4u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/VehState_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e049202_Rx, /ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*    15 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        4u,          4u,       13u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,           3u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/VehState_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_70d412f9_Rx, /ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  { /*    16 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,          0u,       14u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,           2u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/WLCChrgFctEnaReq_oCDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_e37de241_Rx, /ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx] */
  { /*    17 */          TRUE,  COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,       15u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,           5u,                     0u }   /* [/ActiveEcuC/Com/ComConfig/Yr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_cdf9e710_Rx, /ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[18] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */              13u,  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx] */
  /*     1 */              12u,  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx] */
  /*     2 */              16u,  /* [/ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx] */
  /*     3 */               5u,  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  /*     4 */               8u,  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  /*     5 */              15u,  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  /*     6 */               0u,  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*     7 */               1u,  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*     8 */               4u,  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*     9 */              14u,  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*    10 */               6u,  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    11 */               7u,  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    12 */               9u,  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    13 */              10u,  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    14 */              11u,  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    15 */              17u,  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    16 */               2u,  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
  /*    17 */               3u   /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduGrpVectorStartIdx */
  { /*     0 */                   1u },
  { /*     1 */                   1u },
  { /*     2 */                   1u },
  { /*     3 */                   1u },
  { /*     4 */                   1u },
  { /*     5 */                   1u },
  { /*     6 */                   1u }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                   Description
  RxAccessInfoIndUsed       TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  RxDefPduBufferEndIdx      the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx    the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx           the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx         the start index of the 0:n relation pointing to Com_RxSigInfo
  Type                      Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxAccessInfoIndUsed  RxDefPduBufferEndIdx  RxDefPduBufferStartIdx  RxSigInfoEndIdx  RxSigInfoStartIdx  Type                              Referable Keys */
  { /*     0 */                TRUE,                   8u,                     0u,              1u,                0u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  { /*     1 */                TRUE,                  11u,                     8u,              2u,                1u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  { /*     2 */                TRUE,                  12u,                    11u,              3u,                2u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  { /*     3 */                TRUE,                  14u,                    12u,              6u,                3u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  { /*     4 */                TRUE,                  22u,                    14u,             10u,                6u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  { /*     5 */                TRUE,                  28u,                    22u,             16u,               10u, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  { /*     6 */                TRUE,                  36u,                    28u,             18u,               16u, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[18] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*     0 */             13u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx] */
  { /*     1 */             12u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx] */
  { /*     2 */             16u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx] */
  { /*     3 */              5u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  { /*     4 */              8u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  { /*     5 */             15u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  { /*     6 */              0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*     7 */              1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*     8 */              4u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*     9 */             14u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  { /*    10 */              6u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    11 */              7u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    12 */              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    13 */             10u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    14 */             11u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    15 */             17u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  { /*    16 */              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
  { /*    17 */              3u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u }   /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TimePeriod        Referable Keys */
  { /*     0 */         0u },  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     1 */       100u },  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*     2 */        10u }   /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element     Description
  InitMode    Initial transmission mode selector of the Tx I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitMode        Referable Keys */
  { /*     0 */     TRUE },  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     1 */     TRUE },  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*     2 */     TRUE }   /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TimePeriod        Referable Keys */
  { /*     0 */         0u },  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     1 */       100u },  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*     2 */        10u }   /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduGrpVectorEndIdx                       PduGrpVectorStartIdx                      */
  { /*     0 */ COM_NO_PDUGRPVECTORENDIDXOFTXPDUGRPINFO, COM_NO_PDUGRPVECTORSTARTIDXOFTXPDUGRPINFO },
  { /*     1 */                                      1u,                                        0u },
  { /*     2 */                                      1u,                                        0u }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                   Description
  TxPduInitValueUsed        TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  MetaDataLength            Length of MetaData.
  TxBufferLength            the number of relations pointing to Com_TxBuffer
  TxPduInitValueEndIdx      the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx    the start index of the 0:n relation pointing to Com_TxPduInitValue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInitValueUsed  MetaDataLength  TxBufferLength  TxPduInitValueEndIdx  TxPduInitValueStartIdx        Referable Keys */
  { /*     0 */               TRUE,             0u,             6u,                   6u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     1 */               TRUE,             0u,             3u,                   9u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  { /*     2 */               TRUE,             0u,             2u,                  11u,                     9u }   /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     2 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     3 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     4 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     5 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     6 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  /*     7 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  /*     8 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  /*     9 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
  /*    10 */           0x00u   /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  ByteLength                Byte length of the signal or group signal.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxBufferLength            the number of relations pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[16] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BitLength  BitPosition  ByteLength  StartByteInPduPosition  TxBufferLength  TxBufferStartIdx  TxPduInfoIdx        Referable Keys */
  { /*     0 */        8u,          0u,         1u,                     0u,             1u,               0u,           0u },  /* [/ActiveEcuC/Com/ComConfig/UsrData0_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9b82ce18_Tx, /ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     1 */        8u,          8u,         1u,                     1u,             1u,               1u,           0u },  /* [/ActiveEcuC/Com/ComConfig/UsrData1_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_1b72d907_Tx, /ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     2 */        8u,         16u,         1u,                     2u,             1u,               2u,           0u },  /* [/ActiveEcuC/Com/ComConfig/UsrData2_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4113e667_Tx, /ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     3 */        8u,         24u,         1u,                     3u,             1u,               3u,           0u },  /* [/ActiveEcuC/Com/ComConfig/UsrData3_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_c1e3f178_Tx, /ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     4 */        8u,         32u,         1u,                     4u,             1u,               4u,           0u },  /* [/ActiveEcuC/Com/ComConfig/UsrData4_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_f5d198a7_Tx, /ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     5 */        8u,         40u,         1u,                     5u,             1u,               5u,           0u },  /* [/ActiveEcuC/Com/ComConfig/UsrData5_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_75218fb8_Tx, /ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  { /*     6 */        2u,          8u,         0u,                     1u,             1u,               7u,           1u },  /* [/ActiveEcuC/Com/ComConfig/WLCChrgRate_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_b69382aa_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*     7 */        2u,         18u,         0u,                     2u,             1u,               8u,           1u },  /* [/ActiveEcuC/Com/ComConfig/WLCChrgSts_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_eda08377_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*     8 */        2u,         16u,         0u,                     2u,             1u,               8u,           1u },  /* [/ActiveEcuC/Com/ComConfig/WLCCtrlSts_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_a083bd17_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*     9 */        4u,         20u,         0u,                     2u,             1u,               8u,           1u },  /* [/ActiveEcuC/Com/ComConfig/WLCFailSts_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_882ea33c_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*    10 */        2u,          8u,         0u,                     1u,             1u,              10u,           2u },  /* [/ActiveEcuC/Com/ComConfig/WLCImobSts_oWLC_02_oNIO_ES6_RF_CAN_SR_V3_0_77a54935_Tx, /ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
  { /*    11 */        1u,         10u,         0u,                     1u,             1u,               7u,           1u },  /* [/ActiveEcuC/Com/ComConfig/WLCMuteViaHW_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_990775ce_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*    12 */        8u,          0u,         1u,                     0u,             1u,               6u,           1u },  /* [/ActiveEcuC/Com/ComConfig/WLC_01_CRC_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_705754f3_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*    13 */        4u,         12u,         0u,                     1u,             1u,               7u,           1u },  /* [/ActiveEcuC/Com/ComConfig/WLC_01_MsgCntr_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_c3fc8f8f_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx] */
  { /*    14 */        8u,          0u,         1u,                     0u,             1u,               9u,           2u },  /* [/ActiveEcuC/Com/ComConfig/WLC_02_CRC_oWLC_02_oNIO_ES6_RF_CAN_SR_V3_0_1fdbddc0_Tx, /ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
  { /*    15 */        4u,         12u,         0u,                     1u,             1u,              10u,           2u }   /* [/ActiveEcuC/Com/ComConfig/WLC_02_MsgCntr_oWLC_02_oNIO_ES6_RF_CAN_SR_V3_0_15588e7e_Tx, /ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[7];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_aafda74c_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_d7bf39a5_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_d2878c96_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a943b009_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_0cc82007_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_49a017d3_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4780465a_Rx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Rx_42316af2] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/VehSpd_oBCU_04_oNIO_ES6_RF_CAN_SR_V3_0_91cf0813_Rx, /ActiveEcuC/Com/ComConfig/VehSpd_oBCU_04_oNIO_ES6_RF_CAN_SR_V3_0_91cf0813_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt32
  \brief  Rx Signal and Group Signal Buffer. (UINT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt32Type, COM_VAR_NOINIT) Com_RxSigBufferUInt32[1];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/VehOdometer_oCDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_c4f897da_Rx, /ActiveEcuC/Com/ComConfig/VehOdometer_oCDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_c4f897da_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[16];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/CGW_03_CRC_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_bd877a03_Rx, /ActiveEcuC/Com/ComConfig/CGW_03_CRC_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_bd877a03_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/CGW_03_MsgCntr_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e603ff9_Rx, /ActiveEcuC/Com/ComConfig/CGW_03_MsgCntr_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e603ff9_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_CRC_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_67a87047_Rx, /ActiveEcuC/Com/ComConfig/CGW_WLC_CRC_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_67a87047_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/CGW_WLC_MsgCntr_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_2e39b55e_Rx, /ActiveEcuC/Com/ComConfig/CGW_WLC_MsgCntr_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_2e39b55e_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/ComfEna_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_daac19b6_Rx, /ActiveEcuC/Com/ComConfig/ComfEna_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_daac19b6_Rx_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/ComfEna_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_1a60ba8c_Rx, /ActiveEcuC/Com/ComConfig/ComfEna_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_1a60ba8c_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/Day_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_76626f65_Rx, /ActiveEcuC/Com/ComConfig/Day_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_76626f65_Rx_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/Hr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_f5c3e99f_Rx, /ActiveEcuC/Com/ComConfig/Hr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_f5c3e99f_Rx_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/ImobEnaReq_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a2f30745_Rx, /ActiveEcuC/Com/ComConfig/ImobEnaReq_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a2f30745_Rx_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/Min_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_c05ffcb3_Rx, /ActiveEcuC/Com/ComConfig/Min_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_c05ffcb3_Rx_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/Mth_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a0768b21_Rx, /ActiveEcuC/Com/ComConfig/Mth_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a0768b21_Rx_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/Sec_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_48a1d09a_Rx, /ActiveEcuC/Com/ComConfig/Sec_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_48a1d09a_Rx_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/VehState_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e049202_Rx, /ActiveEcuC/Com/ComConfig/VehState_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e049202_Rx_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/VehState_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_70d412f9_Rx, /ActiveEcuC/Com/ComConfig/VehState_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_70d412f9_Rx_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/WLCChrgFctEnaReq_oCDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_e37de241_Rx, /ActiveEcuC/Com/ComConfig/WLCChrgFctEnaReq_oCDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_e37de241_Rx_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/Yr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_cdf9e710_Rx, /ActiveEcuC/Com/ComConfig/Yr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_cdf9e710_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[11];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx, /ActiveEcuC/Com/ComConfig/UsrData0_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9b82ce18_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx, /ActiveEcuC/Com/ComConfig/UsrData1_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_1b72d907_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx, /ActiveEcuC/Com/ComConfig/UsrData2_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_4113e667_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx, /ActiveEcuC/Com/ComConfig/UsrData3_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_c1e3f178_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx, /ActiveEcuC/Com/ComConfig/UsrData4_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_f5d198a7_Tx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx, /ActiveEcuC/Com/ComConfig/UsrData5_WLC_oNM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_75218fb8_Tx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_CRC_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_705754f3_Tx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLCChrgRate_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_b69382aa_Tx, /ActiveEcuC/Com/ComConfig/WLCMuteViaHW_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_990775ce_Tx, /ActiveEcuC/Com/ComConfig/WLC_01_MsgCntr_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_c3fc8f8f_Tx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLCChrgSts_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_eda08377_Tx, /ActiveEcuC/Com/ComConfig/WLCCtrlSts_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_a083bd17_Tx, /ActiveEcuC/Com/ComConfig/WLCFailSts_oWLC_01_oNIO_ES6_RF_CAN_SR_V3_0_882ea33c_Tx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_02_CRC_oWLC_02_oNIO_ES6_RF_CAN_SR_V3_0_1fdbddc0_Tx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLCImobSts_oWLC_02_oNIO_ES6_RF_CAN_SR_V3_0_77a54935_Tx, /ActiveEcuC/Com/ComConfig/WLC_02_MsgCntr_oWLC_02_oNIO_ES6_RF_CAN_SR_V3_0_15588e7e_Tx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[3];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_9357dd65_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_0b9d3d12_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_3e708b41_Tx, /ActiveEcuC/Com/ComConfig/WLC_oNIO_ES6_RF_CAN_SR_V3_0_Tx_146bcd74] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

