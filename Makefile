ADAPTERS := $(wildcard adapters/*)

.PHONY: all clean $(ADAPTERS)

all: $(ADAPTERS)

$(ADAPTERS):
	$(MAKE) -C $@

clean:
	$(MAKE) -C core clean
	@for adapter in $(ADAPTERS); do \
		$(MAKE) -C $$adapter clean; \
	done
