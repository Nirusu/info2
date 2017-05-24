#include "levenshtein.hpp"
#include <algorithm> // use C++11 std::min function so we can compare three items in one function call.
#include <iostream>

int minimal (int *D, std::string *original , std::string *katze , int i, int j) {
    // get string length of katze to get the offset of the two-dimensional array hack
    int lengthKatze = katze->length();
    // let's save some values for more readability.
    // +1 because Levenshtein has a field which doesn't map to a character of both strings, so we pretty much always have an offset of 1
    int D_i1_j1 = D[(i-1)*(lengthKatze + 1) + (j-1)];
    int D_i1_j = D[(i-1)*(lengthKatze + 1) + (j)];
    int D_i_j1 = D[(i)*(lengthKatze + 1) + (j-1)];
    // check if the +0 condition matches. If so, the D_(i-1),(j-1) + 1 can't be smaller than D_(i-1),(j-1). If not, we don't need to consider it.
    // either way, this means we only to check the minimum out of three values instead of four.
    if ((*original)[i-1] == (*katze)[j-1])
        return std::min({D_i1_j1, D_i1_j + 1, D_i_j1 + 1});
    else
        return std::min({D_i1_j1 + 1, D_i1_j +1, D_i_j1 + 1});
}

int levenshtein_distance (std::string original , std::string katze) {
    int lengthOriginal = original.length();
    int lengthKatze = katze.length();
    // initialize our hacky two-in-one-dimensional array. +1 because entry (0,0) in the matrix belongs to neither words but the algorithm requires it.
    int *D = new int[(lengthOriginal + 1) * (lengthKatze + 1)];
    D[0] = 0;
    for (int j = 1; j <= lengthKatze; j++) // x-coordinate contains the second word. We have to do this at this point just for the x-coordinate part because later this loop gets called more than one time, which would overwrite over results from the algorithm.
        D[j] = j;
    // Time for magic
    for (int i = 1; i <= lengthOriginal; i++) {
        D[i * (lengthKatze + 1)] = i; // fake y-coordinate. Pretty messy, to be honest.
        for (int j = 1; j <= lengthKatze; j++) {
            D[i * (lengthKatze + 1) + j] = minimal(D, &original, &katze, i, j);
        }
    }
    // save return value, because we want to delete the array
    int returnValue = D[lengthOriginal * (lengthKatze + 1) + lengthKatze];
    // delete array to avoid potential memory leak
    delete[] D;
    return returnValue;
}