#include "level.h"

level::level(size_t rows, size_t columns, const char *data)
        : rows(rows), columns(columns), data(data, data + rows * columns), entry_row(-1), entry_column(-1) {
    assert(rows > 0 && columns > 0);
    assert(this->data.size() == rows * columns);
    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            char& cell = get_cell(row, column);
            if (cell == PLAYER || cell == PLAYER_ON_GOAL) {
                assert(entry_row == static_cast<size_t>(-1));
                entry_row = row;
                entry_column = column;
                // Установите FLOOR в ячейке, если там будет появляться игрок
                cell = FLOOR;
            }
        }
    }
    assert(entry_row != static_cast<size_t>(-1));
    assert(entry_column != static_cast<size_t>(-1));
}
