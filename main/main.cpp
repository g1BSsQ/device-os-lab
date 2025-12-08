


// main.cpp
// Thêm log khi khởi tạo hệ thống
#include "services/logger/logger.h"
#include "network.h"
#include "device_init.h"

int main() {
    logInfo("System initialization started.");

    // Khởi tạo thiết bị
    device_init();
    hal_device_init();

    // Kiểm tra kết nối mạng
    if (check_network_connectivity()) {
        logInfo("Network connectivity: OK");
    } else {
        logInfo("Network connectivity: FAILED");
    }

    // ...existing code...

    logInfo("System initialization completed.");
    return 0;
}
