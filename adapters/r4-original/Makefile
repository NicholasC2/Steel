# Makefile for r4-original adapter

.PHONY: all clean

#----------------------------------------
# Paths
#----------------------------------------
CORE_DIR       := ../../core
BUILD_DIR      := build
OUTPUT         := _DS_MENU

TOOLS_DIR      := $(DEVKITPRO)/tools/bin
NDSTOOL        := $(TOOLS_DIR)/ndstool.exe
R4DENC         := $(TOOLS_DIR)/r4denc.exe
DLDITOOL       := $(TOOLS_DIR)/dlditool.exe

THEME_PATH     := ../../themes
THEMES         := nebula-blue

STEEL_FOLDER		:= .steel
STEEL_THEME_FOLDER	:= themes

#----------------------------------------
# Default target
#----------------------------------------
all: $(BUILD_DIR) $(BUILD_DIR)/$(OUTPUT)

#----------------------------------------
# Build core
#----------------------------------------
$(CORE_DIR)/steel_core.nds:
	$(MAKE) -C $(CORE_DIR) --no-print-directory

#----------------------------------------
# Build adapter with themes
#----------------------------------------
$(BUILD_DIR)/$(OUTPUT): $(CORE_DIR)/steel_core.nds
	cp $< $@.nds
	$(DLDITOOL) ./r4tf_v2.dldi $<
	$(R4DENC) $@.nds
	rm -f $@.nds

	$(foreach THEME,$(THEMES), \
		cp $(THEME_PATH)/$(THEME)/$(THEME).theme $(BUILD_DIR)/$(STEEL_FOLDER)/$(STEEL_THEME_FOLDER); \
	)

	@echo "Build successful!"

#----------------------------------------
# Prepare build folders
#----------------------------------------
$(BUILD_DIR):
	mkdir -p $@/$(STEEL_FOLDER)/$(STEEL_THEME_FOLDER)

#----------------------------------------
# Clean
#----------------------------------------
clean:
	@echo "Cleaning adapter..."
	rm -rf $(BUILD_DIR)
	$(MAKE) clean -C $(CORE_DIR) --no-print-directory
