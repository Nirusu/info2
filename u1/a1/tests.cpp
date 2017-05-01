#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Simple_class.hpp"

TEST_CASE("Creating a Simple_class")
 {
 Simple_class s(123);
 }

TEST_CASE("Getter of Simple_class")
 {
 Simple_class s(123);
  REQUIRE(s.get() == 123);
 }

TEST_CASE("Setter of Simple_class")
 {
 Simple_class s(123);
  s.set(456);
  REQUIRE(s.get() == 456);
 }

