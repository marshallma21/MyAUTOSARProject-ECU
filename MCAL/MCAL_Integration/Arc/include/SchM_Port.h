/*
 * SchM_Port.h
 *
 *  Created on: 02-Mar-2017
 *      Author: sina
 */

#ifndef SCHM_PORT_H_
#define SCHM_PORT_H_

#include "Os.h"

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00() SuspendOSInterrupts()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00() ResumeOSInterrupts()

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01() SuspendOSInterrupts()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01() ResumeOSInterrupts()

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02() SuspendOSInterrupts()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02() ResumeOSInterrupts()

#define SchM_Enter_Port_PORT_EXCLUSIVE_AREA_03() SuspendOSInterrupts()
#define SchM_Exit_Port_PORT_EXCLUSIVE_AREA_03() ResumeOSInterrupts()

#endif /* SCHM_PORT_H_ */
