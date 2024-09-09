/**
 * soduko board validat	or
*/

#include <stdio.h>

#define MAX_CHAR_BUFFER 100
#define SET_BIT(x, pos) ((x) | (1U << pos))
#define TOGGLE_BIT(x, pos) ((x) ^ (1U << pos))

// sudoku board
int __board[9][9] = {
	{0,0,0,	7,0,0,	0,9,2},
	{9,3,1,	6,0,0,	8,0,0},
	{0,2,8,	0,1,9,	0,0,0},

	{3,8,9,	1,5,2,	7,0,0},
	{1,7,2,	9,6,4,	5,8,0},
	{6,5,4,	0,7,3,	9,2,0},

	{5,4,7,	3,9,6,	2,1,8},
	{8,9,6,	0,0,1,	0,0,7},
	{0,1,3,	0,0,7,	4,6,9}
};

int _board[9][9] = {
	{4,6,5,	7,3,8,	1,9,2},
	{9,3,1,	6,2,5,	8,7,4},
	{7,2,8,	4,1,9,	6,3,5},

	{3,8,9,	1,5,2,	7,4,6},
	{1,7,2,	9,6,4,	5,8,3},
	{6,5,4,	8,7,3,	9,2,1},

	{5,4,7,	3,9,6,	2,1,8},
	{8,9,6,	2,4,1,	3,5,7},
	{2,1,3,	5,8,7,	4,6,9}
};

int board[9][9] =
{
	{0,6,5, 7,0,0,	0,9,2},   
	{9,3,1, 6,0,0,	8,0,0},
	{7,2,8, 0,1,9,	0,0,0},

	{3,8,9, 1,5,0,	7,4,6},
	{1,7,2, 9,0,4,	0,8,3},
	{6,5,4, 8,7,3,	9,2,1},

	{5,0,7, 3,9,6,	2,0,8},
	{8,0,0, 0,0,1,	3,5,7},
	{2,1,3, 0,0,0,	4,6,9}
};

/* CHECK FOR DUPLICATES FUNCTIONS */
int check_row_duplicates(int pn, int py, int px)
{
	for(int x = 0; x < 9; x++)
	{
		if (px==x)
			continue;
		if(pn == board[py][x])
			return 1;
	}
	return 0;
}

int check_column_duplicates(int pn, int py, int px)
{ 
	for(int y = 0; y < 9; y++)
	{
		if (py==y)
			continue;
		if(pn == board[y][px])
			return 1;
	}
	return 0;
}

int check_box_duplicates(int pn, int py, int px)
{
	// make offsets 
	int offset_x = (px/3) * 3;
	int offset_y = (py/3) * 3;
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			if((px == offset_x+x) && (py == offset_y+y))
				continue;

			if(pn == board[offset_y+y][offset_x+x])
				return 1;
		}
	}
	return 0;
}

/* BOARD CHECKING FUNCTIONS */
int check_board()
{
	int board_valid = 1;
	for(int y = 0; y < 9; y++)
	{
		for(int x = 0; x < 9; x++)
		{
			int n = board[y][x];
			// if current index isn't zero then perform checks
			if (board[y][x] != 0)
			{
				// check if row, column and box has no duplicates
				if (check_row_duplicates(n,y,x) || check_column_duplicates(n,y,x) || check_box_duplicates(n,y,x))
				{
					board_valid = 0;
					printf(" ! ");
				}
				else
					printf(" %d ", n);
			} else {
				printf(" %d ", n);
			}

			if (((x + 1 )% 3) == 0)
			{
				printf("  ");
			}
		}
		if (((y + 1 )% 3) == 0)
		{
			printf("\n");
		}
		printf("\n");
	}
	
	printf("%s\n", (board_valid) ? "Board Valid" : "Board Invalid");

	return board_valid;
}

int check_complete()
{
	for(int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if(board[y][x] < 0)
				return 1;
		}
	}
	return 0;
}

/* FILL OBVIOUS MISSING NUMBERS */
int check_empty_values_in_box(int px, int py)
{
	// make offsets 
	int offset_x = (px/3) * 3;
	int offset_y = (py/3) * 3;
	int n=0;
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			if (board[offset_y+y][offset_x+x] == 0)
				n++;
		}
	}
	return n;
}

void fill_last_number_in_box(int px, int py)
{
	int n[10] = {0};	// store array of available numbers in box
	int tn = 0; // missing number
	int offset_x = (px/3) * 3;
	int offset_y = (py/3) * 3;

	// store all non zero numbers
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			int index = board[offset_y+y][offset_x+x];
			if (index > 0)
				n[index] = index;
		}
	}

	// identify missing number from 1-9
	for(int i = 1; i < 10; i++)
	{
		if(n[i] == 0)
		{
			tn = i;
		}
	}

	// fill the empty index with the missing number
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			int index = board[offset_y+y][offset_x+x];
			// need to break this but eh
			if (index ==  0)
				board[offset_y+y][offset_x+x] = tn;
		}
	}
}

