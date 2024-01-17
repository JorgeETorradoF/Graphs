#include <iostream>
#include "Graph.h"

int main() 
{
  /*GraphNode<int>* nodoKawaii = new GraphNode<int>(3);
  GraphNode<int>* newNodoKawaii = new GraphNode<int>(5);
  GraphNode<int>* newNodoKawaii2 = new GraphNode<int>(6);
  GraphNode<int>* newNodoKawaii3 = new GraphNode<int>(6);
  nodoKawaii->addAwn(newNodoKawaii);
  nodoKawaii->addAwn(newNodoKawaii2);
  nodoKawaii->addAwn(newNodoKawaii3);
  nodoKawaii->deleteAwn(6);
  std::cout << "value: " << nodoKawaii->getValue()<< "\n";
  std::list<GraphNode<int>*> lista = nodoKawaii->getAwns();
  for(auto it = lista.begin(); it != lista.end(); it++)
  {
    std::cout<< "Awns: " << (*it)->getValue()<<"\n";
  }
  */
  Graph<int>* grafoKawaii = new Graph<int>(3);
  grafoKawaii->addNode(5);
  grafoKawaii->addNode(7);
  grafoKawaii->addNode(10);
  grafoKawaii->addAwn(3, 10, 12);
  grafoKawaii->addAwn(3, 5, 1);
  grafoKawaii->addAwn(5, 10, 6);
  grafoKawaii->addAwn(5, 7, 3);
  grafoKawaii->addAwn(3, 7, 6);
  grafoKawaii->addAwn(10, 7, 15);
  std::list<GraphNode<int>*> grafito = grafoKawaii->getGraph();
  std::cout << "\nPlain search: \n";
  for(auto it = grafito.begin(); it != grafito.end(); it++)
  {
    std::cout<< "Node number: " << (*it)->getValue()<<"\n";
  }
  auto listaAristas = grafoKawaii->getNode(3)->getAwns();
  std::cout <<"does the Awn (3 , 10) exists? " << grafoKawaii->findAwn(3, 10) << "\n";
  std::cout <<"\nLets see the awns number 3 has\n";
  for(auto it = listaAristas.begin(); it != listaAristas.end(); it++)
  {
    std::cout<< "Awns: " << ((*it).first)->getValue()<< " cost of that awn: "<< ((*it).second)<<"\n";
  }
   std::cout <<"\nCheapest awn of number 3: " << ((grafoKawaii->getNode(3)->getCheapestAwn()).first)->getValue()<<"\n";
  listaAristas = grafoKawaii->getNode(10)->getAwns();
  std::cout <<"\nNow lets see the awns number 10 has\n";
  for(auto it = listaAristas.begin(); it != listaAristas.end(); it++)
  {
    std::cout<< "Awns: " << ((*it).first)->getValue()<< " cost of that awn: "<< ((*it).second)<<"\n";
  }
  std::list<GraphNode<int>*> grafito2 = grafoKawaii->depthFirst();
  std::cout << "\nDepth first search: \n";
  for(auto it = grafito2.begin(); it != grafito2.end(); it++)
  {
    std::cout<< "\nNode number: " << (*it)->getValue();
  }
  std::list<GraphNode<int>*> otroGrafito = grafoKawaii->breadthFirst();
  std::cout << "\n\nBreadth first search: \n";
  for(auto it = otroGrafito.begin(); it != otroGrafito.end(); it++)
  {
    std::cout<< "\nNode number: " << (*it)->getValue();
  }
  std::cout <<"\nLet's see Dijkstra's algorithm on node 3\n";
  std::vector<dijkstraNode<int> > dijkstraVec = grafoKawaii->dijkstra(3);
  for(int i = 0; i < dijkstraVec.size(); i++)
    {
       std::cout <<"\nNode: " << dijkstraVec[i].nodeValue << " Total cost: " << dijkstraVec[i].cost << " predecessor: " << dijkstraVec[i].predecessor <<"\n";
    }
  std::cout << "\n\nhi there, lets delete awn (3 , 10)\n";
  grafoKawaii->deleteAwn(3, 10);
  listaAristas = grafoKawaii->getNode(3)->getAwns();
  for(auto it = listaAristas.begin(); it != listaAristas.end(); it++)
  {
    std::cout<< "\nAwns of number 3: " << ((*it).first)->getValue()<<"\n";
  }
  std::cout << "\nhi there, lets delete node 3 from the graph\n\n";
  grafoKawaii->deleteNode(3);
  grafito = grafoKawaii->getGraph();
  for(auto it = grafito.begin(); it != grafito.end(); it++)
  {
    std::cout<< "Nodes after deletion of 3: " << (*it)->getValue()<<"\n";
  }
}