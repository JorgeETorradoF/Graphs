#ifndef GraphNode_H
#define GraphNode_H
#include<list>
template<class T>
class GraphNode
{
   protected:
    T value;
    std::list<std::pair<GraphNode<T>*,int> > awns;
    bool visited;
   public:
    GraphNode(T value);
    ~GraphNode();
    T getValue();
    void visitNode();
    void unvisitNode();
    bool isVisited();
    std::list<std::pair<GraphNode<T>*,int> > getAwns();
    void setValue(T value);
    void addAwn(GraphNode<T>* newNode, int cost);
    void deleteAwn(T value);
    bool noAwns();
    bool neighborsVisited();
    std::pair<GraphNode<T>*,int> getCheapestAwn();
};
#include "GraphNode.hxx"
#endif //GraphNode_h