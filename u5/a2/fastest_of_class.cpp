#include "fastest_of_class.hpp"

std::vector<Spaceship> fastest_of_class(std::vector<Spaceship> fleet)
{
    std::vector<Spaceship> result; // the fixed fleet list we want to return
    for (int i=0; i<fleet.size(); i++) // for every item in the original fleet list...
    {
        if (result.empty() || !(result.back() == fleet[i]))
        {
            int index_of_fastest = binary_search_upper(fleet, fleet[i]); // get the index of the fastest ship of the class
            result.push_back(fleet[index_of_fastest]); // add it to the fixed fleet list
        }       
    }
    return result; // return the fixed list
}