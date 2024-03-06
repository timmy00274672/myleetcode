/*
19. Remove Nth Node From End of List
Medium
Topics
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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

// ========================================================
#pragma GCC optimize("O3", "unroll-loops")
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	struct ListNode *fast = head, *slow = head;
	for (int i = 0; i < n; i++)
		fast = fast->next;
	if (!fast) {
		// it's the first one
		struct ListNode *newHead = head->next;
		free(head); //avoid of memory leaks
		return newHead;
	}
	// shift both until fast is at the end
	while (fast->next) {
		fast = fast->next, slow = slow->next;
	}
	struct ListNode *node = slow->next;
	slow->next = slow->next->next;
	free(node); //avoid of memory leaks
	return head;
}

int main(int argc, char const *argv[])
{
	// Test 1
	// 	  1 -> 2 -> 3 -> 4 -> 5, remove 2nd from end
	struct ListNode *head =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->val = 4;
	head->next->next->next->next =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->next->val = 5;
	head->next->next->next->next->next = NULL;

	printList(head);
	head = removeNthFromEnd(head, 2);
	printList(head);
	freeList(head);

	// Test 2
	// 	  1, remove 1st from end
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	printList(head);
	head = removeNthFromEnd(head, 1);
	printList(head);
	freeList(head);

	// Test 3
	// 	  1 -> 2, remove 1st from end
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = NULL;

	printList(head);
	head = removeNthFromEnd(head, 1);
	printList(head);
	freeList(head);

	return 0;
}
