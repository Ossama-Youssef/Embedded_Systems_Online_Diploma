#****************************************************#
#@copyrights: Osama Youssef
#@file : makefile 
#@breif : makefile to automate embedded systems projects 
#****************************************************#
#$@ : target
#$< : dependencies
#****************************************************#
#project name 
project_name=Pressure_Controller_Project
#startup name 
startup=startup
#linker script name 
linker_script=linker_script
#map file name 
map_name=map_file
#****************************************************#
#toolchain
CC=arm-none-eabi-
#microprocessor
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
#includes
INCS=-I .
#libaries
LIBS=
#****************************************************#
#including all .c files 
SRC=$(wildcard *.c)
#getting .o file from .c file 
OBJ=$(SRC:.c=.o)

#****************************************************#
#Qemu simulation tool 
#path 
path=../qemu/qemu-system-arm
#board name 
board=versatilepb
#graphics
graphic=-nographic
#memory
memory=128M
#kernel
kernel=-kernel
#*****************************************************#

all: $(project_name).bin
	@echo "====+++++==== Mission Completed ====+++++====="  
	
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@

$(project_name).elf: $(OBJ) 
	$(CC)ld.exe -T $(linker_script).ld $(LIBS) $(OBJ)  -o $@ -Map=$(map_name).map

$(project_name).bin: $(project_name).elf 
	$(CC)objcopy.exe -O binary $< $@

Run_Qemu: $(project_name).bin
	$(path) -M $(board) -m $(memory) $(graphic) $(kernel) $(project_name).bin


clean:
	rm *.elf *.bin *.map	
	clear

clean_all:
	rm *.elf *.bin *.o *.map
	clear
