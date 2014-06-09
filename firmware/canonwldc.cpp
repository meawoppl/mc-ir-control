#include "mc-ir-control/shared.h"

using namespace McIrControl;

// Remote control based module from this device:
// http://www.amazon.com/Canon-WL-DC100-Wireless-Controller-PowerShot/dp/B000050MJH

CanonWLDC100::CanonWLDC100(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _freq = 38;
}
 
void CanonWLDC100::shutterNow()
{
  bool _seq[] = {0,1,0,1,0,0,1,1,1,0,0,0,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1};
  high(9042,_freq,_pin);
  wait(4379);
 
  for (int i=0;i<sizeof(_seq);i++){
    if (_seq[i]==0){
      high(612,_freq,_pin);
      wait(512);
    }
    else{
      high(612,_freq,_pin);
      wait(1621);
    }
  };
    high(599,_freq,_pin);
}
