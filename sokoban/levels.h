#ifndef LEVELS_H
#define LEVELS_H

#include "globals.h"

void load_next_level() {
    ++level_index;
    if (level_index >= LEVEL_COUNT) {
        level_index = 0;
        game_state = VICTORY_STATE;
        create_victory_menu_background();
    }

    current_level = std::make_shared<level>(LEVELS[level_index]);
    size_t entry_row = current_level->get_entry_row();
    size_t entry_column = current_level->get_entry_column();
    if (current_player == nullptr) {
        current_player = std::make_shared<player>(entry_row, entry_column);
    } else {
        current_player->teleport(entry_row, entry_column);
    }
    derive_graphics_metrics_from_loaded_level();
}

void unload_level() {
    current_level.reset();
}

#endif // LEVELS_H
