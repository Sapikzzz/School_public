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
    int amount = 1000000;
    std::vector<Movie> movies_quick, movies_bucket, movies_merge;
    readFile("projekt2_dane.csv", movies_quick, amount);
    readFile("projekt2_dane.csv", movies_bucket, amount);
    readFile("projekt2_dane.csv", movies_merge, amount);
    //quicksort(movies, 0, movies.size() - 1);
    //bucketsort(movies);
    //mergesort(movies, 0, movies.size() - 1);

    test_quick(movies_quick);
    test_bucket(movies_bucket);
    test_merge(movies_merge);

    //
    // std::cout << "Sorted movies by rating:" << std::endl;
    // for (const auto &movie : movies) {
    //     std::cout << movie.title << " " << movie.rating << std::endl;
    // }
    return 0;
}
