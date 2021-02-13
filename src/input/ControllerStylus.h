#ifndef ControllerStylus__H
#define ControllerStylus__H

#include <nds.h>

// Stylus - Checks if the screen was touched & returns (x, y)
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

#endif // ControllerStylus__H
