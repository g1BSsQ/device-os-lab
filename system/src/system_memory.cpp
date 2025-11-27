/*
 * Copyright (c) 2025 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "system_memory.h"
#include "logging.h"
#include <atomic>
#include <thread>
#include <chrono>

namespace particle {
namespace system {

static std::atomic<bool> monitoring_enabled{false};

void start_memory_monitoring(unsigned interval_ms) {
    monitoring_enabled = true;
    std::thread([](unsigned interval) {
        while (monitoring_enabled) {
            size_t free_memory = System.freeMemory();
            LOG(INFO, "Free memory: %zu bytes", free_memory);
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }, interval_ms).detach();
}

void stop_memory_monitoring() {
    monitoring_enabled = false;
}

} // namespace system
} // namespace particle