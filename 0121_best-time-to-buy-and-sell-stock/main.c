#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =================================
#pragma GCC optimize("O3", "unroll-loops")

int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize < 2) {
		return 0;
	}
	int min = prices[0];
	int maxProfit = 0;

	for (int i = 1; i < pricesSize; i++) {
		if (prices[i] < min) {
			min = prices[i];
		} else {
			maxProfit = (prices[i] - min) > maxProfit ?
					    (prices[i] - min) :
					    maxProfit;
		}
	}
	return maxProfit;
}

int main(int argc, char const *argv[])
{
	// Test case1: prices = [7,1,5,3,6,4] -> 5
	printf("maxProfit([7,1,5,3,6,4], 6) = %d\n",
	       maxProfit((int[]){ 7, 1, 5, 3, 6, 4 }, 6));
	// Test case2: prices = [7,6,4,3,1] -> 0
	printf("maxProfit([7,6,4,3,1], 5) = %d\n",
	       maxProfit((int[]){ 7, 6, 4, 3, 1 }, 5));
	// Test case3: prices = [1,2] -> 1
	printf("maxProfit([1,2], 2) = %d\n", maxProfit((int[]){ 1, 2 }, 2));
	// Test case4: prices = [1] -> 0
	printf("maxProfit([1], 1) = %d\n", maxProfit((int[]){ 1 }, 1));
	// Test case5: prices = [] -> 0
	printf("maxProfit([], 0) = %d\n", maxProfit((int[]){}, 0));
	// Test case6: [2,10,1, 5, 3, 6, 4] -> 8
	printf("maxProfit([2,10,1,5,3,6,4], 7) = %d\n",
	       maxProfit((int[]){ 2, 10, 1, 5, 3, 6, 4 }, 7));

	return 0;
}
