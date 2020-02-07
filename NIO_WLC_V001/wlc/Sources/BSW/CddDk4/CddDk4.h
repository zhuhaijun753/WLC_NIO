/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2016 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*        \file   CddDk4.h
 *        \brief  CddDk4 header file
 *
 *      \details
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

#ifndef CDDDK4_H
# define CDDDK4_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PduR Trasnmit Service */
# include "PduR_CddDk4.h"

/* Configuration */
# include "CddDk4_Cfg.h"

/* Dcm */
#include "Dcm.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Vendor and module identification */
# define CDDDK4_VENDOR_ID                                       (30u)
# define CDDDK4_MODULE_ID                                       (255u)

/* AUTOSAR Software specification version information */
# define CDDDK4_AR_RELEASE_MAJOR_VERSION                        (4u)
# define CDDDK4_AR_RELEASE_MINOR_VERSION                        (0u)
# define CDDDK4_AR_RELEASE_REVISION_VERSION                     (3u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define CDDDK4_SW_MAJOR_VERSION                                (2u)
# define CDDDK4_SW_MINOR_VERSION                                (0u)
# define CDDDK4_SW_PATCH_VERSION                                (1u)

# define CDDDK4_INSTANCE_ID_DET                                 (0x00u)

/* ----- API service IDs ----- */
# define CDDDK4_SID_INIT                             (0x00U) /*!< Service ID: ::CddDk4_Init()                      */
# define CDDDK4_SID_GET_VERSION_INFO                 (0x01U) /*!< Service ID: ::CddDk4_GetVersionInfo()            */
# define CDDDK4_SID_MEMORY_INIT                      (0x02U) /*!< Service ID: ::CddDk4_InitMemory()                */
# define CDDDK4_SID_MAINFUNCTION                     (0x03U) /*!< Service ID: ::CddDk4_MainFunction()              */
# define CDDDK4_SID_SERVICE_SEND                     (0x04U) /*!< Service ID: ::CddDk4_SvcSend()                   */
# define CDDDK4_SID_PROVIDE_TX_BUFFER                (0x05U) /*!< Service ID: ::CddDk4_ProvideTxBuffer()           */
# define CDDDK4_SID_TX_CONFIRMATION                  (0x06U) /*!< Service ID: ::CddDk4_TxConfirmation()            */
# define CDDDK4_SID_PROVIDE_RX_BUFFER                (0x07U) /*!< Service ID: ::CddDk4_ProvideRxBuffer()           */
# define CDDDK4_SID_RX_INDICATION                    (0x08U) /*!< Service ID: ::CddDk4_RxIndication()              */
# define CDDDK4_SID_ISDIDAVAILABLE                   (0x09U) /*!< Service ID: ::CddDk4_isDidAvailable()            */
# define CDDDK4_SID_READ_DIDDATA                     (0x0AU) /*!< Service ID: ::CddDk4_ReadDidData()               */
# define CDDDK4_SID_REQUEST_REMOTE_DIDDATA           (0x0BU) /*!< Service ID: ::CddDk4_RequestRemoteDidData()      */
# define CDDDK4_SID_DISABLE_CONNECTION               (0x0CU) /*!< Service ID: ::CddDk4_DisableConnection()         */
# define CDDDK4_SID_ENABLE_CONNECTION                (0x0DU) /*!< Service ID: ::CddDk4_EnableConnection()          */
# define CDDDK4_SID_GET_CONNECTION_STATE_COUNTER     (0x0EU) /*!< Service ID: ::CddDk4_GetConnectionStateCounter() */
# define CDDDK4_SID_INDICATION                       (0x0FU) /*!< Service ID: ::CddDk4_Indication()                */
# define CDDDK4_SID_ISDIDAVAILABLE_INTERNAL          (0x10U) /*!< Service ID: Internal function called by
                                                                  ::CddDk4_isDidAvailable()                        */
