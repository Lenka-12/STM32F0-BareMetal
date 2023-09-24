CC = arm-none-eabi-gcc
MACH = cortex-m0

CFLAGS = -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb  -mfloat-abi=soft --specs=nano.specs -T $(LS) -Wl,-Map=final.map
#LDFLAGS_SH= -mcpu=$(MACH) -mthumb  -mfloat-abi=soft --specs=rdimon.specs -T stm32_ls.ld -Wl,-Map=final.map
INCLUDES = $(addprefix -I, $(include_dirs))  # Add -I before each include directory
OBJOPTIONS = arm-none-eabi-objcopy -O binary -S
OBJHEX = arm-none-eabi-objcopy -O ihex 
include_dirs = . Inc
vpath %.c src/ Inc/
vpath %.h src/ Inc/


SRCS = $(shell ls src/*.c)
LS   = $(shell ls src/*.ld) 
OBJS = $(notdir $(SRCS:.c=.o))
DEPS = $(notdir SRCS:.c=.d)
TARGET = final.elf
BINARY = final.bin
HEX    = final.hex

-include $(DEPS)
.PHONY: all
all: $(BINARY)
$(BINARY): $(TARGET)
	$(OBJOPTIONS) $^ $@
hex: $(HEX)
$(HEX): $(TARGET)
	$(OBJHEX) $^ $@	
	
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS)  $(OBJS) -o $(TARGET)  

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^
.PHONY: clean
clean:
	rm  -rf *.o *.elf

flash:  all
	openocd -f interface/stlink.cfg  -f target/stm32f0x.cfg -c "program $(TARGET) verify reset exit"
load:
	openocd -f interface/stlink.cfg  -f target/stm32f0x.cfg 
