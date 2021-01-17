#include <nds.h>

class Controller {
   private:
      uint32_t _keys;
      touchPosition _stylus;

   public:
      Controller();

      // Gets the currently pressed keys
      void ScanKeyPresses();

      // Returns the current stylus position
      touchPosition Stylus();

      // Returns true if the Start Button was pressed
      bool Start();

      // Returns true if the Select Button was pressed
      bool Select();

      // Returns true if the Up Arrow was pressed
      bool Up();
      
      // Returns true if the Down Arrow was pressed
      bool Down();

      // Returns true if the Left Arrow was pressed
      bool Left();

      // Returns true if the Right Arrow was pressed
      bool Right();

      // Returns true if the X Button was pressed
      bool X();

      // Returns true if the Y Button was pressed
      bool Y();

      // Returns true if the A Button was pressed
      bool A();

      // Returns true if the B Button was pressed
      bool B();

      // Returns true if the Left Trigger was pressed
      bool L();

      // Returns true if the Right Trigger was pressed
      bool R();
};
