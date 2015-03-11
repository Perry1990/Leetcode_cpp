//	Problem	:	Wildcard Matching
//	Author	:	perry1990
//	Date	:	2015/3/10
//	Runtime	:	52 ms
/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool **f;
		int len_s = strlen(s);
		int len_p = strlen(p);
		int tmp = 0, cnt = 0;
		
		while (p[tmp] != '\0')
		    if (p[tmp ++] != '*')
		        cnt ++;
		if (cnt > len_s)
		    return false;
			
		f = new bool*[len_s + 1];
		for (int i = 0; i <= len_s; i ++)
			f[i] = new bool[len_p + 1];
		f[0][0] = 1;
		
		for (int i = 1; i <= len_s; i ++)
			f[i][0] = 0;
		for (int i = 1; i <= len_p; i ++)
			if (p[i-1] == '*')
				f[0][i] = f[0][i-1];
			else
				f[0][i] = 0;
				
		for (int i = 1; i <= len_s; i ++)
		{
			for (int j = 1; j <= len_p; j ++)
			{
				f[i][j] = 0;
				if (p[j-1] == '*' && (f[i-1][j] || f[i][j-1] || f[i-1][j-1]))
					f[i][j] = 1;
				else if (p[j-1] == '?' && f[i-1][j-1])
					f[i][j] = 1;
				else if (s[i-1] == p[j-1] && f[i-1][j-1])
					f[i][j] =1;
			}
		}
		bool ans = f[len_s][len_p];
		for (int i = 0; i <= len_s; i ++)
			delete f[i];
		delete f;
		return ans;
    }
};