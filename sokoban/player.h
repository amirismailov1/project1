#ifndef PLAYER_H
#define PLAYER_H

#include <cstddef>

class player {
public:
    player(size_t row, size_t column) : row{row}, column{column} { };
    [[nodiscard]] size_t get_row() const {
        return row;
    }
    [[nodiscard]] size_t get_column() const {
        return column;
    }
    void teleport(size_t new_row, size_t new_column) {
        this->row = new_row;
        this->column = new_column;
    }
    void move(int dx, int dy);

private:
    size_t row, column;
};

#endif // PLAYER_H
