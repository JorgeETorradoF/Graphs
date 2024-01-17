#ifndef Graph_HXX
#define Graph_HXX
#include "Graph.h"
template<class T>
Graph<T>::Graph()
{
  
}
template<class T>
Graph<T>::Graph(T value)
{
  GraphNode<T>* newNode = new GraphNode<T>(value);
  (this->nodes).push_back(newNode);
}
template<class T>
std::list<GraphNode<T>*> Graph<T>::getGraph()
{
  return this->nodes;
}
template<class T>
void Graph<T>::deleteNode(T value)
{
   if(findNode(value))
   {
     
     //let's erase the connections the target node has with other nodes
     typename std::list<GraphNode<T>*>::iterator it = (this->nodes).begin();
     typename std::list<GraphNode<T>*>::iterator auxIt;
     for(it; it != (this->nodes).end(); it++)
     {
       deleteAwnAux(*it, value);
       //we store the position of the target node, for erasing it later on
       if((*it)->getValue() == value)
       {
         auxIt = it;
       }
     }
     //now we delete it
     (this->nodes).erase(auxIt);
   }
}
template<class T>
void Graph<T>::addNode(T value)
{
  (this->nodes).push_back(new GraphNode<T>(value));
}
template<class T>
bool Graph<T>::findNode(T value)
{
  typename std::list<GraphNode<T>*>::iterator it = (this->nodes).begin();
  for(it; it != (this->nodes).end(); it++)
  {
     if((*it)->getValue() == value)
     {
        return true; 
     }
  }
  return false;
}
template<class T>
GraphNode<T>* Graph<T>::getNode(T value)
{
  GraphNode<T>* desiredNode;
  typename std::list<GraphNode<T>*>::iterator it = (this->nodes).begin();
  for(it; it != (this->nodes).end(); it++)
  {
     if((*it)->getValue() == value)
     {
        desiredNode = *it;
     }
  }
  return desiredNode;
}
template<class T>
void Graph<T>::addAwn(T valueA, T valueB)
{
  if(findNode(valueA) && findNode(valueB))
  {
    GraphNode<T>* targetNodeA = getNode(valueA);
    GraphNode<T>* targetNodeB = getNode(valueB);
    addAwnAux(targetNodeA, targetNodeB);
  }
}
template<class T>
void Graph<T>::deleteAwn(T valueA, T valueB)
{
  if(findNode(valueA))
  {
    GraphNode<T>* targetNode = getNode(valueA);
    deleteAwnAux(targetNode, valueB);
  }
}
template<class T>
void Graph<T>::addAwnAux(GraphNode<T>* nodeA, GraphNode<T>* nodeB)
{
  nodeA->addAwn(nodeB);
}
template<class T>
void Graph<T>::deleteAwnAux(GraphNode<T>* nodeA, T awnValue)
{
  nodeA->deleteAwn(awnValue);
}
template<class T>
std::list<GraphNode<T>*> Graph<T>::depthFirst() {
    std::list<GraphNode<T>*> nodeList;  // List to store visited nodes
    for (GraphNode<T>* node : nodes) {
        if (!node->isVisited()) {
            depthFirstAux(node, &nodeList);
        }
    }
    // Now that I've visited all nodes, I must reset the visited flag, by "unvisiting" each node
    for (GraphNode<T>* node : nodes) {
        node->unvisitNode();
    }
    return nodeList;
}

template<class T>
void Graph<T>::depthFirstAux(GraphNode<T>* currentNode, std::list<GraphNode<T>*>* nodeList) {
    currentNode->visitNode();
    nodeList->push_back(currentNode);

    std::list<GraphNode<T>*> neighbors = currentNode->getAwns();
    for (GraphNode<T>* neighbor : neighbors) {
        if (!neighbor->isVisited()) {
            depthFirstAux(neighbor, nodeList);
        }
    }
}
template<class T>
bool Graph<T>::findAwn(T valueA, T valueB)
{
  if(findNode(valueA))
  {
    GraphNode<T>* targetNode = getNode(valueA);
    std::list<GraphNode<T>*> neighbors = targetNode->getAwns();
    for (GraphNode<T>* neighbor : neighbors)
    {
       if(neighbor->getValue() == valueB)
       {
         return true;
       }
    }
  }
  return false;
}

#endif