/*
1290. Convert Binary Number in a Linked List to Integer
Easy
Topics
Companies
Hint
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 

Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
 

Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.
*/

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
	}
	printf("\n");
}

struct ListNode *convertArrayToList(int *arr, int size)
{
	struct ListNode *node, *prev;
	node = malloc(sizeof(struct ListNode));
	node->val = arr[0];
	struct ListNode *head = node;
	for (int i = 1; i < size; i++) {
		prev = node;
		node = malloc(sizeof(struct ListNode));
		node->val = arr[i];
		node->next = NULL;
		prev->next = node;
	}
	return head;
}

int freeList(struct ListNode *head)
{
	struct ListNode *node = head;
	struct ListNode *next;
	while (node != NULL) {
		next = node->next;
		free(node);
		node = next;
	}
	return 0;
}

// ========================================================
int getDecimalValue(struct ListNode *head)
{
	int result = 0;
	struct ListNode *node = head;
	while (node != NULL) {
		result = result * 2 + node->val;
		node = node->next;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int example1[] = { 1, 1, 0, 1};
    struct ListNode *head = convertArrayToList(example1, sizeof(example1) / sizeof(example1[0]));
    printList(head);
    printf("%d\n", getDecimalValue(head));
    freeList(head);

    int example2[] = { 1, 0, 1};
    head = convertArrayToList(example2, sizeof(example2) / sizeof(example2[0]));
    printList(head);
    printf("%d\n", getDecimalValue(head));
    freeList(head);

	return 0;
}
