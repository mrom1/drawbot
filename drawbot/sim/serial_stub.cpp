#include <iostream>
#include "serial_stub.h"


namespace drawbot {

void SerialStub::begin(unsigned long baudrate)
{

}

void SerialStub::end()
{

}

int SerialStub::available()
{
    return 1;
}

int SerialStub::read()
{
    return 1;
}

unsigned int SerialStub::write(const char *s)
{
    std::cout << s;
    return 0;
}

unsigned int SerialStub::write(const unsigned char* array, long len)
{
    for(long i = 0; i < len; i++)
    {
        std::cout << *(array+i);
    }
    return 0;
}

char* SerialStub::getBuffer()
{
    return nullptr;
}

int SerialStub::getCurrentBufferIndex()
{
    return 0;
}

void SerialStub::update()
{
}


}
