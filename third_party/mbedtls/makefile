MODULE=mbedtls
MBEDTLS_MODULE_PATH=.

# Target this makefile is building.
TARGET_TYPE = a

BUILD_PATH_EXT=$(MBEDTLS_BUILD_PATH_EXT)

# Ensure compatibility with updated dependencies
DEPENDENCIES = crypto platform hal freertos

PROJECT_ROOT ?= ../..
include ../../build/arm-tlm.mk
