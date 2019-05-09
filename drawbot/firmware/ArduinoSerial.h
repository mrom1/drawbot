#pragma once

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "../serial.h"
#include "config.h"

class ArduinoSerial : public drawbot::Serial {
public:
    ArduinoSerial(HardwareSerial& serial);

    void begin(unsigned long baudrate) override;
    void end() override;

    int available() override;
    void update() override;

    int read() override;
    unsigned int write(const char* s) override;
    unsigned int write(const unsigned char* array, long len) override;

    char* getBuffer() override;
    int getCurrentBufferIndex() override;

    void clearBuffer();

private:
    HardwareSerial& _serial;
    char _bufferSerial[MAX_SERIAL_BUF];
    int _bufferCounter;
};