# define CDDDK4_SID_WRITE_DIDDATA                    (0x11U) /*!< Service ID: ::CddDk4_WriteDidData()              */
# define CDDDK4_SID_WRITE_REMOTE_DIDDATA             (0x12U) /*!< Service ID: ::CddDk4_WriteRemoteDidData()        */
# define CDDDK4_SID_WRITE_DIDDATA_INTERNAL           (0x13U) /*!< Service ID: Internal function called by
                                                                  ::CddDk4_WriteDidData()                          */
# define CDDDK4_SID_START_OF_RECEPTION               (0x14U) /*!< Service ID: ::CddDk4_StartOfReception()          */
# define CDDDK4_SID_COPY_RX_DATA                     (0x15U) /*!< Service ID: ::CddDk4_CopyRxData()                */
# define CDDDK4_SID_COPY_TX_DATA                     (0x16U) /*!< Service ID: ::CddDk4_CopyTxData()                */
# define CDDDK4_SID_INTERNAL                         (0xFFU) /*!< Service ID: Internal Functions                   */

/* ----- Error codes ----------------------------------------------------------------------------------------------- */
# define CDDDK4_E_NO_ERROR                          (0x00U) /*!< used to check if no error occurred - use a value
                                                                 unequal to any error code */
# define CDDDK4_E_PARAM_POINTER                     (0x10U) /*!< Error code: API service used with invalid pointer
                                                                 parameter (\c NULL_PTR) */
# define CDDDK4_E_PARAM_VALUE                       (0x11U) /*!< Error code: API service used with invalid parameter
                                                                 value */
# define CDDDK4_E_UNINIT                            (0x20U) /*!< Error code: API service used without module
                                                                 initialization */
# define CDDDK4_E_ALREADY_INITIALIZED               (0x21U) /*!< Error code: The service CDDDK4_Init() is called while
                                                                 the module is already initialized  */
# define CDDDK4_E_CHANNEL_BUFFER_OUT_OF_RANGE       (0x30U) /*!< Error code: API service used with invalid buffer length
                                                            */
# define CDDDK4_E_PDU_ID_RX_OUT_OF_RANGE            (0x31U) /*!< Error code: API service used with Rx-PDU-Id that is not
                                                                 available */
# define CDDDK4_E_DID_DATA_BUFFER_OUT_OF_RANGE      (0x40U) /*!< Error code: API service used with invalid Did data
                                                                 buffer length */
# define CDDDK4_E_DID_STATUS_BUFFER_OUT_OF_RANGE    (0x41U) /*!< Error code: API service used with invalid Did status
                                                                 buffer length */

/* ----- CddDk4_ReturnType ----------------------------------------------------------------------------------------- */
# define CDDDK4_RET_OK                                          (0x00U) /*!< Return code: No error */
# define CDDDK4_RET_NOT_OK                                      (0x01U) /*!< Return code: Error occurred */
# define CDDDK4_RET_NO_FREE_CHANNEL                             (0x02U) /*!< Return code: No Free Connection Channel
                                                                             available */
# define CDDDK4_RET_CONNECTION_BUSY                             (0x03U) /*!< Return code: Connection is busy */
# define CDDDK4_RET_BUFFER_OVFL                                 (0x04U) /*!< Return code: Buffer Overflow */

/* ----- Notification callback return type -------------------------------------------------------------------------- */

# define CDDDK4_NOTIFY_POSITIVE_RESPONSE   (0x00U) /*!< Positive Response. */
# define CDDDK4_NOTIFY_NEGATIVE_RESPONSE   (0x01U) /*!< Negative Response. */
# define CDDDK4_NOTIFY_CONNECTION_TIMEOUT  (0x02U) /*!< Communication Timeout. */
# define CDDDK4_NOTIFY_RESPONSE_TOO_SHORT  (0x03U) /*!< Response too short. */
# define CDDDK4_NOTIFY_RCRRP_LIMIT_REACHED (0x04U) /*!< RCR-RP limit exceeded. */
# define CDDDK4_NOTIFY_BUSY_LIMIT_REACHED  (0x05U) /*!< Busy-Retry limit reached. */
# define CDDDK4_NOTIFY_REQUEST_FAILED      (0x06U) /*!< Request failed, communication error. */
# define CDDDK4_NOTIFY_RESPONSE_FAILED     (0x07U) /*!< Response failed, communication error. */
# define CDDDK4_NOTIFY_CONNECTION_DISABLED (0x08U) /*!< Request rejected, connection is disabled. */
# define CDDDK4_NOTIFY_INVALID_SID         (0x09U) /*!< Response received with invalid Service ID. */
# define CDDDK4_NOTIFY_INVALID_DID         (0x0AU) /*!< Response received with different DID than what was requested. */
# define CDDDK4_NOTIFY_RESPONSE_TOO_LONG   (0x0BU) /*!< Response too long. */

