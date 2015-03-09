//	Problem	:	Combination Sum
//	Author	:	perry1990
//	Date	:	2015/3/8
//	Runtime	:	22 ms
/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

class Solution {
public:
    vector<vector<int> > ans;
	
	void findAns(vector<int> &candidates, int &target, int num, int sum, vector<int> &ans_element)
	{
		if (target == sum)
		{
			ans.push_back(ans_element);
			return;
		}
		if (num >= candidates.size())
			return;
		for (int i = num; i < candidates.size(); i ++)
		{
			if (sum + candidates[i] > target)
				break;
			if (i != 0 && candidates[i] == candidates[i - 1])
				continue;
			ans_element.push_back(candidates[i]);
			findAns(candidates, target, i, sum + candidates[i], ans_element);
			ans_element.pop_back();
		}
	}
	
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
		vector<int> ans_element;
		findAns(candidates, target, 0, 0, ans_element);
		return ans;
    }
};