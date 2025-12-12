#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void adc_init();
void adc_calibrate();
uint16_t adc_read();

#endif // ADC_H