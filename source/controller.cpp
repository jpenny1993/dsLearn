#include <nds.h>
#include <controller.h>

// Check state changes of Buttons on Controller 

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

// Controller / Keypad

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

touchPosition Controller::Stylus()
{
   return _stylus;
}