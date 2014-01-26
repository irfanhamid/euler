#ifndef __TREE_HPP__
#define __TREE_HPP__

namespace euler
{
  template<class T>
  struct TreeNode
  {
    TreeNode<T>* left;
    TreeNode<T>* right;
    T data;

    TreeNode(const T& d) : data(d),
			   left(NULL),
			   right(NULL)
    {
    }
  };
}

#endif
