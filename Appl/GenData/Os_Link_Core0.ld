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
 *              File: Os_Link_Core0.ld
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

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
.OS_INTVEC_CORE0_CODE ALIGN(512) :> .
_OS_INTVEC_CORE0_CODE_START = ADDR(.OS_INTVEC_CORE0_CODE);
_OS_INTVEC_CORE0_CODE_END = ENDADDR(.OS_INTVEC_CORE0_CODE) - 1;
#endif

#if defined ( OS_LINK_EXCVEC_CODE )
.OS_EXCVEC_CORE0_CODE ALIGN(512) :> .
_OS_EXCVEC_CORE0_CODE_START = ADDR(.OS_EXCVEC_CORE0_CODE);
_OS_EXCVEC_CORE0_CODE_END = ENDADDR(.OS_EXCVEC_CORE0_CODE) - 1;
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
.OS_BrsMainBackgroundTask_CODE ALIGN(4) :> .
_OS_BrsMainBackgroundTask_CODE_START = ADDR(.OS_BrsMainBackgroundTask_CODE);
__OS_BrsMainBackgroundTask_CODE_START = ADDR(.OS_BrsMainBackgroundTask_CODE);
_OS_BrsMainBackgroundTask_CODE_END = ENDADDR(.OS_BrsMainBackgroundTask_CODE) - 1;
__OS_BrsMainBackgroundTask_CODE_END = ENDADDR(.OS_BrsMainBackgroundTask_CODE) - 1;
.OS_BrsMainTask_CODE ALIGN(4) :> .
_OS_BrsMainTask_CODE_START = ADDR(.OS_BrsMainTask_CODE);
__OS_BrsMainTask_CODE_START = ADDR(.OS_BrsMainTask_CODE);
_OS_BrsMainTask_CODE_END = ENDADDR(.OS_BrsMainTask_CODE) - 1;
__OS_BrsMainTask_CODE_END = ENDADDR(.OS_BrsMainTask_CODE) - 1;
.OS_CanIsrRxFifo_CODE ALIGN(4) :> .
_OS_CanIsrRxFifo_CODE_START = ADDR(.OS_CanIsrRxFifo_CODE);
__OS_CanIsrRxFifo_CODE_START = ADDR(.OS_CanIsrRxFifo_CODE);
_OS_CanIsrRxFifo_CODE_END = ENDADDR(.OS_CanIsrRxFifo_CODE) - 1;
__OS_CanIsrRxFifo_CODE_END = ENDADDR(.OS_CanIsrRxFifo_CODE) - 1;
.OS_CanIsrStatus_3_CODE ALIGN(4) :> .
_OS_CanIsrStatus_3_CODE_START = ADDR(.OS_CanIsrStatus_3_CODE);
__OS_CanIsrStatus_3_CODE_START = ADDR(.OS_CanIsrStatus_3_CODE);
_OS_CanIsrStatus_3_CODE_END = ENDADDR(.OS_CanIsrStatus_3_CODE) - 1;
__OS_CanIsrStatus_3_CODE_END = ENDADDR(.OS_CanIsrStatus_3_CODE) - 1;
.OS_CanIsrTx_3_CODE ALIGN(4) :> .
_OS_CanIsrTx_3_CODE_START = ADDR(.OS_CanIsrTx_3_CODE);
__OS_CanIsrTx_3_CODE_START = ADDR(.OS_CanIsrTx_3_CODE);
_OS_CanIsrTx_3_CODE_END = ENDADDR(.OS_CanIsrTx_3_CODE) - 1;
__OS_CanIsrTx_3_CODE_END = ENDADDR(.OS_CanIsrTx_3_CODE) - 1;
.OS_Default_Init_Task_CODE ALIGN(4) :> .
_OS_Default_Init_Task_CODE_START = ADDR(.OS_Default_Init_Task_CODE);
__OS_Default_Init_Task_CODE_START = ADDR(.OS_Default_Init_Task_CODE);
_OS_Default_Init_Task_CODE_END = ENDADDR(.OS_Default_Init_Task_CODE) - 1;
__OS_Default_Init_Task_CODE_END = ENDADDR(.OS_Default_Init_Task_CODE) - 1;
.OS_OsTask_APP_CODE ALIGN(4) :> .
_OS_OsTask_APP_CODE_START = ADDR(.OS_OsTask_APP_CODE);
__OS_OsTask_APP_CODE_START = ADDR(.OS_OsTask_APP_CODE);
_OS_OsTask_APP_CODE_END = ENDADDR(.OS_OsTask_APP_CODE) - 1;
__OS_OsTask_APP_CODE_END = ENDADDR(.OS_OsTask_APP_CODE) - 1;
.OS_OsTask_BSW_SCHM_CODE ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_CODE_START = ADDR(.OS_OsTask_BSW_SCHM_CODE);
__OS_OsTask_BSW_SCHM_CODE_START = ADDR(.OS_OsTask_BSW_SCHM_CODE);
_OS_OsTask_BSW_SCHM_CODE_END = ENDADDR(.OS_OsTask_BSW_SCHM_CODE) - 1;
__OS_OsTask_BSW_SCHM_CODE_END = ENDADDR(.OS_OsTask_BSW_SCHM_CODE) - 1;
.OS_OsTask_Cdd_CODE ALIGN(4) :> .
_OS_OsTask_Cdd_CODE_START = ADDR(.OS_OsTask_Cdd_CODE);
__OS_OsTask_Cdd_CODE_START = ADDR(.OS_OsTask_Cdd_CODE);
_OS_OsTask_Cdd_CODE_END = ENDADDR(.OS_OsTask_Cdd_CODE) - 1;
__OS_OsTask_Cdd_CODE_END = ENDADDR(.OS_OsTask_Cdd_CODE) - 1;
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_EXCVEC_CODE
# undef OS_LINK_EXCVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_FAR )
.OS_CORE0_CONST ALIGN(4) :> .
_OS_CORE0_CONST_START = ADDR(.OS_CORE0_CONST);
_OS_CORE0_CONST_END = ENDADDR(.OS_CORE0_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_NEAR )
.OS_CORE0_CONST_FAST ALIGN(4) :> .
_OS_CORE0_CONST_FAST_START = ADDR(.OS_CORE0_CONST_FAST);
_OS_CORE0_CONST_FAST_END = ENDADDR(.OS_CORE0_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_INTVEC_CONST )
.OS_INTVEC_CORE0_CONST ALIGN(4) :> .
_OS_INTVEC_CORE0_CONST_START = ADDR(.OS_INTVEC_CORE0_CONST);
_OS_INTVEC_CORE0_CONST_END = ENDADDR(.OS_INTVEC_CORE0_CONST) - 1;
#endif

#if defined ( OS_LINK_EXCVEC_CONST )
.OS_EXCVEC_CORE0_CONST ALIGN(4) :> .
_OS_EXCVEC_CORE0_CONST_START = ADDR(.OS_EXCVEC_CORE0_CONST);
_OS_EXCVEC_CORE0_CONST_END = ENDADDR(.OS_EXCVEC_CORE0_CONST) - 1;
#endif


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR )
.OS_SystemApplication_OsCore0_CONST ALIGN(4) :> .
_OS_SystemApplication_OsCore0_CONST_START = ADDR(.OS_SystemApplication_OsCore0_CONST);
_OS_SystemApplication_OsCore0_CONST_END = ENDADDR(.OS_SystemApplication_OsCore0_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR )
.OS_SystemApplication_OsCore0_CONST_FAST ALIGN(4) :> .
_OS_SystemApplication_OsCore0_CONST_FAST_START = ADDR(.OS_SystemApplication_OsCore0_CONST_FAST);
_OS_SystemApplication_OsCore0_CONST_FAST_END = ENDADDR(.OS_SystemApplication_OsCore0_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT )

.ROM_OS_SystemApplication_OsCore0_VAR ROM(.OS_SystemApplication_OsCore0_VAR) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR);
_ROM_OS_SystemApplication_OsCore0_VAR_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR);

.ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT);

.ROM_OS_SystemApplication_OsCore0_VAR_FAST ROM(.OS_SystemApplication_OsCore0_VAR_FAST) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST);

.ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT);

.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE ROM(.OS_SystemApplication_OsCore0_VAR_NOCACHE) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE);
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE);

.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT);

.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE ROM(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE);

.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT);
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_FAR )
.OS_BrsMainBackgroundTask_CONST ALIGN(4) :> .
_OS_BrsMainBackgroundTask_CONST_START = ADDR(.OS_BrsMainBackgroundTask_CONST);
_OS_BrsMainBackgroundTask_CONST_END = ENDADDR(.OS_BrsMainBackgroundTask_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_NEAR )
.OS_BrsMainBackgroundTask_CONST_FAST ALIGN(4) :> .
_OS_BrsMainBackgroundTask_CONST_FAST_START = ADDR(.OS_BrsMainBackgroundTask_CONST_FAST);
_OS_BrsMainBackgroundTask_CONST_FAST_END = ENDADDR(.OS_BrsMainBackgroundTask_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_INIT )

