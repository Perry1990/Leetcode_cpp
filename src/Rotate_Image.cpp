//	Problem	:	Rotate Image
//	Author	:	perry1990
//	Date	:	2015/3/11
//	Runtime	:	6 ms
/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for (int i = 0; i < matrix.size() / 2; i ++)
		{
			for (int j = i; j < matrix.size() - i - 1; j ++)
			{
				int i90 = j, j90 = matrix.size() - 1 - i;
				int i180 = matrix.size() - 1 - i, j180 = matrix.size() - 1 - j;
				int i270 = matrix.size() - 1 - j, j270 = i;
				int tmp = matrix[i90][j90];
				matrix[i90][j90] = matrix[i][j];
				matrix[i][j] = matrix[i270][j270];
				matrix[i270][j270] = matrix[i180][j180];
				matrix[i180][j180] = tmp;
			}
		}
    }
};