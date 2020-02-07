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
/*!        \file  CddDk4.c
 *        \brief  CddDk4 source file
 *
 *      \details  CddDk4 main source file and implementation
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


#define CDDDK4_SOURCE


/*********************************************************************************************************************
 * GLOBAL MISRA VIOLATIONS
 *********************************************************************************************************************/

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0612 EOF */ /* MD_CDDDK4_1.1 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "CddDk4.h"
#include "PduR_CddDk4.h"

/* critical sections handled by SchM */
#include "SchM_CddDk4.h"

/* Callback Functions */
#include "CddDk4_Cbk.h"

#include "vstdlib.h"

#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
#include "Det.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of CddDk4 header file */
#if (  (CDDDK4_SW_MAJOR_VERSION != (2u)) \
  || (CDDDK4_SW_MINOR_VERSION != (0u)) \
  || (CDDDK4_SW_PATCH_VERSION != (1u)) )
# error "Vendor specific version numbers of CddDk4.c and CddDk4.h are inconsistent!"
#endif

/* Check the version of the configuration header file */
#if (  (CDDDK4_CFG_SW_MAJOR_VERSION != (2u)) \
  || (CDDDK4_CFG_SW_MINOR_VERSION != (0u)) )
# error "Version numbers of CddDk4.c and BSWM-D file are inconsistent!"
#endif

#if (  (CDDDK4_CFG_GEN_MAJOR_VERSION != (2u)) \
     ||(CDDDK4_CFG_GEN_MINOR_VERSION != (1u)))
# error "Incompatible configuration file version used!"
#endif


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#if !defined (CDDDK4_LOCAL)
# define CDDDK4_LOCAL static
#endif

#if !defined (CDDDK4_LOCAL_INLINE)
# define CDDDK4_LOCAL_INLINE LOCAL_INLINE
#endif


#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/*!< redefinition of \c NotifResultType / \c Std_ReturnType depending on whether AR 3 or AR 4 is used. */
#define CddDk4_TpResultType Std_ReturnType
/*!< redefinition of \c NTFRSLT_OK / \c E_OK depending on whether AR 3 or AR 4 is used. */
#define CDDDK4_NTFRSLT_OK   E_OK
#else /* CDDDK4_AR4_PDUR_SUPPORT */
#define CddDk4_TpResultType     NotifResultType
#define CDDDK4_NTFRSLT_OK       NTFRSLT_OK
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


/*! Small buffer maximum length. */
#define CONNECTION_CHANNEL_SHORT_PAYLOAD_LENGTH 3

/*! Initial value for #CddDk4_ConnStartDelay, so that when it's first incremented it overflows to 0 and 0 is counted.*/
#define CDDDK4_TIMER_CONN_DELAY_BLOCKED         0xFFFFU


#define CDDDK4_NEGATIVE_RESP_LEN 3     /*!< Diagnostic negative response length. */
#define CDDDK4_SERVICE_ID_IDX    1     /*!< Index of the Service ID in a UDS negative response. */
#define CDDDK4_NRC_INDEX         2     /*!< Index of the NRC in a UDS negative response. */
#define CDDDK4_RCRRP_NRC         0x78U /*!< NRC for Request Correctly Received - Response Pending. */
#define CDDDK4_BRR_NRC           0x21U /*!< NRC for Busy - Repeat Request. */
#define CDDDK4_NEGRESP_CODE      0x7FU /*!< Negative Response First Byte. */

# define CDDDK4_RPC_CHECK  0x40U /*! Used in CddDk4_TimerConn for validate response */

/* ----- Modes ----------------------------------------------------------------------------------------------------- */
# define CDDDK4_UNINIT                                          (0x00U) /*!< Signifies module is not initialized. */
# define CDDDK4_INIT                                            (0x01U) /*!< Signifies module is initialized. */

/* ----- CDDDK4 Limiting Parameter --------------------------------------------------------------------------------- */
# define CDDDK4_UNLIMIT_RCRRP                                   (0xFFU) /*!< Unlimited RCRRP receives possible */
# define CDDDK4_UNLIMIT_NRCBUSY                                 (0xFFU) /*!< Unlimited NRC Busy receives possible */

/* ----- UDS Service List (index for ServiceId List) --------------------------------------------------------------- */
# define CDDDK4_SERVICE_0x22                                    0x22U /*!< RDBI Service Identifier */
# define CDDDK4_SERVICE_0x2E                                    0x2EU /*!< WDBI Service Identifier */

/* ----- Channel Assignment ----------------------------------------------------------------------------------------- */
# define CDDDK4_NO_CHANNEL_ASSIGNED                             (0xFFU) /*<! Channel is free */

/* ---- Did Status -------------------------------------------------------------------------------------------------- */

# define CDDDK4_DID_WAITING_REQUEST       0U /*!< DID waiting to be requested from the connection. */
# define CDDDK4_DID_WAITING_WRITE_REQUEST 1U /*!< Application DID waiting to be write-requested from the connection. */
# define CDDDK4_DID_REQUEST_IN_PROGRESS   2U /*!< \c PduR_CddDk4Transmit was called, awaiting further steps. */
# define CDDDK4_DID_RETRY_REQUEST         3U /*!< Request will be retried (busy repeat request or timeout occurred). */

# define CDDDK4_DID_AVAILABLE             4U /*!< Positive response received for a requested DID, data present. */
# define CDDDK4_DID_UNAVAILABLE           5U /*!< DID is not mapped to a connection or timeout retries are exhausted. */

# define CDDDK4_DID_STATUS_PENDING        6U /*!< DID has been requested through a connection, waiting for response. */

# define CDDDK4_DID_WAITING_READ_DATA     10U /*!< DID requested and data is available, waiting for read data request.*/
# define CDDDK4_DID_REPORTED_UNAVAILABLE  11U /*!< DID was reported to be unavailable. */
# define CDDDK4_DID_READ_FINISHED         12U /*!< Read finished. */
# define CDDDK4_DID_WRITE_FINISHED        13U /*!< Write finished. */
# define CDDDK4_DID_WAITING_WRITE_DATA    14U /*!< Waiting for write data. */
# define CDDDK4_DID_REQUEST_CANCELED      15U /*!< Request canceled. */

# define CDDDK4_DID_STATUS_UNKNOWN        255U /*!< Signifies an empty slot. */

/* ----- Connection states ------------------------------------------------------------------------------------------ */

# define CDDDK4_CONNECTION_INACTIVE                0U /*<! Channel is inactive */
# define CDDDK4_CONNECTION_WAIT_DELAY              1U /*<! Channel is waiting for delay elapsed */
# define CDDDK4_CONNECTION_ROUTER_REQUEST          2U /*<! Channel is sending request to any ECU/Connection */
# define CDDDK4_CONNECTION_WAIT_RESPONSE           3U /*<! Channel is waiting for response of ECU/Connection */
# define CDDDK4_CONNECTION_RX_RESPONSE             4U /*<! Channel is receiving response */
# define CDDDK4_CONNECTION_RX_RESPONSE_COMPLETE    5U /*<! Channel notify Application with response data */
# define CDDDK4_CONNECTION_ROUTER_REQUEST_TRANSMIT 6U /*<! Channel has successfully transmit data */
# define CDDDK4_CONNECTION_WAIT_TXCONFIRMATION     7U /*<! Channel is waiting for TxConfirmation */
# define CDDDK4_CONNECTION_WAIT_RXINDICATION       8U /*<! Channel is waiting for RxIndication */
# define CDDDK4_CONNECTION_WAIT_COPY_RESPONSE      9U /*<! Channel is waiting for CopyRxData to fill the buffer */
/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Did Status Buffer Information */
typedef struct
{
  CddDk4_ConnectionIdType           connId;       /* Connection ID for Did */
  uint8                             sid;          /* service id */
  volatile CddDk4_DidStatusType     status;       /* status of Did */
  uint8                             retryCounter; /* count the retries for invalid response */
  CddDk4_RespInfoType               respCode;     /* Response code in case of Service 0x2E */
  uint16                            did;          /* Did value */
  uint16                            didSize;      /* size of Did data */
  CddDk4_TimeoutType                retryTimeOut; /* time out for retry */
  P2VAR(uint8, TYPEDEF, CDDDK4_VAR) dataPtr;      /* Pointer to Did data */
} CddDk4_DidBufferElementStructType;

/*! Internal response data for request manager */
typedef struct
{
  CddDk4_ConnectionIdType connId;                                    /* reference for static ConnectionConfig Table */
  CddDk4_ServiceIdType    serviceId;                                          /* Requested Service */
  CddDk4_RespInfoType     respCode;                                           /* response Code */
  CddDk4_LengthType       dataLength;                                         /* Length of data in respData */
  CddDk4_RespDataType     respData[CDDDK4_CONNECTION_CHANNEL_BUFFER_LIMIT];   /* Response data */
} CddDk4_RespInfoStructType;

/*! Callback pointer for internal response notification */
typedef void(*CddDk4_NotifyFunctionPtr)(P2CONST(CddDk4_RespInfoStructType, TYPEDEF, CDDDK4_VAR));

/*! Runtime Connection Channel Information */
typedef struct
{
  CddDk4_ConnChannelStateType conState;                     /* store current connection state */
  CddDk4_ConnectionIdType     connId;                       /* Index configured connection table */
  CddDk4_ServiceIdType        svcId;                        /* request service id */
  uint8                       rcrrpCounter;                 /* count the received RCRRP messages */
  uint8                       nrcBusyCounter;               /* count the received NRC busy messages */
  PduLengthType               txPduLength;                  /* length of Tx-Pdu */
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
  PduLengthType               bufPos;                       /* position in buffer */
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
  CddDk4_TimeoutType          timeout;                      /* timeout for handle connection */
  CddDk4_NotifyFunctionPtr    backFct;                      /* Callback function */
  PduInfoType                 pduInfo;                      /* Pointer to PDU information */
  CddDk4_RespDataType         shortPayload[3];              /* data buffer */
  CddDk4_RespDataType         payload[CDDDK4_CONNECTION_CHANNEL_BUFFER_LIMIT]; /* data buffer */
} CddDk4_ConnChannelStructType;

/*! Application Did Status Buffer Information */
typedef struct
{
  CddDk4_ConnectionIdType connId;               /* Connection ID for Did */
  uint8                   sid;                  /* service id */
  uint8                   retryCounter;         /* count the retries for invalid response */
  CddDk4_DidStatusType    status;               /* status of Did */
  uint16                  did;                  /* Did value */
  uint16                  didSize;              /* size of Did data */
  CddDk4_TimeoutType      retryTimeOut;         /* time out for retry */
  uint8                   didData[CDDDK4_CONNECTION_CHANNEL_BUFFER_LIMIT]; /* Pointer to Did data */
} CddDk4_ApplDidBufferElementStructType;


/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/



#define CDDDK4_START_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Timer for delay between requests, loaded to zero at startup. */
CDDDK4_LOCAL VAR(CddDk4_TimeoutType, CDDDK4_VAR) CddDk4_ConnStartDelay;

/*! Index to next free DID status buffer position. */
CDDDK4_LOCAL VAR(CddDk4_DidStatusBufferIdxType, CDDDK4_VAR_INIT) CddDk4_CurrentStatusBufferIdx;

/*! Index to next free DID data buffer position. */
CDDDK4_LOCAL VAR(CddDk4_DidDataBufferIdxType, CDDDK4_VAR_INIT) CddDk4_CurrentDataBufferIdx;

#define CDDDK4_STOP_SEC_VAR_NOINIT_16BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define CDDDK4_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Maps connection IDs to their respective assigned channels. */
CDDDK4_LOCAL VAR(CddDk4_ConnChannelIdType, CDDDK4_VAR) CddDk4_ConnectionChannelAssign[CDDDK4_CONNECTION_CONFIG_COUNT];

/*! Holds the connections states, 0 is enabled, otherwise disabled, implemented as a counter to enable multiple clients
 *  to request disable/enable on the same connection, a disable request increments the counter and an enable decrements
 *  it. */
CDDDK4_LOCAL VAR(uint8, CDDDK4_VAR) CddDk4_ConnectionStateCounter[CDDDK4_CONNECTION_CONFIG_COUNT];

/*! Buffer for DID Data; in case of Service 0x2E leading with 2 Byte DID Identifier. */
CDDDK4_LOCAL VAR(uint8, CDDDK4_VAR) CddDk4_DidDataBuffer[(CDDDK4_DID_DATA_BUFFER_SIZE+2)];

/*! Holds the last service indicated by Dcm callout ::CddDk4_Indcation if it was 0x22 or 0x2E, to be used later in
 *  ::CddDk4_IsDidAvailable_Pending. */
CDDDK4_LOCAL VAR(uint8, CDDDK4_VAR) CddDk4_RequestedService;

/*! Used for processing connections in #CDDDK4_CONNECTION_WAIT_DELAY state, to prevent starvation of connections. */
CDDDK4_LOCAL VAR(CddDk4_ConnChannelIdType, CDDDK4_VAR_INIT) CddDk4_CurrentConnChannelIndex;

/*! Counter for active connection channels. */
CDDDK4_LOCAL VAR(CddDk4_ConnChannelIdType, CDDDK4_VAR_INIT) CddDk4_ActiveConnectionChannels;

/*! Counter for DIDs requested via RequestDidData() */
CDDDK4_LOCAL VAR(uint8, CDDDK4_VAR_INIT) CddDk4_ApplRequestedDidsCount;

#define CDDDK4_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define CDDDK4_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Struct array with information about Connections */
CDDDK4_LOCAL VAR(CddDk4_ConnChannelStructType, CDDDK4_VAR)
                                                          CddDk4_ConnectionChannelInfo[CDDDK4_CONNECTION_CHANNEL_LIMIT];

/*! Struct array with information about DID Status */
CDDDK4_LOCAL VAR(CddDk4_DidBufferElementStructType, CDDDK4_VAR) CddDk4_DidStatusBuffer[CDDDK4_MAX_DIDS_TO_BUFFER];

/*! Struct array with information about DID Status for Application */
CDDDK4_LOCAL VAR(CddDk4_ApplDidBufferElementStructType, CDDDK4_VAR)
                                                            CddDk4_ApplDidStatusBuffer[CDDDK4_CONNECTION_CHANNEL_LIMIT];

#define CDDDK4_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define CDDDK4_START_SEC_VAR_INIT_8BIT
#include "MemMap.h"                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Initialization state of the module */
CDDDK4_LOCAL VAR(uint8, CDDDK4_VAR_INIT) CddDk4_Init_State = CDDDK4_UNINIT;

#define CDDDK4_STOP_SEC_VAR_INIT_8BIT
#include "MemMap.h"                                                                  /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined(CddDk4_MemCopy)
/*! Used for memcpy */
# define CddDk4_MemCopy(dst, src, len)          (VStdMemCpy((dst), (src), (len)))    /* PRQA S 3453 */ /* MD_MSR_19.7 */
#endif

/*! Abstraction for ::CddDk4_SvcSend RDBI requests. */
#define CddDk4_SvcSendRDBI(connId, data, len, callback)             \
            CddDk4_SvcSend(CDDDK4_SERVICE_0x22, connId, data, len, callback)         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for ::CddDk4_SvcSend WDBI requests. */
#define CddDk4_SvcSendWDBI(connId, data, len, callback)             \
            CddDk4_SvcSend(CDDDK4_SERVICE_0x2E, connId, data, len, callback)         /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for #CddDk4_ConnectionChannelAssign Map lookup. */
#define CddDk4_GetConnChannelAssignment(connId)                     \
                     (CddDk4_ConnectionChannelAssign[(connId)])                      /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for #CddDk4_ConnectionChannelAssign Map setting. */
#define CddDk4_SetConnChannelAssignment(connId, value)              \
                     (CddDk4_ConnectionChannelAssign[(connId)] = (value))            /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for #CddDk4_ConnectionChannelAssign Map lookup result is #CDDDK4_NO_CHANNEL_ASSIGNED. */
#define CddDk4_isConnectionFree(connId)                             \
((boolean) (CddDk4_GetConnChannelAssignment(connId) == CDDDK4_NO_CHANNEL_ASSIGNED))  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for setting state counter */
#define CddDk4_SetConStateCounter(connId, value)                    \
                     (CddDk4_ConnectionStateCounter[(connId)] = (value))             /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for getting state counter. */
#define CddDk4_GetConStateCounter(connId)       \
                                      (CddDk4_ConnectionStateCounter[(connId)])      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for incrementing state counter. */
#define CddDk4_IncrementConStateCounter(connId) \
                     (CddDk4_ConnectionStateCounter[(connId)]++)                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for decrementing state counter. */
#define CddDk4_DecrementConStateCounter(connId) \
                     (CddDk4_ConnectionStateCounter[(connId)]--)                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for checking if connection is active. */
#define CddDk4_isConnectionActive(connId)       \
                     ((boolean) (CddDk4_ConnectionStateCounter[(connId)] == 0))      /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for getting DID number by application status buffer index. */
#define CddDk4_GetDid_ApplDidStatusBuffer(idx)     \
                     (CddDk4_ApplDidStatusBuffer[(idx)].did)                         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting DID data pointer by application status buffer index. */
#define CddDk4_GetDataPtr_ApplDidStatusBuffer(idx) \
                     (&CddDk4_ApplDidStatusBuffer[(idx)].didData[0])                 /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting DID size by application status buffer index. */
#define CddDk4_GetDidSize_ApplDidStatusBuffer(idx) \
                     (CddDk4_ApplDidStatusBuffer[(idx)].didSize)                     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting Service ID by application status buffer index. */
#define CddDk4_GetSid_ApplDidStatusBuffer(idx)     \
                     (CddDk4_ApplDidStatusBuffer[(idx)].sid)                         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting retry delay timeout count by application status buffer index. */
#define CddDk4_GetRetryDelay_ApplDidStatusBuffer(idx)   \
                     (CddDk4_ApplDidStatusBuffer[(idx)].retryTimeOut)                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting retry counter by application status buffer index. */
#define CddDk4_GetRetryCounter_ApplDidStatusbuffer(idx) \
                     (CddDk4_ApplDidStatusBuffer[(idx)].retryCounter)                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting buffer status by application status buffer index. */
#define CddDk4_GetStatus_ApplDidStatusbuffer(idx) \
                     (CddDk4_ApplDidStatusBuffer[(idx)].status)                      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting mapped connection ID by application status buffer index. */
#define CddDk4_GetConnId_ApplDidStatusbuffer(idx) \
                     (CddDk4_ApplDidStatusBuffer[(idx)].connId)                      /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for setting DID number by application status buffer index. */
