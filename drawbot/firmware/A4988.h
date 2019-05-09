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
