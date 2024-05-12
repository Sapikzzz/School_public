//
// Created by Jakub Sap on 11/05/2024.
//

#include "readFile.h"

#include <fstream>
#include <iostream>

void readFile(std::string filename, std::vector<Movie> &movies) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header
    // Read the file liny by line, every field is separated by a comma, first is index, second is title, third is rating
    // Example line: 1,The Shawshank Redemption,9.3
    // Filter out the index, and read the title and rating
    // There are lines withouth rating, skip them
    while (std::getline(file, line)) {
        std::string title;
        int rating;
        std::size_t pos = line.find(',');
        if (pos == std::string::npos) {
            std::cerr << "Invalid line: " << line << std::endl;
            continue;
        }
        title = line.substr(pos + 1);
        pos = title.find(',');
        if (pos == std::string::npos) {
            std::cerr << "Invalid line: " << line << std::endl;
            continue;
        }
        title = title.substr(0, pos);
        rating = std::stoi(line.substr(pos + 1));
        movies.push_back({title, rating});
    }
    return;
}