int check_empty_values_in_row(int px, int py, int bounds)
{
	// make offsets 
	int n=0;
	for(int x = 0; x < bounds; x++)
	{
		if(board[py][x] == 0)
			n++;
	}
	return n;
}

void fill_last_number_in_row(int px, int py)
{
	int n[10] = {0};
	int tn = 0;
	for(int x = 0; x < 9; x++)
	{
		if(board[py][x] > 0)
			n[board[py][x]] = board[py][x];
	}
	for(int x = 1; x <= 9; x++)
	{
		if(n[x] == 0)
			tn = x;
	}
	for(int x = 0; x < 9; x++)
	{
		if(board[py][x] == 0)
			board[py][x] = tn;
	}
}

int check_empty_values_in_column(int px, int py, int bounds)
{
	// make offsets 
	int n=0;
	for(int y = 0; y < bounds; y++)
	{
		if(board[y][px] == 0)
			n++;
	}
	return n;
}

void fill_last_number_in_column(int px, int py)
{
	int n[10] = {0};
	int tn = 0;
	for(int y = 0; y < 9; y++)
	{
		if(board[y][px] > 0)
			n[board[y][px]] = board[y][px];
	}
	for(int y = 1; y <= 9; y++)
	{
		if(n[y] == 0)
			tn = y;
	}
	for(int y = 0; y < 9; y++)
	{
		if(board[y][px] == 0)
			board[y][px] = tn;
	}
}

// TODO: when checking for neighbors, some boxes are already filled,
int check_neighbors(int pn, int px, int py)
{
	int offset_x = (px/3) * 3;
	int offset_y = (py/3) * 3;
	int n[3][3] = {0}; //012 //012
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			// TODO: theres an issue where in the index is going to be 0
			if(((offset_y+y) == py) && ((offset_x+x) == px))
			{
				// check the direct row and column within the box if they're clear
				for(int i = 0; i < 3; i++)
				{
					n[i][x] = (board[offset_y+i][offset_x+x] > 0 ? 1 : 0);
					n[y][i] = (board[offset_y+y][offset_x+i] > 0 ? 1 : 0);
				}
				continue;
			}
			if(check_column_duplicates(pn,offset_y+y, offset_x+x))
			{
				for(int i = 0; i < 3; i++)
				{
					n[i][x] = 1;
				}
			} else {
				for(int i = 0; i < 3; i++)
				{
					n[i][x] = (board[offset_y+i][offset_x+x] > 0 ? 1 : 0);
				}
			}
			if(check_row_duplicates(pn,offset_y+y, offset_x+x))
			{
				for(int i = 0; i < 3; i++)
				{
					n[y][i] = 1;
				}
			} else {
				for(int i = 0; i < 3; i++)
				{
					n[y][i] = (board[offset_y+y][offset_x+i] > 0 ? 1 : 0);
				}
			}
		}
	}
	// n[py%3][px%3] = 1;
	int d = 0;
	for(int y = 0; y < 3; y++)
	{
		for(int x = 0; x < 3; x++)
		{
			if(n[y][x] != 0)
				d++;
		}
	}
	if (d > 1)
		return 1;
	return 0;
}

// TODO: implement backtracking
void solve_board()
{
	for(int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			// Check if a box has only one left number left to be filled
			if(check_empty_values_in_box(y,x)==1)
				fill_last_number_in_box(y,x);

			if(check_empty_values_in_row(y,x,9)==1)
				fill_last_number_in_row(y,x);

			if(check_empty_values_in_column(y,x,9)==1)
				fill_last_number_in_column(y,x);

			// skip filled values
			int index = board[y][x];
			if(index>0)
				continue;

			for (int i = 1; i <= 9; i++)
			{
				// skip values with duplicates
				if(check_row_duplicates(i,y,x) || check_column_duplicates(i,y,x) || check_box_duplicates(i,y,x))
						continue;
				if(check_neighbors(i,y,x))
				{
					board[y][x] = i;
					break;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	printf("STARTING BOARD\n\n");
	check_board();

	// if(!check_board())
	// 	return 0;

	// for(int i = 0; i < ; i++)
	// {
		solve_board();
	// }

	// check_neighbors(3,8,7);

	// printf("%d\n", check_empty_values_in_box(0,0));

	// print finished board
	printf("FINISHED BOARD\n\n");
	check_board();

	return 1;
}
