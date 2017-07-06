#include "Hash_table.hpp"

Hash_table::Hash_table()
{
    for (int i = 0; i < 256; i++)
    {
        ratings.push_back(-1); // use push_back instead of insert because it's more efficient for array filling
    }
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