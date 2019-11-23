/*
 * Can_integration.h
 *
 *  Created on: 28-Dec-2016
 *      Author: sina
 */

#ifndef CAN_INTEGRATION_H_
#define CAN_INTEGRATION_H_

#include "Can.h"

/* @req 4.1.3/SWS_CanTrcv_00163 */
/** Operating modes of the CAN Transceiver Driver. */
typedef enum {
    /** Transceiver mode NORMAL. */
    CANTRCV_TRCVMODE_NORMAL = 0,

    /**  Transceiver mode SLEEP. */
    CANTRCV_TRCVMODE_SLEEP,

    /** Transceiver mode STANDBY. */
    CANTRCV_TRCVMODE_STANDBY,

    /** Transceiver mode not Initialized */
//QQ    CANTRCV_TRCVMODE_UNITIALIZED
} CanTrcv_TrcvModeType;

#define CanConfigData CanConfigSet

#define OsCounter_0 COUNTER_ID_OsRteCounter
#define OS_TicksToNs_OsCounter_0 OS_TICKS2NS_OsRteCounter

#endif /* CAN_INTEGRATION_H_ */
