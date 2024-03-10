/*
108. Convert Sorted Array to Binary Search Tree
Easy
Topics
Companies
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
*/

#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// =================================
#pragma GCC optimize("O3", "unroll-loops")
struct TreeNode *ArrayRangeToBST(int *nums, int left, int right)
{
	if (left > right)
		return NULL;

	int mid = left + (right - left) / 2;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	root->val = nums[mid];
	root->left = ArrayRangeToBST(nums, left, mid - 1);
	root->right = ArrayRangeToBST(nums, mid + 1, right);
	return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
	return ArrayRangeToBST(nums, 0, numsSize - 1);
}


int main(int argc, char const *argv[])
{
	return 0;
}
