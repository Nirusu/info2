#include "Linked_list.hpp"

Linked_list::Linked_list(std::string input) {
    string = input;
}
std::string Linked_list::get() {
    return string;
}
void Linked_list::set(std::string input) {
    string = input;
}
Linked_list* Linked_list::next() {
    return nextNode;
}
Linked_list* Linked_list::insert_at_index(unsigned int index, Linked_list *node) {
    Linked_list* start = this;
    // check if the node to insert isn't another list but rather a single note
    if (node->nextNode != nullptr)
    {
        return NULL;
    }
    // special cases for index == 0 and index == 1 because otherwise we get in trouble with the for loop
    if (index == 0) {
        start = node;
        start->nextNode = this;
    }
    else if (index == 1) {
        node->nextNode = nextNode;
        nextNode = node;
    }
    else {
        Linked_list* worker = this;
        // iterate through the nodes right before we point we should insert the new node
        for (int i=0; i<index; i++)
        {
            // check to avoid traversing to a non-existing node
            if (worker->nextNode != nullptr)
                worker = worker->nextNode;
            else
                return NULL;
        }
        // set the old "nextNode" into the node we want to insert to avoid loss of data
        node->nextNode = worker->nextNode;
        // replace the nextNode of the node right BEFORE the index with the new node, which also contains our old "nextNode"
        worker->nextNode = node;
    }
    return start;
}

Linked_list* Linked_list::remove_at_index(unsigned int index) {
    Linked_list* start = this;
    Linked_list* beforeToDelete = this;
    // beforeToDelete required so that we can work with the node before last
    Linked_list* toDelete = nullptr;
    // special cases for index == 0 and index == 1 because otherwise we get in trouble with the for loop
    if (index == 0) {
        start = start->nextNode;
        delete this;
    }
    else if (index == 1) {
        if (this->nextNode != nullptr)
            toDelete = this->nextNode;
        else
            return NULL;
        // remove the pointer in the linked list...
        this->nextNode = toDelete->nextNode;
        // .. and free the memory
        delete toDelete;
    }
    else {
        // check to avoid traversing to a non-existing node
        for (int i=0; i<index; i++)
        {
            if (beforeToDelete->nextNode != nullptr)
                beforeToDelete = beforeToDelete->nextNode;
            else
                return NULL;
        }
        // same check as in the loop but now outside because now deleteNode comes into play and we don't want to lose beforeToDelete
        // the idea: toDelete is the one we want to delete. We save the "nextNode" node from it and assign it to the index where toDelete was placed
        if (beforeToDelete->nextNode != nullptr)
            toDelete = beforeToDelete->nextNode;
        else
            return NULL;
        // remove the pointer in the linked list...
        beforeToDelete->nextNode = toDelete->nextNode;
        // and free the memory
       delete toDelete;
    }
    return start;
}