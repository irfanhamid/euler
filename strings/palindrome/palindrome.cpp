/*
  Check to see if a string is a palindrome or not.
*/

#include <iostream>
#include <string.h>

using namespace std;

bool IsPalindrome(const char* str)
{
  int left = 0;
  int right = strlen(str) - 1;

  while (left < right)
  {
    if (str[left++] != str[right--])
      return false;
  }

  return true;
}

int main()
{
  char buffer[1024];
  while (true)
  {
    cin.getline(buffer, 1024);
    if (!strcmp(buffer, "exit"))
      break;

    cout << IsPalindrome(buffer) << endl;
  }

  return 0;
}