# define CDDDK4_NOTIFY_CONNECTION_BUSY     (0x10U) /*!< Request rejected, connection is busy with another request. */




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* ----- Interrupt control ----------------------------------------------------------------------------------------- */
#if (CDDDK4_AR4_SCHM_SUPPORT == STD_ON)
# define CddDk4_EnterExclusiveAreaComMgr() SchM_Enter_CddDk4_CDDDK4_EXCLUSIVE_AREA_0()    /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */
# define CddDk4_LeaveExclusiveAreaComMgr() SchM_Exit_CddDk4_CDDDK4_EXCLUSIVE_AREA_0()     /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */

# define CddDk4_EnterExclusiveAreaReqMgr() SchM_Enter_CddDk4_CDDDK4_EXCLUSIVE_AREA_1()    /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */
# define CddDk4_LeaveExclusiveAreaReqMgr() SchM_Exit_CddDk4_CDDDK4_EXCLUSIVE_AREA_1()     /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */
#else /* CDDDK4_AR4_SCHM_SUPPORT */
# define CddDk4_EnterExclusiveAreaComMgr() SchM_Enter_CddDk4(CDDDK4_EXCLUSIVE_AREA_0)     /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */
# define CddDk4_LeaveExclusiveAreaComMgr() SchM_Exit_CddDk4(CDDDK4_EXCLUSIVE_AREA_0)      /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */

# define CddDk4_EnterExclusiveAreaReqMgr() SchM_Enter_CddDk4(CDDDK4_EXCLUSIVE_AREA_1)    /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */
# define CddDk4_LeaveExclusiveAreaReqMgr() SchM_Exit_CddDk4(CDDDK4_EXCLUSIVE_AREA_1)     /* PRQA S 3453,3335 */ /* MD_MSR_19.7 */
#endif /* CDDDK4_AR4_SCHM_SUPPORT */

/*!
 * \exclusivearea CDDDK4_EXCLUSIVE_AREA_0 (ComMgr)
 * Assures consistency of state changes in communication between the MainFunction and the PduR callouts.
 * \protects consistency of state changes/operations in communication mode, and allocation of reception buffer.
 * \usedin
 *   - ::CddDk4_MainFunction
 *   - ::CddDk4_ProvideRxBuffer
 *   - ::CddDk4_StartOfReception
 * \exclude All other functions provided by CddDk4.
 * \length MEDIUM -
 * \endexclusivearea
 **********************************************************************************************************************/

/*!
 * \exclusivearea CDDDK4_EXCLUSIVE_AREA_1 (ReqMgr)
 * Assures consistency of state changes in requests between the MainFunction, Dcm callouts, and interfaces provided to
 * the application.
 * \protects consistency of state changes/operations in application and Dcm requests, including enabling/disabling
 *           connections.
 * \usedin
 *   - ::CddDk4_MainFunction
 *   - ::CddDk4_IsDidAvailable
 *   - ::CddDk4_ReadDidData
 *   - ::CddDk4_WriteDidData
 *   - ::CddDk4_ReadRemoteDidData
 *   - ::CddDk4_WriteRemoteDidData
 *   - ::CddDk4_DisableConnection
 *   - ::CddDk4_EnableConnection
 * \exclude All other functions provided by CddDk4.
 * \length MEDIUM -
 * \endexclusivearea
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CDDDK4_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  CddDk4_InitMemory()
 *********************************************************************************************************************/
