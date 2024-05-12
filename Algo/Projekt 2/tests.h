//
// Created by Jakub Sap on 13/05/2024.
//

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <vector>
#include "movie.h"
#include "quicksort.h"
#include "bucketsort.h"
#include "mergesort.h"
#include "readFile.h"
#include <chrono>

double mean(std::vector<Movie> &movies);

double median(std::vector<Movie> &movies);

void test_time(std::vector<Movie> movies, int amount);

bool is_sorted(std::vector<Movie> &movies);

#endif //TESTS_H
