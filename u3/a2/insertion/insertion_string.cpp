#include "insertion_string.hpp"

#include <iostream>

std::vector<std::string> insertion_sort (std::vector<std::string> strings, char c)
{

	// use the size() function to get the number of strings from the vector
	int number_of_strings = strings.size();

	// insertion sort
    int j; // required if we need to swap multiple times
    std::string tmp; // temporarily save a string for the swapping operation
    for (int i = 1; i < number_of_strings; i++) // assume first element is sorted, we don't need to start at 0 because with insertion sort we check the current item with the previous one
    {
        j = i;
        // if the current element is smaller than the previous one, move it to the left until it's bigger than the one on the left
        while (j > 0 && compare_by_frequency(strings[j], strings[j-1], c))
        {
            // swap strings
            tmp = strings[j];
            strings[j] = strings[j-1];
            strings[j-1] = tmp;
            // reduce counter
            j--;
        }
    }
	// this should be the sorted vector of strings
	return strings;
}

int compare_by_frequency(std::string a, std::string b, char c)
{

	// these will carry the counts of chars in both strings
	int counter_a = 0;
	int counter_b = 0;

    // two separate loops for counting because the length of a doesn't necessarily need to match the length of b
    for (int i = 0 ; i < a.length(); i++)
    {
        if (a[i] == c)
            counter_a++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == c)
            counter_b++;
    }
	// return a value that represents the comparison result
	if (counter_a < counter_b)
		return 1;
	else
		return 0;
}
