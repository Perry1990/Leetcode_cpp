//	Problem	:	Container With Most Water
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	47 ms
/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string getNum(int a, char x, char y, char z)
    {
        string ans;
        switch(a) {
            case 0: break;
            case 1: ans = x; break;
            case 2: for (int i = 0; i < 2; i++) ans += x; break;
            case 3: for (int i = 0; i < 3; i++) ans += x; break;
            case 4: ans += x; ans += y; break;
            case 5: ans = y; break;
            case 6: ans +=y; ans += x; break;
            case 7: ans = y; for (int i = 0; i < 2; i++) ans += x; break;
            case 8: ans = y; for (int i = 0; i < 3; i++) ans += x; break;
            case 9: ans +=x; ans += z; break;
        }
        return ans;
    }
    
    string intToRoman(int num) {
        string ans;
        int a = num % 10;
        ans = getNum(a, 'I', 'V', 'X') + ans;
        num /= 10;
        if (num == 0) return ans;
        
        a = num % 10;
        ans = getNum(a, 'X', 'L', 'C') + ans;
        num /= 10;
        if (num == 0) return ans;
        
        a = num % 10;
        ans = getNum(a, 'C', 'D', 'M') + ans;
        num /= 10;
        if (num == 0) return ans;
        
        a = num % 10;
        for (int i = 0; i < a; i ++)
            ans = "M" + ans;
        return ans;
    }
};