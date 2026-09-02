.SUFFIXES:

TARGET := steel
BUILD := build

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src/%.c,$(BUILD)/%.o,$(SOURCES))

CC := $(DEVKITARM)/bin/arm-none-eabi-gcc

CFLAGS := \
	-g \
	-Wall \
	-Wextra \
	-O2 \
	-ffunction-sections \
	-fdata-sections \
	-D__NDS__ \
	-DARM9 \
	-I$(DEVKITPRO)/libnds/include \
	-I$(DEVKITPRO)/calico/include

GAME_TITLE := Steel
GAME_SUBTITLE1 := Steel
GAME_SUBTITLE2 :=

LIBS := -lnds9

include $(DEVKITARM)/ds_rules

.PHONY: all clean

all: $(TARGET).nds

$(TARGET).nds: $(TARGET).elf

$(TARGET).elf: $(OBJECTS)

$(BUILD)/%.o: src/%.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJECTS:.o=.d)

clean:
	rm -rf $(BUILD)
	rm -f $(TARGET).elf
	rm -f $(TARGET).nds
	rm -f $(TARGET).map
	rm -f $(TARGET).lst
