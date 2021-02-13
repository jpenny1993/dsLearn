#include <nds.h>
#include "oam/oamfont.h"

int OamSprite::NumSprites = 0;

OamSprite::OamSprite() {
}

OamSprite::~OamSprite() {
   Active = false;  

   //api: free the graphics
   if (Gfx) {
      oamFreeGfx(Oam, Gfx);
   }

   Gfx = 0;
}


/******************************************************************************
   Allocates vram mem for gfx
   
   1. if _reset_id_counter = true s_oamID is reset to zero
      as I'm planning to reload all the sprite gfx every level
      including the ships, bullets, etc.
   2. _increase_id is a parameter I added to control animations
      ie. frames of the same object(sprite) share the same oamID so I'll
      only inc the oamID when I create sprites for another object.
      eg. viper[frame0-frame5] has oam_id =0
      enemy[frame0-frame8] has oam_id = 1

******************************************************************************/
void OamSprite::Create(OamState *_oam, int _width, int _height, SpriteSize _size, SpriteColorFormat _format, int ID ) 
{
   x = 0;
   y = 0;

   Oam = _oam;
   OamID = ID;

   Active = true;
   Width = _width;
   Height = _height;
   Size = _size;
   Format = _format;
      
   //api: allocate a chunk of sprite graphics memory
   Gfx = oamAllocateGfx(Oam, Size, Format);

   assert(Gfx);

   NumSprites++;
}

void OamSprite::Destroy() {
   Active = false;  
   //api: free the graphics
   if(Gfx)
   {   
      oamFreeGfx(Oam, Gfx);
   }

   Gfx = 0;
   NumSprites--;
}


/******************************************************************************

   map our sprite to oam entries

******************************************************************************/
void OamSprite::UpdateOam() {
   //oamSet (OamState *oam, int id, int x, int y, int priority,
   //        int palette_alpha, SpriteSize size, SpriteColorFormat format,
   //        const void *gfxOffset, int affineIndex, bool sizeDouble,
   //        bool hide, bool hflip, bool vflip, bool mosaic)
   oamSet(Oam, 
      OamID,            // id 
      x, y,             // x,y
      0,                // priority
      0,               // palette alpha
      Size,            // size
      Format,          // color format
      Gfx,             // gfx offset
      -1,             // affine index
      false,            // double if rotating? 
      !Active,         // hidden if true
      false,            // hflip
      false,             // vflip
      false);            // apply mosaic?
}



void Oamfont::Init(OamState *_oam,u8 *_gfx, int _width, int _height, SpriteSize _size, int _max_chars, int _minID) {
   ActiveChars = 0;
   Oam = _oam;
   
   if (_max_chars > MAX_FONT_SPRITES)
      _max_chars = MAX_FONT_SPRITES;
   
   Gfx = _gfx;
   MaxChars = _max_chars;
   Width = _width;
   Height = _height;
   TileMemSize = (Width * Height);   // we are using 8 bit 256 colors
   
   for (int i = 0; i < MaxChars; i++) {
      Fonts[i].Create (Oam, Width, Height, _size, SpriteColorFormat_256Color, i + _minID);
      Fonts[i].Active = false;
   }
}

void Oamfont::LoadPalette( const u16* ColorTable, u16* target, int numbytes) {
   dmaCopy(ColorTable, target, numbytes);
}

void Oamfont::Clear() {
   ActiveChars = 0;
   for (int i = 0; i < MaxChars; i++) {
      Fonts[i].Active = false;
      Fonts[i].UpdateOam();
   }
}

void Oamfont::Print(int x, int y, const char *text) {
   unsigned char font_char;
   
   while(*text) {
      font_char = (*(unsigned char*)text++) - 32;
      // don't print space
      if (font_char) {
         for (int i = 0; i < MaxChars; i++) {
            if (!Fonts[i].Active) {
               dmaCopy(Gfx + (TileMemSize*font_char) , Fonts[i].Gfx, TileMemSize);
               Fonts[i].Active = true;
               Fonts[i].x = x;
               Fonts[i].y = y;
               Fonts[i].UpdateOam();
               ActiveChars++;
               break;
            }
         }
      }
      x += Width;
   }
}

void Oamfont::Print(int x, int y, int value) {
   sprintf(Str,"%i",value);
   Print(x, y, Str);
}

void Oamfont::Print(int x, int y, const char *text, int value) {
   strcpy(Str, text);
   sprintf(Str2,"%i",value);
   strcat(Str, Str2);
   
   Print(x, y, Str);
}

void Oamfont::PrintCentered(int x, int y, const char *text) {
   unsigned char font_char;
   int total_width = 0;
   
   total_width = Width * strlen(text);
   
   x = (SCREEN_WIDTH - total_width) / 2; 

   while(*text) {
      font_char = (*(unsigned char*)text++) - 32;
      // don't print space 
      if (font_char) {
         for (int i = 0; i < MaxChars; i++) {
            if (!Fonts[i].Active) {
               dmaCopy(Gfx + (TileMemSize*font_char) , Fonts[i].Gfx, TileMemSize);
               Fonts[i].Active = true;
               Fonts[i].x = x;
               Fonts[i].y = y;
               Fonts[i].UpdateOam();
               ActiveChars++;
               break;
            }
         }
      }
      x += Width; 
   }
}

