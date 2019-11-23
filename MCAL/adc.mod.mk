ADC_MCAL_MODULE:=Adc_TS_${MCAL_VERSION}

# Static MCAL impmentation done by Freescale
inc-y += $(MCAL_PLUGINS_PATH)/$(ADC_MCAL_MODULE)/include
vpath-y += $(MCAL_PLUGINS_PATH)/$(ADC_MCAL_MODULE)/src
obj-y += $(patsubst %.c,%.o,$(notdir $(wildcard $(MCAL_PLUGINS_PATH)/$(ADC_MCAL_MODULE)/src/*.c)))
obj-y += Adc_Cfg.o
obj-y += Adc_PBcfg.o