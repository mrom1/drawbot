#include "stepper_stub.h"

namespace drawbot {

void StepperStub::step(int steps)
{

}

void StepperStub::setSpeed(unsigned long feedrate)
{
    _feedrate = feedrate;
}

unsigned long StepperStub::getSpeed()
{
    return _feedrate;
}

void StepperStub::pause()
{
}

void StepperStub::disable()
{
}

void StepperStub::enable()
{
}

}
