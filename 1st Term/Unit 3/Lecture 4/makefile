#@copyright: Mahmood Gamal
SHELL := powershell.exe
CC=arm-none-eabi
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
project_name=lab4_cortexM4

all: $(project_name).bin
	@echo "=====Build is done.====="

#startup.o: startup.s
#	$(CC)-as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)-gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
$(project_name).elf:  $(OBJ) $(ASOBJ)
	$(CC)-ld.exe -T linker_script.ld -Map="map_file.map" $(LIBS) $(OBJ) $(ASOBJ) -o $@
	cp $(project_name).elf $(project_name).axf

$(project_name).bin: $(project_name).elf
	$(CC)-objcopy.exe -O binary $< $@

clean_all:
	rm *.o, *.elf, *.bin
clean:
	del *.elf, *.bin