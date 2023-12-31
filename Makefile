CC = arm-none-eabi-gcc
MACH = cortex-m0

CFLAGS = -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS = -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T $(LS) -Wl,-Map=final.map
INCLUDES = $(addprefix -I, $(include_dirs))
OBJOPTIONS = arm-none-eabi-objcopy -O binary
include_dirs = include
VPATH = $(SRCDIRS)
# Directories
SRCDIRS = example src
BUILDDIR = build
BINDIR  = binaries

# Source files from each source directory
SOURCES = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

# Object files
OBJS = $(patsubst %.c,$(BUILDDIR)/%.o,$(notdir $(SOURCES)))

# Linker Script
LS = $(wildcard $(BUILDDIR)/*.ld)

TARGET = $(BINDIR)/final.elf
BINARY = $(BINDIR)/final.bin

.PHONY: all clean flash load

all: $(BINDIR) $(BINARY)
$(BINDIR):
	mkdir -p $@
$(BINARY): $(TARGET)
	$(OBJOPTIONS) $< $@

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

# No directory creation here
$(BUILDDIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	rm -rf $(BINARY) $(TARGET) $(OBJS)

flash: all
	openocd -f interface/stlink-v2.cfg -f target/stm32f4x.cfg -c "program $(TARGET) verify reset exit"

load:
	openocd -f interface/stlink.cfg  -f target/stm32f0x.cfg 
