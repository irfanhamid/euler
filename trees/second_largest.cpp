#include <iostream>
#include "../shared/tree.hpp"

using namespace std;

typedef euler::TreeNode_T<int> Tree;

int SecondLargest(const Tree* root)
{
    if (!root || !(root->left || root->right))
        return -1;

    int pred;
    const Tree* curr;
    if (root->left) {
        pred = euler::TreeMax(root->left)->data;
        curr = root;
    } else {
        pred = root->data;
        curr = root->right;
    }

    while (curr->right) {
        if (curr->right->left)
            pred = euler::TreeMax(curr->right->left)->data;
        else
            pred = curr->data;
        curr = curr->right;
    }
    
    return pred;
}

int main()
{
    Tree h(5);
    cout << SecondLargest(&h) << endl;

    Tree l(3);
    h.left = &l;
    cout << SecondLargest(&h) << endl;

    Tree lr(4);
    l.right = &lr;
    cout << SecondLargest(&h) << endl;

    Tree r(7);
    h.right = &r;
    cout << SecondLargest(&h) << endl;
    
    return 0;
}
