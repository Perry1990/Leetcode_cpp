//	Problem	:	3Sum Closest
//	Author	:	perry1990
//	Date	:	2015/2/18
//	Runtime	:	33 ms
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
		int closest_sum = INT_MAX / 10;
		int i, j, k;
		for (i = 0; i < num.size(); i ++)
		{
			if (i && num[i] == num[i-1])
				continue;
			for (j = i + 1, k = num.size() - 1; j < k;)
			{
				if (j > i + 1 && num[j] == num[j-1])
				{
					j ++;
					continue;
				}
				if (k < num.size() - 1 && num[k] == num[k+1])
				{
					k --;
					continue;
				}
				int _3sum = num[i] + num[j] + num[k];
				if (abs(target - _3sum) < abs(target - closest_sum))
					closest_sum = _3sum;
				if (target < _3sum)
					k --;
				else
					j ++;
			}
		}
		return closest_sum;
    }
};