//
// Created by Jakub Sap on 11/05/2024.
//

#include "readFile.h"
#include "movie.h"
#include <fstream>
#include <iostream>
#include <sstream>

void readFile(std::string filename, std::vector<Movie> &movies, int amount) {
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
    while(std::getline(file, line) && amount-- > 0) {
        std::stringstream tmp(line);
        std::string index, title, rating;
        std::getline(tmp, index, ',');
        std::getline(tmp, title, ',');

        while(title.front() == '"') {
            std::string tmpName;
            if(title.back() == '"') {
                break;
            }
            std::getline(tmp, tmpName, ',');
            title += tmpName;
        }

        std::getline(tmp, rating, ',');
        if(!rating.empty()) {
            movies.push_back({title, std::stoi(rating)});
        }
    }

    file.close();
    return;
}
