#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "levenshtein.hpp"

TEST_CASE("Signature for helper function")
 {
 std::string original = "Originalwort";
 std::string katze = "Katzenwort";

 int *D = new int[(original.size()+1) * (katze.size()+1)];
 int i = 1;
 int j = 0;

 int result = minimal(D, &original, &katze, i, j);
 }

TEST_CASE("Edit-distance function")
 {
 std::string original = "Originalwort";
 std::string katze = "Katzenwort";
 int result = levenshtein_distance(original, katze);
 }


TEST_CASE("Edit-example: cat -> cat")
 {
 std::string original = "cat";
 std::string katze = "cat";
 int result = levenshtein_distance(original, katze);
  REQUIRE(result == 0);
 }

TEST_CASE("Edit-example: hat -> cat")
 {
 std::string original = "hat";
 std::string katze = "cat";
 int result = levenshtein_distance(original, katze);
  REQUIRE(result == 1);
 }

TEST_CASE("Edit-example: had -> cat")
 {
 std::string original = "had";
 std::string katze = "cat";
 int result = levenshtein_distance(original, katze);
  REQUIRE(result == 2);
 }

TEST_CASE("Edit-example: head -> cat")
 {
 std::string original = "head";
 std::string katze = "cat";
 int result = levenshtein_distance(original, katze);
  REQUIRE(result == 3);
 }
