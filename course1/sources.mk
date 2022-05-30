#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
# Modified by T. Green, 24 May 2022 
#
#*****************************************************************************

# Add your Source files to this variable
ifeq ($(PLATFORM), MSP432)
SOURCES = ./src/memory.c \
	./src/main.c \
	./src/interrupts_msp432p401r_gcc.c \
	./src/startup_msp432p401r_gcc.c \
	./src/system_msp432p401r.c
else
SOURCES = ./src/memory.c \
	./src/main.c
endif

ifeq ($(PLATFORM), MSP432)
HEADERS = memory.h \
	platform.h \
	cmsis_gcc.h \
	core_cm4.h \
	core_cmFunc.h \
	core_cmInstr.h \
	core_cmSimd.h \
	msp_compatibility.h \
	msp432p401r.h \
	system_msp432p401r.h 
else
HEADERS = memory.h \
	platform.h
endif

# Add your include paths to this variable
ifeq ($(PLATFORM), MSP432)
INCLUDES = -I ./include/CMSIS \
	-I ./include/common \
	-I ./include/msp432
else
INCLUDES = -I ./include/common
endif
