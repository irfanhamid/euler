/*
  Given a string, find the longest palindrome in it.
*/

#include <iostream>
#include <string.h>

using namespace std;

int PalindromeLength(const char* str, int strLen, int i)
{
  int j = 1;
  for (j = 1; i+j < strLen && i-j >= 0; ++j) {
    if (str[i + j] != str[i - j]) {
      return j;
    }
  }
  return j-1;
}

int* Palindromes(const char* str)
{
  int strLen = strlen(str);
  if (!(str && strLen)) {
    return NULL;
  }
  int *ret = new int[strLen];
  for (int i = 0; i < strLen; ++i) {
    ret[i] = 0;
  }

  for (int i = 1; i < strLen - 1; ++i) {
    ret[i] = PalindromeLength(str,strLen,  i);
  }

  return ret;
}

int main()
{
  char buffer[1024];
  while (true)
  {
    cin.getline(buffer, 1024);
    if (!strcmp(buffer, "exit"))
      break;
    int *pals = Palindromes(buffer);
    int longest = 0;
    int ctr = 0;
    for (int i = 0; i < strlen(buffer); ++i) {
      if (pals[i] > longest) {
        longest = pals[i];
        ctr = i;
      }
    }
    if (longest > 1) {
      for (int i = ctr-longest; i <= ctr+longest; ++i) {
        cout << buffer[i];
      }
      cout << endl;
    }
  }

  return 0;
}
