//	Problem	:	Valid Parentheses
//	Author	:	perry1990
//	Date	:	2015/2/19
//	Runtime	:	2 ms
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0 || s.size() % 2 == 1)
			return false;
		vector<char> paren_type;
		int num = 0;
		for (int i = 0; i < s.size(); i ++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				num ++;
				paren_type.push_back(s[i]);
			}
			else {
				if (num == 0) return false;
				num --;
				char ch = paren_type.back();
				if (ch == '(' && s[i] != ')' || ch == '[' && s[i] != ']' || ch == '{' && s[i] != '}')
					return false;
				paren_type.pop_back();
			}
		}
		if (num == 0)
			return true;
		else
			return false;
    }
};