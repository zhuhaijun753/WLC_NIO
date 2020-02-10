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
 *             File:  TSC_SWC_WLCAPP.c
 *           Config:  WLC.dpa
 *      ECU-Project:  WLC
 *
 *        Generator:  MICROSAR RTE Generator Version 4.20.0
 *                    RTE Core Version 1.20.0
 *          License:  CBD1900162
 *
 *      Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_SWC_WLCAPP.h"
#include "TSC_SWC_WLCAPP.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_SWC_WLCAPP_Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetCurrentComMode(ComM_ModeType *ComMode)
{
  return Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetCurrentComMode(ComMode);
}
Std_ReturnType TSC_SWC_WLCAPP_Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetMaxComMode(ComM_ModeType *ComMode)
{
  return Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetMaxComMode(ComMode);
}
Std_ReturnType TSC_SWC_WLCAPP_Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetRequestedComMode(ComM_ModeType *ComMode)
{
  return Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_GetRequestedComMode(ComMode);
}
Std_ReturnType TSC_SWC_WLCAPP_Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_RequestComMode(ComM_ModeType ComMode)
{
  return Rte_Call_UR_CN_NIO_ES6_RF_CAN_SR_V3_0_e01a4c57_RequestComMode(ComMode);
}


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* SWC_WLCAPP */
      /* SWC_WLCAPP */



