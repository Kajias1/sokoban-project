#include "player.h"

size_t player::getRow() const {
    return row;
}

size_t player::getColumn() const {
    return column;
}

void player::setRow(size_t newRow) {
    row = newRow;
}

void player::setColumn(size_t newColumn) {
    column = newColumn;
}
