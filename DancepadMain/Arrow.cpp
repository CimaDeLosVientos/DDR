#include <stdint.h>
// Arrow.cpp
#include "Arrow.h"
#include <Keyboard.h>


Arrow::Arrow(int pin, uint8_t keyLinked)
{
  _pin = pin;
  //_debugPin = _pin + 6;
  _status = 1;
  _statusPrev = 1;
  _keyLinked = keyLinked;
}

Arrow::Arrow()
{
}

void Arrow::Setup()
{
  pinMode(_pin, INPUT_PULLUP);
}    

void Arrow::DigitalRead()
{
  _status = digitalRead(_pin);
}

bool Arrow::IsPressed()
{
  return _status != _statusPrev && _status == LOW;
}

void Arrow::Press()
{
  Keyboard.press(_keyLinked);
  //digitalWrite(_debugPin, HIGH);
  _statusPrev = _status;      
}

bool Arrow::IsReleased()
{
  return _status != _statusPrev && _status == HIGH;
}

void Arrow::Release()
{
  Keyboard.release(_keyLinked);
  //digitalWrite(_debugPin, LOW);
  _statusPrev = _status;      
}

void Arrow::Process()
{
  Arrow::DigitalRead();

  if (Arrow::IsPressed())
  {
    Arrow::Press();
  }
  if (Arrow::IsReleased())
  {
    Arrow::Release();
  }
}