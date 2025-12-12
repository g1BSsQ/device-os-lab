#include "message_queue.h"
#include <stdio.h>
#include <string.h>

static MessageQueue message_queue;

void message_queue_init() {
    message_queue.head = 0;
    message_queue.tail = 0;
    memset(message_queue.messages, 0, sizeof(message_queue.messages));
    printf("Message queue initialized.\n");
}

bool message_queue_push(const char* message) {
    size_t next_head = (message_queue.head + 1) % MESSAGE_QUEUE_SIZE;
    if (next_head == message_queue.tail) {
        printf("Message queue is full. Cannot push message.\n");
        return false;
    }
    strncpy(message_queue.messages[message_queue.head], message, MESSAGE_MAX_LENGTH - 1);
    message_queue.messages[message_queue.head][MESSAGE_MAX_LENGTH - 1] = '\0';
    message_queue.head = next_head;
    printf("Message pushed: %s\n", message);
    return true;
}

bool message_queue_pop(char* buffer) {
    if (message_queue.head == message_queue.tail) {
        printf("Message queue is empty. Cannot pop message.\n");
        return false;
    }
    strncpy(buffer, message_queue.messages[message_queue.tail], MESSAGE_MAX_LENGTH);
    message_queue.tail = (message_queue.tail + 1) % MESSAGE_QUEUE_SIZE;
    printf("Message popped: %s\n", buffer);
    return true;
}