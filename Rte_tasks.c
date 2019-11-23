#include "Os.h"
#include "Rte.h"
#include "S32K144.h" /* include peripheral declarations S32K144 */


static unsigned int test_counter = 0;
static unsigned int counter2 = 0;
static unsigned long counter3 = 0;
static unsigned char quality = 0;
static unsigned int sts = 0;
static unsigned int swtSts = 0;
static unsigned int PotValue = 0;



void add_counter( void ) {
	test_counter++;
}



void IntControllerMain( void ) {
	add_counter();
	//(void)TerminateTask();
}

void LEDActuatorMain( void ) {
	counter2++;
	if(counter2 > 10) {
		counter2 = 0;
		Rte_Call_LEDActuator_BlueLiActuatorInstance_LEDSignal_Write(sts);
		if(sts==0) {
			sts = 1;
		}else {
			sts = 0;
		}
	}
	
	
	//(void)TerminateTask();
}

void RedLiDimmingMain( void ) {
	counter3+=0xFF;
	if(counter3>0xFFFF){
		counter3=0;
	}
	Rte_Call_IoHwAb_IoHwAbInstance_Pwm_RedLEDDuty_Set(counter3, &quality);
	//(void)TerminateTask();
}

void TimeToggleLEDMain( void ) {
	add_counter();
	//(void)TerminateTask();
}

void PotSensorMain( void ) {

	Rte_Call_IoHwAb_IoHwAbInstance_Analog_POT_Read(&PotValue, &quality);
	//(void)TerminateTask();
}

void SwtSensorMain( void ) {
	Rte_Call_IoHwAb_IoHwAbInstance_Digital_Swt_Read(&swtSts,&quality);
	//(void)TerminateTask();
}

