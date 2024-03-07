/*
26. Remove Duplicates from Sorted Array
Easy
Topics
Companies
Hint
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/

#include <stdio.h>

void printArray(int *nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

#pragma GCC optimize("O3", "unroll-loops")
// ========================================================
int removeDuplicates(int *nums, int numsSize)
{
	int j = 0; // processed index
	int size = 0; // size of unique elements

	for (j = 0; j < numsSize; j++) {
		// if nums[j] is different from nums[size]
		// then cp nums[j] to nums[size+1]

		// printf("[%d] j = %d, size = %d\n", nums[j], j, size);

		if (nums[j] != nums[size]) {
			nums[size + 1] = nums[j];
			size++;
		}
	}

	return size + 1;
}

int main(int argc, char const *argv[])
{
	int num = 0;
	// Test case 1: nums = [1,1,2]
	int nums1[] = { 1, 1, 2 };
	int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
	num = removeDuplicates(nums1, numsSize1);

	printf("[%d] Test case 1: nums = [1,1,2], array = ", __LINE__);
	printArray(nums1, num);

	// Test case 2: nums = [0,0,1,1,1,2,2,3,3,4]
	int nums2[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
	num = removeDuplicates(nums2, numsSize2);

	printf("[%d] Test case 2: nums = [0,0,1,1,1,2,2,3,3,4], array = ", __LINE__);
	printArray(nums2, num);

	// Test case 3: nums = [1,1,1,1,1,1,1,1,1,1]
	int nums3[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
	num = removeDuplicates(nums3, numsSize3);

	printf("[%d] Test case 3: nums = [1,1,1,1,1,1,1,1,1,1], array = ", __LINE__);
	printArray(nums3, num);

	// Test case 4: nums = [1,2,3,4,5,6,7,8,9,10]
	int nums4[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int numsSize4 = sizeof(nums4) / sizeof(nums4[0]);
	num = removeDuplicates(nums4, numsSize4);

	printf("[%d] Test case 4: nums = [1,2,3,4,5,6,7,8,9,10], array = ", __LINE__);
	printArray(nums4, num);

	return 0;
}
