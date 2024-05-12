//
// Created by Jakub Sap on 12/05/2024.
//

#include "bucketsort.h"

void bucketsort(std::vector<Movie> &movies) {
    int maxRating = 10; // max rating is 10, depending on that we create 11 buckets for rating 0-10
    std::vector<std::vector<Movie>> buckets(maxRating + 1); // creating buckets
    for (const auto &movie : movies) { // putting movies into buckets by pushing every movie into bucket
        buckets[movie.rating].push_back(movie); // with its own rating, if rating is 2 we do buckets[2].push_back(movie)
    }
    movies.clear(); // clearing movies vector for inserting sorted movies
    for (int i = 0; i <= 10; i++) { // iterating through buckets
        for (const auto &movie : buckets[i]) {  // iterating through every movie in bucket
            movies.push_back(movie);
        }
    }
}
