//	Problem	:	Longest Palindromic Substring
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	88 ms
/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int j, len, max_len = 0, start_pnt = 0, palindrome_type = 0;
        for (int i = 0; i < s.size(); i ++)
        {
            j = i - 1;
            len = 1;
            while (j >= 0 && i + (i - j) < s.size())
            {
                if (s[j] == s[i + i - j])
                    len += 2;
                else break;
                j --;
            }
            if (len > max_len)
            {
                max_len = len;
                start_pnt = i;
                palindrome_type = 1;
            }
            if (i + 1 == s.size())
                break;
            j = i - 1;
            len = 2;
            while (j >= 0 && i + i - j + 1 < s.size())
            {
                if (s[j] == s[i + i - j + 1])
                    len += 2;
                else break;
                j--;
            }
            if (len > max_len && s[i] == s[i + 1])
            {
                max_len = len;
                start_pnt = i;
                palindrome_type = 2;
            }
        }
        string ans;
        start_pnt = start_pnt - ((max_len + 1) / 2 - 1);
        ans = s.substr(start_pnt, max_len);
        return ans;
    }
};