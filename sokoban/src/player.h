#ifndef SOKOBAN_PLAYER_H
#define SOKOBAN_PLAYER_H

#include <cstddef>

class player {
public:
    player(): row{0}, column{0} {};

    [[nodiscard]] size_t getRow() const;
    [[nodiscard]] size_t getColumn() const;

    void setRow(size_t newRow);
    void setColumn(size_t newRow);
private:
    size_t row;
    size_t column;
};


#endif //SOKOBAN_PLAYER_H
