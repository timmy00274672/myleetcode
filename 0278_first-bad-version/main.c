/*
278. First Bad Version
Easy
Topics
Companies
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
 

Constraints:

1 <= bad <= n <= 231 - 1

https://leetcode.com/problems/first-bad-version/description/
*/

#include <stdbool.h>
#include <stdio.h>

#pragma GCC optimize("O3", "unroll-loops")

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// ========================================================
int first = 1;
bool isBadVersion(int version)
{
	if (version >= first)
		return 1;
	return 0;
}

int firstBadVersion(int n)
{
	// Binary search
	int left = 1, right = n;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (isBadVersion(mid))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main(int argc, char const *argv[])
{
	// Test case 1: 5, 4
	first = 4;
	printf("Test case 1: 5, 4 => %d\n", firstBadVersion(5));

	// Test case 2: 1, 1
	first = 1;
	printf("Test case 2: 1, 1 => %d\n", firstBadVersion(1));

	// Test case 3: 2126753390, 1702766719
	first = 1702766719;
	printf("Test case 3: 2126753390, 1702766719 => %d\n", firstBadVersion(2126753390));
	return 0;
}
