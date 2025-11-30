SRC_DIR := source
OUT := $(notdir $(CURDIR)).theme

.PHONY: all clean $(OUT)

all: $(OUT)

$(OUT):
	@echo "Building $(OUT)..."
	@cd $(SRC_DIR) && zip -r ../$(OUT) ./

clean:
	@echo "Cleaning $(OUT)..."
	@rm -f $(OUT)
