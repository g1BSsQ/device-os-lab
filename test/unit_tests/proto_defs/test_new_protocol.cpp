#include "new_protocol.pb.h"
#include "unit_test.h"

// Test case for encoding a NewProtocolMessage
test(NewProtocol_Encode) {
    NewProtocolMessage message = NewProtocolMessage_init_default;
    strcpy(message.id, "test_id");
    message.version = 1;
    message.is_encrypted = true;

    uint8_t buffer[256];
    pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
    bool status = pb_encode(&stream, NewProtocolMessage_fields, &message);

    assertTrue(status);
    assertGreater(stream.bytes_written, 0);
}

// Test case for decoding a NewProtocolMessage
test(NewProtocol_Decode) {
    uint8_t buffer[256] = { /* Encoded data */ };
    pb_istream_t stream = pb_istream_from_buffer(buffer, sizeof(buffer));

    NewProtocolMessage message = NewProtocolMessage_init_default;
    bool status = pb_decode(&stream, NewProtocolMessage_fields, &message);

    assertTrue(status);
    assertEqual(strcmp(message.id, "test_id"), 0);
    assertEqual(message.version, 1);
    assertTrue(message.is_encrypted);
}