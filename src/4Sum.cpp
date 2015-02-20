//	Problem	:	4Sum
//	Author	:	perry1990
//	Date	:	2015/2/19
//	Runtime	:	115 ms
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    struct pair_element
	{
		int val, pos_a, pos_b;
	};
	vector<vector<int> > ans;
	
	void refresh_ans(vector<int> num, int a, int b, int c, int d)
	{
		if (a == b || a == c || a == d || b == c || b == d || c == d)
			return;
		vector<int> ans_element = {num[a], num[b], num[c], num[d]};
		sort(ans_element.begin(), ans_element.end());
		for (int i = 0; i < ans.size(); i ++)
		{
			if (ans[i][0] == ans_element[0] && ans[i][1] == ans_element[1] && ans[i][2] == ans_element[2] && ans[i][3] == ans_element[3])
				return;
		}
		ans.push_back(ans_element);
	}
	
	struct compair {
		bool operator () (pair_element a, pair_element b) {return a.val < b.val;}
	}compair_func;
	
	vector<vector<int> > fourSum(vector<int> &num, int target) {
        int i, j;
		vector<pair_element> pair_vec;
		
		if (num.size() < 4) return ans;
		sort(num.begin(), num.end());
		for (i = 0; i < num.size(); i ++)
			for (j = i + 1; j < num.size(); j ++)
			{
				pair_element a;
				a.val = num[i] + num[j];
				a.pos_a = i; a.pos_b = j;
				pair_vec.push_back(a);
			}
		sort(pair_vec.begin(), pair_vec.end(), compair_func);
		for (i = 0, j = pair_vec.size() - 1; i < j;)
		{
			if (i && pair_vec[i].val == pair_vec[i-1].val)
			{
				i ++;
				continue;
			}
			if (j < pair_vec.size() - 1 && pair_vec[j].val == pair_vec[j+1].val)
			{
				j --;
				continue;
			}
			if (pair_vec[i].val + pair_vec[j].val == target)
			{
				for (int k = i; pair_vec[k].val == pair_vec[i].val && k < j; k ++)
					for (int l = j; pair_vec[l].val == pair_vec[j].val && k < l; l --)
						refresh_ans(num, pair_vec[k].pos_a, pair_vec[k].pos_b, pair_vec[l].pos_a, pair_vec[l].pos_b);
				i ++;
				j --;
			}
			else if (pair_vec[i].val + pair_vec[j].val < target)
				i ++;
			else j --;
		}
		return ans;
    }
};
