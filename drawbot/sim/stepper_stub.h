#pragma once

#include "../stepper.h"

namespace drawbot {

class StepperStub : Stepper
{
public:
    void step(int steps) override;
    void setSpeed(unsigned long feedrate) override;
    unsigned long getSpeed() override;
    void pause() override;
    void disable() override;
    void enable() override;

private:
    unsigned long _feedrate;
};

}
