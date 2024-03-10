/*
104. Maximum Depth of Binary Tree
Easy
Topics
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// =================================
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return left > right ? left + 1 : right + 1;
}

#pragma GCC optimize("O3", "unroll-loops")

int main(int argc, char const *argv[])
{
	return 0;
}
