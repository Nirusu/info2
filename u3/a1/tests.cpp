#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "buffy_vampire_slayer.hpp"

TEST_CASE("Sums of creature powers: example 1")
{
	int N = 10;
	int creatures[10] = {1, 3, 20, 14, 7, 5, 10, 12, 6, 2};

	creature_counts counts = count_creatures(N, creatures);
	REQUIRE(counts.zombie_count == 6);
}

TEST_CASE("Sums of creature powers: example 2")
{
	int N = 10;
	int creatures[10] = {1, 3, 20, 9, 7, 5, 10, 12, 6, 2};

	creature_counts counts = count_creatures(N, creatures);
	REQUIRE(counts.vampire_count == 5);
}

TEST_CASE("Sorted by creature types: example 1")
{
	int N = 10;
	int creatures[10] = {1, 3, 20, 14, 7, 5, 10, 12, 6, 2};

	int *sorted_creatures = sort(creatures, N);
	REQUIRE(sorted_creatures[2] == 10);
}

TEST_CASE("Sorted by creature types: example 2")
{
	int N = 3;
	int creatures[3] = {1, 3, 20};

	int *sorted_creatures = sort(creatures, N);
	REQUIRE(sorted_creatures[0] == 20);
}

TEST_CASE("Attack plan: example 1")
{
	int N = 10;
	int creatures[10] = {1, 3, 20, 9, 7, 5, 10, 12, 6, 2};

	creature_counts counts = count_creatures(N, creatures);
	int *sorted_creatures = sort(creatures, N);
	int *attack_creatures = create_attack_plan(N, sorted_creatures, counts);

	REQUIRE(attack_creatures[5] == 50);
}

TEST_CASE("Attack plan: example 2")
{
	int N = 10;
	int creatures[10] = {1, 3, 20, 9, 7, 5, 11, 12, 6, 2};

	creature_counts counts = count_creatures(N, creatures);
	int *sorted_creatures = sort(creatures, N);
	int *attack_creatures = create_attack_plan(N, sorted_creatures, counts);

	REQUIRE(attack_creatures[11] == 36);
}
