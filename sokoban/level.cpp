#include "level.h"

level::level(size_t rows, size_t columns, const char *data) : rows(rows), columns(columns) {
    this->data.assign(data, data + rows * columns);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < columns; ++col) {
            if (get_cell(row, col) == PLAYER || get_cell(row, col) == PLAYER_ON_GOAL) {
                entry_row = row;
                entry_column = col;
                return;
            }
        }
    }
    entry_row = entry_column = static_cast<size_t>(-1);
}
