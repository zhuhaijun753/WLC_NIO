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
 *            Module: Os
 *           Program: VAG AR4 (MSR_Vag_SLP5)
 *          Customer: SAIC Volkswagen Automotive Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016393AFP-C
 *    License Scope : The usage is restricted to CBD1900162_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Lcfg.h
 *   Generation Time: 2019-07-11 16:32:27
 *           Project: Demo - Version 1.0
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

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_BrsMainBackgroundTask_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BrsMainBackgroundTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_BRSMAINBACKGROUNDTASK_CODE) Os_Task_BrsMainBackgroundTask(void);

# define OS_STOP_SEC_BrsMainBackgroundTask_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_BrsMainTask_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BrsMainTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_BRSMAINTASK_CODE) Os_Task_BrsMainTask(void);

# define OS_STOP_SEC_BrsMainTask_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CODE) Os_Task_Default_Init_Task(void);

# define OS_STOP_SEC_Default_Init_Task_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_APP_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_APP()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APP_CODE) Os_Task_OsTask_APP(void);

# define OS_STOP_SEC_OsTask_APP_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_BSW_SCHM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_BSW_SCHM()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_BSW_SCHM_CODE) Os_Task_OsTask_BSW_SCHM(void);

# define OS_STOP_SEC_OsTask_BSW_SCHM_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_Cdd_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_Cdd()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_CDD_CODE) Os_Task_OsTask_Cdd(void);

# define OS_STOP_SEC_OsTask_Cdd_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrRxFifo_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrRxFifo()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRRXFIFO_CODE) Os_Isr_CanIsrRxFifo(void);

# define OS_STOP_SEC_CanIsrRxFifo_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrStatus_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrStatus_3()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRSTATUS_3_CODE) Os_Isr_CanIsrStatus_3(void);

# define OS_STOP_SEC_CanIsrStatus_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrTx_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrTx_3()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRTX_3_CODE) Os_Isr_CanIsrTx_3(void);

# define OS_STOP_SEC_CanIsrTx_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
