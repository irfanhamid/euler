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

    LinkNode_T() : next(NULL),
                   prev(NULL)
    {
    }
  };
}

#endif
