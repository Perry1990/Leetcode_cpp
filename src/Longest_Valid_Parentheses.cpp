//	Problem	:	Longest Valid Parentheses
//	Author	:	perry1990
//	Date	:	2015/2/22
//	Runtime	:	25 ms
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#define N 256
class Solution {
public:
    int longestValidParentheses(string s) {
		int ans = 0, pos[N], num = 0;
		for (int i = 0; i < N; i ++)
			pos[i] = -1;
		for (int i = 0; i < s.size(); i ++)
		{
			if (s[i] == '(')
			{
				num ++;
				if (pos[num] == -1)
					pos[num] = i;
			}
			else if (s[i] == ')')
			{
				if (num > 0)
				{
					int len = i - pos[num] + 1;
					if (len > ans)
						ans = len;
					pos[num + 1] = -1;
					num --;
				}
				else
				    pos[num + 1] = -1;
			}
		}
		return ans;
    }
};