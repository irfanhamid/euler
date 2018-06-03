/**
 * Problem taken from https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
 * m represents a maze of n x n dimension where a 0 represents a wall, 1 represents a path.
 * A rat has to go (0,0) -> (n-1,n-1). Write an algorithm to print all possible  paths in
 * lexicographic order for the rat to reach destination.
 */

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> MazeT;

void TravelTo(int, int, int, int, const string&, MazeT&, const MazeT&);

string&& GetDirection(int x0, int y0, int x1, int y1)
{
  if (x0 == x1)
    return move(string(y0 < y1 ? "D" : "U"));
  return move(string(x0 < x1 ? "R" : "L"));
}

/**
 * Find all paths in the given maze from (0, 0) to (n-1, n-1)
 */
void FindPaths(const MazeT& m)
{
  // Initialize the visited matrix
  MazeT v;
  v.resize(m.size(), vector<int>(m.size(), 0));

  v[0][0] = 1;
  TravelTo(0, 0, 0, 1, "", v, m);
  TravelTo(0, 0, 1, 0, "", v, m);
}

void TravelTo(int x0, int y0, int x1, int y1, const string& prefix, MazeT& v, const MazeT& m)
{
  // If this is a wall, go back
  if (!m[x1][y1]) {
    return;
  }
  const size_t n = m.size();
  const string dir = GetDirection(x0, y0, x1, y1);

  if (x1 == n-1 && y1 == n-1) {
    cout << prefix.c_str() << dir << endl;
    return;
  }

  // If we've already been here, go back
  if (v[x1][y1]) {
    return;
  }
  v[x1][y1] = 1;

  string path_to_here(prefix);
  path_to_here.append(dir);
  
  if (x1 > 0) {
    TravelTo(x1, y1, x1-1, y1, path_to_here, v, m);
  }
  if (x1 < n-1) {
    TravelTo(x1, y1, x1+1, y1, path_to_here, v, m);
  }
  if (y1 > 0) {
    TravelTo(x1, y1, x1, y1-1, path_to_here, v, m);
  }
  if (y1 < n-1) {
    TravelTo(x1, y1, x1, y1+1, path_to_here, v, m);
  }

  // Unmark the fact that we've visited through here, otherwise
  // backtracking won't work and we will only explore one path
  v[x1][y1] = 0;
}

int main()
{
  MazeT m = {
    { 1, 0, 0, 0 },
    { 1, 1, 0, 0 },
    { 1, 1, 0, 0 },
    { 0, 1, 1, 1 }
  };

  FindPaths(m);

  return 0;
}

