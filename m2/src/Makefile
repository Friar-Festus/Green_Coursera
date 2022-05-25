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

#------------------------------------------------------------------------------
# Build c1m2.out or intermediate files for MSP432 or HOST (x86_64) targets
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#	   	.i -     Source files after running through pre-processor
#		.asm -   Assembler code from source files
#		.o - 	 Object files from source files
#		compile-all - 	
#				 Generate object files for all input implementation files
#		build -	 Generate executable binary 
#		clean -  Delete all intermediate, executable, and map files
#
# Platform Overrides:
#      	MSP432 - Specifically the MSP432P401R variant used on the MSP-EXP432P401R
#				 development board
#	   	HOST - 	 x86_64 Linux (Ubuntu 18.04)
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2.out

# Platform Overrides (Changed name to avoid self-referential error)
PLATFORM_SPEC = $(PLATFORM)

# Architectures Specific Flags
LINKER_FILE = -T ../msp432p401r.lds 
CPU = -mcpu=cortex-m4 
ARCH = -mthumb \
	-march=armv7e-m \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16
SPECS = --specs=nosys.specs 

# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	SIZE = arm-none-eabi-size
else 
	CC = gcc
	SIZE = size
endif

# LD = 
LDFLAGS = -Wl,-Map=c1m2.map
CFLAGS = -g -Wall -Werror -O0 -std=c99
DEPFLAGS = -MM -MP -MD

OBJDUMP = objdump -S

# CPPFLAGs = 

OBJS := $(SOURCES:.c=.o)
PREPROC := $(SOURCES:.c=.i)

build: $(TARGET)
compile-all: $(OBJS)

%.i : %.c
ifeq ($(PLATFORM), MSP432)
	$(CC) $(INCLUDES) $(CFLAGS) -E $< -DMSP432 -o $@
else
	$(CC) $(INCLUDES) $(CFLAGS) -E $< -DHOST -o $@
endif

%.asm : %.c
ifeq ($(PLATFORM), MSP432)
	$(CC) $(INCLUDES) $(CFLAGS) -S $< -DMSP432 -o $@
else
	$(CC) $(INCLUDES) $(CFLAGS) -S $< -DHOST -o $@
endif

%.d : %.c
ifeq ($(PLATFORM), MSP432)
	$(CC) $(INCLUDES) $< $(DEPFLAGS) -DMSP432 -o $@
else
	$(CC) $(INCLUDES) $< $(DEPFLAGS) -DHOST -o $@
endif

%.o : %.c
ifeq ($(PLATFORM), MSP432)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< $(CPU) $(ARCH) $(SPECS) -DMSP432 -o $@
else
	$(CC) -c $< $(INCLUDES) $(CFLAGS) -DHOST -o $@
endif

.PHONY : c1m2.out
$(TARGET) : 
ifeq ($(PLATFORM), MSP432)
	$(CC) $(INCLUDES) $(CFLAGS) $(SOURCES) $(CPU) $(ARCH) $(SPECS) $(LDFLAGS) $(LINKER_FILE) -DMSP432 -o $@
else
	$(CC) $(INCLUDES) $(CFLAGS) $(SOURCES) $(LDFLAGS) -DHOST -o $@
endif
	$(SIZE) $(TARGET)

.PHONY : compile-all 
$(SOURCES) :

.PHONY : dump
dump : 
	$(OBJDUMP) $(TARGET)

.PHONY : clean
clean : 
	rm -f *.o *.i *.s *.out *.asm *.map *.d
