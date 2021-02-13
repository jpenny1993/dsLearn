#include "input/ControllerStylus.h"

ControllerStylus:: ControllerStylus(touchPosition* position) {
   _position = position;
}

bool ControllerStylus::Touched() {
   // DSi doesn't return value for screen resistance
   // Using pixel values to ensure we always know
   return _position->px > 0 &&
          _position->py > 0;
}

uint16_t ControllerStylus::X() {
   return _position->px;
}

uint16_t ControllerStylus::Y() {
   return _position->py;
}
