#include <sstream>
#include <fstream>
#include "level.h"

level parse_level(const std::string& level_data) {
    size_t rows = 0, columns = 0;
    std::vector<char> data;

    std::istringstream iss(level_data);
    std::string line;
    while (std::getline(iss, line, '|')) {
        rows++;
        columns = line.size();
        for (char c : line) {
            data.push_back(c);
        }
    }

    return level(rows, columns, data.data());
}

std::vector<level> parse_levels_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::vector<level> levels;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        if (line.substr(0, 2) == "; ") {
            std::getline(file, line);
            std::string level_data;
            while (std::getline(file, line) && !line.empty()) {
                level_data += line;
            }
            levels.push_back(parse_level(level_data));
        }
    }

    return levels;
}
