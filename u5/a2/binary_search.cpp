#include "binary_search.hpp"

int binary_search_upper(std::vector<Spaceship> ships, Spaceship ship)
{
    int left = 0;
    int right = ships.size() - 1;
    int mid;

    /* modified binary search:
     *
     * instead of directly searing for the highest item,
     * we search for the start of the a ship class in the vector
     */
    while (left < right) // abort search if we're done with searching
    {
        mid = (left + right) / 2;
        // if we're in the same class, use this as our middle for searching
        if (ships[mid] == ship)
            right = mid;
        else
            // if not, we're looking for a faster ship, so we set the lower boundary to the ship next to our pivot
            left = mid + 1;
    }
    // now that we know the starting point, iterate through until we hit the last ship of the same class, which is the fastest because our input is sorted.
    while (left + 1 < ships.size() && ships[left] == ships[left+1])
    {
        left++;
    }
    // return the index
    return left;
}