//	Problem	:	Reverse Integer
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	13 ms
/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
    int reverse(int x) {
        int flag = x < 0 ? -1 : 1;
        int ans = 0;
        x *= flag;
        while (x > 0)
        {
            if (INT_MAX / 10 < ans || INT_MAX - ans * 10 < x % 10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans * flag;
    }
};