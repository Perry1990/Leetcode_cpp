//	Problem	:	Search in Rotated Sorted Array
//	Author	:	perry1990
//	Date	:	2015/2/22
//	Runtime	:	7 ms
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search_unrotated(int A[], int n, int target)
	{
		int upper = n - 1, lower = 0;
		while (upper > lower)
		{
			int mid = lower + (upper - lower) / 2;
			if (A[mid] == target)
				return mid;
			if (A[mid] < target)
				lower = mid + 1;
			if (A[mid] > target)
				upper = mid - 1;
		}
		if (A[lower] == target)
			return lower;
		else return -1;
	}
	
	int search(int A[], int n, int target) {
        if (A[0] < A[n - 1]) return search_unrotated(A, n, target);
		if (target < A[0] && target > A[n - 1])
			return -1;
		if (target == A[0]) return 0;
		if (target == A[n - 1]) return (n - 1);
		int upper = n - 1, lower = 0;
		while (upper - lower > 1)
		{
			int mid = lower + (upper - lower) / 2;
			if (A[mid] == target)
				return mid;
			if (target > A[0])
			{
				if (A[mid] < A[n - 1] || A[mid] > target)
				{
					upper = mid - 1;
				}
				else if (A[mid] < target)
				{
					lower = mid + 1;
				}
			}
			else if (target < A[n - 1])
			{
				if (A[mid] < target || A[mid] > A[0])
				{
					lower = mid + 1;
				}
				else if (A[mid] > target)
				{
					upper = mid - 1;
				}
			}
		}
		if (A[upper] == target) return upper;
		if (A[lower] == target) return lower;
		return -1;
    }
};