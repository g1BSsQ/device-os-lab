#include "gsm0710muxer.h"
#include "muxer.h"
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <assert.h>

void test_muxer_performance() {
    auto start = std::chrono::high_resolution_clock::now();
    // TODO: Thực hiện các thao tác xử lý muxer cần tối ưu
    for (int i = 0; i < 100000; ++i) {
        // Giả lập xử lý gói tin
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Muxer processing time: " << duration << " ms" << std::endl;
}

void test_muxer_state_machine() {
    muxer_init();
    assert(muxer_get_state() == MUXER_STATE_IDLE);

    muxer_set_state(MUXER_STATE_START);
    assert(muxer_get_state() == MUXER_STATE_START);

    muxer_set_state(MUXER_STATE_PROCESSING);
    assert(muxer_get_state() == MUXER_STATE_PROCESSING);

    muxer_set_state(MUXER_STATE_ERROR);
    assert(muxer_get_state() == MUXER_STATE_ERROR);

    printf("All state machine tests passed.\n");
}

int main() {
    test_muxer_performance();
    test_muxer_state_machine();
    return 0;
}
