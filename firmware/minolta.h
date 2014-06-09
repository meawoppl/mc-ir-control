#ifndef mcic_shared_h
#define mcic_shared_h

using namespace McIrControl;

class Minolta{
public:
  Minolta(int pin);
  void shutterNow();
  void shutterDelayed();
private:
  int _pin;
  int _freq;
};

#endif
