//	Problem	:	ZigZag Conversion
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	25 ms
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int nRows) {
        string ans;
        if (nRows == 1) return s;
        else if (nRows == 2)
        {
            for (int i = 0; i < s.size(); i += 2)
                ans += s[i];
            for (int i = 1; i < s.size(); i += 2)
                ans += s[i];
            return ans;
        }
        
        for (int i = 0; i < s.size(); i += nRows *2 - 2)
            ans += s[i];
        for (int i = 1; i < nRows - 1; i ++)
        {
            for (int j = i; j < s.size(); j += nRows * 2 - 2)
            {
                ans += s[j];
                int next_pos = (j - i) + (nRows * 2 - 2) - i - 1;
                if (next_pos < s.size())
                    ans += s[next_pos];
            }
        }
        for (int i = nRows - 1; i < s.size(); i += nRows * 2 - 2)
            ans += s[i];
        return ans;
    }
};