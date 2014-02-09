/*
  Remove selected character from a string, in-place.
*/

#include <iostream>
#include <string.h>

using namespace std;

// Remove all occurrences of 'r' from str
// A more general form which takes a vector of chars to remove is easy, just change condition
// if (str[curr] == r) to check for each of said characters
void RemoveChars(char* str, char r)
{
  int skip = 0;
  int curr = 0;
  while (str[curr])
  {
    if (str[curr] == r)
    {
      ++skip;
    }
    else if (skip)
    {
        str[curr - skip] = str[curr];
    }
    ++curr;
  }
  str[curr - skip] = '\0';
}

int main(int argc, char** argv)
{
  if (argc != 2)
    return -1;

  char buffer[1024];
  char r = argv[1][0];
  while (true)
  {
    cin.getline(buffer, 1024);
    if (!strcmp(buffer, "exit"))
      break;
    RemoveChars(buffer, r);
    cout << buffer << endl;
  }

  return 0;
}
