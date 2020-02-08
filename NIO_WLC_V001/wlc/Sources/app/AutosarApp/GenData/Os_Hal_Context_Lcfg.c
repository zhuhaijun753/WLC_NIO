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
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2019-07-11 17:10:34
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

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
#if 0
#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic ISR2 level context data: Level4 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn;

/*! HAL dynamic task context data: BrsMainBackgroundTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BrsMainBackgroundTask_Dyn;

/*! HAL dynamic task context data: BrsMainTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_BrsMainTask_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: OsTask_APP */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_APP_Dyn;

/*! HAL dynamic task context data: OsTask_BSW_SCHM */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_BSW_SCHM_Dyn;

/*! HAL dynamic task context data: OsTask_Cdd */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Cdd_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperOs_CoreInitHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FF00uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperStatusHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FF00uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL ISR2 context configuration data: CanIsrRxFifo */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrRxFifo =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrRxFifo, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FF00uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrStatus_3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_3 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrStatus_3, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FF00uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrTx_3 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrTx_3 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrTx_3, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FF00uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Os_TimerPitIsr, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FF00uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL task context configuration data: BrsMainBackgroundTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BrsMainBackgroundTask =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio2_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio2_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_BrsMainBackgroundTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: BrsMainTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_BrsMainTask =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_BrsMainTask_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_BrsMainTask_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_BrsMainTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: Default_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio100_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Default_Init_Task, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Os_IdleTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_APP */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_APP =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_APP_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_APP_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_APP, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_BSW_SCHM */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_BSW_SCHM =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_BSW_SCHM_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_BSW_SCHM_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_BSW_SCHM, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_Cdd */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Cdd =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio18_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio18_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_Cdd, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackEnd   = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn) /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
