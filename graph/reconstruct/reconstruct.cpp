/*
  Reconstruct a graph from a given adjacency list.
*/

#include <map>
#include <set>
#include <iostream>
#include "graph.hpp"

using namespace std;
using namespace euler;

typedef GraphNode_T<int, double> GraphNode;
typedef map<const GraphNode*, GraphNode*> Mapping;
typedef set<const GraphNode*> Visited;

void DoReconstructionFromNode(const GraphNode* self, Mapping& mapping, Visited& visited)
{
  if (visited.find(self) != visited.end())
    return;
  visited.insert(self);

  Mapping::iterator mirrorIt = mapping.find(self);
  if (mirrorIt == mapping.end())
    return;

  GraphNode* mirror = mirrorIt->second;

  for (vector<GraphNode::Link_T>::const_iterator it = self->links.begin();
       it != self->links.end();
       ++it)
  {
    GraphNode* newnode = NULL;
    Mapping::iterator mirrorLinkIt = mapping.find(it->first);
    if (mirrorLinkIt == mapping.end())
    {
      newnode = new GraphNode();
      newnode->data = it->first->data;
      mapping.insert(make_pair(it->first, newnode));
    }
    else
    {
      newnode = mirrorLinkIt->second;
    }
    mirror->links.push_back(make_pair(newnode, 0.0D));
    DoReconstructionFromNode(it->first, mapping, visited);
  }
}

GraphNode* Reconstruct(const GraphNode* start)
{
  if (!start)
    return NULL;

  // If the node in the source graph has been seen, then its mirror in the destination graph
  // is stored in this map. The map doesn't own the nodes, only pointers are held.
  Mapping mapping;
  GraphNode* newstart = new GraphNode();
  mapping.insert(make_pair(start, newstart));
  newstart->data = start->data;

  Visited visited;
  DoReconstructionFromNode(start, mapping, visited);

  return newstart;
}

int main()
{
  GraphNode s, one, two, three;
  s.data = 0, one.data = 1, two.data = 2, three.data = 3;
  s.links.push_back(make_pair(&one, 0.0D));
  s.links.push_back(make_pair(&two, 0.0D));
  s.links.push_back(make_pair(&three, 0.0D));
  two.links.push_back(make_pair(&one, 0.0D));

  GraphNode* news = Reconstruct(&s);
  cout << news->data << endl;
  cout << news->links[0].first->data << endl;
  cout << news->links[1].first->data << endl;
  cout << news->links[2].first->data << endl;
  cout << news->links[1].first->links[0].first->data << endl; 

  return 0;
}
