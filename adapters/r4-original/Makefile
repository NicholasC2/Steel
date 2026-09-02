CORE := ../../core

CORE_NDS := $(CORE)/steel.nds

DLDI := r4tf_v2.dldi
OUTPUT := r4-original.nds

.PHONY: all clean

all: $(OUTPUT)

$(CORE_NDS):
	$(MAKE) -C $(CORE)

$(OUTPUT): $(CORE_NDS) $(DLDI)
	cp $(CORE_NDS) $@
	dlditool $(DLDI) $@

clean:
	rm -f $(OUTPUT)
