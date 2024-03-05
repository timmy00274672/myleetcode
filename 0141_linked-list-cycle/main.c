/*
141. Linked List Cycle
Easy
Topics
Companies
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
// Algorithm: Floyd's Tortoise and Hare
bool hasCycle(struct ListNode *head)
{
	struct ListNode *slow = head;
	struct ListNode *fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	// 1 -> 2 -> 3 -> 1

	struct ListNode *head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next = head;

	printList(head);
	printf("%d\n", hasCycle(head));
	freeList(head);

	// corner case []
	head = NULL;
	printf("[]\n");
	printf("%d\n", hasCycle(head));

	// 1 -> 2
	head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = NULL;

	printList(head);
	printf("%d\n", hasCycle(head));
	freeList(head);

	return 0;
}
