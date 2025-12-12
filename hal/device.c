#include <stdio.h>
#include "spi.h"
#include "adc.h"

void hal_device_setup() {
    printf("HAL device setup...\n");
    spi_init();
    spi_enable_dma();
    adc_init();
    adc_calibrate();
    // TODO: Thêm logic setup thiết bị
}
