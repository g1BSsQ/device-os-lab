#include "sync.h"
#include <mutex>

std::mutex sync_mutex;

void sync_lock() {
    sync_mutex.lock();
}

void sync_unlock() {
    sync_mutex.unlock();
}
