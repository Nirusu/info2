#include "Queue.hpp"

void Queue::push(std::string string) {
    if (node == nullptr)
    node = new Linked_list(string);
    else {
        Linked_list* lastNode = node;
        unsigned int counter = 1;
        while (lastNode->next() != nullptr) {
            lastNode = lastNode->next();
            counter++;
        }
        node->insert_at_index(counter, new Linked_list(string));
    }
}
std::string Queue::pop() {
    std::string returnString = node->get();
    Linked_list* toDelete = node;
    node = node->next();
    delete toDelete;
    return returnString;
}
bool Queue::has_next() {
    if (node != nullptr)
        return true;
    else
        return false;
}