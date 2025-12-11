#include "hal_thread.h"
#include <thread>
#include <mutex>
#include <iostream>

static std::mutex hal_thread_mutex;

void hal_thread_create(void (*thread_func)(void), const char* name) {
    std::lock_guard<std::mutex> lock(hal_thread_mutex);
    try {
        std::thread new_thread(thread_func);
        new_thread.detach();
        std::cout << "Thread " << name << " created successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Failed to create thread: " << e.what() << std::endl;
    }
}