/*!
 * \brief       Function for *_INIT_*-variable initialization
 * \details     Service to initialize module global variables at power up. This function initializes the
 *              variables in *_INIT_* sections. Used in case they are not initialized by the startup code.
 * \pre         Module is uninitialized.
 * \trace       CREQ-105670
 * \trace       DSGN-CddDk422763
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_InitMemory(void);

/**********************************************************************************************************************
 *  CddDk4_Init()
 *********************************************************************************************************************/
/*!
 * \brief       Initialization function
 * \details     This function initializes the module CDDDK4. It initializes all variables and sets the module state to
 *              initialized.
 *
 * \param[in]   ConfigPtr               Configuration structure for initializing the module
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \pre         Module is uninitialized.
 * \pre         CddDk4_InitMemory has been called unless CddDk4_Init_State is initialized by start-up code.
 * \trace       CREQ-105670, CREQ-105669
 * \trace       DSGN-CddDk422770
 * \note        Specification of module initialization
 *********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_Init(void);

/**********************************************************************************************************************
 *  CddDk4_MainFunction()
 *********************************************************************************************************************/
/*!
 * \brief       Cyclic CddDk4 task
 * \details     Executes all internal used timers and state machines
 *
 * \pre         -
 * \trace       CREQ-105668, CREQ-105669
 * \trace       DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796, DSGN-CddDk422800
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_MainFunction(void);


/**********************************************************************************************************************
*  CddDk4_RequestRemoteDidData()
*********************************************************************************************************************/
/*!
 * \brief       API to request read Did data service
 * \details     Sending 0x22 (ReadDataByIdentifer) service if free channels are available.
 *
 * \param[in]   DID                 Did Identifier
 * \param[in]   ConnId              Connection id from which Did will be requested
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 * \pre         Module is initialized.
 * \trace       CREQ-105669
 * \trace       DSGN-CddDk422795
 * \return      CDDDK4_RET_OK:               Request was successful.
 * \return      CDDDK4_RET_NO_FREE_CHANNEL:  Request was not successful. All connection channels are busy
 * \return      CDDDK4_RET_NOT_OK:           Request was not successful.
 *********************************************************************************************************************/
FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_RequestRemoteDidData(uint16 DID, CddDk4_ConnectionIdType ConnId);


