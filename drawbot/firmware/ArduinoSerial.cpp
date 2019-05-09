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
