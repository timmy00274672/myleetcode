/*
21. Merge Two Sorted Lists
Easy
Topics
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

https://leetcode.com/problems/merge-two-sorted-lists/description/*/

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
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
	if (list1 == NULL && list2 == NULL) {
		return NULL;
	}

	struct ListNode *head = NULL;

	struct ListNode *lNode = list1;
	struct ListNode *rNode = list2;
	struct ListNode *node;
	do {
		if (head == NULL) {
			// printf("[%s:%d] head == NULL\n", __func__, __LINE__);
			node = (struct ListNode *)malloc(sizeof(struct ListNode));
			node->next = NULL;
			head = node;
		} else {
			// printf("[%s:%d] head != NULL\n", __func__, __LINE__);
			node->next = (struct ListNode *)malloc(sizeof(struct ListNode));
			node = node->next;
			node->next = NULL;
		}
		// printf("[%s:%d] lNode = %p, rNode = %p\n", __func__, __LINE__, lNode, rNode);

		if (rNode == NULL) {
			node->val = lNode->val;
			lNode = lNode->next;
			// printf("[%s:%d] node->val = %d\n", __func__, __LINE__, node->val);
		} else if (lNode == NULL) {
			node->val = rNode->val;
			rNode = rNode->next;
			// printf("[%s:%d] node->val = %d\n", __func__, __LINE__, node->val);
		} else if (lNode->val <= rNode->val) {
			node->val = lNode->val;
			lNode = lNode->next;
			// printf("[%s:%d] node->val = %d\n", __func__, __LINE__, node->val);
		} else {
			node->val = rNode->val;
			rNode = rNode->next;
			// printf("[%s:%d] node->val = %d\n", __func__, __LINE__, node->val);
		}
		// printf("[%s:%d] lNode = %p, rNode = %p\n", __func__, __LINE__, lNode, rNode);
	} while (lNode != NULL || rNode != NULL);

	return head;
}

int main(int argc, char const *argv[])
{
	// Case 1: [1, 2, 3] + [1, 3, 5]
	struct ListNode *list1 =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *list2 =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	list1->val = 1;
	list1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list1->next->val = 2;
	list1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list1->next->next->val = 3;
	list1->next->next->next = NULL;

	list2->val = 1;
	list2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2->next->val = 3;
	list2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2->next->next->val = 5;
	list2->next->next->next = NULL;

	struct ListNode *result = mergeTwoLists(list1, list2);
	printf("[Case 1] [1, 2, 3] + [1, 3, 5]\n");
	printList(result);
	freeList(result);
	freeList(list1);
	freeList(list2);

	// Case 1: [1, 2, 4] + [1, 3, 4]
	list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	list1->val = 1;
	list1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list1->next->val = 2;
	list1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list1->next->next->val = 4;
	list1->next->next->next = NULL;

	list2->val = 1;
	list2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2->next->val = 3;
	list2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2->next->next->val = 4;
	list2->next->next->next = NULL;

	result = mergeTwoLists(list1, list2);
	printf("[Case 2] [1, 2, 4] + [1, 3, 4]\n");
	printList(result);
	freeList(result);
	freeList(list1);
	freeList(list2);

	// Case 3: [] + []
	list1 = NULL;
	list2 = NULL;
	result = mergeTwoLists(list1, list2);
	printf("[Case 3] [] + []\n");
	printList(result);
	freeList(result);

	// Case 4: [] + [0]
	list1 = NULL;
	list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	list2->val = 0;
	list2->next = NULL;
	printf("[Case 4] [] + [0]\n");
	result = mergeTwoLists(list1, list2);
	printList(result);
	freeList(result);
	freeList(list2);
	return 0;
}
