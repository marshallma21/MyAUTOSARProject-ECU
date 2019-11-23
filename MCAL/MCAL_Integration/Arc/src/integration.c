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

#include "Std_Types.h"
#include "irq.h"
#include "isr.h"
#include "Integration.h"

#define ISR_PRIORITY	6uL


/******************************************************/



/*******************************************/

extern void Adc_Adc12bsarv2_EndGroupConvUnit0 (void);
// extern void Adc_Adc12bsarv2_EndGroupConvUnit1(void);

//extern void FTM_2_CH_0_CH_1_ISR (void);

/**
 * Installing all MCAL Interrupts
 */
void MCAL_IRQ_setup( void )
{
//#if defined(USE_CAN)
//    //Can0
//    ISR_INSTALL_ISR2("CAN0_Recv",  Can0_IsrReceiveHandler,  		IRQ_SRC_CAN0INT0, PRIO_CAN0_0,  0);
//    ISR_INSTALL_ISR2("CAN0_Trans", Can0_IsrTransmitHandler, 		IRQ_SRC_CAN0INT1, PRIO_CAN0_1,  0);
//    ISR_INSTALL_ISR2("CAN0_Busoff",Can0_IsrBusOffHandler,   		IRQ_SRC_CAN0INT2, PRIO_CAN0_2,  0);
//    ISR_INSTALL_ISR2("CAN0_Recv_FIFO",Can0_IsrReceiveFIFOHandler, 	IRQ_SRC_CAN0INT3, PRIO_CAN0_3,  0);
//
//    //Can1
//    ISR_INSTALL_ISR2("CAN1_Recv",  Can1_IsrReceiveHandler,  		IRQ_SRC_CAN1INT0, 	PRIO_CAN1_0,  0);
//    ISR_INSTALL_ISR2("CAN1_Trans", Can1_IsrTransmitHandler, 		IRQ_SRC_CAN1INT1, 	PRIO_CAN1_1,  0);
//    ISR_INSTALL_ISR2("CAN1_Busoff",Can1_IsrBusOffHandler,   		IRQ_SRC_CAN1INT2, 	PRIO_CAN1_2,  0);
//    ISR_INSTALL_ISR2("CAN0_Recv_FIFO",Can0_IsrReceiveFIFOHandler,  	IRQ_SRC_CAN1INT3, 	PRIO_CAN1_3,  0);
//#endif
#if defined(USE_ADC)
    //ADC
    ISR_INSTALL_ISR2("ADC_0",    Adc_Adc12bsarv2_EndGroupConvUnit0,   ADC0_IRQn,  ISR_PRIORITY, 0);
//    ISR_INSTALL_ISR2("ADC_1",    Adc_Adc12bsarv2_EndGroupConvUnit1,   ADC1_IRQn,  ADC_ISR_PRIORITY, 0);
#endif
#if defined(USE_PWM)
    //ADC
    //ISR_INSTALL_ISR2("PWM_0",    FTM_2_CH_0_CH_1_ISR,   FTM2_Ch0_Ch1_IRQn,  ISR_PRIORITY, 0);
//    ISR_INSTALL_ISR2("ADC_1",    Adc_Adc12bsarv2_EndGroupConvUnit1,   ADC1_IRQn,  ADC_ISR_PRIORITY, 0);
#endif

}

uint32 Mcu_Arc_GetSystemClock(void) {

    return (uint32)80000000;
}
