#include <cstdio>
#include "GameState.h"

GameState *GameState::_instance = nullptr;

GameState::GameState() {
    // The maximum number of entities that can be rendered on NDS is 128
    sprite_infos.reserve(MAX_SPRITE_NUMBER);

    // Set up logic
    _current_scene = Scene::MAIN_MENU;
}

GameState::~GameState() {
}

void GameState::dispose() {
    DEBUG_BREAKING_ASSERT(_instance);
    delete _instance;
}

void GameState::init() {
    DEBUG_BREAKING_ASSERT(!_instance);
    _instance = new GameState();
    DEBUG_BREAKING_ASSERT(_instance);
}

void GameState::start_new_game() {
   // Reset game state here

   _current_scene = Scene::LEVEL;
}

void GameState::start_main_menu() {
   // Update state to display menu
    _current_scene = Scene::MAIN_MENU;
   
   // TODO populate main menu
}

void GameState::start_scores() {
   // Update state to display score
    _current_scene = Scene::SCORES;
}

void GameState::start_level_summary() {
    _current_scene = Scene::LEVEL_SUMMARY;
   // Display winner
   // Display time spent
}

bool GameState::update() {
   // TODO update game state
    return true;
}
