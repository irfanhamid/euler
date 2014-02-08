#include <iostream>
#include <string.h>

using namespace std;

bool IsChar(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void ReverseWords(char* buffer)
{
  int left = 0;
  int right;
  char tmp;

  // Handle case of the string starting with whitespace
  while (!IsChar(buffer[left]))
    ++left;
  right = left;

  while (buffer[left])
  {
    while (IsChar(buffer[right]))
      ++right;
    
    // Reverse the word, sits in buffer[left : right - 1]
    int wordLeft = left;
    int wordRight = right - 1;
    while (wordLeft < wordRight)
    {
      tmp = buffer[wordLeft];
      buffer[wordLeft++] = buffer[wordRight];
      buffer[wordRight--] = tmp;
    }
    
    // Find next word's left boundary
    while (!IsChar(buffer[right]) && buffer[right])
      ++right;

    left = right;
  }

  // Reverse the string
  left = 0;
  right = strlen(buffer) - 1;
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

    ReverseWords(buffer);
    cout << buffer << endl;
  }

  return 0;
}
