/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference..
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use..
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Communication_Read_APP.c
 *           Config:  WLC.dpa
 *        SW-C Type:  Communication_Read_APP
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  C-Code implementation template for SW-C <Communication_Read_APP>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Communication_Read_APP.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_Communication_Read_APP.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Communication_Read_APP_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * CGW_03_CRC: Integer in interval [0...255]
 * CGW_03_MsgCntr: Integer in interval [0...15]
 * CGW_WLC_CRC: Integer in interval [0...255]
 * CGW_WLC_MsgCntr: Integer in interval [0...15]
 * Day: Integer in interval [0...31]
 * Hr: Integer in interval [0...23]
 * Min: Integer in interval [0...59]
 * Sec: Integer in interval [0...59]
 * UsrData0_WLC: Integer in interval [0...255]
 * UsrData1_WLC: Integer in interval [0...255]
 * UsrData2_WLC: Integer in interval [0...255]
 * UsrData3_WLC: Integer in interval [0...255]
 * UsrData4_WLC: Integer in interval [0...255]
 * UsrData5_WLC: Integer in interval [0...255]
 * VehOdometer: Integer in interval [0...16777214]
 * VehSpd: Integer in interval [0...8191]
 * WLCMuteViaHW: Boolean
 * WLC_01_CRC: Integer in interval [0...255]
 * WLC_01_MsgCntr: Integer in interval [0...15]
 * WLC_02_CRC: Integer in interval [0...255]
 * WLC_02_MsgCntr: Integer in interval [0...15]
 * Yr: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ComfEna: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Comfort_not_enabled (0U)
 *   Cx1_Comfort_enabled (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ComfEna_ASIL: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Comfort_not_enabled (0U)
 *   Cx1_Comfort_enabled (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * ImobEnaReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Disable (0U)
 *   Cx1_Enable_AID1 (1U)
 *   Cx2_Enable_AID2 (2U)
 *   Cx3_Invalid (3U)
 * Mth: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Unknown (0U)
 *   Cx1_January (1U)
 *   Cx2_February (2U)
 *   Cx3_March (3U)
 *   Cx4_April (4U)
 *   Cx5_May (5U)
 *   Cx6_June (6U)
 *   Cx7_July (7U)
 *   Cx8_August (8U)
 *   Cx9_September (9U)
 *   CxA_October (10U)
 *   CxB_November (11U)
 *   CxC_December (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid (15U)
 * VehState: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Parked_vehicle_Off_ (0U)
 *   Cx1_Driver_present_On_ (1U)
 *   Cx2_Driving (2U)
 *   Cx3_Software_update (3U)
 *   Cx4_Reserved (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid (15U)
 * VehState_ASIL: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Parked_vehicle_Off_ (0U)
 *   Cx1_Driver_present_On_ (1U)
 *   Cx2_Driving (2U)
 *   Cx3_Software_update (3U)
 *   Cx4_Reserved (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid (15U)
 * WLCChrgFctEnaReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Disable_WLC_charging_function (0U)
 *   Cx1_Enable_WLC_charging_function (1U)
 *   Cx2_No_operation (2U)
 *   Cx3_Invalid (3U)
 * WLCChrgRate: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_started_ (0U)
 *   Cx1_Power_Requested_ (1U)
 *   Cx2_Power_Reduced_ (2U)
 *   Cx3_Reserved (3U)
 * WLCChrgSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_WLC_stopped (0U)
 *   Cx1_WLC_on_going (1U)
 *   Cx2_Charge_complete (2U)
 *   Cx3_Invalid (3U)
 * WLCCtrlSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_WLC_enabled (0U)
 *   Cx1_WLC_disabled (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 * WLCFailSts: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_No_failure (0U)
 *   Cx1_Over_temperature (1U)
 *   Cx2_Under_voltage (2U)
 *   Cx3_Over_voltage (3U)
 *   Cx4_Internal_error (4U)
 *   Cx5_Foreign_object_existing (5U)
 *   Cx6_Unknown_error (6U)
 *   Cx7_Smartphone_no_response_or_error (7U)
 *   Cx8_Conductive_Device_Detected (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid (15U)
 * WLCImobSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Disable (0U)
 *   Cx1_Enable (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Invalid (3U)
 *
 *********************************************************************************************************************/


#define Communication_Read_APP_START_SEC_CODE
#include "Communication_Read_APP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComReadandWrite_Runnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_CGW_03_CRC_CGW_03_CRC(CGW_03_CRC *data)
 *   Std_ReturnType Rte_Read_CGW_03_MsgCntr_CGW_03_MsgCntr(CGW_03_MsgCntr *data)
 *   Std_ReturnType Rte_Read_CGW_WLC_CRC_CGW_WLC_CRC(CGW_WLC_CRC *data)
 *   Std_ReturnType Rte_Read_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr(CGW_WLC_MsgCntr *data)
 *   Std_ReturnType Rte_Read_ComfEna_ComfEna(ComfEna *data)
 *   Std_ReturnType Rte_Read_ComfEna_ASIL_ComfEna_ASIL(ComfEna_ASIL *data)
 *   Std_ReturnType Rte_Read_Day_Day(Day *data)
 *   Std_ReturnType Rte_Read_Hr_Hr(Hr *data)
 *   Std_ReturnType Rte_Read_ImobEnaReq_ImobEnaReq(ImobEnaReq *data)
 *   Std_ReturnType Rte_Read_Min_Min(Min *data)
 *   Std_ReturnType Rte_Read_Mth_Mth(Mth *data)
 *   Std_ReturnType Rte_Read_Sec_Sec(Sec *data)
 *   Std_ReturnType Rte_Read_VehOdometer_VehOdometer(VehOdometer *data)
 *   Std_ReturnType Rte_Read_VehSpd_VehSpd(VehSpd *data)
 *   Std_ReturnType Rte_Read_VehState_VehState(VehState *data)
 *   Std_ReturnType Rte_Read_VehState_ASIL_VehState_ASIL(VehState_ASIL *data)
 *   Std_ReturnType Rte_Read_WLCChrgFctEnaReq_WLCChrgFctEnaReq(WLCChrgFctEnaReq *data)
 *   Std_ReturnType Rte_Read_Yr_Yr(Yr *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_UsrData0_WLC_UsrData0_WLC(UsrData0_WLC data)
 *   Std_ReturnType Rte_Write_UsrData1_WLC_UsrData1_WLC(UsrData1_WLC data)
 *   Std_ReturnType Rte_Write_UsrData2_WLC_UsrData2_WLC(UsrData2_WLC data)
 *   Std_ReturnType Rte_Write_UsrData3_WLC_UsrData3_WLC(UsrData3_WLC data)
 *   Std_ReturnType Rte_Write_UsrData4_WLC_UsrData4_WLC(UsrData4_WLC data)
 *   Std_ReturnType Rte_Write_UsrData5_WLC_UsrData5_WLC(UsrData5_WLC data)
 *   Std_ReturnType Rte_Write_WLCChrgRate_WLCChrgRate(WLCChrgRate data)
 *   Std_ReturnType Rte_Write_WLCChrgSts_WLCChrgSts(WLCChrgSts data)
 *   Std_ReturnType Rte_Write_WLCCtrlSts_WLCCtrlSts(WLCCtrlSts data)
 *   Std_ReturnType Rte_Write_WLCFailSts_WLCFailSts(WLCFailSts data)
 *   Std_ReturnType Rte_Write_WLCImobSts_WLCImobSts(WLCImobSts data)
 *   Std_ReturnType Rte_Write_WLCMuteViaHW_WLCMuteViaHW(WLCMuteViaHW data)
 *   Std_ReturnType Rte_Write_WLC_01_CRC_WLC_01_CRC(WLC_01_CRC data)
 *   Std_ReturnType Rte_Write_WLC_01_MsgCntr_WLC_01_MsgCntr(WLC_01_MsgCntr data)
 *   Std_ReturnType Rte_Write_WLC_02_CRC_WLC_02_CRC(WLC_02_CRC data)
 *   Std_ReturnType Rte_Write_WLC_02_MsgCntr_WLC_02_MsgCntr(WLC_02_MsgCntr data)
 *
 * Mode Interfaces:
 * ================
 *   uint8 Rte_Mode_DcmEcuReset_DcmEcuReset(void)
 *   Modes of Rte_ModeType_DcmEcuReset:
 *   - RTE_MODE_DcmEcuReset_EXECUTE
 *   - RTE_MODE_DcmEcuReset_HARD
 *   - RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_KEYONOFF
 *   - RTE_MODE_DcmEcuReset_NONE
 *   - RTE_MODE_DcmEcuReset_SOFT
 *   - RTE_TRANSITION_DcmEcuReset
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ComReadandWrite_Runnable_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Communication_Read_APP_CODE) ComReadandWrite_Runnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: ComReadandWrite_Runnable
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  CGW_03_CRC Read_CGW_03_CRC_CGW_03_CRC;
  CGW_03_MsgCntr Read_CGW_03_MsgCntr_CGW_03_MsgCntr;
  CGW_WLC_CRC Read_CGW_WLC_CRC_CGW_WLC_CRC;
  CGW_WLC_MsgCntr Read_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr;
  ComfEna Read_ComfEna_ComfEna;
  ComfEna_ASIL Read_ComfEna_ASIL_ComfEna_ASIL;
  Day Read_Day_Day;
  Hr Read_Hr_Hr;
  ImobEnaReq Read_ImobEnaReq_ImobEnaReq;
  Min Read_Min_Min;
  Mth Read_Mth_Mth;
  Sec Read_Sec_Sec;
  VehOdometer Read_VehOdometer_VehOdometer;
  VehSpd Read_VehSpd_VehSpd;
  VehState Read_VehState_VehState;
  VehState_ASIL Read_VehState_ASIL_VehState_ASIL;
  WLCChrgFctEnaReq Read_WLCChrgFctEnaReq_WLCChrgFctEnaReq;
  Yr Read_Yr_Yr;

  Rte_ModeType_DcmEcuReset DcmEcuReset_DcmEcuReset;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_Communication_Read_APP_Rte_Read_CGW_03_CRC_CGW_03_CRC(&Read_CGW_03_CRC_CGW_03_CRC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_CGW_03_MsgCntr_CGW_03_MsgCntr(&Read_CGW_03_MsgCntr_CGW_03_MsgCntr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_CGW_WLC_CRC_CGW_WLC_CRC(&Read_CGW_WLC_CRC_CGW_WLC_CRC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr(&Read_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_ComfEna_ComfEna(&Read_ComfEna_ComfEna);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_ComfEna_ASIL_ComfEna_ASIL(&Read_ComfEna_ASIL_ComfEna_ASIL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_Day_Day(&Read_Day_Day);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_Hr_Hr(&Read_Hr_Hr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_ImobEnaReq_ImobEnaReq(&Read_ImobEnaReq_ImobEnaReq);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_Min_Min(&Read_Min_Min);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_Mth_Mth(&Read_Mth_Mth);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_Sec_Sec(&Read_Sec_Sec);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_VehOdometer_VehOdometer(&Read_VehOdometer_VehOdometer);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_VehSpd_VehSpd(&Read_VehSpd_VehSpd);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_VehState_VehState(&Read_VehState_VehState);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_VehState_ASIL_VehState_ASIL(&Read_VehState_ASIL_VehState_ASIL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_WLCChrgFctEnaReq_WLCChrgFctEnaReq(&Read_WLCChrgFctEnaReq_WLCChrgFctEnaReq);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Read_Yr_Yr(&Read_Yr_Yr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_UsrData0_WLC_UsrData0_WLC(Rte_InitValue_UsrData0_WLC_UsrData0_WLC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_UsrData1_WLC_UsrData1_WLC(Rte_InitValue_UsrData1_WLC_UsrData1_WLC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_UsrData2_WLC_UsrData2_WLC(Rte_InitValue_UsrData2_WLC_UsrData2_WLC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_UsrData3_WLC_UsrData3_WLC(Rte_InitValue_UsrData3_WLC_UsrData3_WLC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_UsrData4_WLC_UsrData4_WLC(Rte_InitValue_UsrData4_WLC_UsrData4_WLC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_UsrData5_WLC_UsrData5_WLC(Rte_InitValue_UsrData5_WLC_UsrData5_WLC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLCChrgRate_WLCChrgRate(Rte_InitValue_WLCChrgRate_WLCChrgRate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLCChrgSts_WLCChrgSts(Rte_InitValue_WLCChrgSts_WLCChrgSts);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLCCtrlSts_WLCCtrlSts(Rte_InitValue_WLCCtrlSts_WLCCtrlSts);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLCFailSts_WLCFailSts(Rte_InitValue_WLCFailSts_WLCFailSts);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLCImobSts_WLCImobSts(Rte_InitValue_WLCImobSts_WLCImobSts);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLCMuteViaHW_WLCMuteViaHW(Rte_InitValue_WLCMuteViaHW_WLCMuteViaHW);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLC_01_CRC_WLC_01_CRC(Rte_InitValue_WLC_01_CRC_WLC_01_CRC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLC_01_MsgCntr_WLC_01_MsgCntr(Rte_InitValue_WLC_01_MsgCntr_WLC_01_MsgCntr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLC_02_CRC_WLC_02_CRC(Rte_InitValue_WLC_02_CRC_WLC_02_CRC);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_Communication_Read_APP_Rte_Write_WLC_02_MsgCntr_WLC_02_MsgCntr(Rte_InitValue_WLC_02_MsgCntr_WLC_02_MsgCntr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  DcmEcuReset_DcmEcuReset = TSC_Communication_Read_APP_Rte_Mode_DcmEcuReset_DcmEcuReset();

  Communication_Read_APP_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Communication_Read_APP_STOP_SEC_CODE
#include "Communication_Read_APP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Communication_Read_APP_TestDefines(void)
{
  /* Enumeration Data Types */

  ComfEna Test_ComfEna_V_1 = Cx0_Comfort_not_enabled;
  ComfEna Test_ComfEna_V_2 = Cx1_Comfort_enabled;
  ComfEna Test_ComfEna_V_3 = Cx2_Reserved;
  ComfEna Test_ComfEna_V_4 = Cx3_Invalid;

  ComfEna_ASIL Test_ComfEna_ASIL_V_1 = Cx0_Comfort_not_enabled;
  ComfEna_ASIL Test_ComfEna_ASIL_V_2 = Cx1_Comfort_enabled;
  ComfEna_ASIL Test_ComfEna_ASIL_V_3 = Cx2_Reserved;
  ComfEna_ASIL Test_ComfEna_ASIL_V_4 = Cx3_Invalid;

  ImobEnaReq Test_ImobEnaReq_V_1 = Cx0_Disable;
  ImobEnaReq Test_ImobEnaReq_V_2 = Cx1_Enable_AID1;
  ImobEnaReq Test_ImobEnaReq_V_3 = Cx2_Enable_AID2;
  ImobEnaReq Test_ImobEnaReq_V_4 = Cx3_Invalid;

  Mth Test_Mth_V_1 = Cx0_Unknown;
  Mth Test_Mth_V_2 = Cx1_January;
  Mth Test_Mth_V_3 = Cx2_February;
  Mth Test_Mth_V_4 = Cx3_March;
  Mth Test_Mth_V_5 = Cx4_April;
  Mth Test_Mth_V_6 = Cx5_May;
  Mth Test_Mth_V_7 = Cx6_June;
  Mth Test_Mth_V_8 = Cx7_July;
  Mth Test_Mth_V_9 = Cx8_August;
  Mth Test_Mth_V_10 = Cx9_September;
  Mth Test_Mth_V_11 = CxA_October;
  Mth Test_Mth_V_12 = CxB_November;
  Mth Test_Mth_V_13 = CxC_December;
  Mth Test_Mth_V_14 = CxD_Reserved;
  Mth Test_Mth_V_15 = CxE_Reserved;
  Mth Test_Mth_V_16 = CxF_Invalid;

  VehState Test_VehState_V_1 = Cx0_Parked_vehicle_Off_;
  VehState Test_VehState_V_2 = Cx1_Driver_present_On_;
  VehState Test_VehState_V_3 = Cx2_Driving;
  VehState Test_VehState_V_4 = Cx3_Software_update;
  VehState Test_VehState_V_5 = Cx4_Reserved;
  VehState Test_VehState_V_6 = Cx5_Reserved;
  VehState Test_VehState_V_7 = Cx6_Reserved;
  VehState Test_VehState_V_8 = Cx7_Reserved;
  VehState Test_VehState_V_9 = Cx8_Reserved;
  VehState Test_VehState_V_10 = Cx9_Reserved;
  VehState Test_VehState_V_11 = CxA_Reserved;
  VehState Test_VehState_V_12 = CxB_Reserved;
  VehState Test_VehState_V_13 = CxC_Reserved;
  VehState Test_VehState_V_14 = CxD_Reserved;
  VehState Test_VehState_V_15 = CxE_Reserved;
  VehState Test_VehState_V_16 = CxF_Invalid;

  VehState_ASIL Test_VehState_ASIL_V_1 = Cx0_Parked_vehicle_Off_;
  VehState_ASIL Test_VehState_ASIL_V_2 = Cx1_Driver_present_On_;
  VehState_ASIL Test_VehState_ASIL_V_3 = Cx2_Driving;
  VehState_ASIL Test_VehState_ASIL_V_4 = Cx3_Software_update;
  VehState_ASIL Test_VehState_ASIL_V_5 = Cx4_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_6 = Cx5_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_7 = Cx6_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_8 = Cx7_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_9 = Cx8_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_10 = Cx9_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_11 = CxA_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_12 = CxB_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_13 = CxC_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_14 = CxD_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_15 = CxE_Reserved;
  VehState_ASIL Test_VehState_ASIL_V_16 = CxF_Invalid;

  WLCChrgFctEnaReq Test_WLCChrgFctEnaReq_V_1 = Cx0_Disable_WLC_charging_function;
  WLCChrgFctEnaReq Test_WLCChrgFctEnaReq_V_2 = Cx1_Enable_WLC_charging_function;
  WLCChrgFctEnaReq Test_WLCChrgFctEnaReq_V_3 = Cx2_No_operation;
  WLCChrgFctEnaReq Test_WLCChrgFctEnaReq_V_4 = Cx3_Invalid;

  WLCChrgRate Test_WLCChrgRate_V_1 = Cx0_Not_started_;
  WLCChrgRate Test_WLCChrgRate_V_2 = Cx1_Power_Requested_;
  WLCChrgRate Test_WLCChrgRate_V_3 = Cx2_Power_Reduced_;
  WLCChrgRate Test_WLCChrgRate_V_4 = Cx3_Reserved;

  WLCChrgSts Test_WLCChrgSts_V_1 = Cx0_WLC_stopped;
  WLCChrgSts Test_WLCChrgSts_V_2 = Cx1_WLC_on_going;
  WLCChrgSts Test_WLCChrgSts_V_3 = Cx2_Charge_complete;
  WLCChrgSts Test_WLCChrgSts_V_4 = Cx3_Invalid;

  WLCCtrlSts Test_WLCCtrlSts_V_1 = Cx0_WLC_enabled;
  WLCCtrlSts Test_WLCCtrlSts_V_2 = Cx1_WLC_disabled;
  WLCCtrlSts Test_WLCCtrlSts_V_3 = Cx2_Reserved;
  WLCCtrlSts Test_WLCCtrlSts_V_4 = Cx3_Invalid;

  WLCFailSts Test_WLCFailSts_V_1 = Cx0_No_failure;
  WLCFailSts Test_WLCFailSts_V_2 = Cx1_Over_temperature;
  WLCFailSts Test_WLCFailSts_V_3 = Cx2_Under_voltage;
  WLCFailSts Test_WLCFailSts_V_4 = Cx3_Over_voltage;
  WLCFailSts Test_WLCFailSts_V_5 = Cx4_Internal_error;
  WLCFailSts Test_WLCFailSts_V_6 = Cx5_Foreign_object_existing;
  WLCFailSts Test_WLCFailSts_V_7 = Cx6_Unknown_error;
  WLCFailSts Test_WLCFailSts_V_8 = Cx7_Smartphone_no_response_or_error;
  WLCFailSts Test_WLCFailSts_V_9 = Cx8_Conductive_Device_Detected;
  WLCFailSts Test_WLCFailSts_V_10 = Cx9_Reserved;
  WLCFailSts Test_WLCFailSts_V_11 = CxA_Reserved;
  WLCFailSts Test_WLCFailSts_V_12 = CxB_Reserved;
  WLCFailSts Test_WLCFailSts_V_13 = CxC_Reserved;
  WLCFailSts Test_WLCFailSts_V_14 = CxD_Reserved;
  WLCFailSts Test_WLCFailSts_V_15 = CxE_Reserved;
  WLCFailSts Test_WLCFailSts_V_16 = CxF_Invalid;

  WLCImobSts Test_WLCImobSts_V_1 = Cx0_Disable;
  WLCImobSts Test_WLCImobSts_V_2 = Cx1_Enable;
  WLCImobSts Test_WLCImobSts_V_3 = Cx2_Reserved;
  WLCImobSts Test_WLCImobSts_V_4 = Cx3_Invalid;

  /* Modes */

  uint8 Test_DcmEcuReset_MV_1 = RTE_MODE_DcmEcuReset_NONE;
  uint8 Test_DcmEcuReset_MV_2 = RTE_MODE_DcmEcuReset_HARD;
  uint8 Test_DcmEcuReset_MV_3 = RTE_MODE_DcmEcuReset_KEYONOFF;
  uint8 Test_DcmEcuReset_MV_4 = RTE_MODE_DcmEcuReset_SOFT;
  uint8 Test_DcmEcuReset_MV_5 = RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER;
  uint8 Test_DcmEcuReset_MV_6 = RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER;
  uint8 Test_DcmEcuReset_MV_7 = RTE_MODE_DcmEcuReset_EXECUTE;
  uint8 Test_DcmEcuReset_TV = RTE_TRANSITION_DcmEcuReset;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
