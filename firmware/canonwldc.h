#ifndef mcic_canonwldc_h
#define mcic_canonwldc_h

using namespace McIrControl;

class CanonWLDC100{
public:
  CanonWLDC100(int pin);
  void shutterNow();
private:
  int _pin;
  int _freq;
};

#endif
