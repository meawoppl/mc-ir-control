#ifndef mcic_canon_h
#define mcic_canon_h

using namespace McIrControl;

class Canon{
public:
  Canon(int pin);
  void shutterNow();
  void shutterDelayed();
private:
  int _pin;
  int _freq;
};

#endif
