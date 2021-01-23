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
   rtc.Update();
   tm time = rtc.Time();
   iprintf("\x1b[0;1HTime = %02i:%02i:%02i", time.tm_hour, time.tm_min, time.tm_sec);
   iprintf("\x1b[1;1HFrame = %04lld\n", rtc.Frame());

   iprintf("Stylus %s\n", (ctrl.Stylus.Touched() ? "was touched" : "not touched"));
   iprintf("Stylus - x %04i, y %04i\n", ctrl.Stylus.X(), ctrl.Stylus.Y());

   KeypadTest("A", ctrl.A);
   KeypadTest("B", ctrl.B);
   KeypadTest("Y", ctrl.Y);
   KeypadTest("X", ctrl.X);
   KeypadTest("L", ctrl.L);
   KeypadTest("R", ctrl.R);
   KeypadTest("Start", ctrl.Start);
   KeypadTest("Select", ctrl.Select);
   KeypadTest("Up", ctrl.Up);
   KeypadTest("Down", ctrl.Down);
   KeypadTest("Left", ctrl.Left);
   KeypadTest("Right", ctrl.Right);
}

void RenderGame(void) {
}