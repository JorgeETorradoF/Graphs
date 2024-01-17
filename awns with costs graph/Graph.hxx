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
void Graph<T>::addAwn(T valueA, T valueB, int cost)
{
  if(findNode(valueA) && findNode(valueB))
  {
    GraphNode<T>* targetNodeA = getNode(valueA);
    GraphNode<T>* targetNodeB = getNode(valueB);
    addAwnAux(targetNodeA, targetNodeB, cost);
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
void Graph<T>::addAwnAux(GraphNode<T>* nodeA, GraphNode<T>* nodeB, int cost)
{
  nodeA->addAwn(nodeB, cost);
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

    std::list<std::pair<GraphNode<T>*,int> > neighbors = currentNode->getAwns();
    for (std::pair<GraphNode<T>*,int>  neighbor : neighbors) {
        if (!(neighbor.first)->isVisited()) {
            depthFirstAux(neighbor.first, nodeList);
        }
    }
}
template<class T>
bool Graph<T>::findAwn(T valueA, T valueB)
{
  if(findNode(valueA))
  {
    GraphNode<T>* targetNode = getNode(valueA);
    std::list<std::pair<GraphNode<T>*,int> > neighbors = targetNode->getAwns();
    for (std::pair<GraphNode<T>*,int>  neighbor : neighbors)
    {
       if((neighbor.first)->getValue() == valueB)
       {
         return true;
       }
    }
  }
  return false;
}

template<class T>
std::list<GraphNode<T>*> Graph<T>::breadthFirst() {
    std::list<GraphNode<T>*> result; // List to store visited nodes

    if (nodes.empty()) {
        return result; // No nodes to traverse
    }

    // Create a queue to store nodes to visit
    std::queue<GraphNode<T>*> queue;

    // Start with the first node in the graph
    GraphNode<T>* startNode = nodes.front();
    startNode->visitNode(); // Mark the start node as visited
    queue.push(startNode);

    while (!queue.empty()) {
        // Dequeue a node from the front of the queue
        GraphNode<T>* currentNode = queue.front();
        queue.pop();

        result.push_back(currentNode); // Store the visited node in the list

        // Get the adjacent nodes of the current node
        std::list<std::pair<GraphNode<T>*, int> > adjNodes = currentNode->getAwns();
        for (const auto& neighbor : adjNodes) {
            GraphNode<T>* nextNode = neighbor.first;

            if (!nextNode->isVisited()) {
                nextNode->visitNode(); // Mark the neighbor as visited
                queue.push(nextNode); // Enqueue the neighbor for traversal
            }
        }
    }

    // Reset the visited state of all nodes after the traversal
    for (auto node : nodes) {
        node->unvisitNode();
    }

    return result;
}
template<class T>
int Graph<T>::findNodeIndex(T value) {
    int index = 0;
    for (const auto& node : nodes) {
        if (node->getValue() == value) {
            return index;
        }
        index++;
    }
    return -1; // Node not found
}

template<class T>
std::vector<dijkstraNode<T>> Graph<T>::dijkstra(T sourceValue) {
    std::vector<dijkstraNode<T>> dist;

    // Initialize distance vector with infinite values
    for (const auto& node : nodes) {
        dijkstraNode<T> nodeData;
        nodeData.nodeValue = node->getValue();
        dist.push_back(nodeData);
    }

    // Find the source node
    GraphNode<T>* sourceNode = getNode(sourceValue);
    if (sourceNode == nullptr) {
        return dist; // Source node not found
    }

    // Set distance to the source node to 0
    for (auto& nodeData : dist) {
        if (nodeData.nodeValue == sourceValue) {
            nodeData.cost = 0;
            nodeData.predecessor = nodeData.nodeValue;
            break;
        }
    }

    // Create a priority queue to track nodes with the smallest distance
    std::priority_queue<dijkstraNode<T>> pq;

    // Push the source node to the priority queue
    dijkstraNode<T> sourceDijkstraNode;
    sourceDijkstraNode.nodeValue = sourceValue;
    sourceDijkstraNode.cost = 0;
    pq.push(sourceDijkstraNode);

    while (!pq.empty()) {
        dijkstraNode<T> currentNodeData = pq.top();
        pq.pop();
        // Get the current node
        GraphNode<T>* currentNode = getNode(currentNodeData.nodeValue);

        // Explore its neighbors
        for (const auto& neighborPair : currentNode->getAwns()) {
            GraphNode<T>* neighbor = neighborPair.first;
            int edgeCost = neighborPair.second;

            int neighborIndex = findNodeIndex(neighbor->getValue());
                int newCost = dist[findNodeIndex(currentNode->getValue())].cost + edgeCost;

                // If the new cost is smaller, update the distance
                if (newCost < dist[neighborIndex].cost) {
                    dist[neighborIndex].cost = newCost;
                    dist[neighborIndex].predecessor = currentNodeData.nodeValue;

                    // Push the updated node to the priority queue
                    pq.push(dist[neighborIndex]);
                }
        }
    }

    return dist;
}

#endif