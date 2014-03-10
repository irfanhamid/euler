/*
  Calculating nth order statistic for a set of integers. 
  The nth order statistic of a set of numbers is the nth
  number when they are arranged in increasing order.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

// v: vector of integers
// k: the order of the statistic we want
int OrderStatistic(int* v, int left, int right, int k, bool& bFound)
{
  if (left + k > right)
  {
    bFound = false;
    return -1;
  }

  bFound = true;
  if (left == right)
    return v[k];

  int part = left + (rand() % (right - left + 1));
  int partVal = v[part];
  int l = left;
  int r = right - 1;
  v[part] = v[r];
  v[r] = partVal;
  while (l < r)
  {
    if (v[l] > partVal)
    {
      while (v[r] >= partVal && l < r)
        --r;

      if (v[r] < partVal && l < r)
      {
        int tmp = v[l];
        v[l] = v[r];
        v[r] = tmp;
      }
    }
    ++l;
  }
  v[r] = partVal;

  if (part > k)
    return OrderStatistic(v, part + 1, right, k - part, bFound);
  else if (part < k)
    return OrderStatistic(v, left, part - 1, k, bFound);
  return partVal;
}

int main()
{
  //int buffer[] = {5, 4, 3, 7, 8, 10, 1, 15};
  int buffer[] = {5, 4};
  bool bFound = false;
  cout << OrderStatistic(buffer, 0, 1, 0, bFound) << endl;
  return 0;
}