/**********************************************************************************************************************
*  CddDk4_IsDidAvailable()
*********************************************************************************************************************/
/*!
 * \brief       Dcm IsDidAvailable Callout Implementation.
 * \details     Used by Dcm to determine if DID is available.
 *
 * \param[in]   DID                 Did Identifier
 * \param[in]   OpStatus            Status of the current operation
 * \param[out]  supported           Indicate if requested DID is available or not
 * \context     TASK
 * \reentrant   TRUE for different DIDs
 * \synchronous FALSE
 * \pre         Module is initialized.
 * \trace       CREQ-105669
 * \trace       DSGN-CddDk422792, DSGN-CddDk422793
 * \return      E_OK:               Request was successful.
 * \return      DCM_E_PENDING:      Request is not finished. Further call(s) required to finish.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_IsDidAvailable(uint16 DID,
                                                        Dcm_OpStatusType OpStatus,
                                                        P2VAR(Dcm_DidSupportedType, AUTOMATIC, CDDDK4_VAR) supported);

/**********************************************************************************************************************
*  CddDk4_ReadDidData()
*********************************************************************************************************************/
/*!
 * \brief       Dcm ReadDidData Callout Implementation.
 * \details     Used by Dcm to read an available DID's data.
 *
 * \param[in]   DID                 Did Identifier
 * \param[in]   OpStatus            Status of the current operation
 * \param[out]  Data                Buffer where the Did data shall be copied
 * \param[out]  DataLength          Length of the data that was read
 * \param[out]  ErrorCode           NRC to be sent in case of a negative response (E_NOT_OK)
 * \context     TASK
 * \reentrant   TRUE for different DIDs
 * \synchronous FALSE
 * \pre         Module is initialized. Did availability was requested with API CddDk4_isDidAvailable().
 * \trace       CREQ-105669
 * \trace       DSGN-CddDk422792
 * \return      E_OK:               Request was successful.
 * \return      E_NOT_OK:           Request was not successful.
 * \return      DCM_E_PENDING:      Request is not finished. Further call(s) required to finish
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_ReadDidData(
                                                  uint16 DID,
                                                  P2VAR(uint8, AUTOMATIC, CDDDK4_VAR) Data,
                                                  Dcm_OpStatusType OpStatus,
                                                  P2VAR(uint16, AUTOMATIC, CDDDK4_VAR) DataLength,
                                                  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_VAR) ErrorCode);

/**********************************************************************************************************************
*  CddDk4_WriteDidData()
*********************************************************************************************************************/
/*!
 * \brief       Write Did data
 * \details     API to write Did data
 *
 * \param[in]   DID                 Did Identifier
 * \param[in]   Data                Pointer to Did data
 * \param[in]   OpStatus            Status of the current operation
 * \param[in]   DataLength          Length of the data to be written
 * \param[out]  ErrorCode           NRC to be sent in case of a negative response (E_NOT_OK)
 * \context     TASK
 * \reentrant   TRUE for different DIDs
 * \synchronous FALSE
 * \pre         Module is initialized. Did availability was requested with API CddDk4_isDidAvailable().
 * \trace       CREQ-105669
 * \trace       DSGN-CddDk422793
 * \return      E_OK:               Request was successful.
 * \return      E_NOT_OK:           Request was not successful.
 * \return      DCM_E_PENDING:      Request is not finished. Further call(s) required to finish
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_WriteDidData(
                                                  uint16 DID,
                                                  P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) Data,
                                                  Dcm_OpStatusType OpStatus,
                                                  uint16 DataLength,
                                                  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_VAR) ErrorCode);

/**********************************************************************************************************************
*  CddDk4_WriteRemoteDidData()
*********************************************************************************************************************/
/*!
 * \brief       API to request write Did data service
 * \details     Sending 0x2E (WriteDataByIdentifer) service if free channels are available.
 * \param[in]   DID                 Did Identifier
 * \param[in]   ConnId              Connection id to which Did data shall be written
 * \param[in]   Data                Pointer to Did data
 * \param[in]   DataLength          Length of the data to be written
 * \return      CDDDK4_RET_OK:               Request was successful.
 * \return      CDDDK4_RET_NO_FREE_CHANNEL:  Request was not successful. All connection channels are busy
 * \return      CDDDK4_RET_BUFFER_OVFL:      Request was not successful. DataLength is too long for channel buffer.
 * \return      CDDDK4_RET_NOT_OK:           Request was not successful.
 * \pre         Module is initialized.
 * \trace       CREQ-105669
 * \trace       DSGN-CddDk422796
 * \context     TASK
 * \reentrant   TRUE for different DIDs
 * \synchronous FALSE
 *********************************************************************************************************************/
FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_WriteRemoteDidData(uint16 DID,
                                                               CddDk4_ConnectionIdType ConnId,
                                                               P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) Data,
                                                               uint16 DataLength);

