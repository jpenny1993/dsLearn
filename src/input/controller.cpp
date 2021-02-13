#include "input/Controller.h"

// Controller - Updates the keypad and stylus state

Controller::Controller() {
   _pressed = 0;
   _heldDown = 0;
   _released = 0;
}

void Controller::ScanKeyPresses() {
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