#include <iostream>
#include <stack>
#include "tree.hpp"

using namespace std;

typedef euler::TreeNode<int> TNode;

void Inorder(const TNode* tree)
{
  /* 
     Recursively defined as:

     Inorder(tree->left);
     visit(tree);
     Inorder(tree->right);
  */

  const TNode* current = tree;
  stack<const TNode*> frame;

  while (true)
  {
    if (!current) {
      if (frame.empty())
	return;

      current = frame.top();
      frame.pop();

      // <visit>
      cout << current->data << "\t";
      // </visit>

      current = current->right;
    } else {
      frame.push(current);
      current = current->left;
    }
  }
}

void Postorder(const TNode* tree)
{
  /*
    Recursively defined as:
    
    Postorder(tree->left);
    Postorder(tree->right);
    visit(tree);
  */

  const TNode* prev = NULL;
  const TNode* current = tree;
  stack<const TNode*> frame;

  while (current)
  {
    if (current) {
      if ((!current->right && !current->left) || prev == current->left || prev == current->right) {
	cout << current->data << "\t";
	prev = current;
	if (frame.empty())
	  return;
	current = frame.top();
	frame.pop();
      } else {
	frame.push(current);
	if (current->right)
	  frame.push(current->right);

	if (current->left) {
	  current = current->left;
	} else if (frame.empty()) {
	  return;
	} else {
	  current = frame.top();
	  frame.pop();
	}
      }
    }
  }
} 

void Preorder(const TNode* tree)
{
  /*
    Recursively defined as:

    visit(tree);
    Preorder(tree->left);
    Preorder(tree->right);
  */

  const TNode* current = tree;
  stack<const TNode*> frame;
  
  while (true)
  {
    if (current) {

      // <visit>
      cout << current->data << "\t";
      // </visit>

      frame.push(current->right);
      current = current->left;
    } else {
      if (frame.empty())
	return;

      current = frame.top();
      frame.pop();
    }
  }
}

int main()
{
  TNode root(8);
  TNode rootl(5);
  TNode rootr(10);
  root.left = &rootl;
  root.right = &rootr;
  
  TNode rootll(2);
  TNode rootlr(7);
  rootl.left = &rootll;
  rootl.right = &rootlr;
  
  Inorder(&root);
  cout << endl;
  Preorder(&root);
  cout << endl;
  Postorder(&root);
  cout << endl;
  return 0;
}
