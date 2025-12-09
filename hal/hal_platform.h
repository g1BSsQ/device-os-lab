#ifndef HAL_PLATFORM_H
#define HAL_PLATFORM_H

#include <stdint.h>

// Standardized HAL error codes
typedef enum {
    HAL_SUCCESS = 0,
    HAL_ERROR_GENERIC = -1,
    HAL_ERROR_TIMEOUT = -2,
    HAL_ERROR_INVALID_PARAM = -3,
    HAL_ERROR_BUSY = -4
} HAL_Status;

#endif // HAL_PLATFORM_H

// ...existing code...