#ifndef Graph_H
#define Graph_H
#include<list>
#include "GraphNode.h"
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
     void addAwn(T valueA, T valueB);
     void deleteAwn(T valueA, T valueB);
     void addAwnAux(GraphNode<T>* nodeA, GraphNode<T>* nodeB);
     void deleteAwnAux(GraphNode<T>* nodeA, T awnValue);
     std::list<GraphNode<T>*> depthFirst();
     void depthFirstAux(GraphNode<T>* currentNode,std::list<GraphNode<T>*>* nodeList);
     bool findAwn(T valueA, T valueB);
};
#include "Graph.hxx"
#endif //Graph_h