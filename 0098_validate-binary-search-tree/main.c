/*
98. Validate Binary Search Tree
Medium
Topics
Companies
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

https://leetcode.com/problems/validate-binary-search-tree/description/
*/

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// =================================
bool isValidBSTRecursive(struct TreeNode* root, struct TreeNode* min, struct TreeNode* max) {
    // if root is NULL, return true
    if (root == NULL) {
        return true;
    }
    // if min is not NULL and root value is less than or equal to min value, return false
    if (min != NULL && root->val <= min->val) {
        return false;
    }
    // if max is not NULL and root value is greater than or equal to max value, return false
    if (max != NULL && root->val >= max->val) {
        return false;
    }
    // run recursive function for left child with min and root
    // run recursive function for right child with root and max
    return isValidBSTRecursive(root->left, min, root) && isValidBSTRecursive(root->right, root, max);
}

bool isValidBST(struct TreeNode* root) {
    // run recursive function
    return isValidBSTRecursive(root, NULL, NULL);
}

#pragma GCC optimize("O3", "unroll-loops")

int main(int argc, char const *argv[])
{
	return 0;
}
