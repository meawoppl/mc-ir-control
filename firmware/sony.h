#ifndef mcic_sony_h
#define mcic_sony_h

using namespace McIrControl;

class Sony{
public:
  Sony(int pin);
  void shutterNow();
  void shutterDelayed();
  void toggleVideo();
private:
  int _pin;
  int _freq;
};

#endif
