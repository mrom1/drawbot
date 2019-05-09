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
