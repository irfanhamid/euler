/*
  "Flatten" a BST into a doubly linked list such that walking the list gives an in-order traversal.
*/

#include <iostream>
#include "tree.hpp"

using namespace std;

typedef euler::TreeNode_T<int> Tree_T;

Tree_T* Flatten(Tree_T* root)
{
  if (!root)
    return NULL;

  // left is prev pointer, right is next pointer
  Tree_T* head = NULL;
  Tree_T* tail = NULL;
  head = Flatten(root->left);
  if (head)
  {
    root->left = head->left;
    root->left->right = root;
  }
  else
  {
    head = root;
  }

  root->right = Flatten(root->right);
  if (root->right)
  {
    tail = root->right->left;
    root->right->left = root;    
  }
  else
  {
    tail = root;
  }
  tail->right = head;
  head->left = tail;

  return head;
}

int main()
{
  Tree_T root(10);
  Tree_T rootr(11);
  Tree_T rootrr(12);
  Tree_T rootl(2);
  Tree_T rootll(1);
  Tree_T rootlr(7);
  Tree_T rootlrl(5);
  Tree_T rootlrr(8);

  root.SetLeftChild(&rootl);
  root.SetRightChild(&rootr);
  rootl.SetLeftChild(&rootll);
  rootl.SetRightChild(&rootlr);
  rootr.SetRightChild(&rootrr);
  rootlr.SetLeftChild(&rootlrl);
  rootlr.SetRightChild(&rootlrr);

  Tree_T* newRoot = Flatten(&root);
  Tree_T* curr = newRoot;
  cout << curr->data << endl;
  curr = curr->right;
  while (curr != newRoot)
  {
    cout << curr->data << endl;
    curr = curr->right;
  }

  return 0;
}
