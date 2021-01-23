// Libraries
#include <nds.h>
#include <time.h>
#include <stdio.h>

// My Includes
#include <controller.h>

void UpdateGame(double deltaTime);
void RenderGame(double deltaTime);

Controller ctrl;

int main()
{
   time_t currentTime, deltaTime, lastTime = time(NULL);
   int16_t hours, seconds, minutes;
   uint64_t frame = 0;
   double fps;
   consoleDemoInit();

   while (1)
   {
      frame++;
      // Calculate time between frames
      currentTime = time(NULL);
      deltaTime = currentTime - lastTime;
      fps = (1.0 / deltaTime) * 1000;
      lastTime = currentTime;

      // Convert unix timestamp into human readable time
      struct tm *timeStruct = gmtime((const time_t *)&currentTime);
      hours = timeStruct->tm_hour;
      minutes = timeStruct->tm_min;
      seconds = timeStruct->tm_sec;

      // Print debug info
      // TODO: why is delta time not working as expected
      iprintf("\x1b[0;1HTime = %02i:%02i:%02i", hours, minutes, seconds);
      iprintf("\x1b[1;1HFrame = %04lld\n", frame);
      iprintf("\x1b[2;1HFPS = %02f\n", fps);

      UpdateGame(deltaTime);
      RenderGame(deltaTime);

      swiWaitForVBlank();
      ctrl.ScanKeyPresses();
   }

   return 0;
}

void KeypadTest(const char *button, ControllerButton btn)
{
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

void UpdateGame(double deltaTime)
{
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

void RenderGame(double deltaTime)
{
}