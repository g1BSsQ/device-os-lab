/**
 * @file rtos_test.cpp
 * @brief Unit tests for RTOS threading functions.
 *
 * This file contains unit tests for the RTOS threading functions.
 */

#include "rtos.h"
#include <gtest/gtest.h>

void sample_thread_function() {
    // Example thread function
}

TEST(RTOSTest, CreateThread) {
    ASSERT_NO_THROW(rtos_create_thread(sample_thread_function));
}

TEST(RTOSTest, MutexLockUnlock) {
    ASSERT_NO_THROW(rtos_lock());
    ASSERT_NO_THROW(rtos_unlock());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
