//	Problem	:	Next Permutation
//	Author	:	perry1990
//	Date	:	2015/2/22
//	Runtime	:	15 ms
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() == 0 || num.size() == 1) return;
		int i = num.size() - 1;
		while (i > 0 && num[i - 1] >= num[i])
			i --;
		if (i == 0)
			sort(num.begin(), num.end());
		else
		{
			int min_no = i;
			for (int j = i; j < num.size(); j ++)
				if (num[j] < num[min_no] && num[j] > num[i - 1])
					min_no = j;
			int tmp = num[min_no];
			num[min_no] = num[i - 1];
			num[i - 1] = tmp;
			sort(num.begin() + i, num.end());
		}
		return;
    }
};