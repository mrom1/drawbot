#pragma once

#include "../protocol.h"

namespace drawbot {

class ProtocolStub : Protocol
{
    float parseCommand(char command, float value) override;
    void setSerialInterface(Serial* s) override;
    void help() override;

private:
    Serial* _serial;

};
}