#define CddDk4_SetDid_ApplDidStatusBuffer(idx, value)     \
                 (CddDk4_ApplDidStatusBuffer[(idx)].did = (value))                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting DID size by application status buffer index. */
#define CddDk4_SetDidSize_ApplDidStatusBuffer(idx, value) \
                 (CddDk4_ApplDidStatusBuffer[(idx)].didSize = (value))               /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting Service ID by application status buffer index. */
#define CddDk4_SetSid_ApplDidStatusBuffer(idx, value)     \
                 (CddDk4_ApplDidStatusBuffer[(idx)].sid = (value))                   /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting retry delay timeout count by application status buffer index. */
#define CddDk4_SetRetryDelay_ApplDidStatusBuffer(idx, value) \
                 (CddDk4_ApplDidStatusBuffer[(idx)].retryTimeOut = (value))          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting retry counter by application status buffer index. */
#define CddDk4_SetRetryCounter_ApplDidStatusbuffer(idx, value) \
                 (CddDk4_ApplDidStatusBuffer[(idx)].retryCounter = (value))          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting buffer status by application status buffer index. */
#define CddDk4_SetStatus_ApplDidStatusbuffer(idx, value) \
                 (CddDk4_ApplDidStatusBuffer[(idx)].status = (value))                /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting mapped connection ID to application status buffer index. */
#define CddDk4_SetConnId_ApplDidStatusbuffer(idx, value) \
                 (CddDk4_ApplDidStatusBuffer[(idx)].connId = (value))                /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! Abstraction for getting DID number by status buffer index. */
#define CddDk4_GetDid_DidStatusBuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].did)           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting DID data pointer by status buffer index. */
#define CddDk4_GetDataPtr_DidStatusbuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].dataPtr)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting DID size by status buffer index. */
#define CddDk4_GetDidSize_DidStatusbuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].didSize)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting retry delay timeout count by status buffer index. */
#define CddDk4_GetRetryDelay_DidStatusBuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].retryTimeOut)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting retry counter by status buffer index. */
#define CddDk4_GetRetryCounter_DidStatusbuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].retryCounter)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting buffer status by status buffer index. */
#define CddDk4_GetStatus_DidStatusbuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].status)        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting mapped connection ID by status buffer index. */
#define CddDk4_GetConnId_DidStatusbuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].connId)        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting response code by status buffer index. */
#define CddDk4_GetRespCode_DidStatusbuffer(idx) \
                                       (CddDk4_DidStatusBuffer[(idx)].respCode)      /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Abstraction for setting DID number by status buffer index. */
#define CddDk4_SetDid_DidStatusBuffer(idx, value) \
                              (CddDk4_DidStatusBuffer[(idx)].did = (value))          /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting DID data pointer by status buffer index. */
#define CddDk4_SetDataPtr_DidStatusbuffer(idx, value) \
                              (CddDk4_DidStatusBuffer[(idx)].dataPtr = (value))      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting DID size by status buffer index. */
#define CddDk4_SetDidSize_DidStatusbuffer(idx, value) \
                              (CddDk4_DidStatusBuffer[(idx)].didSize = (value))      /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting retry delay timeout count by status buffer index. */
