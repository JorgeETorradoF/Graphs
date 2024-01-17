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
  this->visited = false;
}
template<class T>
T GraphNode<T>::getValue()
{
  return this->value;
}
template<class T>
std::list<std::pair<GraphNode<T>*,int> > GraphNode<T>::getAwns()
{
  return this->awns;
}
template<class T>
void GraphNode<T>::setValue(T value)
{
  this->value = value;
}
template<class T>
void GraphNode<T>::addAwn(GraphNode<T>* newNode, int cost)
{
  std::pair<GraphNode<T>*,int> newPair(newNode, cost);
  bool exists = false;
  typename std::list<std::pair<GraphNode<T>*,int> >::iterator it = (this->awns).begin();
  for(it; it != (this->awns).end(); it++)
  {
    if(((*it).first)->getValue() == newNode->getValue())
    {
      exists = true;
      break;
    }
  }
  if(!exists)
  {
    (this->awns).push_back(newPair);
  }
}
template<class T>
void GraphNode<T>::deleteAwn(T value)
{
  typename std::list<std::pair<GraphNode<T>*,int> >::iterator it = (this->awns).begin();
  for(it; it != (this->awns).end(); it++)
  {
    if(((*it).first)->getValue() == value)
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
template<class T>
bool GraphNode<T>::neighborsVisited()
{
  typename std::list<std::pair<GraphNode<T>*,int> >::iterator it = (this->awns).begin();
  for(it; it != (this->awns).end(); it++)
    {
      if(!((*it).first)->isVisited())
      {
        return false;
      }
    }
  return true;
}
template <class T>
std::pair<GraphNode<T>*,int> GraphNode<T>::getCheapestAwn()
{
  std::pair<GraphNode<T>*,int> cheapestAwn;
  if(!(this->awns).empty())
  {
    typename std::list<std::pair<GraphNode<T>*,int> >::iterator it = (this->awns).begin();
    cheapestAwn = *it;
    it++;
    for(it; it != (this->awns).end(); it++)
    {
      if(((*it).second) < cheapestAwn.second)
      {
        cheapestAwn = *it;
      }
    }
  }
  return cheapestAwn;
}
#endif