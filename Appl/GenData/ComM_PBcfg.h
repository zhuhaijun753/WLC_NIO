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
 *            Module: ComM
 *           Program: VAG AR4 (MSR_Vag_SLP5)
 *          Customer: SAIC Volkswagen Automotive Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016393AFP-C
 *    License Scope : The usage is restricted to CBD1900162_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: ComM_PBcfg.h
 *   Generation Time: 2019-12-01 17:02:35
 *           Project: WLC - Version 1.0
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


#if !defined(COMM_PBCFG_H)
#define COMM_PBCFG_H


/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "ComM_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  ComMPBDataSwitches  ComM Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define COMM_PBCONFIG                                                 STD_OFF  /**< Deactivateable: 'ComM_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_LTCONFIGIDXOFPBCONFIG                                    STD_OFF  /**< Deactivateable: 'ComM_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define COMM_PCCONFIGIDXOFPBCONFIG                                    STD_OFF  /**< Deactivateable: 'ComM_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif /* COMM_PBCFG_H */

