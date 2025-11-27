// Include the memory monitoring header
#include "system_memory.h"

// Example usage of memory monitoring
void setup() {
    particle::system::start_memory_monitoring(1000); // Start monitoring every 1 second
}

void loop() {
    // Application logic here
    // Stop monitoring if needed
    // particle::system::stop_memory_monitoring();
}