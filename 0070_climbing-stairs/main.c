#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =================================
#pragma GCC optimize("O3", "unroll-loops")

int climbStairsRecursive(int n, int *dp)
{
	if (dp[n] != -1) {
		return dp[n];
	}
	dp[n] = climbStairsRecursive(n - 1, dp) +
		climbStairsRecursive(n - 2, dp);
	return dp[n];
}
int climbStairs(int n)
{
	int dp[n + 2];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	int ret = climbStairsRecursive(n, dp);
	// for (int i = 3; i <= n; i++) {
	// 	printf("dp[%d] = %d\n", i, dp[i]);
	// }
	return ret;
}

int main(int argc, char const *argv[])
{
	printf("climbStairs(0) = %d\n", climbStairs(0));
	printf("climbStairs(1) = %d\n", climbStairs(1));
	printf("climbStairs(2) = %d\n", climbStairs(2));
	printf("climbStairs(3) = %d\n", climbStairs(3));
	printf("climbStairs(40) = %d\n", climbStairs(40));

	return 0;
}
