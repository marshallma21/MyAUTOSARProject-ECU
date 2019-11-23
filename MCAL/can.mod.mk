CAN_MCAL_MODULE:=Can_TS_${MCAL_VERSION}

# Static MCAL impmentation done by Freescale
inc-y += $(MCAL_PLUGINS_PATH)/$(CAN_MCAL_MODULE)/include
vpath-y += $(MCAL_PLUGINS_PATH)/$(CAN_MCAL_MODULE)/src
obj-y += $(patsubst %.c,%.o,$(notdir $(wildcard $(MCAL_PLUGINS_PATH)/$(CAN_MCAL_MODULE)/src/*.c)))
obj-y += Can_Cfg.o
obj-y += Can_PBcfg.o
