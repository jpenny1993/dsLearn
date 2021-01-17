#include <nds.h>
#include <controller.h>

Controller::Controller()
{
   _keys = 0;
}

void Controller::ScanKeyPresses()
{
   // Update the keypad state
   scanKeys();

   // Get the current state of pressed keys
   // Other functions that may be useful; keysCurrent(), keysHeld(), keysUp(), keysDownRepeat()
   _keys = keysDown();

   // Get the current state of the touchpad
   touchRead(&_stylus);
}

touchPosition Controller::Stylus()
{
   return _stylus;
}

bool Controller::Start()
{
   return _keys & KEY_START;
}

bool Controller::Select()
{
   return _keys & KEY_SELECT;
}

bool Controller::Up()
{
   return _keys & KEY_UP;
}

bool Controller::Down()
{
   return _keys & KEY_DOWN;
}

bool Controller::Left()
{
   return _keys & KEY_LEFT;
}

bool Controller::Right()
{
   return _keys & KEY_RIGHT;
}

bool Controller::X()
{
   return _keys & KEY_X;
}

bool Controller::Y()
{
   return _keys & KEY_Y;
}

bool Controller::A()
{
   return _keys & KEY_A;
}

bool Controller::B()
{
   return _keys & KEY_B;
}

bool Controller::L()
{
   return _keys & KEY_L;
}

bool Controller::R()
{
   return _keys & KEY_R;
}