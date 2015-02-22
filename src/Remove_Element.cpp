//	Problem	:	Remove Element
//	Author	:	perry1990
//	Date	:	2015/2/21
//	Runtime	:	5 ms
/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = 0;
		while (i < n && j < n)
		{
			while (j < n && A[j] == elem)
				j ++;
			if (j < n)
			{
				A[i] = A[j];
				i ++; j ++;
			}
		}
		return i;
    }
};