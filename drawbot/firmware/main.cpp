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



#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "../drawbot.h"
#include "config.h"
#include "gcode.h"
#include "ArduinoSerial.h"
#include "A4988.h"

static drawbot::Drawbot session;
static GCode protocol;
static ArduinoSerial serial(Serial);
static A4988 xStepper(PIN_X_STEPPER_ENABLED,
                      PIN_X_STEPPER_DIR,
                      PIN_X_STEPPER_STEP,
                      PIN_X_STEPPER_MS1,
                      PIN_X_STEPPER_MS2,
                      PIN_X_STEPPER_MS3);
static A4988 yStepper(PIN_Y_STEPPER_ENABLED,
                      PIN_Y_STEPPER_DIR,
                      PIN_Y_STEPPER_STEP,
                      PIN_Y_STEPPER_MS1,
                      PIN_Y_STEPPER_MS2,
                      PIN_Y_STEPPER_MS3);

void setup()
{
    serial.begin(BAUDRATE);
    session.setProtocol(&protocol);
    session.setSerial(&serial);
    session.setStepperXAxis(&xStepper);
    session.setStepperYAxis(&yStepper);
}

void loop()
{
    serial.update();
    session.processCommands();
    serial.clearBuffer();
}
