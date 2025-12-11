#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <string>

class Protocol {
public:
    void initialize();
    void send(const std::string& message);
    std::string receive();
};

#endif // PROTOCOL_H