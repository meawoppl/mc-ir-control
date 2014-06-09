#ifndef mcic_olympus_h
#define mcic_olympus_h

using namespace McIrControl;

class Olympus{
public:
  Olympus(int pin);
  void shutterNow();
  void zoomin(unsigned int pct);
  void zoomout(unsigned int pct);
private:
  int _pin;
  int _freq;
};

#endif
