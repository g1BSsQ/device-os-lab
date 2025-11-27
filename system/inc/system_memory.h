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

#ifndef PARTICLE_SYSTEM_MEMORY_H
#define PARTICLE_SYSTEM_MEMORY_H

#include <cstddef>

namespace particle {
namespace system {

/**
 * @brief Starts memory monitoring at a specified interval.
 *
 * @param interval_ms Monitoring interval in milliseconds.
 */
void start_memory_monitoring(unsigned interval_ms);

/**
 * @brief Stops memory monitoring.
 */
void stop_memory_monitoring();

} // namespace system
} // namespace particle

#endif // PARTICLE_SYSTEM_MEMORY_H