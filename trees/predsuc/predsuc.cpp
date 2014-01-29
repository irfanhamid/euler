/*
  Logically, in a BST, the successsor of a node is the node immediately after it in an inorder traversal.
  If the node has a left child, then successor is the TreeMin(leftchild).
  Otherwise, keep going up the tree until you climb up a left link and then the parent is the successor.
  Symmetric reasoning to arrive at the algorithm for predecessor.
 */

#include <iostream>
#include "tree.hpp"

using namespace std;

typedef euler::TreeNode_T<int> Tree_T;

// Assume that the successor of a node where it is the only node of a tree is not defined
const Tree_T* Successor(const Tree_T* tree)
{
  if (!tree || (!tree->left && !tree->right && !tree->parent))
    return NULL;

  if (tree->right)
    return euler::TreeMin<int>(tree->right);

  const Tree_T* current = tree;
  while (current)
  {
    if (current->parent->left == current)
      return current->parent;

    current = current->parent;
  }

  return current;
}

// Assume that the predecessor of a node where it is the only node of a tree is not defined
const Tree_T* Predecessor(const Tree_T* tree)
{
  if (!tree || (!tree->left && !tree->right && !tree->parent))
    return NULL;

  if (tree->left)
    return euler::TreeMax<int>(tree->left);

  const Tree_T* current = tree;
  while (current)
  {
    if (current->parent->right == current)
      return current;

    current = current->parent;    
  }

  return current;
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

  cout << Successor(&rootll)->data << endl;
  cout << Successor(&rootl)->data << endl;
  cout << Successor(&rootlr)->data << endl;
  cout << Successor(&rootlrl)->data << endl;
  cout << Successor(&rootlrr)->data << endl;

  return 0;
}