#define CddDk4_SetRetryDelay_DidStatusBuffer(idx, value) \
                              (CddDk4_DidStatusBuffer[(idx)].retryTimeOut = (value)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting retry counter by status buffer index. */
#define CddDk4_SetRetryCounter_DidStatusbuffer(idx, value) \
                              (CddDk4_DidStatusBuffer[(idx)].retryCounter = (value)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting buffer status by status buffer index. */
#define CddDk4_SetStatus_DidStatusbuffer(idx, value) \
                                (CddDk4_DidStatusBuffer[(idx)].status = (value))     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting mapped connection ID to status buffer index. */
#define CddDk4_SetConnId_DidStatusbuffer(idx, value) \
                                (CddDk4_DidStatusBuffer[(idx)].connId = (value))     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting response code by status buffer index. */
#define CddDk4_SetRespCode_DidStatusbuffer(idx, value) \
                                (CddDk4_DidStatusBuffer[(idx)].respCode = (value))   /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! Abstraction for getting channel timeout by channel ID. */
#define CddDk4_ChannelInfo_GetTimeOut(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].timeout)            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's data payload by channel ID. */
#define CddDk4_ChannelInfo_GetPayload(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].payload)            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's data short-payload by channel ID. */
#define CddDk4_ChannelInfo_GetShortPayload(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].shortPayload)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's connection state by channel ID. */
#define CddDk4_ChannelInfo_GetConState(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].conState)           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's RCR-RP counter by channel ID. */
#define CddDk4_ChannelInfo_GetRCRRPCounter(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].rcrrpCounter)       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's counter to Busy NRC sending by channel ID. */
#define CddDk4_ChannelInfo_GetNrcBusyCounter(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].nrcBusyCounter)     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's assigned connection ID by channel ID. */
#define CddDk4_ChannelInfo_GetConnId(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].connId)             /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's request Service ID by channel ID. */
#define CddDk4_ChannelInfo_GetSvcId(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].svcId)              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's pointer to notification function by channel ID. */
#define CddDk4_ChannelInfo_GetbackFctPtr(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].backFct)            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's current PDU's Sdu Length by channel ID. */
#define CddDk4_ChannelInfo_GetPduInfo_SduLength(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].pduInfo.SduLength)  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's current PDU's Sdu data pointer by channel ID. */
#define CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].pduInfo.SduDataPtr) /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's current PDU's info pointer by channel ID. */
#define CddDk4_ChannelInfo_GetPduInfoPtr(channelId) \
                      (&(CddDk4_ConnectionChannelInfo[(channelId)].pduInfo))         /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's Tx PDU length by channel ID. */
#define CddDk4_ChannelInfo_GetTxPduLength(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].txPduLength)        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for getting channel's buffer position by channel ID. */
#define CddDk4_ChannelInfo_GetBufferPosition(channelId) \
                      (CddDk4_ConnectionChannelInfo[(channelId)].bufPos)             /* PRQA S 3453 */ /* MD_MSR_19.7 */


/*! Abstraction for setting channel timeout by channel ID. */
#define CddDk4_ChannelInfo_SetTimeOut(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].timeout = (value))            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's data payload by channel ID and payload index. */
#define CddDk4_ChannelInfo_SetPayload(channelId, idx, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].payload[idx] = (value))       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's connection state by channel ID. */
#define CddDk4_ChannelInfo_SetConState(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].conState = (value))           /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's RCR-RP counter by channel ID. */
#define CddDk4_ChannelInfo_SetRCRRPCounter(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].rcrrpCounter = (value))       /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's counter to Busy NRC sending by channel ID. */
#define CddDk4_ChannelInfo_SetNrcBusyCounter(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].nrcBusyCounter = (value))     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's assigned connection ID by channel ID. */
#define CddDk4_ChannelInfo_SetConnId(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].connId = (value))             /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's request Service ID by channel ID. */
#define CddDk4_ChannelInfo_SetSvcId(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].svcId = (value))              /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's pointer to notification function by channel ID. */
#define CddDk4_ChannelInfo_SetbackFctPtr(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].backFct = (value))            /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's current PDU's Sdu Length by channel ID. */
#define CddDk4_ChannelInfo_SetPduInfo_SduLength(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].pduInfo.SduLength = (value))  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's current PDU's Sdu data pointer by channel ID. */
#define CddDk4_ChannelInfo_SetPduInfo_SduDataPtr(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].pduInfo.SduDataPtr = (value)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's Tx PDU length by channel ID. */
#define CddDk4_ChannelInfo_SetTxPduLength(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].txPduLength = (value))        /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Abstraction for setting channel's buffer position by channel ID. */
#define CddDk4_ChannelInfo_SetBufferPosition(channelId, value) \
            (CddDk4_ConnectionChannelInfo[(channelId)].bufPos = (value))             /* PRQA S 3453 */ /* MD_MSR_19.7 */



/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CDDDK4_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * CddDk4_SvcSend()
 *********************************************************************************************************************/
/*!
 * \brief   Starts new service request on a configured connection.
 * \details Try to start new service request on the connection corresponding to the passed connection ID.
 *
 * \param[in]   svcId       UDS Service Id
 * \param[in]   connId      connection ID
 * \param[in]   requestData Pointer to request data array
 * \param[in]   length      Request data length
 * \param[in]   callback    Pointer to Notification Function
 * \pre -
 * \trace       DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 * \return      CDDDK4_RET_OK:              Service request accepted.
 * \return      CDDDK4_RET_NO_FREE_CHANNEL: Service request cannot be accepted, no free channel is available.
 * \return      CDDDK4_RET_CONNECTION_BUSY: Service request cannot be accepted, connection is already busy.
 * \return      CDDDK4_RET_NOT_OK:          Service Request is not accepted.
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_SvcSend(
                                                      CddDk4_ServiceIdType svcId,
                                                      CddDk4_ConnectionIdType connId,
                                                      P2CONST(CddDk4_RespDataType, AUTOMATIC, CDDDK4_CONST) requestData,
                                                      CddDk4_LengthType length,
                                                      CddDk4_NotifyFunctionPtr callback);


/**********************************************************************************************************************
 CddDk4_TransmitService()
 *********************************************************************************************************************/
/*!
 * \brief   Transmits a pending request.
 * \details Transmits the connection channel data through PduR.
 *
 * \param[in]   connId Connection ID
 * \pre -
 * \trace       DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 * \return      E_OK:     Request sent successfully.
 * \return      E_NOT_OK: Otherwise.
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_TransmitService(CddDk4_ConnectionIdType connId);


/**********************************************************************************************************************
 * CddDk4_ConnManagerStart()
 *********************************************************************************************************************/
/*!
 * \brief   Assigns and initializes a free channel to a connection.
 * \details If the connection was not already open and a free channel is available; the channel is assigned to the
 *          connection and is initialized.
 *
 * \param[in]  svcId    Service ID.
 * \param[in]  connId   Connection ID.
 * \param[in]  callback Pointer to Notification Function.
 * \pre      Expects that interrupts disabled
 * \trace    DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 * \return   CDDDK4_RET_OK:              Connection channel initialized successfully.
 * \return   CDDDK4_RET_NO_FREE_CHANNEL: Connection channel not initialized successfully, no free channel available.
 * \return   CDDDK4_RET_CONNECTION_BUSY: Connection is busy.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_ConnManagerStart(CddDk4_ServiceIdType svcId,
                                                                                 CddDk4_ConnectionIdType connId,
                                                                                 CddDk4_NotifyFunctionPtr callback);


/**********************************************************************************************************************
 CddDk4_ConnManagerStateTask()
 *********************************************************************************************************************/
/*!
 * \brief   Manages open channels' states.
 * \details Manages open channels' states except for delays and timeouts.
 *
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerStateTask(void);


/**********************************************************************************************************************
 CddDk4_ConnectionTimerTask()
 *********************************************************************************************************************/
/*!
 * \brief    Manages open channels' delays and timeouts.
 * \details  Manages open channels' delays between subsequent requests and timeouts.
 *
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796, DSGN-CddDk422800
 **********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ConnectionTimerTask(void);


/**********************************************************************************************************************
CddDk4_RequestManagerStateTask()
 *********************************************************************************************************************/
/*!
 * \brief   Manages open DID Requests.
 * \details Manages open DID Requests.
 *
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 **********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_RequestManagerStateTask(void);


/**********************************************************************************************************************
CddDk4_RequestManagerTimerTask()
 *********************************************************************************************************************/
/*!
 * \brief   Manages open DID Requests' delays, timeouts, and retries.
 * \details Manages open DID Requests' delays, timeouts, and retries.
 *
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796, DSGN-CddDk422800
 **********************************************************************************************************************/
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_RequestManagerTimerTask(void);


/**********************************************************************************************************************
 *  CddDk4_ConnManagerChClose()
 *********************************************************************************************************************/
/*!
 * \brief   Closes a connection channel.
 * \details Closes connection channel, calls the notification function, removes assignment to connection, and updates
 *          #CddDk4_ActiveConnectionChannels appropriately.
 *
 * \param[in] channelId            Channel ID to be closed.
 * \param[in] responseCode         With which the notification callback will be called.
 * \param[in] suppressNotification Whether the function should suppress application notification.
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerChClose(CddDk4_ConnChannelIdType channelId,
                                                               CddDk4_RespInfoType responseCode,
                                                               boolean suppressNotification);


/**********************************************************************************************************************
 *  CddDk4_ConnManagerGetAndInitFreeChannel()
 *********************************************************************************************************************/
/*!
 * \brief   Looks for and assigns a free channel to a connection.
 * \details Looks for and assigns a free channel to a connection, returns the first free channel that was found,
 *          #CDDDK4_NO_CHANNEL_ASSIGNED otherwise.
 *
 * \param[in] connId Connection ID to which the channel should be assigned.
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 * \return    Assigned Channel ID in case a free channel was found.
 * \return    #CDDDK4_NO_CHANNEL_ASSIGNED otherwise.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ConnChannelIdType, CDDDK4_CODE) CddDk4_ConnManagerGetAndInitFreeChannel(
                                                                                        CddDk4_ConnectionIdType connId);


/**********************************************************************************************************************
 *  CddDk4_ConnManagerVerifyResponse()
 *********************************************************************************************************************/
/*!
 * \brief    Verifies response.
 * \details Verifies response buffer, if positive advances the state, if negative calls
 *          ::CddDk4_ConnManagerVerifyNegativeResponse, if positive for the wrong service ID closes the channel.
 *
 * \param[in] channelId Channel ID
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyResponse(
                                                               CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) channelId);


/**********************************************************************************************************************
 *  CddDk4_ConnManagerVerifyRCRRP()
 *********************************************************************************************************************/
/*!
 * \brief   Manages a received RCRRP
 * \details Checks internal count of RCR-RPs, resets the response timers if the counter is still less than than the
 *          maximum allowed and sets the channel to the appropriate state, closes the channel otherwise.
 *
 * \param[in] channelId Channel ID
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyRCRRP(
                                                               CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) channelId);


/**********************************************************************************************************************
 *  CddDk4_ConnManagerVerifyBRR()
 *********************************************************************************************************************/
/*!
 * \brief   Manages busy repeat request responses.
 * \details Manages busy repeat request responses, checks the maximum number configured (if any) and handles
 *          the internal counter.
 *
 * \param[in] channelId  Channel ID for which the BRR will be managed.
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyBRR(
                                                               CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) channelId);


/**********************************************************************************************************************
 * CddDk4_ApplResponseNotify()
 *********************************************************************************************************************/
/*!
 * \brief   Manages application response notification.
 * \details Checks #CddDk4_ApplDidStatusBuffer for correct request, checks the correct service ID and calls the
 *          appropriate notification function.
 *
 * \param[in] response The response info structure that will be processed.
 * \pre -
 * \trace DSGN-CddDk422795, DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ApplResponseNotify(
                                                    P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response);


/**********************************************************************************************************************
 * CddDk4_ResponseNotify()
 *********************************************************************************************************************/
/*!
 * \brief   Manages communication manager response notification.
 * \details Checks #CddDk4_DidStatusBuffer for correct request, checks the correct service ID and calls the
 *          appropriate notification function.
 *
 * \param[in] response The response info structure that will be processed.
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793
 *********************************************************************************************************************/
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ResponseNotify(
                                                    P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response);


#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
/**********************************************************************************************************************
 * CddDk4_GetConnIdTxPdu()
 *********************************************************************************************************************/
/*!
 * \brief   Provides the connection ID corresponding to the passed Tx PDU ID.
 * \details Searches the connection configuration for a Tx PDU ID matching the passed Tx PDU ID, if found returns
 *          the connection ID, if not found returns #CDDDK4_INVALID_CONNECTION_ID.
 *
 * \param[in] txPdu TxPdu Id
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is off, otherwise it's a macro declared in CddDk4_Cfg.h
 * \trace DSGN-CddDk422797
 * \return If a connection is found with a matching Tx PDU ID then that connection ID is returned.
 * \return #CDDDK4_INVALID_CONNECTION_ID otherwise.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ConnectionIdType, CDDDK4_CODE) CddDk4_GetConnIdTxPdu(PduIdType txPdu);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 * CddDk4_GetDIDConnectionId()
 *********************************************************************************************************************/
/*!
 * \brief   Provides the connection ID corresponding to the passed DID number.
 * \details Searches #CddDk4_DidTable for the passed DID number and if found returns the assigned connection ID, if not
 *          found returns #CDDDK4_INVALID_CONNECTION_ID.
 *
 * \param[in]  did      DID number
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793
 * \return If a connection is found with a matching DID number then that connection ID is returned.
 * \return #CDDDK4_INVALID_CONNECTION_ID otherwise.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ConnectionIdType, CDDDK4_CODE) CddDk4_GetDIDConnectionId(CddDk4_DidIdentifierType did);


/**********************************************************************************************************************
 * CddDk4_TxConfirmation_Internal()
 *********************************************************************************************************************/
/*!
 * \brief      Common implementation of Tx Confirmation for PduR 3 and 4 schemes.
 * \details    Common implementation of Tx Confirmation for PduR 3 and 4 schemes, checks if in the appropriate state,
 *             moves the state forward or logs an error.
 *
 * \param[in]  CddDk4TxPduId  incoming Pdu Id
 * \param[in]  Result         transmission result
 * \pre -
 * \trace DSGN-CddDk422797, DSGN-CddDk422798
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_TxConfirmation_Internal(
                               CONST(PduIdType, AUTOMATIC) CddDk4TxPduId, CONST(CddDk4_TpResultType, AUTOMATIC) Result);


/**********************************************************************************************************************
 * CddDk4_RxIndication_Internal()
 *********************************************************************************************************************/
/*!
 * \brief   Common implementation of Rx Confirmation for PduR 3 and 4 schemes.
 * \details Common implementation of Rx Confirmation for PduR 3 and 4 schemes, checks if in the appropriate state, moves
 *          the state forward or logs an error.
 *
 * \param[in]  CddDk4RxPduId  incoming Pdu Id
 * \param[in]  Result         reception result
 * \pre -
 * \trace DSGN-CddDk422797, DSGN-CddDk422798
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_RxIndication_Internal(
                               CONST(PduIdType, AUTOMATIC) CddDk4RxPduId, CONST(CddDk4_TpResultType, AUTOMATIC) Result);


#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
 * CddDk4_CopyPduIntoBuffer()
 *********************************************************************************************************************/
/*!
 * \brief   Copies an incoming Pdu into the Rx Buffer.
 * \details Performs some common parameter checks and copies an incoming PDU into the Rx buffer, adjusts the buffer
 *          position, and sets the remaining buffer length.
 *
 * \param[in]  ChannelId     The channel for which the state is checked and the data is copied into its buffer.
 * \param[in]  PduInfoPtr    The PDU to copied inside the buffer.
 * \param[out] BufferSizePtr The remaining buffer size to the upper layer.
 * \param[in]  ServiceId     The ServiceId to be used to report Det errors if Det errors are enabled.
 * \pre -
 * \config CDDDK4_AR4_PDUR_SUPPORT is on.
 * \trace DSGN-CddDk422798
 * \return BUFREQ_E_NOT_OK: If error detected.
 * \return BUFREQ_OK:       Otherwise.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_CopyPduIntoBuffer(
                                                        CddDk4_ConnChannelIdType ChannelId,
                                                        P2CONST(PduInfoType, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr,
                                                        P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr,
                                                        uint8 ServiceId);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 * CddDk4_ProvideBuffer()
 *********************************************************************************************************************/
/*!
 * \brief   Assigns a buffer to a certain channel
 * \details Checks channel state, validates requested buffer size, and assigns an appropriate buffer depending on the
 *          size, in case of AR3 PduR returns a Pdu Info Ptr pointing to the buffer, in case of AR4 PduR returns the
 *          allocated buffer size.
 *
 * \param[in]  ChannelId     The channel to check its state and assign the buffer.
 * \param[in]  TpSduLength   The length of the message to be received in the buffer.
 * \param[out] BufferSizePtr AR4 PduR: The returned allocated buffer size.
 * \param[out] PduInfoPtr    AR3 PduR: The returned PduInfoPtr pointing to the buffer allocated.
 * \pre -
 * \trace DSGN-CddDk422797, DSGN-CddDk422798
 * \return BUFREQ_E_NOT_OK: If parameter check fails.
 * \return BUFREQ_E_OVFL:   If requested TpSduLength is bigger than the maximum buffer size that can be allocated.
 * \return BUFREQ_OK:       Otherwise.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_ProvideBuffer(
                                                      CddDk4_ConnChannelIdType ChannelId,
                                                      PduLengthType TpSduLength,
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
                                                      P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr);
#else /* CDDDK4_AR4_PDUR_SUPPORT */
                                                      P2VAR(PduInfoTypeApplPtr, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 * CddDk4_ClearDidStatusBuffer()
 *********************************************************************************************************************/
/*!
 * \brief     Resets #CddDk4_DidStatusBuffer to its initial values.
 * \details   #CddDk4_DidStatusBuffer members are all set to their initial values and the states are set to
 *            #CDDDK4_DID_STATUS_UNKNOWN.
 *
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ClearDidStatusBuffer(void);


/**********************************************************************************************************************
 * CddDk4_VerifyPositiveResponse()
 *********************************************************************************************************************/
/*!
 * \brief   Verifies Positive Response.
 * \details Validates positive response to be to a requested DID and contains some data, returns #CDDDK4_DID_AVAILABLE
 *          or #CDDDK4_DID_UNAVAILABLE depending on the result.
 *
 * \param[in] statusBufferIdx Index to DidStatusBuffer assigned to the response.
 * \param[in] response        The response info structure that will be processed.
 * \pre -
 * \trace DSGN-CddDk422792
 * \return      CDDDK4_DID_AVAILABLE:   DID is available
 * \return      CDDDK4_DID_UNAVAILABLE: DID is unavailable
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(CddDk4_DidStatusType, CDDDK4_CODE) CddDk4_VerifyPositiveResponse(
                                                  CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                  P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_CONST) response);


/**********************************************************************************************************************
 * CddDk4_ProcessDidRequest()
 *********************************************************************************************************************/
/*!
 * \brief   Processes a DID request.
 * \details Processes a DID request in #CDDDK4_DID_WAITING_REQUEST state, initiates the request through
 *          ::CddDk4_ProcessDidReadRequest if not already started and handles cancellation.
 *
 * \param[in] statusBufferIdx  Index to DidStatusBuffer assigned to the request.
 * \trace       DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422799
 * \pre -
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ProcessDidRequest(CddDk4_DidStatusBufferIdxType statusBufferIdx);


/**********************************************************************************************************************
 * CddDk4_ProcessDidReadRequest()
 *********************************************************************************************************************/
/*!
 * \brief   Processes a DID read request.
 * \details Processes a DID read request and attempts to schedule it through calling #CddDk4_SvcSendRDBI.
 *
 * \param[in] statusBufferIdx  Index to DidStatusBuffer assigned to the request.
 * \param[in] connId           Connection Id assigned to DID
 * \pre -
 * \trace DSGN-CddDk422792
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ProcessDidReadRequest(CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                                         CddDk4_ConnectionIdType connId);


/**********************************************************************************************************************
 * CddDk4_ProcessDidWriteRequest()
 *********************************************************************************************************************/
/*!
 * \brief   Processes a DID write request.
 * \details Processes a DID write request and attempts to schedule it through calling #CddDk4_SvcSendWDBI.
 *
 * \param[in] statusBufferIdx  Index to DidStatusBuffer assigned to the request.
 * \pre -
 * \trace DSGN-CddDk422793
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ProcessDidWriteRequest(
                                                                         CddDk4_DidStatusBufferIdxType statusBufferIdx);


/**********************************************************************************************************************
 * CddDk4_ApplProcessDidRequest()
 *********************************************************************************************************************/
/*!
 * \brief   Processes DID requests from application.
 * \details Processes a DID request from application and attempts to schedule it through calling #CddDk4_SvcSendRDBI
 *          or #CddDk4_SvcSendWDBI.
 *
 * \param[in] statusBufferIdx Index to application DidStatusBuffer assigned to the request.
 * \pre -
 * \trace DSGN-CddDk422795, DSGN-CddDk422796, DSGN-CddDk422799
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ApplProcessDidRequest(CddDk4_DidStatusBufferIdxType statusBufferIdx);


/**********************************************************************************************************************
 * CddDk4_IsDidAvailable_Pending()
 *********************************************************************************************************************/
/*!
 * \brief   Provides availability status of a pending DID.
 * \details If DID availability status is known, result is reported via \c supported and \c E_OK is returned, if still
 *          pending then DCM_E_PENDING is returned.
 *
 * \param[in]   DID       DID number.
 * \param[out]  supported Indicates if the DID is available or not.
 * \pre -
 * \trace DSGN-CddDk422792
 * \return      E_OK:          Request was successful
 * \return      DCM_E_PENDING: Request is still pending
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_IsDidAvailable_Pending(
                                                          uint16 DID,
                                                          P2VAR(Dcm_DidSupportedType, AUTOMATIC, CDDDK4_VAR) supported);


/**********************************************************************************************************************
 * CddDk4_AddDidRequest()
 *********************************************************************************************************************/
/*!
 * \brief   Adds DID request to DID status buffer.
 * \details Called from initial ::CddDk4_IsDidAvailable to process the DID request in the next main task cycle.
 *
 * \param[in] statusBufferIdx Index to DidStatusBuffer assigned to request DID
 * \return E_OK:     DID was added successfully.
 * \return E_NOT_OK: DID was not added; DID status buffer is full.
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_AddDidRequest(uint16 DID);


/**********************************************************************************************************************
 * CddDk4_WriteDidData_Pending()
 *********************************************************************************************************************/
/*!
 * \brief   Handles write request in Dcm state PENDING.
 * \details Verifies request status and returning result to caller.
 *
 * \param[in]   DID            DID Identifier
 * \param[out]  ErrorCode      NRC to be sent in case of a negative response (E_NOT_OK)
 * \pre -
 * \trace DSGN-CddDk422793
 * \return      E_OK:          Request was successful
 * \return      E_NOT_OK:      Request was not successful
 * \return      DCM_E_PENDING: Request is not finished. Further call(s) required to finish
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_WriteDidData_Pending(
                                                  uint16 DID,
                                                  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_VAR) ErrorCode);

#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
/**********************************************************************************************************************
 * CddDk4_WriteRemoteDidData_Internal()
 *********************************************************************************************************************/
/*!
 * \brief   Sets up an application DID status buffer entry for a write request.
 * \details Sets up an application DID status buffer entry for a write request by putting it in the appropriate state,
 *          copying the data to be written in the internal buffer, and updating #CddDk4_ApplRequestedDidsCount.
 *
 * \param[in]   DID        DID number
 * \param[in]   connId     Connection ID to which DID data shall be written.
 * \param[in]   Data       Pointer to DID data.
 * \param[in]   DataLength Length of the data to be written.
 * \pre -
 * \trace DSGN-CddDk422796
 * \return E_OK:                       Request was successful.
 * \return CDDDK4_RET_NO_FREE_CHANNEL: Request was not successful, All connection channels are busy.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_WriteRemoteDidData_Internal(
                                                                        uint16 DID,
                                                                        CddDk4_ConnectionIdType connId,
                                                                        P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) Data,
                                                                        uint16 DataLength);
#endif /* CDDDK4_CFG_SUPPORT_APPLNOTIFY */


/**********************************************************************************************************************
 * CddDk4_WriteDidData_Initial()
 *********************************************************************************************************************/
/*!
 * \brief   Handles Write DID Data request in Dcm state INITIAL.
 * \details Processes Write DID Data request is Dcm state INITIAL, checks if all conditions are correct, and sets up
 *          an entry in #CddDk4_DidStatusBuffer for the request.
 *
 * \param[in]   DID            DID Identifier
 * \param[in]   Data           Pointer to DID data
 * \param[in]   DataLength     Length of the data to be written
 * \param[out]  ErrorCode      NRC to be sent in case of a negative response (E_NOT_OK)
 * \pre -
 * \trace DSGN-CddDk422793
 * \return      E_NOT_OK:      Request was not successful.
 * \return      DCM_E_PENDING: Request is scheduled, Further call(s) required to finish.
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_WriteDidData_Initial(
                                             uint16 DID,
                                             P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) Data,
                                             uint16 DataLength,
                                             P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_APPL_VAR) ErrorCode);


/**********************************************************************************************************************
 * CddDk4_ApplResponseNotify_Svc22()
 *********************************************************************************************************************/
/*!
 * \brief   Calculates the response to be sent in the application notification for service 0x22.
 * \details Calculates the response to be sent in the application notification in response to an earlier service 0x22
 *          request based on the result of the request and internal states.
 *
 * \param[in] statusBufferIdx Index to application DID status buffer corresponding to response.
 * \param[in] response        The response info structure that will be processed.
 * \pre -
 * \trace DSGN-CddDk422795
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ApplResponseNotify_Svc22(
                                                    CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                    P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response);


/**********************************************************************************************************************
 * CddDk4_ApplResponseNotify_Svc2E()
 *********************************************************************************************************************/
/*!
 * \brief   Calculates the response to be sent in the application notification for service 0x2E.
 * \details Calculates the response to be sent in the application notification in response to an earlier service 0x2E
 *          request based on the result of the request and internal states.
 *
 * \param[in] statusBufferIdx Index to application DID status buffer corresponding to response.
 * \param[in] response        The response info structure that will be processed.
 * \pre -
 * \trace DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ApplResponseNotify_Svc2E(
                                                    CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                    P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response);


/**********************************************************************************************************************
 * CddDk4_ResponseNotify_Svc22()
 *********************************************************************************************************************/
/*!
 * \brief   Called from ::CddDk4_ResponseNotify to continue the notification specific to service 0x22.
 * \details Checks for positive response, manages reported timeouts and sets up the retry state if applicable, and
 *          manages negative responses.
 *
 * \param[in] statusBufferIdx DID status buffer index corresponding to response.
 * \param[in] response        The response info structure that will be processed.
 * \pre -
 * \trace DSGN-CddDk422792
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ResponseNotify_Svc22(
                                                    CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                    P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response);


/**********************************************************************************************************************
 * CddDk4_ResponseNotify_Svc2E()
 *********************************************************************************************************************/
/*!
 * \brief   Called from ::CddDk4_ResponseNotify to continue the notification specific to service 0x2E.
 * \details Checks and validates positive response, manages reported timeouts and sets up the retry state if applicable,
 *          and manages negative responses.
 * \param[in] statusBufferIdx DID status buffer index corresponding to response
 * \param[in] response        The response info structure that will be processed.
 * \pre -
 * \trace DSGN-CddDk422793
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ResponseNotify_Svc2E(
                                                    CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                    P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response);


/**********************************************************************************************************************
 * CddDk4_ConnManagerVerifyNegativeResponse()
 *********************************************************************************************************************/
/*!
 * \brief   Verifies negative response format.
 * \details Verifies negative response length and format, forwards to the appropriate negative response handler if
 *          valid, and closes the channel if invalid.
 * \param[in]   ChannelId     Channel ID
 * \pre -
 * \trace DSGN-CddDk422792, DSGN-CddDk422793, DSGN-CddDk422795, DSGN-CddDk422796
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyNegativeResponse(
                                                               CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) ChannelId);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/* -------------------------------------------------------------------------------------------------------------------*/
/* Request Manager                                                                                                    */
/* -------------------------------------------------------------------------------------------------------------------*/

/**********************************************************************************************************************
 *CddDk4_ApplResponseNotify_Svc22()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ApplResponseNotify_Svc22(
                                                     CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                     P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response)
{
#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ApplRespInfoStructType lNotify;

  /* ----- Implementation ----------------------------------------------- */
  lNotify.connId = response->connId;
  lNotify.respCode = response->respCode;
  lNotify.dataLength = response->dataLength;
  lNotify.sid = response->serviceId;
  lNotify.did = CddDk4_GetDid_ApplDidStatusBuffer(statusBufferIdx);

  if (lNotify.dataLength > 0)
  {
    lNotify.respData = &response->respData[0];
  }

  if (response->respCode == CDDDK4_NOTIFY_POSITIVE_RESPONSE)
  {
    if (lNotify.dataLength > 2)
    {
      /* data length must at least contain the DID identifier and 1 byte DID data */
      uint16 lDid = 0;
      lDid = (lDid | response->respData[0]) << 8;
      lDid = lDid | response->respData[1];

      if (CddDk4_GetDid_ApplDidStatusBuffer(statusBufferIdx) == lDid)
      {
        /* DID Identifier is equal to requested DID Identifier */
        lNotify.respData = &(response->respData[2]);
        lNotify.dataLength = lNotify.dataLength - 2;
      }
      else
      {
        lNotify.respCode = CDDDK4_NOTIFY_INVALID_DID;
      }
    }
    else
    {
      lNotify.respCode = CDDDK4_NOTIFY_RESPONSE_TOO_SHORT;
    }
  }

  CddDk4_SetStatus_ApplDidStatusbuffer(statusBufferIdx, CDDDK4_DID_STATUS_UNKNOWN);
  CddDk4_EnterExclusiveAreaReqMgr();
  CddDk4_ApplRequestedDidsCount--;
  CddDk4_LeaveExclusiveAreaReqMgr();

  (void)CDDDK4_CFG_APPLNOTIFY(&lNotify);
#else
  CDDDK4_DUMMY_STATEMENT(statusBufferIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(response);        /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/**********************************************************************************************************************
 *CddDk4_ApplResponseNotify_Svc2E()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ApplResponseNotify_Svc2E(
                                                     CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                     P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response)
{
#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ApplRespInfoStructType lNotify;

  /* ----- Implementation ----------------------------------------------- */
  lNotify.connId = response->connId;
  lNotify.respCode = response->respCode;
  lNotify.dataLength = response->dataLength;
  lNotify.sid = response->serviceId;
  lNotify.did = CddDk4_GetDid_ApplDidStatusBuffer(statusBufferIdx);

  if (lNotify.dataLength > 0)
  {
    lNotify.respData = &response->respData[0];
  }

  if ((response->respCode == CDDDK4_NOTIFY_POSITIVE_RESPONSE))
  {
    if (response->dataLength == 2)
    {
      /* data length must at least contain the  DID identifier */
      uint16 lDid = 0;
      lDid = (lDid | response->respData[0]) << 8;
      lDid = lDid | response->respData[1];

      if (CddDk4_GetDid_ApplDidStatusBuffer(statusBufferIdx) != lDid)
      {
        /* DID Identifier in response is not equal to requested DID Identifier */
        lNotify.respCode = CDDDK4_NOTIFY_INVALID_DID;
      }
      else
      {
        /* response data includes only DID; response data struct contains DID already */
        lNotify.dataLength = 0;
      }
    }
    else if (response->dataLength < 2)
    {
      lNotify.respCode = CDDDK4_NOTIFY_RESPONSE_TOO_SHORT;
    }
    else
    {
      lNotify.respCode = CDDDK4_NOTIFY_RESPONSE_TOO_LONG;
    }
  }

  CddDk4_SetStatus_ApplDidStatusbuffer(statusBufferIdx, CDDDK4_DID_STATUS_UNKNOWN);
  CddDk4_EnterExclusiveAreaReqMgr();
  CddDk4_ApplRequestedDidsCount--;
  CddDk4_LeaveExclusiveAreaReqMgr();

  (void)CDDDK4_CFG_APPLNOTIFY(&lNotify);
#else
  CDDDK4_DUMMY_STATEMENT(statusBufferIdx); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(response);        /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}


#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
/**********************************************************************************************************************
 *CddDk4_WriteRemoteDidData_Internal()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_WriteRemoteDidData_Internal(
                                                                        uint16 DID,
                                                                        CddDk4_ConnectionIdType connId,
                                                                        P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) Data,
                                                                        uint16 DataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult;

  /* ----- Implementation ----------------------------------------------- */
  CddDk4_EnterExclusiveAreaReqMgr();
  if (CddDk4_ApplRequestedDidsCount < CDDDK4_CONNECTION_CHANNEL_LIMIT)
  {
    /* application DID status buffer is not full */
    /* looking for free position in application status buffer */
    CddDk4_DidStatusBufferIdxType lStatusIdx = 0;
    while (  (lStatusIdx < CDDDK4_CONNECTION_CHANNEL_LIMIT)
           &&(CddDk4_GetStatus_ApplDidStatusbuffer(lStatusIdx) != CDDDK4_DID_STATUS_UNKNOWN))
    {
      lStatusIdx++;
    }

    if (lStatusIdx < CDDDK4_CONNECTION_CHANNEL_LIMIT)
    {
      /* free space was found */
      CddDk4_SetStatus_ApplDidStatusbuffer(lStatusIdx, CDDDK4_DID_WAITING_REQUEST);
      CddDk4_GetDataPtr_ApplDidStatusBuffer(lStatusIdx)[0] = (uint8)(DID >> 8);
      CddDk4_GetDataPtr_ApplDidStatusBuffer(lStatusIdx)[1] = (uint8)DID;
      CddDk4_MemCopy(&CddDk4_GetDataPtr_ApplDidStatusBuffer(lStatusIdx)[2], Data, DataLength);

      CddDk4_SetDid_ApplDidStatusBuffer(lStatusIdx, DID);
      CddDk4_SetSid_ApplDidStatusBuffer(lStatusIdx, CDDDK4_SERVICE_0x2E);
      CddDk4_SetRetryCounter_ApplDidStatusbuffer(lStatusIdx, CDDDK4_CFG_MAX_REQUEST_RETRIES);
      CddDk4_SetRetryDelay_ApplDidStatusBuffer(lStatusIdx, CDDDK4_CFG_REQUEST_RETRY_DELAY);
      CddDk4_SetConnId_ApplDidStatusbuffer(lStatusIdx, connId);
      CddDk4_SetDidSize_ApplDidStatusBuffer(lStatusIdx, (DataLength + 2));

      CddDk4_ApplRequestedDidsCount++;
      lResult = CDDDK4_RET_OK;
    }
    else
    {
      lResult = CDDDK4_RET_NO_FREE_CHANNEL;
    }
  }
  else
  {
    lResult = CDDDK4_RET_NO_FREE_CHANNEL;
  }
  CddDk4_LeaveExclusiveAreaReqMgr();

  return lResult;
}
#endif /* CDDDK4_CFG_SUPPORT_APPLNOTIFY */


/**********************************************************************************************************************
 *CddDk4_WriteDidData_Initial()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_WriteDidData_Initial(
                                              uint16 DID,
                                              P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) Data,
                                              uint16 DataLength,
                                              P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_APPL_VAR) ErrorCode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult = E_NOT_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;
  /* Service 0x2E only allowed for single DIDs; multi DID request are not allowed; lIdx set to 0 */
  CddDk4_DidStatusBufferIdxType lIdx = 0;

  /* ----- Implementation ----------------------------------------------- */
  if (  (CddDk4_GetDid_DidStatusBuffer(lIdx) == DID)
      &&(CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_WAITING_WRITE_DATA))
  {
    if (DataLength <= CDDDK4_DID_DATA_BUFFER_SIZE)
    {
      CddDk4_DidDataBuffer[0] = (uint8)(CddDk4_GetDid_DidStatusBuffer(lIdx) >> 8);
      CddDk4_DidDataBuffer[1] = (uint8)CddDk4_GetDid_DidStatusBuffer(lIdx);

      CddDk4_MemCopy(&CddDk4_DidDataBuffer[2], Data, DataLength);
      CddDk4_SetDataPtr_DidStatusbuffer(lIdx, &CddDk4_DidDataBuffer[0]);
      CddDk4_SetDidSize_DidStatusbuffer(lIdx, (DataLength + 2));

      CddDk4_SetRetryDelay_DidStatusBuffer(lIdx, CDDDK4_CFG_REQUEST_RETRY_DELAY);
      CddDk4_SetRetryCounter_DidStatusbuffer(lIdx, CDDDK4_CFG_MAX_REQUEST_RETRIES);

      CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_WAITING_WRITE_REQUEST);
      lResult = DCM_E_PENDING;
    }
    else
    {
      *ErrorCode = DCM_E_TRANSFERDATASUSPENDED;
    }
  }
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  else
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
#endif

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_WRITE_DIDDATA_INTERNAL, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
}


