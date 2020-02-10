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
 *            Module: CanIf
 *           Program: VAG AR4 (MSR_Vag_SLP5)
 *          Customer: SAIC Volkswagen Automotive Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016393AFP-C
 *    License Scope : The usage is restricted to CBD1900162_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2020-02-08 13:14:15
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

#define CANIF_LCFG_SOURCE

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanNm Header Files  */ 
#include "CanNm_Cfg.h"
#include "CanNm_Cbk.h"
 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  CDD Header Files  */ 
#include "Cdd_Cbk.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/





#define CANIF_STOP_SEC_APPL_CODE

#include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_MemMap */

/**********************************************************************************************************************
  ComStackLib
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
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MappedTxBuffersConfigEndIdx                                                                                       MappedTxBuffersConfigStartIdx                                                                                             Referable Keys */
  { /*     0 */                          1u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,                            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_DataChecksumRxErrFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_DataChecksumRxErrFctType, CANIF_CONST) CanIf_DataChecksumRxErrFctPtr = NULL_PTR;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CtrlStatesIdx                                                                                       PduIdFirst                           PduIdLast                           TxBufferCfgIdx                                                                              TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,         0u  /* Unused, TxPduId 0 */,        0u  /* Unused, TxPduId 6 */,                                     0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01 */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx] */
  { /*     1 */            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,         1u  /* RxPduId */          ,       12u  /* RxPduId  */         , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_91fc07e0_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MailBoxConfigIdx                                                                                  Referable Keys */
  { /*     0 */               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                                 Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanNm_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanNm_RxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }    , CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ },  /* [CanTp_RxIndication] */
  { /*     3 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 0313 */ /* MD_CanIf_Rule11.1 */ }   /* [PduR_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  IsDataChecksumRxPdu       TRUE: Data checksum Rx-PDU, FALSE: None Data checksum Rx-PDU
  Dlc                       Data length code.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[13] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxPduCanId                                                                                RxPduMask                                                                UpperPduId                                                   IsDataChecksumRxPdu  Dlc  RxIndicationFctListIdx                                      Comment                                                                                 Referable Keys */
  { /*     0 */    0x0500u  /* Lower CanId of range: WLC_d9d2b008_Rx, 2.0- or FD-PDU */                 ,   0x657Fu  /* Upper CanId of range: WLC_d9d2b008_Rx */                 , CanNmConf_CanNmRxPdu_NIO_ES6_RF_CAN_SR_V3_0_CAN_40361c2d_Rx, FALSE              ,  8u,                     1u  /* CanNm_RxIndication */     },  /* [PDU: WLC_d9d2b008_Rx, Lower CanId of range: 0x500]                         */  /* [CanIfConf_CanIfRxPduCfg_WLC_d9d2b008_Rx] */
  { /*     1 */    0x0638u  /* DIAG_REQ_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_dcbbcb37_Rx, 2.0- or FD-PDU */   ,   0x07FFu  /* DIAG_REQ_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_dcbbcb37_Rx */   , CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_b9a7b042             , FALSE              ,  8u,                     2u  /* CanTp_RxIndication */     },  /* [PDU: DIAG_REQ_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_dcbbcb37_Rx, CanId: 0x638]    */  /* [CanIfConf_CanIfRxPduCfg_DIAG_REQ_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_dcbbcb37_Rx] */
  { /*     2 */    0x0601u  /* DIAG_REQ_AllECU_Tp_oNIO_ES6_RF_CAN_SR_V3_0_23f8e329_Rx, 2.0- or FD-PDU */,   0x07FFu  /* DIAG_REQ_AllECU_Tp_oNIO_ES6_RF_CAN_SR_V3_0_23f8e329_Rx */, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_210b33f5                 , FALSE              ,  8u,                     2u  /* CanTp_RxIndication */     },  /* [PDU: DIAG_REQ_AllECU_Tp_oNIO_ES6_RF_CAN_SR_V3_0_23f8e329_Rx, CanId: 0x601] */  /* [CanIfConf_CanIfRxPduCfg_DIAG_REQ_AllECU_Tp_oNIO_ES6_RF_CAN_SR_V3_0_23f8e329_Rx] */
  { /*     3 */    0x04BCu  /* WLC_DEVLP_02_oNIO_ES6_RF_CAN_SR_V3_0_52a3faed_Rx, 2.0- or FD-PDU */      ,   0x07FFu  /* WLC_DEVLP_02_oNIO_ES6_RF_CAN_SR_V3_0_52a3faed_Rx */      , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_2                        , FALSE              ,  8u,                     2u  /* CanTp_RxIndication */     },  /* [PDU: WLC_DEVLP_02_oNIO_ES6_RF_CAN_SR_V3_0_52a3faed_Rx, CanId: 0x4bc]       */  /* [CanIfConf_CanIfRxPduCfg_WLC_DEVLP_02_oNIO_ES6_RF_CAN_SR_V3_0_52a3faed_Rx] */
  { /*     4 */    0x04AFu  /* CDC_WLC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_0c4c3dd1_Rx, 2.0- or FD-PDU */       ,   0x07FFu  /* CDC_WLC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_0c4c3dd1_Rx */       , CanTpConf_CanTpRxNPdu_CanTpRxNPdu                          , FALSE              ,  8u,                     2u  /* CanTp_RxIndication */     },  /* [PDU: CDC_WLC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_0c4c3dd1_Rx, CanId: 0x4af]        */  /* [CanIfConf_CanIfRxPduCfg_CDC_WLC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_0c4c3dd1_Rx] */
  { /*     5 */    0x03BEu  /* CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_411e58d5_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_411e58d5_Rx */           , PduRConf_PduRSrcPdu_PduRSrcPdu_8b01a8ad                    , TRUE               ,  8u,                     3u  /* PduR_CanIfRxIndication */ },  /* [PDU: CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_411e58d5_Rx, CanId: 0x3be]            */  /* [CanIfConf_CanIfRxPduCfg_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_411e58d5_Rx] */
  { /*     6 */    0x03B2u  /* CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a587df53_Rx, 2.0- or FD-PDU */        ,   0x07FFu  /* CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a587df53_Rx */        , PduRConf_PduRSrcPdu_PduRSrcPdu_ece35bb2                    , FALSE              ,  6u,                     3u  /* PduR_CanIfRxIndication */ },  /* [PDU: CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a587df53_Rx, CanId: 0x3b2]         */  /* [CanIfConf_CanIfRxPduCfg_CGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a587df53_Rx] */
  { /*     7 */    0x03AAu  /* CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_6ce0b6d1_Rx, 2.0- or FD-PDU */         ,   0x07FFu  /* CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_6ce0b6d1_Rx */         , PduRConf_PduRSrcPdu_PduRSrcPdu_3feaaad3                    , FALSE              ,  3u,                     3u  /* PduR_CanIfRxIndication */ },  /* [PDU: CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_6ce0b6d1_Rx, CanId: 0x3aa]          */  /* [CanIfConf_CanIfRxPduCfg_CDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_6ce0b6d1_Rx] */
  { /*     8 */    0x02C3u  /* CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_e6e0b02d_Rx, 2.0- or FD-PDU */            ,   0x07FFu  /* CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_e6e0b02d_Rx */            , PduRConf_PduRSrcPdu_PduRSrcPdu_f115c878                    , FALSE              ,  2u,                     3u  /* PduR_CanIfRxIndication */ },  /* [PDU: CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_e6e0b02d_Rx, CanId: 0x2c3]             */  /* [CanIfConf_CanIfRxPduCfg_CGW_02_oNIO_ES6_RF_CAN_SR_V3_0_e6e0b02d_Rx] */
  { /*     9 */    0x02BAu  /* CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_96cf9e96_Rx, 2.0- or FD-PDU */           ,   0x07FFu  /* CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_96cf9e96_Rx */           , PduRConf_PduRSrcPdu_PduRSrcPdu_8b049bb0                    , FALSE              ,  1u,                     3u  /* PduR_CanIfRxIndication */ },  /* [PDU: CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_96cf9e96_Rx, CanId: 0x2ba]            */  /* [CanIfConf_CanIfRxPduCfg_CDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_96cf9e96_Rx] */
  { /*    10 */    0x010Cu  /* CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3fecd32f_Rx, 2.0- or FD-PDU */            ,   0x07FFu  /* CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3fecd32f_Rx */            , PduRConf_PduRSrcPdu_PduRSrcPdu_8f6b5f25                    , TRUE               ,  8u,                     3u  /* PduR_CanIfRxIndication */ },  /* [PDU: CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3fecd32f_Rx, CanId: 0x10c]             */  /* [CanIfConf_CanIfRxPduCfg_CGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3fecd32f_Rx] */
  { /*    11 */    0x005Bu  /* BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_7f355556_Rx, 2.0- or FD-PDU */            ,   0x07FFu  /* BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_7f355556_Rx */            , PduRConf_PduRSrcPdu_PduRSrcPdu_3ec2fcac                    , TRUE               ,  8u,                     3u  /* PduR_CanIfRxIndication */ },  /* [PDU: BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_7f355556_Rx, CanId: 0x5b]              */  /* [CanIfConf_CanIfRxPduCfg_BCU_04_oNIO_ES6_RF_CAN_SR_V3_0_7f355556_Rx] */
  { /*    12 */    0x0027u  /* IMOB_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_451c91a3_Rx, 2.0- or FD-PDU */      ,   0x07FFu  /* IMOB_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_451c91a3_Rx */      , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_1                        , FALSE              ,  8u,                     2u  /* CanTp_RxIndication */     }   /* [PDU: IMOB_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_451c91a3_Rx, CanId: 0x27]        */  /* [CanIfConf_CanIfRxPduCfg_IMOB_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_451c91a3_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxBufferPrioByCanIdBaseIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                            Referable Keys */
  { /*     0 */                         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01 */,                                             7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01 */,                                             7u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01 */,                                               0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01 */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduConfigIdx                                                                                                   Referable Keys */
  { /*     0 */             0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RESP_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_00ce42fa_Tx */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
  { /*     1 */             1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_76bbfea6_Tx */           },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
  { /*     2 */             2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx */     },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
  { /*     3 */             3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_CDC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_f65364a2_Tx */      },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
  { /*     4 */             4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_1dd10da5_Tx */           },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
  { /*     5 */             5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_adb4aee2_Tx */           },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
  { /*     6 */             6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx */     }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[3] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanNm_TxConfirmation                  ,  /* [CanNm_TxConfirmation] */
  /*     2 */ CanTp_TxConfirmation                     /* [CanTp_TxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  IsDataChecksumTxPdu         TRUE: Data checksum Tx-PDU, FALSE: None Data checksum Tx-PDU
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  Dlc                         Data length code.
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CanId    UpperLayerTxPduId                                                IsDataChecksumTxPdu  CtrlStatesIdx                                                                                       Dlc  MailBoxConfigIdx                                                                            TxConfirmationFctListIdx                                    Comment                                                                 Referable Keys */
  { /*     0 */ 0x06B8u, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_b9a7b042                     , FALSE              ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,  8u,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */,                       2u  /* CanTp_TxConfirmation */ },  /* [PDU: DIAG_RESP_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_00ce42fa_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RESP_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_00ce42fa_Tx] */
  { /*     1 */ 0x0538u, CanNmConf_CanNmTxPdu_NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_1915286e_Tx, FALSE              ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,  8u,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */,                       1u  /* CanNm_TxConfirmation */ },  /* [PDU: NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_76bbfea6_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_76bbfea6_Tx] */
  { /*     2 */ 0x04BBu, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_002                      , FALSE              ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,  8u,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */,                       2u  /* CanTp_TxConfirmation */ },  /* [PDU: WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx] */
  { /*     3 */ 0x04AEu, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu                          , FALSE              ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,  8u,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */,                       2u  /* CanTp_TxConfirmation */ },  /* [PDU: WLC_CDC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_f65364a2_Tx]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_CDC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_f65364a2_Tx] */
  { /*     4 */ 0x03E3u, PduRConf_PduRDestPdu_WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_49299080_Tx, TRUE               ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,  3u,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */,                       0u  /* NULL_PTR */             },  /* [PDU: WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_1dd10da5_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_1dd10da5_Tx] */
  { /*     5 */ 0x0340u, PduRConf_PduRDestPdu_WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_60d6e62c_Tx, TRUE               ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,  2u,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */,                       0u  /* NULL_PTR */             },  /* [PDU: WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_adb4aee2_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_adb4aee2_Tx] */
  { /*     6 */ 0x0028u, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_001                      , FALSE              ,            0u  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593 */,  8u,               0u  /* /ActiveEcuC/Can/CanConfigSet/CN_NIO_ES6_RF_CAN_SR_V3_0_d2612a1f_Tx */,                       2u  /* CanTp_TxConfirmation */ }   /* [PDU: IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxQueueIdx                                                                                                   Comment                                                                                           Referable Keys */
  { /*     0 */         0u  /* /ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RESP_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_00ce42fa_Tx */ },  /* [DIAG_RESP_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_00ce42fa_Tx, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RESP_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_00ce42fa_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
  { /*     1 */         1u  /* /ActiveEcuC/CanIf/CanIfInitCfg/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_76bbfea6_Tx */           },  /* [NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_76bbfea6_Tx, BasicCAN TxPdu with Tx-buffer]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_76bbfea6_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
  { /*     2 */         2u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx */     },  /* [WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx, BasicCAN TxPdu with Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
  { /*     3 */         3u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_CDC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_f65364a2_Tx */      },  /* [WLC_CDC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_f65364a2_Tx, BasicCAN TxPdu with Tx-buffer]      */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_CDC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_f65364a2_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
  { /*     4 */         4u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_1dd10da5_Tx */           },  /* [WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_1dd10da5_Tx, BasicCAN TxPdu with Tx-buffer]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_1dd10da5_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
  { /*     5 */         5u  /* /ActiveEcuC/CanIf/CanIfInitCfg/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_adb4aee2_Tx */           },  /* [WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_adb4aee2_Tx, BasicCAN TxPdu with Tx-buffer]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_adb4aee2_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
  { /*     6 */         6u  /* /ActiveEcuC/CanIf/CanIfInitCfg/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx */     }   /* [IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx, BasicCAN TxPdu with Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_NIO_ES6_RF_CAN_SR_V3_0_a63ca593] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_3145ee01] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/DIAG_RESP_WLC_Tp_oNIO_ES6_RF_CAN_SR_V3_0_00ce42fa_Tx] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/NM_WLC_oNIO_ES6_RF_CAN_SR_V3_0_76bbfea6_Tx] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_CDC_NFC_oNIO_ES6_RF_CAN_SR_V3_0_f65364a2_Tx] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_01_oNIO_ES6_RF_CAN_SR_V3_0_1dd10da5_Tx] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/WLC_02_oNIO_ES6_RF_CAN_SR_V3_0_adb4aee2_Tx] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



