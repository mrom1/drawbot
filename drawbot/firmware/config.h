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

#define BAUDRATE                (115200)
#define MAX_SERIAL_BUF          (64)
#define STEPS_PER_TURN          (200)
#define STEPS_PER_MM            (STEPS_PER_TURN*16/0.8)
#define MAX_FEEDRATE            (1000000)
#define MIN_FEEDRATE            (1)

#define PIN_X_STEPPER_ENABLED   (2)
#define PIN_X_STEPPER_DIR       (7)
#define PIN_X_STEPPER_STEP      (6)
#define PIN_X_STEPPER_MS1       (3)
#define PIN_X_STEPPER_MS2       (4)
#define PIN_X_STEPPER_MS3       (5)

#define PIN_Y_STEPPER_ENABLED   (11)
#define PIN_Y_STEPPER_DIR       (16)
#define PIN_Y_STEPPER_STEP      (15)
#define PIN_Y_STEPPER_MS1       (12)
#define PIN_Y_STEPPER_MS2       (13)
#define PIN_Y_STEPPER_MS3       (14)
