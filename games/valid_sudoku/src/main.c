/**
 * THIS CODE IS FROM GEEKS FOR GEEKS, HOW STUPID AM I??
*/

#include <stdio.h>

#define MAX_CHAR_BUFFER 100

// sudoku board
int board1[9][9] = {
	{0,0,0,	7,0,0,	0,0,2},
	{0,0,1,	6,0,0,	8,0,0},
	{0,2,8,	0,1,9,	0,0,0},

	{3,8,9,	0,0,2,	7,0,0},
	{1,0,0,	9,0,4,	5,8,0},
	{0,5,4,	0,7,3,	9,2,0},

	{5,0,7,	0,9,6,	0,1,0},
	{8,9,0,	0,0,1,	0,0,7},
	{0,0,3,	0,0,7,	4,6,9}
};

int board2[9][9] = {
	{5,3,0,	0,7,0,	0,0,0},
	{6,0,0,	1,9,5,	0,0,0},
	{0,9,8,	0,0,0,	0,6,0},

	{8,0,0,	0,6,0,	0,0,3},
	{4,0,0,	8,0,3,	0,0,0},
	{7,0,0,	0,2,0,	0,0,6},

	{0,6,0,	0,0,0,	2,8,0},
	{0,0,0,	4,1,9,	0,0,5},
	{0,0,0,	0,8,0,	0,7,9}
};

/* CHECK FOR DUPLICATES FUNCTIONS */
int check_row_duplicates(int board[9][9], int pn, int py, int px)
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

int check_column_duplicates(int board[9][9], int pn, int py, int px)
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

int check_box_duplicates(int board[9][9], int pn, int py, int px)
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
int check_board(int board[9][9])
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
				if (check_row_duplicates(board, n,y,x) ||
					check_column_duplicates(board, n,y,x) || 
					check_box_duplicates(board,n,y,x))
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

// Checks whether it will be 
// legal to assign num to the
// given row, col
int check_safe(int grid[9][9], int row, 
				int col, int num)
{
    // Check if we find the same num 
    // in the similar row , we
    // return 0
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return 0;

    // Check if we find the same num in 
    // the similar column , we
    // return 0
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return 0;

    // Check if we find the same num in 
    // the particular 3*3 matrix,
    // we return 0
    int startRow = row - row % 3, 
            startCol = col - col % 3;

	// loop over 3x3 box
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + 
                            startCol] == num)
                return 0;

    return 1;
}

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
int solve_board(int grid[9][9], int row, int col)
{
    // Check if we have reached the 8th 
    // row and 9th column (0
    // indexed matrix) , we are 
    // returning 1 to avoid
    // further backtracking
    if (row == 9 - 1 && col == 9)
        return 1;

    // Check if column value  becomes 9 , 
    // we move to next row and
    //  column start from 0
    if (col == 9) {
        row++;
        col = 0;
    }
  
    // Check if the current position of 
    // the grid already contains
    // value >0, we iterate for next column
    if (grid[row][col] > 0)
        return solve_board(grid, row, col + 1);

    for (int num = 1; num <= 9; num++) 
    {
        
        // Check if it is safe to place 
        // the num (1-9)  in the
        // given row ,col  ->we 
        // move to next column
        if (check_safe(grid, row, col, num)) 
        {
            
           /* Assigning the num in 
              the current (row,col)
              position of the grid
              and assuming our assigned 
              num in the position
              is correct     */
            grid[row][col] = num;
          
            //  Checking for next possibility with next
            //  column
            if (solve_board(grid, row, col + 1))
                return 1;
        }
      
        // Removing the assigned num , 
        // since our assumption
        // was wrong , and we go for 
        // next assumption with
        // diff num value
        grid[row][col] = 0;
    }
    return 0;
}

int main(int argc, char** argv)
{
	printf("STARTING BOARD\n\n");
	check_board(board1);

	solve_board(board1, 0, 0);

	// print finished board
	printf("FINISHED BOARD\n\n");
	check_board(board1);

	return 1;
}
