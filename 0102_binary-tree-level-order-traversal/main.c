/*
102. Binary Tree Level Order Traversal
Solved
Medium
Topics
Companies
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// =================================
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int *returnSize,
		 int **returnColumnSizes)
{
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}

	struct TreeNode **queue =
		(struct TreeNode **)malloc(2000 * sizeof(struct TreeNode *));
	*returnColumnSizes = malloc(2000 * sizeof(int));
	int front = 0;
	int rear = 0;
	queue[rear++] = root;

	int **result = (int **)malloc(2000 * sizeof(int *));
	int level = 0;
	int tmpRear = rear;

	while (front < rear) {
		int count = 0;
		for (int i = front; i < tmpRear; i++) {
			if (queue[i] != NULL) {
				count++;
				if (queue[i]->left != NULL) {
					queue[rear++] = queue[i]->left;
				}
				if (queue[i]->right != NULL) {
					queue[rear++] = queue[i]->right;
				}
			}
		}

		result[level] = (int *)malloc(count * sizeof(int));
		(*returnColumnSizes)[level] = 0;

		for (int i = front; i < tmpRear; i++) {
			if (queue[i] != NULL) {
				result[level][(*returnColumnSizes)[level]++] =
					queue[i]->val;
			}
		}

		front = tmpRear;
		tmpRear = rear;
		level++;
	}

	*returnSize = level;
	free(queue);

	return result;
}
#pragma GCC optimize("O3", "unroll-loops")

int main(int argc, char const *argv[])
{
	return 0;
}
