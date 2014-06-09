#include "mc-ir-control/shared.h"

using namespace McIrControl;

Sony::Sony(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _freq = 40;
}

void Sony::shutterNow()
{
  bool _seq[] = {
    1,0,1,1,0,1,0,0,1,0,1,1,1,0,0,0,1,1,1,1    };
  for (int j=0;j<3;j++) {
    high(2320,_freq,_pin);
    wait(650);
    for (int i=0;i<sizeof(_seq);i++){
      if (_seq[i]==0){
        high(575,_freq,_pin);
        wait(650);
      }
      else{
        high(1175,_freq,_pin);
        wait(650);
      }
    }
    wait(10000);
  }
}

void Sony::shutterDelayed()
{
  bool _seqDelayed[] = {
    1,1,1,0,1,1,0,0,1,0,1,1,1,0,0,0,1,1,1,1    };
  for (int j=0;j<3;j++) {
    high(2320,_freq,_pin);
    wait(650);
    for (int i=0;i<sizeof(_seqDelayed);i++){
      if (_seqDelayed[i]==0){
        high(575,_freq,_pin);
        wait(650);
      }
      else{
        high(1175,_freq,_pin);
        wait(650);
      }
    }
    wait(10000);
  }
}

void Sony::toggleVideo()
{
  bool _seqToggle[] = {
    0,0,0,1,0,0,1,0,1,0,1,1,1,0,0,0,1,1,1,1    };
  for (int j=0;j<3;j++) {
    high(2320,_freq,_pin);
    wait(650);
    for (int i=0;i<sizeof(_seqToggle);i++){
      if (_seqToggle[i]==0){
        high(575,_freq,_pin);
        wait(650);
      }
      else{
        high(1175,_freq,_pin);
        wait(650);
      }
    }
    wait(10000);
  }
}
