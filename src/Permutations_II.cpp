//	Problem	:	Permutations II
//	Author	:	perry1990
//	Date	:	2015/3/11
//	Runtime	:	32 ms
/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
		sort(num.begin(), num.end());
		ans.push_back(num);
		int len = num.size();
		while(1)
		{
			int i = len - 1;
			while (i > 0 && num[i] <= num[i - 1])
				i --;
			if (i == 0) break;
			int j = len - 1, next_perm = len;
			while (j >= i)
			{
				if (num[j] > num[i - 1] && (next_perm == len || num[j] < num[next_perm]))
					next_perm = j;
				j --;
			}
			int tmp = num[next_perm]; num[next_perm] = num[i - 1]; num[i - 1] = tmp;
			sort(num.begin() + i, num.end());
			ans.push_back(num);
		}
		return ans;
    }
};