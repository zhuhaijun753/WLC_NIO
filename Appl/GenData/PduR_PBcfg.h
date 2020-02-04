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
 *              File: PduR_PBcfg.h
 *   Generation Time: 2020-02-04 15:38:40
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
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type COMMUNICATION_INTERFACE of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_01_oNIO_ES6_RF_CAN_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 * 
 * [Warning] PDUR07020 - Invalid setting of communication type. 
 * - [Reduced Severity due to User-Defined Parameter] The configured communication type COMMUNICATION_INTERFACE of DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath does not match with the expected routing type UNDEFINED.
 * Erroneous configuration elements:
 * /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/WLC_DEVLP_02_oNIO_ES6_RF_CAN_PduRRoutingPath[0:PduRRoutingPathCommunicationType](value=COMMUNICATION_INTERFACE) (DefRef: /MICROSAR/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRRoutingPathCommunicationType)
 *********************************************************************************************************************/


#if !defined (PDUR_PBCFG_H)
# define PDUR_PBCFG_H
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* \trace SPEC-1238 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPBDataSwitches  PduR Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'PduR_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PDUR_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'PduR_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define PDUR_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'PduR_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* PDUR_PBCFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_PBcfg.h
 *********************************************************************************************************************/

