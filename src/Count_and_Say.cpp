//	Problem	:	Count and Say
//	Author	:	perry1990
//	Date	:	2015/3/8
//	Runtime	:	14 ms
/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
		string str = "1";
		for (int i = 1; i < n; i ++)
		{
			int j = 0;
			string new_str;
			while (j < str.size())
			{
				int same_num = 1;
				while (j + 1 < str.size() && str[j] == str[j + 1])
				{
					j ++;
					same_num ++;
				}
				new_str = new_str + to_string(same_num);
				new_str = new_str + str[j];
				j ++;
			}
			str = new_str;
		}
		return str;
    }
};