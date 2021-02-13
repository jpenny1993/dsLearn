#ifndef SPRITETYPES__H
#define SPRITETYPES__H

/**
 * SpritesheetType is focused on file, what it contains.
 * It helps when it comes to manage multiple palettes - see OamManager.cpp
 */
enum class SpritesheetType {
    MENU_BUTTON = 0,
    CHESS_BOARD = 1,
    CHESS_PIECE = 2,
    NONE
};

#endif // SPRITETYPES__H