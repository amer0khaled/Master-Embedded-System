#@Copywrite: Amer Khaled

CC=arm-none-eabi-
CPU=cortex-m3
CFLAGS=-mthumb -gdwarf-2 -mcpu=
INCS=-I.
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
ASM=$(wildcard *.s)
OBJASM=$(ASM:.s=.o)
TARGET=Learn_In_Depth_CORTEX_M3


all: $(TARGET).bin
	@echo "==========Build is Done=========="

%.o: %.s
	$(CC)as $(CFLAGS)$(CPU) $< -o $@
	@echo "==========Assembling Process is Done=========="

%.o: %.c
	$(CC)gcc $(CFLAGS)$(CPU) $(INCS) -c $< -o $@
	@echo "==========Compilation and Assembling Processes are Done=========="

$(TARGET).elf: $(OBJ) $(OBJASM)
	$(CC)ld -T linker_script.ld -Map=$(TARGET).map $(LIBS) $(OBJ) $(OBJASM) -o $@
	@echo "==========Linking Process is Done=========="

$(TARGET).bin: $(TARGET).elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	@echo "==========Clean Every Thing=========="

clean:
	rm *.elf *.bin
	@echo "==========Clean binary and elf Images=========="
