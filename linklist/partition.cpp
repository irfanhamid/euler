#include <iostream>
#include "../../shared/list.hpp"

using namespace std;
using namespace euler;

typedef LinkNode_T<int> IntNode;

IntNode* partition_stable(IntNode* head, int pivot)
{
    IntNode* prefix_head = nullptr;
    IntNode* prefix_tail = nullptr;
    IntNode* suffix_head = nullptr;
    IntNode* suffix_tail = nullptr;

    IntNode* curr_next = nullptr;
    IntNode* curr = head;
    while (curr) {
        curr_next = curr->next;
        if (curr->data < pivot) {
            if (!prefix_head)
                prefix_head = prefix_tail = curr;
            else {
                prefix_tail->next = curr;
                prefix_tail = curr;
            }
        } else {
            if (!suffix_head)
                suffix_head = suffix_tail = curr;
            else {
                suffix_tail->next = curr;
                suffix_tail = curr;
            }
        }
        curr = curr_next;
    }

    if (prefix_tail) {
        prefix_tail->next = suffix_head;
        return prefix_head;
    }

    return suffix_head;
}

IntNode* partition(IntNode* head, int pivot)
{
    IntNode* prefix = nullptr;
    IntNode* prefix_last = nullptr;
    IntNode* suffix = nullptr;
    IntNode* curr_next = nullptr;

    IntNode* curr = head;
    while (curr) {
        curr_next = curr->next;
        if (curr->data < pivot) {
            curr->next = prefix;
            prefix = curr;
            if (!prefix_last)
                prefix_last = curr;
        } else {
            curr->next = suffix;
            suffix = curr;
        }
        curr = curr_next;
    }

    if (prefix_last) {
        prefix_last->next = suffix;
        return prefix;
    }
    return suffix;
}

int main()
{
    IntNode head(10);
    IntNode* curr = &head;
    srand(time(nullptr));

    cout << curr->data << endl;
    for (int i = 0; i < 15; ++i) {
        curr->next = new IntNode(rand() % 64);
        curr = curr->next;
        cout << curr->data << endl;
    }
    cout << "--------\n";

    curr = partition_stable(&head, 32);

    for (; curr; curr = curr->next)
        cout << curr->data << endl;
    return 0;
}