//	Problem	:	Jump Game II
//	Author	:	perry1990
//	Date	:	2015/3/10
//	Runtime	:	19 ms
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    int jump(int A[], int n) {
        int max_n = 0, i = 0, step = 0;
		while (max_n < n - 1)
		{
			int prev_max_n = max_n;
			for (; i <= prev_max_n; i ++)
				if (i + A[i] > max_n)
					max_n = i + A[i];
			step ++;
		}
		return step;
    }
};