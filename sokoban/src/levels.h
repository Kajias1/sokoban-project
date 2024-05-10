#ifndef LEVELS_H
#define LEVELS_H

#include "globals.h"
#include "player_handler.h"
#include "graphics.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <cstddef>

void parse_levels() {
    std::ifstream infile("data/levels.sl");
    std::string line;
    std::vector<std::string> parsed_level = { };
    int parsed_level_index = 0;
    while (std::getline(infile, line)) {
        for (char c : line) {
            if (c == ';') {
                size_t rows = parsed_level[0].size();
                size_t columns = parsed_level.size();
                for (const std::string& str : parsed_level) {
                    if (rows <= str.size()) rows = str.size();
                }
                size_t n = 0;
                class level new_level = {columns, rows, new char[rows * columns]};
                for (std::string& str : parsed_level) {
                    std::string filled_string = str;
                    for (int i = 0; i < rows - str.size(); i++) {
                        filled_string.push_back(' ');
                    }
                    for (char element : filled_string) {
                        new_level.getData()[n] = element;
                        n++;
                    }
                }

                LEVELS.push_back(new_level);
                parsed_level.clear();
                parsed_level_index++;
                continue;
            }
        }
        std::istringstream iss(line);
        std::string level_line;
        for (int i = 0; i < line.size(); i++) {
            int next_char_in = 1;
            if (isdigit(line[i])) {
                int count = line[i] - '0';
                if (isdigit(line[i + 1]) && i + 1 < line.size()) {
                    count = (line[i] - '0') * 10 + (line[i + 1] - '0');
                    next_char_in = 2;
                }
                for (int j = 0; j < count; j++) {
                    level_line.push_back(line[i + next_char_in]);
                }
                i += next_char_in;
            } else if (line[i] != '|' && line[i] != ';') {
                level_line.push_back(line[i]);
            } else if (line[i] == '|' || line[i] == line[line.size() - 1]) {
                parsed_level.push_back(level_line);
                level_line.clear();
            }
            if (i == line.size() - 1) {
                parsed_level.push_back(level_line);
                level_line.clear();
            };
        }
    }
}

void load_next_level() {
    ++level_index;
    if (level_index >= LEVELS.size()) {
        level_index = 0;
        game_state = VICTORY_STATE;
        create_victory_menu_background();
    }

    level.setRows(LEVELS[level_index].getRows());
    level.setColumns(LEVELS[level_index].getColumns());
    level.setData(new char[level.getRows() * level.getColumns()]);

    for (size_t row = 0; row < level.getRows(); ++row) {
        for (size_t column = 0; column < level.getColumns(); ++column) {
            char cell = LEVELS[level_index].getData()[row * level.getColumns() + column];
            if (cell == PLAYER) {
                level.setCell(row, column, FLOOR);
                spawn_player(row, column);
            } else if (cell == PLAYER_ON_GOAL) {
                level.setCell(row, column, GOAL);
                spawn_player(row, column);
            } else {
                level.setCell(row, column, cell);
            }
        }
    }

    derive_graphics_metrics_from_loaded_level();
}

void unload_level() {
    level.setRows(0);
    level.setColumns(0);

    delete[] level.getData();
    level.setData(nullptr);
}

#endif // LEVELS_H
