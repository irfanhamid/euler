#include <iostream>
#include "list.hpp"

using namespace std;
using namespace euler;

typedef LinkNode_T<int> Link_T;

bool IsCycle(const Link_T* head)
{
  if ( !head )
    return false;

  const Link_T* slow = head;
  const Link_T* fast = head;
  while ( slow && fast )
  {
    slow = slow->next;
    fast = fast->next;

    if ( fast )
      fast = fast->next;

    if ( slow == fast )
      return slow != NULL;
  }

  return false;
}

int main()
{
  Link_T h0, h1, h2, h3;
  h0.next = NULL;
  cout << IsCycle(&h0) << endl;

  h0.next = &h1, h1.next = &h2, h2.next = &h3, h3.next = NULL;
  cout << IsCycle(&h0) << endl;

  h3.next = &h2;
  cout << IsCycle(&h0) << endl;

  return 0;
}
