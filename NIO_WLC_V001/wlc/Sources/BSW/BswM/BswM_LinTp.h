/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
 * 
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  BswM_LinTp.h
 *        \brief  MICROSAR Basic Software Mode Manager
 *
 *      \details  Callback header for LinTp.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/
#if !defined BSWM_LINTP_H
# define BSWM_LINTP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "LinTp_Types.h"
# include "Lin_GeneralTypes.h"
# include "LinIf_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT VERSIONS
 *********************************************************************************************************************/

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
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# define BSWM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
# include "BswM_vMemMap.h" 

/**********************************************************************************************************************
 *  BswM_LinTp_RequestMode()
 *********************************************************************************************************************/
/*! \brief      Function called by LinTp to request a mode for the corresponding LIN channel
 * \details     Passed mode is stored and depending rules are arbitrated.
 * \param[in]   Network               The LIN channel that the indicated state corresponds to.
 * \param[in]   LinTpRequestedMode    The current state of the LIN channel.
 * \pre         -
 * \context     TASK|ISR1|ISR2
 * \reentrant   TRUE for different networks
 * \synchronous TRUE
 * \config      BSWM_ENABLE_LINTP
 * \trace       SPEC-16688, SPEC-7873, SPEC-7891, SPEC-16660
 */
extern FUNC(void, BSWM_CODE) BswM_LinTp_RequestMode(NetworkHandleType Network, LinTp_Mode LinTpRequestedMode);

# define BSWM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
# include "BswM_vMemMap.h" 

#endif

/**********************************************************************************************************************
 *  END OF FILE: BswM_LinTp.h
 *********************************************************************************************************************/
