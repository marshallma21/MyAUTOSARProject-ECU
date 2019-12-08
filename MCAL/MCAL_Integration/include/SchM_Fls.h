/*
 * SchM_Fls.h
 *
 *  Created on: 02-Mar-2017
 *      Author: sina
 */

#ifndef SCHM_FLS_H_
#define SCHM_FLS_H_

#define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10() SuspendOSInterrupts()
#define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11() SuspendOSInterrupts()
#define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12() SuspendOSInterrupts()
#define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13() SuspendOSInterrupts()

#define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10() ResumeOSInterrupts()
#define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11() ResumeOSInterrupts()
#define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12() ResumeOSInterrupts()
#define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13() ResumeOSInterrupts()

#endif /* SCHM_FLS_H_ */
