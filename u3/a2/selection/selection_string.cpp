#include "selection_string.hpp"

#include <iostream>

std::vector<std::string> selection_sort (std::vector<std::string> strings, char c)
{
	// use the size() function to get the number of strings from the vector
	int number_of_strings = strings.size();
	int min; // use int - easier to swap with the index rather than the objects themselves
	std::string tmp; // temporarily save string object for swapping operation
	for (int i = 0; i < number_of_strings; i++)
	{
		min = i;
		for (int j = i + 1; j < number_of_strings; j++)
		{
			if (compare_by_frequency(strings[j], strings[i], c))
			{
				min = j;
			}
		}
		// swap
		tmp = strings[i];
		strings[i] = strings[min];
		strings[min] = tmp;
	}
	return strings;
}

int compare_by_frequency(std::string a, std::string b, char c) // copy-pasted from insertion sort - this function hasn't been edited
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

