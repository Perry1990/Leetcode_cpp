//	Problem	:	Search for a Range
//	Author	:	perry1990
//	Date	:	2015/2/22
//	Runtime	:	15 ms
/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int upper = n - 1, lower = 0;
		while (upper > lower)
		{
			int mid = lower + (upper - lower) / 2;
			if (A[mid] == target)
				break;
			if (A[mid] < target)
				lower = mid + 1;
			if (A[mid] > target)
				upper = mid - 1;
		}
		int mid = lower + (upper - lower)  / 2;
		if (A[mid] == target)
		{
			upper = mid; lower = mid;
			while (lower > 0 && A[lower - 1] == A[mid])
				lower --;
			while (upper < n - 1 && A[upper + 1] == A[mid])
				upper ++;
			vector<int> ans = {lower, upper};
			return ans;
		}
		else {
			vector<int> ans = {-1, -1};
			return ans;
		}
    }
};