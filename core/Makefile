.SUFFIXES:

ifeq ($(strip $(DEVKITARM)),)
$(error Please set DEVKITARM in your environment: export DEVKITARM=<path to>/devkitARM)
endif

include $(DEVKITARM)/ds_rules

TARGET := steel
BUILD := build

# update these if ur making a fork
GAME_TITLE := Steel
GAME_SUBTITLE1 := by NicholasC
GAME_SUBTITLE2 :=

ARCH := -march=armv5te -mtune=arm946e-s -mthumb

CFLAGS := -g -Wall -O2 -ffunction-sections -fdata-sections $(ARCH) -DARM9
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
CPPFLAGS := -I$(LIBNDS)/include

ASFLAGS := -g $(ARCH)

LDFLAGS := -specs=ds_arm9.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map)

LIBS := -lnds9
LIBDIRS := $(LIBNDS)

ifneq ($(BUILD),$(notdir $(CURDIR)))

export OUTPUT := $(CURDIR)/$(TARGET)
export DEPSDIR := $(CURDIR)/$(BUILD)
export LD := $(CXX)

CPPFILES := $(notdir $(wildcard src/*.cpp))

export VPATH := $(CURDIR)/src
export OFILES := $(CPPFILES:.cpp=.o)

export LIBPATHS := $(foreach dir,$(LIBDIRS),-L$(dir)/lib)

.PHONY: $(BUILD) clean

$(BUILD):
	@mkdir -p $@
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

clean:
	@rm -rf $(BUILD) $(TARGET).elf $(TARGET).nds $(TARGET).ds.gba

else

DEPENDS := $(OFILES:.o=.d)

$(OUTPUT).nds: $(OUTPUT).elf

$(OUTPUT).elf: $(OFILES)

-include $(DEPENDS)

endif
