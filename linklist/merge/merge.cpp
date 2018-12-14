#include <iostream>

#include "../../shared/list.hpp"

using namespace std;
using namespace euler;

typedef LinkNode_T<int> IntNode;

IntNode* merge(IntNode* l0, IntNode* l1)
{
    IntNode* e0 = l0;
    IntNode* e1 = l1;
    
    IntNode* h = nullptr;
    if (e0 && !e1) {
        h = e0;
        e0 = e0->next;
    } else if (!e0 && e1) {
        h = e1;
        e1 = e1->next;
    } else if (e0->data < e1->data) {
        h = e0;
        e0 = e0->next;
    } else {
        h = e1;
        e1 = e1->next;
    }

    IntNode* curr = h;
    while (e0 || e1) {
        if (e0 && !e1) {
            curr->next = e0;
            e0 = e0->next;
        } else if (!e0 && e1) {
            curr->next = e1;
            e1 = e1->next;
        } else if (e0->data < e1->data) {
            curr->next = e0;
            e0 = e0->next;
        } else {
            curr->next = e1;
            e1 = e1->next;
        }
        curr = curr->next;
    }

    return h;
}

int main()
{
    IntNode h0(0);
    IntNode h1(1);
    
    IntNode* c0 = &h0;
    IntNode* c1 = &h1;
    for (int i = 0; i < 17; i += 2) {
        c0->next = new IntNode(i + 2);
        c0 = c0->next;
        c1->next = new IntNode(i + 1);
        c1 = c1->next;
    }

    c0 = merge(&h0, &h1);
    while (c0) {
        cout << c0->data << endl;
        c0 = c0->next;
    }

    cout << "-------\n";
    h0.next = nullptr;
    c0 = merge(&h0, nullptr);
    while (c0) {
        cout << c0->data << endl;
        c0 = c0->next;
    }

    return 0;
}