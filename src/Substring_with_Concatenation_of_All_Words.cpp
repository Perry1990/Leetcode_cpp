//	Problem	:	Substring with Concatenation of All Words
//	Author	:	perry1990
//	Date	:	2015/2/22
//	Runtime	:	50 ms
/*
You are given a string, S, and a list of words, L, that are all of the same length.
Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
	struct wordStat
	{
		int num, no;
	};
	
	vector<int> findSubstring(string S, vector<string> &L) {
		unordered_map<string, wordStat> m;
		vector<int> ans;
		for (int i = 0; i < L.size(); i ++)
		{
			m[L[i]].num ++;
			m[L[i]].no = i;
		}
		int wordLen = L[0].size();
		int *checkList = new int[L.size()];
		for (int i = 0; i < wordLen; i ++)
		{
			int matchedWord = 0;
			for (int j = 0; j < L.size(); j ++)
				checkList[j] = 0;
			for (int j = i; j + wordLen <= S.size(); j += wordLen)
			{
				int wordCnt = (j - i) / wordLen;
				string crntStr = S.substr(j, wordLen);
				unordered_map<string, wordStat>::iterator itr = m.find(crntStr);
				if (itr != m.end())
				{
					checkList[itr->second.no] ++;
					if (checkList[itr->second.no] <= m[crntStr].num)
						matchedWord ++;
				}
				string prevStr;
				if (wordCnt >= L.size())
				{
					prevStr = S.substr(j - L.size() * wordLen, wordLen);
					itr = m.find(prevStr);
					if (itr != m.end())
					{
						if (checkList[itr->second.no] <= m[prevStr].num)
							matchedWord --;
						checkList[itr->second.no] --;
					}
				}
				if (matchedWord == L.size())
					ans.push_back(j - (L.size() - 1) * wordLen);
			}
		}
		delete checkList;
		return ans;
    }
};