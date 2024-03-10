#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =================================
#pragma GCC optimize("O3", "unroll-loops")

int maxSubArray(int *nums, int numsSize)
{
	int max = nums[0];
	int sum = 0;
	for (int i = 0; i < numsSize; i++) {
		if (sum < 0) {
			sum = 0;
		}
		sum += nums[i];
		if (sum > max) {
			max = sum;
		}
	}
	return max;
}
int main(int argc, char const *argv[])
{
	// Test case 1: [-2,1,-3,4,-1,2,1,-5,4] -> 6
	printf("[%2d] maxSubArray([-2,1,-3,4,-1,2,1,-5,4], 9) = %d\n", 1,
	       maxSubArray((int[]){ -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 9));

	// Test case 2: [1] -> 1
	printf("[%2d] maxSubArray([1], 1) = %d\n", 2,
	       maxSubArray((int[]){ 1 }, 1));
	return 0;
}
