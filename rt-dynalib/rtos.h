/**
 * @file rtos.h
 * @brief RTOS threading API definitions.
 *
 * This file contains the declarations of threading functions for the RTOS layer.
 */

#pragma once

/**
 * @brief Creates a new thread.
 *
 * @param func The function to run in the thread.
 */
void rtos_create_thread(void (*func)());

/**
 * @brief Locks a mutex.
 */
void rtos_lock();

/**
 * @brief Unlocks a mutex.
 */
void rtos_unlock();
