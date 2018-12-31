#include <iostream>
#include <stack>
#include <deque>
#include "tree.hpp"

using namespace std;

typedef euler::TreeNode_T<int> Tree_T;

void Inorder(const Tree_T* tree)
{
  /* 
     Recursively defined as:

     Inorder(tree->left);
     visit(tree);
     Inorder(tree->right);
  */

  const Tree_T* current = tree;
  stack<const Tree_T*> frame;

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

void Postorder(const Tree_T* tree)
{
  /*
    Recursively defined as:
    
    Postorder(tree->left);
    Postorder(tree->right);
    visit(tree);
  */

  const Tree_T* prev = NULL;
  const Tree_T* current = tree;
  stack<const Tree_T*> frame;

  while (current)
  {
    if (current) {
      if ((!current->right && !current->left) || prev == current->left || prev == current->right) {

	// <visit>
	cout << current->data << "\t";
	// </visit>

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

void Preorder(const Tree_T* tree)
{
  /*
    Recursively defined as:

    visit(tree);
    Preorder(tree->left);
    Preorder(tree->right);
  */

  const Tree_T* current = tree;
  stack<const Tree_T*> frame;
  
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

// We'll print out one line per level
void BreadthFirst(const Tree_T* tree)
{
  deque<const Tree_T*> store;
  store.push_back(tree);

  while (!store.empty())
  {
    const Tree_T* curr = store.front();
    store.pop_front();
    cout << curr->data << "\t";
    if (curr->left)
      store.push_back(curr->left);
    if (curr->right)
      store.push_back(curr->right);
  }

  cout << endl;
}

int main()
{
  Tree_T root(8);
  Tree_T rootl(5);
  Tree_T rootr(10);
  root.left = &rootl;
  root.right = &rootr;
  
  Tree_T rootll(2);
  Tree_T rootlr(7);
  rootl.left = &rootll;
  rootl.right = &rootlr;
  
  Inorder(&root);
  cout << endl;
  Preorder(&root);
  cout << endl;
  Postorder(&root);
  cout << endl;
  BreadthFirst(&root);
  return 0;
}
