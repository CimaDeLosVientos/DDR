#include <stdint.h>
// Arrow.cpp
#include "Arrow.h"
#include "Dancepad.h"


Dancepad::Dancepad(Arrow upArrow, Arrow rightArrow, Arrow downArrow, Arrow leftArrow)
{
  _upArrow = upArrow;
  _rightArrow = rightArrow;
  _downArrow = downArrow;
  _leftArrow = leftArrow;
  _orientation = 0;
  _arrows[0] = _upArrow;
  _arrows[1] = _rightArrow;
  _arrows[2] = _downArrow;
  _arrows[3] = _leftArrow;
}

void Dancepad::Setup()
{
  for (int ii = 0; ii < 4; ++ii) {
    _arrows[ii].Setup();
  }
}

void Dancepad::SetRotate(int orientation)
{
  _orientation = orientation;
}

void Dancepad::Process()
{
  for (int ii = 0; ii < 4; ++ii) {
    _arrows[(ii + _orientation) % 4].Process();
  }
}