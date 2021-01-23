#include <nds.h>

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

class ControllerStylus {
   private:
   touchPosition* _position;

   public:
   ControllerStylus(touchPosition* position);

   // Returns true if the stylus has touched the screen
   bool Touched();

   // Returns the X pixel position of the stylus 
   uint16_t X();

   // Returns the Y pixel position of the stylus 
   uint16_t Y();
};

class Controller {
   private:
      uint32_t  _pressed;
      uint32_t  _heldDown;
      uint32_t  _released;
      touchPosition _stylus;

   public:
      Controller();

      // Gets the current key state, should be done at least once per game loop
      void ScanKeyPresses();

      ControllerStylus Stylus = ControllerStylus(&_stylus);

      ControllerButton Start = ControllerButton(KEY_START, &_pressed, &_heldDown, &_released);

      ControllerButton Select = ControllerButton(KEY_SELECT, &_pressed, &_heldDown, &_released);

      ControllerButton Up = ControllerButton(KEY_UP, &_pressed, &_heldDown, &_released);
      
      ControllerButton Down = ControllerButton(KEY_DOWN, &_pressed, &_heldDown, &_released);

      ControllerButton Left = ControllerButton(KEY_LEFT, &_pressed, &_heldDown, &_released);

      ControllerButton Right = ControllerButton(KEY_RIGHT, &_pressed, &_heldDown, &_released);

      ControllerButton X = ControllerButton(KEY_X, &_pressed, &_heldDown, &_released);

      ControllerButton Y = ControllerButton(KEY_Y, &_pressed, &_heldDown, &_released);

      ControllerButton A = ControllerButton(KEY_A, &_pressed, &_heldDown, &_released);

      ControllerButton B = ControllerButton(KEY_B, &_pressed, &_heldDown, &_released);

      ControllerButton L = ControllerButton(KEY_L, &_pressed, &_heldDown, &_released);

      ControllerButton R = ControllerButton(KEY_R, &_pressed, &_heldDown, &_released);
};
