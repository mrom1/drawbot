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
