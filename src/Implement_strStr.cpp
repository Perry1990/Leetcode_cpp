//	Problem	:	Implement strStr()
//	Author	:	perry1990
//	Date	:	2015/2/21
//	Runtime	:	5 ms
/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer.
If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int len1 = strlen(haystack), len2 = strlen(needle);
		for (int i = 0; i < len1 - len2 + 1; i ++)
		{
			int j = 0;
			while (j < len2 && haystack[i + j] == needle[j])
				j ++;
			if (j == len2)
				return i;
		}
		return -1;
    }
};