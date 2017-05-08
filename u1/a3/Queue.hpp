#include "../a2/Linked_list.hpp"
#include <string>

class Queue {
private:
    Linked_list* node = nullptr;
public:
    void push(std::string string);
    std::string pop();
    bool has_next();
};