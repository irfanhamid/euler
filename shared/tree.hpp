#ifndef __TREE_HPP__
#define __TREE_HPP__

namespace euler
{
  template<class Payload_T>
  struct TreeNode_T
  {
    typedef TreeNode_T<Payload_T> Self_T;

    Payload_T data;
    Self_T* left;
    Self_T* right;
    Self_T* parent;

    TreeNode_T(const Payload_T& d) : data(d),
                                     left(nullptr),
                                     right(nullptr),
                                     parent(nullptr)
    {
    }

    TreeNode_T(const Payload_T& d,
               TreeNode_T* l,
               TreeNode_T* r) : data(d),
                                left(l),
                                right(r),
                                parent(nullptr)
    {
    } 
    
    void SetLeftChild(Self_T* l)
    {
      left = l;
      left->parent = this;
    }

    void SetRightChild(Self_T* r)
    {
      right = r;
      right->parent = this;
    }
  };

  template<class Payload_T>
  TreeNode_T<Payload_T>* TreeMin(TreeNode_T<Payload_T>* tree)
  {
    if (!tree)
      return nullptr;

    TreeNode_T<Payload_T>* current = tree;
    while (current->left)
      current = current->left;

    return current;
  }

  template<class Payload_T>
  TreeNode_T<Payload_T>* TreeMax(TreeNode_T<Payload_T>* tree)
  {
    if (!tree)
      return nullptr;

    TreeNode_T<Payload_T>* current = tree;
    while (current->right)
      current = current->right;

    return current;
  }
}

#endif
