/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  CddDk4_Cbk.h
 *        \brief  CddDk4 callback definitions
 *
 *      \details  Function prototypes of CddDk4 callback and notification functions.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vector Informatik GmbH
 *  Muhammad Tayel                vismul        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2015-09-09  vissat  -             initial version
 *  02.00.00  2016-05-21  vismul  ESCAN00090611 FEAT-1716: Support for DK2 routing for VAG SLP5
 *                                ESCAN00089975 Compiler error: Error occurs when using CddDk4 module with an AUTOSAR 3
 *                                              SchM.
 *                                ESCAN00090292 Endless loop during main function.
 *  02.00.01  2016-10-06  vismul  ESCAN00087604 BETA version - the BSW module is in BETA state.
 *                                ESCAN00092197 Compiler warning: Possible loss of data.
 *********************************************************************************************************************/


#ifndef CDDDK4_CBK_H
# define CDDDK4_CBK_H


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CddDk4_Cfg.h"

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
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CDDDK4_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
/**********************************************************************************************************************
  CddDk4_ProvideTxBuffer
**********************************************************************************************************************/
/*!
 * \brief Called by the PduR to request the Tx CddDk4 SDU Buffer to be transmitted.
 * \details Implementation of PduR 3 Callout \c <Msn>_ProvideTxBuffer, called by PduR in response to a previous call
 *          to PduR_<Msn>Transmit to get the buffer containing the message to be sent.
 *
 * \param[in]  CddDk4TxPduId ID of the CddDk4 I-PDU that will be transmitted.
 * \param[out] PduInfoPtr    Pointer to pointer to PduInfoStructure containing SDU data pointer and SDU length of the
 *                           transmit buffer.
 * \param[in]  Length        Exact length of the requested transmit buffer, it should be less than or equal to the Sdu
 *                           length of the Sdu whose transmission was initiated in a previous call
 *                           to \c PduR_CddDk4Transmit.\n
 * \context ANY
 * \reentrant TRUE for different CddDk4TxPduId.
 * \synchronous TRUE
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is off.
 * \trace DSGN-CddDk422797
 * \return BUFREQ_OK         Buffer request accomplished successfully\n
 *         BUFREQ_E_NOT_OK   The CddDk4TxPduId is not valid\n
 *                           or the CddDk4TxPduId is not forwarded in this identity\n
 *                           or the PduInfoPtr is not valid\n
 *                           or function call was not expected.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_ProvideTxBuffer(
                                                       PduIdType CddDk4TxPduId,
                                                       P2VAR(PduInfoTypeApplPtr, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr,
                                                       PduLengthType Length);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
  CddDk4_TpTxConfirmation
**********************************************************************************************************************/
/*!
 * \brief Confirmation of completed transmission.
 * \details Implementation of PduR 4 Callout \c <Msn>_TpTxConfirmation, called by PduR to confirm the end
 *          of a transmission request giving its final result.
 *
 * \param[in] CddDk4TxPduId The transmitted PDU.
 * \param[in] Result        The result of the transmission.
 * \context ANY
 * \reentrant TRUE for different CddDk4TxPduId.
 * \synchronous TRUE
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is on.
 * \trace DSGN-CddDk422798
**********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_TpTxConfirmation(PduIdType CddDk4TxPduId, Std_ReturnType Result);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
/**********************************************************************************************************************
  CddDk4_TxConfirmation
**********************************************************************************************************************/
/*!
 * \brief Confirmation of completed transmission.
 * \details Implementation of PduR 3 Callout \c <Msn>_TxConfirmation, called by PduR to confirm the end
 *          of a transmission request giving its final result.
 *
 * \param[in] CddDk4TxPduId The transmitted PDU.
 * \param[in] Result        The result of the transmission.
 * \context ANY
 * \reentrant TRUE for different CddDk4TxPduId.
 * \synchronous TRUE
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is off.
 * \trace DSGN-CddDk422797
**********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_TxConfirmation(PduIdType CddDk4TxPduId, NotifResultType Result);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
  CddDk4_StartOfReception
**********************************************************************************************************************/
/*!
 * \brief Indication of incoming new PDU reception.
 * \details Implementation of PduR 4 Callout \c <Msn>_StartOfReception, called by PduR to indicate the start
 *          of reception of the indicated Pdu ID.
 *
 * \param[in]  CddDk4RxPduId PduId to be received.
 * \param[in]  PduInfoPtr    If not a null pointer and SDU length is _not_ 0 then it should be considered the first
 *                           segment of data to be received and data length equal to the SDU length should be copied
 *                           internal buffer, if not a null pointer and SDU length is 0 then it is considered a poll
 *                           of CddDk4 buffer size and not treated as a reception indication and the possible buffer
 *                           size is returned, if it is a null pointer then it is considered a reception indication but
 *                           no data yet is present and data is to be received in consequent calls
 *                           to ::CddDk4_CopyRxData.
 * \param[in]  TpSduLength   The total length of the PDU to be received.
 * \param[out] BufferSizePtr The remaining internal buffer size after current function call is provided to the caller.
 * \context ANY
 * \reentrant TRUE for different CddDk4RxPduId.
 * \synchronous TRUE
 * \pre -
 * \trace DSGN-CddDk422798
 * \config CDDDK4_AR4_PDUR_SUPPORT is on.
 * \return BUFREQ_E_NOT_OK   If a wrong parameter is passed, the PduId is not assigned to an active channel (for cases
 *                           other than polling the buffer size), or the channel is in a wrong state.\n
 *         BUFREQ_E_OVFL     If the Pdu is longer than the maximum buffer that could be allocated.\n
 *         BUFREQ_OK         Successful execution.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_StartOfReception(
                                                       PduIdType CddDk4RxPduId,
                                                       P2VAR(PduInfoType, AUTOMATIC, CDDDK4_APPL_DATA) PduInfoPtr,
                                                       PduLengthType TpSduLength,
                                                       P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr);
#endif/* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
  CddDk4_CopyRxData
**********************************************************************************************************************/
/*!
 * \brief  Indication of incoming PDU segment.
 * \details Implementation of PduR 4 Callout \c <Msn>_CopyRxData, called by PduR to give CddDk4 a received segment
 *          of the indicated Pdu ID.
 *
 * \param[in]  CddDk4RxPduId PduId to be received.
 * \param[in]  PduInfoPtr    If PduInfoPtr->SduLength contains the length of the segment to be received, and
 *                           PduInfoPtr->SduDataPtr contains the segment to be received.
 * \param[out] BufferSizePtr The remaining internal buffer size after current function call is provided to the caller
 *                           through this pointer.
 * \context ANY
 * \reentrant TRUE for different CddDk4RxPduId.
 * \synchronous TRUE
 * \pre -
 * \trace DSGN-CddDk422798
 * \config CDDDK4_AR4_PDUR_SUPPORT is on.
 * \return BUFREQ_E_NOT_OK   If a wrong parameter is passed, the PduId is not assigned to an active channel, or the
 *                           channel is in a wrong state.\n
 *         BUFREQ_OK         Successful execution.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_CopyRxData(PduIdType CddDk4RxPduId,
                                                       P2VAR(PduInfoType, AUTOMATIC, CDDDK4_APPL_DATA) PduInfoPtr,
                                                       P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr);
#endif/* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
  CddDk4_CopyTxData
**********************************************************************************************************************/
/*!
 * \brief  Request for transmitted segment.
 * \details Implementation of PduR 4 Callout \c <Msn>_CopyTxData, called by PduR to get segment of the indicated Pdu ID
 *          in order to transmit it.
 *
 * \param[in]     CddDk4TxPduId    PduId for which Tx Data is being requested.
 * \param[in,out] PduInfoPtr       PduInfoPtr->SduLength is the length requested to be provided, PduInfoPtr->SduDataPtr
 *                                 is where the data should be written.
 * \param[in,out] Retry            Not used, present only to match the callout prototype in PduR.
 * \param[out]    AvailableDataPtr Remaining data to be sent is provided to the caller through this pointer.
 * \context ANY
 * \reentrant TRUE for different CddDk4TxPduId.
 * \synchronous TRUE
 * \pre -
 * \trace DSGN-CddDk422798
 * \config CDDDK4_AR4_PDUR_SUPPORT is on.
 * \return BUFREQ_E_NOT_OK         If a wrong parameter is passed, the PduId is not assigned to an active channel,
 *                                 or the channel is in a wrong state.\n
 *         BUFREQ_OK               Successful execution.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_CopyTxData(
                                                    PduIdType CddDk4TxPduId,
                                                    P2VAR(PduInfoType, AUTOMATIC, CDDDK4_APPL_DATA) PduInfoPtr,
                                                    P2VAR(RetryInfoType, AUTOMATIC, CDDDK4_APPL_DATA) Retry,
                                                    P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) AvailableDataPtr);
#endif/* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
  CddDk4_TpRxIndication
**********************************************************************************************************************/
/*!
 * \brief Indication of completed reception.
 * \details Implementation of PduR 4 Callout \c <Msn>_TpRxIndication, called by PduR to indicate the end
 *          of reception of the indicated Pdu ID giving its final result.
 *
 * \param[in] CddDk4RxPduId The received PDU.
 * \param[in] Result        The result of the reception.
 * \context ANY
 * \reentrant TRUE for different CddDk4RxPduId.
 * \synchronous TRUE
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is on.
 * \trace DSGN-CddDk422798
**********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_TpRxIndication(PduIdType CddDk4RxPduId, Std_ReturnType Result);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
/**********************************************************************************************************************
  CddDk4_ProvideRxBuffer
**********************************************************************************************************************/
/*!
 * \brief      The function is called by the PduR to receive a CddDk4 SDU.
 * \details Implementation of PduR 3 Callout \c <Msn>_ProvideRxBuffer, called by PduR to request a buffer from CddDk4
 *          to write into it the received Pdu indicated by the passed Pdu ID.
 *
 * \param[in]  CddDk4RxPduId ID of the CddDk4 I-PDU that will be received.
 * \param[in]  TpSduLength   Length of the entire SDU that will be received
 * \param[out] PduInfoPtr    Pointer to pointer to PduInfoStructure containing SDU data pointer and SDU length
 *                            of a receive buffer.
 * \context ANY
 * \reentrant TRUE for different CddDk4RxPduId.
 * \synchronous TRUE
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is off.
 * \trace DSGN-CddDk422797
 * \return        BufReq_ReturnType\n
 *                BUFREQ_OK         Buffer request accomplished successfully\n
 *                BUFREQ_E_NOT_OK   The PDU Router is in the PDUR_UNINIT state\n
 *                                  or the CddDk4RxPduId is not valid\n
 *                                  or the CddDk4RxPduId is not forwarded in this identity\n
 *                                  or the PduInfoPtr is not valid\n
 *                                  or the request was not accepted by the destination upper layer.\n
 *                BUFREQ_E_OVFL     The CddDk4 module is not able to receive number of TpSduLength bytes
 *                                  and no buffer is provided.
**********************************************************************************************************************/
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_ProvideRxBuffer(
                                                      PduIdType CddDk4RxPduId,
                                                      PduLengthType TpSduLength,
                                                      P2VAR(PduInfoTypeApplPtr, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
/**********************************************************************************************************************
  CddDk4_RxIndication
**********************************************************************************************************************/
/*!
 * \brief Indication of completed reception.
 * \details Implementation of PduR 3 Callout \c <Msn>_RxIndication, called by PduR to indicate the end
 *          of reception of the indicated Pdu ID giving its final result.
 *
 * \context ANY
 * \reentrant TRUE for different CddDk4RxPduId.
 * \synchronous TRUE
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is off.
 * \trace DSGN-CddDk422797
 * \param[in] CddDk4RxPduId The received PDU.
 * \param[in] Result        The result of the reception.
**********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_RxIndication(PduIdType CddDk4RxPduId, NotifResultType Result);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */

# define CDDDK4_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* CDDDK4_CBK_H */

/*********************************************************************************************************************
 *  END OF FILE: CddDk4_Cbk.h
 ********************************************************************************************************************/

