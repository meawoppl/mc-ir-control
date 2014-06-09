#include "mc-ir-control/shared.h"

using namespace McIrControl;

Pentax::Pentax(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _freq = 38;
}

void Pentax::shutterNow()
{
  high(13000,_freq,_pin);
  wait(3000);
  for (int i=0;i<7;i++){
    high(1000,_freq,_pin);
    wait(1000);
  };
}

void Pentax::toggleFocus()
{
  high(13000,_freq,_pin);
  wait(3000);
  for (int i=0;i<5;i++){
    high(1000,_freq,_pin);
    wait(1000);
  };
  high(1000,_freq,_pin);
  wait(3000);
  high(1000,_freq,_pin);
}
