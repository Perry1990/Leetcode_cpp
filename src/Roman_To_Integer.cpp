//	Problem	:	Roman To Integer
//	Author	:	perry1990
//	Date	:	2015/2/18
//	Runtime	:	56 ms
/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int RTI(char a)
	{
		switch (a)
		{
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}
	
	int romanToInt(string s) {
        int ans = RTI(s[0]);
        for (int i = 1; i < s.size(); i ++)
        {
            if (RTI(s[i]) > RTI(s[i-1]))
				ans += RTI(s[i]) - RTI(s[i-1]) * 2;
			else
				ans += RTI(s[i]);
        }
		return ans;
    }
};