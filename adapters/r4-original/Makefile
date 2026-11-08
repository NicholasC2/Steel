STEEL_DIR := ../../steel
BUILD_DIR := build
STEEL_NDS := $(STEEL_DIR)/steel.nds
DLDI_FILE := adapters/r4-original/r4tf_v2.dldi
OUTPUT_NDS := $(BUILD_DIR)/r4-original.nds

.PHONY: all clean

all: $(OUTPUT_NDS)

$(STEEL_NDS):
	cd $(STEEL_DIR) && zig build

$(OUTPUT_NDS): $(STEEL_NDS)
	mkdir -p $(BUILD_DIR)
	cp $(STEEL_NDS) $@
	dlditool $(DLDI_FILE) $@

clean:
	cd $(STEEL_DIR) && zig build clean
	rm -rf $(BUILD_DIR)