/*
237. Delete Node in a Linked List
Medium
Topics
Companies
There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.
 

Example 1:


Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:


Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
 

Constraints:

The number of the nodes in the given list is in the range [2, 1000].
-1000 <= Node.val <= 1000
The value of each node in the list is unique.
The node to be deleted is in the list and is not a tail node.

https://leetcode.com/problems/delete-node-in-a-linked-list/description/
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
void deleteNode(struct ListNode* node) {	
	struct ListNode *next = node->next;
	node->val = node->next->val;
	node->next = node->next->next;
	free(next);
}

int main(int argc, char const *argv[])
{
	// Case 0: [4 5 3 9] node 5
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 4;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 5;
	head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->val = 9;
	head->next->next->next->next = NULL;

	printf("Case 0: \n");
	printf("before: ");
	printList(head);
	printf("\n");
	deleteNode(head->next);
	printf("after: ");
	printList(head);
	printf("\n");

	return 0;
}
