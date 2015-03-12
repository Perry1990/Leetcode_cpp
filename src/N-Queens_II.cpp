//	Problem	:	N-Queens II
//	Author	:	perry1990
//	Date	:	2015/3/11
//	Runtime	:	5 ms
/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int ans;
	void solve(int lvl, int n, int *board)
	{
		if (lvl == n)
		{
			ans ++;
			return;
		}
		
		for (int i = 0; i < n; i ++)
		{
			int j;
			for (j = 0; j < lvl; j ++)
				if (board[j] == i || i - lvl == board[j] - j || i + lvl == board[j] + j)
					break;
			if (j == lvl || !lvl)
			{
				board[lvl] = i;
				solve(lvl + 1, n, board);
			}
		}
	}
	
	int totalNQueens(int n) {
        int *board = new int[n];
		solve(0, n, board);
		return ans;
    }
};