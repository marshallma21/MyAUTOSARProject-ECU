WDG_MCAL_MODULE:=Wdg_TS_${MCAL_VERSION}


# Static MCAL impmentation done by Freescale
inc-y += $(MCAL_PLUGINS_PATH)/$(WDG_MCAL_MODULE)/include
vpath-y += $(MCAL_PLUGINS_PATH)/$(WDG_MCAL_MODULE)/src
obj-y += $(patsubst %.c,%.o,$(notdir $(wildcard $(MCAL_PLUGINS_PATH)/$(WDG_MCAL_MODULE)/src/*.c)))
obj-y += Wdg_CfgExt.o
obj-y += Wdg_Cfg.o
obj-y += Wdg_Lcfg.o
obj-y += Wdg_PBcfg.o