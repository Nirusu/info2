#ifndef __BUFFY_VAMPIRE_SLAYER_HPP__
#define __BUFFY_VAMPIRE_SLAYER_HPP__

typedef struct creature_counts
{
	int zombie_count;
	int vampire_count;
	int zombie_sum;
	int vampire_sum;
} creature_counts;

creature_counts count_creatures(int N, int creature_powers[]);
int *create_attack_plan(int N, int elements[], creature_counts c);
int *sort(int elements[], int length);
void swap(int *a,int *b);

#endif
