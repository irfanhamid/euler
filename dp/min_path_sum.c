/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which
 * minimizes the sum of all numbers along its path. You can only move to the right or down in the grid.
 */

#include <stdio.h>

int grid[][3] = {
  { 1, 3, 1 },
  { 1, 5, 1 },
  { 4, 2, 1 }
};

int min_path_sum(int grid[][3], int rows, int cols)
{
  int path_sums[][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 }
  };

  path_sums[rows-1][cols-1] = grid[rows-1][cols-1];
  for (int y = rows-2; y >= 0; --y)
    path_sums[y][cols-1] = path_sums[y+1][cols-1] + grid[y][cols-1];
  for (int x = cols-2; x >= 0; --x)
    path_sums[rows-1][x] = path_sums[rows-1][x+1] + grid[rows-1][x];
  

  for (int y = rows-2; y >=0; --y) {
    for (int x = cols-2; x >= 0; --x) {
      if (path_sums[y+1][x] > path_sums[y][x+1])
        path_sums[y][x] = grid[y][x] + path_sums[y][x+1];
      else
        path_sums[y][x] = grid[y][x] + path_sums[y+1][x];
    }
  }
  return path_sums[0][0];
}

int main(int argc, const char** argv)
{
  printf("%d\n", min_path_sum(grid, 3, 3));
  return 0;
}
