//
// Created by Jakub Sap on 13/05/2024.
//

#include "mergesort.h"
#include <vector>
#include "movie.h"

void merge(std::vector<Movie> &movies, int left, int middle, int right) {
    int left_size = middle - left + 1; // size of left subarray
    int right_size = right - middle;    // size of right subarray

    std::vector<Movie> L(left_size);  // Creating temporary vectors
    std::vector<Movie> R(right_size);

    // Copying data to temporary vectors L[] and R[]
    for (int i = 0; i < left_size; i++) {
        L[i] = movies[left + i];
    }
    for (int j = 0; j < right_size; j++) {
        R[j] = movies[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = 0;
    // Merging the temporary vectors back into movies[]
    while (i < left_size && j < right_size) {
        if (L[i].rating <= R[j].rating) {
            movies[k] = L[i];
            i++;
        } else {
            movies[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        movies[k] = L[i];
        i++;
        k++;
    }

    while (j < right_size) {
        movies[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(std::vector<Movie> &movies, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergesort(movies, left, middle);
        mergesort(movies, middle + 1, right);

        merge(movies, left, middle, right);
    }
}