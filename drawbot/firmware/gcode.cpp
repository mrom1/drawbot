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



#include "gcode.h"

float GCode::parseCommand(char command, float value)
{
    char *ptr = _serial->getBuffer();

    while((long)ptr > 1 && (*ptr) && (long)ptr < (long)_serial->getBuffer()+_serial->getCurrentBufferIndex())
    {
        if(*ptr == command)
            return atof(ptr+1);

        ptr=strchr(ptr, ' ') + 1;
    }

    return value; // default
}

void GCode::setSerialInterface(drawbot::Serial* s)
{
    _serial = s;
}

void GCode::help()
{
    if(_serial == nullptr)
        return;

    _serial->write("Commands:");
    _serial->write("G00 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move");
    _serial->write("G01 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move");
    _serial->write("G92 [X(steps)] [Y(steps)]; - change logical position");
    _serial->write("M18; - disable motors");
    _serial->write("M100; - this help message");
    _serial->write("M114; - report position and feedrate");
}
