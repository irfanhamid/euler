#include <iostream>
#include "tree.hpp"

using namespace std;

typedef euler::TreeNode_T<int> Tree_T;

// Helper functions to dump out the traversals
void Inorder(Tree_T* root, int* outputBuffer, int& cursor)
{
  if (!root)
    return;

  Inorder(root->left, outputBuffer, cursor);
  outputBuffer[cursor++] = root->data;
  Inorder(root->right, outputBuffer, cursor);
}

void Preorder(Tree_T* root, int* outputBuffer, int& cursor)
{
  if (!root)
    return;

  outputBuffer[cursor++] = root->data;
  Preorder(root->left, outputBuffer, cursor);
  Preorder(root->right, outputBuffer, cursor);
}

int Search(int* v, int s, int e, int k)
{
  int i;
  for (i = s; i <= e && v[i] != k; ++i);
  return i;
}

int preorderStart = 0;

Tree_T* Reconstruct(int* inorder, int inorderStart, int inorderEnd, int* preorder)
{
  Tree_T* root = new Tree_T(preorder[preorderStart++]);
  if (inorderStart == inorderEnd)
    return root;

  // Find the root in the inorder traversal
  int r = Search(inorder, inorderStart, inorderEnd, root->data);

  // If root is at left edge of inorder traversal, then no left subtree
  if (r == inorderStart)
    root->left = NULL;
  else
    root->left = Reconstruct(inorder, inorderStart, r - 1, preorder);

  // If root is at right edge of inorder traversal, then no right subtree
  if (r == inorderEnd)
    root->right = NULL;
  else
    root->right = Reconstruct(inorder, r + 1, inorderEnd, preorder);

  return root;
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

  int inorder[8];
  int preorder[8];

  int cursor = 0;
  Inorder(&root, inorder, cursor);
  cursor = 0;
  Preorder(&root, preorder, cursor);

  for (int i = 0; i < 8; ++i)
    cout << inorder[i] << "\t";
  cout << endl;

  for (int i = 0; i < 8; ++i)
    cout << preorder[i] << "\t";
  cout << endl;

  Tree_T* reconstructed = Reconstruct(inorder, 0, 7, preorder);

  cursor = 0;
  Inorder(reconstructed, inorder, cursor);
  cursor = 0;
  Preorder(reconstructed, preorder, cursor);

  cout << "Reconstructed version of the tree:" << endl;
  for (int i = 0; i < 8; ++i)
    cout << inorder[i] << "\t";
  cout << endl;

  for (int i = 0; i < 8; ++i)
    cout << preorder[i] << "\t";
  cout << endl;

  return 0;
}
