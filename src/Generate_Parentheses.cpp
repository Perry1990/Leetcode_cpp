//	Problem	:	Generate Parentheses
//	Author	:	perry1990
//	Date	:	2015/2/19
//	Runtime	:	5 ms
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> ans;
	void generate(string ans_str, int crnt, int stack, int n)
	{
		if (crnt == n)
		{
			ans_str = ans_str + "()";
			for (int i = 0; i < stack; i ++)
				ans_str = ans_str + ")";
			ans.push_back(ans_str);
			return;
		}
		ans_str = ans_str + "(";
		generate(ans_str, crnt + 1, stack + 1, n);
		for (int i = 0; i < stack + 1; i ++)
		{
			ans_str = ans_str + ")";
			generate(ans_str, crnt + 1, stack - i, n);
		}
	}
	
	vector<string> generateParenthesis(int n) {
        string ans_str;
		generate(ans_str, 1, 0, n);
		return ans;
    }
};