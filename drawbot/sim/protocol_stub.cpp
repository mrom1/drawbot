#include "protocol_stub.h"

namespace drawbot {

float ProtocolStub::parseCommand(char command, float value)
{
    return value; // default
}

void ProtocolStub::setSerialInterface(drawbot::Serial* s)
{
    _serial = s;
}

void ProtocolStub::help()
{
}

}
