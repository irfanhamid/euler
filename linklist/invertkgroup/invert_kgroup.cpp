#include <iostream>
#include "../../shared/list.hpp"

using namespace std;
using namespace euler;

typedef LinkNode_T<int> Link;

bool has_atleast(Link* head, int k)
{
  if (!head)
    return false;
  Link* curr = head;
  for (int i = 0; i < k; ++i) {
    curr = curr->next;
    if (!curr)
      return false;
  }
  return true;
}

Link* invert_kgroup(Link* head, int k)
{
  if (k <= 1 || !head || !head->next)
    return head;

  Link* new_head = head;
  Link* blk_prev = nullptr;
  Link* blk_head = nullptr;
  Link* curr = head;
  Link* next = curr->next;
  Link* next_next = next->next;

  while (curr) {
    if (!has_atleast(curr, k))
      break;

    // Grab curr + k nodes and invert them
    blk_head = curr;
    for (int i = 0; i < k - 1; ++i) {
      next_next = next->next;
      next->next = curr;
      curr = next;
      next = next_next;
    }
    if (blk_prev)
      blk_prev->next = curr;
    else
      new_head = next;

    blk_head->next = next;

    curr = next;
    blk_prev = curr;
  }

  return new_head;
}

int main()
{
  Link head((int)0);
  Link* curr = &head;

  for (int i = 0; i < 15; ++i) {
    curr->next = new Link(i+1);
    curr = curr->next;
  }
  curr->next = nullptr;

  curr = invert_kgroup(&head, 3);
  for (; curr; curr = curr->next)
    cout << curr->data << endl;

  return 0;
}
