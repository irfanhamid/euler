/*
  Reverse a string in-place, i.e., without using any auxiliary storage space.
*/

#include <iostream>
#include <string.h>

using namespace std;

void Reverse(char* buffer)
{
  int left = 0;
  int right = strlen(buffer) - 1;
  char tmp;

  while (left < right)
  {
    tmp = buffer[left];
    buffer[left++] = buffer[right];
    buffer[right--] = tmp;
  }
}

int main()
{
  char buffer[1024];

  while (true)
  {
    cin.getline(buffer, 1024);
    if (!strcmp(buffer, "exit"))
      break;
    Reverse(buffer);
    cout << buffer << endl;
  }

  return 0;
}
