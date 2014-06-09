#ifndef mcic_pentax_h
#define mcic_pentax_h

using namespace McIrControl;

class Pentax{
public:
  Pentax(int pin);
  void shutterNow();
  void toggleFocus();
private:
  int _pin;
  int _freq;
};

#endif
