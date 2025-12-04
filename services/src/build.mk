TARGET_SPARK_SERVICES_SRC_PATH = $(SERVICES_MODULE_PATH)/src
NANOPB_SRC_PATH = $(SERVICES_MODULE_PATH)/nanopb

CPPSRC += $(call target_files,$(TARGET_SPARK_SERVICES_SRC_PATH),*.cpp)
CPPSRC += $(TARGET_SPARK_SERVICES_SRC_PATH)/user_auth.cpp
CSRC += $(call target_files,$(TARGET_SPARK_SERVICES_SRC_PATH),*.c)

# Updated logging module configuration
LOG_MODULE_CATEGORY = logging_service

# Ensure new logging files are included
CSRC += $(TARGET_SPARK_SERVICES_SRC_PATH)/logging.c
