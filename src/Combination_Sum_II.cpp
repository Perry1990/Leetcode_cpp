//	Problem	:	Combination Sum II
//	Author	:	perry1990
//	Date	:	2015/3/8
//	Runtime	:	14 ms
/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ¡­ , ak) must be in non-descending order. (ie, a1 ¡Ü a2 ¡Ü ¡­ ¡Ü ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
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
			if (i != 0 && i > num && candidates[i] == candidates[i - 1])
				continue;
			ans_element.push_back(candidates[i]);
			findAns(candidates, target, i + 1, sum + candidates[i], ans_element);
			ans_element.pop_back();
		}
	}
	
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
		vector<int> ans_element;
		findAns(candidates, target, 0, 0, ans_element);
		return ans;
    }
};