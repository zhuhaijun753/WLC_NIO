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
 *            Module: PduR
 *           Program: VAG AR4 (MSR_Vag_SLP5)
 *          Customer: SAIC Volkswagen Automotive Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016393AFP-C
 *    License Scope : The usage is restricted to CBD1900162_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_CanNm.h
 *   Generation Time: 2020-02-04 12:12:48
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
 * WARNING: This code has been generated with reduced-severity errors. 
 * The created output files contain errors that have been ignored. Usage of the created files can lead to unpredictable behavior of the embedded code.
 * Usage of the created files happens at own risk!
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_CGW_WLC_PduRRoutingPath cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be identical. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/PduR/CDDTp[0:PduRCommunicationInterface](value=false), /ActiveEcuC/CanIf/CanIfInitCfg/IMOB_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_451c91a3_Rx[0:CanIfRxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/IMOB_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_da4d0319_Rx)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_CGW_WLC_PduRRoutingPath/PduRDestPdu_1[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/IMOB_CGW_WLC_oNIO_ES6_RF_CDDasCanTp) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_CGW_WLC_PduRRoutingPath/PduRSrcPdu_1[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/IMOB_CGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_da4d0319_Rx) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_CGW_WLC_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_WLC_CGW_oNIO_ES6_RF_CAN cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be identical. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/PduR/CDDTp[0:PduRCommunicationInterface](value=false), /ActiveEcuC/CanIf/CanIfInitCfg/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_4f44c7a2_Tx[0:CanIfTxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_efb0805f_Tx)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_WLC_CGW_oNIO_ES6_RF_CAN/PduRDestPdu_2[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_SR_V3_0_efb0805f_Tx) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_WLC_CGW_oNIO_ES6_RF_CAN/PduRSrcPdu_2[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/IMOB_WLC_CGW_oNIO_ES6_RF_CAN_CDDAsCanTp) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_WLC_CGW_oNIO_ES6_RF_CAN[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be identical. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/PduR/CDDTp[0:PduRCommunicationInterface](value=false), /ActiveEcuC/CanIf/CanIfInitCfg/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_163e9779_Tx[0:CanIfTxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_0423feed_Tx)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath/PduRDestPdu_4[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/WLC_DEVLP_01_oNIO_ES6_RF_CAN_SR_V3_0_0423feed_Tx) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath/PduRSrcPdu_4[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/WLC_DEVLP_01_oNIO_ES6_RF_CAN_CDDasCanTp) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] Communication type of PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath cannot be determined. The communication types of the PduRSrcPdu and PduRDestPdu must be identical. Routing paths between different communication types are not possible.
 * 
 * Multiple communication types found:
 * TRANSPORT_PROTOCOL, COMMUNICATION_INTERFACE
 * 
 * Parameters influencing the communication type:
 * /ActiveEcuC/PduR/CDDTp[0:PduRCommunicationInterface](value=false), /ActiveEcuC/CanIf/CanIfInitCfg/WLC_DEVLP_02_oNIO_ES6_RF_CAN_SR_V3_0_52a3faed_Rx[0:CanIfRxPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/WLC_DEVLP_02_oNIO_ES6_RF_CAN_SR_V3_0_2ddc8841_Rx)
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath/PduRDestPdu_5[0:PduRDestPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/WLC_DEVLP_02_oNIO_ES6_RF_CAN_CDDasCanTp) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRDestPdu/PduRDestPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath/PduRSrcPdu_5[0:PduRSrcPduRef](value=/ActiveEcuC/EcuC/EcucPduCollection/WLC_DEVLP_02_oNIO_ES6_RF_CAN_SR_V3_0_2ddc8841_Rx) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu/PduRSrcPduRef)
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type COMMUNICATION_INTERFACE of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_CGW_WLC_PduRRoutingPath does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_CGW_WLC_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type COMMUNICATION_INTERFACE of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_WLC_CGW_oNIO_ES6_RF_CAN does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IMOB_WLC_CGW_oNIO_ES6_RF_CAN[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type COMMUNICATION_INTERFACE of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type COMMUNICATION_INTERFACE of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 *********************************************************************************************************************/
#if !defined (PDUR_CANNM_H)
# define PDUR_CANNM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Cfg.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* \trace SPEC-629 */

#define PDUR_START_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * PduR_CanNmRxIndication
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the CanNm to indicate the complete reception of a CanNm I-PDU.\n
 *           The PDU Router evaluates the CanNm I-PDU handle and identifies the destination(s) of the PDU.\n
 *           The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 * \param    RxPduId           ID of the received CanNm I-PDU
 * \param    info        Payload information of the received I-PDU (pointer to data and data length)
 * \return   none
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_CanNmRxIndication calls for the same CanNmRxPduId.
 * \trace    DSGN-PduR_IF_Forwarding
 * \trace    SPEC-666, SPEC-674, SPEC-1096, SPEC-2020085
 * \note     The function is called by CanNm.
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanNmRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);

/* PduR_CanNmTxConfirmation API disabled due to disabled TxConfirmation in PduRBswModule settings. */

/**********************************************************************************************************************
 * PduR_CanNmTriggerTransmit
 *********************************************************************************************************************/
/*!
 * \brief    The function is called by the CanNm to request the CanNm TX I-PDU before transmission.\n
 *           The PDU Router evaluates the CanNm I-PDU handle and identifies the destination(s) of the PDU.
 *           The call is routed to an upper IF module using the appropriate I-PDU handle of the destination layer.
 * \param          TxPduId       ID of the CanNm I-PDU that will be transmitted
 * \param[in,out]  info          Contains a pointer to a buffer (SduDataPtr) to where the SDU
 *                               data shall be copied, and the available buffer size in SduLengh.
 *                               On return, the service will indicate the length of the copied SDU
 *                               data in SduLength.
 * \return         E_OK          SDU has been copied and SduLength indicates the number of copied bytes.
 * \return         E_NOT_OK      No data has been copied, because
 *                               PduR is not initialized
 *                               or TxPduId is not valid
 *                               or PduInfoPtr is NULL_PTR
 *                               or SduDataPtr is NULL_PTR
 *                               or SduLength is too small.
 * \pre      PduR_Init() is executed successfully.
 * \context  This function can be called on interrupt and task level and has not to be interrupted by other\n
 *           PduR_CanNmTriggerTransmit calls for the same CanNmTxPduId.
 * \trace    DSGN-PduR_IF_Forwarding
 * \trace    SPEC-666, SPEC-1828
 * \note     The function is called by CanNm.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_CanNmTriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info);









#define PDUR_STOP_SEC_CODE
# include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif  /* PDUR_CANNM_H */


/**********************************************************************************************************************
 * GLOBAL MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/*  module specific MISRA deviations:
    MD_PduR_3451:   MISRA rule: 8.8
    Reason:         The global identifier has been declared in more than one file. the function declaration has to be in
                    the PduR_<Module>.h. Affected APIs are CancelReceive, CancelTransmit and ChangeParameter.
    Risk:           no risk.
    Prevention:     To avoid a duplicate declaration uns the BSW-Module "use-Tag" flag.
*/

/**********************************************************************************************************************
 * END OF FILE: PduR_CanNm.h
 *********************************************************************************************************************/

