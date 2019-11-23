MCL_MCAL_MODULE:=Mcl_TS_${MCAL_VERSION}

# Static MCAL impmentation done by Freescale
inc-y += $(MCAL_PLUGINS_PATH)/$(MCL_MCAL_MODULE)/include
vpath-y += $(MCAL_PLUGINS_PATH)/$(MCL_MCAL_MODULE)/src

obj-y += CDD_Mcl.o
obj-y += Ftm_Common.o
obj-y += LPit_Common.o
obj-y += Lptmr_Common.o
obj-y += Mcl_Dma_Irq.o
obj-y += Mcl_Dma.o
obj-y += Mcl_DmaMux.o
obj-y += Mcl_IPW.o
obj-y += Mcl_Lmem.o
obj-y += Mcl_TrgMux.o
obj-y += CDD_Mcl_Cfg.o
obj-y += CDD_Mcl_PBcfg.o
