# Version of build system
REQUIRED_BUILD_SYSTEM_VERSION=1.0.0

# Get configuration makefiles
-include ../config/Rte/Config/*.mk
-include ../config/$(BOARDDIR)/Rte/Config/*.mk
-include ../config/*.mk
-include ../config/$(BOARDDIR)/*.mk


# Project settings

SELECT_CONSOLE = RAMLOG

SELECT_OPT = OPT_DEBUG 

#########################################
#	MCAL modules to be used from NXP	#
#########################################

MOD_AVAIL += MCALBASE
MOD_AVAIL += MCL
MOD_AVAIL += ARC

MOD_USE += ADC
MOD_USE += CAN 
MOD_USE += DIO 
MOD_USE += MCU 
MOD_USE += PORT 
MOD_USE += PWM
#MOD_USE += GPT
MOD_USE += MCALBASE 
MOD_USE += MCL 
MOD_USE += ARC
#MOD_USE += SPI

#Selecting Compiler being used for the NXP MCAL
CFG += CANIF_ASR_4_3_1

def-y += CPU_S32K144HFT0VLLT
def-y += CFG_MCAL_EXTERNAL
