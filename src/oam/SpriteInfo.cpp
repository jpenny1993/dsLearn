#include <nds.h>
#include "oam/SpriteInfo.h"

void SpriteInfo::UpdateFrame(u8 *tile, u32 size) {
    dmaCopyHalfWords(3, tile, &sprite_address[entry->gfxIndex * this->offset_multiplier], size);
}