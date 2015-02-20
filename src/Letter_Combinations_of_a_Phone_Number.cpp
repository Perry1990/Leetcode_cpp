//	Problem	:	Letter Combinations of a Phone Number
//	Author	:	perry1990
//	Date	:	2015/2/19
//	Runtime	:	2 ms
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
		string dig2abc[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		int total_comb = 1;
		
		if (digits.size() == 0)
		{
			ans.push_back("");
			return ans;
		}
		for (int i = 0; i < digits.size(); i ++)
			total_comb *= dig2abc[digits[i] - '0'].size();
		for (int i = 0; i < total_comb; i ++)
		{
			int crnt_num = i;
			string ans_str;
			ans_str.clear();
			for (int j = 0; j < digits.size(); j ++)
			{
				ans_str = ans_str + dig2abc[digits[j] - '0'][crnt_num % dig2abc[digits[j] - '0'].size()];
				crnt_num = crnt_num / dig2abc[digits[j] - '0'].size();
			}
			ans.push_back(ans_str);
		}
		return ans;
    }
};