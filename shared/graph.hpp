#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <map>
#include <vector>

namespace euler
{
  template<
    class Payload_T,
    class Linkload_T
  >
  struct GraphNode_T
  {
    typedef GraphNode_T<Payload_T, Linkload_T> Self_T;
    typedef std::pair<GraphNode_T*, Linkload_T> Link_T;

    Payload_T data;
    std::vector<Link_T> links;
  };
}

#endif
