/**
 * Given an array of integers, find the longest non-decreasing subsequence within it
 * A[i_0] .. A[i_k] where each i_j < i_j+1 and A[i_j] <= A[i_j+1]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest_nondecreasing_subseq(int* seq, int n, int* subseq)
{
  int* longest = (int*) malloc(sizeof(int) * n);
  int* path = (int*) malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    longest[i] = 1;
    path[i] = -1;
  }

  for (int i = 1; i < n; ++i) {
    int curr = seq[i];
    for (int j = i - 1; j >= 0; --j) {
      if (seq[j] == seq[i]) {
        longest[i] = 1 + longest[j];
        path[i] = j;
        continue;
      }
      
      if (seq[j] < seq[i] && longest[j] > (longest[i] - 1)) {
        longest[i] = 1 + longest[j];
        path[i] = j;
      }
    }
  }

  int max_path = 0;
  int max_path_term_idx;
  for (int i = 0; i < n; ++i) {
    if (longest[i] > max_path) {
      max_path = longest[i];
      max_path_term_idx = i;
    }
  }

  int curr = max_path_term_idx;
  int i = 0;
  while (curr != -1) {
    subseq[i++] = curr;
    curr = path[curr];
  }

  free(path);
  free(longest);
  return max_path;
}

int main()
{
  int seq[] = {1, 0, 4, 1, 2, 5, 3, 7, 1, 2};
  int subseq[10];
  int longest = longest_nondecreasing_subseq(seq, 10, subseq);
  for (int i = 0; i < longest; ++i) {
    printf("%d ", subseq[i]);
  }
  printf("\n");
  return 0;
}