.ROM_OS_BrsMainBackgroundTask_VAR ROM(.OS_BrsMainBackgroundTask_VAR) :> .
_ROM_OS_BrsMainBackgroundTask_VAR_START = ADDR(.ROM_OS_BrsMainBackgroundTask_VAR);
_ROM_OS_BrsMainBackgroundTask_VAR_END = ENDADDR(.ROM_OS_BrsMainBackgroundTask_VAR);

.ROM_OS_BrsMainBackgroundTask_VAR_NOINIT ROM(.OS_BrsMainBackgroundTask_VAR_NOINIT) :> .
_ROM_OS_BrsMainBackgroundTask_VAR_NOINIT_START = ADDR(.ROM_OS_BrsMainBackgroundTask_VAR_NOINIT);
_ROM_OS_BrsMainBackgroundTask_VAR_NOINIT_END = ENDADDR(.ROM_OS_BrsMainBackgroundTask_VAR_NOINIT);

.ROM_OS_BrsMainBackgroundTask_VAR_ZERO_INIT ROM(.OS_BrsMainBackgroundTask_VAR_ZERO_INIT) :> .
_ROM_OS_BrsMainBackgroundTask_VAR_ZERO_INIT_START = ADDR(.ROM_OS_BrsMainBackgroundTask_VAR_ZERO_INIT);
_ROM_OS_BrsMainBackgroundTask_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_BrsMainBackgroundTask_VAR_ZERO_INIT);

.ROM_OS_BrsMainBackgroundTask_VAR_FAST ROM(.OS_BrsMainBackgroundTask_VAR_FAST) :> .
_ROM_OS_BrsMainBackgroundTask_VAR_FAST_START = ADDR(.ROM_OS_BrsMainBackgroundTask_VAR_FAST);
_ROM_OS_BrsMainBackgroundTask_VAR_FAST_END = ENDADDR(.ROM_OS_BrsMainBackgroundTask_VAR_FAST);

.ROM_OS_BrsMainBackgroundTask_VAR_FAST_NOINIT ROM(.OS_BrsMainBackgroundTask_VAR_FAST_NOINIT) :> .
_ROM_OS_BrsMainBackgroundTask_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_BrsMainBackgroundTask_VAR_FAST_NOINIT);
_ROM_OS_BrsMainBackgroundTask_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_BrsMainBackgroundTask_VAR_FAST_NOINIT);

.ROM_OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT ROM(.OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT);
_ROM_OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK
# undef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK
#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_FAR
# undef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_NEAR
# undef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_INIT
# undef OS_LINK_CONST_TASK_BRSMAINBACKGROUNDTASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINTASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINTASK_FAR )
.OS_BrsMainTask_CONST ALIGN(4) :> .
_OS_BrsMainTask_CONST_START = ADDR(.OS_BrsMainTask_CONST);
_OS_BrsMainTask_CONST_END = ENDADDR(.OS_BrsMainTask_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINTASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINTASK_NEAR )
.OS_BrsMainTask_CONST_FAST ALIGN(4) :> .
_OS_BrsMainTask_CONST_FAST_START = ADDR(.OS_BrsMainTask_CONST_FAST);
_OS_BrsMainTask_CONST_FAST_END = ENDADDR(.OS_BrsMainTask_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINTASK ) || defined ( OS_LINK_CONST_TASK_BRSMAINTASK_INIT )

.ROM_OS_BrsMainTask_VAR ROM(.OS_BrsMainTask_VAR) :> .
_ROM_OS_BrsMainTask_VAR_START = ADDR(.ROM_OS_BrsMainTask_VAR);
_ROM_OS_BrsMainTask_VAR_END = ENDADDR(.ROM_OS_BrsMainTask_VAR);

.ROM_OS_BrsMainTask_VAR_NOINIT ROM(.OS_BrsMainTask_VAR_NOINIT) :> .
_ROM_OS_BrsMainTask_VAR_NOINIT_START = ADDR(.ROM_OS_BrsMainTask_VAR_NOINIT);
_ROM_OS_BrsMainTask_VAR_NOINIT_END = ENDADDR(.ROM_OS_BrsMainTask_VAR_NOINIT);

.ROM_OS_BrsMainTask_VAR_ZERO_INIT ROM(.OS_BrsMainTask_VAR_ZERO_INIT) :> .
_ROM_OS_BrsMainTask_VAR_ZERO_INIT_START = ADDR(.ROM_OS_BrsMainTask_VAR_ZERO_INIT);
_ROM_OS_BrsMainTask_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_BrsMainTask_VAR_ZERO_INIT);

.ROM_OS_BrsMainTask_VAR_FAST ROM(.OS_BrsMainTask_VAR_FAST) :> .
_ROM_OS_BrsMainTask_VAR_FAST_START = ADDR(.ROM_OS_BrsMainTask_VAR_FAST);
_ROM_OS_BrsMainTask_VAR_FAST_END = ENDADDR(.ROM_OS_BrsMainTask_VAR_FAST);

.ROM_OS_BrsMainTask_VAR_FAST_NOINIT ROM(.OS_BrsMainTask_VAR_FAST_NOINIT) :> .
_ROM_OS_BrsMainTask_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_BrsMainTask_VAR_FAST_NOINIT);
_ROM_OS_BrsMainTask_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_BrsMainTask_VAR_FAST_NOINIT);

.ROM_OS_BrsMainTask_VAR_FAST_ZERO_INIT ROM(.OS_BrsMainTask_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_BrsMainTask_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_BrsMainTask_VAR_FAST_ZERO_INIT);
_ROM_OS_BrsMainTask_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_BrsMainTask_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINTASK
# undef OS_LINK_CONST_TASK_BRSMAINTASK
#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINTASK_FAR
# undef OS_LINK_CONST_TASK_BRSMAINTASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINTASK_NEAR
# undef OS_LINK_CONST_TASK_BRSMAINTASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_BRSMAINTASK_INIT
# undef OS_LINK_CONST_TASK_BRSMAINTASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR )
.OS_Default_Init_Task_CONST ALIGN(4) :> .
_OS_Default_Init_Task_CONST_START = ADDR(.OS_Default_Init_Task_CONST);
_OS_Default_Init_Task_CONST_END = ENDADDR(.OS_Default_Init_Task_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR )
.OS_Default_Init_Task_CONST_FAST ALIGN(4) :> .
_OS_Default_Init_Task_CONST_FAST_START = ADDR(.OS_Default_Init_Task_CONST_FAST);
_OS_Default_Init_Task_CONST_FAST_END = ENDADDR(.OS_Default_Init_Task_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT )

.ROM_OS_Default_Init_Task_VAR ROM(.OS_Default_Init_Task_VAR) :> .
_ROM_OS_Default_Init_Task_VAR_START = ADDR(.ROM_OS_Default_Init_Task_VAR);
_ROM_OS_Default_Init_Task_VAR_END = ENDADDR(.ROM_OS_Default_Init_Task_VAR);

.ROM_OS_Default_Init_Task_VAR_NOINIT ROM(.OS_Default_Init_Task_VAR_NOINIT) :> .
_ROM_OS_Default_Init_Task_VAR_NOINIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_NOINIT);
_ROM_OS_Default_Init_Task_VAR_NOINIT_END = ENDADDR(.ROM_OS_Default_Init_Task_VAR_NOINIT);

.ROM_OS_Default_Init_Task_VAR_ZERO_INIT ROM(.OS_Default_Init_Task_VAR_ZERO_INIT) :> .
_ROM_OS_Default_Init_Task_VAR_ZERO_INIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_ZERO_INIT);
_ROM_OS_Default_Init_Task_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_Default_Init_Task_VAR_ZERO_INIT);

.ROM_OS_Default_Init_Task_VAR_FAST ROM(.OS_Default_Init_Task_VAR_FAST) :> .
_ROM_OS_Default_Init_Task_VAR_FAST_START = ADDR(.ROM_OS_Default_Init_Task_VAR_FAST);
_ROM_OS_Default_Init_Task_VAR_FAST_END = ENDADDR(.ROM_OS_Default_Init_Task_VAR_FAST);

.ROM_OS_Default_Init_Task_VAR_FAST_NOINIT ROM(.OS_Default_Init_Task_VAR_FAST_NOINIT) :> .
_ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_FAST_NOINIT);
_ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_Default_Init_Task_VAR_FAST_NOINIT);

.ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT ROM(.OS_Default_Init_Task_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT);
_ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR )
.OS_IdleTask_OsCore0_CONST ALIGN(4) :> .
_OS_IdleTask_OsCore0_CONST_START = ADDR(.OS_IdleTask_OsCore0_CONST);
_OS_IdleTask_OsCore0_CONST_END = ENDADDR(.OS_IdleTask_OsCore0_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR )
.OS_IdleTask_OsCore0_CONST_FAST ALIGN(4) :> .
_OS_IdleTask_OsCore0_CONST_FAST_START = ADDR(.OS_IdleTask_OsCore0_CONST_FAST);
_OS_IdleTask_OsCore0_CONST_FAST_END = ENDADDR(.OS_IdleTask_OsCore0_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT )

.ROM_OS_IdleTask_OsCore0_VAR ROM(.OS_IdleTask_OsCore0_VAR) :> .
_ROM_OS_IdleTask_OsCore0_VAR_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR);
_ROM_OS_IdleTask_OsCore0_VAR_END = ENDADDR(.ROM_OS_IdleTask_OsCore0_VAR);

.ROM_OS_IdleTask_OsCore0_VAR_NOINIT ROM(.OS_IdleTask_OsCore0_VAR_NOINIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_NOINIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_NOINIT);
_ROM_OS_IdleTask_OsCore0_VAR_NOINIT_END = ENDADDR(.ROM_OS_IdleTask_OsCore0_VAR_NOINIT);

.ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT ROM(.OS_IdleTask_OsCore0_VAR_ZERO_INIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT);
_ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT);

.ROM_OS_IdleTask_OsCore0_VAR_FAST ROM(.OS_IdleTask_OsCore0_VAR_FAST) :> .
_ROM_OS_IdleTask_OsCore0_VAR_FAST_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST);
_ROM_OS_IdleTask_OsCore0_VAR_FAST_END = ENDADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST);

.ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT ROM(.OS_IdleTask_OsCore0_VAR_FAST_NOINIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT);
_ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT);

.ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT ROM(.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT);
_ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APP ) || defined ( OS_LINK_CONST_TASK_OSTASK_APP_FAR )
.OS_OsTask_APP_CONST ALIGN(4) :> .
_OS_OsTask_APP_CONST_START = ADDR(.OS_OsTask_APP_CONST);
_OS_OsTask_APP_CONST_END = ENDADDR(.OS_OsTask_APP_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APP ) || defined ( OS_LINK_CONST_TASK_OSTASK_APP_NEAR )
.OS_OsTask_APP_CONST_FAST ALIGN(4) :> .
_OS_OsTask_APP_CONST_FAST_START = ADDR(.OS_OsTask_APP_CONST_FAST);
_OS_OsTask_APP_CONST_FAST_END = ENDADDR(.OS_OsTask_APP_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APP ) || defined ( OS_LINK_CONST_TASK_OSTASK_APP_INIT )

.ROM_OS_OsTask_APP_VAR ROM(.OS_OsTask_APP_VAR) :> .
_ROM_OS_OsTask_APP_VAR_START = ADDR(.ROM_OS_OsTask_APP_VAR);
_ROM_OS_OsTask_APP_VAR_END = ENDADDR(.ROM_OS_OsTask_APP_VAR);

.ROM_OS_OsTask_APP_VAR_NOINIT ROM(.OS_OsTask_APP_VAR_NOINIT) :> .
_ROM_OS_OsTask_APP_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_APP_VAR_NOINIT);
_ROM_OS_OsTask_APP_VAR_NOINIT_END = ENDADDR(.ROM_OS_OsTask_APP_VAR_NOINIT);

.ROM_OS_OsTask_APP_VAR_ZERO_INIT ROM(.OS_OsTask_APP_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_APP_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_APP_VAR_ZERO_INIT);
_ROM_OS_OsTask_APP_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_OsTask_APP_VAR_ZERO_INIT);

.ROM_OS_OsTask_APP_VAR_FAST ROM(.OS_OsTask_APP_VAR_FAST) :> .
_ROM_OS_OsTask_APP_VAR_FAST_START = ADDR(.ROM_OS_OsTask_APP_VAR_FAST);
_ROM_OS_OsTask_APP_VAR_FAST_END = ENDADDR(.ROM_OS_OsTask_APP_VAR_FAST);

.ROM_OS_OsTask_APP_VAR_FAST_NOINIT ROM(.OS_OsTask_APP_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_APP_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_APP_VAR_FAST_NOINIT);
_ROM_OS_OsTask_APP_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_OsTask_APP_VAR_FAST_NOINIT);

.ROM_OS_OsTask_APP_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_APP_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_APP_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_APP_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_APP_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_OsTask_APP_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APP
# undef OS_LINK_CONST_TASK_OSTASK_APP
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APP_FAR
# undef OS_LINK_CONST_TASK_OSTASK_APP_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APP_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_APP_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APP_INIT
# undef OS_LINK_CONST_TASK_OSTASK_APP_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_FAR )
.OS_OsTask_BSW_SCHM_CONST ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_CONST_START = ADDR(.OS_OsTask_BSW_SCHM_CONST);
_OS_OsTask_BSW_SCHM_CONST_END = ENDADDR(.OS_OsTask_BSW_SCHM_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_NEAR )
.OS_OsTask_BSW_SCHM_CONST_FAST ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_CONST_FAST_START = ADDR(.OS_OsTask_BSW_SCHM_CONST_FAST);
_OS_OsTask_BSW_SCHM_CONST_FAST_END = ENDADDR(.OS_OsTask_BSW_SCHM_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_INIT )

.ROM_OS_OsTask_BSW_SCHM_VAR ROM(.OS_OsTask_BSW_SCHM_VAR) :> .
_ROM_OS_OsTask_BSW_SCHM_VAR_START = ADDR(.ROM_OS_OsTask_BSW_SCHM_VAR);
_ROM_OS_OsTask_BSW_SCHM_VAR_END = ENDADDR(.ROM_OS_OsTask_BSW_SCHM_VAR);

.ROM_OS_OsTask_BSW_SCHM_VAR_NOINIT ROM(.OS_OsTask_BSW_SCHM_VAR_NOINIT) :> .
_ROM_OS_OsTask_BSW_SCHM_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_NOINIT);
_ROM_OS_OsTask_BSW_SCHM_VAR_NOINIT_END = ENDADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_NOINIT);

.ROM_OS_OsTask_BSW_SCHM_VAR_ZERO_INIT ROM(.OS_OsTask_BSW_SCHM_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_BSW_SCHM_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_ZERO_INIT);
_ROM_OS_OsTask_BSW_SCHM_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_ZERO_INIT);

.ROM_OS_OsTask_BSW_SCHM_VAR_FAST ROM(.OS_OsTask_BSW_SCHM_VAR_FAST) :> .
_ROM_OS_OsTask_BSW_SCHM_VAR_FAST_START = ADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_FAST);
_ROM_OS_OsTask_BSW_SCHM_VAR_FAST_END = ENDADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_FAST);

.ROM_OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT ROM(.OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT);
_ROM_OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT);

.ROM_OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM
# undef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_FAR
# undef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_INIT
# undef OS_LINK_CONST_TASK_OSTASK_BSW_SCHM_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_CDD ) || defined ( OS_LINK_CONST_TASK_OSTASK_CDD_FAR )
.OS_OsTask_Cdd_CONST ALIGN(4) :> .
_OS_OsTask_Cdd_CONST_START = ADDR(.OS_OsTask_Cdd_CONST);
_OS_OsTask_Cdd_CONST_END = ENDADDR(.OS_OsTask_Cdd_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_CDD ) || defined ( OS_LINK_CONST_TASK_OSTASK_CDD_NEAR )
.OS_OsTask_Cdd_CONST_FAST ALIGN(4) :> .
_OS_OsTask_Cdd_CONST_FAST_START = ADDR(.OS_OsTask_Cdd_CONST_FAST);
_OS_OsTask_Cdd_CONST_FAST_END = ENDADDR(.OS_OsTask_Cdd_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_CDD ) || defined ( OS_LINK_CONST_TASK_OSTASK_CDD_INIT )

.ROM_OS_OsTask_Cdd_VAR ROM(.OS_OsTask_Cdd_VAR) :> .
_ROM_OS_OsTask_Cdd_VAR_START = ADDR(.ROM_OS_OsTask_Cdd_VAR);
_ROM_OS_OsTask_Cdd_VAR_END = ENDADDR(.ROM_OS_OsTask_Cdd_VAR);

.ROM_OS_OsTask_Cdd_VAR_NOINIT ROM(.OS_OsTask_Cdd_VAR_NOINIT) :> .
_ROM_OS_OsTask_Cdd_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_Cdd_VAR_NOINIT);
_ROM_OS_OsTask_Cdd_VAR_NOINIT_END = ENDADDR(.ROM_OS_OsTask_Cdd_VAR_NOINIT);

.ROM_OS_OsTask_Cdd_VAR_ZERO_INIT ROM(.OS_OsTask_Cdd_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_Cdd_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Cdd_VAR_ZERO_INIT);
_ROM_OS_OsTask_Cdd_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_OsTask_Cdd_VAR_ZERO_INIT);

