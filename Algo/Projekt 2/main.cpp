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
    int amount = 10000;
    std::vector<Movie> movies_quick, movies_bucket, movies_merge;
    readFile("projekt2_dane.csv", movies_quick, amount);
    readFile("projekt2_dane.csv", movies_bucket, amount);
    readFile("projekt2_dane.csv", movies_merge, amount);

    test_quick(movies_quick);
    test_bucket(movies_bucket);
    test_merge(movies_merge);

    // quicksort(movies_quick, 0, movies_quick.size() - 1);
    // bucketsort(movies_bucket);
    // mergesort(movies_merge, 0, movies_merge.size() - 1);


    // std::cout << "Quick movies by rating:" << std::endl;
    // for (const auto &movie : movies_quick) {
    //     std::cout << movie.title << " " << movie.rating << std::endl;
    // }
    // std::cout << std::endl;
    //
    // std::cout << "Bucket movies by rating:" << std::endl;
    // for (const auto &movie : movies_bucket) {
    //     std::cout << movie.title << " " << movie.rating << std::endl;
    // }
    // std::cout << std::endl;
    //
    // std::cout << "Merge movies by rating:" << std::endl;
    // for (const auto &movie : movies_merge) {
    //     std::cout << movie.title << " " << movie.rating << std::endl;
    // }
    return 0;
}
