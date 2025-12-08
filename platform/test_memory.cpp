#include "memory.h"
#include <assert.h>
#include <stdio.h>

void test_memory_leak() {
    void* a = platform_malloc(100);
    void* b = platform_malloc(200);
    platform_free(a);
    // intentionally not freeing b to simulate leak
    size_t leaks = platform_memory_leak_count();
    printf("Memory leak count: %zu\n", leaks);
    assert(leaks == 1);
    platform_memory_cleanup();
    assert(platform_memory_leak_count() == 0);
    printf("Memory leak test passed!\n");
}

int main() {
    test_memory_leak();
    return 0;
}
