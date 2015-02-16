//	Problem	:	Regular Expression Matching
//	Author	:	perry1990
//	Date	:	2015/2/15
//	Runtime	:	36 ms
/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
*/
#define N 500

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int len_s = 0, len_p = 0;
		int crnt_pos, type[N], f[N][N];
		char chr[N];
        while (s[len_s] != '\0')
            len_s ++;
        while (p[len_p] != '\0')
            len_p ++;
        crnt_pos = -1;
        for (int i = 0; i < len_p; i ++)
        {
            if (p[i] == '.')
            {
                crnt_pos ++;
                chr[crnt_pos] = '.';
                type[crnt_pos] = 3;
            }
            else if (p[i] != '*')
            {
                crnt_pos ++;
                chr[crnt_pos] = p[i];
                type[crnt_pos] = 1;
            }
            else if (p[i] == '*')
                type[crnt_pos] ++;
        }
        len_p = crnt_pos + 1;
		f[0][0] = 1;
		for (int i = 1; i <= len_s; i ++)
			f[i][0] = 0;
		for (int j = 1; j <= len_p; j ++)
		{
			if ((type[j-1] == 2 && f[0][j-1]) || (type[j-1] == 4 && f[0][j-1]))
				f[0][j] = 1;
			else f[0][j] = 0;
			for (int i = 1; i <= len_s; i ++)
			{
				if ((type[j-1] == 1 && s[i-1] == chr[j-1] && f[i-1][j-1]) || (type[j-1] == 2 && ((s[i-1] == chr[j-1] && f[i-1][j-1]) || f[i][j-1] || (s[i-1] == chr[j-1] && f[i-1][j])))
					|| (type[j-1] == 3 && f[i-1][j-1]) || (type[j-1] == 4 && (f[i-1][j-1] || f[i][j-1] || f[i-1][j])))
					f[i][j] = 1;
				else f[i][j] = 0;
			}
		}
		for (int i = 0; i <= len_p; i ++)
		{
			for (int j = 0; j <= len_s; j ++)
				cout << f[j][i] << " ";
			cout << endl;
		}
		if (f[len_s][len_p]) return true;
		else return false;
    }
};