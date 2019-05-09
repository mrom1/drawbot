#pragma once
#include "serial.h"

namespace drawbot {
class Protocol {
public:
    virtual float parseCommand(char command, float value) = 0;
    virtual void setSerialInterface(Serial* s) = 0;
    virtual void help() = 0;
};

}
