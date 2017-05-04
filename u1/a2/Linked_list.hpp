#include <string>
class Linked_list{
private:
    std::string string;
    Linked_list* nextNode = nullptr;
public:
    Linked_list(std::string input);
    std::string get();
    void set(std::string input);
    Linked_list* next();
    Linked_list* insert_at_index(unsigned int index, Linked_list *node);
    Linked_list* remove_at_index(unsigned int index);
};