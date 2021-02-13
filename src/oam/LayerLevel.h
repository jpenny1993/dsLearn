#ifndef LAYERLEVEL__H
#define LAYERLEVEL__H

// https://devkitpro.org/viewtopic.php?f=38&t=8720
enum class LayerLevel {
    TOP         = 0, // OBJPRIORITY_0 | BG_PRIORITY_0
    MIDDLE_TOP  = 1, // OBJPRIORITY_1 | BG_PRIORITY_1
    MIDDLE_BOT  = 2, // OBJPRIORITY_2 | BG_PRIORITY_2
    BOTTOM      = 3, // OBJPRIORITY_3 | BG_PRIORITY_3
};

#endif // LAYERLEVEL__H