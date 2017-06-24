#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "reverse_quick_sort.hpp"

using namespace std;

TEST_CASE("Comparing Oranges")
 {
 Orange great(9000, 5000);
 Orange bad(5, 6000);
   REQUIRE(bad < great);
   REQUIRE((great < bad) == false);
 }


TEST_CASE("Sorting Oranges")
 {
 Orange great(9000, 5000);
 Orange not_impressed(9000, 4);
 Orange bad(5, 6000);

 std::vector<Orange> oranges;
  oranges.push_back(not_impressed);
  oranges.push_back(bad);
  oranges.push_back(great);

  reverse_quick_sort(&oranges, 0, oranges.size()-1);

   REQUIRE(oranges[0].sweetness == 9000);
   REQUIRE(oranges[0].juicyness == 5000);

   REQUIRE(oranges[1].sweetness == 9000);
   REQUIRE(oranges[1].juicyness == 4);

   REQUIRE(oranges[2].sweetness == 5);
   REQUIRE(oranges[2].juicyness == 6000);
 }
