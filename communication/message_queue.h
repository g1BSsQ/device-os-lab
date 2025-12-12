#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <stdbool.h>
#include <stddef.h>

#define MESSAGE_QUEUE_SIZE 10
#define MESSAGE_MAX_LENGTH 256

typedef struct {
    char messages[MESSAGE_QUEUE_SIZE][MESSAGE_MAX_LENGTH];
    size_t head;
    size_t tail;
} MessageQueue;

void message_queue_init();
bool message_queue_push(const char* message);
bool message_queue_pop(char* buffer);

#endif // MESSAGE_QUEUE_H