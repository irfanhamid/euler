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

#include <cstdint>
#include <vector>
#include <iostream>

using namespace std;

enum Direction {
    Up,
    Down,
    Left,
    Right
};

void LongestIncreasingPathFrom(const vector<vector<int32_t>>& matrix,
                               vector<vector<size_t>>& memo,
                               vector<vector<Direction>>& dirMemo,
                               size_t x, size_t y)
{
    if (memo[x][y])
        return;
    
    if (x < matrix.size()-1 && matrix[x+1][y] > matrix[x][y]) {
        LongestIncreasingPathFrom(matrix, memo, dirMemo, x+1, y);
        dirMemo[x][y] = Right;
        memo[x][y] = memo[x+1][y];
    }
    
    if (x > 0 && matrix[x-1][y] > matrix[x][y]) {
        LongestIncreasingPathFrom(matrix, memo, dirMemo, x-1, y);
        if (memo[x-1][y] > memo[x][y]) {
            dirMemo[x][y] = Left;
            memo[x][y] = memo[x-1][y];
        }
    }

    if (y < matrix[0].size()-1 && matrix[x][y+1] > matrix[x][y]) {
        LongestIncreasingPathFrom(matrix, memo, dirMemo, x, y+1);
        if (memo[x][y+1] > memo[x][y]) {
            dirMemo[x][y] = Down;
            memo[x][y] = memo[x][y+1];
        }
    }

    if (y > 0 && matrix[x][y-1] > matrix[x][y]) {
        LongestIncreasingPathFrom(matrix, memo, dirMemo, x, y-1);
        if (memo[x][y-1] > memo[x][y]) {
            dirMemo[x][y] = Up;
            memo[x][y] = memo[x][y-1];
        }
    }
    ++memo[x][y];
}

vector<int32_t> LongestIncreasingPath(const vector<vector<int32_t>>& matrix)
{
    vector<int32_t> path;

    // Initialize the memo table, assume rectangular input matrix
    vector<vector<size_t>> memo(matrix.size());
    vector<vector<Direction>> dirMemo(matrix.size());
    for (size_t i = 0; i < matrix.size(); ++i) {
        memo[i].resize(matrix[0].size());
        dirMemo[i].resize(matrix[0].size());
    }
    for (auto& v : memo) {
        for (size_t i = 0; i < v.size(); ++i)
            v[i] = 0;
    }

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            if (!memo[i][j])
                LongestIncreasingPathFrom(matrix, memo, dirMemo, i, j);
        }
    }

    // Find maximum path size
    size_t xMax = 0, yMax = 0;
    size_t maxPath = memo[0][0];
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            if (memo[i][j] > maxPath) {
                maxPath = memo[i][j];
                xMax = i;
                yMax = j;
            }
        }
    }

    while (true) {
        path.push_back(matrix[xMax][yMax]);
        if (memo[xMax][yMax] == 1)
            break;
        switch (dirMemo[xMax][yMax]) {
            case Up: --yMax; break;
            case Down: ++yMax; break;
            case Left: --xMax; break;
            case Right: ++xMax; break;
        }
    }

    return move(path);
}

int main()
{
    vector<vector<int32_t>> matrix = {
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };

    vector<int32_t> path = LongestIncreasingPath(matrix);
    for (auto i : path)
        cout << i << " -> ";
    cout << endl;

    vector<vector<int32_t>> matrix2 = {
        {3,4,5},
        {3,2,6},
        {2,2,1}
    };
    path = LongestIncreasingPath(matrix2);
    for (auto i : path)
        cout << i << " -> ";
    cout << endl;
    return 0;
}
