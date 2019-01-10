#include <iostream>
#include "list.hpp"

using namespace std;
using namespace euler;
typedef LinkNode_T<int> Link_T;

Link_T* Reverse(Link_T* head)
{
  if ( !head )
    return NULL;

  Link_T* p = NULL;
  Link_T* c = head;
  Link_T* n;
  while ( c )
  {
    n = c->next;
    c->next = p;
    p = c;
    c = n;
  }

  return p;
}

int main()
{
  Link_T h0;
  h0.data = 0;
  h0.next = NULL;
  
  Link_T* n = Reverse(&h0);
  cout << n->data << endl;

  Link_T h1, h2, h3;
  h0.next = &h1, h1.next = &h2, h2.next = &h3, h3.next = NULL;
  h1.data = 1, h2.data = 2, h3.data = 3;
  n = Reverse(&h0);
  while (n)
  {
    cout << n->data << "\t";
    n = n->next;
  }
  cout << endl;

  return 0;
}
