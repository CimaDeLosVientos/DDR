#include <stdint.h>
// Dancepad.h
#ifndef Dancepad_h
#define Dancepad_h

#include <Arduino.h>

class Dancepad
{
  private:
    Arrow _upArrow;
    Arrow _rightArrow;
    Arrow _downArrow;
    Arrow _leftArrow;
    int _orientation;
    bool _enabled;
    Arrow _arrows[4];
    
  public:
    Dancepad(Arrow _upArrow, Arrow _rightArrow, Arrow _downArrow, Arrow _leftArrow);

    void Setup();

    void SetRotate(int orientation);

    void Process();
};

#endif
