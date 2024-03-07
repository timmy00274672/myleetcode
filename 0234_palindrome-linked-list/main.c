/*
234. Palindrome Linked List
Easy
Topics
Companies
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

https://leetcode.com/problems/palindrome-linked-list/description/
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void printList(struct ListNode *head)
{
	struct ListNode *node = head;
	while (node != NULL) {
		printf("%d ", node->val);
		node = node->next;
		if (node == head) {
			break;
		}
	}
	printf("\n");
}

int freeList(struct ListNode *head)
{
	struct ListNode *node = head;
	struct ListNode *next;
	while (node != NULL) {
		next = node->next;
		if (node != NULL) {
			free(node);
		}
		node = next;
		if (node == head) {
			break;
		}
	}
	return 0;
}

#pragma GCC optimize("O3", "unroll-loops")
// ========================================================
bool isPalindrome(struct ListNode* head) {
	// find the middle one
	// reverse the second half
	// compare the first half and the second half

	struct ListNode *slow = head;
	struct ListNode *fast = head;
	struct ListNode *mid  = NULL;

	if (head == NULL) {
		return true;
	}

	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	mid = slow;

	// start to reverse the second half
	// A    ->    B    ->     C
	struct ListNode *node = mid->next;
	struct ListNode *prev = mid;
	mid->next = NULL;

	while(node != NULL) {
		struct ListNode *next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}

	// printf("[%d] print the first half\n", __LINE__);
	// printList(head);
	// printf("[%d] print the second half\n", __LINE__);
	// printList(prev);

	// compare the first half and the second half
	while(prev != NULL) {
		// printf("[%d] L: %d, R: %d\n", __LINE__, head->val, prev->val);
		if (head->val != prev->val) {
			// printf("[%d] false\n", __LINE__);
			return false;
		}
		head = head->next;
		prev = prev->next;
	}
	
	return true;
}

int main(int argc, char const *argv[])
{
	bool ret;
	// Test case: 1 2 2 1
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->val = 2;
	head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->val = 1;
	head->next->next->next->next = NULL;


	ret = isPalindrome(head);
	// printf("[%d] [1, 2, 2, 1] ret = %d\n=========================\n", __LINE__, ret);
	freeList(head);

	// Test case: 1 2
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = NULL;

	ret = isPalindrome(head);
	// printf("[%d] [1, 2] ret = %d\n=========================\n", __LINE__, ret);
	freeList(head);

	// Test case: 1
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	ret = isPalindrome(head);
	// printf("[%d] [1] ret = %d\n=========================\n", __LINE__, ret);
	freeList(head);

	// Test case: NULL
	head = NULL;
	ret = isPalindrome(head);
	// printf("[%d] NULL ret = %d\n=========================\n", __LINE__, ret);
	freeList(head);

	return 0;
}
