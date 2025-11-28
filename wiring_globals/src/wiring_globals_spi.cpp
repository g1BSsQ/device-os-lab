#include "spark_wiring_spi.h"
#include "core_hal.h"
#include "spark_macros.h"

#ifndef SPARK_WIRING_NO_SPI

namespace particle {
namespace globals {

::particle::SpiProxy<HAL_SPI_INTERFACE1> SPI;

#if Wiring_SPI1
::particle::SpiProxy<HAL_SPI_INTERFACE2> SPI1;
#endif // Wiring_SPI1

#if Wiring_SPI2
::particle::SpiProxy<HAL_SPI_INTERFACE3> SPI2;
#endif // Wiring_SPI2

// Optimize SPI communication by enabling DMA transfers
void configureSPIForDMA() {
    // Example: Configure SPI for higher throughput using DMA
    SPI.setDMAEnabled(true);
#if Wiring_SPI1
    SPI1.setDMAEnabled(true);
#endif
#if Wiring_SPI2
    SPI2.setDMAEnabled(true);
#endif
}

} } // particle::globals

#endif //SPARK_WIRING_NO_SPI
