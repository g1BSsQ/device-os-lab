MODULE = proto_defs
PROTO_DEFS_MODULE_PATH = .

# Target this makefile is building.
TARGET_TYPE = a

BUILD_PATH_EXT = $(PROTO_DEFS_BUILD_PATH_EXT)

DEPENDENCIES = third_party/nanopb
MAKE_DEPENDENCIES = third_party/nanopb

# Organized proto sources for better readability
PROTO_SOURCES = \
	src/control/extensions.pb.c \
	src/control/common.pb.c \
	src/control/config.pb.c \
	src/control/wifi.pb.c \
	src/control/wifi_new.pb.c \
	src/control/cellular.pb.c \
	src/control/network.pb.c \
	src/control/network_old.pb.c \
	src/control/storage.pb.c \
	src/control/cloud.pb.c \
	src/cloud/ledger.pb.c \
	src/cloud/cloud.pb.c \
	src/cloud/describe.pb.c \
	src/internal/network_config.pb.c \
	src/internal/ledger.pb.c

PROTO_HEADERS = $(PROTO_SOURCES:.c=.h)

include ../build/arm-tlm.mk
