/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Communication_Read_APP.h
 *           Config:  WLC.dpa
 *      ECU-Project:  WLC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  Application header file for SW-C <Communication_Read_APP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMMUNICATION_READ_APP_H
# define _RTE_COMMUNICATION_READ_APP_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Communication_Read_APP_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_CGW_03_CRC_CGW_03_CRC (0U)
#  define Rte_InitValue_CGW_03_MsgCntr_CGW_03_MsgCntr (0U)
#  define Rte_InitValue_CGW_WLC_CRC_CGW_WLC_CRC (0U)
#  define Rte_InitValue_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr (0U)
#  define Rte_InitValue_ComfEna_ComfEna (0U)
#  define Rte_InitValue_ComfEna_ASIL_ComfEna_ASIL (0U)
#  define Rte_InitValue_Day_Day (0U)
#  define Rte_InitValue_Hr_Hr (0U)
#  define Rte_InitValue_ImobEnaReq_ImobEnaReq (0U)
#  define Rte_InitValue_Min_Min (0U)
#  define Rte_InitValue_Mth_Mth (0U)
#  define Rte_InitValue_Sec_Sec (0U)
#  define Rte_InitValue_UsrData0_WLC_UsrData0_WLC (0U)
#  define Rte_InitValue_UsrData1_WLC_UsrData1_WLC (0U)
#  define Rte_InitValue_UsrData2_WLC_UsrData2_WLC (0U)
#  define Rte_InitValue_UsrData3_WLC_UsrData3_WLC (0U)
#  define Rte_InitValue_UsrData4_WLC_UsrData4_WLC (0U)
#  define Rte_InitValue_UsrData5_WLC_UsrData5_WLC (0U)
#  define Rte_InitValue_VehOdometer_VehOdometer (0U)
#  define Rte_InitValue_VehSpd_VehSpd (0U)
#  define Rte_InitValue_VehState_VehState (0U)
#  define Rte_InitValue_VehState_ASIL_VehState_ASIL (0U)
#  define Rte_InitValue_WLCChrgFctEnaReq_WLCChrgFctEnaReq (0U)
#  define Rte_InitValue_WLCChrgRate_WLCChrgRate (0U)
#  define Rte_InitValue_WLCChrgSts_WLCChrgSts (0U)
#  define Rte_InitValue_WLCCtrlSts_WLCCtrlSts (0U)
#  define Rte_InitValue_WLCFailSts_WLCFailSts (0U)
#  define Rte_InitValue_WLCImobSts_WLCImobSts (0U)
#  define Rte_InitValue_WLCMuteViaHW_WLCMuteViaHW (FALSE)
#  define Rte_InitValue_WLC_01_CRC_WLC_01_CRC (0U)
#  define Rte_InitValue_WLC_01_MsgCntr_WLC_01_MsgCntr (0U)
#  define Rte_InitValue_WLC_02_CRC_WLC_02_CRC (0U)
#  define Rte_InitValue_WLC_02_MsgCntr_WLC_02_MsgCntr (0U)
#  define Rte_InitValue_Yr_Yr (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_UsrData0_WLC_UsrData0_WLC(UsrData0_WLC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_UsrData1_WLC_UsrData1_WLC(UsrData1_WLC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_UsrData2_WLC_UsrData2_WLC(UsrData2_WLC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_UsrData3_WLC_UsrData3_WLC(UsrData3_WLC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_UsrData4_WLC_UsrData4_WLC(UsrData4_WLC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_UsrData5_WLC_UsrData5_WLC(UsrData5_WLC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLCChrgRate_WLCChrgRate(WLCChrgRate data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLCChrgSts_WLCChrgSts(WLCChrgSts data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLCCtrlSts_WLCCtrlSts(WLCCtrlSts data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLCFailSts_WLCFailSts(WLCFailSts data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLCImobSts_WLCImobSts(WLCImobSts data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLCMuteViaHW_WLCMuteViaHW(WLCMuteViaHW data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLC_01_CRC_WLC_01_CRC(WLC_01_CRC data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLC_01_MsgCntr_WLC_01_MsgCntr(WLC_01_MsgCntr data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Communication_Read_APP_WLC_02_MsgCntr_WLC_02_MsgCntr(WLC_02_MsgCntr data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(uint8, RTE_CODE) Rte_Mode_Communication_Read_APP_DcmEcuReset_DcmEcuReset(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_CGW_03_CRC_CGW_03_CRC Rte_Read_Communication_Read_APP_CGW_03_CRC_CGW_03_CRC
#  define Rte_Read_Communication_Read_APP_CGW_03_CRC_CGW_03_CRC(data) (Com_ReceiveSignal(ComConf_ComSignal_CGW_03_CRC_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_bd877a03_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_CGW_03_MsgCntr_CGW_03_MsgCntr Rte_Read_Communication_Read_APP_CGW_03_MsgCntr_CGW_03_MsgCntr
#  define Rte_Read_Communication_Read_APP_CGW_03_MsgCntr_CGW_03_MsgCntr(data) (Com_ReceiveSignal(ComConf_ComSignal_CGW_03_MsgCntr_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e603ff9_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_CGW_WLC_CRC_CGW_WLC_CRC Rte_Read_Communication_Read_APP_CGW_WLC_CRC_CGW_WLC_CRC
#  define Rte_Read_Communication_Read_APP_CGW_WLC_CRC_CGW_WLC_CRC(data) (Com_ReceiveSignal(ComConf_ComSignal_CGW_WLC_CRC_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_67a87047_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr Rte_Read_Communication_Read_APP_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr
#  define Rte_Read_Communication_Read_APP_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr(data) (Com_ReceiveSignal(ComConf_ComSignal_CGW_WLC_MsgCntr_oCGW_WLC_oNIO_ES6_RF_CAN_SR_V3_0_2e39b55e_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_ComfEna_ComfEna Rte_Read_Communication_Read_APP_ComfEna_ComfEna
#  define Rte_Read_Communication_Read_APP_ComfEna_ComfEna(data) (Com_ReceiveSignal(ComConf_ComSignal_ComfEna_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_1a60ba8c_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_ComfEna_ASIL_ComfEna_ASIL Rte_Read_Communication_Read_APP_ComfEna_ASIL_ComfEna_ASIL
#  define Rte_Read_Communication_Read_APP_ComfEna_ASIL_ComfEna_ASIL(data) (Com_ReceiveSignal(ComConf_ComSignal_ComfEna_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_daac19b6_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Day_Day Rte_Read_Communication_Read_APP_Day_Day
#  define Rte_Read_Communication_Read_APP_Day_Day(data) (Com_ReceiveSignal(ComConf_ComSignal_Day_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_76626f65_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Hr_Hr Rte_Read_Communication_Read_APP_Hr_Hr
#  define Rte_Read_Communication_Read_APP_Hr_Hr(data) (Com_ReceiveSignal(ComConf_ComSignal_Hr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_f5c3e99f_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_ImobEnaReq_ImobEnaReq Rte_Read_Communication_Read_APP_ImobEnaReq_ImobEnaReq
#  define Rte_Read_Communication_Read_APP_ImobEnaReq_ImobEnaReq(data) (Com_ReceiveSignal(ComConf_ComSignal_ImobEnaReq_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_a2f30745_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Min_Min Rte_Read_Communication_Read_APP_Min_Min
#  define Rte_Read_Communication_Read_APP_Min_Min(data) (Com_ReceiveSignal(ComConf_ComSignal_Min_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_c05ffcb3_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Mth_Mth Rte_Read_Communication_Read_APP_Mth_Mth
#  define Rte_Read_Communication_Read_APP_Mth_Mth(data) (Com_ReceiveSignal(ComConf_ComSignal_Mth_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_a0768b21_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Sec_Sec Rte_Read_Communication_Read_APP_Sec_Sec
#  define Rte_Read_Communication_Read_APP_Sec_Sec(data) (Com_ReceiveSignal(ComConf_ComSignal_Sec_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_48a1d09a_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehOdometer_VehOdometer Rte_Read_Communication_Read_APP_VehOdometer_VehOdometer
#  define Rte_Read_Communication_Read_APP_VehOdometer_VehOdometer(data) (Com_ReceiveSignal(ComConf_ComSignal_VehOdometer_oCDC_IC_01_oNIO_ES6_RF_CAN_SR_V3_0_c4f897da_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehSpd_VehSpd Rte_Read_Communication_Read_APP_VehSpd_VehSpd
#  define Rte_Read_Communication_Read_APP_VehSpd_VehSpd(data) (Com_ReceiveSignal(ComConf_ComSignal_VehSpd_oBCU_04_oNIO_ES6_RF_CAN_SR_V3_0_91cf0813_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehState_VehState Rte_Read_Communication_Read_APP_VehState_VehState
#  define Rte_Read_Communication_Read_APP_VehState_VehState(data) (Com_ReceiveSignal(ComConf_ComSignal_VehState_oCGW_02_oNIO_ES6_RF_CAN_SR_V3_0_70d412f9_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_VehState_ASIL_VehState_ASIL Rte_Read_Communication_Read_APP_VehState_ASIL_VehState_ASIL
#  define Rte_Read_Communication_Read_APP_VehState_ASIL_VehState_ASIL(data) (Com_ReceiveSignal(ComConf_ComSignal_VehState_ASIL_oCGW_03_oNIO_ES6_RF_CAN_SR_V3_0_3e049202_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_WLCChrgFctEnaReq_WLCChrgFctEnaReq Rte_Read_Communication_Read_APP_WLCChrgFctEnaReq_WLCChrgFctEnaReq
#  define Rte_Read_Communication_Read_APP_WLCChrgFctEnaReq_WLCChrgFctEnaReq(data) (Com_ReceiveSignal(ComConf_ComSignal_WLCChrgFctEnaReq_oCDC_WLC_oNIO_ES6_RF_CAN_SR_V3_0_e37de241_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_Yr_Yr Rte_Read_Communication_Read_APP_Yr_Yr
#  define Rte_Read_Communication_Read_APP_Yr_Yr(data) (Com_ReceiveSignal(ComConf_ComSignal_Yr_oCGW_TCU_01_oNIO_ES6_RF_CAN_SR_V3_0_cdf9e710_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_UsrData0_WLC_UsrData0_WLC Rte_Write_Communication_Read_APP_UsrData0_WLC_UsrData0_WLC
#  define Rte_Write_UsrData1_WLC_UsrData1_WLC Rte_Write_Communication_Read_APP_UsrData1_WLC_UsrData1_WLC
#  define Rte_Write_UsrData2_WLC_UsrData2_WLC Rte_Write_Communication_Read_APP_UsrData2_WLC_UsrData2_WLC
#  define Rte_Write_UsrData3_WLC_UsrData3_WLC Rte_Write_Communication_Read_APP_UsrData3_WLC_UsrData3_WLC
#  define Rte_Write_UsrData4_WLC_UsrData4_WLC Rte_Write_Communication_Read_APP_UsrData4_WLC_UsrData4_WLC
#  define Rte_Write_UsrData5_WLC_UsrData5_WLC Rte_Write_Communication_Read_APP_UsrData5_WLC_UsrData5_WLC
#  define Rte_Write_WLCChrgRate_WLCChrgRate Rte_Write_Communication_Read_APP_WLCChrgRate_WLCChrgRate
#  define Rte_Write_WLCChrgSts_WLCChrgSts Rte_Write_Communication_Read_APP_WLCChrgSts_WLCChrgSts
#  define Rte_Write_WLCCtrlSts_WLCCtrlSts Rte_Write_Communication_Read_APP_WLCCtrlSts_WLCCtrlSts
#  define Rte_Write_WLCFailSts_WLCFailSts Rte_Write_Communication_Read_APP_WLCFailSts_WLCFailSts
#  define Rte_Write_WLCImobSts_WLCImobSts Rte_Write_Communication_Read_APP_WLCImobSts_WLCImobSts
#  define Rte_Write_WLCMuteViaHW_WLCMuteViaHW Rte_Write_Communication_Read_APP_WLCMuteViaHW_WLCMuteViaHW
#  define Rte_Write_WLC_01_CRC_WLC_01_CRC Rte_Write_Communication_Read_APP_WLC_01_CRC_WLC_01_CRC
#  define Rte_Write_WLC_01_MsgCntr_WLC_01_MsgCntr Rte_Write_Communication_Read_APP_WLC_01_MsgCntr_WLC_01_MsgCntr
#  define Rte_Write_WLC_02_CRC_WLC_02_CRC Rte_Write_Communication_Read_APP_WLC_02_CRC_WLC_02_CRC
#  define Rte_Write_Communication_Read_APP_WLC_02_CRC_WLC_02_CRC(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_WLC_02_MsgCntr_WLC_02_MsgCntr Rte_Write_Communication_Read_APP_WLC_02_MsgCntr_WLC_02_MsgCntr


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_DcmEcuReset_DcmEcuReset Rte_Mode_Communication_Read_APP_DcmEcuReset_DcmEcuReset


# endif /* !defined(RTE_CORE) */


# define Communication_Read_APP_START_SEC_CODE
# include "Communication_Read_APP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_ComReadandWrite_Runnable ComReadandWrite_Runnable
# endif

FUNC(void, Communication_Read_APP_CODE) ComReadandWrite_Runnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Communication_Read_APP_STOP_SEC_CODE
# include "Communication_Read_APP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_COMMUNICATION_READ_APP_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
