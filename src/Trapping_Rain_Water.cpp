//	Problem	:	Trapping Rain Water
//	Author	:	perry1990
//	Date	:	2015/3/10
//	Runtime	:	10 ms
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution {
public:
    int trap(int A[], int n) {
        int left = 0, right = n - 1;
		int max_left = 0, max_right = 0;
		int ans = 0;
		while (left <= right)
		{
			if (A[left] <= A[right])
			{
				if (A[left] > max_left)
					max_left = A[left];
				else
					ans += max_left - A[left];
				left ++;
			}
			else {
				if (A[right] > max_right)
					max_right = A[right];
				else
					ans += max_right - A[right];
				right --;
			}
		}
		return ans;
    }
};