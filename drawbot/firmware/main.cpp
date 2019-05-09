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
