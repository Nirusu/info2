#include "fastest_of_class.hpp"

std::vector<Spaceship> fastest_of_class(std::vector<Spaceship> fleet)
{
    std::vector<Spaceship> result; // the fixed fleet list we want to return
    for (int i=0; i<fleet.size(); i++) // for every item in the original fleet list...
    {
        if (result.empty() || !(result.back() == fleet[i])) // don't want to add duplicate entries. check for emptiness because "calling back() on an empty container causes undefined behavior"
        {
            int index_of_fastest = binary_search_upper(fleet, fleet[i]); // get the index of the fastest ship of the class
            result.push_back(fleet[index_of_fastest]); // use the index to add the entry to the new, fleet list without duplicates
        }       
    }
    return result; // return the fixed list
}