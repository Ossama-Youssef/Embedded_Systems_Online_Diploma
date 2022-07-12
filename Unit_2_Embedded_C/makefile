#****************************************************#
#@copyrights: Osama Youssef
#@file : makefile 
#@breif : makefile to automate embedded systems projects 
#****************************************************#
#$@ : target
#$< : dependencies
#****************************************************#
#project name 
project_name=learn_in_depth_cortex_m3_s_startup
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
#including all .s files 	
AS=$(wildcard *.s)
#getting .o file from .s file 
ASOBJ=$(AS:.s=.o)
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
	
startup.o: $(startup).s
	$(CC)as.exe $(CFLAGS) $< -o $@


%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@

$(project_name).elf: $(OBJ) $(ASOBJ) 
	$(CC)ld.exe -T $(linker_script).ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=$(map_name).map

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