.ROM_OS_OsTask_Cdd_VAR_FAST ROM(.OS_OsTask_Cdd_VAR_FAST) :> .
_ROM_OS_OsTask_Cdd_VAR_FAST_START = ADDR(.ROM_OS_OsTask_Cdd_VAR_FAST);
_ROM_OS_OsTask_Cdd_VAR_FAST_END = ENDADDR(.ROM_OS_OsTask_Cdd_VAR_FAST);

.ROM_OS_OsTask_Cdd_VAR_FAST_NOINIT ROM(.OS_OsTask_Cdd_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_Cdd_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_Cdd_VAR_FAST_NOINIT);
_ROM_OS_OsTask_Cdd_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_OsTask_Cdd_VAR_FAST_NOINIT);

.ROM_OS_OsTask_Cdd_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_Cdd_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_Cdd_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Cdd_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_Cdd_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_OsTask_Cdd_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_CDD
# undef OS_LINK_CONST_TASK_OSTASK_CDD
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_CDD_FAR
# undef OS_LINK_CONST_TASK_OSTASK_CDD_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_CDD_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_CDD_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_CDD_INIT
# undef OS_LINK_CONST_TASK_OSTASK_CDD_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRRXFIFO ) || defined ( OS_LINK_CONST_ISR_CANISRRXFIFO_FAR )
.OS_CanIsrRxFifo_CONST ALIGN(4) :> .
_OS_CanIsrRxFifo_CONST_START = ADDR(.OS_CanIsrRxFifo_CONST);
_OS_CanIsrRxFifo_CONST_END = ENDADDR(.OS_CanIsrRxFifo_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRRXFIFO ) || defined ( OS_LINK_CONST_ISR_CANISRRXFIFO_NEAR )
.OS_CanIsrRxFifo_CONST_FAST ALIGN(4) :> .
_OS_CanIsrRxFifo_CONST_FAST_START = ADDR(.OS_CanIsrRxFifo_CONST_FAST);
_OS_CanIsrRxFifo_CONST_FAST_END = ENDADDR(.OS_CanIsrRxFifo_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRRXFIFO ) || defined ( OS_LINK_CONST_ISR_CANISRRXFIFO_INIT )

.ROM_OS_CanIsrRxFifo_VAR ROM(.OS_CanIsrRxFifo_VAR) :> .
_ROM_OS_CanIsrRxFifo_VAR_START = ADDR(.ROM_OS_CanIsrRxFifo_VAR);
_ROM_OS_CanIsrRxFifo_VAR_END = ENDADDR(.ROM_OS_CanIsrRxFifo_VAR);

.ROM_OS_CanIsrRxFifo_VAR_NOINIT ROM(.OS_CanIsrRxFifo_VAR_NOINIT) :> .
_ROM_OS_CanIsrRxFifo_VAR_NOINIT_START = ADDR(.ROM_OS_CanIsrRxFifo_VAR_NOINIT);
_ROM_OS_CanIsrRxFifo_VAR_NOINIT_END = ENDADDR(.ROM_OS_CanIsrRxFifo_VAR_NOINIT);

.ROM_OS_CanIsrRxFifo_VAR_ZERO_INIT ROM(.OS_CanIsrRxFifo_VAR_ZERO_INIT) :> .
_ROM_OS_CanIsrRxFifo_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrRxFifo_VAR_ZERO_INIT);
_ROM_OS_CanIsrRxFifo_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_CanIsrRxFifo_VAR_ZERO_INIT);

.ROM_OS_CanIsrRxFifo_VAR_FAST ROM(.OS_CanIsrRxFifo_VAR_FAST) :> .
_ROM_OS_CanIsrRxFifo_VAR_FAST_START = ADDR(.ROM_OS_CanIsrRxFifo_VAR_FAST);
_ROM_OS_CanIsrRxFifo_VAR_FAST_END = ENDADDR(.ROM_OS_CanIsrRxFifo_VAR_FAST);

.ROM_OS_CanIsrRxFifo_VAR_FAST_NOINIT ROM(.OS_CanIsrRxFifo_VAR_FAST_NOINIT) :> .
_ROM_OS_CanIsrRxFifo_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CanIsrRxFifo_VAR_FAST_NOINIT);
_ROM_OS_CanIsrRxFifo_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_CanIsrRxFifo_VAR_FAST_NOINIT);

.ROM_OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT ROM(.OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT);
_ROM_OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_ISR_CANISRRXFIFO
# undef OS_LINK_CONST_ISR_CANISRRXFIFO
#endif

#ifdef OS_LINK_CONST_ISR_CANISRRXFIFO_FAR
# undef OS_LINK_CONST_ISR_CANISRRXFIFO_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRRXFIFO_NEAR
# undef OS_LINK_CONST_ISR_CANISRRXFIFO_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRRXFIFO_INIT
# undef OS_LINK_CONST_ISR_CANISRRXFIFO_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_3_FAR )
.OS_CanIsrStatus_3_CONST ALIGN(4) :> .
_OS_CanIsrStatus_3_CONST_START = ADDR(.OS_CanIsrStatus_3_CONST);
_OS_CanIsrStatus_3_CONST_END = ENDADDR(.OS_CanIsrStatus_3_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_3_NEAR )
.OS_CanIsrStatus_3_CONST_FAST ALIGN(4) :> .
_OS_CanIsrStatus_3_CONST_FAST_START = ADDR(.OS_CanIsrStatus_3_CONST_FAST);
_OS_CanIsrStatus_3_CONST_FAST_END = ENDADDR(.OS_CanIsrStatus_3_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_3_INIT )

.ROM_OS_CanIsrStatus_3_VAR ROM(.OS_CanIsrStatus_3_VAR) :> .
_ROM_OS_CanIsrStatus_3_VAR_START = ADDR(.ROM_OS_CanIsrStatus_3_VAR);
_ROM_OS_CanIsrStatus_3_VAR_END = ENDADDR(.ROM_OS_CanIsrStatus_3_VAR);

.ROM_OS_CanIsrStatus_3_VAR_NOINIT ROM(.OS_CanIsrStatus_3_VAR_NOINIT) :> .
_ROM_OS_CanIsrStatus_3_VAR_NOINIT_START = ADDR(.ROM_OS_CanIsrStatus_3_VAR_NOINIT);
_ROM_OS_CanIsrStatus_3_VAR_NOINIT_END = ENDADDR(.ROM_OS_CanIsrStatus_3_VAR_NOINIT);

.ROM_OS_CanIsrStatus_3_VAR_ZERO_INIT ROM(.OS_CanIsrStatus_3_VAR_ZERO_INIT) :> .
_ROM_OS_CanIsrStatus_3_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrStatus_3_VAR_ZERO_INIT);
_ROM_OS_CanIsrStatus_3_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_CanIsrStatus_3_VAR_ZERO_INIT);

.ROM_OS_CanIsrStatus_3_VAR_FAST ROM(.OS_CanIsrStatus_3_VAR_FAST) :> .
_ROM_OS_CanIsrStatus_3_VAR_FAST_START = ADDR(.ROM_OS_CanIsrStatus_3_VAR_FAST);
_ROM_OS_CanIsrStatus_3_VAR_FAST_END = ENDADDR(.ROM_OS_CanIsrStatus_3_VAR_FAST);

.ROM_OS_CanIsrStatus_3_VAR_FAST_NOINIT ROM(.OS_CanIsrStatus_3_VAR_FAST_NOINIT) :> .
_ROM_OS_CanIsrStatus_3_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CanIsrStatus_3_VAR_FAST_NOINIT);
_ROM_OS_CanIsrStatus_3_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_CanIsrStatus_3_VAR_FAST_NOINIT);

.ROM_OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT ROM(.OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT);
_ROM_OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_3
# undef OS_LINK_CONST_ISR_CANISRSTATUS_3
#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_3_FAR
# undef OS_LINK_CONST_ISR_CANISRSTATUS_3_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_3_NEAR
# undef OS_LINK_CONST_ISR_CANISRSTATUS_3_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_3_INIT
# undef OS_LINK_CONST_ISR_CANISRSTATUS_3_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRTX_3 ) || defined ( OS_LINK_CONST_ISR_CANISRTX_3_FAR )
.OS_CanIsrTx_3_CONST ALIGN(4) :> .
_OS_CanIsrTx_3_CONST_START = ADDR(.OS_CanIsrTx_3_CONST);
_OS_CanIsrTx_3_CONST_END = ENDADDR(.OS_CanIsrTx_3_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRTX_3 ) || defined ( OS_LINK_CONST_ISR_CANISRTX_3_NEAR )
.OS_CanIsrTx_3_CONST_FAST ALIGN(4) :> .
_OS_CanIsrTx_3_CONST_FAST_START = ADDR(.OS_CanIsrTx_3_CONST_FAST);
_OS_CanIsrTx_3_CONST_FAST_END = ENDADDR(.OS_CanIsrTx_3_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRTX_3 ) || defined ( OS_LINK_CONST_ISR_CANISRTX_3_INIT )

