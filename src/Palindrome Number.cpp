//	Problem	:	Palindrome Number
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	122 ms
/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int target = 0, source = x;
        while (x != 0)
        {
            target = target * 10 + x % 10;
            x /= 10;
        }
        return target == source;
    }
};