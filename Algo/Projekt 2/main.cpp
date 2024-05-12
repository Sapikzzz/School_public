#include <iostream>
#include <vector>
#include "readFile.h"
#include "movie.h"
#include "quicksort.h"
#include <fstream>

int main() {
    std::vector<Movie> movies;
    readFile("projekt2_dane.csv", movies, 10000);
    quicksort(movies, 0, movies.size() - 1);
    std::cout << "Sorted movies by rating:" << std::endl;
    for (const auto &movie : movies) {
        std::cout << movie.title << " " << movie.rating << std::endl;
    }
    return 0;
}
