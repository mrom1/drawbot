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



#include "ArduinoSerial.h"

ArduinoSerial::ArduinoSerial(HardwareSerial& serial) : _serial(serial)
{
}

void ArduinoSerial::begin(unsigned long baudrate)
{
    _serial.begin(baudrate);
}

void ArduinoSerial::end()
{
    _serial.end();
}

int ArduinoSerial::available()
{
    return _serial.available();
}

int ArduinoSerial::read()
{
    return _serial.read();
}

unsigned int ArduinoSerial::write(const char *s)
{
    return _serial.write(s);
}

unsigned int ArduinoSerial::write(const unsigned char* array, long len)
{
    return _serial.write(array, len);
}

char* ArduinoSerial::getBuffer()
{
    return _bufferSerial;
}

int ArduinoSerial::getCurrentBufferIndex()
{
    return _bufferCounter;
}

void ArduinoSerial::update()
{
    while(available() > 0)
    {
        char c = read();

        if(_bufferCounter < MAX_SERIAL_BUF - 1)
            _bufferSerial[_bufferCounter++]=c;

        if(c == '\n' || c == 'r')
        {
            _bufferSerial[_bufferCounter] = '\0';
            write("\r\n");
        }
    }
}

void ArduinoSerial::clearBuffer()
{   // overwriting the buffer is unneccessary
    _bufferCounter = 0;
}
