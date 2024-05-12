//
// Created by Jakub Sap on 11/05/2024.
//

#include "quicksort.h"
// (vector for movies, left == 0, right == movies.size() - 1)
int partition(std::vector<Movie> &movies, int low, int high) {
    int i = low;
    int j = high;
    int pivot = movies[(low + high) / 2].rating;
    while (i <= j) {
        while (movies[i].rating < pivot) {
            i++;
        }
        while (movies[j].rating > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(movies[i], movies[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(std::vector<Movie> &movies, int low, int high) {
    int index = partition(movies, low, high);
    if (low < index - 1) {
        quicksort(movies, low, index - 1);
    }
    if (index < high) {
        quicksort(movies, index, high);
    }
}




