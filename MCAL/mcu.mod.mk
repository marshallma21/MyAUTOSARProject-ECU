MCU_MCAL_MODULE:=Mcu_TS_${MCAL_VERSION}

# Static MCAL impmentation done by Freescale
inc-y += $(MCAL_PLUGINS_PATH)/$(MCU_MCAL_MODULE)/include
vpath-y += $(MCAL_PLUGINS_PATH)/$(MCU_MCAL_MODULE)/src

obj-y += $(patsubst %.c,%.o,$(notdir $(wildcard $(MCAL_PLUGINS_PATH)/$(MCU_MCAL_MODULE)/src/*.c)))
obj-y += Mcu_Cfg.o
obj-y += Mcu_PBcfg.o