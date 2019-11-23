#include "Os.h"
#include "Rte.h"
#include "S32K144.h" /* include peripheral declarations S32K144 */
#include "IoHwAb.h"
#include "Com.h"
#include "EcuM.h"

#define BSW_SERVICE_TASK_PERIOD	0.005

#define CAN_MAIN_PERIOD		((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define COMM_MAIN_PERIOD	((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define COM_MAIN_PERIOD		((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define ECUM_MAIN_PERIOD	((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define CANSM_MAIN_PERIOD	((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define CANTP_MAIN_PERIOD   ((uint32_t)(0.005 / BSW_SERVICE_TASK_PERIOD))
#define DCM_MAIN_PERIOD     ((uint32_t)(0.02 / BSW_SERVICE_TASK_PERIOD))
#define IOHWAB_MAIN_PERIOD  ((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define BSWM_MAIN_PERIOD    ((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define XCP_MAIN_PERIOD		((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define SWCMEM_MAIN_PERIOD  ((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))
#define WDGM_MAIN_PERIOD    ((uint32_t)(0.01 / BSW_SERVICE_TASK_PERIOD))

static uint32_t service = 0u;

void WDOG_disable (void){
  WDOG->CNT=0xD928C520; 	/* Unlock watchdog */
  WDOG->TOVAL=0x0000FFFF;	/* Maximum timeout value */
  WDOG->CS = 0x00002100;    /* Disable watchdog */
}

void OsIdle( void ) {
	for(;;){

	}
}

void OsStartupTask( void ) {
	EcuM_StartupTwo();
	WDOG_disable();
	//(void)TerminateTask();
}

void OsBswServiceTask( void ) {

	EcuM_StateType state = ECUM_STATE_OFF;

	(void)EcuM_GetState(&state);

    if (0u == (service % COM_MAIN_PERIOD)) {
        Com_MainFunctionRx();
        Com_MainFunctionTx();
    }

	if (0u == (service % IOHWAB_MAIN_PERIOD)) {
		IoHwAb_MainFunction();
	}

	service++;

	if( !((service % IOHWAB_MAIN_PERIOD)==0) )	{
		service = 0u;
	}

	(void)TerminateTask();
}
