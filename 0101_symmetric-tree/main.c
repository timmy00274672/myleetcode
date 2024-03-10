/*
101. Symmetric Tree
Easy
Topics
Companies
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?

https://leetcode.com/problems/symmetric-tree/description/
*/

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

// helper function
bool isTheSame(struct TreeNode* left, struct TreeNode* right) {
    // if both left and right are NULL, return true
    if (left == NULL && right == NULL) {
        return true;
    }
    // if either left or right is NULL, return false
    if (left == NULL || right == NULL) {
        return false;
    }
    // if left value is not equal to right value, return false
    if (left->val != right->val) {
        return false;
    }
    // run recursive function for left child of left with right child of right
    // run recursive function for right child of left with left child of right
    return isTheSame(left->left, right->right) && isTheSame(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isTheSame(root->left, root->right);
}

#pragma GCC optimize("O3", "unroll-loops")

int main(int argc, char const *argv[])
{
	return 0;
}
