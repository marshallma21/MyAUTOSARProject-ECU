PORT_MCAL_MODULE:=Port_TS_${MCAL_VERSION}

# Static MCAL impmentation done by Freescale
inc-y += $(MCAL_PLUGINS_PATH)/$(PORT_MCAL_MODULE)/include
vpath-y += $(MCAL_PLUGINS_PATH)/$(PORT_MCAL_MODULE)/src
obj-y += $(patsubst %.c,%.o,$(notdir $(wildcard $(MCAL_PLUGINS_PATH)/$(PORT_MCAL_MODULE)/src/*.c)))
obj-y += Port_Cfg.o
obj-y += Port_PBcfg.o