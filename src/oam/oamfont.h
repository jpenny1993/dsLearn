#ifndef Oamfont__H
#define Oamfont__H

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FONT_SPRITES 96

class OamSprite {
   public:
      OamSprite();
      ~OamSprite();

      void Create(OamState *_oam, int _width, int _height, SpriteSize _size, SpriteColorFormat _format, int ID);
      void Destroy();
      void UpdateOam();

      static int NumSprites;

      OamState *Oam;

      int OamID;

      int x;
      int y;

      int Width;
      int Height;

      SpriteColorFormat Format;
      SpriteSize Size;

      bool Active;

      u16 *Gfx;
};

class Oamfont {
public:
   void Init(OamState *_oam, u8 *_gfx, int _width, int _height, SpriteSize _size, int _max_chars, int _minID);
   void LoadPalette(const u16 *ColorTable, u16 *target, int numbytes);
   void Clear();
   void Print(int x, int y, const char *text);
   void Print(int x, int y, int value);
   void Print(int x, int y, const char *text, int value);
   void PrintCentered(int x, int y, const char *text);
   void PrintScore(int x, int y, int value, const char *filler, int length);
   void PrintSpaced(int x, int y, const char *text, int x_space, s32 x_offset, s32 y_offset);
   void PrintSine(int x, int y, const char *text, int width_offset, int _height, int cycles, s32 start_angle);
   void PrintBounce(int x, int y, const char *text, int width_offset, int _height, int cycles, s32 start_angle);
   void PrintVertical(int x, int y, const char *text);
   void PrintSineVertical(int x, int y, const char *text, int height_offset, int _width, int cycles, s32 start_angle);

   int Width;
   int Height;
   int TileMemSize;
   int ActiveChars;
   int Start;

private:
   OamState *Oam;
   u8 *Gfx;
   int MaxChars;

   OamSprite Fonts[MAX_FONT_SPRITES];
   char Str[256];
   char Str2[256];
};

#endif
