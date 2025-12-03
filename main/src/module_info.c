#include <stdio.h>
#include <stdlib.h>

#include "module_info.inc"

// Example function with null pointer handling
void process_data(const char* data) {
    if (data == NULL) {
        fprintf(stderr, "Error: Null pointer received in process_data\n");
        return;
    }

    // Process the data
    printf("Processing data: %s\n", data);
}