.ROM_OS_CanIsrTx_3_VAR ROM(.OS_CanIsrTx_3_VAR) :> .
_ROM_OS_CanIsrTx_3_VAR_START = ADDR(.ROM_OS_CanIsrTx_3_VAR);
_ROM_OS_CanIsrTx_3_VAR_END = ENDADDR(.ROM_OS_CanIsrTx_3_VAR);

.ROM_OS_CanIsrTx_3_VAR_NOINIT ROM(.OS_CanIsrTx_3_VAR_NOINIT) :> .
_ROM_OS_CanIsrTx_3_VAR_NOINIT_START = ADDR(.ROM_OS_CanIsrTx_3_VAR_NOINIT);
_ROM_OS_CanIsrTx_3_VAR_NOINIT_END = ENDADDR(.ROM_OS_CanIsrTx_3_VAR_NOINIT);

.ROM_OS_CanIsrTx_3_VAR_ZERO_INIT ROM(.OS_CanIsrTx_3_VAR_ZERO_INIT) :> .
_ROM_OS_CanIsrTx_3_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrTx_3_VAR_ZERO_INIT);
_ROM_OS_CanIsrTx_3_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_CanIsrTx_3_VAR_ZERO_INIT);

.ROM_OS_CanIsrTx_3_VAR_FAST ROM(.OS_CanIsrTx_3_VAR_FAST) :> .
_ROM_OS_CanIsrTx_3_VAR_FAST_START = ADDR(.ROM_OS_CanIsrTx_3_VAR_FAST);
_ROM_OS_CanIsrTx_3_VAR_FAST_END = ENDADDR(.ROM_OS_CanIsrTx_3_VAR_FAST);

.ROM_OS_CanIsrTx_3_VAR_FAST_NOINIT ROM(.OS_CanIsrTx_3_VAR_FAST_NOINIT) :> .
_ROM_OS_CanIsrTx_3_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CanIsrTx_3_VAR_FAST_NOINIT);
_ROM_OS_CanIsrTx_3_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_CanIsrTx_3_VAR_FAST_NOINIT);

.ROM_OS_CanIsrTx_3_VAR_FAST_ZERO_INIT ROM(.OS_CanIsrTx_3_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CanIsrTx_3_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrTx_3_VAR_FAST_ZERO_INIT);
_ROM_OS_CanIsrTx_3_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_CanIsrTx_3_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_3
# undef OS_LINK_CONST_ISR_CANISRTX_3
#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_3_FAR
# undef OS_LINK_CONST_ISR_CANISRTX_3_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_3_NEAR
# undef OS_LINK_CONST_ISR_CANISRTX_3_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_3_INIT
# undef OS_LINK_CONST_ISR_CANISRTX_3_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR )
.OS_CounterIsr_SystemTimer_CONST ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_CONST_START = ADDR(.OS_CounterIsr_SystemTimer_CONST);
_OS_CounterIsr_SystemTimer_CONST_END = ENDADDR(.OS_CounterIsr_SystemTimer_CONST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR )
.OS_CounterIsr_SystemTimer_CONST_FAST ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_CONST_FAST_START = ADDR(.OS_CounterIsr_SystemTimer_CONST_FAST);
_OS_CounterIsr_SystemTimer_CONST_FAST_END = ENDADDR(.OS_CounterIsr_SystemTimer_CONST_FAST) - 1;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT )

.ROM_OS_CounterIsr_SystemTimer_VAR ROM(.OS_CounterIsr_SystemTimer_VAR) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR);
_ROM_OS_CounterIsr_SystemTimer_VAR_END = ENDADDR(.ROM_OS_CounterIsr_SystemTimer_VAR);

.ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT ROM(.OS_CounterIsr_SystemTimer_VAR_NOINIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_END = ENDADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT);

.ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT ROM(.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END = ENDADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT);

.ROM_OS_CounterIsr_SystemTimer_VAR_FAST ROM(.OS_CounterIsr_SystemTimer_VAR_FAST) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST);
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_END = ENDADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST);

.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT ROM(.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END = ENDADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT);

.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT ROM(.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END = ENDADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT);

#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
#endif



#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_APP
# undef OS_LINK_CONST_APP
#endif

#ifdef OS_LINK_CONST_TASK
# undef OS_LINK_CONST_TASK
#endif

#ifdef OS_LINK_CONST_ISR
# undef OS_LINK_CONST_ISR
#endif

#ifdef OS_LINK_CONST_KERNEL
# undef OS_LINK_CONST_KERNEL
#endif

#ifdef OS_LINK_CONST_KERNEL_FAR
# undef OS_LINK_CONST_KERNEL_FAR
#endif

#ifdef OS_LINK_CONST_KERNEL_NEAR
# undef OS_LINK_CONST_KERNEL_NEAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif

#ifdef OS_LINK_EXCVEC_CONST
# undef OS_LINK_EXCVEC_CONST
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_INIT )
.OS_CORE0_VAR ALIGN(4) :> .
_OS_CORE0_VAR_START = ADDR(.OS_CORE0_VAR);
_OS_CORE0_VAR_END = ENDADDR(.OS_CORE0_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT )
.OS_CORE0_VAR_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_NOINIT_START = ADDR(.OS_CORE0_VAR_NOINIT);
_OS_CORE0_VAR_NOINIT_END = ENDADDR(.OS_CORE0_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT )
.OS_CORE0_VAR_FAST ALIGN(4) :> .
_OS_CORE0_VAR_FAST_START = ADDR(.OS_CORE0_VAR_FAST);
_OS_CORE0_VAR_FAST_END = ENDADDR(.OS_CORE0_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT )
.OS_CORE0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_FAST_NOINIT_START = ADDR(.OS_CORE0_VAR_FAST_NOINIT);
_OS_CORE0_VAR_FAST_NOINIT_END = ENDADDR(.OS_CORE0_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT )
.OS_CORE0_VAR_NOCACHE ALIGN(4) :> .
_OS_CORE0_VAR_NOCACHE_START = ADDR(.OS_CORE0_VAR_NOCACHE);
_OS_CORE0_VAR_NOCACHE_END = ENDADDR(.OS_CORE0_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT )
.OS_CORE0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CORE0_VAR_NOCACHE_NOINIT);
_OS_CORE0_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_CORE0_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT )
.OS_CORE0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CORE0_VAR_FAST_NOCACHE_START = ADDR(.OS_CORE0_VAR_FAST_NOCACHE);
_OS_CORE0_VAR_FAST_NOCACHE_END = ENDADDR(.OS_CORE0_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT )
.OS_CORE0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CORE0_VAR_FAST_NOCACHE_NOINIT);
_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_CORE0_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_FAR )
.OS_PUBLIC_CORE0_VAR_NOINIT ALIGN(4) :> .
_OS_PUBLIC_CORE0_VAR_NOINIT_START = ADDR(.OS_PUBLIC_CORE0_VAR_NOINIT);
_OS_PUBLIC_CORE0_VAR_NOINIT_END = ENDADDR(.OS_PUBLIC_CORE0_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_NEAR )
.OS_PUBLIC_CORE0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START = ADDR(.OS_PUBLIC_CORE0_VAR_FAST_NOINIT);
_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END = ENDADDR(.OS_PUBLIC_CORE0_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_FAR )
.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT);
_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_NEAR )
.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT);
_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_FAR )
.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT);
_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_NEAR )
.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT);
_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif


