#include <stdint.h>
// Arrow.h
#ifndef Arrow_h
#define Arrow_h

#include <Arduino.h>

class Arrow
{
  public:
    int _pin;
    int _debugPin;
    int _status;
    int _statusPrev;
    uint8_t _keyLinked;
    
  public:
    Arrow(int pin, uint8_t keyLinked);
    Arrow();

    void Setup();

    void DigitalRead();

    bool IsPressed();

    void Press();

    bool IsReleased();

    void Release();

    void Process();
};

#endif
