#ifndef SPRITEINFO__H
#define SPRITEINFO__H

#include <nds/arm9/sprite.h>
#include "oam/SpritesheetType.h"
#include "oam/OamType.h"

class SpriteInfo {
   public:
      u16 *sprite_address{};
      int offset_multiplier{};

      u8 oamId_palette{};
      int oamId_tiles{};

      int width{};
      int height{};
      int angle{};
      SpriteEntry *entry{};

      SpritesheetType spriteType{};
      u16 oam_address{};
      OamType oamType{};

      void UpdateFrame(u8 *tile, u32 size);
};

#endif // SPRITEINFO__H