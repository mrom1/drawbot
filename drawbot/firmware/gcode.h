#pragma once

#include "../protocol.h"
#include "ArduinoSerial.h"

class GCode : public drawbot::Protocol {
public:
    float parseCommand(char command, float value) override;
    void setSerialInterface(drawbot::Serial* s) override;
    void help() override;

private:
    drawbot::Serial* _serial;
};
