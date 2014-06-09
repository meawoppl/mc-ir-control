#ifndef mcic_shared_h
#define mcic_shared_h

using namespace McIrControl;

void wait(unsigned int time){
  unsigned long start = micros();
  while(micros()-start<=time){
  }
}

void high(unsigned int time, int freq, int pinLED){
  int pause = (1000/freq/2)-4;
  unsigned long start = micros();
  while(micros()-start<=time){
    digitalWrite(pinLED,HIGH);
    delayMicroseconds(pause);
    digitalWrite(pinLED,LOW);
    delayMicroseconds(pause);
  }
}

#endif
