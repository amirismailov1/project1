#include "player.h"
#include "raylib.h"
#include <memory>
#include "level.h"
extern std::shared_ptr<level> current_level;
extern void load_next_level();

extern Sound goal_sound;
extern Sound exit_sound;
extern void play_sound(Sound sound);

void player::move(int dx, int dy) {
    int next_row = static_cast<int>(row) + dy;
    int next_column = static_cast<int>(column) + dx;
    if (!current_level->is_cell_inside(next_row, next_column)) {
        return;
    }
    char &cell = current_level->get_cell(static_cast<size_t>(next_row), static_cast<size_t>(next_column));
    if (cell == FLOOR || cell == GOAL) {
        row = static_cast<size_t>(next_row);
        column = static_cast<size_t>(next_column);
    } else if (cell == BOX || cell == BOX_ON_GOAL) {
        int target_row = next_row + dy;
        int target_column = next_column + dx;
        if (!current_level->is_cell_inside(target_row, target_column)) {
            return;
        }
        char &target_cell = current_level->get_cell(static_cast<size_t>(target_row), static_cast<size_t>(target_column));
        if (target_cell == FLOOR || target_cell == GOAL) {
            cell = cell == BOX ? FLOOR : GOAL;
            if (target_cell == FLOOR) {
                target_cell = BOX;
            } else {
                target_cell = BOX_ON_GOAL;
                play_sound(goal_sound);
            }
            row = static_cast<size_t>(next_row);
            column = static_cast<size_t>(next_column);

            bool level_solved = true;
            for (size_t level_row = 0; level_row < current_level->get_rows(); ++level_row) {
                for (size_t level_column = 0; level_column < current_level->get_columns(); ++level_column) {
                    char cell_to_test = current_level->get_cell(level_row, level_column);
                    if (cell_to_test == GOAL) {
                        level_solved = false;
                        break;
                    }
                }
                if (!level_solved) break;
            }

            if (level_solved) {
                load_next_level();
                play_sound(exit_sound);
            }
        }
    }
}

