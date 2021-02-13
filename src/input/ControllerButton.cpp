#include "input/ControllerButton.h"

ControllerButton::ControllerButton(
   KEYPAD_BITS keycode,
   uint32_t* pressed,
   uint32_t* heldDown,
   uint32_t* released) {
      _keycode = keycode;
      _pressed = pressed;
      _heldDown = heldDown;
      _released = released;
}

bool ControllerButton::CurrentlyPressed() {
   return keysCurrent() & _keycode;
}

bool ControllerButton::HeldDown() {
   return *_heldDown & _keycode;
}

bool ControllerButton::Pressed() {
   return *_pressed & _keycode;
}

bool ControllerButton::Released() {
   return *_released & _keycode;
}
