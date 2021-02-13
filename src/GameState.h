#ifndef GAME_STATE__H
#define GAME_STATE__H

#include <vector>
#include <mm_types.h>
#include <nds/arm9/console.h>

#include "Debugger.h"
#include "input/Controller.h"
#include "oam/SpriteInfo.h"
#include "oam/OamManager.h"

static constexpr uint8_t DEFAULT_DMA_CHANNEL = 3;

enum class Scene {
    MAIN_MENU,
    LEVEL,
    LEVEL_SUMMARY,
    SCORES,
};

class GameState {
   public:

      GameState();

      ~GameState();

      static void init();

      static void dispose();

      inline static GameState &instance() {
         DEBUG_BREAKING_ASSERT(_instance);
         return *_instance;
      }

      bool update();

      void start_new_game();

      void start_main_menu();

      void start_scores();

      void start_level_summary();

      Scene _current_scene;

      std::vector<SpriteInfo *> sprite_infos; // list of wrappers around OAM entries

      double clean_unused_oam_timer; //every arbitrary amount of time OAM is checked for unused entities and cleaned off

   private:
      static GameState *_instance;
};

#endif // GAME_STATE__H
