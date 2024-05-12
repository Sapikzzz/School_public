#include <iostream>
#include <vector>
#include "readFile.h"
#include "movie.h"
#include "quicksort.h"
#include "bucketsort.h"
#include "mergesort.h"
#include "tests.h"
#include <fstream>
#include <chrono>

int main() {
    std::vector<Movie> movies;
    // readFile("projekt2_dane.csv", movies, 100);
    //quicksort(movies, 0, movies.size() - 1);
    //bucketsort(movies);
    // mergesort(movies, 0, movies.size() - 1);
    test_time(movies, 10000);
    test_time(movies, 100000);
    test_time(movies, 500000);
    test_time(movies, 1000000);


    // std::cout << "Sorted movies by rating:" << std::endl;
    // for (const auto &movie : movies) {
    //     std::cout << movie.title << " " << movie.rating << std::endl;
    // }
    return 0;
}