/**********************************************************************************************************************
 *CddDk4_WriteDidData_Pending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_WriteDidData_Pending(
                                                   uint16 DID,
                                                   P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_VAR) ErrorCode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult = E_NOT_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* Write DID does not support multi DID request; only one DID should be in buffer */
  CddDk4_DidStatusBufferIdxType lIdx = 0;

  /* ----- Implementation ----------------------------------------------- */
  if (CddDk4_GetDid_DidStatusBuffer(lIdx) == DID)
  {
    if (CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_WRITE_FINISHED)
    {
      CddDk4_RespInfoType lRespCode = CddDk4_GetRespCode_DidStatusbuffer(lIdx);
      switch (lRespCode)
      {
      case CDDDK4_NOTIFY_POSITIVE_RESPONSE:
        lResult = E_OK;
        break;

      case CDDDK4_NOTIFY_NEGATIVE_RESPONSE:
        *ErrorCode = CddDk4_GetDataPtr_DidStatusbuffer(lIdx)[0];
        break;

      case CDDDK4_NOTIFY_CONNECTION_TIMEOUT:
      case CDDDK4_NOTIFY_RESPONSE_TOO_SHORT:
      case CDDDK4_NOTIFY_RESPONSE_FAILED:
      case CDDDK4_NOTIFY_INVALID_SID:
      case CDDDK4_NOTIFY_INVALID_DID:
      case CDDDK4_NOTIFY_RESPONSE_TOO_LONG:
        *ErrorCode = DCM_E_NORESPONSEFROMSUBNETCOMPONENT;
        break;

      case CDDDK4_NOTIFY_RCRRP_LIMIT_REACHED:
      case CDDDK4_NOTIFY_BUSY_LIMIT_REACHED:
        *ErrorCode = DCM_E_GENERALREJECT;
        break;

      case CDDDK4_NOTIFY_REQUEST_FAILED:
        *ErrorCode = DCM_E_TRANSFERDATASUSPENDED;
        break;

      default:
        break;
      }
    }
    else if (CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_REQUEST_IN_PROGRESS)
    {
      lResult = DCM_E_PENDING;
    }
    else
    {
      *ErrorCode = DCM_E_GENERALREJECT;
    }
  }
  else
  {
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    errorId = CDDDK4_E_PARAM_VALUE;
#endif
    *ErrorCode = DCM_E_NORESPONSEFROMSUBNETCOMPONENT;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_WRITE_DIDDATA_INTERNAL, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
}


/**********************************************************************************************************************
 *CddDk4_AddDidRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_AddDidRequest(uint16 DID)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult = E_NOT_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  CddDk4_EnterExclusiveAreaReqMgr();
  if (CddDk4_CurrentStatusBufferIdx < CDDDK4_MAX_DIDS_TO_BUFFER)
  {
    /* DID request can be stored in DID status buffer */
    CddDk4_SetDid_DidStatusBuffer(CddDk4_CurrentStatusBufferIdx, DID);
    CddDk4_SetRetryDelay_DidStatusBuffer(CddDk4_CurrentStatusBufferIdx, CDDDK4_CFG_REQUEST_RETRY_DELAY);
    CddDk4_SetRetryCounter_DidStatusbuffer(CddDk4_CurrentStatusBufferIdx, CDDDK4_CFG_MAX_REQUEST_RETRIES);
    CddDk4_SetStatus_DidStatusbuffer(CddDk4_CurrentStatusBufferIdx, CDDDK4_DID_WAITING_REQUEST);
    CddDk4_CurrentStatusBufferIdx++;
    lResult = E_OK;
  }
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  else
  {
    /* DID status buffer is out of memory */
    errorId = CDDDK4_E_DID_STATUS_BUFFER_OUT_OF_RANGE;
  }
#endif
  CddDk4_LeaveExclusiveAreaReqMgr();

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_INTERNAL, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
}


/**********************************************************************************************************************
 *CddDk4_IsDidAvailable_Pending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_IsDidAvailable_Pending(
                                                           uint16 DID,
                                                           P2VAR(Dcm_DidSupportedType, AUTOMATIC, CDDDK4_VAR) supported)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult = E_OK;
  CddDk4_DidStatusBufferIdxType lIdx = 0;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* DIDs that are not pending any more should not be requested with OpStatus DCM_PENDING; look for unreported DID */
  {
    while (  (lIdx < CddDk4_CurrentStatusBufferIdx)
           &&(  (CddDk4_GetDid_DidStatusBuffer(lIdx) != DID)
              ||(CddDk4_GetStatus_DidStatusbuffer(lIdx) > CDDDK4_DID_STATUS_PENDING))
      )
    {
      lIdx++;
    }
  }

  if (lIdx < CddDk4_CurrentStatusBufferIdx)
  {
    /* get status of DID */
    CddDk4_DidStatusType lDidStatus = CddDk4_GetStatus_DidStatusbuffer(lIdx);

    if (lDidStatus == CDDDK4_DID_UNAVAILABLE)
    {
      /* report requested DID as unavailable */
      CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_REPORTED_UNAVAILABLE);
      *supported = DCM_DID_NOT_SUPPORTED;
    }
    else if (lDidStatus == CDDDK4_DID_AVAILABLE)
    {
      /* report requested  DID as available and wait for read or write data Callback */
      if (CddDk4_RequestedService == CDDDK4_SERVICE_0x22)
      {
        CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_WAITING_READ_DATA);
      }
      else
      {
        CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_WAITING_WRITE_DATA);
      }
      *supported = DCM_DID_SUPPORTED;
    }
    else
    {
      /* request is still in progress */
      lResult = DCM_E_PENDING;
    }
  }
  else
  {
    /* DID was not requested before -> report DID as unavailable */
    *supported = DCM_DID_NOT_SUPPORTED;
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    errorId = CDDDK4_E_PARAM_VALUE;
#endif
  }


  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_ISDIDAVAILABLE_INTERNAL, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
}


/**********************************************************************************************************************
 *CddDk4_ApplProcessDidRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ApplProcessDidRequest(CddDk4_DidStatusBufferIdxType statusBufferIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ReturnType lResult = CDDDK4_RET_NOT_OK;
  CddDk4_ApplRespInfoStructType lNotify;
  CddDk4_ConnectionIdType lConnId;
  lNotify.respCode = CDDDK4_NOTIFY_CONNECTION_BUSY;
  lNotify.sid = CddDk4_GetSid_ApplDidStatusBuffer(statusBufferIdx);

  /* ----- Implementation ----------------------------------------------- */
  CddDk4_SetStatus_ApplDidStatusbuffer(statusBufferIdx, CDDDK4_DID_REQUEST_IN_PROGRESS);

  lConnId = CddDk4_GetConnId_ApplDidStatusbuffer(statusBufferIdx);
  if (FALSE == CddDk4_isConnectionActive(lConnId))
  {
    /* Connection is disabled */
    lNotify.respCode = CDDDK4_NOTIFY_CONNECTION_DISABLED;
  }
  else if (  (CddDk4_ActiveConnectionChannels < CDDDK4_CONNECTION_CHANNEL_LIMIT)
           &&(CddDk4_GetConnChannelAssignment(lConnId) == CDDDK4_NO_CHANNEL_ASSIGNED))
  {
    if (CddDk4_GetSid_ApplDidStatusBuffer(statusBufferIdx) == CDDDK4_SERVICE_0x22)
    {
      /* No communication request is in progress with given connection Id, connection is active and free channel is
       * available; DID can be requested */
      uint8 lData[2];
      lData[0] = (uint8)(CddDk4_GetDid_ApplDidStatusBuffer(statusBufferIdx) >> 8);
      lData[1] = (uint8)CddDk4_GetDid_ApplDidStatusBuffer(statusBufferIdx);

      lResult = CddDk4_SvcSendRDBI(lConnId, lData, 2, &CddDk4_ApplResponseNotify);
    }
    else
    {
      /* service 0x2E */
      lResult = CddDk4_SvcSendWDBI(lConnId,
                                   CddDk4_GetDataPtr_ApplDidStatusBuffer(statusBufferIdx),
                                   CddDk4_GetDidSize_ApplDidStatusBuffer(statusBufferIdx),
                                   &CddDk4_ApplResponseNotify);
    }
  }
  else
  {
    /* do nothing */
  }

  if (lResult != CDDDK4_RET_OK)
  {
    /* no free channel available or connection not active; notify application */
#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
    lNotify.connId = CddDk4_GetConnId_ApplDidStatusbuffer(statusBufferIdx);
    lNotify.did = CddDk4_GetDid_ApplDidStatusBuffer(statusBufferIdx);
    lNotify.dataLength = 0;
    (void) CDDDK4_CFG_APPLNOTIFY(&lNotify);
#else
    CDDDK4_DUMMY_STATEMENT(lNotify); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

    CddDk4_SetStatus_ApplDidStatusbuffer(statusBufferIdx, CDDDK4_DID_STATUS_UNKNOWN);
    CddDk4_EnterExclusiveAreaReqMgr();
    CddDk4_ApplRequestedDidsCount--;
    CddDk4_LeaveExclusiveAreaReqMgr();
  }
}


/**********************************************************************************************************************
 *CddDk4_ProcessDidRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ProcessDidRequest(CddDk4_DidStatusBufferIdxType statusBufferIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ConnectionIdType lConId = CddDk4_GetDIDConnectionId(CddDk4_GetDid_DidStatusBuffer(statusBufferIdx));

  /* ----- Implementation ----------------------------------------------- */
  if ((lConId == CDDDK4_INVALID_CONNECTION_ID) || (FALSE == CddDk4_isConnectionActive(lConId)))
  {
    /* DID is not Configured or Connection is Disabled */
    CddDk4_EnterExclusiveAreaReqMgr();
    if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) != CDDDK4_DID_REQUEST_CANCELED)
    {
      CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, CDDDK4_DID_UNAVAILABLE);
    }
    CddDk4_LeaveExclusiveAreaReqMgr();
  }
  else if (CddDk4_RequestedService == CDDDK4_SERVICE_0x2E)
  {
    /* connection ID is valid for write request */
    CddDk4_EnterExclusiveAreaReqMgr();
    if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) != CDDDK4_DID_REQUEST_CANCELED)
    {
      CddDk4_SetConnId_DidStatusbuffer(statusBufferIdx, lConId);
      CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, CDDDK4_DID_AVAILABLE);
    }
    CddDk4_LeaveExclusiveAreaReqMgr();
  }
  else if (CddDk4_GetConnChannelAssignment(lConId) == CDDDK4_NO_CHANNEL_ASSIGNED)
  {
    /* No communication request is in progress with given connection Id; request can be sent */
      CddDk4_ProcessDidReadRequest(statusBufferIdx, lConId);
  }
  else
  {
    /* do nothing */
  }
}


/**********************************************************************************************************************
 *CddDk4_ProcessDidReadRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ProcessDidReadRequest(CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                                         CddDk4_ConnectionIdType connId)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ReturnType lResult;
  uint8 lData[2];

  /* ----- Implementation ----------------------------------------------- */
  lData[0] = (uint8)(CddDk4_GetDid_DidStatusBuffer(statusBufferIdx) >> 8);
  lData[1] = (uint8)CddDk4_GetDid_DidStatusBuffer(statusBufferIdx);
  CddDk4_EnterExclusiveAreaReqMgr();
  if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) == CDDDK4_DID_WAITING_REQUEST)
  {
    CddDk4_SetConnId_DidStatusbuffer(statusBufferIdx, connId);
    CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, CDDDK4_DID_REQUEST_IN_PROGRESS);
    CddDk4_LeaveExclusiveAreaReqMgr();

    lResult = CddDk4_SvcSendRDBI(connId, lData, 2, &CddDk4_ResponseNotify);

    if (lResult != CDDDK4_RET_OK)
    {
      CddDk4_EnterExclusiveAreaReqMgr();
      if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) == CDDDK4_DID_REQUEST_IN_PROGRESS)
      {
        /* free channel was not available; request could not be send */
        CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, CDDDK4_DID_WAITING_REQUEST);
      }
      CddDk4_LeaveExclusiveAreaReqMgr();
    }
  }
  else
  {
    CddDk4_LeaveExclusiveAreaReqMgr();
  }
}


/**********************************************************************************************************************
 *CddDk4_ProcessDidWriteRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ProcessDidWriteRequest(CddDk4_DidStatusBufferIdxType statusBufferIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ReturnType lResult;

  /* ----- Implementation ----------------------------------------------- */
  CddDk4_EnterExclusiveAreaReqMgr();
  if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) != CDDDK4_DID_REQUEST_CANCELED)
  {
    CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, CDDDK4_DID_REQUEST_IN_PROGRESS);
  }
  CddDk4_LeaveExclusiveAreaReqMgr();

  lResult = CddDk4_SvcSendWDBI(CddDk4_GetConnId_DidStatusbuffer(statusBufferIdx),
                               CddDk4_GetDataPtr_DidStatusbuffer(statusBufferIdx),
                               CddDk4_GetDidSize_DidStatusbuffer(statusBufferIdx),
                               &CddDk4_ResponseNotify);

  if (lResult != CDDDK4_RET_OK)
  {
    CddDk4_EnterExclusiveAreaReqMgr();
    if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) == CDDDK4_DID_REQUEST_IN_PROGRESS)
    {
      /* free channel was not available; request could not be send */
      CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, CDDDK4_DID_WAITING_WRITE_REQUEST);
    }
    CddDk4_LeaveExclusiveAreaReqMgr();
  }
}


/**********************************************************************************************************************
 *CddDk4_ResponseNotify_Svc22()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ResponseNotify_Svc22(
                                                     CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                     P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_DidStatusType lNewDidStatus;

  /* ----- Implementation ----------------------------------------------- */

  /* valid did status index found; */
  if (response->respCode == CDDDK4_NOTIFY_POSITIVE_RESPONSE)
  {
    /* positive response */
    lNewDidStatus = CddDk4_VerifyPositiveResponse(statusBufferIdx, response);
  }
  else if ((response->respCode == CDDDK4_NOTIFY_CONNECTION_TIMEOUT)
    && (CddDk4_GetRetryCounter_DidStatusbuffer(statusBufferIdx) > 0)
    )
  {
    /* timeout expired without reception of response; retry request after retry delay */
    lNewDidStatus = CDDDK4_DID_RETRY_REQUEST;
  }
  else
  {
    /* report DID as unavailable if configured number of request retries were not successful or response is negative */
    lNewDidStatus = CDDDK4_DID_UNAVAILABLE;
  }

  CddDk4_EnterExclusiveAreaReqMgr();
  if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) != CDDDK4_DID_REQUEST_CANCELED)
  {
    CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, lNewDidStatus);
  }
  CddDk4_LeaveExclusiveAreaReqMgr();

}

