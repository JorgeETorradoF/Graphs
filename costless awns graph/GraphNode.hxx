#ifndef GraphNode_HXX
#define GraphNode_HXX
#include "GraphNode.h"
template<class T>
GraphNode<T>::GraphNode(T value)
{
  this->value = value;
  this->visited = false;
}
template<class T>
GraphNode<T>::~GraphNode()
{
}
template<class T>
T GraphNode<T>::getValue()
{
  return this->value;
}
template<class T>
std::list<GraphNode<T>*> GraphNode<T>::getAwns()
{
  return this->awns;
}
template<class T>
void GraphNode<T>::setValue(T value)
{
  this->value = value;
}
template<class T>
void GraphNode<T>::addAwn(GraphNode<T>* newNode)
{
  bool exists = false;
  typename std::list<GraphNode<T>*>::iterator it = (this->awns).begin();
  for(it; it != (this->awns).end(); it++)
  {
    if((*it)->getValue() == newNode->getValue())
    {
      exists = true;
      break;
    }
  }
  if(!exists)
  {
    (this->awns).push_back(newNode);
  }
}
template<class T>
void GraphNode<T>::deleteAwn(T value)
{
  typename std::list<GraphNode<T>*>::iterator it = (this->awns).begin();
  for(it; it != (this->awns).end(); it++)
  {
    if((*it)->getValue() == value)
    {
      (this->awns).erase(it);
      break;
    }
  }
}
template<class T>
void GraphNode<T>::visitNode()
{
  this->visited = true;
}
template<class T>
void GraphNode<T>::unvisitNode()
{
  this->visited = false;
}
template<class T>
bool GraphNode<T>::isVisited()
{
  return this->visited;
}
template<class T>
bool GraphNode<T>::noAwns()
{
  return (this->awns).empty();
}
#endif