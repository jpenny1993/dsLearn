// Libraries
#include <nds.h>
#include <clock.h>
#include <stdio.h>

// My Includes
#include <controller.h>

void UpdateGame(void);
void RenderGame(void);

Clock rtc;
Controller ctrl;

int main()
{
   consoleDemoInit();

   while (1) {
      rtc.Update();

      UpdateGame();
      RenderGame();

      swiWaitForVBlank();
      ctrl.ScanKeyPresses();
   }

   return 0;
}

void KeypadTest(const char *button, ControllerButton btn) {
   if (btn.Pressed())
   {
      iprintf("The %s button was pressed\n", button);
   }
   if (btn.HeldDown())
   {
      iprintf("The %s button was held down\n", button);
   }
   if (btn.Released())
   {
      iprintf("The %s button was released\n", button);
   }
}

void UpdateGame(void) {
   tm time = rtc.Time();
   iprintf("\x1b[0;1HTime = %02i:%02i:%02i", time.tm_hour, time.tm_min, time.tm_sec);
   iprintf("\x1b[1;1HFrame = %04lld\n", rtc.Frame());

}

void RenderGame(void) {
}