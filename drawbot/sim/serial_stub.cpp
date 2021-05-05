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