/**********************************************************************************************************************
 *CddDk4_ResponseNotify_Svc2E()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ResponseNotify_Svc2E(
                                                     CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                     P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_RespInfoType lRespCode;
  CddDk4_DidStatusType lNewStatus;

  /* ----- Implementation ----------------------------------------------- */
  lRespCode = response->respCode;
  lNewStatus = CDDDK4_DID_WRITE_FINISHED;

  if (lRespCode == CDDDK4_NOTIFY_POSITIVE_RESPONSE)
  {
    /* positive response */
    if (response->dataLength > 2)
    {
      lRespCode = CDDDK4_NOTIFY_RESPONSE_TOO_LONG;
    }
    else if (response->dataLength == 2)
    {
      /* data length must at least contain the  DID identifier and 1 byte DID data */
      uint16 lDid = 0;
      lDid = (lDid | response->respData[0]) << 8;
      lDid = lDid | response->respData[1];

      if (CddDk4_GetDid_DidStatusBuffer(statusBufferIdx) != lDid)
      {
        /* DID Identifier is not equal to requested DID Identifier */
        lRespCode = CDDDK4_NOTIFY_INVALID_DID;
      }
    }
    else
    {
      lRespCode = CDDDK4_NOTIFY_RESPONSE_TOO_SHORT;
    }
  }
  else if (lRespCode == CDDDK4_NOTIFY_CONNECTION_TIMEOUT)
  {
    if (CddDk4_GetRetryCounter_DidStatusbuffer(statusBufferIdx) > 0)
    {
      /* timeout expired without reception of response; retry request after retry delay */
      lNewStatus = CDDDK4_DID_RETRY_REQUEST;
    }
  }
  else if (lRespCode == CDDDK4_NOTIFY_NEGATIVE_RESPONSE)
  {
    /* copy NRC to data buffer */
    CddDk4_DidDataBuffer[CddDk4_CurrentDataBufferIdx] = response->respData[0];
    CddDk4_SetDataPtr_DidStatusbuffer(statusBufferIdx, &CddDk4_DidDataBuffer[CddDk4_CurrentDataBufferIdx]);
  }
  else
  {
    /* do nothing */
  }

  CddDk4_SetRespCode_DidStatusbuffer(statusBufferIdx, lRespCode);
  CddDk4_EnterExclusiveAreaReqMgr();
  if (CddDk4_GetStatus_DidStatusbuffer(statusBufferIdx) != CDDDK4_DID_REQUEST_CANCELED)
  {
    CddDk4_SetStatus_DidStatusbuffer(statusBufferIdx, lNewStatus);
  }
  CddDk4_LeaveExclusiveAreaReqMgr();
}


/**********************************************************************************************************************
 *CddDk4_VerifyPositiveResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(CddDk4_DidStatusType, CDDDK4_CODE) CddDk4_VerifyPositiveResponse(
                                                   CddDk4_DidStatusBufferIdxType statusBufferIdx,
                                                   P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_CONST) response)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean lValidDid = FALSE;
  CddDk4_DidStatusType lResult;

  /* ----- Implementation ----------------------------------------------- */
  if (response->dataLength > 2)
  {
    /* data length must at least contain the  DID identifier and 1 byte DID data */
    uint16 lDid = 0;
    lDid = (lDid | response->respData[0]) << 8;
    lDid = lDid | response->respData[1];

    if (CddDk4_GetDid_DidStatusBuffer(statusBufferIdx) == lDid)
    {
      /* DID Identifier is equal to requested DID Identifier */
      lValidDid = TRUE;
    }
  }

  if (lValidDid == TRUE)
  {
    /* DID Identifier is valid and equal to requested DID Identifier */

    /* DID data length is response data length without 2 byte DID Identifier */
    CddDk4_LengthType lDataLength = response->dataLength - 2;

    if ((CddDk4_CurrentDataBufferIdx + lDataLength) < CDDDK4_DID_DATA_BUFFER_SIZE)
    {
      /* enough space in buffer to store DID data */

      /* set dataPtr to DID Data in DID status */
      CddDk4_SetDataPtr_DidStatusbuffer(statusBufferIdx, &CddDk4_DidDataBuffer[CddDk4_CurrentDataBufferIdx]);

      /* copy DID data to buffer */
      CddDk4_MemCopy(&CddDk4_DidDataBuffer[CddDk4_CurrentDataBufferIdx], &(response->respData[2]), lDataLength);

      /* set DID data length in DID status */
      CddDk4_SetDidSize_DidStatusbuffer(statusBufferIdx, lDataLength);

      CddDk4_CurrentDataBufferIdx = CddDk4_CurrentDataBufferIdx + lDataLength;
    }
    else
    {
      /* not enough space in buffer for DID data */

      /* set dataPtr to NULL_PTR; will later be interpreted as NRC 0x14: Response too long */
      CddDk4_SetDataPtr_DidStatusbuffer(statusBufferIdx, NULL_PTR);
    }

    lResult = CDDDK4_DID_AVAILABLE;
    /* setting DID status to available */
  }
  else
  {
    /* DID is not valid or no did data in response; DID is set to unavailable */
    lResult = CDDDK4_DID_UNAVAILABLE;
  }

  return lResult;
}


/**********************************************************************************************************************
 *CddDk4_ClearDidStatusBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *********************************************************************************************************************/
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ClearDidStatusBuffer(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_DidStatusBufferIdxType_least lIdx;

  /* ----- Implementation ----------------------------------------------- */
  CddDk4_CurrentStatusBufferIdx = 0;
  CddDk4_CurrentDataBufferIdx = 0;

  for (lIdx = 0; lIdx < CDDDK4_MAX_DIDS_TO_BUFFER; lIdx++)
  {
    CddDk4_SetDataPtr_DidStatusbuffer(lIdx, NULL_PTR);
    CddDk4_SetDidSize_DidStatusbuffer(lIdx, 0);
    CddDk4_SetConnId_DidStatusbuffer(lIdx, CDDDK4_INVALID_CONNECTION_ID);
    CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_STATUS_UNKNOWN);
    CddDk4_SetRetryCounter_DidStatusbuffer(lIdx, CDDDK4_CFG_MAX_REQUEST_RETRIES);
    CddDk4_SetRetryDelay_DidStatusBuffer(lIdx, CDDDK4_CFG_REQUEST_RETRY_DELAY);
  }
}


/**********************************************************************************************************************
 *CddDk4_GetConnIdTxPdu()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ConnectionIdType, CDDDK4_CODE) CddDk4_GetConnIdTxPdu(PduIdType txPdu)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ConnectionIdType lResult = CDDDK4_INVALID_CONNECTION_ID;
  CddDk4_ConnectionIdType lConId;

  /* ----- Implementation ----------------------------------------------- */
  for (lConId = 0; lConId < CDDDK4_CONNECTION_CONFIG_COUNT; lConId++)
  {
    if (txPdu == CddDk4_Cfg_ConnectionTxPduId(lConId))
    {
      lResult = lConId;
      break;
    }
  }

  return lResult;
}
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
/**********************************************************************************************************************
 *CddDk4_GetDIDConnectionId()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ConnectionIdType, CDDDK4_CODE) CddDk4_GetDIDConnectionId(CddDk4_DidIdentifierType did)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ConnectionIdType lConId = CDDDK4_INVALID_CONNECTION_ID;
  CddDk4_DidTableIdxType lDidIdx;

  /* ----- Implementation ----------------------------------------------- */
  for (lDidIdx = 0; lDidIdx != CDDDK4_DIDS_CONFIG_COUNT; lDidIdx++)
  {
    if (CddDk4_Cfg_DidIdentifier(lDidIdx) == did)
    {
      lConId = CddDk4_Cfg_DidConnectionId(lDidIdx);
      break;
    }
  }

  return (lConId);
}


/**********************************************************************************************************************
 *CddDk4_ConnManagerVerifyNegativeResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyNegativeResponse(
                                                                CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) ChannelId)
{
  /* Verify that negative response has length 3 */
  if (CddDk4_ChannelInfo_GetPduInfo_SduLength(ChannelId) == CDDDK4_NEGATIVE_RESP_LEN)
  {
    if (    CddDk4_ChannelInfo_GetSvcId(ChannelId)
         != CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(ChannelId)[CDDDK4_SERVICE_ID_IDX])
    {
      /* Service Id in Response not as expected */
      CddDk4_ConnManagerChClose(ChannelId, CDDDK4_NOTIFY_INVALID_SID, FALSE);
    }
    else if (CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(ChannelId)[CDDDK4_NRC_INDEX] == CDDDK4_RCRRP_NRC)
    {
      /* RCRRP is received */
      CddDk4_ConnManagerVerifyRCRRP(ChannelId);
    }
    else if (CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(ChannelId)[CDDDK4_NRC_INDEX] == CDDDK4_BRR_NRC)
    {
      /* NRC Busy was received */
      CddDk4_ConnManagerVerifyBRR(ChannelId);
    }
    else
    {
      /* Notify client with negative response */
      CddDk4_ConnManagerChClose(ChannelId, CDDDK4_NOTIFY_NEGATIVE_RESPONSE, FALSE);
    }
  }
  else if (CddDk4_ChannelInfo_GetPduInfo_SduLength(ChannelId) < CDDDK4_NEGATIVE_RESP_LEN)
  {
    /* negative response to short */
    CddDk4_ConnManagerChClose(ChannelId, CDDDK4_NOTIFY_RESPONSE_TOO_SHORT, FALSE);
  }
  else
  {
    /* negative response to long */
    CddDk4_ConnManagerChClose(ChannelId, CDDDK4_NOTIFY_RESPONSE_TOO_LONG, FALSE);
  }

}


/**********************************************************************************************************************
 * CddDk4_CopyPduIntoBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
CDDDK4_LOCAL_INLINE FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_CopyPduIntoBuffer(
                                                        CddDk4_ConnChannelIdType ChannelId,
                                                        P2CONST(PduInfoType, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr,
                                                        P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr,
                                                        uint8 ServiceId)
{
  /* ----- Local Variables ---------------------------------------------- */
  P2VAR(PduInfoType, AUTOMATIC, CDDDK4_VAR) lLocalPduPtr = CddDk4_ChannelInfo_GetPduInfoPtr(ChannelId);
  PduLengthType lBufPos = CddDk4_ChannelInfo_GetBufferPosition(ChannelId);
  BufReq_ReturnType lResult;
  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = CDDDK4_E_NO_ERROR;
  lResult = BUFREQ_E_NOT_OK;
  if(PduInfoPtr->SduDataPtr == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else if((lBufPos + PduInfoPtr->SduLength) > lLocalPduPtr->SduLength)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else
#endif /* CDDDK4_DEV_ERROR_DETECT */
  {
    /* ----- Implementation ----------------------------------------------- */
    PduLengthType lCopyLength = PduInfoPtr->SduLength;
    SduDataPtrType lDestPtr = &(lLocalPduPtr->SduDataPtr[lBufPos]);
    CddDk4_ChannelInfo_SetBufferPosition(ChannelId, lBufPos + lCopyLength);
    *BufferSizePtr = lLocalPduPtr->SduLength - CddDk4_ChannelInfo_GetBufferPosition(ChannelId);
    CddDk4_MemCopy(lDestPtr, PduInfoPtr->SduDataPtr, lCopyLength);
    lResult = BUFREQ_OK;
  }
  /* ----- Development Error Report -------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, ServiceId, errorId);
  }
#else /* CDDDK4_DEV_ERROR_REPORT */
  CDDDK4_DUMMY_STATEMENT(ServiceId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif /* CDDDK4_DEV_ERROR_REPORT */
  return lResult;
}
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 * CddDk4_ProvideBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_ProvideBuffer(
                                                       CddDk4_ConnChannelIdType ChannelId,
                                                       PduLengthType TpSduLength,
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
                                                       P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr)
#else /* CDDDK4_AR4_PDUR_SUPPORT */
                                                       P2VAR(PduInfoTypeApplPtr, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr)
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
{
  BufReq_ReturnType lResult = BUFREQ_E_NOT_OK;
  /* exclusive area is used to prevent changing status after connection was closed */
  CddDk4_EnterExclusiveAreaComMgr();
  if (CddDk4_ChannelInfo_GetConState(ChannelId) == CDDDK4_CONNECTION_WAIT_RESPONSE)
  {
    /* response was expected for assigned Connection Id */
    if (TpSduLength <= CONNECTION_CHANNEL_SHORT_PAYLOAD_LENGTH)
    {
      /* sdu is small; small buffer is provided */
      CddDk4_ChannelInfo_SetPduInfo_SduDataPtr(ChannelId, &CddDk4_ChannelInfo_GetShortPayload(ChannelId)[0]);
      lResult = BUFREQ_OK;
    }
    else if (TpSduLength <= CDDDK4_CONNECTION_CHANNEL_BUFFER_LIMIT)
    {
      /* requested buffer can be provided */
      CddDk4_ChannelInfo_SetPduInfo_SduDataPtr(ChannelId, &CddDk4_ChannelInfo_GetPayload(ChannelId)[0]);
      lResult = BUFREQ_OK;
    }
    else
    {
      /* Sdu is too big; requested buffer can not be provided */
      lResult = BUFREQ_E_OVFL;
    }

    if (lResult == BUFREQ_OK)
    {
#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
      *PduInfoPtr = CddDk4_ChannelInfo_GetPduInfoPtr(ChannelId);
      CddDk4_ChannelInfo_SetConState(ChannelId, CDDDK4_CONNECTION_WAIT_RXINDICATION);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
      CddDk4_ChannelInfo_SetPduInfo_SduLength(ChannelId, TpSduLength);
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
      *BufferSizePtr = TpSduLength;
      CddDk4_ChannelInfo_SetBufferPosition(ChannelId, 0);
      CddDk4_ChannelInfo_SetConState(ChannelId, CDDDK4_CONNECTION_WAIT_COPY_RESPONSE);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
    }
  }
  CddDk4_LeaveExclusiveAreaComMgr();
  return lResult;
}

/**********************************************************************************************************************
 *CddDk4_TxConfirmation_Internal()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_TxConfirmation_Internal(CONST(PduIdType, AUTOMATIC) CddDk4TxPduId,
                                                                           CONST(CddDk4_TpResultType, AUTOMATIC) Result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;
  CddDk4_ConnectionIdType lConnId;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
  else if (CddDk4TxPduId >= CDDDK4_TX_PDU_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    lConnId = CddDk4_GetConnIdTxPdu(CddDk4TxPduId);

    CddDk4_ConnStartDelay = 0;

#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    if (lConnId == CDDDK4_INVALID_TX_CONNECTION_ID)
    {
      errorId = CDDDK4_E_PARAM_VALUE;
    }
    else
#endif
    {
      CddDk4_ConnChannelIdType lChannel = CddDk4_GetConnChannelAssignment(lConnId);

      if (lChannel != CDDDK4_NO_CHANNEL_ASSIGNED)
      {
        if (  (Result == CDDDK4_NTFRSLT_OK)
            &&(CddDk4_ChannelInfo_GetConState(lChannel) == CDDDK4_CONNECTION_WAIT_TXCONFIRMATION))
        {
          /* request was sent, connection have to wait for response */
          CddDk4_ChannelInfo_SetConState(lChannel, CDDDK4_CONNECTION_WAIT_RESPONSE);
        }
        else
        {
          /* request has not been completed successfully */
          CddDk4_ConnManagerChClose(lChannel, CDDDK4_NOTIFY_REQUEST_FAILED, FALSE);
        }
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_TX_CONFIRMATION, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *CddDk4_RxIndication_Internal()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_RxIndication_Internal(CONST(PduIdType, AUTOMATIC) CddDk4RxPduId,
                                                                         CONST(CddDk4_TpResultType, AUTOMATIC) Result)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;
  CddDk4_ConnectionIdType lConnId;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (CddDk4RxPduId >= CDDDK4_RX_PDU_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PDU_ID_RX_OUT_OF_RANGE;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    lConnId = CddDk4_GetConnIdRxPdu(CddDk4RxPduId);
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    if (lConnId == CDDDK4_INVALID_CONNECTION_ID)
    {
      errorId = CDDDK4_E_PARAM_VALUE;
    }
    else
#endif
    {
      CddDk4_ConnChannelIdType lChannelId = CddDk4_GetConnChannelAssignment(lConnId);

      if (lChannelId != CDDDK4_NO_CHANNEL_ASSIGNED)
      {
        if ((Result == CDDDK4_NTFRSLT_OK)
          && (CddDk4_ChannelInfo_GetConState(lChannelId) == CDDDK4_CONNECTION_WAIT_RXINDICATION)
          )
        {
          /* response has been received successfully */
          CddDk4_ChannelInfo_SetConState(lChannelId, CDDDK4_CONNECTION_RX_RESPONSE);
        }
        else
        {
          /* response has not been received successfully */
          CddDk4_ConnManagerChClose(lChannelId, CDDDK4_NOTIFY_RESPONSE_FAILED, FALSE);
        }
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_RX_INDICATION, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/**********************************************************************************************************************
 *CddDk4_ResponseNotify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ResponseNotify(
                                                     P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_DidStatusBufferIdxType lIdx;

  /* ----- Implementation ----------------------------------------------- */
  /* looking for DID Status Index belonging to connection ID of response */
  for (lIdx = 0; lIdx < CddDk4_CurrentStatusBufferIdx; lIdx++)
  {
    if ((CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_REQUEST_IN_PROGRESS)
      && (response->connId == CddDk4_GetConnId_DidStatusbuffer(lIdx)))
    {
      /* found connection ID with DID request in progress */
      break;
    }
  }

  if (lIdx < CddDk4_CurrentStatusBufferIdx)
  {
    if (response->serviceId == CDDDK4_SERVICE_0x22)
    {
      /* response to service 0x22 */
      CddDk4_ResponseNotify_Svc22(lIdx, response);
    }
    else
    {
      /* response to service 0x2E */
      CddDk4_ResponseNotify_Svc2E(lIdx, response);
    }
  }
}




/**********************************************************************************************************************
 *CddDk4_ApplResponseNotify()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ApplResponseNotify(
                                                     P2CONST(CddDk4_RespInfoStructType, AUTOMATIC, CDDDK4_VAR) response)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_DidStatusBufferIdxType lIdx;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  /* looking for DID Status Index belonging to connection ID of response */
  for (lIdx = 0; lIdx < CDDDK4_CONNECTION_CHANNEL_LIMIT; lIdx++)
  {
    if ((CddDk4_GetStatus_ApplDidStatusbuffer(lIdx) == CDDDK4_DID_REQUEST_IN_PROGRESS)
      && (response->connId == CddDk4_GetConnId_ApplDidStatusbuffer(lIdx)) )
    {
      /* found connection ID with DID request in progress */
      break;
    }
  }

  if (lIdx < CDDDK4_CONNECTION_CHANNEL_LIMIT)
  {
    if (response->serviceId == CDDDK4_SERVICE_0x22)
    {
      CddDk4_ApplResponseNotify_Svc22(lIdx, response);
    }
    else
    {
      /* service 0x2e */
      CddDk4_ApplResponseNotify_Svc2E(lIdx, response);
    }
  }
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  else
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
#endif


  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_INTERNAL, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/**********************************************************************************************************************
 *CddDk4_RequestManagerTimerTask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_RequestManagerTimerTask(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_DidStatusBufferIdxType lIdx;

  /* ----- Implementation ----------------------------------------------- */
  for (lIdx = 0; lIdx < CddDk4_CurrentStatusBufferIdx; lIdx++)
  {
    if (  (CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_RETRY_REQUEST)
        &&(CddDk4_GetRetryDelay_DidStatusBuffer(lIdx) == 0))
    {
      CddDk4_EnterExclusiveAreaReqMgr();
      if (CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_RETRY_REQUEST)
      {
        /* retry counter is > 0; is verified before setting status to CDDDK4_DID_RETRY_REQUEST */
        uint8 lRetryCounter = CddDk4_GetRetryCounter_DidStatusbuffer(lIdx);

        lRetryCounter--;
        CddDk4_SetRetryCounter_DidStatusbuffer(lIdx, lRetryCounter);

        if (lRetryCounter > 0)
        {
          /* if retry counter > 0 then it is set to configured value; else counter stays 0 */
          CddDk4_SetRetryDelay_DidStatusBuffer(lIdx, CDDDK4_CFG_REQUEST_RETRY_DELAY);
        }

        /* retry request DID if request not canceled */
        if (CddDk4_RequestedService == CDDDK4_SERVICE_0x22)
        {
          /* Service 0x22 */
          CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_WAITING_REQUEST);
        }
        else
        {
          /* Service 0x2E */
          CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_WAITING_WRITE_REQUEST);
        }
      }
      CddDk4_LeaveExclusiveAreaReqMgr();
    }

    /* */
    if (  (CddDk4_GetRetryDelay_DidStatusBuffer(lIdx) > 0)
        &&(  (CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_RETRY_REQUEST)
           ||(CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_REQUEST_IN_PROGRESS))
      )
    {
      /* decrement timer each task cycle */
      CddDk4_TimeoutType lRetryTimeOut = CddDk4_GetRetryDelay_DidStatusBuffer(lIdx) - 1;
      CddDk4_SetRetryDelay_DidStatusBuffer(lIdx, lRetryTimeOut);
    }
  }
}



