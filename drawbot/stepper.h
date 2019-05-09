#pragma once

namespace drawbot {

class Stepper {

public:
    virtual void step(int steps) = 0;
    virtual void setSpeed(unsigned long feedrate) = 0;
    virtual unsigned long getSpeed() = 0;
    virtual void pause() = 0;
    virtual void disable() = 0;
    virtual void enable() = 0;
};

}

