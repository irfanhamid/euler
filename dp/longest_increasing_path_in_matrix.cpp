/**
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 * 
 * [
  [9,9,4],
  [6,6,8],
  [2,1,1]
  ]

  [
  [3,4,5],
  [3,2,6],
  [2,2,1]
  ]  
 */

#include <cstdlib>
#include <vector>

using namespace std;

enum Direction {
    Up,
    Down,
    Left,
    Right
};

vector<int32_t> LongestIncreasingPath(const vector<vector<int32_t>>& matrix)
{
    vector<int32_t> path;

    // Initialize the memo table, assume rectangular input matrix
    vector<vector<size_t>> memo(matrix.size());
    for (size_t i = 0; i < matrix.size(); ++i)
        memo[i].resize(matrix[0].size());
    for (auto& v : memo) {
        for (size_t i = 0; i < v.size(); ++i)
            v[i] = __SIZE_MAX__;
    }

    return move(path);
}

void LongestIncreasingPathFrom(const vector<vector<int32_t>>& matrix,
                               vector<vector<size_t>>& memo,
                               vector<vector<Direction>>& dirMemo,
                               size_t x, size_t y)
{
    if (memo[x][y] != __SIZE_MAX__)
        return;
    
    if (x < matrix.size() && matrix[x+1][y] > matrix[x][y]) {
        LongestIncreasingPathFrom(matrix, memo, dirMemo, x+1, y);

    }
}

int main()
{
    return 0;
}