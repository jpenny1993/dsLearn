#include <controller.h>

// Button - Checks key state changes for provided keycode

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

// Stylus - Checks if the screen was touched & returns (x, y)

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

// Controller - Updates the keypad and stylus state

Controller::Controller()
{
   _pressed = 0;
   _heldDown = 0;
   _released = 0;
}

void Controller::ScanKeyPresses()
{
   // Update the libnds keypad state
   scanKeys();

   // Set the current key state
   // Other functions that may be useful; keysDownRepeat(), keysSetRepeat( u8 setDelay, u8 setRepeat );
   _pressed = keysDown();
   _heldDown = keysHeld();
   _released = keysUp();

   // Get the current state of the touchpad
   touchRead(&_stylus);
}