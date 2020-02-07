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
/*!        \file  CddDk4_Types.h
 *        \brief  CddDk4 type definitions
 *
 *      \details  CddDk4 definitions of structs and enumerations and simple types.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vector Informatik
 *  Muhammad Tayel                vismul        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2015-09-16  vissat  -             Initial version
 *  02.00.00  2016-05-21  vismul  ESCAN00090611 FEAT-1716: Support for DK2 routing for VAG SLP5
 *                                ESCAN00089975 Compiler error: Error occurs when using CddDk4 module with an AUTOSAR 3
 *                                              SchM.
 *                                ESCAN00090292 Endless loop during main function.
 *  02.00.01  2016-10-06  vismul  ESCAN00087604 BETA version - the BSW module is in BETA state.
 *                                ESCAN00092197 Compiler warning: Possible loss of data.
 *********************************************************************************************************************/

#ifndef CDDDK4_TYPES_H
# define CDDDK4_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "ComStack_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* --- Basic Types ------------------------------------------------------------------------------------------------- */
/* Vector specific types */

/*! Services will be defined as 1 bit */
typedef uint32 CddDk4_ServiceMaskType;

/*! Timeout counter type */
typedef uint16 CddDk4_TimeoutType;

/*! Response message length type */
typedef uint16 CddDk4_LengthType;

/*! Response message length type _least variant for loop variables */
typedef uint16_least CddDk4_LengthType_least;

/*! Connection channel state type */
typedef uint8 CddDk4_ConnChannelStateType;

/*! Connection channel id type */
typedef uint8 CddDk4_ConnChannelIdType;

/*! Connection channel id type _least variant for loop variables */
typedef uint8_least CddDk4_ConnChannelIdType_least;

/*! CDDDK4 state type */
typedef uint8 CddDk4_StateType;

/*! Request PDU Id type */
typedef uint8 CddDk4_ReqSduIdType;

/*! Response PDU Id type */
typedef uint8 CddDk4_RespSduIdType;

/*! UDS Service Id type */
typedef uint8 CddDk4_ServiceIdType;

/*! Connection availability type */
typedef uint8 CddDk4_ConnectionAvailibilityInfoType;

/*! used to send Response/NRC to application  */
typedef uint8 CddDk4_RespInfoType;

/*! Index for the static configured Connection list */
typedef uint8 CddDk4_ConnectionIdType;

/*! Index for the static configured Connection list _least variant for loop variable */
typedef uint8_least CddDk4_ConnectionIdType_least;

/*! Response data type */
typedef uint8 CddDk4_RespDataType;

/*! Request data type */
typedef uint8 CddDk4_ReqDataType;

/*! Connection Channel Array */
typedef uint8 CddDk4_ConnChannelsType;

/*! CddDk4 specific return type */
typedef uint8 CddDk4_ReturnType;

/*! Did status type */
typedef uint8 CddDk4_DidStatusType;

/*! Did status buffer index type */
typedef uint16 CddDk4_DidStatusBufferIdxType;

/*! Did status buffer index type _least variant for loop variables */
typedef uint16_least CddDk4_DidStatusBufferIdxType_least;

/*! Did data buffer index type */
typedef uint16 CddDk4_DidDataBufferIdxType;

/*! Did table index type */
typedef uint16 CddDk4_DidTableIdxType;

/*! DID Number type */
typedef uint16 CddDk4_DidIdentifierType;

/*! Response data for application */
typedef struct
{
    uint8                    sid;                                      /* service id */
    CddDk4_ConnectionIdType  connId;                                   /* reference for static ConnectionConfig Table */
    CddDk4_RespInfoType      respCode;                                 /* response code */
    uint16                   did;                                      /* Requested Did */
    CddDk4_LengthType        dataLength;                               /* Length of data in respData */
    P2CONST(CddDk4_RespDataType, TYPEDEF, CDDDK4_APPL_VAR) respData;   /* Pointer to response data */
} CddDk4_ApplRespInfoStructType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* CDDDK4_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: CddDk4_Types.h
 *********************************************************************************************************************/

