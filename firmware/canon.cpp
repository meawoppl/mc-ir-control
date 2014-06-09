#include "mc-ir-control/shared.h"

using namespace McIrControl;

Canon::Canon(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _freq = 33;
}

void Canon::shutterNow()
{
 for(int i=0; i<16; i++) { 
    digitalWrite(_pin, HIGH);
    delayMicroseconds(11);
    digitalWrite(_pin, LOW);
    delayMicroseconds(11);
  } 
  delayMicroseconds(7330); 
  for(int i=0; i<16; i++) { 
    digitalWrite(_pin, HIGH);
    delayMicroseconds(11);
    digitalWrite(_pin, LOW);
    delayMicroseconds(11);
  }
}

void Canon::shutterDelayed()
{
  for(int i=0; i<16; i++) { 
    digitalWrite(_pin, HIGH);
    delayMicroseconds(11);
    digitalWrite(_pin, LOW);
    delayMicroseconds(11);
  } 
  delayMicroseconds(5360); 
  for(int i=0; i<16; i++) { 
    digitalWrite(_pin, HIGH);
    delayMicroseconds(11);
    digitalWrite(_pin, LOW);
    delayMicroseconds(11);
  }
}
