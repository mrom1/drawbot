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
#include "stepper.h"
#include "serial.h"
#include "protocol.h"

namespace drawbot {

class Drawbot {

public:
    Drawbot() = default;
    void setSerial(Serial* s);
    void setProtocol(Protocol* p);
    void setStepperXAxis(Stepper* xStepper);
    void setStepperYAxis(Stepper* yStepper);

    void drawLine(float x, float y);

    void processCommands();
    void printHelp();

private:
    template <typename T> inline // unsafe, does not work for all cases see LWG issue 2192 for reference
    T absolute(const T& v) { return v < 0 ? -v : v; }
    void setPosition(float x, float y);

private:
    Stepper* xStepper, *yStepper;
    Protocol* gcode;

private:
    float px,py,pz;
};

}