#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_ALL_START = .;
__OS_SystemApplication_OsCore0_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT )
.OS_SystemApplication_OsCore0_VAR ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_START = ADDR(.OS_SystemApplication_OsCore0_VAR);
_OS_SystemApplication_OsCore0_VAR_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOINIT);
_OS_SystemApplication_OsCore0_VAR_NOINIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_ZERO_INIT);
_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST);
_OS_SystemApplication_OsCore0_VAR_FAST_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT);
_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT);
_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT )
.OS_SystemApplication_OsCore0_VAR_NOCACHE ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_NOCACHE_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE);
_OS_SystemApplication_OsCore0_VAR_NOCACHE_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT);
_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT);
_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE);
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT);
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_ALL_END = .-1;
__OS_SystemApplication_OsCore0_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK
. = ALIGN(4);
_OS_BrsMainBackgroundTask_VAR_ALL_START = .;
__OS_BrsMainBackgroundTask_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_INIT )
.OS_BrsMainBackgroundTask_VAR ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_START = ADDR(.OS_BrsMainBackgroundTask_VAR);
_OS_BrsMainBackgroundTask_VAR_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_NOINIT )
.OS_BrsMainBackgroundTask_VAR_NOINIT ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_NOINIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_NOINIT);
_OS_BrsMainBackgroundTask_VAR_NOINIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_ZERO_INIT )
.OS_BrsMainBackgroundTask_VAR_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainBackgroundTask_VAR_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainBackgroundTask_VAR_ZERO_INIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_ZERO_INIT);
_OS_BrsMainBackgroundTask_VAR_ZERO_INIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_INIT )
.OS_BrsMainBackgroundTask_VAR_FAST ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_FAST_START = ADDR(.OS_BrsMainBackgroundTask_VAR_FAST);
_OS_BrsMainBackgroundTask_VAR_FAST_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_NOINIT )
.OS_BrsMainBackgroundTask_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_FAST_NOINIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOINIT);
_OS_BrsMainBackgroundTask_VAR_FAST_NOINIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_ZERO_INIT )
.OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT);
_OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_INIT )
.OS_BrsMainBackgroundTask_VAR_NOCACHE ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_NOCACHE_START = ADDR(.OS_BrsMainBackgroundTask_VAR_NOCACHE);
_OS_BrsMainBackgroundTask_VAR_NOCACHE_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_NOINIT )
.OS_BrsMainBackgroundTask_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_NOCACHE_NOINIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_NOCACHE_NOINIT);
_OS_BrsMainBackgroundTask_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_ZERO_INIT )
.OS_BrsMainBackgroundTask_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainBackgroundTask_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainBackgroundTask_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_NOCACHE_ZERO_INIT);
_OS_BrsMainBackgroundTask_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_INIT )
.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_START = ADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE);
_OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_NOINIT )
.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_NOINIT);
_OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_ZERO_INIT )
.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_BrsMainBackgroundTask_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK
. = ALIGN(4);
_OS_BrsMainBackgroundTask_VAR_ALL_END = .-1;
__OS_BrsMainBackgroundTask_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINBACKGROUNDTASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_BRSMAINTASK
. = ALIGN(4);
_OS_BrsMainTask_VAR_ALL_START = .;
__OS_BrsMainTask_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_INIT )
.OS_BrsMainTask_VAR ALIGN(4) :> .
_OS_BrsMainTask_VAR_START = ADDR(.OS_BrsMainTask_VAR);
_OS_BrsMainTask_VAR_END = ENDADDR(.OS_BrsMainTask_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_NOINIT )
.OS_BrsMainTask_VAR_NOINIT ALIGN(4) :> .
_OS_BrsMainTask_VAR_NOINIT_START = ADDR(.OS_BrsMainTask_VAR_NOINIT);
_OS_BrsMainTask_VAR_NOINIT_END = ENDADDR(.OS_BrsMainTask_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_ZERO_INIT )
.OS_BrsMainTask_VAR_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainTask_VAR_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainTask_VAR_ZERO_INIT_START = ADDR(.OS_BrsMainTask_VAR_ZERO_INIT);
_OS_BrsMainTask_VAR_ZERO_INIT_END = ENDADDR(.OS_BrsMainTask_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_INIT )
.OS_BrsMainTask_VAR_FAST ALIGN(4) :> .
_OS_BrsMainTask_VAR_FAST_START = ADDR(.OS_BrsMainTask_VAR_FAST);
_OS_BrsMainTask_VAR_FAST_END = ENDADDR(.OS_BrsMainTask_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_NOINIT )
.OS_BrsMainTask_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_BrsMainTask_VAR_FAST_NOINIT_START = ADDR(.OS_BrsMainTask_VAR_FAST_NOINIT);
_OS_BrsMainTask_VAR_FAST_NOINIT_END = ENDADDR(.OS_BrsMainTask_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_ZERO_INIT )
.OS_BrsMainTask_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainTask_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainTask_VAR_FAST_ZERO_INIT_START = ADDR(.OS_BrsMainTask_VAR_FAST_ZERO_INIT);
_OS_BrsMainTask_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_BrsMainTask_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_INIT )
.OS_BrsMainTask_VAR_NOCACHE ALIGN(4) :> .
_OS_BrsMainTask_VAR_NOCACHE_START = ADDR(.OS_BrsMainTask_VAR_NOCACHE);
_OS_BrsMainTask_VAR_NOCACHE_END = ENDADDR(.OS_BrsMainTask_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_NOINIT )
.OS_BrsMainTask_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BrsMainTask_VAR_NOCACHE_NOINIT_START = ADDR(.OS_BrsMainTask_VAR_NOCACHE_NOINIT);
_OS_BrsMainTask_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_BrsMainTask_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_ZERO_INIT )
.OS_BrsMainTask_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainTask_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainTask_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_BrsMainTask_VAR_NOCACHE_ZERO_INIT);
_OS_BrsMainTask_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_BrsMainTask_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_INIT )
.OS_BrsMainTask_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_BrsMainTask_VAR_FAST_NOCACHE_START = ADDR(.OS_BrsMainTask_VAR_FAST_NOCACHE);
_OS_BrsMainTask_VAR_FAST_NOCACHE_END = ENDADDR(.OS_BrsMainTask_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_NOINIT )
.OS_BrsMainTask_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BrsMainTask_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_BrsMainTask_VAR_FAST_NOCACHE_NOINIT);
_OS_BrsMainTask_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_BrsMainTask_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_ZERO_INIT )
.OS_BrsMainTask_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_BrsMainTask_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_BrsMainTask_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_BrsMainTask_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_BrsMainTask_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_BrsMainTask_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK
. = ALIGN(4);
_OS_BrsMainTask_VAR_ALL_END = .-1;
__OS_BrsMainTask_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_TASK_BRSMAINTASK
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BRSMAINTASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
. = ALIGN(4);
_OS_Default_Init_Task_VAR_ALL_START = .;
__OS_Default_Init_Task_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT )
.OS_Default_Init_Task_VAR ALIGN(4) :> .
_OS_Default_Init_Task_VAR_START = ADDR(.OS_Default_Init_Task_VAR);
_OS_Default_Init_Task_VAR_END = ENDADDR(.OS_Default_Init_Task_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT )
.OS_Default_Init_Task_VAR_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_NOINIT);
_OS_Default_Init_Task_VAR_NOINIT_END = ENDADDR(.OS_Default_Init_Task_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_ZERO_INIT);
_OS_Default_Init_Task_VAR_ZERO_INIT_END = ENDADDR(.OS_Default_Init_Task_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT )
.OS_Default_Init_Task_VAR_FAST ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_START = ADDR(.OS_Default_Init_Task_VAR_FAST);
_OS_Default_Init_Task_VAR_FAST_END = ENDADDR(.OS_Default_Init_Task_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT )
.OS_Default_Init_Task_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOINIT);
_OS_Default_Init_Task_VAR_FAST_NOINIT_END = ENDADDR(.OS_Default_Init_Task_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_ZERO_INIT);
_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_Default_Init_Task_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT )
.OS_Default_Init_Task_VAR_NOCACHE ALIGN(4) :> .
_OS_Default_Init_Task_VAR_NOCACHE_START = ADDR(.OS_Default_Init_Task_VAR_NOCACHE);
_OS_Default_Init_Task_VAR_NOCACHE_END = ENDADDR(.OS_Default_Init_Task_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT )
.OS_Default_Init_Task_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_NOCACHE_NOINIT);
_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_Default_Init_Task_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT);
_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT )
.OS_Default_Init_Task_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_NOCACHE_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE);
_OS_Default_Init_Task_VAR_FAST_NOCACHE_END = ENDADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT )
.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT);
_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
. = ALIGN(4);
_OS_Default_Init_Task_VAR_ALL_END = .-1;
__OS_Default_Init_Task_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_ALL_START = .;
__OS_IdleTask_OsCore0_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT )
.OS_IdleTask_OsCore0_VAR ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_START = ADDR(.OS_IdleTask_OsCore0_VAR);
_OS_IdleTask_OsCore0_VAR_END = ENDADDR(.OS_IdleTask_OsCore0_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOINIT);
_OS_IdleTask_OsCore0_VAR_NOINIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_ZERO_INIT);
_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT )
.OS_IdleTask_OsCore0_VAR_FAST ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST);
_OS_IdleTask_OsCore0_VAR_FAST_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOINIT);
_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT);
_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT )
.OS_IdleTask_OsCore0_VAR_NOCACHE ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_NOCACHE_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE);
_OS_IdleTask_OsCore0_VAR_NOCACHE_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT);
_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT);
_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE);
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT);
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_ALL_END = .-1;
__OS_IdleTask_OsCore0_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_APP
. = ALIGN(4);
_OS_OsTask_APP_VAR_ALL_START = .;
__OS_OsTask_APP_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_INIT )
.OS_OsTask_APP_VAR ALIGN(4) :> .
_OS_OsTask_APP_VAR_START = ADDR(.OS_OsTask_APP_VAR);
_OS_OsTask_APP_VAR_END = ENDADDR(.OS_OsTask_APP_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_NOINIT )
.OS_OsTask_APP_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_APP_VAR_NOINIT_START = ADDR(.OS_OsTask_APP_VAR_NOINIT);
_OS_OsTask_APP_VAR_NOINIT_END = ENDADDR(.OS_OsTask_APP_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_ZERO_INIT )
.OS_OsTask_APP_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_APP_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_APP_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_APP_VAR_ZERO_INIT);
_OS_OsTask_APP_VAR_ZERO_INIT_END = ENDADDR(.OS_OsTask_APP_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_INIT )
.OS_OsTask_APP_VAR_FAST ALIGN(4) :> .
_OS_OsTask_APP_VAR_FAST_START = ADDR(.OS_OsTask_APP_VAR_FAST);
_OS_OsTask_APP_VAR_FAST_END = ENDADDR(.OS_OsTask_APP_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_NOINIT )
.OS_OsTask_APP_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_APP_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_APP_VAR_FAST_NOINIT);
_OS_OsTask_APP_VAR_FAST_NOINIT_END = ENDADDR(.OS_OsTask_APP_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_APP_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_APP_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_APP_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_APP_VAR_FAST_ZERO_INIT);
_OS_OsTask_APP_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_OsTask_APP_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_INIT )
.OS_OsTask_APP_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_APP_VAR_NOCACHE_START = ADDR(.OS_OsTask_APP_VAR_NOCACHE);
_OS_OsTask_APP_VAR_NOCACHE_END = ENDADDR(.OS_OsTask_APP_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_NOINIT )
.OS_OsTask_APP_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_APP_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_APP_VAR_NOCACHE_NOINIT);
_OS_OsTask_APP_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_OsTask_APP_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_APP_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_APP_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_APP_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_APP_VAR_NOCACHE_ZERO_INIT);
_OS_OsTask_APP_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_OsTask_APP_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_INIT )
.OS_OsTask_APP_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_APP_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_APP_VAR_FAST_NOCACHE);
_OS_OsTask_APP_VAR_FAST_NOCACHE_END = ENDADDR(.OS_OsTask_APP_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_NOINIT )
.OS_OsTask_APP_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_APP_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_APP_VAR_FAST_NOCACHE_NOINIT);
_OS_OsTask_APP_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_OsTask_APP_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_APP_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_APP_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_APP_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_APP_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_OsTask_APP_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_OsTask_APP_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP
. = ALIGN(4);
_OS_OsTask_APP_VAR_ALL_END = .-1;
__OS_OsTask_APP_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_TASK_OSTASK_APP
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APP_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM
. = ALIGN(4);
_OS_OsTask_BSW_SCHM_VAR_ALL_START = .;
__OS_OsTask_BSW_SCHM_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_INIT )
.OS_OsTask_BSW_SCHM_VAR ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_START = ADDR(.OS_OsTask_BSW_SCHM_VAR);
_OS_OsTask_BSW_SCHM_VAR_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_NOINIT )
.OS_OsTask_BSW_SCHM_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_NOINIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_NOINIT);
_OS_OsTask_BSW_SCHM_VAR_NOINIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_ZERO_INIT )
.OS_OsTask_BSW_SCHM_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BSW_SCHM_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BSW_SCHM_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_ZERO_INIT);
_OS_OsTask_BSW_SCHM_VAR_ZERO_INIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_INIT )
.OS_OsTask_BSW_SCHM_VAR_FAST ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_FAST_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_FAST);
_OS_OsTask_BSW_SCHM_VAR_FAST_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_NOINIT )
.OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT);
_OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT);
_OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_INIT )
.OS_OsTask_BSW_SCHM_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_NOCACHE_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_NOCACHE);
_OS_OsTask_BSW_SCHM_VAR_NOCACHE_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_NOINIT )
.OS_OsTask_BSW_SCHM_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_NOCACHE_NOINIT);
_OS_OsTask_BSW_SCHM_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_BSW_SCHM_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BSW_SCHM_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BSW_SCHM_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_NOCACHE_ZERO_INIT);
_OS_OsTask_BSW_SCHM_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_INIT )
.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE);
_OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_NOINIT )
.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_NOINIT);
_OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_OsTask_BSW_SCHM_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM
. = ALIGN(4);
_OS_OsTask_BSW_SCHM_VAR_ALL_END = .-1;
__OS_OsTask_BSW_SCHM_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSW_SCHM_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_CDD
. = ALIGN(4);
_OS_OsTask_Cdd_VAR_ALL_START = .;
__OS_OsTask_Cdd_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_INIT )
.OS_OsTask_Cdd_VAR ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_START = ADDR(.OS_OsTask_Cdd_VAR);
_OS_OsTask_Cdd_VAR_END = ENDADDR(.OS_OsTask_Cdd_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_NOINIT )
.OS_OsTask_Cdd_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_NOINIT_START = ADDR(.OS_OsTask_Cdd_VAR_NOINIT);
_OS_OsTask_Cdd_VAR_NOINIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_ZERO_INIT )
.OS_OsTask_Cdd_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Cdd_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Cdd_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_Cdd_VAR_ZERO_INIT);
_OS_OsTask_Cdd_VAR_ZERO_INIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_INIT )
.OS_OsTask_Cdd_VAR_FAST ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_FAST_START = ADDR(.OS_OsTask_Cdd_VAR_FAST);
_OS_OsTask_Cdd_VAR_FAST_END = ENDADDR(.OS_OsTask_Cdd_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_NOINIT )
.OS_OsTask_Cdd_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_Cdd_VAR_FAST_NOINIT);
_OS_OsTask_Cdd_VAR_FAST_NOINIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_Cdd_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Cdd_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Cdd_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_Cdd_VAR_FAST_ZERO_INIT);
_OS_OsTask_Cdd_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_INIT )
.OS_OsTask_Cdd_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_NOCACHE_START = ADDR(.OS_OsTask_Cdd_VAR_NOCACHE);
_OS_OsTask_Cdd_VAR_NOCACHE_END = ENDADDR(.OS_OsTask_Cdd_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_NOINIT )
.OS_OsTask_Cdd_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Cdd_VAR_NOCACHE_NOINIT);
_OS_OsTask_Cdd_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Cdd_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Cdd_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Cdd_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Cdd_VAR_NOCACHE_ZERO_INIT);
_OS_OsTask_Cdd_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_INIT )
.OS_OsTask_Cdd_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_Cdd_VAR_FAST_NOCACHE);
_OS_OsTask_Cdd_VAR_FAST_NOCACHE_END = ENDADDR(.OS_OsTask_Cdd_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_NOINIT )
.OS_OsTask_Cdd_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Cdd_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Cdd_VAR_FAST_NOCACHE_NOINIT);
_OS_OsTask_Cdd_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Cdd_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Cdd_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Cdd_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Cdd_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_OsTask_Cdd_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_OsTask_Cdd_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD
. = ALIGN(4);
_OS_OsTask_Cdd_VAR_ALL_END = .-1;
__OS_OsTask_Cdd_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_TASK_OSTASK_CDD
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_CDD_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO
. = ALIGN(4);
_OS_CanIsrRxFifo_VAR_ALL_START = .;
__OS_CanIsrRxFifo_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_INIT )
.OS_CanIsrRxFifo_VAR ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_START = ADDR(.OS_CanIsrRxFifo_VAR);
_OS_CanIsrRxFifo_VAR_END = ENDADDR(.OS_CanIsrRxFifo_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_NOINIT )
.OS_CanIsrRxFifo_VAR_NOINIT ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_NOINIT_START = ADDR(.OS_CanIsrRxFifo_VAR_NOINIT);
_OS_CanIsrRxFifo_VAR_NOINIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_ZERO_INIT )
.OS_CanIsrRxFifo_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrRxFifo_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrRxFifo_VAR_ZERO_INIT_START = ADDR(.OS_CanIsrRxFifo_VAR_ZERO_INIT);
_OS_CanIsrRxFifo_VAR_ZERO_INIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_INIT )
.OS_CanIsrRxFifo_VAR_FAST ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_FAST_START = ADDR(.OS_CanIsrRxFifo_VAR_FAST);
_OS_CanIsrRxFifo_VAR_FAST_END = ENDADDR(.OS_CanIsrRxFifo_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_NOINIT )
.OS_CanIsrRxFifo_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_FAST_NOINIT_START = ADDR(.OS_CanIsrRxFifo_VAR_FAST_NOINIT);
_OS_CanIsrRxFifo_VAR_FAST_NOINIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_ZERO_INIT )
.OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT);
_OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_INIT )
.OS_CanIsrRxFifo_VAR_NOCACHE ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_NOCACHE_START = ADDR(.OS_CanIsrRxFifo_VAR_NOCACHE);
_OS_CanIsrRxFifo_VAR_NOCACHE_END = ENDADDR(.OS_CanIsrRxFifo_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_NOINIT )
.OS_CanIsrRxFifo_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrRxFifo_VAR_NOCACHE_NOINIT);
_OS_CanIsrRxFifo_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_ZERO_INIT )
.OS_CanIsrRxFifo_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrRxFifo_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrRxFifo_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrRxFifo_VAR_NOCACHE_ZERO_INIT);
_OS_CanIsrRxFifo_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_INIT )
.OS_CanIsrRxFifo_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_FAST_NOCACHE_START = ADDR(.OS_CanIsrRxFifo_VAR_FAST_NOCACHE);
_OS_CanIsrRxFifo_VAR_FAST_NOCACHE_END = ENDADDR(.OS_CanIsrRxFifo_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_NOINIT )
.OS_CanIsrRxFifo_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrRxFifo_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrRxFifo_VAR_FAST_NOCACHE_NOINIT);
_OS_CanIsrRxFifo_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_ZERO_INIT )
.OS_CanIsrRxFifo_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrRxFifo_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrRxFifo_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrRxFifo_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_CanIsrRxFifo_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CanIsrRxFifo_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO
. = ALIGN(4);
_OS_CanIsrRxFifo_VAR_ALL_END = .-1;
__OS_CanIsrRxFifo_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_ISR_CANISRRXFIFO
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRRXFIFO_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3
. = ALIGN(4);
_OS_CanIsrStatus_3_VAR_ALL_START = .;
__OS_CanIsrStatus_3_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_INIT )
.OS_CanIsrStatus_3_VAR ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_START = ADDR(.OS_CanIsrStatus_3_VAR);
_OS_CanIsrStatus_3_VAR_END = ENDADDR(.OS_CanIsrStatus_3_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_NOINIT )
.OS_CanIsrStatus_3_VAR_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_NOINIT_START = ADDR(.OS_CanIsrStatus_3_VAR_NOINIT);
_OS_CanIsrStatus_3_VAR_NOINIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_ZERO_INIT )
.OS_CanIsrStatus_3_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_3_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_3_VAR_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_3_VAR_ZERO_INIT);
_OS_CanIsrStatus_3_VAR_ZERO_INIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_INIT )
.OS_CanIsrStatus_3_VAR_FAST ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_FAST_START = ADDR(.OS_CanIsrStatus_3_VAR_FAST);
_OS_CanIsrStatus_3_VAR_FAST_END = ENDADDR(.OS_CanIsrStatus_3_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_NOINIT )
.OS_CanIsrStatus_3_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_FAST_NOINIT_START = ADDR(.OS_CanIsrStatus_3_VAR_FAST_NOINIT);
_OS_CanIsrStatus_3_VAR_FAST_NOINIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_ZERO_INIT )
.OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT);
_OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_INIT )
.OS_CanIsrStatus_3_VAR_NOCACHE ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_NOCACHE_START = ADDR(.OS_CanIsrStatus_3_VAR_NOCACHE);
_OS_CanIsrStatus_3_VAR_NOCACHE_END = ENDADDR(.OS_CanIsrStatus_3_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_NOINIT )
.OS_CanIsrStatus_3_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrStatus_3_VAR_NOCACHE_NOINIT);
_OS_CanIsrStatus_3_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_ZERO_INIT )
.OS_CanIsrStatus_3_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_3_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_3_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_3_VAR_NOCACHE_ZERO_INIT);
_OS_CanIsrStatus_3_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_INIT )
.OS_CanIsrStatus_3_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_FAST_NOCACHE_START = ADDR(.OS_CanIsrStatus_3_VAR_FAST_NOCACHE);
_OS_CanIsrStatus_3_VAR_FAST_NOCACHE_END = ENDADDR(.OS_CanIsrStatus_3_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_NOINIT )
.OS_CanIsrStatus_3_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_3_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrStatus_3_VAR_FAST_NOCACHE_NOINIT);
_OS_CanIsrStatus_3_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_ZERO_INIT )
.OS_CanIsrStatus_3_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_3_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_3_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_3_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_CanIsrStatus_3_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CanIsrStatus_3_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3
. = ALIGN(4);
_OS_CanIsrStatus_3_VAR_ALL_END = .-1;
__OS_CanIsrStatus_3_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_3_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISRTX_3
. = ALIGN(4);
_OS_CanIsrTx_3_VAR_ALL_START = .;
__OS_CanIsrTx_3_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_INIT )
.OS_CanIsrTx_3_VAR ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_START = ADDR(.OS_CanIsrTx_3_VAR);
_OS_CanIsrTx_3_VAR_END = ENDADDR(.OS_CanIsrTx_3_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_NOINIT )
.OS_CanIsrTx_3_VAR_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_NOINIT_START = ADDR(.OS_CanIsrTx_3_VAR_NOINIT);
_OS_CanIsrTx_3_VAR_NOINIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_ZERO_INIT )
.OS_CanIsrTx_3_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_3_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_3_VAR_ZERO_INIT_START = ADDR(.OS_CanIsrTx_3_VAR_ZERO_INIT);
_OS_CanIsrTx_3_VAR_ZERO_INIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_INIT )
.OS_CanIsrTx_3_VAR_FAST ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_FAST_START = ADDR(.OS_CanIsrTx_3_VAR_FAST);
_OS_CanIsrTx_3_VAR_FAST_END = ENDADDR(.OS_CanIsrTx_3_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_NOINIT )
.OS_CanIsrTx_3_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_FAST_NOINIT_START = ADDR(.OS_CanIsrTx_3_VAR_FAST_NOINIT);
_OS_CanIsrTx_3_VAR_FAST_NOINIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_ZERO_INIT )
.OS_CanIsrTx_3_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_3_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_3_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CanIsrTx_3_VAR_FAST_ZERO_INIT);
_OS_CanIsrTx_3_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_INIT )
.OS_CanIsrTx_3_VAR_NOCACHE ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_NOCACHE_START = ADDR(.OS_CanIsrTx_3_VAR_NOCACHE);
_OS_CanIsrTx_3_VAR_NOCACHE_END = ENDADDR(.OS_CanIsrTx_3_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_NOINIT )
.OS_CanIsrTx_3_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrTx_3_VAR_NOCACHE_NOINIT);
_OS_CanIsrTx_3_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_ZERO_INIT )
.OS_CanIsrTx_3_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_3_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_3_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrTx_3_VAR_NOCACHE_ZERO_INIT);
_OS_CanIsrTx_3_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_INIT )
.OS_CanIsrTx_3_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_FAST_NOCACHE_START = ADDR(.OS_CanIsrTx_3_VAR_FAST_NOCACHE);
_OS_CanIsrTx_3_VAR_FAST_NOCACHE_END = ENDADDR(.OS_CanIsrTx_3_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_NOINIT )
.OS_CanIsrTx_3_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_3_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrTx_3_VAR_FAST_NOCACHE_NOINIT);
_OS_CanIsrTx_3_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_ZERO_INIT )
.OS_CanIsrTx_3_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_3_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_3_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrTx_3_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_CanIsrTx_3_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CanIsrTx_3_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3
. = ALIGN(4);
_OS_CanIsrTx_3_VAR_ALL_END = .-1;
__OS_CanIsrTx_3_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_ISR_CANISRTX_3
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_3_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_ALL_START = .;
__OS_CounterIsr_SystemTimer_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_START = ADDR(.OS_CounterIsr_SystemTimer_VAR);
_OS_CounterIsr_SystemTimer_VAR_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOINIT);
_OS_CounterIsr_SystemTimer_VAR_NOINIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT);
_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST);
_OS_CounterIsr_SystemTimer_VAR_FAST_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_FAST) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT);
_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR_NOCACHE ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE);
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT);
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT);
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT) - 1;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END = ENDADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_bss) - 1;
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_ALL_END = .-1;
__OS_CounterIsr_SystemTimer_VAR_ALL_END = .-1;
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
#endif


#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_APP
# undef OS_LINK_VAR_APP
#endif

#ifdef OS_LINK_VAR_TASK
# undef OS_LINK_VAR_TASK
#endif

#ifdef OS_LINK_VAR_ISR
# undef OS_LINK_VAR_ISR
#endif

#ifdef OS_LINK_KERNEL_TRACE
# undef OS_LINK_KERNEL_TRACE
#endif

#ifdef OS_LINK_KERNEL_TRACE_FAR
# undef OS_LINK_KERNEL_TRACE_FAR
#endif

#ifdef OS_LINK_KERNEL_TRACE_NEAR
# undef OS_LINK_KERNEL_TRACE_NEAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS
# undef OS_LINK_KERNEL_BARRIERS
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_FAR
# undef OS_LINK_KERNEL_BARRIERS_FAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_NEAR
# undef OS_LINK_KERNEL_BARRIERS_NEAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS
# undef OS_LINK_KERNEL_CORESTATUS
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_FAR
# undef OS_LINK_KERNEL_CORESTATUS_FAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_NEAR
# undef OS_LINK_KERNEL_CORESTATUS_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE
# undef OS_LINK_VAR_KERNEL_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif


