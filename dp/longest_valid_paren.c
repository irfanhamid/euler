/**
 * Given a string made up of only parentheses, find the longest substring
 * that is a valid parenthetization.
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int longest_paren(char* v, char** start)
{
  int longest[1024];
  memset(longest, 0, sizeof(int)*1024);

  for (int i = 1; v[i]; ++i) {
    if (v[i] == '(') {
      longest[i] = 0;
      continue;
    }
    
    // v[i] == ')'
    if (v[i - 1] == '(') {
      longest[i] = i >= 2 ? longest[i - 2] + 2 : 2;
      continue;
    } else {
      // v[i-1] == ')'
      if ((i - 1 - longest[i - 1]) >= 0 && v[i - 1 - longest[i - 1]] == '(') {
        longest[i] = longest[i - 1] + 2;
        longest[i] += (i - 2 - longest[i - 1]) >= 0 ? longest[i - 2 - longest[i - 1]] : 0;
        continue;
      }
    }
    longest[i] = 0;
  }

  int max = 0;
  *start = NULL;
  for (int i = 0; v[i]; ++i) {
    if (longest[i] > max) {
      max = longest[i];
      *start = v + i - max + 1;
    }
  }
  return max;
}

int main(int argc, const char** argv)
{
  char input[1024];
  while (1) {
    scanf("%s", input);

    for (int i = 0; input[i]; ++i) {
      if (!(input[i] == '(' || input[i] == ')')) {
        printf("Invalid input, must contain only ( or )\n");
        return 1;
      }
    }

    char *start;
    int len = longest_paren(input, &start);
    if (len) {
      for (int i = 0; i < len; ++i) {
        printf("%c", start[i]);
      }
      printf("\n");
    }
  }

  return 0;
}
