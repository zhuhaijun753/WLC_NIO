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
 *             File:  TSC_Communication_Read_APP.h
 *           Config:  WLC.dpa
 *      ECU-Project:  WLC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_CGW_03_CRC_CGW_03_CRC(CGW_03_CRC *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_CGW_03_MsgCntr_CGW_03_MsgCntr(CGW_03_MsgCntr *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_CGW_WLC_CRC_CGW_WLC_CRC(CGW_WLC_CRC *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_CGW_WLC_MsgCntr_CGW_WLC_MsgCntr(CGW_WLC_MsgCntr *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_ComfEna_ComfEna(ComfEna *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_ComfEna_ASIL_ComfEna_ASIL(ComfEna_ASIL *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_Day_Day(Day *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_Hr_Hr(Hr *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_ImobEnaReq_ImobEnaReq(ImobEnaReq *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_Min_Min(Min *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_Mth_Mth(Mth *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_Sec_Sec(Sec *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_VehOdometer_VehOdometer(VehOdometer *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_VehSpd_VehSpd(VehSpd *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_VehState_VehState(VehState *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_VehState_ASIL_VehState_ASIL(VehState_ASIL *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_WLCChrgFctEnaReq_WLCChrgFctEnaReq(WLCChrgFctEnaReq *data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Read_Yr_Yr(Yr *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_UsrData0_WLC_UsrData0_WLC(UsrData0_WLC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_UsrData1_WLC_UsrData1_WLC(UsrData1_WLC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_UsrData2_WLC_UsrData2_WLC(UsrData2_WLC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_UsrData3_WLC_UsrData3_WLC(UsrData3_WLC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_UsrData4_WLC_UsrData4_WLC(UsrData4_WLC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_UsrData5_WLC_UsrData5_WLC(UsrData5_WLC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLCChrgRate_WLCChrgRate(WLCChrgRate data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLCChrgSts_WLCChrgSts(WLCChrgSts data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLCCtrlSts_WLCCtrlSts(WLCCtrlSts data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLCFailSts_WLCFailSts(WLCFailSts data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLCImobSts_WLCImobSts(WLCImobSts data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLCMuteViaHW_WLCMuteViaHW(WLCMuteViaHW data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLC_01_CRC_WLC_01_CRC(WLC_01_CRC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLC_01_MsgCntr_WLC_01_MsgCntr(WLC_01_MsgCntr data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLC_02_CRC_WLC_02_CRC(WLC_02_CRC data);
Std_ReturnType TSC_Communication_Read_APP_Rte_Write_WLC_02_MsgCntr_WLC_02_MsgCntr(WLC_02_MsgCntr data);

/** Mode switches */
uint8 TSC_Communication_Read_APP_Rte_Mode_DcmEcuReset_DcmEcuReset(void);




