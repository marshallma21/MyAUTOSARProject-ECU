FLS_MCAL_MODULE:=Fls_TS_${MCAL_VERSION}

# Static MCAL impmentation done by Freescale
inc-y += $(MCAL_PLUGINS_PATH)/$(FLS_MCAL_MODULE)/include
vpath-y += $(MCAL_PLUGINS_PATH)/$(FLS_MCAL_MODULE)/src
obj-y += $(patsubst %.c,%.o,$(notdir $(wildcard $(MCAL_PLUGINS_PATH)/$(FLS_MCAL_MODULE)/src/*.c)))
obj-y += Fls_Cfg.o
obj-y += Fls_PBcfg.o