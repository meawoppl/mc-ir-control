#include "mc-ir-control/shared.h"

using namespace McIrControl;

Nikon::Nikon(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _freq = 40;
}

void Nikon::shutterNow()
{
  high(2000,_freq,_pin);
  wait(27830);
  high(390,_freq,_pin);
  wait(1580);
  high(410,_freq,_pin);
  wait(3580);
  high(400,_freq,_pin);
}
