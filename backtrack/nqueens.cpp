/**
 * The N Queens problem. Place n queens on a chess board of size
 * n x n such that no queen can attack another 
 * 
 */

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool CanPlace(const vector<int>& placed, int x1, int y1)
{
  for (int x0 = 0; x0 < placed.size(); ++x0) {
    int y0 = placed[x0];
    if (x0 == x1 || y0 == y1 || abs(x1 - x0) == abs(y1 - y0)) {
      return false;
    }
  }
  return true;
}

void FindQueens(const vector<int>& queens, int n)
{
  if (queens.size() == n) {
    for (int i = 0; i < n; ++i)
      cout << queens[i] << " ";
    cout << endl;
    return;
  }

  int x = queens.size();
  for (int y = 0; y < n; ++y) {
    if (CanPlace(queens, x, y)) {
      vector<int> new_queens;
      new_queens.assign(queens.begin(), queens.end());
      new_queens.push_back(y);
      FindQueens(new_queens, n);
    }
  }
}

void FindAllQueens(int n)
{
  for (int y = 0; y < n; ++y) {
    vector<int> queens;
    queens.push_back(y);
    FindQueens(queens, n);
  }
}

int main(int argc, const char** argv)
{
  if (argc != 2)
    return 1;

  int n = atoi(argv[1]);

  cout << n << " queens: " << endl;
  FindAllQueens(n);

  return 0;
}
