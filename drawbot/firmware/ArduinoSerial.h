/************************************************************************
 * This file is part of the minilockcpp distribution
 * (https://github.com/mrom1/minilockcpp).
 * Copyright (c) 2021 mrom1.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************/



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
