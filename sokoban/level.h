#ifndef LEVEL_H
#define LEVEL_H

#include <cstddef>
#include <vector>
#include <cassert>
#include <algorithm>

/* Game Elements */
const char WALL = '#';
const char FLOOR = '-';
const char BOX = '$';
const char BOX_ON_GOAL = '*';
const char GOAL = '.';
const char PLAYER = '@';
const char PLAYER_ON_GOAL = '+';

class level {
public:
    level(size_t rows, size_t columns, const char *data);
    [[nodiscard]] bool is_cell_inside(int row, int column) const {
        assert(row >= 0);
        assert(column >= 0);
        return static_cast<size_t>(row) < this->rows && static_cast<size_t>(column) < this->columns;
    }
    char& get_cell(size_t row, size_t column) {
        assert(is_cell_inside(row, column));
        return data[row * columns + column];
    }
    char& set_cell(size_t row, size_t column, char cell) {
        assert(is_cell_inside(row, column));
        data[row * columns + column] = cell;
        return data[row * columns + column];
    }
    [[nodiscard]] size_t get_rows() const {
        return rows;
    }
    [[nodiscard]] size_t get_columns() const {
        return columns;
    }
    [[nodiscard]] size_t get_entry_row() const {
        assert(entry_row != static_cast<size_t>(-1));
        return entry_row;
    }
    [[nodiscard]] size_t get_entry_column() const {
        assert(entry_column != static_cast<size_t>(-1));
        return entry_column;
    }

private:
    size_t rows, columns;
    std::vector<char> data;
    size_t entry_row, entry_column;
};

#endif // LEVEL_H
