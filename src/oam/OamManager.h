#ifndef OAMMANAGER__H
#define OAMMANAGER__H

#define MAX_SPRITE_NUMBER 128

#include "Debugger.h"
#include "oam/LayerLevel.h"
#include "oam/OamType.h"
#include "oam/SpriteInfo.h"
#include "oam/SpritesheetType.h"

class OAMManager {
   public:
      static void init_background_hardware();

      static void init_sprite_hardware();

      explicit OAMManager(OamType);

      static void init();

      static void dispose();

      static inline OAMManager& main(){
         DEBUG_BREAKING_ASSERT(_main_instance);
         return *_main_instance;
      }

      static inline OAMManager& sub(){
         DEBUG_BREAKING_ASSERT(_main_instance);
         return *_sub_instance;
      }

      void update();

      SpriteInfo *initSprite(const uint16_t pallette[],
                              int16_t palLen,
                              const uint16_t tiles[],
                              int16_t tilesLen,
                              ObjSize size,
                              SpritesheetType spriteType,
                              bool reuse_palette,
                              bool reuse_tiles,
                              LayerLevel layer);

      void clear_sprite_attributes();

      OamType _oam_type{};
      uint16_t offset_multiplier{};
      uint16_t *sprite_address{};
      uint16_t *palette_address{};
      uint16_t *oam_address{};

      uint32_t current_oam_id_palette = 0;
      uint32_t current_oam_id_tiles = 0;

      /* Keep track of the available tiles */
      uint16_t nextAvailableTileIdx = 0;

      OAMTable *oam{};

      int16_t _background_id{};

   private:
      static OAMManager* _main_instance;
      static OAMManager* _sub_instance;
};

#endif // OAMMANAGER__H