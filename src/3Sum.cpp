//	Problem	:	3Sum
//	Author	:	perry1990
//	Date	:	2015/2/18
//	Runtime	:	91 ms
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        map<int, int> m;
		vector<vector<int>> ans;
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); i ++)
			if (m.find(num[i]) == m.end())
				m[num[i]] = 1;
			else
				m[num[i]] ++;
		map<int, int>::iterator itr1, itr2, itr3;
		for (itr1 = m.begin(); itr1 != m.end(); itr1 ++)
		{
			for (itr2 = m.begin(); itr2 != itr1; itr2 ++)
			{
				if (0 - itr1->first - itr2->first < itr1->first)
					break;
				itr3 = m.find(0 - itr1->first - itr2->first);
				if (itr3 != m.end())
				{
					int a = 1;
					if (itr3->first == itr2->first) a ++;
					if (itr3->first == itr1->first) a ++;
					if (a <= m[itr3->first])
					{
						vector<int> ans_element;
						ans_element.clear();
						ans_element.push_back(itr2->first);
						ans_element.push_back(itr1->first);
						ans_element.push_back(itr3->first);
						ans.push_back(ans_element);
					}
				}
			}
			if (0 - ((itr1->first) << 1) < itr1->first)
				continue;
			if (m[itr1->first] < 2) continue;
			itr3 = m.find(0 - ((itr1->first) << 1));
			if (itr3 != m.end())
			{
				int a = 1;
				if (itr3->first == itr1->first) a += 2;
				if (a <= m[itr3->first])
				{
					vector<int> ans_element;
					ans_element.clear();
					ans_element.push_back(itr1->first);
					ans_element.push_back(itr1->first);
					ans_element.push_back(itr3->first);
					ans.push_back(ans_element);
				}
			}
		}
		return ans;
    }
};