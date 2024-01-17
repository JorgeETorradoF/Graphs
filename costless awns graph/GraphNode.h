#ifndef GraphNode_H
#define GraphNode_H
#include<list>
template<class T>
class GraphNode
{
   protected:
    T value;
    std::list<GraphNode<T>*> awns;
    bool visited;
   public:
    GraphNode(T value);
    ~GraphNode();
    T getValue();
    void visitNode();
    void unvisitNode();
    bool isVisited();
    std::list<GraphNode<T>* > getAwns();
    void setValue(T value);
    void addAwn(GraphNode<T>* newNode);
    void deleteAwn(T value);
    bool noAwns();
};
#include "GraphNode.hxx"
#endif //GraphNode_h