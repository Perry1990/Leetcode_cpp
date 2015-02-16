//	Problem	:	String to Integer (atoi)
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	16 ms
/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases.
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated.
If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

class Solution {
public:
    int atoi(string str) {
        int i = 0;
        if (str.length() == 0)
            return 0;
        while (str[i] == ' ')
            i ++;
        int start_pos = i, flag= 0;
        int ans = 0;
        if (str[i] == '+')
        {
            flag = 1;
            i ++;
        }
        else if (str[i] == '-')
        {
            flag = -1;
            i ++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
            flag = 1;
        else return 0;
        while (str[i] >= '0' && str[i] <= '9' && i < str.length())
        {
            if (INT_MAX / 10 < ans || (INT_MAX / 10 == ans && INT_MAX % 10 < str[i] - 48))
                ans = INT_MAX;
            else if (INT_MIN / 10 > ans || (INT_MIN / 10 == ans && (abs)(INT_MIN % 10) < str[i] - 48))
                ans = INT_MIN;
            else
                ans = ans * 10 + (str[i] - 48) * flag;
            i ++;
        }
        return ans;
    }
};