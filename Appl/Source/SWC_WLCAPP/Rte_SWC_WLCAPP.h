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
 *             File:  Rte_SWC_WLCAPP.h
 *           Config:  D:/Auto/Demo/WLCProject/WLC.dpa
 *        SW-C Type:  SWC_WLCAPP
 *  Generation Time:  2020-02-09 12:02:07
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  Application header file for SW-C <SWC_WLCAPP> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SWC_WLCAPP_H
# define _RTE_SWC_WLCAPP_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SWC_WLCAPP_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_CDS_SWC_WLCAPP
{
  /* dummy entry */
  uint8 _dummy;
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_SWC_WLCAPP, RTE_CONST, RTE_CONST) Rte_Inst_SWC_WLCAPP; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_SWC_WLCAPP, TYPEDEF, RTE_CONST) Rte_Instance;


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetCurrentComMode(P2VAR(ComM_ModeType, AUTOMATIC, RTE_SWC_WLCAPP_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetMaxComMode(P2VAR(ComM_ModeType, AUTOMATIC, RTE_SWC_WLCAPP_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetRequestedComMode(P2VAR(ComM_ModeType, AUTOMATIC, RTE_SWC_WLCAPP_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_RequestComMode(ComM_ModeType ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetCurrentComMode Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetCurrentComMode
# define Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetMaxComMode Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetMaxComMode
# define Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetRequestedComMode Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetRequestedComMode
# define Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_RequestComMode Rte_Call_SWC_WLCAPP_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_RequestComMode




# define SWC_WLCAPP_START_SEC_CODE
# include "SWC_WLCAPP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: ComControl_Init_Runnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetCurrentComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetMaxComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetRequestedComMode(ComM_ModeType *ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_ComControl_Init_Runnable ComControl_Init_Runnable
FUNC(void, SWC_WLCAPP_CODE) ComControl_Init_Runnable(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define SWC_WLCAPP_STOP_SEC_CODE
# include "SWC_WLCAPP_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

# define RTE_E_ComM_UserRequest_E_MODE_LIMITATION (2U)

# define RTE_E_ComM_UserRequest_E_NOT_OK (1U)

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_SWC_WLCAPP_H */
