
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Đơn giản quản lý các con trỏ đã cấp phát
static void* allocations[1024];
static size_t alloc_count = 0;

void* platform_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr && alloc_count < 1024) {
        allocations[alloc_count++] = ptr;
    }
    return ptr;
}

void platform_free(void* ptr) {
    if (ptr) {
        free(ptr);
        for (size_t i = 0; i < alloc_count; ++i) {
            if (allocations[i] == ptr) {
                allocations[i] = allocations[--alloc_count];
                break;
            }
        }
    }
}

size_t platform_memory_leak_count() {
    return alloc_count;
}

void platform_memory_cleanup() {
    for (size_t i = 0; i < alloc_count; ++i) {
        free(allocations[i]);
    }
    alloc_count = 0;
}
