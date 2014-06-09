#ifndef mcic_nikon_h
#define mcic_nikon_h

using namespace McIrControl;

class Nikon{
public:
  Nikon(int pin);
  void shutterNow();
private:
  int _pin;
  int _freq;
};

#endif
