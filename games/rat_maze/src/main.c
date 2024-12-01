#include <stdio.h>
#include "color.h"

#define N 8

void print_maze(int maze[N][N], int start_x, int start_y, int end_x, int end_y)
{
    for(int h = 0; h < N; h++)
    {
        printf("\t\t");
        for (int w = 0; w < N; w++)
        {
            ((h == start_y && w == start_x) ?
            printf("%s", BACKGROUND_TEXT(45, "  "))
            :
                ((h == end_y && w == end_x ) ?
                printf("%s", BACKGROUND_TEXT(45, "  "))
                :
                    printf("%s", (
                        maze[h][w] ? 
                        BACKGROUND_TEXT(41, "  ") : BACKGROUND_TEXT(42, "  ")
                    ))
                )
            );
            // printf(" %d ", maze[h][w]);
        }
        printf("\n");
    }
}

int is_safe(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x >= 0 && x < N && y >= 0 && y < N && maze[y][x] == 0 && sol[y][x] == 1)
        return 1;
    else
        return 0;
}

int solve_maze_util(int maze[N][N], int x, int y, int sol[N][N])
{
    // if x and y are at the finished index at the bottom right corner
    if (x == N - 1 && y == N -1)
    {
        sol[y][x] = 1;
        return 1;
    }

    // FIXED: infinite loop occurs when moving index back and forth
    // this happens because the subroutine below cannot proceed to the
    // third and fourth if statement...
    // FIXED: we need to also track the filled cells in the is_safe function
    // with sol[y][x] == 1
    if (is_safe(maze, x, y, sol))
    {
        sol[y][x] = 0;
        // move up
        if (solve_maze_util(maze, x, y - 1,sol))
            return 1;
        // move right
        if (solve_maze_util(maze, x + 1, y,sol))
            return 1;
        // move down
        if (solve_maze_util(maze, x, y + 1,sol))
            return 1;
        // move left
        if (solve_maze_util(maze, x - 1, y,sol))
            return 1;
        // if neither works, backtrack and unmark the current index as the valid route
        sol[y][x] = 1;
        return 0;
    }
    return 0;
}

int solve_maze(int maze[N][N])
{
    int sol[N][N] = {
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1}
    };
    // solve_maze_util(maze, 0, 0, sol);
    if (!solve_maze_util(maze, 0, 0, sol))
    {
        printf("No solution exists!");
        return 0;
    }
    print_maze(sol, 0, 0, N-1, N-1);
    return 1;
}

int main()
{
    int maze[N][N] = {
        {0,1,0,1,0,1,0,1},
        {0,0,0,0,0,1,0,1},
        {1,0,1,1,0,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,1,1,0,0,0,0,1},
        {0,1,1,0,1,1,1,1},
        {0,1,1,0,1,0,0,1},
        {0,0,0,0,0,0,0,0}
    };

    printf("initial maze: \n");
    print_maze(maze, 0, 0, N-1, N-1);
    printf("solved maze: \n");
    solve_maze(maze);

    return 0;

}