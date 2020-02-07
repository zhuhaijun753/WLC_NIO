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
 *             File:  Os_Cfg.h
 *           Config:  WLC.dpa
 *      ECU-Project:  WLC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  Os definitions
 *********************************************************************************************************************/

#ifndef _OS_CFG_H_
# define _OS_CFG_H_

/* Os definitions */

/* Tasks */
# define OsTask_APP (0U)
# define OsTask_BSW_SCHM (1U)

/* Alarms */
# define Rte_Al_TE_Communication_Read_APP_ComReadandWrite_Runnable (0U)
# define Rte_Al_TE2_OsTask_BSW_SCHM_0_10ms (1U)
# define Rte_Al_TE2_OsTask_BSW_SCHM_0_20ms (2U)
# define Rte_Al_TE_CanTp_CanTp_MainFunction (3U)

/* Events */
# define Rte_Ev_Cyclic2_OsTask_BSW_SCHM_0_10ms (0x01)
# define Rte_Ev_Cyclic2_OsTask_BSW_SCHM_0_20ms (0x04)
# define Rte_Ev_Run_CanTp_CanTp_MainFunction (0x02)
# define Rte_Ev_Run_Communication_Read_APP_ComReadandWrite_Runnable (0x01)

/* Spinlocks */

/* Resources */

/* ScheduleTables */

/* Cores */

/* Trusted Functions */


#endif /* _OS_CFG_H_ */
