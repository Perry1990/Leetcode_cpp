//	Problem	:	Maximum Subarray
//	Author	:	perry1990
//	Date	:	2015/3/11
//	Runtime	:	12 ms
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, start = -1, ans = 0, min_neg = INT_MIN;
		for (int i = 0; i < n; i ++)
		{
			if (sum < 0)
			{
				sum = 0;
				start = i;
			}
			sum += A[i];
			if (sum > ans)
				ans = sum;
			if (A[i] <= 0 && A[i] > min_neg)
				min_neg = A[i];
		}
		if (ans != 0)
			return ans;
		else
			return min_neg;
    }
};