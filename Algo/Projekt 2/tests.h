//
// Created by Jakub Sap on 13/05/2024.
//

#ifndef TESTS_H
#define TESTS_H

#include <vector>
#include "movie.h"


double mean(std::vector<Movie> &movies);

double median(std::vector<Movie> &movies);

void test_quick(std::vector<Movie> movies);

void test_bucket(std::vector<Movie> movies);

void test_merge(std::vector<Movie> movies);

bool is_sorted(std::vector<Movie> &movies);


#endif //TESTS_H
