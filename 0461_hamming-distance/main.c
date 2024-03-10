/*
461. Hamming Distance
Solved
Easy
Topics
Companies
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
Example 2:

Input: x = 3, y = 1
Output: 1
 

Constraints:

0 <= x, y <= 231 - 1

https://leetcode.com/problems/hamming-distance/description/
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

// =================================
#pragma GCC optimize("O3", "unroll-loops")
int hammingDistance(int x, int y) {
    int count = 0;
	int z = x ^ y;
	while (z) {
		count += z & 1;
		z >>= 1;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	return 0;
}