/**********************************************************************************************************************
 *CddDk4_RequestManagerStateTask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_RequestManagerStateTask(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_DidStatusBufferIdxType lIdx;

  /* ----- Implementation ----------------------------------------------- */

  /* internal request have higher priority; so they are processed at first */
  for (lIdx = 0;
           (lIdx < CddDk4_CurrentStatusBufferIdx)
        && (CddDk4_ActiveConnectionChannels < CDDDK4_CONNECTION_CHANNEL_LIMIT);
       lIdx++)
  {
    /* still free channels available; CddDk4_CurrentStatusBufferIdx indicates unused did status buffer position */
    if (CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_WAITING_REQUEST)
    {
      CddDk4_ProcessDidRequest(lIdx);
    }
    else if (CddDk4_GetStatus_DidStatusbuffer(lIdx) == CDDDK4_DID_WAITING_WRITE_REQUEST)
    {
      CddDk4_ProcessDidWriteRequest(lIdx);
    }
    else
    {
      /* do nothing */
    }
  }

  /* process all did request from application */
  for (lIdx = 0; lIdx < CDDDK4_CONNECTION_CHANNEL_LIMIT; lIdx++)
  {
    /* Size of Application DID Status buffer is equal to number of Channels */
    if (CddDk4_GetStatus_ApplDidStatusbuffer(lIdx) == CDDDK4_DID_WAITING_REQUEST)
    {
      CddDk4_ApplProcessDidRequest(lIdx);
    }
  }
}


/**********************************************************************************************************************
 * CddDk4_ConnManagerChClose()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerChClose(CddDk4_ConnChannelIdType channelId,
                                                               CddDk4_RespInfoType responseCode,
                                                               boolean suppressNotification)
{
  if (suppressNotification == FALSE)
  {
    /* ----- Local Variables ---------------------------------------------- */
    CddDk4_RespInfoStructType response;

    /* ----- Implementation ----------------------------------------------- */
    response.connId = CddDk4_ChannelInfo_GetConnId(channelId);
    response.serviceId = CddDk4_ChannelInfo_GetSvcId(channelId);
    response.respCode = responseCode;
    response.dataLength = 0;

    if (responseCode == CDDDK4_NOTIFY_NEGATIVE_RESPONSE)
    {
      /* if response is negative NRC is returned */
      response.respData[0] = CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(channelId)[CDDDK4_NRC_INDEX];
      response.dataLength = 1;
    }
    else if (responseCode == CDDDK4_NOTIFY_POSITIVE_RESPONSE)
    {
      /* Copy response data for notify application, because channel will be used for new connection */
      response.dataLength = CddDk4_ChannelInfo_GetPduInfo_SduLength(channelId) - 1;
      CddDk4_MemCopy(&response.respData[0],
                     &CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(channelId)[1],
                     response.dataLength);
    }
    else
    {
      /* do nothing */
    }

    CddDk4_ChannelInfo_GetbackFctPtr(channelId)(&response);
  }
  /* Close Channel */
  CddDk4_ChannelInfo_SetConState(channelId, CDDDK4_CONNECTION_INACTIVE);
  CddDk4_SetConnChannelAssignment(CddDk4_ChannelInfo_GetConnId(channelId), CDDDK4_NO_CHANNEL_ASSIGNED);
  CddDk4_ActiveConnectionChannels = CddDk4_ActiveConnectionChannels - 1;
}

/**********************************************************************************************************************
 * CddDk4_ConnectionTimerTask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ConnectionTimerTask(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ConnChannelIdType_least lChannelId;

  /* ----- Implementation ----------------------------------------------- */
  /* Looking for open connections and decrease timeout counter,
  * if timeout elapsed close connection channel and call notify callback.
  * Also decrease Connection delay timer, if delay elapsed set connection channel state to ROUTER_REQUEST
  * (if requests pending), reload delay timer.
  */

  /* look for open connection where state was wait for response and handle timeout */
  for (lChannelId = 0; lChannelId < CDDDK4_CONNECTION_CHANNEL_LIMIT; lChannelId++)
  {
    /* Check channel for open connection and channel state, to decrease timeout counter */
    if (CddDk4_ChannelInfo_GetConState(lChannelId) == CDDDK4_CONNECTION_WAIT_RESPONSE)
    {
      /* Check if timeout elapsed */
      if (CddDk4_ChannelInfo_GetTimeOut(lChannelId) > 0)
      {
        /* Timeout not elapsed */
        CddDk4_TimeoutType lTimeOut = CddDk4_ChannelInfo_GetTimeOut(lChannelId) - 1;
        CddDk4_ChannelInfo_SetTimeOut(lChannelId, lTimeOut);
      }
      else
      {
        /* Timeout elapsed, notify application and close connection channel */
        CddDk4_EnterExclusiveAreaComMgr();
        CddDk4_ConnManagerChClose((CddDk4_ConnChannelIdType)lChannelId, CDDDK4_NOTIFY_CONNECTION_TIMEOUT, FALSE);
        CddDk4_LeaveExclusiveAreaComMgr();
      }
    }

  } /* End Loop */

  /* Delay is reloaded when a request was sent */
  if (CddDk4_ConnStartDelay == CDDDK4_TIMER_CONN_DELAY)
  {
    CddDk4_ConnChannelIdType_least lChannelEndIdx = CddDk4_CurrentConnChannelIndex;

    /* looking for next connection that is waiting for delay */
    while (CddDk4_ChannelInfo_GetConState(lChannelEndIdx) != CDDDK4_CONNECTION_WAIT_DELAY)
    {
      lChannelEndIdx = (lChannelEndIdx + 1) % CDDDK4_CONNECTION_CHANNEL_LIMIT;

      if (CddDk4_CurrentConnChannelIndex == lChannelEndIdx)
      {
        break;
      }
    }

    if (CddDk4_ChannelInfo_GetConState(lChannelEndIdx) == CDDDK4_CONNECTION_WAIT_DELAY)
    {
      /* Set the next state, so connection can send the request */
      CddDk4_ChannelInfo_SetConState(lChannelEndIdx, CDDDK4_CONNECTION_ROUTER_REQUEST);
      CddDk4_ConnStartDelay = CDDDK4_TIMER_CONN_DELAY_BLOCKED;
    }

    CddDk4_CurrentConnChannelIndex = (CddDk4_ConnChannelIdType)((lChannelEndIdx + 1) % CDDDK4_CONNECTION_CHANNEL_LIMIT);
  }

#if (CDDDK4_CFG_SUPPORT_TIMER_CONN_DELAY == STD_ON)
  if (CddDk4_ConnStartDelay < CDDDK4_TIMER_CONN_DELAY)
  {
    CddDk4_ConnStartDelay++;
  }
#endif
}

/**********************************************************************************************************************
 * CddDk4_ConnManagerStateTask()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerStateTask(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ConnChannelIdType_least channelId;

  /* ----- Implementation ----------------------------------------------- */
  /* If no connection is open, skip */
  if(CddDk4_ActiveConnectionChannels > 0)
  {
    /* look into each channel and process them if necessary  */
    for(channelId = 0; channelId < CDDDK4_CONNECTION_CHANNEL_LIMIT; channelId++)
    {
      switch (CddDk4_ChannelInfo_GetConState(channelId))
      {
      case CDDDK4_CONNECTION_RX_RESPONSE:
      {
        /* Response length must be at least 1 Byte (Negative Response Code/Positive Response Code) */
        if (CddDk4_ChannelInfo_GetPduInfo_SduLength(channelId) > 0)
        {
          CddDk4_ConnManagerVerifyResponse((CddDk4_ConnChannelIdType)channelId);
        }
        else
        { /* Notify application, if message length was smaller than 1 byte */
          CddDk4_ConnManagerChClose((CddDk4_ConnChannelIdType)channelId, CDDDK4_NOTIFY_RESPONSE_TOO_SHORT, FALSE);
        }
        break;
      }
      case CDDDK4_CONNECTION_RX_RESPONSE_COMPLETE:
      {
        CddDk4_ConnManagerChClose((CddDk4_ConnChannelIdType)channelId, CDDDK4_NOTIFY_POSITIVE_RESPONSE, FALSE);
        break;
      }
      case CDDDK4_CONNECTION_ROUTER_REQUEST:
      {
        /* Try to send request */
        if (CddDk4_TransmitService(CddDk4_ChannelInfo_GetConnId(channelId)) != E_OK)
        {
        /* Error occurs, notify application */
          CddDk4_ConnManagerChClose((CddDk4_ConnChannelIdType)channelId, CDDDK4_NOTIFY_REQUEST_FAILED, FALSE);
        }
        break;
      }
      default:
        /* nothing to be done for this connection channel */
        break;
      }
    }
  }
}

/**********************************************************************************************************************
 * CddDk4_ConnManagerVerifyResponse()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyResponse(
                                                                CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) channelId)
{
  /* ----- Implementation ----------------------------------------------- */

  /* Check if request service added 0x40u the same as response code */
  if (CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(channelId)[0]
                                                         == (CddDk4_ChannelInfo_GetSvcId(channelId) | CDDDK4_RPC_CHECK))
  {
    CddDk4_ChannelInfo_SetConState(channelId, CDDDK4_CONNECTION_RX_RESPONSE_COMPLETE);
  }
  else if (CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(channelId)[0] == CDDDK4_NEGRESP_CODE)
  {
    /* Verify negative response */
    CddDk4_ConnManagerVerifyNegativeResponse(channelId);
  }
  else
  {
    /* Unexpected Sid received; notify client */
    CddDk4_ConnManagerChClose(channelId, CDDDK4_NOTIFY_INVALID_SID, FALSE);
  }
}

/**********************************************************************************************************************
 * CddDk4_ValidateRCRRP()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyRCRRP(
                                                                CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) channelId)
{
  /* ----- Implementation ----------------------------------------------- */
  if (CddDk4_Cfg_ConnectionMaxRCRRP(CddDk4_ChannelInfo_GetConnId(channelId)) < CDDDK4_UNLIMIT_RCRRP)
  {
    /* RCRRP receive was not unlimited */
    if (CddDk4_ChannelInfo_GetRCRRPCounter(channelId) > 0)
    {
      /* Reload connection timer and count the received RCRRP message */
      uint8 lRCRRPCounter = CddDk4_ChannelInfo_GetRCRRPCounter(channelId) - 1;
      CddDk4_ChannelInfo_SetRCRRPCounter(channelId, lRCRRPCounter);
      CddDk4_ChannelInfo_SetTimeOut(channelId,
                                    CddDk4_Cfg_ConnectionP2ExtendedTimer(CddDk4_ChannelInfo_GetConnId(channelId)));
      CddDk4_ChannelInfo_SetConState(channelId, CDDDK4_CONNECTION_WAIT_RESPONSE);
    }
    else
    {
      /* Notify application that count of received RCRRP messages greater than configured */
      CddDk4_ConnManagerChClose(channelId, CDDDK4_NOTIFY_RCRRP_LIMIT_REACHED, FALSE);
    }
  }
  else
  { /* RCRRP receive was unlimited */
    /* Reload connection timer with P2 extended Timeout */
    CddDk4_ChannelInfo_SetTimeOut(channelId,
                                         CddDk4_Cfg_ConnectionP2ExtendedTimer(CddDk4_ChannelInfo_GetConnId(channelId)));
    CddDk4_ChannelInfo_SetConState(channelId, CDDDK4_CONNECTION_WAIT_RESPONSE);
  }
}

/**********************************************************************************************************************
 * CddDk4_ValidateBusyRepeat()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(void, CDDDK4_CODE) CddDk4_ConnManagerVerifyBRR(
                                                                CONST(CddDk4_ConnChannelIdType, CDDDK4_CONST) channelId)
{
  /* ----- Implementation ----------------------------------------------- */
  if (CddDk4_Cfg_ConnectionMaxNrcBusy(CddDk4_ChannelInfo_GetConnId(channelId)) < CDDDK4_UNLIMIT_NRCBUSY)
  {
    if(CddDk4_ChannelInfo_GetNrcBusyCounter(channelId) > 0)
    {
      uint8 lNrcBusyCounter = CddDk4_ChannelInfo_GetNrcBusyCounter(channelId) - 1;
      CddDk4_ChannelInfo_SetNrcBusyCounter(channelId, lNrcBusyCounter);
      /* Set default connection properties */
      CddDk4_ChannelInfo_SetTimeOut(channelId, CddDk4_Cfg_ConnectionP2Timer(CddDk4_ChannelInfo_GetConnId(channelId)));
      CddDk4_ChannelInfo_SetConState(channelId, CDDDK4_CONNECTION_WAIT_DELAY);
    }
    else
    {
      /* NRC 0x21 (Busy repeat request) limit is reached */
      CddDk4_ConnManagerChClose(channelId, CDDDK4_NOTIFY_BUSY_LIMIT_REACHED, FALSE);
    }
  }
  else
  {
    /* Unlimited retries on received NRC 0x21 (Busy repeat request) */
    /* Set default connection properties */
    CddDk4_ChannelInfo_SetTimeOut(channelId, CddDk4_Cfg_ConnectionP2Timer(CddDk4_ChannelInfo_GetConnId(channelId)));
    CddDk4_ChannelInfo_SetConState(channelId, CDDDK4_CONNECTION_WAIT_DELAY);
  }
}


/**********************************************************************************************************************
 * CddDk4_TransmitService()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_TransmitService(CddDk4_ConnectionIdType connId)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult;
  PduIdType lPduId;
  PduLengthType lTxPduLength;
  CddDk4_ConnChannelIdType lChannelId = CddDk4_GetConnChannelAssignment(connId);
  /* ----- Implementation ----------------------------------------------- */

  lPduId = CddDk4_Cfg_ConnectionTxPduId(connId);
  lTxPduLength = CddDk4_ChannelInfo_GetTxPduLength(lChannelId);
  CddDk4_ChannelInfo_SetPduInfo_SduLength(lChannelId, lTxPduLength);
  CddDk4_ChannelInfo_SetConState(lChannelId, CDDDK4_CONNECTION_ROUTER_REQUEST_TRANSMIT);
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
  CddDk4_ChannelInfo_SetBufferPosition(lChannelId, 0);
  CddDk4_ChannelInfo_SetPduInfo_SduDataPtr(lChannelId, &CddDk4_ChannelInfo_GetPayload(lChannelId)[0]);
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
  lResult = PduR_CddDk4Transmit(lPduId, CddDk4_ChannelInfo_GetPduInfoPtr(lChannelId));
  if (lResult != E_OK)
  {
    /* transmit request was not sent */
    CddDk4_ChannelInfo_SetConState(CddDk4_GetConnChannelAssignment(connId), CDDDK4_CONNECTION_ROUTER_REQUEST);

    /* request could not be sent; next request will be handled immediately */
    CddDk4_ConnStartDelay = CDDDK4_TIMER_CONN_DELAY;
  }

  return lResult;
}


/**********************************************************************************************************************
 * CddDk4_ConnManagerGetAndInitFreeChannel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ConnChannelIdType, CDDDK4_CODE) CddDk4_ConnManagerGetAndInitFreeChannel(
                                                                                         CddDk4_ConnectionIdType connId)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ConnChannelIdType lResult = CDDDK4_NO_CHANNEL_ASSIGNED;
  CddDk4_ConnChannelIdType_least channelId;
  /* ----- Implementation ----------------------------------------------- */
  for(channelId = 0; channelId < CDDDK4_CONNECTION_CHANNEL_LIMIT; channelId++)
  {
    if (CddDk4_ChannelInfo_GetConState(channelId) == CDDDK4_CONNECTION_INACTIVE)
    {
      /* Allocate the free channel */
      lResult = (CddDk4_ConnChannelIdType)channelId;
      CddDk4_ChannelInfo_SetConState(lResult, CDDDK4_CONNECTION_WAIT_DELAY);
      CddDk4_ChannelInfo_SetConnId(lResult, connId);
      CddDk4_SetConnChannelAssignment(connId, lResult);
      CddDk4_ActiveConnectionChannels = CddDk4_ActiveConnectionChannels + 1;
      break;
    }
  }
  return lResult;
}

