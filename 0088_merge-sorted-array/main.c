/*
88. Merge Sorted Array
Easy
Topics
Companies
Hint
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

https://leetcode.com/problems/merge-sorted-array/description/
*/

#include <stdio.h>

#pragma GCC optimize("O3", "unroll-loops")

void printArray(int *nums, int numsSize)
{
	printf("[");
	for (int i = 0; i < numsSize; i++) {
		printf("%d", nums[i]);
		if (i < numsSize - 1)
			printf(", ");
	}
	printf("]\n");
}
// ========================================================
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	if (n == 0)
		return;
	// start filling from the end of nums1
	// and reusing m, n as index
	int index = nums1Size - 1; // index to fill
	m--;
	n--;

	while (m >= 0 || n >= 0) {
		if (m < 0) {
			nums1[index] = nums2[n];
			n--;
		} else if (n < 0) {
			nums1[index] = nums1[m];
			m--;
		} else if (nums1[m] > nums2[n]) {
			nums1[index] = nums1[m];
			m--;
		} else {
			nums1[index] = nums2[n];
			n--;
		}
		index--;
	}
}

int main(int argc, char const *argv[])
{
	// Test case 1: [1,2,3,0,0,0] 3 [2,5,6] 3
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	merge(nums1, 6, 3, nums2, 3, 3);
	printf("Test case 1: [1,2,3,0,0,0] 3 [2,5,6] 3 => ");
	printArray(nums1, 6);

	// Test case 2: [1] 1 [] 0
	int nums3[] = { 1 };
	int nums4[] = {};
	merge(nums3, 1, 1, nums4, 0, 0);
	printf("Test case 2: [1] 1 [] 0 => ");
	printArray(nums3, 1);

	// Test case 3: [] 0 [1] 1
	int nums5[] = { 0 };
	int nums6[] = { 1 };
	merge(nums5, 0, 0, nums6, 1, 1);
	printf("Test case 3: [] 0 [1] 1 => ");
	printArray(nums5, 1);

	return 0;
}
