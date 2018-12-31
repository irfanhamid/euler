#ifndef __LIST_H__
#define __LIST_H__

namespace euler
{
  template<class Payload_T>
  struct LinkNode_T
  {
    typedef LinkNode_T<Payload_T> Self_T;

    Payload_T data;
    Self_T* next;
    Self_T* prev;

    LinkNode_T() : next(nullptr),
                   prev(nullptr)
    {
    }

    LinkNode_T(Payload_T d) : data(d),
                              next(nullptr),
                              prev(nullptr)
    {
    }
  };

  template<class Payload_T>
  void insert_after(LinkNode_T<Payload_T>* marker,
                    LinkNode_T<Payload_T>* new_node)
  {
    if (!marker)
      return;

    new_node->next = marker->next;
    new_node->prev = marker->prev;

    if (new_node->prev)
      new_node->prev->next = new_node;
    if (new_node->next)
      new_node->next->prev = new_node;
  }
}

#endif
