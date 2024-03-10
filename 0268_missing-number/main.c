#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// =================================
#pragma GCC optimize("O3", "unroll-loops")

int missingNumber(int *nums, int numsSize)
{
	// sum of 0 to n = n * (n + 1) / 2
	int sum = numsSize * (numsSize + 1) / 2;
	for (int i = 0; i < numsSize; i++) {
		sum -= nums[i];
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	// nums = [3,0,1], Output: 2
	printf("missingNumber([3,0,1], 3) = %d\n",
	       missingNumber((int[]){ 3, 0, 1 }, 3));
	// nums = [0,1], Output: 2
	printf("missingNumber([0,1], 2) = %d\n",
	       missingNumber((int[]){ 0, 1 }, 2));

	return 0;
}
