#include "buffy_vampire_slayer.hpp"
#include <iostream>

// take all powers and count those of the zombies and vampires
// we return a struct that carries the counter of both creature types
creature_counts count_creatures(int N, int creature_powers[])
{
	// this will be our return element
	creature_counts counts;

	// these will carry the overall powers of both creature types
	int sum_zombie_powers = 0;
	int sum_vampire_powers = 0;

	int count_zombies = 0;
	int count_vampires = 0;

	// iterate values in array, check if even or odd number and raise according counters
	for (int i=0; i<N; i++)
	{
		if (creature_powers[i] % 2 == 0) // use mod 2 to check if we have an even or odd number
		{
			count_zombies++;
			sum_zombie_powers += creature_powers[i];
		}
		else
		{
			count_vampires++;
			sum_vampire_powers += creature_powers[i];
		}
	}

	// your implementation should compute the power sums and counts of both creature types
	// use the following to initialize the struct with the computed values
	counts.zombie_count = count_zombies;
	counts.vampire_count = count_vampires;

	counts.zombie_sum = sum_zombie_powers;
	counts.vampire_sum = sum_vampire_powers;

	return counts;
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// take all monsters and sort them
int *sort(int *elements, int length)
{
	// generate the creature counts because we need them for our sorting loops
	creature_counts counts = count_creatures(length, elements);
	// you can treat it just like a normal array, indexing like element[i], ...
	// create array with zombies and vampire powers separated, so it's easier to sort. This requires us to run through elements once to filter them out.
	int zombies[counts.zombie_count];
	int vampires[counts.vampire_count];
	// need two helper variables to save the next free position in the zombie and vampire arrays.
	int zombie_array_index = 0;
	int vampire_array_index = 0;
	// fill zombie and vampire subarrays
	for (int i=0; i<length; i++)
	{
		if (elements[i] % 2 == 0)
		{
			zombies[zombie_array_index] = elements[i];
			zombie_array_index++;
		}
		else
		{
			vampires[vampire_array_index] = elements[i];
			vampire_array_index++;
		}
	}
	// selection sort - zombie array
	int *min;
	for (int i=0; i<counts.zombie_count-1; i++) // don't need to check the last element because we already set every smaller value to the left
	{
		min = &zombies[i]; // pivot element on the left side where we want to set the lowest item
		for (int j=i + 1; j<counts.zombie_count; j++) // +1 because we don't need to check if the pivot element is smaller than itself for obvious reasons
		{
			if (zombies[j] < *min)
			{
				min = &zombies[j];
			}
		}
		swap(&zombies[i], min);
	}
	// selection sort - vampire array
	for (int i=0; i<counts.vampire_count-1; i++) // don't need to check the last element because we already set every smaller value to the left
	{
		min = &vampires[i]; // pivot element on the left side where we want to set the lowest item
		for (int j=i + 1; j<counts.vampire_count; j++) // +1 because we don't need to check if the pivot element is smaller than itself for obvious reasons
		{
			if (vampires[j] < *min)
			{
				min = &vampires[j];
			}
		}
		swap(&vampires[i], min);
	}
	// merge subarrays back into elements
	for (int i=0; i<counts.zombie_count; i++)
	{
		elements[i] = zombies[i];
	}
	for (int i=0; i<counts.vampire_count; i++)
	{
		elements[i+counts.zombie_count] = vampires[i]; // use counts.zombie_count as offset
	}
	// return the pointer to the now sorted array
	return elements;
}

int *create_attack_plan(int N, int *elements, creature_counts counts)
{
	// take care of the indices, this part will be a bit tricky
	// use debug prints if your have trouble with correct indexing
	// example: std::cout << "elements[i] = " << elements[i] << std::endl;
	// create attack_plan with two more entries than the amount of powers because we need to add the sums for the zombies and the vampires

	int *attack_plan = new int[N+2];  // don't forget to free the allocated memory for the attack_plan if it isn't needed anymore, otherwise we're leaking precious memory!
	// put zombie powers into the attack plan
	for (int i=0; i < counts.zombie_count; i++)
	{
		attack_plan[i] = elements[i];
	}
	// put the sum of the zombie powers after the single zombie powers
	attack_plan[counts.zombie_count] = counts.zombie_sum;
	// now that we're done with the zombies, let's fill the attack_plan with the vampire powers...
	for (int i=counts.zombie_count; i<N+1; i++)
	{
		attack_plan[i+1] = elements[i];
	}
	// ... and put the sum of the vampire powers at the end of our attack plan
	attack_plan[N+1] = counts.vampire_sum;

	// DEBUG:
	/* for (int i=0; i<N+2; i++)
	{
		std::cout << attack_plan[i] << ", ";
	}
	std::cout << std::endl; */

	// return our fail-proof attack plan!!!
	return attack_plan;
}
