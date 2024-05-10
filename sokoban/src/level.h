#ifndef SOKOBAN_LEVEL_H
#define SOKOBAN_LEVEL_H

#include <cstddef>

class level {
public:
    level(): rows{0}, columns{0}, data{nullptr} {};
    level(size_t rows, size_t columns, char* data) {
        this->rows = rows;
        this->columns = columns;
        this->data = data;
    }

    [[nodiscard]] size_t getRows() const;
    [[nodiscard]] size_t getColumns() const;
    [[nodiscard]] char* getData() const;

    void setRows(size_t newRows);
    void setColumns(size_t newColumns);
    void setData(char* newData);

    char& getCell(size_t row, size_t column);
    void setCell(size_t row, size_t column, char cell);

    [[nodiscard]] bool isCellInsideLevel(int row, int column) const;

private:
    size_t rows, columns;
    char *data = nullptr;
};


#endif //SOKOBAN_LEVEL_H
