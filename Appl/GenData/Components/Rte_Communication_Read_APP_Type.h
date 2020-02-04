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
 *             File:  Rte_Communication_Read_APP_Type.h
 *           Config:  WLC.dpa
 *      ECU-Project:  WLC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  Application types header file for SW-C <Communication_Read_APP>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_COMMUNICATION_READ_APP_TYPE_H
# define _RTE_COMMUNICATION_READ_APP_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_Comfort_not_enabled
#   define Cx0_Comfort_not_enabled (0U)
#  endif

#  ifndef Cx1_Comfort_enabled
#   define Cx1_Comfort_enabled (1U)
#  endif

#  ifndef Cx2_Reserved
#   define Cx2_Reserved (2U)
#  endif

#  ifndef Cx3_Invalid
#   define Cx3_Invalid (3U)
#  endif

#  ifndef Cx0_Disable
#   define Cx0_Disable (0U)
#  endif

#  ifndef Cx1_Enable_AID1
#   define Cx1_Enable_AID1 (1U)
#  endif

#  ifndef Cx2_Enable_AID2
#   define Cx2_Enable_AID2 (2U)
#  endif

#  ifndef Cx0_Unknown
#   define Cx0_Unknown (0U)
#  endif

#  ifndef Cx1_January
#   define Cx1_January (1U)
#  endif

#  ifndef Cx2_February
#   define Cx2_February (2U)
#  endif

#  ifndef Cx3_March
#   define Cx3_March (3U)
#  endif

#  ifndef Cx4_April
#   define Cx4_April (4U)
#  endif

#  ifndef Cx5_May
#   define Cx5_May (5U)
#  endif

#  ifndef Cx6_June
#   define Cx6_June (6U)
#  endif

#  ifndef Cx7_July
#   define Cx7_July (7U)
#  endif

#  ifndef Cx8_August
#   define Cx8_August (8U)
#  endif

#  ifndef Cx9_September
#   define Cx9_September (9U)
#  endif

#  ifndef CxA_October
#   define CxA_October (10U)
#  endif

#  ifndef CxB_November
#   define CxB_November (11U)
#  endif

#  ifndef CxC_December
#   define CxC_December (12U)
#  endif

#  ifndef CxD_Reserved
#   define CxD_Reserved (13U)
#  endif

#  ifndef CxE_Reserved
#   define CxE_Reserved (14U)
#  endif

#  ifndef CxF_Invalid
#   define CxF_Invalid (15U)
#  endif

#  ifndef Cx0_Parked_vehicle_Off_
#   define Cx0_Parked_vehicle_Off_ (0U)
#  endif

#  ifndef Cx1_Driver_present_On_
#   define Cx1_Driver_present_On_ (1U)
#  endif

#  ifndef Cx2_Driving
#   define Cx2_Driving (2U)
#  endif

#  ifndef Cx3_Software_update
#   define Cx3_Software_update (3U)
#  endif

#  ifndef Cx4_Reserved
#   define Cx4_Reserved (4U)
#  endif

#  ifndef Cx5_Reserved
#   define Cx5_Reserved (5U)
#  endif

#  ifndef Cx6_Reserved
#   define Cx6_Reserved (6U)
#  endif

#  ifndef Cx7_Reserved
#   define Cx7_Reserved (7U)
#  endif

#  ifndef Cx8_Reserved
#   define Cx8_Reserved (8U)
#  endif

#  ifndef Cx9_Reserved
#   define Cx9_Reserved (9U)
#  endif

#  ifndef CxA_Reserved
#   define CxA_Reserved (10U)
#  endif

#  ifndef CxB_Reserved
#   define CxB_Reserved (11U)
#  endif

#  ifndef CxC_Reserved
#   define CxC_Reserved (12U)
#  endif

#  ifndef Cx0_Disable_WLC_charging_function
#   define Cx0_Disable_WLC_charging_function (0U)
#  endif

#  ifndef Cx1_Enable_WLC_charging_function
#   define Cx1_Enable_WLC_charging_function (1U)
#  endif

