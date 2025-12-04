/**
 * @file rtos.cpp
 * @brief Implementation of RTOS threading functions.
 *
 * This file contains the implementation of threading functions for the RTOS layer.
 */

#include "rtos.h"
#include <mutex>
#include <thread>

std::mutex rtos_mutex;

/**
 * @brief Example function to create a thread.
 *
 * @param func The function to run in the thread.
 */
void rtos_create_thread(void (*func)()) {
    std::thread new_thread(func);
    new_thread.detach();
}

/**
 * @brief Example function to lock a mutex.
 */
void rtos_lock() {
    rtos_mutex.lock();
}

/**
 * @brief Example function to unlock a mutex.
 */
void rtos_unlock() {
    rtos_mutex.unlock();
}
