CORE := ../../core

BUILD := build
CORE_NDS := $(CORE)/steel.nds

DLDI := r4tf_v2.dldi
OUTPUT := $(BUILD)/r4-original.nds

.PHONY: all clean

all: $(OUTPUT)

$(CORE_NDS):
	$(MAKE) -C $(CORE)

$(OUTPUT): $(CORE_NDS) $(DLDI)
	@mkdir -p $(BUILD)
	cp $(CORE_NDS) $@
	dlditool $(DLDI) $@

clean:
	@rm -rf $(BUILD)
	@rm -f $(OUTPUT)
