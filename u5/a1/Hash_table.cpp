#include "Hash_table.hpp"

Hash_table::Hash_table()
{
	ratings.resize(256, -1); // expand array to 256 entries (0-255), use -1 as dummy entries
}

void Hash_table::put(std::string title, int value)
{
    int index = string_hash(title); // generate index-hash
    ratings[index] = value;         // save value
}

int Hash_table::get(std::string title)
{
    int index = string_hash(title); // generate index-hash
    return ratings[index];          // return value
}