#include "level.h"

bool level::isCellInsideLevel(int row, int column) const {
    return row < rows && column < columns;
}

char& level::getCell(size_t row, size_t column) {
    return data[row * columns + column];
}

void level::setCell(size_t row, size_t column, char cell) {
    data[row * columns + column] = cell;
}

[[nodiscard]] size_t level::getRows() const {
    return rows;
}

[[nodiscard]] size_t level::getColumns() const {
    return columns;
}

[[nodiscard]] char* level::getData() const {
    return data;
}

void level::setRows(size_t newRows) {
    rows = newRows;
}

void level::setColumns(size_t newColumns) {
    columns = newColumns;
}

void level::setData(char* newData) {
    data = newData;
}