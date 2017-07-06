#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__

#include <vector>
#include <string>
#include "string_hash.hpp"

class Hash_table {

private:
    std::vector<int> ratings;
public:
    Hash_table();
    void put(std::string title, int value);
    int get(std::string title);
};

#endif
