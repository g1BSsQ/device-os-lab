# put deliverable products at the end
MAKE_DEPENDENCIES=communication hal platform services wiring bootloader main
docs

PROJECT_ROOT = .
COMMON_BUILD=build
BUILD_PATH_BASE=$(COMMON_BUILD)/target

# Include common.mk for shared flags
include $(COMMON_BUILD)/common.mk

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
SUBDIRS := communication communication-dynalib gsm0710muxer hal platform services wiring bootloader main

# Added third-party libraries to the build process
SUBDIRS += third_party/mbedtls third_party/nanopb third_party/lwip

.PHONY: all clean $(SUBDIRS)

# Parallel build for faster execution
all: $(SUBDIRS)
	@echo "Build completed for all modules."

$(SUBDIRS):
	$(MAKE) -C $@ -j$(nproc)

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	$(VERBOSE)$(RMDIR) $(BUILD_PATH_BASE)

# Documentation generation
docs:
	@echo "Generating documentation..."
	doxygen Doxyfile

# Cross-compilation support
CROSS_COMPILE ?= arm-none-eabi-
CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)g++
LD := $(CROSS_COMPILE)ld

include $(COMMON_BUILD)/common-tools.mk
include $(COMMON_BUILD)/recurse.mk
include $(COMMON_BUILD)/verbose.mk

# New build target
new_target:
	@echo "Building new target..."
	# Add commands to build the new target here

# Added dynamic library support for services
DYNALIB_DIR := services-dynalib

# Updated dynamic library build target
.PHONY: dynalib

dynalib:
	$(MAKE) -C $(DYNALIB_DIR) CFLAGS="-O2 -DTHREAD_SAFE"

all: dynalib
	@echo "Dynamic library for services built successfully."

# Add test_crypto.cpp to the test build process
TEST_SOURCES += test/test_crypto.cpp

# Add test_hal.cpp to the test build process
TEST_SOURCES += test/test_hal.cpp

# Add test_services.cpp to the test build process
TEST_SOURCES += test/test_services.cpp

# Include modularized makefiles
include common.mk
include subdirs.mk
include build.mk
include clean.mk

# Add clang-format target
.PHONY: clang-format
clang-format:
	@echo "Running clang-format..."
	clang-format -i $(shell find . -name '*.cpp' -o -name '*.h')
