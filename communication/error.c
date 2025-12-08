#include "error.h"
#include <stdio.h>

const char* comm_error_str(int code) {
    switch (code) {
        case COMM_OK: return "OK";
        case COMM_ERR_OVERFLOW: return "Buffer Overflow";
        case COMM_ERR_CRC: return "CRC Error";
        case COMM_ERR_TIMEOUT: return "Timeout";
        default: return "Unknown Error";
    }
}

void comm_report_error(int code) {
    printf("Communication Error: %s\n", comm_error_str(code));
}
