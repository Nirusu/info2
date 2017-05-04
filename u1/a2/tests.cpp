#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../a1/catch.hpp"

#include "Linked_list.hpp"


TEST_CASE("Creation")
 {
 std::string value = "x";
 Linked_list *head = new Linked_list(value);
 }


TEST_CASE("Getting an attribute")
 {
 Linked_list *head = new Linked_list("x");
 std::string str = head->get();
 }


TEST_CASE("Getting the next node")
 {
 Linked_list *head = new Linked_list("x");
 Linked_list *next = head->next();
 }


TEST_CASE("Setting an attribute")
 {
 Linked_list *head = new Linked_list("x");
  head->set("a");
 }


TEST_CASE("Insertion")
 {
 Linked_list *a = new Linked_list("a");
 Linked_list *b = new Linked_list("b");
 Linked_list *c = new Linked_list("c");

 Linked_list *start;
  start = b->insert_at_index(1, c);
  start = b->insert_at_index(0, a);
 }


TEST_CASE("Removal")
 {
 Linked_list *a = new Linked_list("a");
 Linked_list *start = a->remove_at_index(0);
 }


TEST_CASE("Removal - later")
 {
 Linked_list *a = new Linked_list("a");
 Linked_list *b = new Linked_list("b");
  a->insert_at_index(1, b);

 Linked_list *start = a->remove_at_index(1);
 }

