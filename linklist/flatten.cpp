#include <iostream>

using namespace std;

template<typename U>
struct Node_T {
  U data;
  Node_T<U>* next;
  Node_T<U>* child;

  Node_T<U>(U d, Node_T<U>* n = nullptr, Node_T<U>* c = nullptr) :
    data(d),
    next(n),
    child(c)
  {}
};

template<typename U>
void Flatten(Node_T<U>* head, Node_T<U>** tail)
{
  if (!head)
    return;

  Node_T<U>* curr = head;
  while (curr) {
    if (curr->child) {
      Node_T<U>* next = curr->next;
      Node_T<U>* tail2;
      Flatten(curr->child, &tail2);
      curr->next = curr->child;
      curr->child = nullptr;
      //while (curr->next)
      //  curr = curr->next;
      curr = tail2;
      curr->next = next;
    }
    if (!curr->next)
      *tail = curr;
    curr = curr->next;
  }
}

template<typename U>
void PrintList(Node_T<U>* head)
{
  Node_T<U>* curr = head;
  while (curr) {
    if (curr->child)
      cout << curr->data << " has a child!" << endl;
    cout << curr->data << "\t";
    curr = curr->next;
  }
  cout << endl;
}

typedef Node_T<char> Node;

int main()
{
  Node A('A'), B('B'), C('C'), D('D'), E('E'), F('F'), G('G'), H('H'), I('I'), J('J');
  Node *T;
  A.child = &B, A.next = &E, E.next = &F, F.next = &G;
  B.next = &C, C.next = &D;
  G.child = &H, H.next = &I;
  I.next = &J;
  
  Flatten(&A, &T);

  PrintList(&A);

  return 0;
}
