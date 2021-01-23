#include <time.h>

class Clock {
   private:
   bool _isEmulator; // DeSmuMe doesn't implement time properly
   uint64_t _ticker; // Emulated timestamp to add to initial tick
   uint64_t _frame;
   time_t _start;
   time_t _time;

   public:
   Clock();

   uint64_t Frame();

   tm Time();

   void Update();
};