/*-------------------------------- Arctic Core ------------------------------
 * Copyright (C) 2013, ArcCore AB, Sweden, www.arccore.com.
 * Contact: <contact@arccore.com>
 *
 * You may ONLY use this file:
 * 1)if you have a valid commercial ArcCore license and then in accordance with
 * the terms contained in the written license agreement between you and ArcCore,
 * or alternatively
 * 2)if you follow the terms found in GNU General Public License version 2 as
 * published by the Free Software Foundation and appearing in the file
 * LICENSE.GPL included in the packaging of this file or here
 * <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>
 *-------------------------------- Arctic Core -----------------------------*/

#ifndef INTEGRATION_H_
#define INTEGRATION_H_

#if defined(USE_MCU)
#include "MCU_integration.h"
#endif
#if defined(USE_CAN)
#include "Can_integration.h"
#endif
#if defined(USE_PORT)
#include "Port_integration.h"
#endif
#if defined(USE_ADC)
#include "Adc_integration.h"
#endif
#if defined(USE_DIO)
#include "Dio_integration.h"
#endif
#if defined(USE_FLS)
#include "Fls_integration.h"
#endif
#if defined(USE_FEE)
#include "Fee_integration.h"
#endif
#if defined(USE_GPT)
#include "Gpt_integration.h"
#endif
#if defined(USE_WDG)
#include "Wdg_integration.h"
#endif
#if defined(USE_PWM)
#include "Pwm_integration.h"
#endif
#if defined(USE_OS)
#include "Os_integration.h"
#endif

void MCAL_IRQ_setup( void );
uint32 Mcu_Arc_GetSystemClock(void);

#endif /* INTEGRATION_H_ */
