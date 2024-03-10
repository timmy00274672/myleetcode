/*
2540. Minimum Common Value
Easy
Topics
Companies
Hint
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.

Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4]
Output: 2
Explanation: The smallest element common to both arrays is 2, so we return 2.
Example 2:

Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
Output: 2
Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[j] <= 109
Both nums1 and nums2 are sorted in non-decreasing order.

https://leetcode.com/problems/minimum-common-value/description/
*/

#include <stdio.h>

#pragma GCC optimize("O3", "unroll-loops")
// ========================================================
int getCommon(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	int index1 = 0, index2 = 0;
	while( index1 < nums1Size || index2 < nums2Size )
	{
		if( index1 == nums1Size || index2 == nums2Size )
			return -1;
		if( nums1[index1] == nums2[index2] )
			return nums1[index1];
		if( nums1[index1] < nums2[index2] )
			index1++;
		else
			index2++;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	// Test case 1: [1,2,3] [2,4]
	int ans = getCommon((int[]){1, 2, 3}, 3, (int[]){2, 4}, 2);
	printf("Test case 1: [1,2,3] [2,4] => %d\n", ans);

	// Test case 2: [1,2,3,6] [2,3,4,5]
	ans = getCommon((int[]){1, 2, 3, 6}, 4, (int[]){2, 3, 4, 5}, 4);
	printf("Test case 2: [1,2,3,6] [2,3,4,5] => %d\n", ans);

	// Test case 3: [] [1,2,3,4,5]
	ans = getCommon((int[]){}, 0, (int[]){1, 2, 3, 4, 5}, 5);
	printf("Test case 3: [] [1,2,3,4,5] => %d\n", ans);

	// Test case 4: [1,3,5] [2,4,6]
	ans = getCommon((int[]){1, 3, 5}, 3, (int[]){2, 4, 6}, 3);
	printf("Test case 4: [1,3,5] [2,4,6] => %d\n", ans);

	return 0;
}
