//	Problem	:	Longest Substring Without Repeating Characters
//	Author	:	perry1990
//	Date	:	2015/2/12
//	Runtime	:	101 ms
/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
private:
    map<char, int> m;
    int max_length = 0;
public:
    int lengthOfLongestSubstring(string s) {
        int crnt_length = 0, substr_start = 0;
        for (int i = 0; i < s.length(); i ++)
        {
            map<char, int>::iterator it;
            it = m.find(s[i]);
            if (it != m.end() && substr_start <= it->second)
            {
                if (max_length < crnt_length)
                    max_length = crnt_length;
                crnt_length = i - m[s[i]];
                substr_start = m[s[i]] + 1;
                m[s[i]] = i;
            } else
            {
                m[s[i]] = i;
                crnt_length ++;
            }
        }
        if (max_length < crnt_length)
            max_length = crnt_length;
        return max_length;
    }
};