#include "Linear_probing_hash_table.hpp"

Linear_probing_hash_table::Linear_probing_hash_table()
{
	table.resize(256, nullptr);
}


int Linear_probing_hash_table::get_index(unsigned char hash, std::string key)
{
	int index = hash;
	while (table[index] != nullptr)
	{
		if (table[index]->key == key)
			return index;
		index = (index + 1) % 256;
		// TODO: Was returnen, wenn wir nichts finden?
		if (index == hash) // abort if our search is exhausted
		{
			return -1;
		}
	}
	return -1; // abort if we hit a nullptr
}


void Linear_probing_hash_table::insert(Entry *e)
{
	// insertion of a new entry to the table
	int index = e->hash;
	while (table[index] != nullptr)
	{
		if (e->key == table[index]->key) // if we find the same key, overwrite the entry
		{
			table[index] = e;
			return;
		}
		index = (index + 1) % 256;
	}
	table[index] = e;
}     


void Linear_probing_hash_table::remove(unsigned char hash, std::string key)
{
	int index = hash;
	while (table[index]->key != key) // don't iterate over 256
	{
		index++; // we're ignoring the wrap-around here
		if (index >= 256) // abort, if index goes over 256 to avoid out of bounds
		{
			return;
		}
	}
	if (table[index+1] == nullptr)
	{
		table[index] = nullptr;
	}
	else
	{
		// TODO: Third case
	}
}

