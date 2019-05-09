#pragma once

namespace drawbot {

class Serial {

public:
    virtual void begin(unsigned long baudrate) = 0;
    virtual void end() = 0;

    virtual int available() = 0;
    virtual void update() = 0;

    virtual int read() = 0;
    virtual unsigned int write(const char* s) = 0;
    virtual unsigned int write(const unsigned char* array, long len) = 0;

    virtual char* getBuffer() = 0;
    virtual int getCurrentBufferIndex() = 0;
};

}
