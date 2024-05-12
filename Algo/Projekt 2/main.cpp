#include <iostream>
#include <vector>
#include "readFile.h"
#include "movie.h"

int main() {
    std::vector<Movie> movies;
    readFile("projekt2_dane.csv", movies);
    return 0;
}
