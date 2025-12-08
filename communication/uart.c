#include "uart.h"
#include "crc.h"
#include <stdio.h>

#include "error.h"

static uint8_t uart_buffer[UART_BUFFER_SIZE];
static size_t head = 0, tail = 0;

void uart_init() {
    head = tail = 0;
}

int uart_write(uint8_t data) {
    size_t next_head = (head + 1) % UART_BUFFER_SIZE;
    if (next_head == tail) {
        // Buffer đầy, không ghi thêm
        comm_report_error(COMM_ERR_OVERFLOW);
        return COMM_ERR_OVERFLOW;
    }
    uart_buffer[head] = data;
    head = next_head;
    return 0;
}

int uart_read(uint8_t* data) {
    if (head == tail) {
        // Buffer rỗng
        comm_report_error(COMM_ERR_TIMEOUT);
        return COMM_ERR_TIMEOUT;
    }
    *data = uart_buffer[tail];
    tail = (tail + 1) % UART_BUFFER_SIZE;
    return 0;
}

size_t uart_available() {
    if (head >= tail) return head - tail;
    return UART_BUFFER_SIZE - tail + head;
}

// Gửi một buffer dữ liệu kèm CRC
int uart_send_with_crc(const uint8_t* data, size_t length) {
    uint16_t crc = crc16(data, length);
    for (size_t i = 0; i < length; ++i) {
        if (uart_write(data[i]) != 0) {
            comm_report_error(COMM_ERR_OVERFLOW);
            return COMM_ERR_OVERFLOW;
        }
    }
    // Gửi CRC (2 byte)
    if (uart_write((uint8_t)(crc & 0xFF)) != 0) {
        comm_report_error(COMM_ERR_OVERFLOW);
        return COMM_ERR_OVERFLOW;
    }
    if (uart_write((uint8_t)((crc >> 8) & 0xFF)) != 0) {
        comm_report_error(COMM_ERR_OVERFLOW);
        return COMM_ERR_OVERFLOW;
    }
    return COMM_OK;
}

// Nhận một buffer dữ liệu và kiểm tra CRC
int uart_receive_with_crc(uint8_t* buffer, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        if (uart_read(&buffer[i]) != 0) {
            comm_report_error(COMM_ERR_TIMEOUT);
            return COMM_ERR_TIMEOUT;
        }
    }
    uint8_t crc_lo, crc_hi;
    if (uart_read(&crc_lo) != 0) {
        comm_report_error(COMM_ERR_TIMEOUT);
        return COMM_ERR_TIMEOUT;
    }
    if (uart_read(&crc_hi) != 0) {
        comm_report_error(COMM_ERR_TIMEOUT);
        return COMM_ERR_TIMEOUT;
    }
    uint16_t received_crc = crc_lo | (crc_hi << 8);
    uint16_t calc_crc = crc16(buffer, length);
    if (received_crc == calc_crc) {
        return COMM_OK;
    } else {
        comm_report_error(COMM_ERR_CRC);
        return COMM_ERR_CRC;
    }
}
