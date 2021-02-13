#ifndef HUD__H
#define HUD__H

#include <nds/arm9/console.h>
#include "Debugger.h"

#define HUD_ITEMS_ROW_X 236

class SpriteInfo;

class Hud {

public:

    Hud();

    static void init();

    static void dispose();

    inline static Hud &instance() {
        DEBUG_BREAKING_ASSERT(_instance);
        return *_instance;
    }

    void init_console();

    void clear_console();

    void update();

    void debug_oam();

    PrintConsole *print_console{};

    static Hud* _instance;
};

#endif // HUD__H