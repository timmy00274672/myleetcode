/*
206. Reverse Linked List
Easy
Topics
Companies
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

https://leetcode.com/problems/reverse-linked-list/description/
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
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *prev = NULL;
	struct ListNode *next = NULL;
	struct ListNode *curr = head;

	while(curr != NULL) {
		// save next
		next = curr->next;
		// reverse, NULL for the first one is correct
		curr->next = prev;
		// move to next
		prev = curr;
		curr = next;
	}
	return prev;
}

int main(int argc, char const *argv[])
{
	// Test case: 1 -> 2 -> 3
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next = NULL;

	printList(head);
	head = reverseList(head);
	printList(head);
	freeList(head);

	return 0;
}
