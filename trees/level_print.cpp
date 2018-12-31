/**
 * Print a binary tree in level order.
 */

#include <cstdint>
#include <iostream>
#include <queue>
#include "tree.hpp"

using namespace std;

typedef euler::TreeNode_T<std::uint32_t> Tree;
typedef queue<const Tree*> NodeQueue;

void LevelPrint(const Tree& root)
{
  NodeQueue q0, q1;
  NodeQueue *front, *back;
  front = &q0;
  back = &q1;

  front->push(&root);

  // Keep going until both queues are empty
  while (!(front->empty() && back->empty())) {
    // When the front queue is empty, flip the two queues
    // This is semantically equivalent to a level being finished 
    if (front->empty()) {
      cout << endl;
      NodeQueue* tmp = front;
      front = back;
      back = tmp;
      continue;
    }
    
    const Tree* t = front->front();
    front->pop();
    cout << t->data << "\t";
    
    // Add this node's children, if they exist, to the back queue,
    // which is the staging area for the next level down 
    if (t->left)
      back->push(t->left);
    if (t->right)
      back->push(t->right);
  }    
}

int main(int argc, const char** argv)
{
  Tree root(0);
  Tree l(1);
  Tree r(2);
  Tree ll(3);
  Tree lr(4);
  Tree rl(5);
  Tree rr(6);
  Tree rrl(7);
  root.SetLeftChild(&l);
  root.SetRightChild(&r);
  l.SetLeftChild(&ll);
  l.SetRightChild(&lr);
  r.SetLeftChild(&rl);
  r.SetRightChild(&rr);
  rr.SetLeftChild(&rrl);

  LevelPrint(root);
  return 0;
}