/**********************************************************************************************************************
 * CddDk4_ConnManagerStart()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL_INLINE FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_ConnManagerStart(CddDk4_ServiceIdType svcId,
                                                                                 CddDk4_ConnectionIdType connId,
                                                                                 CddDk4_NotifyFunctionPtr callback)
        {
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ReturnType lResult = CDDDK4_RET_NO_FREE_CHANNEL;
  /* ----- Implementation ----------------------------------------------- */
  /* Prevent to start a new connection, when no free channels available or Connection is already in use */
  if (CddDk4_isConnectionFree(connId) == FALSE)
  {
     lResult = CDDDK4_RET_CONNECTION_BUSY;
  }
  else if ( CddDk4_ActiveConnectionChannels < CDDDK4_CONNECTION_CHANNEL_LIMIT )
  {
    /* Only assign, if Channel available */
    CddDk4_ConnChannelIdType lFreeChannel;
    lFreeChannel = CddDk4_ConnManagerGetAndInitFreeChannel(connId);
    /* Check, if already connection channel to connection is open */
    if (lFreeChannel < CDDDK4_NO_CHANNEL_ASSIGNED)
    {
      /* Set channel to initial values */
      CddDk4_ChannelInfo_SetSvcId(lFreeChannel, svcId);
      CddDk4_ChannelInfo_SetTimeOut(lFreeChannel, CddDk4_Cfg_ConnectionP2Timer(connId));   /* Load P2 Time as default */
      CddDk4_ChannelInfo_SetRCRRPCounter(lFreeChannel, CddDk4_Cfg_ConnectionMaxRCRRP(connId));
      CddDk4_ChannelInfo_SetNrcBusyCounter(lFreeChannel, CddDk4_Cfg_ConnectionMaxNrcBusy(connId));
      CddDk4_ChannelInfo_SetbackFctPtr(lFreeChannel, callback); /* Set Function pointer to CddDk4_Notify as default */
      /* Check result value, it could be also possible that connection was already open */
      /* New Connection was assigned */
      lResult = CDDDK4_RET_OK;
    }
  }
  else
  {
    /* do nothing */
  }

  return lResult;
}


/**********************************************************************************************************************
 *CddDk4_SvcSend()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
CDDDK4_LOCAL FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_SvcSend(
                                                      CddDk4_ServiceIdType svcId,
                                                      CddDk4_ConnectionIdType connId,
                                                      P2CONST(CddDk4_RespDataType, AUTOMATIC, CDDDK4_CONST) requestData,
                                                      CddDk4_LengthType length,
                                                      CddDk4_NotifyFunctionPtr callback)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;
  CddDk4_ReturnType lResult = CDDDK4_RET_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  if (length >= CDDDK4_CONNECTION_CHANNEL_BUFFER_LIMIT)
  {
    errorId = CDDDK4_E_CHANNEL_BUFFER_OUT_OF_RANGE;
  }
  else
  {
    /* Initialize Connection Channel and check if enough buffer size available. */
    lResult = CddDk4_ConnManagerStart(svcId, connId, callback);
    if ((lResult == CDDDK4_RET_OK))
    {
      CddDk4_LengthType_least lIndex;
      CddDk4_ConnChannelIdType channel = CddDk4_GetConnChannelAssignment(connId);
      CddDk4_ChannelInfo_SetTxPduLength(channel, (length + 1U));

      CddDk4_ChannelInfo_SetPayload(channel, 0, svcId);
      /* Copy request data into connection channel */
      for (lIndex = 0; lIndex < length; lIndex++)
      {
        /* Copy request into connection channel for of later use (e.g. NRC Busy received) */
        CddDk4_ChannelInfo_SetPayload(channel, (lIndex + 1U), requestData[lIndex]);
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_SERVICE_SEND, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
    return lResult;
} /* CddDk4_SvcSend() */
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *CddDk4_CopyTxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_CopyTxData(
                    PduIdType CddDk4TxPduId,
                    P2VAR(PduInfoType, AUTOMATIC, CDDDK4_APPL_DATA) PduInfoPtr, /* PRQA S 3673 */ /* MD_CDDDK4_16.7_2 */
                    P2VAR(RetryInfoType, AUTOMATIC, CDDDK4_APPL_DATA) Retry,    /* PRQA S 3673 */ /* MD_CDDDK4_16.7_2 */
                    P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) AvailableDataPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType lResult = BUFREQ_E_NOT_OK;
  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = CDDDK4_E_NO_ERROR;
  /* Check initialization state of the component */
  if (CddDk4_Init_State != CDDDK4_INIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (CddDk4TxPduId >= CDDDK4_TX_PDU_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else if(  (PduInfoPtr == NULL_PTR)
          ||(AvailableDataPtr == NULL_PTR))
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    CddDk4_ConnectionIdType lConnId = CddDk4_GetConnIdTxPdu(CddDk4TxPduId);

#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    if (lConnId == CDDDK4_INVALID_TX_CONNECTION_ID)
    {
      errorId = CDDDK4_E_PARAM_VALUE;
    }
    else
#endif /* CDDDK4_DEV_ERROR_DETECT */
    {
      CddDk4_ConnChannelIdType lChannelId = CddDk4_GetConnChannelAssignment(lConnId);
      if (CddDk4_ChannelInfo_GetConState(lChannelId) == CDDDK4_CONNECTION_ROUTER_REQUEST_TRANSMIT)
      {
        PduLengthType lPayloadLength = CddDk4_ChannelInfo_GetPduInfo_SduLength(lChannelId);
        PduLengthType lBufPos = CddDk4_ChannelInfo_GetBufferPosition(lChannelId);
        *AvailableDataPtr = lPayloadLength - lBufPos;
        if(PduInfoPtr->SduLength == 0)
        {
          lResult = BUFREQ_OK;
        }
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
        else if(PduInfoPtr->SduDataPtr == NULL_PTR)
        {
          errorId = CDDDK4_E_PARAM_POINTER;
        }
        else if(PduInfoPtr->SduLength > (*AvailableDataPtr))
        {
          errorId = CDDDK4_E_PARAM_VALUE;
        }
#endif /* CDDDK4_DEV_ERROR_DETECT */
        else
        {
          SduDataPtrType lSrcPtr = &(CddDk4_ChannelInfo_GetPduInfo_SduDataPtr(lChannelId)[lBufPos]);
          CddDk4_MemCopy(PduInfoPtr->SduDataPtr, lSrcPtr, PduInfoPtr->SduLength);
          *AvailableDataPtr = *AvailableDataPtr - PduInfoPtr->SduLength;
          CddDk4_ChannelInfo_SetBufferPosition(lChannelId, lBufPos + PduInfoPtr->SduLength);
          if(*AvailableDataPtr == 0)
          {
            CddDk4_ChannelInfo_SetConState(lChannelId, CDDDK4_CONNECTION_WAIT_TXCONFIRMATION);
          }
          lResult = BUFREQ_OK;
        }
      }
    }
  }
/* ----- Development Error Report -------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_COPY_TX_DATA, errorId);
  }
#endif /* CDDDK4_DEV_ERROR_REPORT */
  CDDDK4_DUMMY_STATEMENT(Retry); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  return lResult;
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */
/**********************************************************************************************************************
 *CddDk4_ProvideTxBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#else /* CDDDK4_AR4_PDUR_SUPPORT */
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_ProvideTxBuffer(
                                                       PduIdType CddDk4TxPduId,
                                                       P2VAR(PduInfoTypeApplPtr, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr,
                                                       PduLengthType Length)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType lResult = BUFREQ_E_NOT_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (PduInfoPtr == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* get assigned connection ID */
    CddDk4_ConnectionIdType lConnId = CddDk4_GetConnIdTxPdu(CddDk4TxPduId);

#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    if (lConnId == CDDDK4_INVALID_CONNECTION_ID)
    {
      errorId = CDDDK4_E_PARAM_VALUE;
    }
    else
#endif
    {
      if (CddDk4_GetConnChannelAssignment(lConnId) != CDDDK4_NO_CHANNEL_ASSIGNED)
      {
        CddDk4_ConnChannelIdType lChannelId = CddDk4_GetConnChannelAssignment(lConnId);
        if (CddDk4_ChannelInfo_GetConState(lChannelId) == CDDDK4_CONNECTION_ROUTER_REQUEST_TRANSMIT)
        {
          /* callback CddDk4_ProvideTxBuffer was expected for this connection */
          if (Length <= CddDk4_ChannelInfo_GetPduInfo_SduLength(lChannelId))
          {
            /* TxBuffer is provided successfully */
            CddDk4_ChannelInfo_SetPduInfo_SduDataPtr(lChannelId, &CddDk4_ChannelInfo_GetPayload(lChannelId)[0]);
            *PduInfoPtr = CddDk4_ChannelInfo_GetPduInfoPtr(lChannelId);

            /* Connection has to wait for TxConfirmation */
            CddDk4_ChannelInfo_SetConState(lChannelId, CDDDK4_CONNECTION_WAIT_TXCONFIRMATION);
            lResult = BUFREQ_OK;
          }
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
          else
          {
            errorId = CDDDK4_E_PARAM_VALUE;
          }
#endif /* CDDDK4_DEV_ERROR_DETECT */
        }
      }
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_PROVIDE_TX_BUFFER, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 *CddDk4_StartOfReception()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_StartOfReception(
                    PduIdType CddDk4RxPduId,
                    P2VAR(PduInfoType, AUTOMATIC, CDDDK4_APPL_DATA) PduInfoPtr, /* PRQA S 3673 */ /* MD_CDDDK4_16.7_2 */
                    PduLengthType TpSduLength,
                    P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr)
{
    /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType lResult = BUFREQ_E_NOT_OK;
  CddDk4_ConnectionIdType lConnId;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = CDDDK4_E_NO_ERROR;
  /* Check initialization state of the component */
  if (CddDk4_Init_State != CDDDK4_INIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (CddDk4RxPduId >= CDDDK4_RX_PDU_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PDU_ID_RX_OUT_OF_RANGE;
  }
  else if(BufferSizePtr == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif /* CDDDK4_DEV_ERROR_DETECT */
  {
    lConnId = CddDk4_GetConnIdRxPdu(CddDk4RxPduId);
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    if (lConnId == CDDDK4_INVALID_CONNECTION_ID)
    {
      errorId = CDDDK4_E_PARAM_VALUE;
    }
    else
#endif
    {
    /* ----- Implementation ----------------------------------------------- */
      CddDk4_ConnChannelIdType lChannelId;
      lChannelId = CddDk4_GetConnChannelAssignment(lConnId);

      /* Check if any channel is assigned to connection */
      if (lChannelId != CDDDK4_NO_CHANNEL_ASSIGNED)
      {
        /* in case TP is probing buffer size */
        if (TpSduLength == 0)
        {
          *BufferSizePtr = CDDDK4_CONNECTION_CHANNEL_BUFFER_LIMIT;
          lResult = BUFREQ_OK;
        }
        else
        {
          /* normal use case */
          lResult = CddDk4_ProvideBuffer(lChannelId, TpSduLength, BufferSizePtr);
          if((lResult == BUFREQ_OK) && (PduInfoPtr != NULL_PTR))
          {
            lResult = CddDk4_CopyPduIntoBuffer(lChannelId, PduInfoPtr, BufferSizePtr, CDDDK4_SID_START_OF_RECEPTION);
          }
        }
      }
    }
  }
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_START_OF_RECEPTION, errorId);
  }
#endif /* CDDDK4_DEV_ERROR_REPORT */
  return lResult;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif/* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 *CddDk4_CopyRxData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_CopyRxData(
                    PduIdType CddDk4RxPduId,
                    P2VAR(PduInfoType, AUTOMATIC, CDDDK4_APPL_DATA) PduInfoPtr, /* PRQA S 3673 */ /* MD_CDDDK4_16.7_2 */
                    P2VAR(PduLengthType, AUTOMATIC, CDDDK4_APPL_DATA) BufferSizePtr)
{
    /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType lResult = BUFREQ_E_NOT_OK;
  CddDk4_ConnectionIdType lConnId;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  uint8 errorId = CDDDK4_E_NO_ERROR;
  /* Check initialization state of the component */
  if (CddDk4_Init_State != CDDDK4_INIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (CddDk4RxPduId >= CDDDK4_RX_PDU_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PDU_ID_RX_OUT_OF_RANGE;
  }
  else if(PduInfoPtr == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else if(BufferSizePtr == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif /* CDDDK4_DEV_ERROR_DETECT */
  {
    lConnId = CddDk4_GetConnIdRxPdu(CddDk4RxPduId);
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    if (lConnId == CDDDK4_INVALID_CONNECTION_ID)
    {
      errorId = CDDDK4_E_PARAM_VALUE;
    }
    else
#endif
    {
    /* ----- Implementation ----------------------------------------------- */
      CddDk4_ConnChannelIdType lChannelId;
      lChannelId = CddDk4_GetConnChannelAssignment(lConnId);

      /* Check if any channel is assigned to connection */
      if(  (lChannelId != CDDDK4_NO_CHANNEL_ASSIGNED)
         &&(CddDk4_ChannelInfo_GetConState(lChannelId) == CDDDK4_CONNECTION_WAIT_COPY_RESPONSE))
      {
        lResult = BUFREQ_OK;
        /* in case TP is probing buffer size */
        if (PduInfoPtr->SduLength == 0)
        {
          *BufferSizePtr = PduInfoPtr->SduLength - CddDk4_ChannelInfo_GetBufferPosition(lChannelId);
        }
        else
        {
          lResult = CddDk4_CopyPduIntoBuffer(lChannelId, PduInfoPtr, BufferSizePtr, CDDDK4_SID_COPY_RX_DATA);
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
          if ((*BufferSizePtr == 0) && (lResult == BUFREQ_OK))
#else  /* CDDDK4_DEV_ERROR_DETECT */
          if (*BufferSizePtr == 0)
#endif /* CDDDK4_DEV_ERROR_DETECT */
          {
            CddDk4_ChannelInfo_SetConState(lChannelId, CDDDK4_CONNECTION_WAIT_RXINDICATION);
          }
        }
      }
    }
  }
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_COPY_RX_DATA, errorId);
  }
#endif /* CDDDK4_DEV_ERROR_REPORT */
  return lResult;
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF */
#endif/* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 *CddDk4_ProvideRxBuffer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
FUNC(BufReq_ReturnType, CDDDK4_CODE) CddDk4_ProvideRxBuffer(
                                                       PduIdType CddDk4RxPduId,
                                                       PduLengthType TpSduLength,
                                                       P2VAR(PduInfoTypeApplPtr, AUTOMATIC, CDDDK4_APPL_VAR) PduInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  BufReq_ReturnType lResult = BUFREQ_E_NOT_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;
  CddDk4_ConnectionIdType lConnId;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (CddDk4RxPduId >= CDDDK4_RX_PDU_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PDU_ID_RX_OUT_OF_RANGE;
  }
  else if (PduInfoPtr == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else if (TpSduLength == 0)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* get assigned Connection Id */
    lConnId = CddDk4_GetConnIdRxPdu(CddDk4RxPduId);

#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
    if (lConnId == CDDDK4_INVALID_CONNECTION_ID)
    {
      errorId = CDDDK4_E_PARAM_VALUE;
    }
    else
#endif
    {
      CddDk4_ConnChannelIdType lChannelId = CddDk4_GetConnChannelAssignment(lConnId);

      /* Check if any channel is assigned to connection */
      if (lChannelId != CDDDK4_NO_CHANNEL_ASSIGNED)
      {
        lResult = CddDk4_ProvideBuffer(lChannelId, TpSduLength, PduInfoPtr);
      }
    }
  }


  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_PROVIDE_RX_BUFFER, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  return lResult;
}   /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* CDDDK4_AR4_PDUR_SUPPORT */

#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *CddDk4_TpTxConfirmation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_TpTxConfirmation(PduIdType CddDk4TxPduId, Std_ReturnType Result)
{
  CddDk4_TxConfirmation_Internal(CddDk4TxPduId, Result);
}
#endif /* CDDDK4_AR4_PDUR_SUPPORT */
#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
/**********************************************************************************************************************
 *CddDk4_TxConfirmation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CDDDK4_CODE)
CddDk4_TxConfirmation(PduIdType CddDk4TxPduId,  NotifResultType Result)
{
  CddDk4_TxConfirmation_Internal(CddDk4TxPduId, Result);
}
#endif /* CDDDK4_AR4_PDUR_SUPPORT */

#if (CDDDK4_AR4_PDUR_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *CddDk4_TpRxIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_TpRxIndication(PduIdType CddDk4RxPduId, Std_ReturnType Result)
{
  CddDk4_RxIndication_Internal(CddDk4RxPduId, Result);
}
#endif /* CDDDK4_AR4_PDUR_SUPPORT */

#if (CDDDK4_AR4_PDUR_SUPPORT != STD_ON)
/**********************************************************************************************************************
 *CddDk4_RxIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CDDDK4_CODE)
CddDk4_RxIndication(PduIdType CddDk4RxPduId, NotifResultType Result)
{
  CddDk4_RxIndication_Internal(CddDk4RxPduId, Result);
}
#endif /* CDDDK4_AR4_PDUR_SUPPORT */


/**********************************************************************************************************************
 *CddDk4_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */
  CddDk4_Init_State = CDDDK4_UNINIT;
}

/**********************************************************************************************************************
 * CddDk4_MainFunction()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
  errorId = CDDDK4_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */

    if (CddDk4_Init_State == (uint8)CDDDK4_INIT)
    {
      /* Communication manger */
      CddDk4_ConnectionTimerTask();

      CddDk4_ConnManagerStateTask();

      /* Request manager */
      CddDk4_RequestManagerTimerTask();

      CddDk4_RequestManagerStateTask();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
  (void) Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_MAINFUNCTION, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
} /* CddDk4_MainFunction() */

/**********************************************************************************************************************
 * CddDk4_Init()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == CDDDK4_INIT)
  {
  errorId = CDDDK4_E_ALREADY_INITIALIZED;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    CddDk4_ConnChannelIdType_least lIndex;

     /* At startup there must be no delay between requests */
    CddDk4_ConnStartDelay = CDDDK4_TIMER_CONN_DELAY;

    /* init global variables */
    CddDk4_ApplRequestedDidsCount = 0;

    CddDk4_ActiveConnectionChannels = 0;

    CddDk4_CurrentConnChannelIndex = 0;

    /* Initialize list, so connection channels can be assigned */
    for (lIndex = 0; lIndex < CDDDK4_CONNECTION_CONFIG_COUNT; lIndex++)
    {
      CddDk4_SetConnChannelAssignment(lIndex, CDDDK4_NO_CHANNEL_ASSIGNED);
      CddDk4_SetConStateCounter(lIndex, 0);
    }

    for(lIndex = 0; lIndex < CDDDK4_CONNECTION_CHANNEL_LIMIT; lIndex++)
    {
      CddDk4_ChannelInfo_SetConState(lIndex, CDDDK4_CONNECTION_INACTIVE);

      /* clear application DID status buffer */
      CddDk4_SetStatus_ApplDidStatusbuffer(lIndex, CDDDK4_DID_STATUS_UNKNOWN);
    }

    /* clear DID status buffer */
    CddDk4_ClearDidStatusBuffer();


    CddDk4_Init_State = CDDDK4_INIT;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
  (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_INIT, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

} /* CddDk4_Init() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */

#if (CDDDK4_SUPPORT_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  CddDk4_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CDDDK4_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  if (versioninfo == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    versioninfo->vendorID = (CDDDK4_VENDOR_ID);
    versioninfo->moduleID = (CDDDK4_MODULE_ID);
    versioninfo->sw_major_version = (CDDDK4_SW_MAJOR_VERSION);
    versioninfo->sw_minor_version = (CDDDK4_SW_MINOR_VERSION);
    versioninfo->sw_patch_version = (CDDDK4_SW_PATCH_VERSION);
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_GET_VERSION_INFO, errorId);
  }
# else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif



/* ------------------------------------------------------------------------------------------------------------------ */
/* Request Manager                                                                                                    */
/* ------------------------------------------------------------------------------------------------------------------ */

/**********************************************************************************************************************
 *CddDk4_Indication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_Indication(
       uint8 SID,
       P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) RequestData,
       uint16 DataSize,
       uint8 ReqType,
       uint16 SourceAddress,
       P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_APPL_VAR) ErrorCode) /* PRQA S 3673 */ /* MD_CDDDK4_16.7 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  lResult = E_NOT_OK;
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    lResult = E_OK;
    if (  (SID == CDDDK4_SERVICE_0x22)
        ||(SID == CDDDK4_SERVICE_0x2E))
    {
      /* new Service request 0x22 or 0x2E received; clear status buffer */
      CddDk4_ClearDidStatusBuffer();
      CddDk4_RequestedService = SID;
    }
  }

  /* ----- Development Eriror Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_INDICATION, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  CDDDK4_DUMMY_STATEMENT(RequestData); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(ReqType); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(DataSize); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(SourceAddress); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(ErrorCode); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return lResult;
}  /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *CddDk4_Confirmation()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, CDDDK4_CODE)CddDk4_Confirmation(uint8 SID,
                                                     uint8 ReqType,
                                                     uint16 SourceAddress,
                                                     Dcm_ConfirmationStatusType ConfirmationStatus)
{

  /* ----- Implementation ----------------------------------------------- */
  CDDDK4_DUMMY_STATEMENT(SID); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(ReqType); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(SourceAddress); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(ConfirmationStatus); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return E_OK;
}


/**********************************************************************************************************************
 *CddDk4_IsDidAvailable()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_IsDidAvailable(uint16 DID,
                                                        Dcm_OpStatusType OpStatus,
                                                        P2VAR(Dcm_DidSupportedType, AUTOMATIC, CDDDK4_VAR) supported)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult = E_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
    if (supported != NULL_PTR)
    {
      *supported = DCM_DID_NOT_SUPPORTED;
    }
  }
  else if (supported == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation --------------------------------------- */
    *supported = DCM_DID_NOT_SUPPORTED;

    if (OpStatus == DCM_INITIAL)
    {
      /* new DID is requested */
      if (CddDk4_AddDidRequest(DID) == E_OK)
      {
        lResult = DCM_E_PENDING;
      }
    }
    else if (OpStatus == DCM_PENDING)
    {
      /* verify pending status of requested DID */
      lResult = CddDk4_IsDidAvailable_Pending(DID, supported);
    }
    else if (OpStatus == DCM_CANCEL)
    {
      /* cancel request for requested DID; if already requested, response will be ignored */
      CddDk4_DidStatusBufferIdxType lIdx = 0;

      while (  (lIdx < CddDk4_CurrentStatusBufferIdx)
             &&(  (CddDk4_GetDid_DidStatusBuffer(lIdx) != DID)
                ||(CddDk4_GetStatus_DidStatusbuffer(lIdx) > CDDDK4_DID_STATUS_PENDING))
        )
      {
        lIdx++;
      }

      if (lIdx < CddDk4_CurrentStatusBufferIdx)
      {
        /* the exclusive area is to assure the CANCEL status is not reset elsewhere, see CddDk4_ProcessDidRequest */
        CddDk4_EnterExclusiveAreaReqMgr();
        CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_REQUEST_CANCELED);
        CddDk4_LeaveExclusiveAreaReqMgr();
      }
    }
    else
    {
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
      /* not supported OpStatus */
      errorId = CDDDK4_E_PARAM_VALUE;
#endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_ISDIDAVAILABLE, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
}     /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */ /* 4 out of the detected CYC are in Det */


