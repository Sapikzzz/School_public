//
// Created by Jakub Sap on 13/05/2024.
//

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include "movie.h"

void mergesort(std::vector<Movie> &movies, int left, int right);

void merge(std::vector<Movie> &movies, int left, int mid, int right);


#endif //MERGESORT_H
