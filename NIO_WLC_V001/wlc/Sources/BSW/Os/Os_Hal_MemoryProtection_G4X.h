/***********************************************************************************************************************
*  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \addtogroup Os_Hal_MemoryProtection
 *  \{
 *
 *  \file       Os_Hal_MemoryProtection_G4X.h
 *  \brief
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/

#ifndef OS_HAL_MEMORYPROTECTION_G4X_H
# define OS_HAL_MEMORYPROTECTION_G4X_H
                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! \brief         Sets the MPU Region with the passed index to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU(uint32 index, uint32* ptr)
 *  \param[in]     Index    Index of the MPU region. Parameter must be in range [0, OS_HAL_MPU_REGION_COUNT_COREn]
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU(Index, Config)  Os_Hal_SetMPIDX##Index();                                                         /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */ \
                                       Os_Hal_SetMPLA((Config)->MpuRegion##Index.RegionStart);    \
                                       Os_Hal_SetMPUA((Config)->MpuRegion##Index.RegionEnd);      \
                                       Os_Hal_SetMPAT((Config)->MpuRegion##Index.RegionAttribute)                        /* PRQA S 3453, 0342 */ /* MD_MSR_FctLikeMacro, MD_MSR_Rule20.10_0342 */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU0(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU0(Config)        Os_Hal_SetMPU(0, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU1(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU1(Config)        Os_Hal_SetMPU(1, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU2(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU2(Config)        Os_Hal_SetMPU(2, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU3(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU3(Config)        Os_Hal_SetMPU(3, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU4(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU4(Config)        Os_Hal_SetMPU(4, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU5(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU5(Config)        Os_Hal_SetMPU(5, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU6(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU6(Config)        Os_Hal_SetMPU(6, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU7(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU7(Config)        Os_Hal_SetMPU(7, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU8(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU8(Config)        Os_Hal_SetMPU(8, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU9(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU9(Config)        Os_Hal_SetMPU(9, (Config))                                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU10(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU10(Config)       Os_Hal_SetMPU(10, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU11(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU11(Config)       Os_Hal_SetMPU(11, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU12(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU12(Config)       Os_Hal_SetMPU(12, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU13(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU13(Config)       Os_Hal_SetMPU(13, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU14(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU14(Config)       Os_Hal_SetMPU(14, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU15(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU15(Config)       Os_Hal_SetMPU(15, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU16(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU16(Config)       Os_Hal_SetMPU(16, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU17(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU17(Config)       Os_Hal_SetMPU(17, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU18(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU18(Config)       Os_Hal_SetMPU(18, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU19(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU19(Config)       Os_Hal_SetMPU(19, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU19(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU20(Config)       Os_Hal_SetMPU(20, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU21(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU21(Config)       Os_Hal_SetMPU(21, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU22(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU22(Config)       Os_Hal_SetMPU(22, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU23(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU23(Config)       Os_Hal_SetMPU(23, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU24(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU24(Config)       Os_Hal_SetMPU(24, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU25(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU25(Config)       Os_Hal_SetMPU(25, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU26(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU26(Config)       Os_Hal_SetMPU(26, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU27(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU27(Config)       Os_Hal_SetMPU(27, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU28(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU28(Config)       Os_Hal_SetMPU(28, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU29(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU29(Config)       Os_Hal_SetMPU(29, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU30(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU30(Config)       Os_Hal_SetMPU(30, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! \brief         Sets the MPU Region to the passed configuration value
 *  \details       --no details--
 *  \fn void Os_Hal_SetMPU31(uint32* ptr)
 *  \param[in]     Config   Pointer to the platform specific MPU region configuration. Parameter must not be NULL.
 *  \context       OS_INTERNAL
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           SUPERVISOR
 */
# define Os_Hal_SetMPU31(Config)       Os_Hal_SetMPU(31, (Config))                                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Macro to set the lower stack address in the MPU0 region. */
# define Os_Hal_GetMPLA_0              Os_Hal_GetMPLA                                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Macro to set the upper stack address in the MPU0 region. */
# define Os_Hal_GetMPUA_0              Os_Hal_GetMPUA                                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_Hal_Set_MemRegionID()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_Set_MemRegionID,
(
    VAR(uint32, OS_VAR_NOINIT) value
))
{
  Os_Hal_SetSPID(value);
}


/***********************************************************************************************************************
 *  Os_Hal_SetMPURegion0()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_Hal_SetMPURegion0,
(
    P2CONST(Os_Hal_ContextStackConfigType, AUTOMATIC, OS_VAR_NOINIT) InitialStackRegion
))
{
  /* Initialize MPID7..0 registers */
  Os_Hal_Init_MPIDn();

  /* Initialize MPU region 0 */
  Os_Hal_SetMPIDX0();
  Os_Hal_SetMPLA(InitialStackRegion->Os_Hal_StackStart);
  Os_Hal_SetMPUA(InitialStackRegion->Os_Hal_StackEnd);
  Os_Hal_SetMPAT(OS_HAL_MPU_MPAT0);
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_MEMORYPROTECTION_G4X_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Hal_MemoryProtection_G4X.h
 **********************************************************************************************************************/
