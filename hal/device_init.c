#include "device_init.h"
#include "spi.h"
#include "adc.h"
#include <stdio.h>

void hal_device_init() {
    // Khởi tạo thiết bị phần cứng
    printf("HAL device initialization...\n");
    spi_init();
    spi_enable_dma();
    adc_init();
    adc_calibrate();
    // TODO: Thêm logic khởi tạo thực tế
}
