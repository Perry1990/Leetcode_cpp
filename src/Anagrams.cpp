//	Problem	:	Anagrams
//	Author	:	perry1990
//	Date	:	2015/3/11
//	Runtime	:	71 ms
/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> ans;
		struct foo
		{
			string str, original_str;
		};
		vector<foo> str_list;
		struct compare
		{
			bool operator () (foo a, foo b) {return a.str < b.str;}
		};
		for (int i = 0; i < strs.size(); i ++)
		{
			foo str_element;
			str_element.str = str_element.original_str = strs[i];
			str_list.push_back(str_element);
		}
        for (int i = 0; i < strs.size(); i ++)
			sort(str_list[i].str.begin(), str_list[i].str.end());
		sort(str_list.begin(), str_list.end(), compare());
		int prev = 0;
		for (int i = 1; i < strs.size(); i ++)
			if (str_list[i].str.compare(str_list[i-1].str) == 0)
			{
				if (prev == 0)
					ans.push_back(str_list[i-1].original_str);
				prev = 1;
				ans.push_back(str_list[i].original_str);
			}
			else
				prev = 0;
		return ans;
    }
};