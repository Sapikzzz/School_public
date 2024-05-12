#include <iostream>
#include <vector>
#include "readFile.h"
#include "movie.h"
#include "quicksort.h"
#include "bucketsort.h"
#include "mergesort.h"
#include <fstream>
#include <chrono>

int main() {
    std::vector<Movie> movies;
    readFile("projekt2_dane.csv", movies, 500000);
    auto start = std::chrono::high_resolution_clock::now();
    //quicksort(movies, 0, movies.size() - 1);
    //bucketsort(movies);
    mergesort(movies, 0, movies.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Sorting took: " << diff.count() << "s" << std::endl;
    // std::cout << "Sorted movies by rating:" << std::endl;
    // for (const auto &movie : movies) {
    //     std::cout << movie.title << " " << movie.rating << std::endl;
    // }
    return 0;
}