/**********************************************************************************************************************
*  CddDk4_Indication()
*********************************************************************************************************************/
/*!
 * \brief       Request Indication
 * \details     Called by DCM before processing diagnostic request
 *
 * \param[in]   SID           Service Identifier
 * \param[in]   RequestData   This parameter contains the complete request data except the SID. This parameter is not
 *                            used.
 * \param[in]   DataSize      This parameter defines how many bytes in the RequestData parameter are valid. This
 *                            parameter is not used.
 * \param[in]   ReqType       Addressing type of the request(0=physical request, 1=functional request). This parameter
 *                            is not used.
 * \param[in]   SourceAddress Dcm client description . This parameter is not used.
 * \param[out]  ErrorCode     Negative response Code in Case of an error. This parameter is not used.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \pre         Module is initialized.
 * \trace       CREQ-105669
 * \trace       DSGN-CddDk422792, DSGN-CddDk422793
 * \return      E_NOT_OK: CddDk4 is not initialized.
 * \return      E_OK: Otherwise.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_Indication(
                                             uint8 SID,
                                             P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) RequestData,
                                             uint16 DataSize,
                                             uint8 ReqType,
                                             uint16 SourceAddress,
                                             P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
*  CddDk4_Confirmation()
*********************************************************************************************************************/
/*!
 * \brief       Request Confirmation.
 * \details     Called by DCM after processing a diagnostic request
 *
 * \param[in]   SID                Service Identifier.
 * \param[in]   ReqType            Addressing type of the request(0=physical request, 1=functional request)
 * \param[in]   SourceAddress      Dcm client description.
 * \param[in]   ConfirmationStatus Confirmation of a successful transmission or a transmission error of a diagnostic
 *                                 service.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \pre         Module is initialized.
 * \trace       DSGN-CddDk422792, DSGN-CddDk422793
 * \return      E_OK always.
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_Confirmation(uint8 SID,
                                                      uint8 ReqType,
                                                      uint16 SourceAddress,
                                                      Dcm_ConfirmationStatusType ConfirmationStatus);

/**********************************************************************************************************************
*  CddDk4_DisableConnection()
*********************************************************************************************************************/
/*!
 * \brief       Disables Connection
 * \details     Internal Connection counter of given Connection Id is incremented.
 *              If Connection counter is != 0 Connection status is disabled.
 *              Request to this connection will be rejected.
 * \param[in]   ConnId              Connection Id
 * \pre         Module is initialized.
 * \trace       DSGN-CddDk422799
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_DisableConnection(CddDk4_ConnectionIdType ConnId);

/**********************************************************************************************************************
*  CddDk4_EnableConnection()
*********************************************************************************************************************/
/*!
 * \brief       Enables Connection
 * \details     Internal Connection counter of given Connection Id is decremented.
 *              If Connection counter is equal 0 Connection status is enabled.
 * \param[in]   ConnId              Connection Id
 * \pre         Module is initialized.
 * \trace       DSGN-CddDk422799
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_EnableConnection(CddDk4_ConnectionIdType ConnId);

/**********************************************************************************************************************
*  CddDk4_GetConnectionStateCounter()
*********************************************************************************************************************/
/*!
 * \brief       Provides internal connection counter
 * \details     Provides internal connection counter of given Connection Id
 * \param[in]   ConnId              Connection Id
 * \param[out]  Counter             Value of iternal connection counter
 * \return      E_OK:               Connection state counter is provided successfully
 * \return      E_NOT_OK:           Connection state counter is not provided successfully
 * \pre         Module is initialized.
 * \trace       DSGN-CddDk422799
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_GetConnectionStateCounter(CddDk4_ConnectionIdType ConnId,
                                                                   P2VAR(uint8, AUTOMATIC, CDDDK4_VAR) Counter);

# if (CDDDK4_SUPPORT_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  CddDk4_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * \brief       Returns the version information
 * \details     CddDk4_GetVersionInfo() returns version information, vendor ID and AUTOSAR module ID of the component.
 * \param[out]  versioninfo             Pointer to where to store the version information. Parameter must not be NULL.
 * \pre         -
 * \trace       CREQ-105669, CREQ-105662
 * \context     TASK|ISR2
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CDDDK4_CODE) CddDk4_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDDDK4_APPL_VAR) versioninfo);
# endif


/**********************************************************************************************************************
 *  CddDk4_ApplNotify()
 *********************************************************************************************************************/
/*!
 * \brief   Callout to be implemented by the application to get notification of request results
 * \details Application should implement this callout to get information on status of read/write requests made through
 *          ::CddDk4_RequestRemoteDidData and ::CddDk4_WriteRemoteDidData.
 * \param[out] response Structure to hold response information.
 * \pre -
 * \context     TASK
 * \reentrant   FALSE (i.e. not mandated to be reentrant).
 * \synchronous TRUE
 *********************************************************************************************************************/
#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
FUNC(void, CDDDK4_CODE) CDDDK4_CFG_APPLNOTIFY(P2VAR(CddDk4_ApplRespInfoStructType, AUTOMATIC, CDDDK4_VAR) response);
#endif /* CDDDK4_CFG_SUPPORT_APPLNOTIFY */

# define CDDDK4_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

#endif /* CDDDK4_H */

/**********************************************************************************************************************
 *  END OF FILE: CddDk4.h
 *********************************************************************************************************************/

