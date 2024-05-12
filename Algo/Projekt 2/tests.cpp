//
// Created by Jakub Sap on 13/05/2024.
//

#include "tests.h"

#include <iostream>
#include <vector>
#include "movie.h"
#include "quicksort.h"
#include "bucketsort.h"
#include "mergesort.h"
#include "readFile.h"
#include <chrono>

double mean(std::vector<Movie> &movies) {
    int sum;
    for(int i = 0; i < movies.size(); i++) {
        sum += movies[i].rating;
    }
    return sum / movies.size();
}

double median(std::vector<Movie> &movies) {
    if(movies.size() % 2 == 0) {
        return (movies[movies.size() / 2].rating + movies[movies.size() / 2 + 1].rating) / 2;
    } else {
        return movies[movies.size() / 2].rating;
    }
}

bool is_sorted(std::vector<Movie> &movies) {
    for(int i = 0; i < movies.size() - 1; i++) {
        if(movies[i].rating > movies[i + 1].rating) {
            return false;
        }
    }
    return true;
}

void test_time(std::vector<Movie> movies, int elements) {
    readFile("projekt2_dane.csv", movies, elements);
    auto start_q = std::chrono::high_resolution_clock::now();
    quicksort(movies , 0, movies.size() - 1);
    auto end_q = std::chrono::high_resolution_clock::now();
    std::cout << "Quicksort took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_q - start_q).count() << "ms";
    if(is_sorted(movies)) {
        std::cout << "  Sorted";
    } else {
        std::cout << "  Not sorted";
    }
    std::cout << "  Srednia: " << mean(movies);
    std::cout << "  Mediana: " << median(movies);

    std::cout << std::endl;

    readFile("projekt2_dane.csv", movies, elements);
    auto start_b = std::chrono::high_resolution_clock::now();
    bucketsort(movies);
    auto end_b = std::chrono::high_resolution_clock::now();
    std::cout << "Bucketsort took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_b - start_b).count() << "ms";
    if(is_sorted(movies)) {
        std::cout << "  Sorted";
    } else {
        std::cout << "  Not sorted";
    }
    std::cout << "  Srednia: " << mean(movies);
    std::cout << "  Mediana: " << median(movies);

    std::cout << std::endl;

    readFile("projekt2_dane.csv", movies, elements);
    auto start_m = std::chrono::high_resolution_clock::now();
    mergesort(movies, 0, movies.size() - 1);
    auto end_m = std::chrono::high_resolution_clock::now();
    std::cout << "Mergesort took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_m - start_m).count() << "ms";
    if(is_sorted(movies)) {
        std::cout << "  Sorted";
    } else {
        std::cout << "  Not sorted";
    }
    std::cout << "  Srednia: " << mean(movies) ;
    std::cout << "  Mediana: " << median(movies);

    std::cout << std::endl;
}