void Oamfont::PrintScore(int x, int y, int value, const char *filler, int length) {
   sprintf(Str2,"%i",value);
   int value_len = strlen(Str2);
   
   if (length < value_len)
      length = value_len;
      
   int new_length = length - value_len;
   
   for (int i=0; i < new_length; i++) {
      Str[i]=*filler;
   }

   char *p_str = &Str[new_length];
 
   strcpy(p_str, Str2);
   
   Print(x, y, Str);
}

void Oamfont::PrintSpaced(int x, int y, const char *text, int x_space, s32 x_offset, s32 y_offset) {
   unsigned char font_char;
   s32 spacing = x_space << 12;
   s32 y_spacing = 0;
   s32 _x = x << 12;
   s32 _y = y << 12;
   s32 _x_space = x_space << 12;
   
   while(*text) {
      font_char = (*(unsigned char*)text++) - 32;
      // don't print space 
      if (font_char) {
         for (int i = 0; i < MaxChars; i++) {
            if (!Fonts[i].Active) {
               dmaCopy(Gfx + (TileMemSize*font_char) , Fonts[i].Gfx, TileMemSize);
               Fonts[i].Active = true;
               Fonts[i].x = _x >> 12;
               Fonts[i].y = _y >> 12;
               Fonts[i].UpdateOam();
               ActiveChars++;
               break;
            }
         }
      }
      
      y_spacing += y_offset;
      
      spacing += x_offset;
      _x_space = spacing;
      
      _x += ((Width<<12) + _x_space); 
      _y += (y_spacing);
   }
}

void Oamfont::PrintSine(int x, int y, const char *text, int width_offset, int _height, int cycles, s32 start_angle) {
   unsigned char font_char;
   unsigned int length = strlen(text);
   s32 angle_inc = div32(32768/2, length-1)*cycles;
   
   s32 _y;
   
   while(*text) {
      font_char = (*(unsigned char*)text++) - 32;
      
      _y = sinLerp(start_angle) * _height; 
      // don't print space 
      if (font_char) {
         for (int i = 0; i < MaxChars; i++) {
            if (!Fonts[i].Active) {
               dmaCopy(Gfx + (TileMemSize*font_char) , Fonts[i].Gfx, TileMemSize);
               Fonts[i].Active = true;
               Fonts[i].x = x;
               Fonts[i].y = y + (_y>>12);
               Fonts[i].UpdateOam();
               ActiveChars++;
               break;
            }
         }
      }
      
      x += Width + width_offset; 
      start_angle += angle_inc;
   }
}

void Oamfont::PrintBounce(int x, int y, const char *text, int width_offset, int _height, int cycles, s32 start_angle) {
   unsigned char font_char;
   unsigned int length = strlen(text);
   s32 angle_inc = div32(32768/2, length-1)*cycles;
   
   s32 _y;
   
   while(*text) {
      font_char = (*(unsigned char*)text++) - 32;
      
      _y = -abs(sinLerp(start_angle) * _height); 
      // don't print space 
      if (font_char) {
         for (int i = 0; i < MaxChars; i++) {
            if (!Fonts[i].Active) {
               dmaCopy(Gfx + (TileMemSize*font_char) , Fonts[i].Gfx, TileMemSize);
               Fonts[i].Active = true;
               Fonts[i].x = x;
               Fonts[i].y = y + (_y>>12);
               Fonts[i].UpdateOam();
               ActiveChars++;
               break;
            }
         }
      }
      
      x += Width + width_offset; 
      start_angle += angle_inc;
   }
}

void Oamfont::PrintVertical(int x, int y, const char *text) {
   unsigned char font_char;
   
   while(*text) {
      font_char = (*(unsigned char*)text++) - 32;
      // don't print space 
      if (font_char) {
         for (int i = 0; i < MaxChars; i++) {
            if (!Fonts[i].Active) {
               dmaCopy(Gfx + (TileMemSize*font_char) , Fonts[i].Gfx, TileMemSize);
               Fonts[i].Active = true;
               Fonts[i].x = x;
               Fonts[i].y = y;
               Fonts[i].UpdateOam();
               ActiveChars++;
               break;
            }
         }
      }
      y += Height; 
   }
}

void Oamfont::PrintSineVertical(int x, int y, const char *text, int height_offset, int _width, int cycles, s32 start_angle) {
   unsigned char font_char;
   unsigned int length = strlen(text);
   s32 angle_inc = div32(32768/2, length-1)*cycles;
   
   s32 _x;
   
   while(*text) {
      font_char = (*(unsigned char*)text++) - 32;
      
      _x = sinLerp(start_angle) * _width; 
      // don't print space 
      if (font_char) {
         for (int i = 0; i < MaxChars; i++) {
            if (!Fonts[i].Active) {
               dmaCopy(Gfx + (TileMemSize*font_char) , Fonts[i].Gfx, TileMemSize);
               Fonts[i].Active = true;
               Fonts[i].x = (_x >> 12) + x;
               Fonts[i].y = y;
               Fonts[i].UpdateOam();
               ActiveChars++;
               break;
            }
         }
      }
      
      
      y += Height + height_offset; 
      start_angle += angle_inc;
   }
}
