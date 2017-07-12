#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Spaceship.hpp"
#include "binary_search.hpp"
#include "fastest_of_class.hpp"

using namespace std;

TEST_CASE("Spaceship: Class Speed 510 == Class Speed 550")
 {
 Spaceship a("Enterprise", 510);
 Spaceship b("Voyager", 550);
  REQUIRE((a == b) == true);
 }


TEST_CASE("Spaceship: Class Speed 510 != Class Speed 750")
 {
 Spaceship a("Enterprise", 510);
 Spaceship c("Millennium Falcon", 750);
  REQUIRE((a == c) == false);
 }


TEST_CASE("Binary Search -- Same Class")
 {
 Spaceship a("Enterprise", 510);
 Spaceship b("Voyager", 550);
 vector<Spaceship> ships = {a, b};
 
 int index = binary_search_upper(ships, a);
  REQUIRE(index == 1);

  index = binary_search_upper(ships, b);
  REQUIRE(index == 1);
 }



TEST_CASE("Fastest of Class")
 {
 Spaceship a("Enterprise", 510);
 vector<Spaceship> ships = {a};
 
 vector<Spaceship> result = fastest_of_class(ships);
  REQUIRE(result.size() == 1);
 }