#include "mc-ir-control/shared.h"

using namespace McIrControl;

Olympus::Olympus(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _freq = 40;
}

void Olympus::shutterNow()
{
  bool _seq[] = {
    0,1,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1    };
  high(8972,_freq,_pin);
  wait(4384);
  high(624,_freq,_pin);
  for (int i=0;i<sizeof(_seq);i++){
    if (_seq[i]==0){
      wait(488);
      high(600,_freq,_pin);
    }
    else{
      wait(1600);
      high(600,_freq,_pin);
    }
  };
}

void Olympus::zoomin(unsigned int pct)
{
  bool _seq[] = {
    0,1,1,0,0,0,0,1,1,1,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1    };
  high(9000,_freq,_pin);
  wait(4500);
  high(500,_freq,_pin);
  for (int i=0;i<sizeof(_seq);i++){
    if (_seq[i]==0){
      wait(500);
      high(500,_freq,_pin);
    }
    else{
      wait(1500);
      high(500,_freq,_pin);
    }
  };
  wait(40000);
  if (pct>100) pct = 100;
  pct = (pct*52)/100 + 1;
  for (int i=1; i<pct; i++)
  {
    high(9000,_freq,_pin);
    wait(2000);
    high(500,_freq,_pin);
    wait(96000);
  }

}

void Olympus::zoomout(unsigned int pct)
{
  bool _seq[] = 
             {0,1,1,0,0,0,0,1,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1 };
  high(9000,_freq,_pin);           // 
  wait(4500);
  high(500,_freq,_pin);
  for (int i=0;i<sizeof(_seq);i++){
    if (_seq[i]==0){
      wait(500);
      high(500,_freq,_pin);
    }
    else{
      wait(1500);
      high(500,_freq,_pin);
    }
  };
  wait(40000);
  if (pct>100) pct = 100;
  pct = (pct*70)/100 + 1;
  for (int i=1; i<pct; i++)
  {
    high(9000,_freq,_pin);
    wait(2000);
    high(500,_freq,_pin);
    wait(96000);
  }
}
