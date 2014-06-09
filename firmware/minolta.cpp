#include "mc-ir-control/shared.h"

using namespace McIrControl;

Minolta::Minolta(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _freq = 38;
}

void Minolta::shutterNow()
{
  bool _seq[] = {
    0,0,1,0,1,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1    };
  high(3750,_freq,_pin);
  wait(1890);
  for (int i=0;i<sizeof(_seq);i++){
    if (_seq[i]==0){
      high(456,_freq,_pin);
      wait(487);
    }
    else{
      high(456,_freq,_pin);
      wait(1430);
    }
  };
}

void Minolta::shutterDelayed()
{
  bool _seqDelayed[] = {
    0,0,1,0,1,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1    };
  high(3750,_freq,_pin);
  wait(1890);
  for (int i=0;i<sizeof(_seqDelayed);i++){
    if (_seqDelayed[i]==0){
      high(456,_freq,_pin);
      wait(487);
    }
    else{
      high(456,_freq,_pin);
      wait(1430);
    }
  };
}
