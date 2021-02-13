#ifndef ControllerButton__H
#define ControllerButton__H

#include <nds.h>

// Button - Checks key state changes for provided keycode
class ControllerButton {
   private:
      KEYPAD_BITS _keycode;
      uint32_t* _pressed;
      uint32_t* _heldDown;
      uint32_t* _released;

   public:
      ControllerButton(KEYPAD_BITS keycode, uint32_t* pressed, uint32_t* heldDown, uint32_t* released);

      // Returns true if button is pressed, this does an active check instead of relying on scanKeys() to have run
      bool CurrentlyPressed();

      // Returns true if the button is held down
      bool HeldDown();

      // Returns true if the button was pressed
      bool Pressed();

      // Returns true if the button was released
      bool Released();
};

#endif //ControllerButton__H