#  ifndef Cx2_No_operation
#   define Cx2_No_operation (2U)
#  endif

#  ifndef Cx0_Not_started_
#   define Cx0_Not_started_ (0U)
#  endif

#  ifndef Cx1_Power_Requested_
#   define Cx1_Power_Requested_ (1U)
#  endif

#  ifndef Cx2_Power_Reduced_
#   define Cx2_Power_Reduced_ (2U)
#  endif

#  ifndef Cx3_Reserved
#   define Cx3_Reserved (3U)
#  endif

#  ifndef Cx0_WLC_stopped
#   define Cx0_WLC_stopped (0U)
#  endif

#  ifndef Cx1_WLC_on_going
#   define Cx1_WLC_on_going (1U)
#  endif

#  ifndef Cx2_Charge_complete
#   define Cx2_Charge_complete (2U)
#  endif

#  ifndef Cx0_WLC_enabled
#   define Cx0_WLC_enabled (0U)
#  endif

#  ifndef Cx1_WLC_disabled
#   define Cx1_WLC_disabled (1U)
#  endif

#  ifndef Cx0_No_failure
#   define Cx0_No_failure (0U)
#  endif

#  ifndef Cx1_Over_temperature
#   define Cx1_Over_temperature (1U)
#  endif

#  ifndef Cx2_Under_voltage
#   define Cx2_Under_voltage (2U)
#  endif

#  ifndef Cx3_Over_voltage
#   define Cx3_Over_voltage (3U)
#  endif

#  ifndef Cx4_Internal_error
#   define Cx4_Internal_error (4U)
#  endif

#  ifndef Cx5_Foreign_object_existing
#   define Cx5_Foreign_object_existing (5U)
#  endif

#  ifndef Cx6_Unknown_error
#   define Cx6_Unknown_error (6U)
#  endif

#  ifndef Cx7_Smartphone_no_response_or_error
#   define Cx7_Smartphone_no_response_or_error (7U)
#  endif

#  ifndef Cx8_Conductive_Device_Detected
#   define Cx8_Conductive_Device_Detected (8U)
#  endif

#  ifndef Cx1_Enable
#   define Cx1_Enable (1U)
#  endif

# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_DcmEcuReset
#  define RTE_MODETYPE_DcmEcuReset
typedef uint8 Rte_ModeType_DcmEcuReset;
# endif

# define RTE_MODE_Communication_Read_APP_DcmEcuReset_NONE (0U)
# ifndef RTE_MODE_DcmEcuReset_NONE
#  define RTE_MODE_DcmEcuReset_NONE (0U)
# endif
# define RTE_MODE_Communication_Read_APP_DcmEcuReset_HARD (1U)
# ifndef RTE_MODE_DcmEcuReset_HARD
#  define RTE_MODE_DcmEcuReset_HARD (1U)
# endif
# define RTE_MODE_Communication_Read_APP_DcmEcuReset_KEYONOFF (2U)
# ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#  define RTE_MODE_DcmEcuReset_KEYONOFF (2U)
# endif
# define RTE_MODE_Communication_Read_APP_DcmEcuReset_SOFT (3U)
# ifndef RTE_MODE_DcmEcuReset_SOFT
#  define RTE_MODE_DcmEcuReset_SOFT (3U)
# endif
# define RTE_MODE_Communication_Read_APP_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER (4U)
# endif
# define RTE_MODE_Communication_Read_APP_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#  define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
# endif
# define RTE_MODE_Communication_Read_APP_DcmEcuReset_EXECUTE (6U)
# ifndef RTE_MODE_DcmEcuReset_EXECUTE
#  define RTE_MODE_DcmEcuReset_EXECUTE (6U)
# endif
# define RTE_TRANSITION_Communication_Read_APP_DcmEcuReset (7U)
# ifndef RTE_TRANSITION_DcmEcuReset
#  define RTE_TRANSITION_DcmEcuReset (7U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_COMMUNICATION_READ_APP_TYPE_H */
