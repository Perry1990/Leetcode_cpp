//	Problem	:	Multiply Strings
//	Author	:	perry1990
//	Date	:	2015/3/10
//	Runtime	:	15 ms
/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1; i >= 0; i --)
		{
			int carry = 0;
			for (int j = num2.size() - 1; j >= 0; j --)
			{
				int num = (num1[i] - 48) * (num2[j] - 48) + (ans[i + j + 1] - 48) + carry;
				carry = num / 10;
				ans[i + j + 1] = (num % 10) + 48;
			}
			ans[i] += carry;
		}
		
		int pos = 0;
		while (ans[pos] == '0' && pos < ans.size())
			pos ++;
		if (pos != ans.size())
		{
			ans = ans.substr(pos);
			return ans;
		}
		return "0";
    }
};