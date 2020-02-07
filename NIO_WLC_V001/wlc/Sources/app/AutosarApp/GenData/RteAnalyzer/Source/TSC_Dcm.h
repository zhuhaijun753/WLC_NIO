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
 *             File:  TSC_Dcm.h
 *           Config:  WLC.dpa
 *      ECU-Project:  WLC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Service interfaces */
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_BootloaderVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_BootloaderVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_BootloaderVersion_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ConfigurarionFingerprint_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ConfigurarionFingerprint_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ConfigurarionFingerprint_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUConfigurarion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUConfigurarion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUConfigurarion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUDiagDatabaseVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUDiagDatabaseVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUManufacturingDate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUManufacturingDate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUProgrammingDate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUProgrammingDate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUSerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ECUSerialNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ReadActiveDiagSession_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ReadActiveDiagSession_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ReadFingerprint_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_ReadFingerprint_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_RepairShopFingerPrint_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_RepairShopFingerPrint_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_RepairShopFingerPrint_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SystemName_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SystemName_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SystemName_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SystemSupplierIdData_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_SystemSupplierIdData_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VIN_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VIN_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_CalibrarionPartNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_CalibrarionPartNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_CalibrarionPartNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_CalibrationBaseline_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_CalibrationBaseline_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_CalibrationBaseline_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_FOTASpecialPartNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_FOTASpecialPartNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_FOTASpecialPartNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SoftwarBaseline_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SoftwarBaseline_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SoftwarBaseline_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SofwarePartNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SofwarePartNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SofwarePartNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SparepartNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SparepartNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_SparepartNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_Specialdatabaseline_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_Specialdatabaseline_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_Specialdatabaseline_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DcmDspData_VM_Specialdatabaseline_WriteData(const uint8 *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_RWDI_LightOnOffCounter_LightOnOffCounter_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_RWDI_LightOnOffCounter_LightOnOffCounter_Value_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_RWDI_LightOnOffCounter_LightOnOffCounter_Value_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_VM_HardwareBaseline_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_VM_HardwareBaseline_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_VM_HardwareBaseline_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_VM_HardwarePartNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_VM_HardwarePartNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Diag_VM_HardwarePartNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_01_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_01_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_02_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_02_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode);

/** Mode switches */
Std_ReturnType TSC_Dcm_Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode);
Std_ReturnType TSC_Dcm_Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode);
Std_ReturnType TSC_Dcm_Rte_Switch_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode);

/** Mode switch acknowledgement */
Std_ReturnType TSC_Dcm_Rte_SwitchAck_DcmEcuReset_DcmEcuReset(void);




