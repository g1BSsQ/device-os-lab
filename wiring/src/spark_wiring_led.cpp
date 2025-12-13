/*
 * Copyright (c) 2016 Particle Industries, Inc.  All rights reserved.
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

#include "spark_wiring_led.h"
#include "spark_wiring_logging.h"

// particle::LEDStatus
particle::LEDStatus::LEDStatus(uint32_t color, LEDPattern pattern, uint16_t period, LEDPriority priority, LEDSource source) {
    d_.size = sizeof(LEDStatusData);
    d_.next = nullptr;
    d_.prev = nullptr;
    d_.priority = LED_PRIORITY_VALUE(priority, source); // Combine source and priority into single value
    d_.pattern = pattern;
    d_.flags = 0;
    d_.color = color;
    if (d_.pattern == LED_PATTERN_CUSTOM) {
        d_.callback = updateCallback; // User callback
        d_.data = this; // Callback data
    } else {
        // Cap period to reasonable range
        if (period == 0) {
            period = 1;
        } else if (period > 60000) {
            period = 60000;
        }
        d_.period = period;
    }
}

void particle::LEDStatus::updateCallback(system_tick_t ticks, void* data) {
    LEDStatus* s = static_cast<LEDStatus*>(data);
    s->update(ticks);
}

// particle::LEDSystemTheme
void particle::LEDSystemTheme::setSignal(LEDSignal signal, uint32_t color, LEDPattern pattern, uint16_t period) {
    setColor(signal, color);
    setPattern(signal, pattern);
    setPeriod(signal, period);
}

// Function to implement custom LED blink patterns
void setCustomLEDBlinkPattern(const char* pattern) {
    if (!pattern || pattern[0] == '\0')
    {
        Log.error("Invalid LED pattern: null or empty");
        return;
    }
    // Limit pattern length to prevent excessive processing
    size_t len = strlen(pattern);
    if (len > 1024) {
        Log.error("Invalid LED pattern: too long (%u chars, max 1024)",
                  (unsigned)len);
        return;
    }

    // Validate pattern contains only '0' and '1'
    for (const char* p = pattern; *p != '\0'; ++p)
    {
        if (*p != '0' && *p != '1')
        {
            Log.error("Invalid LED pattern: contains invalid character '%c'", *p);
            return;
        }
    }

    Log.info("Applying custom LED blink pattern: %s", pattern);

    // Example: Parse the pattern and apply it
    // This is a placeholder implementation
    for (const char* p = pattern; *p != '\0'; ++p) {
        if (*p == '1') {
            // Turn LED on
            Log.info("LED ON");
        } else if (*p == '0') {
            // Turn LED off
            Log.info("LED OFF");
        }
        // Add delay or timing logic here
    }
}
