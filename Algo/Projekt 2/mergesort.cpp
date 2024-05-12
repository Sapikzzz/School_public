//
// Created by Jakub Sap on 13/05/2024.
//

#include "mergesort.h"
#include <vector>
#include "movie.h"

void merge(std::vector<Movie> &movies, int low, int mid, int high) {
    int left_size = mid - low + 1;
    int right_size = high - mid;

    std::vector<Movie> L(left_size), R(right_size);

    for (int i = 0; i < left_size; i++) {
        L[i] = movies[low + i];
    }
    for (int j = 0; j < right_size; j++) {
        R[j] = movies[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

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

void mergesort(std::vector<Movie> &movies, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergesort(movies, low, mid);
        mergesort(movies, mid + 1, high);

        merge(movies, low, mid, high);
    }
}
