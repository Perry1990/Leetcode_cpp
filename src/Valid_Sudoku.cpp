//	Problem	:	Valid Sudoku
//	Author	:	perry1990
//	Date	:	2015/2/22
//	Runtime	:	18 ms
/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9)
			return false;
		for (int i = 0; i < 9; i ++)
			if (board[i].size() != 9)
				return false;
		for (int i = 0; i < 9; i ++)
		{
			int table[10];
			for (int j = 0; j <= 9; j ++)
				table[j] = 0;
			for (int j = 0; j < 9; j ++)
				if ((board[i][j] < '1' || board[i][j] > '9') && board[i][j] != '.' || (board[i][j] - 48 <= 9 && board[i][j] - 48 >= 0 && table[board[i][j] - 48]))
					return false;
				else 
					if (board[i][j] != '.')
						table[board[i][j] - 48] = 1;
		}
		for (int i = 0; i < 9; i ++)
		{
			int table[10];
			for (int j = 0; j <= 9; j ++)
				table[j] = 0;
			for (int j = 0; j < 9; j ++)
				if ((board[j][i] < '1' || board[j][i] > '9') && board[j][i] != '.' || (board[j][i] - 48 <= 9 && board[j][i] - 48 >= 0 && table[board[j][i] - 48]))
					return false;
				else 
					if (board[j][i] != '.')
						table[board[j][i] - 48] = 1;
		}
		for (int i = 0; i < 9; i ++)
		{
			int row_group = i / 3;
			int col_group = i % 3;
			int table[10];
			for (int j = 0; j <= 9; j ++)
				table[j] = 0;
			for (int j = row_group * 3; j < (row_group + 1) * 3; j ++)
				for (int k = col_group * 3; k < (col_group + 1) * 3; k ++)
					if ((board[i][j] < '1' || board[i][j] > '9') && board[i][j] != '.' || (board[j][k] - 48 <= 9 && board[j][k] - 48 >= 0 && table[board[j][k] - 48]))
						return false;
					else 
						if (board[j][k] != '.')
							table[board[j][k] - 48] = 1;
		}
		return true;
    }
};