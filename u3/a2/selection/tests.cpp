#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "selection_string.hpp"

TEST_CASE("Loop through string vector: example 1")
{
	std::vector<std::string> my_strings;

	my_strings.push_back("imhungry");
	my_strings.push_back("cookies");
	my_strings.push_back("strawberries");
	my_strings.push_back("cheesecake");
	my_strings.push_back("food");

	char c = 'e';

	std::vector<std::string> sorted_strings = selection_sort(my_strings, c);

	REQUIRE(sorted_strings[1] == "food");
}

TEST_CASE("Loop through string vector: example 2")
{
	std::vector<std::string> my_strings;

	my_strings.push_back("aabbcc");
	my_strings.push_back("ababababababa");
	my_strings.push_back("ccaa");
	my_strings.push_back("abc");
	my_strings.push_back("aaabbbaaabbb");

	char c = 'b';

	std::vector<std::string> sorted_strings = selection_sort(my_strings, c);

	REQUIRE(sorted_strings[3] == "ababababababa");
}

TEST_CASE("Count the # of characters correctly: example 1")
{

	std::string a = "kingkong";
	std::string b = "godzilla";
	char c = 'g';

	int result = compare_by_frequency(a, b, c);
	REQUIRE(result == 0);
}

TEST_CASE("Count the # of characters correctly: example 2")
{

	std::string a = "kingkong";
	std::string b = "godzilla";
	char c = 'z';

	int result = compare_by_frequency(a, b, c);
	REQUIRE(result == 1);
}
