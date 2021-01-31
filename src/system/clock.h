#include <time.h>

#ifndef Clock__H
#define Clock__H

class Clock {
   private:
   bool _isEmulator; // DeSmuMe doesn't implement time properly
   int16_t _fps;
   uint64_t _ticker; // Emulated timestamp to add to initial tick
   uint64_t _frame;
   time_t _start;
   time_t _time;

   public:
   Clock(int16_t fps);

   Clock() : Clock(60) {} // Assume 60fps by default

   uint64_t Frame();

   tm Time();

   void Update();
};

#endif // Clock__H