/**********************************************************************************************************************
 *CddDk4_ReadDidData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_ReadDidData(
                                                   uint16 DID,
                                                   P2VAR(uint8, AUTOMATIC, CDDDK4_VAR) Data,
                                                   Dcm_OpStatusType OpStatus,
                                                   P2VAR(uint16, AUTOMATIC, CDDDK4_VAR) DataLength,
                                                   P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_VAR) ErrorCode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult = E_NOT_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (Data == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else if (DataLength == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else if (ErrorCode == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation --------------------------------------- */
    if (OpStatus == DCM_INITIAL)
    {
      CddDk4_DidStatusBufferIdxType lStatusBufferIdx = 0;

      while (  (lStatusBufferIdx < CddDk4_CurrentStatusBufferIdx)
             &&(  (CddDk4_GetDid_DidStatusBuffer(lStatusBufferIdx) != DID)
                ||(CddDk4_GetStatus_DidStatusbuffer(lStatusBufferIdx) != CDDDK4_DID_WAITING_READ_DATA))
        )
      {
        lStatusBufferIdx++;
      }

      if (lStatusBufferIdx < CddDk4_CurrentStatusBufferIdx)
      {
        if (CddDk4_GetDataPtr_DidStatusbuffer(lStatusBufferIdx) != NULL_PTR)
        {
          /* DID data is in buffer */
          /* copy DID data in buffer */
          CddDk4_MemCopy(Data,
                         CddDk4_GetDataPtr_DidStatusbuffer(lStatusBufferIdx),
                         CddDk4_GetDidSize_DidStatusbuffer(lStatusBufferIdx));
          *DataLength = CddDk4_GetDidSize_DidStatusbuffer(lStatusBufferIdx);
          CddDk4_SetStatus_DidStatusbuffer(lStatusBufferIdx, CDDDK4_DID_READ_FINISHED);
          lResult = E_OK;
        }
        else
        {
          *ErrorCode = DCM_E_RESPONSETOOLONG;
        }
      }
      else
      {
        /* DID is not available to read */
        *ErrorCode = DCM_E_GENERALREJECT;
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
        errorId = CDDDK4_E_PARAM_VALUE;
#endif
      }
    }
    else
    {
      /* OpStatus is not equal DCM_INITIAL */
      *ErrorCode = DCM_E_GENERALREJECT;
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
      errorId = CDDDK4_E_PARAM_VALUE;
#endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_READ_DIDDATA, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */


/**********************************************************************************************************************
 *CddDk4_WriteRemoteDidData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_WriteRemoteDidData(uint16 DID,
                                                               CddDk4_ConnectionIdType ConnId,
                                                               P2CONST(uint8, AUTOMATIC, CDDDK4_APPL_VAR) Data,
                                                               uint16 DataLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ReturnType lResult = CDDDK4_RET_NOT_OK;
#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (ConnId >= CDDDK4_CONNECTION_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else if (Data == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else if (DataLength == 0)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else
# endif
  {
    /* ----- Implementation --------------------------------------- */
    /* check if data + 3 Byte Overhead fits in channel buffer */
    if ((DataLength + 3) <= CDDDK4_CONNECTION_CHANNEL_BUFFER_LIMIT)
    {
      lResult = CddDk4_WriteRemoteDidData_Internal(DID, ConnId, Data, DataLength);
    }
    else
    {
      lResult = CDDDK4_RET_BUFFER_OVFL;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_WRITE_REMOTE_DIDDATA, errorId);
  }
# else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
#else
  CDDDK4_DUMMY_STATEMENT(DID); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(ConnId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(Data); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(DataLength); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif /* CDDDK4_CFG_SUPPORT_APPLNOTIFY  */

  return lResult;
}                                                   /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *CddDk4_RequestRemoteDidData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(CddDk4_ReturnType, CDDDK4_CODE) CddDk4_RequestRemoteDidData(uint16 DID, CddDk4_ConnectionIdType ConnId)
{
  /* ----- Local Variables ---------------------------------------------- */
  CddDk4_ReturnType lResult = CDDDK4_RET_NOT_OK;
#if (CDDDK4_CFG_SUPPORT_APPLNOTIFY == STD_ON)
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (ConnId >= CDDDK4_CONNECTION_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else
# endif
  {
    /* ----- Implementation --------------------------------------- */
    CddDk4_DidStatusBufferIdxType lStatusIdx = CDDDK4_CONNECTION_CHANNEL_LIMIT;
    CddDk4_EnterExclusiveAreaReqMgr();
    if (CddDk4_ApplRequestedDidsCount < CDDDK4_CONNECTION_CHANNEL_LIMIT)
    {
      /* application DID status buffer is not full */
      /* looking for free position in application status buffer */
      lStatusIdx = 0;
      while (  (lStatusIdx < CDDDK4_CONNECTION_CHANNEL_LIMIT)
             &&(CddDk4_GetStatus_ApplDidStatusbuffer(lStatusIdx) != CDDDK4_DID_STATUS_UNKNOWN))
      {
        lStatusIdx++;
      }

      /* the index will always be valid because CddDk4_ApplRequestedDidsCount is already validated to be less than
       * CDDDK4_CONNECTION_CHANNEL_LIMIT
       */
      /* PRQA S 3689 6 */ /* MD_CDDDK4_21.1_3689 */
      CddDk4_SetStatus_ApplDidStatusbuffer(lStatusIdx, CDDDK4_DID_WAITING_REQUEST);
      CddDk4_SetDid_ApplDidStatusBuffer(lStatusIdx, DID);
      CddDk4_SetSid_ApplDidStatusBuffer(lStatusIdx, CDDDK4_SERVICE_0x22);
      CddDk4_SetRetryCounter_ApplDidStatusbuffer(lStatusIdx, CDDDK4_CFG_MAX_REQUEST_RETRIES);
      CddDk4_SetRetryDelay_ApplDidStatusBuffer(lStatusIdx, CDDDK4_CFG_REQUEST_RETRY_DELAY);
      CddDk4_SetConnId_ApplDidStatusbuffer(lStatusIdx, ConnId);
      lResult = CDDDK4_RET_OK;
      CddDk4_ApplRequestedDidsCount++;
    }
    CddDk4_LeaveExclusiveAreaReqMgr();

    /* set rest of status information after leaving critical section */
    if (lStatusIdx == CDDDK4_CONNECTION_CHANNEL_LIMIT)
    {
      lResult = CDDDK4_RET_NO_FREE_CHANNEL;
    }

  }

  /* ----- Development Error Report --------------------------------------- */
# if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_REQUEST_REMOTE_DIDDATA, errorId);
  }
# else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
#else
  CDDDK4_DUMMY_STATEMENT(DID);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  CDDDK4_DUMMY_STATEMENT(ConnId);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif  /* CDDDK4_CFG_SUPPORT_APPLNOTIFY */

  return lResult;
}


/**********************************************************************************************************************
 *CddDk4_WriteDidData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_WriteDidData(
                                                   uint16 DID,
                                                   P2CONST(uint8, AUTOMATIC, CDDDK4_VAR) Data,
                                                   Dcm_OpStatusType OpStatus,
                                                   uint16 DataLength,
                                                   P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, CDDDK4_VAR) ErrorCode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult = E_NOT_OK;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (Data == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else if (DataLength == 0)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else if (ErrorCode == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation --------------------------------------- */
    *ErrorCode = DCM_E_GENERALREJECT;

    if (OpStatus == DCM_INITIAL)
    {
      lResult = CddDk4_WriteDidData_Initial(DID, Data, DataLength, ErrorCode);
    }
    else if (OpStatus == DCM_PENDING)
    {
      lResult = CddDk4_WriteDidData_Pending(DID, ErrorCode);
    }
    else if (OpStatus == DCM_CANCEL)
    {
        /* Service 0x2E only allowed for single DIDs; multi DID request are not allowed; lIdx set to 0 */
        CddDk4_DidStatusBufferIdxType lIdx = 0;

        if (CddDk4_GetDid_DidStatusBuffer(lIdx) == DID)
        {
          CddDk4_EnterExclusiveAreaReqMgr();
          if (  (CddDk4_GetStatus_DidStatusbuffer(lIdx) != CDDDK4_DID_REQUEST_IN_PROGRESS)
              &&(CddDk4_GetStatus_DidStatusbuffer(lIdx) != CDDDK4_DID_WRITE_FINISHED)
              &&(CddDk4_GetStatus_DidStatusbuffer(lIdx) != CDDDK4_DID_STATUS_UNKNOWN))
          {
            CddDk4_SetStatus_DidStatusbuffer(lIdx, CDDDK4_DID_REQUEST_CANCELED);
            lResult = E_OK;
          }
          CddDk4_LeaveExclusiveAreaReqMgr();

        }
        else
        {
          *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    else
    {
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
      errorId = CDDDK4_E_PARAM_VALUE;
#endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_WRITE_DIDDATA, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
} /* PRQA S 6080, 6030 */ /* MD_MSR_STMIF, MD_MSR_STCYC */


/* ------------------------------------------------------------------------------------------------------------------ */
/* Mode Manager                                                                                                       */
/* ------------------------------------------------------------------------------------------------------------------ */

/**********************************************************************************************************************
 *CddDk4_DisableConnection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_DisableConnection(CddDk4_ConnectionIdType ConnId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (ConnId >= CDDDK4_CONNECTION_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else
#endif
  {
    /* ----- Implementation --------------------------------------- */
    CddDk4_EnterExclusiveAreaReqMgr();
    if (CddDk4_GetConStateCounter(ConnId) == 255)
    {
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
      errorId = CDDDK4_E_PARAM_VALUE;
#endif
    }
    else
    {
      CddDk4_IncrementConStateCounter(ConnId);
    }
    CddDk4_LeaveExclusiveAreaReqMgr();
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_DISABLE_CONNECTION, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/**********************************************************************************************************************
 *CddDk4_EnableConnection()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CDDDK4_CODE) CddDk4_EnableConnection(CddDk4_ConnectionIdType ConnId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  /* Check initialization state of the component */
  if (CddDk4_Init_State == (uint8)CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (ConnId >= CDDDK4_CONNECTION_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else
#endif
  {
    /* ----- Implementation --------------------------------------- */
    CddDk4_EnterExclusiveAreaReqMgr();
    if (CddDk4_GetConStateCounter(ConnId) > 0)
    {
      CddDk4_DecrementConStateCounter(ConnId);
    }
    CddDk4_LeaveExclusiveAreaReqMgr();
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_ENABLE_CONNECTION, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/**********************************************************************************************************************
 *CddDk4_GetConnectionStateCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CDDDK4_CODE) CddDk4_GetConnectionStateCounter(CddDk4_ConnectionIdType ConnId,
                                                                   P2VAR(uint8, AUTOMATIC, CDDDK4_VAR) Counter)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType lResult;
  uint8 errorId = CDDDK4_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CDDDK4_DEV_ERROR_DETECT == STD_ON)
  lResult = E_NOT_OK;

  /* Check initialization state of the component */
  if (CddDk4_Init_State == CDDDK4_UNINIT)
  {
    errorId = CDDDK4_E_UNINIT;
  }
  else if (ConnId >= CDDDK4_CONNECTION_CONFIG_COUNT)
  {
    errorId = CDDDK4_E_PARAM_VALUE;
  }
  else if (Counter == NULL_PTR)
  {
    errorId = CDDDK4_E_PARAM_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation --------------------------------------- */
    *Counter = CddDk4_GetConStateCounter(ConnId);
    lResult = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CDDDK4_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CDDDK4_E_NO_ERROR)
  {
    (void)Det_ReportError(CDDDK4_MODULE_ID, CDDDK4_INSTANCE_ID_DET, CDDDK4_SID_GET_CONNECTION_STATE_COUNTER, errorId);
  }
#else
  CDDDK4_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return lResult;
}

#define CDDDK4_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:

   MD_CDDDK4_16.7:
   Description: Rule 16.7: A pointer parameter in a function prototype should be declared as pointer to const if the
                pointer is not used to modify the addressed object.
   Reason:      The function has write access to shared state. The caller may not rely on constancy. Even if the
                current implementation does not need write access, this is allowed to change. A stable interface is
                preferred to adhering to this rule.
   Risk:        None.
   Prevention:  None.

   MD_CDDDK4_16.7_2:
   Description: Rule 16.7: A pointer parameter in a function prototype should be declared as pointer to const if the
                pointer is not used to modify the addressed object.
   Reason:      The interface is an implementation of another module's callout function, the prototype is therefore
                defined by that module and CddDk4 is not free to change it.
   Risk:        None.
   Prevention:  None.

   MD_CDDDK4_1.1:
   Description: Rule 1.1 All code shall conform to ISO 9899:1990 C programming language, ISO 9899, amended and corrected
                by ISO/IEC 9899/COR1:1995, ISO/IEC 9899/AMD1:1995, and ISO/IEC 9899/COR2: 1996
   Reason:      Depending on the configuration size of Objects can exceed the C90 limit of 32767 bytes.
   Risk:        Compilation error.
   Prevention:  Compiler compatibility must be tested during integration.

   MD_CDDDK4_21.1_3689:
   Description: Rule 21.1 Message 3689: Indexing array with value that will apparently be out of bounds.
   Reason:      If CddDk4_ApplRequestedDidsCount is less than CDDDK4_CONNECTION_CHANNEL_LIMIT then there must be an
                empty slot, and thus the index will always be valid because CddDk4_ApplRequestedDidsCount is already
                validated to be less than CDDDK4_CONNECTION_CHANNEL_LIMIT.
   Risk:        None.
   Prevention:  None.
 */

/**********************************************************************************************************************
 *  END OF FILE: CddDk4.c
 *********************************************************************************************************************/

