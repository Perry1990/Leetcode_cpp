//	Problem	:	Longest Common Prefix
//	Author	:	perry1990
//	Date	:	2015/2/18
//	Runtime	:	7 ms
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int min_len = INT_MAX;
		string ans;
		
		if (strs.empty()) return ans;
		for (int i = 0; i < strs.size(); i ++)
			if (strs[i].length() < min_len)
				min_len = strs[i].length();
		
		for (int i = 0; i < min_len; i ++)
		{
			if (strs[0].empty()) return ans;
			char ch = strs[0][i];
			for (int j = 0; j < strs.size(); j ++)
				if (strs[j][i] != ch)
					return ans;
			ans += ch;
		}
		return ans;
    }
};