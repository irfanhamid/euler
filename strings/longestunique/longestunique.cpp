/*
  Find the longest substring with unique characters in a string. Assume only ASCII text.
*/
#include <iostream>
#include <string.h>

using namespace std;

char* LongestUnique(char* str)
{
  int histogram[52];
  memset(histogram, 0, sizeof(int) * 52);

  int maxLeft = 0;
  int maxRight = 0;
  int left = 0;
  int right = 0;
  
  while (str[right])
  {
    if (histogram[str[right] - 'a'])
    {
      if ((right - left) > (maxRight - maxLeft))
      {
        maxLeft = left;
        maxRight = right;
      }
      left = right;
      memset(histogram, 0, sizeof(int) * 52);
    }
    else
    {
      ++histogram[str[right] - 'a'];
    }
    ++right;
  }
  if ((right - left) > (maxRight - maxLeft))
  {
    maxLeft = left;
    maxRight = right;
  }
  str[maxRight] = '\0';

  return &str[maxLeft];
}

int main()
{
  char buffer[1024];
  while (true)
  {
    cin.getline(buffer, 1024);
    if (!strcmp(buffer, "exit"))
      break;

    cout << LongestUnique(buffer) << endl;
  }

  return 0;  
}
