/*
  Given a string, find the longest palindrome in it.
*/

#include <iostream>
#include <string.h>

using namespace std;

void LongestPalindromesOfStride(const char* str, int stride, int* memo)
{
  int strLen = strlen(str);
  int left = 0;
  
  if (stride == 1)
  {
    for (int i = 0; i + stride < strLen; ++i)
      if (str[i] == str[i + 1])
        memo[i * strLen + 1] = 1;
  }
  else
  {
    for (int i = 0; i + stride < strLen; i += stride)
    {
      if (str[i] == str[i + stride] && memo[(i + 1) * strLen + i + stride - 1])
        memo[i * strLen + stride] = 1;
    }
  }
}

void LongestPalindrome(const char* str)
{
  int strLen = strlen(str);
  if (!(str && strLen))
    return;

  int* memo = new int[strLen * strLen];
  memset((void*)memo, 0, sizeof(int) * strLen * strLen);
  for (int i = 0; i < strLen; ++i)
    memo[i * strLen + i] = 1;

  for (int i = 1; i < strLen; ++i)
    LongestPalindromesOfStride(str, i, memo);

  int longest = 1;
  int left = 0, right = 0;
  for (int i = 0; i < strLen; ++i)
  {
    for (int j = strLen - 1; j > 0; --j)
    {
      if (memo[i * strLen + j])
      {
        if ((j - i) > longest)
        {
          longest = j - i;
          left = i;
          right = j;
        }
      }
    }
  }

  char palindrome[1024];
  memcpy(palindrome, &str[left], right - left + 1);
  palindrome[right - left + 1] = '\0';
  cout << palindrome << endl;
}

int main()
{
  char buffer[1024];
  while (true)
  {
    cin.getline(buffer, 1024);
    if (!strcmp(buffer, "exit"))
      break;
    LongestPalindrome(buffer);
  }

  return 0;
}
