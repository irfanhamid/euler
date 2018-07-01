/**
 * Given an ordered vector of integers and a given integer k, find the
 * index of least upper bound of k within the vector, or return -1
 */

#include <stdio.h>
#include <stdlib.h>

int least_upper_bound(const int* v, int l, int r, int k)
{
  int m;
  while (1) {
    // If all elements are greater than k, then lub is smallest element
    if (v[l] > k)
      return l;
    // If all elements are less than or equal to k, then no lub exists
    if (v[r] <= k)
      return -1;
    // If sequence is only 1 element, then it has a lub if it is greater than k
    if (l == r)
      return v[l] > k ? l : -1;

    m = (r-l)/2 + l;
    if (v[m] <= k) {
      l = m + 1;
      continue;
    }
    if (v[m] > k) {
      r = m;
      continue;
    }
    l = m;
  }

  return -1;
}

int main(int argc, const char** argv)
{
  if (argc != 2) {
    printf("usage: lub k\n");
    return 1;
  }

  int v[100];
  for (int i = 0; i < 100; ++i)
    v[i] = i+1;
  
  int lub_idx = least_upper_bound(v, 0, 99, atoi(argv[1]));
  if (lub_idx != -1)
    printf("lub: %d\n", v[lub_idx]);
  else
    printf("no lub\n");
  return 0;
}
