#include <chrono>
#include <thread>
#include <iostream>

void hal_timer_delay_ms(unsigned int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    std::cout << "Delayed for " << milliseconds << " ms." << std::endl;
}

unsigned long hal_timer_get_tick() {
    using namespace std::chrono;
    static auto start_time = steady_clock::now();
    auto now = steady_clock::now();
    return duration_cast<milliseconds>(now - start_time).count();
}