/*
118. Pascal's Triangle
Easy
Topics
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30

https://leetcode.com/problems/pascals-triangle/description/
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// =================================
#pragma GCC optimize("O3", "unroll-loops")
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
	*returnSize = numRows;
	if (numRows == 0) {
		return NULL;
	}
	int **result = (int **)malloc(numRows * sizeof(int *));
	*returnColumnSizes = (int *)malloc(numRows * sizeof(int));

	// for each level
	for (int h = 0; h < numRows; h++) {
		result[h] = (int *)malloc((h + 1) * sizeof(int));
		(*returnColumnSizes)[h] = h + 1;
		result[h][0] = 1;
		// printf("[%d][0] = %d\n", h, result[h][0]);
		// for each element in the level
		for (int i = 1; i < h; i++) {
			result[h][i] = result[h - 1][i - 1] + result[h - 1][i];
			// printf("[%d][%d] = %d\n", h, i, result[h][i]);
		}
		result[h][h] = 1;
		// printf("[%d][%d] = %d\n", h, h, result[h][h]);
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int numRows = 5;
	int returnSize;
	int *returnColumnSizes;
	int **result = generate(numRows, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < returnColumnSizes[i]; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	free(result);
	return 0;
}
