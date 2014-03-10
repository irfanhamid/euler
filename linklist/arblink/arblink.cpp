/*
  Given a link list with one next and one "arbitrary" pointer which can point to any node in the list, give an algorithm to copy the list.
  In this example, I am using the "prev" pointer as the arbitrary. The algorithm runs in linear time and const space by first modifying the
  list in place, then extracting the new list out of the expanded original one, leaving it intact.
*/

#include <iostream>
#include "list.hpp"

using namespace euler;
using namespace std;

typedef LinkNode_T<int> Link_T;

Link_T* CopyLinklist(Link_T* head)
{
  if (!head)
    return NULL;

  // In the first path, expand the link list in place with duplicate elements
  Link_T* curr = head;
  while (curr)
  {
    Link_T* newlink = new Link_T();
    newlink->data = curr->data;
    newlink->next = curr->next;
    curr->next = newlink; 

    curr = newlink->next;
  }

  // In the second pass, link the prev pointer to the arbitrary node as in problem statement
  curr = head;
  Link_T* newhead = head->next;
  while (curr && curr->next)
  {
    if (curr->prev)
    {
      curr->next->prev = curr->prev->next;
    }
    curr = curr->next->next;
  }

  // In the last pass, separate out the link lists
  curr = head;
  while (curr)
  {
    Link_T* interleaved = curr->next;
    curr->next = interleaved->next;
    
    if (interleaved->next)
      interleaved->next = interleaved->next->next;

    curr = curr->next;
  }

  return newhead;
}

void PrintArbList(Link_T* head)
{
  if (!head)
    return;

  Link_T* curr = head;
  while (curr)
  {
    cout << curr->data;
    if (curr->prev)
      cout << "\t" << curr->prev->data;
    cout << endl;

    curr = curr->next;
  }
}

int main()
{
  Link_T one, two, three, four, five;
  one.data = 1, two.data = 2, three.data = 3, four.data = 4, five.data = 5;
  one.next = &two, two.next = &three, three.next = &four, four.next = &five, five.next = NULL;
  one.prev = &two, two.prev = &one, five.prev = &three;

  PrintArbList(&one);
  Link_T* newhead = CopyLinklist(&one);
  PrintArbList(newhead);
  return 0;
}
