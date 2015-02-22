//	Problem	:	Remove Duplicates from Sorted Array
//	Author	:	perry1990
//	Date	:	2015/2/21
//	Runtime	:	35 ms
/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int i = 0, j = 0;
		while (i < n && j < n)
		{
			A[i] = A[j];
			while (j + 1 < n && A[j] == A[j + 1])
				j ++;
			i ++;
			j ++;
		}
		return i;
    }
};