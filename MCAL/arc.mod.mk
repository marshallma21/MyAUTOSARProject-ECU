ARC_MCAL_MODULE:=Arc

# Static MCAL integration done by ArcCore
inc-y += $(MCAL_CONFIG_PATH)/MCAL_Integration/$(ARC_MCAL_MODULE)/include
vpath-y += $(MCAL_CONFIG_PATH)/MCAL_Integration/$(ARC_MCAL_MODULE)/src
obj-y += $(patsubst %.c,%.o,$(notdir $(wildcard $(MCAL_CONFIG_PATH)/MCAL_Integration/$(ARC_MCAL_MODULE)/src/*.c)))


