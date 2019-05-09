#pragma once

#include "../serial.h"

namespace drawbot {

class SerialStub : Serial
{
    void begin(unsigned long baudrate) override;
    void end() override;

    int available() override;
    void update() override;

    int read() override;
    unsigned int write(const char* s) override;
    unsigned int write(const unsigned char* array, long len) override;

    char* getBuffer() override;
    int getCurrentBufferIndex() override;
};

}
