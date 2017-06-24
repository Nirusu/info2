#include "reverse_quick_sort.hpp"

// without shuffling

void reverse_quick_sort(std::vector<Orange> *oranges, int left, int right)
{
    int i = left, j = right;
    int pivot = (left + right) / 2; // use middle as pivot
    // partition
    while (i <= j)
    {
        /* explanation of reverse quick sort:
         * instead of searching for an element from the left side which is greater than the pivot value
         * and searching for an element from the right side which is less than the pivot value,
         * we search the left side for an element which is smaller than the pivot value
         * and search the right side for an element which is bigger than the pivot element.
         * If both our searches end, we swap the found oranges and recursively call this function again with adjusted boundaries.
         */
        while ((*oranges)[pivot] < (*oranges)[i]) // bracketed pointers needed because we want to access the Orange objects from inside the vector
            i++;
        while ((*oranges)[j] < (*oranges)[pivot])
            j--;
        // swap
        if (i <= j)
        {
            Orange tmp = (*oranges)[i]; // tmp needed because otherwise we can't access one value anymore because we've overwritten it at that point
            (*oranges)[i] = (*oranges)[j];
            (*oranges)[j] = tmp;
            // increase/decrease counters for next recursive call so we're not stuck
            i++;
            j--;
        }
        // recursion
        if (left < j)
            reverse_quick_sort(oranges, left, j);
        if (i < right)
            reverse_quick_sort(oranges, i, right);
    }
}