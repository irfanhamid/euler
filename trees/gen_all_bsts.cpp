#include <iostream>
#include <vector>
#include <queue>
#include "../../shared/tree.hpp"

using namespace std;
using namespace euler;

typedef TreeNode_T<int> TreeNode;
typedef queue<TreeNode*> TreeNodes;

vector<TreeNode*> empty_forest;

vector<TreeNode*> gen_bsts(vector<int>& seq)
{
    vector<TreeNode*> forest;
    if (!seq.size())
        return empty_forest;
    else if (seq.size() == 1) {
        forest.push_back(new TreeNode(seq[0]));
        return forest;
    } else {
        for (int idx_root = 0; idx_root < seq.size(); ++idx_root) {
            vector<int> smaller;
            vector<int> not_smaller;
            for (int idx = 0; idx < seq.size(); ++idx) {
                if (idx == idx_root)
                    continue;
                
                if (seq[idx] < seq[idx_root])
                    smaller.push_back(seq[idx]);
                else
                    not_smaller.push_back(seq[idx]);
            }
                
            vector<TreeNode*> smaller_forest = gen_bsts(smaller);
            vector<TreeNode*> not_smaller_forest = gen_bsts(not_smaller);
            for (TreeNode* t0 : smaller_forest) {
                for (TreeNode* t1 : not_smaller_forest) {
                    TreeNode* me = new TreeNode(seq[idx_root]);
                    me->left = t0;
                    me->right = t1;
                    forest.push_back(me);
                }
            }
        }
    }

    return forest;
}

void print_bst(TreeNode* r)
{
    TreeNodes nodes;
    nodes.push(r);
    nodes.push(nullptr);
    while (!nodes.empty()) {
        TreeNode* ptr = nodes.front();
        nodes.pop();
        if (ptr) {
            cout << ptr->data << "\t";
            if (ptr->left) {
                cout << "l>" << ptr->left->data << "\t";
                nodes.push(ptr->left);
            }
            if (ptr->right) {
                cout << "r>" << ptr->right->data << "\t";
                nodes.push(ptr->right);
            }
        } else {
            cout << endl;
            if (!nodes.empty())
                nodes.push(nullptr);
        }
    }
}

int main()
{
    empty_forest.push_back(nullptr);
    vector<int> s = {0, 1, 2};
    vector<TreeNode*> f = gen_bsts(s);
    for (TreeNode* r : f) {
        print_bst(r);
        cout << "\n\n------------\n\n";
    }
    return 0;
}