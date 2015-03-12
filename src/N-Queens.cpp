//	Problem	:	N-Queens
//	Author	:	perry1990
//	Date	:	2015/3/11
//	Runtime	:	8 ms
/*
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string> > ans;
	void solve(int lvl, int n, int *board)
	{
		if (lvl == n)
		{
			string str;
			vector<string> vec_string;
			for (int i = 0; i < n; i ++)
			{
				if (board[i] != 0) str.append(board[i], '.');
				str += 'Q';
				str.append(n - board[i] - 1, '.');
				vec_string.push_back(str);
				str.clear();
			}
			ans.push_back(vec_string);
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
	
	vector<vector<string> > solveNQueens(int n) {
        int *board = new int[n];
		solve(0, n, board);
		return ans;
    }
};