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

#include "../stepper.h"
#include "config.h"

class A4988 : public drawbot::Stepper
{
public:
    A4988(unsigned char step, unsigned char ms1, unsigned char ms2, unsigned char ms3);
    A4988(unsigned char enable, unsigned char dir, unsigned char step, unsigned char ms1, unsigned char ms2, unsigned char ms3);

    void step(int steps) override;
    void setSpeed(unsigned long feedrate) override;
    unsigned long getSpeed() override;
    void pause() override;
    void disable() override;
    void enable() override;

private:
    void update();

private:
    bool _enabled;
    // Pins
    unsigned char _enable;
    unsigned char _dir;
    unsigned char _step;
    unsigned char _ms1;
    unsigned char _ms2;
    unsigned char _ms3;

    // Speed
    unsigned long _delay;
    unsigned long _feedrate = (MAX_FEEDRATE-MIN_FEEDRATE)/2;
};
