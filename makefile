# put deliverable products at the end
MAKE_DEPENDENCIES=communication hal platform services wiring bootloader main
docs

PROJECT_ROOT = .
COMMON_BUILD=build
BUILD_PATH_BASE=$(COMMON_BUILD)/target

ifdef SPARK_PRODUCT_ID
PRODUCT_ID=$(SPARK_PRODUCT_ID)
endif

include $(COMMON_BUILD)/platform-id.mk

ifdef PRODUCT_ID
msg_ext =, product ID: $(PRODUCT_ID)
endif

msg = Building firmware for $(PRODUCT_DESC), platform ID: $(PLATFORM_ID)$(msg_ext)

$(info $(msg))

# Modularized makefile structure
SUBDIRS := communication hal platform services wiring bootloader main

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)
	@echo "Build completed for all modules."

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	$(VERBOSE)$(RMDIR) $(BUILD_PATH_BASE)

# Documentation generation
docs:
	@echo "Generating documentation..."
	doxygen Doxyfile

include $(COMMON_BUILD)/common-tools.mk
include $(COMMON_BUILD)/recurse.mk
include $(COMMON_BUILD)/verbose.mk

# New build target
new_target:
	@echo "Building new target..."
	# Add commands to build the new target here

# Added dynamic library support for services
DYNALIB_DIR := services-dynalib

.PHONY: dynalib

dynalib:
	$(MAKE) -C $(DYNALIB_DIR)

all: dynalib
	@echo "Dynamic library for services built successfully."

.PHONY: all docs new_target
