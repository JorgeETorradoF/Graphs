#ifndef Graph_H
#define Graph_H
#include<list>
#include<queue>
#include<vector>
#include<limits>
#include <algorithm>
#include "GraphNode.h"
template<class T>
struct dijkstraNode
{
  T nodeValue;
  T predecessor;
  int cost = std::numeric_limits<int>::max();
  bool operator == (const dijkstraNode<T>& other) const {
    return nodeValue == other.nodeValue;
}
  bool operator == (const T& other) const {
    return nodeValue == other;
}
  bool operator<(const dijkstraNode<T>& other) const {
    return cost < other.cost;
}
};
template<class T>
class Graph
{
   protected:
     std::list<GraphNode<T>*> nodes;
   public:
     Graph();
     Graph(T value);
     std::list<GraphNode<T>*> getGraph();
     void deleteNode(T value);
     void addNode(T value);
     bool findNode(T value);
     GraphNode<T>* getNode(T value);
     void addAwn(T valueA, T valueB, int cost);
     void deleteAwn(T valueA, T valueB);
     void addAwnAux(GraphNode<T>* nodeA, GraphNode<T>* nodeB, int cost);
     void deleteAwnAux(GraphNode<T>* nodeA, T awnValue);
     std::list<GraphNode<T>*> depthFirst();
     void depthFirstAux(GraphNode<T>* currentNode,std::list<GraphNode<T>*>* nodeList);
     std::list<GraphNode<T>*> breadthFirst();
     bool findAwn(T valueA, T valueB);
     int findNodeIndex(T value);
     std::vector<dijkstraNode<T>> dijkstra(T sourceValue);

};
#include "Graph.hxx"
#endif //Graph_h