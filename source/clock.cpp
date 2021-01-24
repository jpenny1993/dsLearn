
#include <clock.h>

Clock::Clock(int16_t fps) {
   _fps = fps;
   _frame = 0;
   _ticker = 0;
}

uint64_t Clock::Frame() {
   return _frame;
}

tm Clock::Time() {
   return *gmtime((const time_t *)&_time);
}

void Clock::Update() {
   _frame++;

   /* Integer overflow fix for clock, currently it's a pointless waste of processing power
   // Reset frame counter when int.max is reached
   if (_frame == UINT64_MAX) _frame = 0;

   // Reset ticker if int.max is reached
   if (_ticker == UINT64_MAX) {
      _start += _ticker;
      _ticker = 0;
   }
   */

   // Starting tick will be provided by emulators, doesn't work in constructor
   if (_start == 0) {
      _start = time(NULL);
   }

   // Update realtime once a second
   bool shouldUpdate = (_frame % _fps) == 0;
   if (shouldUpdate) {
      if (_isEmulator) {
         _ticker++;
         _time = _start + _ticker;
      } else {
         _time = time(NULL);
         _isEmulator = _time == _start;
      }
   }
}
