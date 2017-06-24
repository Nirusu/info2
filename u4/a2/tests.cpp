#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Binary_heap.hpp"

using namespace std;

TEST_CASE("Comparing Apples")
 {
 Apple great(2000, 1000);
 Apple bad(1000, 3000);
   REQUIRE(bad < great);
   REQUIRE((great < bad) == false);
 }


TEST_CASE("Binary Heap")
 {
 Apple great(2000, 1000);
 Apple not_impressed(2000, 500);
 Apple bad(1000, 3000);

 Binary_heap h;
  h.insert(not_impressed);
  h.insert(great);
  h.insert(bad);

   REQUIRE(h.is_empty() == false);
 Apple first = h.del_max();
   REQUIRE(first.sweetness == great.sweetness);
   REQUIRE(first.juicyness == great.juicyness);

   REQUIRE(h.is_empty() == false);
 Apple second = h.del_max();
   REQUIRE(second.sweetness == not_impressed.sweetness);
   REQUIRE(second.juicyness == not_impressed.juicyness);

   REQUIRE(h.is_empty() == false);
 Apple third = h.del_max();
   REQUIRE(third.sweetness == bad.sweetness);
   REQUIRE(third.juicyness == bad.juicyness);

   REQUIRE(h.is_empty() == true);
 }
