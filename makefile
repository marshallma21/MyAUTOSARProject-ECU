
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
obj-y += integration.o

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
PROJECT_C_FILES+=$(notdir $(wildcard ../src/*.c))
obj-y += $(PROJECT_C_FILES:%.c=%.o)

inc-y += ..
