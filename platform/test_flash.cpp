#include "flash.h"
#include <iostream>

int main() {
    uint8_t write_data[4] = {0xAA, 0xBB, 0xCC, 0xDD};
    uint8_t read_data[4] = {0};
    if (flash_write(100, write_data, 4) == 0) {
        std::cout << "Write success" << std::endl;
    } else {
        std::cout << "Write failed" << std::endl;
    }
    if (flash_read(100, read_data, 4) == 0) {
        std::cout << "Read success: ";
        for (int i = 0; i < 4; ++i) std::cout << std::hex << (int)read_data[i] << " ";
        std::cout << std::endl;
    } else {
        std::cout << "Read failed" << std::endl;
    }
    return 0;
}
