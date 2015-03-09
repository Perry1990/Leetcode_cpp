//	Problem	:	Sudoku Solver
//	Author	:	perry1990
//	Date	:	2015/3/8
//	Runtime	:	60 ms
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

class Solution {
public:
	struct pos
	{
		int x, y, num_avail;
	};
	struct compare
	{
		bool operator () (pos a, pos b) {return a.num_avail < b.num_avail;}
	};
	vector<pos> avail_list;
	
    bool solver(int lvl, int ***constraints, vector<vector<char>> &board)
	{
		if (lvl >= avail_list.size())
			return true;
		for (int i = 1; i <= 9; i ++)
		{
			if (constraints[avail_list[lvl].x][avail_list[lvl].y][i] == 1)
			{
				board[avail_list[lvl].x][avail_list[lvl].y] = i + 48;
				for (int k = 0; k < 9; k ++)
				{
					if (constraints[avail_list[lvl].x][k][i] == 1)
						constraints[avail_list[lvl].x][k][i] = -lvl;
					if (constraints[k][avail_list[lvl].y][i] == 1)
						constraints[k][avail_list[lvl].y][i] = -lvl;
				}
				for (int k = avail_list[lvl].x/3*3; k < (avail_list[lvl].x/3+1)*3; k ++)
					for (int l = avail_list[lvl].y/3*3; l < (avail_list[lvl].y/3+1)*3; l ++)
						if (constraints[k][l][i] == 1)
							constraints[k][l][i] = -lvl;
				if (solver(lvl + 1, constraints, board))
					return true;
				board[avail_list[lvl].x][avail_list[lvl].y] = '.';
				for (int k = 0; k < 9; k ++)
				{
					if (constraints[avail_list[lvl].x][k][i] == -lvl)
						constraints[avail_list[lvl].x][k][i] = 1;
					if (constraints[k][avail_list[lvl].y][i] == -lvl)
						constraints[k][avail_list[lvl].y][i] = 1;
				}
				for (int k = avail_list[lvl].x/3*3; k < (avail_list[lvl].x/3+1)*3; k ++)
					for (int l = avail_list[lvl].y/3*3; l < (avail_list[lvl].y/3+1)*3; l ++)
						if (constraints[k][l][i] == -lvl)
							constraints[k][l][i] = 1;
			}
		}
		return false;
	}
	
	void solveSudoku(vector<vector<char> > &board) {
        int ***constraints;
		constraints = new int**[9];
		for (int i = 0; i < 9; i ++)
		{
			constraints[i] = new int*[9];
			for (int j = 0; j < 9; j ++)
			{
				constraints[i][j] = new int[10];
				for (int k = 0; k <= 9; k ++)
					constraints[i][j][k] = 1;
			}
		}
		for (int i = 0; i < 9; i ++)
			for (int j = 0; j < 9; j ++)
			{
				if (board[i][j] == '.')
					continue;
				int num = board[i][j] - 48;
				for (int k = 0; k < 9; k ++)
				{
					constraints[i][k][num] = 0;
					constraints[k][j][num] = 0;
				}
				for (int k = i/3*3; k < (i/3+1)*3; k ++)
					for (int l = j/3*3; l < (j/3+1)*3; l ++)
						constraints[k][l][num] = 0;
			}
		for (int i = 0; i < 9; i ++)
			for (int j = 0; j < 9; j ++)
			{
				if (board[i][j] != '.')
					continue;
				int num_avail = 0;
				for (int k = 1; k <= 9; k ++)
					if (constraints[i][j][k])
						num_avail ++;
				pos _pos;
				_pos.x = i; _pos.y = j; _pos.num_avail = num_avail;
				avail_list.push_back(_pos);
			}
		sort(avail_list.begin(), avail_list.end(), compare());
		solver(0, constraints, board);
    }
};