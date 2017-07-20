#include "Linear_probing_hash_table.hpp"

Linear_probing_hash_table::Linear_probing_hash_table()
{
	table.resize(256, nullptr);
}


int Linear_probing_hash_table::get_index(unsigned char hash, std::string key)
{
	int index = hash;
	// abort if we hit a nullptr
	// all other cases are handled inside the loop
	while (table[index] != nullptr)
	{
		if (table[index]->key == key) // if the key of the entry matches we key we're searching for, we found the index...
			return index; // ... so let's return it.
		index = (index + 1) % 256; // if we haven't found our key, do linear probing with wrap-around
		if (index == hash) // abort if our search is exhausted
		{
			return -1;
		}
	}
	return -1; // abort if we hit a nullptr
}


void Linear_probing_hash_table::insert(Entry *e)
{
	int index = e->hash;
	// if the correct entry is free, this loop isn't executed. If the correct entry is blocked, this loop does the linear-probing stuff.
	while (table[index] != nullptr)
	{
		if (e->key == table[index]->key) // if we find the same key, overwrite the entry
		{
			table[index] = e;
			return;
		}
		index = (index + 1) % 256; // linear probing
	}
	// if we found an empty spot, insert the entry.
	table[index] = e;
}     


void Linear_probing_hash_table::remove(unsigned char hash, std::string key)
{
	int index = hash;
	// Step 1: find element
	while (table[index]->key != key) // don't iterate over 256
	{
		index++; // we're ignoring the wrap-around here
		if (index >= 256) // abort, if index goes over 256 to avoid out of bounds
		{
			return;
		}
	}
	// Step 2a): deletion with next cell empty
	if (table[index+1] == nullptr)
	{
		table[index] = nullptr;
	}
	// Step 2a) + 2b): deletion with next cell empty (first if) or NOT empty (second if)
		// find next element which is at an irregular spot
		for (int i=index+1; i < 256; i++) // abort if we reach the end of the table, no wrap-around
		{
			// if we hit an empty entry...
			if (table[i] == nullptr) {
				table[index] = nullptr; // delete our entry we meant to delete
				break; // stop the search
			}
			// else find the next entry where the hash doesn't match the index, because that means the entry has been moved by linear probing
			if (i != table[i]->hash)
			{
				table[index] = table[i]; // move next-found linear probed element to our empty spot
				table[i] = nullptr; // clear the spot
				break; // stop the search
			}
		}
}

