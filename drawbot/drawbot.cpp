#include "drawbot.h"

namespace drawbot {

void Drawbot::setSerial(Serial *s)
{
    if(gcode != nullptr)
        gcode->setSerialInterface(s);
}

void Drawbot::setProtocol(Protocol *p)
{
    gcode = p;
}

void Drawbot::setStepperXAxis(Stepper *xStepper)
{
    this->xStepper = xStepper;
}

void Drawbot::setStepperYAxis(Stepper *yStepper)
{
    this->yStepper = yStepper;
}

void Drawbot::setPosition(float x, float y)
{
    // todo: limit switch
    px = x;
    py = y;
}

void Drawbot::processCommands()
{
    if(gcode == nullptr)
        return;

    int cmd = gcode->parseCommand('G',-1);
    switch(cmd)
    {
        case  0:
        case  1:
        { // line
            xStepper->setSpeed(gcode->parseCommand('F', xStepper->getSpeed()));
            yStepper->setSpeed(gcode->parseCommand('F', yStepper->getSpeed()));
            drawLine(gcode->parseCommand('X',px), gcode->parseCommand('Y', py));
            break;
        }
        case 92:
        {
            setPosition( gcode->parseCommand('X',0), gcode->parseCommand('Y',0) );
        }
        break;
        default:  break;
    }

    cmd = gcode->parseCommand('M',-1);
    switch(cmd) {
    case 18:  // disable motors
      xStepper->disable();
      yStepper->disable();
      break;
    case 100:  gcode->help();  break;
    default:  break;
  }
}

void Drawbot::drawLine(float x, float y)
{
    long dx=x-px; // distance to move (delta)
    long dy=y-py;
    int dirx=dx > 0?1:-1; // direction to move
    int diry=dy > 0?1:-1;
    dx=absolute(dx); // absolute delta
    dy=absolute(dy);

    long over=0;

    if(dx > dy)
    {
        over = dx/2;
        for(long i=0; i < dx;++i)
        {
            xStepper->step(dirx);
            over+=dy;
            if(over>=dx)
            {
                over-=dx;
                yStepper->step(diry);
            }
            xStepper->pause();
        }
        // switch limit
    }
    else
    {
        over = dy/2;
        for(long i=0;i < dy; ++i)
        {
            yStepper->step(diry);
            over+=dx;
            if(over>=dy)
            {
                over-=dy;
                xStepper->step(dirx);
            }
            yStepper->pause();
        }
        // switch limit
    }

    px = x;
    py = y;
}

void Drawbot::printHelp() {
    if(gcode != nullptr)
        gcode->help();
}

}


