/*
876. Middle of the Linked List
Easy
Topics
Companies
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
https://leetcode.com/problems/middle-of-the-linked-list/description
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
struct ListNode *middleNode(struct ListNode *head)
{
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
int main(int argc, char const *argv[])
{
	// Test case 1: [1]
	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;

	printf("[%3d][1] [1] middle = %d\n", __LINE__, middleNode(head)->val);

	// Test case 2: [1, 2]
	head->next = malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = NULL;

	printf("[%3d][2] [1 2] middle = %d\n", __LINE__, middleNode(head)->val);

	// Test case 3: [1, 2, 3]
	head->next->next = malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next = NULL;

	printf("[%3d][3] [1 2 3] middle = %d\n", __LINE__, middleNode(head)->val);
	freeList(head);
	head = NULL;

	// Test case 4: []
	printf("[%3d][4] [] middle = %p\n", __LINE__, middleNode(head));
	
	return 0;
}
