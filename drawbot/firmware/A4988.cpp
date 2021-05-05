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



#include "A4988.h"

A4988::A4988(unsigned char step, unsigned char ms1, unsigned char ms2, unsigned char ms3) : _step(step), _ms1(ms1), _ms2(ms2), _ms3(ms3), _enabled(true)
{
    pinMode(_step, OUTPUT);
    pinMode(_ms1, OUTPUT);
    pinMode(_ms2, OUTPUT);
    pinMode(_ms3, OUTPUT);
}

A4988::A4988(unsigned char enable, unsigned char dir, unsigned char step, unsigned char ms1, unsigned char ms2, unsigned char ms3) : _enable(enable), _dir(dir), _step(step), _ms1(ms1), _ms2(ms2), _ms3(ms3), _enabled(true)
{
    pinMode(_enable, OUTPUT);
    pinMode(_dir, OUTPUT);
    pinMode(_step, OUTPUT);
    pinMode(_ms1, OUTPUT);
    pinMode(_ms2, OUTPUT);
    pinMode(_ms3, OUTPUT);
}

void A4988::step(int steps)
{
    for (int i=0; i < steps; i++)
    {
        digitalWrite(_step, HIGH);
        delayMicroseconds(_delay);
        digitalWrite(_step, LOW);
        delayMicroseconds(_delay);
    }
}

void A4988::setSpeed(unsigned long feedrate)
{
    if(_feedrate==feedrate) return;
    if(feedrate>MAX_FEEDRATE || feedrate<MIN_FEEDRATE) return;
    _delay = 1000000.0/feedrate;
    _feedrate = feedrate;
}

unsigned long A4988::getSpeed()
{
    return _feedrate;
}

void A4988::pause()
{
    delay(_delay/1000);
    delayMicroseconds(_delay%1000); // delayMicroseconds doesn't work for values > ~16k.
}

void A4988::disable()
{
    if (!_enabled) return;
    _enabled = false;
    update();
}

void A4988::enable()
{
    if (_enabled) return;
    _enabled = true;
    update();
}

void A4988::update()
{
    digitalWrite(_enable, !_enabled);
    digitalWrite(_ms1, (1 << 0));
    digitalWrite(_ms2, (1 << 1));
    digitalWrite(_ms3, (1 << 2));
}
