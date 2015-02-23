//	Problem	:	Search Insert Position
//	Author	:	perry1990
//	Date	:	2015/2/22
//	Runtime	:	8 ms
/*
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (target < A[0]) return 0;
		else if (target > A[n - 1]) return n;
		
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
		if (A[lower] >= target)
			return lower;
		else return lower + 1;
    }
};