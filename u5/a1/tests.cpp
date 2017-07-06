#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "string_hash.hpp"
#include "Hash_table.hpp"

using namespace std;

TEST_CASE("Hash: \"Power Rangers Dino Thunder\" == 125")
 {
 std::string s = "Power Rangers Dino Thunder";
 unsigned char result = 125;
  REQUIRE(string_hash(s) == result);
 }

TEST_CASE("Hash: \"Teenage Mutant Ninja Turtles\" == 145")
 {
 std::string s = "Teenage Mutant Ninja Turtles";
 unsigned char result = 145;
  REQUIRE(string_hash(s) == result);
 }


TEST_CASE("Hashtable: get/put")
 {
 Hash_table t;
 std::string s = "Teenage Mutant Ninja Turtles";
 int in = 9;

  t.put(s, in);

 int out = t.get(s);
  REQUIRE(in == out);
 }

