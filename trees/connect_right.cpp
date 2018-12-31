#include <iostream>
#include <queue>
#include "../shared/tree.hpp"

using namespace std;

struct Tree_T {
    int data;
    Tree_T* left;
    Tree_T* right;
    Tree_T* sibling;

    Tree_T(int d) : data(d)
                  , left(nullptr)
                  , right(nullptr)
                  , sibling(nullptr)
    {}

    void SetLeftChild(Tree_T* c) { left = c; }
    void SetRightChild(Tree_T* c) { right = c; }
};

void ConnectRight(Tree_T* root)
{
    if (!root)
        return;

    queue<Tree_T*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Tree_T* p = q.front();
        q.pop();
        if (!p) {
            if (q.size() && q.front())
                q.push(nullptr);

            continue;
        }
        p->sibling = q.front();

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
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

    ConnectRight(&root);

    return 0;
}