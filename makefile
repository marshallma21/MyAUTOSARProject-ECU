
# Project name, used for output files et.c.
PROJECTNAME = MyAUTOSARProject-ECU


#################### Arctic Core make system ######################
# Following is an explanation of the most usable features 
# of the Arctic Core make system.
#
# obj-y : list of object files to build.
# VPATH : list of directories in which to
#         look for source files.
# inc-y : list of directories in which to
#         look for header files.
# libitem-y : list of libraries to include. 
# build-exe-y : the name of build the output file.
# ldcmdfile-y: path to linkscript, used when building "build-exe-y"
#
# For more information see:
# http://arccore.com/wiki/Makesystem
###################################################################


#MCAL make files
include ../MCAL/mcal.mod.mk 

VPATH += ../MCAL/MCAL_Integration/src
inc-y += ../MCAL/MCAL_Integration/include

include $(ROOTDIR)/scripts/project_defaults.mk
#include $(ROOTDIR)/scripts/rules.mk
VPATH += ../include
inc-y += ../include

VPATH += ../config/$(board_name)
inc-y += ../config/$(board_name)

# Project files (adds all .c files in src directory)
VPATH += ../src
inc-y += ../src
PROJECT_C_FILES=$(notdir $(wildcard ../*.c))
obj-y += $(PROJECT_C_FILES:%.c=%.o)

inc-y += ..

ifeq ($(COMPILER),gcc)
CFLAGS_Rte.o += -Werror
CFLAGS_Rte_Main.o += -Werror
CFLAGS_Rte_Calprms.o += -Werror
CFLAGS_Rte_Internal.o += -Werror
CFLAGS_Rte_Callbacks.o += -Werror
CFLAGS_Rte_Fifo.o += -Werror
CFLAGS_Rte_BswM.o += -Werror
CFLAGS_Rte_ComM.o += -Werror
CFLAGS_Rte_Dcm.o += -Werror
CFLAGS_Rte_Dem.o += -Werror
CFLAGS_Rte_Det.o += -Werror
CFLAGS_Rte_Dlt.o += -Werror
#CFLAGS_Rte_EcuM.o += -Werror
CFLAGS_Rte_IoHwAb.o += -Werror
CFLAGS_Rte_SwcReaderType.o += -Werror
CFLAGS_Rte_SwcWriterType.o += -Werror
CFLAGS_Rte_WdgM.o += -Werror
CFLAGS_DcmCallbacks.o += -Werror
CFLAGS_Dem_Callbacks.o += -Werror
CFLAGS_IoHwAb.o += -Werror
CFLAGS_PlatformTasks.o += -Werror
CFLAGS_SbcCdd.o += -Werror
CFLAGS_SpiCallbacks.o += -Werror
CFLAGS_SwcReader.o += -Werror
CFLAGS_SwcWriter.o += -Werror
CFLAGS_os_hooks.o += -Werror
CFLAGS_Os_Cfg.o += -Werror
#CFLAGS_EcuM.o += -Werror
#CFLAGS_EcuM_Fixed.o += -Werror
#CFLAGS_EcuM_Main.o += -Werror
#CFLAGS_EcuM_PBcfg.o += -Werror
#CFLAGS_EcuM_PBHeader.o += -Werror
#CFLAGS_EcuM_GeneratedCallouts.o += -Werror
#CFLAGS_EcuM_Callout_Stubs.o += -Werror
CFLAGS_Crc.o += -Werror
CFLAGS_Crc_8.o += -Werror
CFLAGS_Crc_16.o += -Werror
CFLAGS_Crc_32.o += -Werror
#CFLAGS_BswM.o += -Werror
CFLAGS_Mcu.o += -Werror
CFLAGS_Mcu_LCfg.o += -Werror
CFLAGS_Mcu_PBcfg.o += -Werror
CFLAGS_Port.o += -Werror
CFLAGS_Port_Lcfg.o += -Werror
CFLAGS_Port_PBcfg.o += -Werror
CFLAGS_Fls.o += -Werror
CFLAGS_Fls_Cfg.o += -Werror
CFLAGS_Can.o += -Werror
CFLAGS_Can_PBcfg.o += -Werror
CFLAGS_CanIf.o += -Werror
CFLAGS_CanIf_Cfg.o += -Werror
CFLAGS_CanIf_PBCfg.o += -Werror
CFLAGS_CanTp.o += -Werror
CFLAGS_CanTp_PBCfg.o += -Werror
CFLAGS_Dio.o += -Werror
CFLAGS_Dio_Lcfg.o += -Werror
CFLAGS_Adc_Cfg.o += -Werror
CFLAGS_Adc_Internal.o += -Werror
CFLAGS_arch_krn.o += -Werror
CFLAGS_os_event.o += -Werror
CFLAGS_os_init.o += -Werror
CFLAGS_arch.o += -Werror
CFLAGS_os_task.o += -Werror
CFLAGS_os_resource.o += -Werror
CFLAGS_os_alarm.o += -Werror
CFLAGS_os_sched_table.o += -Werror
CFLAGS_os_counter.o += -Werror
CFLAGS_sys_tick.o += -Werror
CFLAGS_os_isr.o += -Werror
CFLAGS_os_arctest.o += -Werror
CFLAGS_os_application.o += -Werror
CFLAGS_irq.o += -Werror
CFLAGS_NvM.o += -Werror
CFLAGS_NvM_Cfg.o += -Werror
CFLAGS_MemIf.o += -Werror
CFLAGS_Fee.o += -Werror
CFLAGS_Fee_Cfg.o += -Werror
CFLAGS_Wdg.o += -Werror
CFLAGS_Wdg_Lcfg.o += -Werror
CFLAGS_ComM_Cfg.o += -Werror
CFLAGS_CanSM.o += -Werror
CFLAGS_CanSM_Internal.o += -Werror
CFLAGS_CanSM_LCfg.o += -Werror
CFLAGS_Com_Cfg.o += -Werror
CFLAGS_Com_PbCfg.o += -Werror
CFLAGS_Com_Com.o += -Werror
CFLAGS_Com_Sched.o += -Werror
CFLAGS_Com.o += -Werror
CFLAGS_Com_misc.o += -Werror
CFLAGS_PduR_CanNm.o += -Werror
CFLAGS_PduR_Com.o += -Werror
CFLAGS_PduR_Logic.o += -Werror
CFLAGS_PduR_LinIf.o += -Werror
CFLAGS_PduR_CDD_LinSlvIf.o += -Werror
CFLAGS_PduR_CddPduR.o += -Werror
CFLAGS_PduR_PbCfg.o += -Werror
CFLAGS_PduR_Cfg.o += -Werror
CFLAGS_PduR_CanIf.o += -Werror
CFLAGS_PduR_CanTp.o += -Werror
CFLAGS_PduR_J1939Tp.o += -Werror
CFLAGS_PduR_IpduM.o += -Werror
CFLAGS_PduR_Dcm.o += -Werror
CFLAGS_PduR_SoAd.o += -Werror
CFLAGS_PduR_Routing.o += -Werror
CFLAGS_PduR.o += -Werror
CFLAGS_PduR_FrIf.o += -Werror
CFLAGS_PduR_FrNm.o += -Werror
CFLAGS_PduR_FrTp.o += -Werror
CFLAGS_PduR_UdpNm.o += -Werror
CFLAGS_PduR_LdCom.o += -Werror
CFLAGS_IoHwAb_Digital.o += -Werror
CFLAGS_IoHwAb_Analog.o += -Werror
CFLAGS_IoHwAb_Pwm.o += -Werror
CFLAGS_Dem.o += -Werror
CFLAGS_Dem_LCfg.o += -Werror
CFLAGS_Dcm.o += -Werror
CFLAGS_Dcm_Dsp.o += -Werror
CFLAGS_Dcm_Dsd.o += -Werror
CFLAGS_Dcm_Dsl.o += -Werror
CFLAGS_Dcm_ROE.o += -Werror
CFLAGS_Dcm_Internal.o += -Werror
CFLAGS_Dcm_LCfg.o += -Werror
CFLAGS_Dcm_Callout_Stubs.o += -Werror
CFLAGS_Xcp.o += -Werror
CFLAGS_XcpOnCan.o += -Werror
CFLAGS_XcpOnEth.o += -Werror
CFLAGS_Xcp_Program.o += -Werror
CFLAGS_Xcp_Memory.o += -Werror
CFLAGS_Xcp_MemoryHelper.o += -Werror
CFLAGS_Xcp_Cfg.o += -Werror
CFLAGS_Xcp_Callout_Stubs.o += -Werror
CFLAGS_cirq_buffer.o += -Werror
CFLAGS_version.o += -Werror
CFLAGS_serial_dbg_winidea.o += -Werror
CFLAGS_clib_port.o += -Werror
CFLAGS_clib.o += -Werror
CFLAGS_printf.o += -Werror
CFLAGS_xtoa.o += -Werror
CFLAGS_Adc.o += -Werror
CFLAGS_Pwm.o += -Werror
CFLAGS_timer_dwt.o += -Werror

endif
