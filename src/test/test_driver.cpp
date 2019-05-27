#include <iostream>
#include "DirectedGraph.h"
#include "UndirectedGraph.h"
#include "DfsVisitor.h"
#include "BfsVisitor.h"
#include "circularqueue.h"
#include "BfsWallsAndGates.h"

std::ostream& operator<<(std::ostream& os, const DirectedGraph& graph) {
	os << "DirectedGraph\n";
	graph.toString(os);
	return os;
}

std::ostream& operator<<(std::ostream& os, const UndirectedGraph& graph) {
	os << "UndirectedGraph\n";
	graph.toString(os);
	return os;
}

void testGraph()
{
    printf("Starting dsa_test\n");
    DirectedGraph g1;

    g1.addEdge(1,2);
    g1.addEdge(1,5);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(3,4);
    g1.addEdge(4,5);
    g1.addEdge(4,6);
    g1.addEdge(5,6);
    g1.addEdge(6,7);
    g1.addEdge(7,1);

    g1.addEdge(8,9);
    g1.addEdge(9,10);
    g1.addEdge(9,11);
    g1.addEdge(11,8);

    std::cout << g1;

    UndirectedGraph g2;

    g2.addEdge(1,2);
    g2.addEdge(1,5);
    g2.addEdge(2,3);
    g2.addEdge(2,4);
    g2.addEdge(3,4);
    g2.addEdge(4,5);
    g2.addEdge(4,6);
    g2.addEdge(5,6);
    g2.addEdge(6,7);
    g2.addEdge(7,1);

    g2.addEdge(8,9);
    g2.addEdge(9,10);
    g2.addEdge(9,11);
    g2.addEdge(11,8);

    std::cout << g2;

    std::cout << "DfsVisitor\n";
    DfsVisitor visitor(&g2);
    visitor.Init(1);
    visitor.Visit();

    std::cout << "\nBfsVisitor\n";
    BfsVisitor bfsVisitor(&g2);
    bfsVisitor.Init(1);
    bfsVisitor.Visit();
}

void testCircularQueue()
{
	  int value = 1;
	  MyCircularQueue* obj = new MyCircularQueue(3);
	  std::cout << obj << std::endl;
	  bool param_1 = obj->enQueue(value++);
	  std::cout << param_1 << std::endl;
	  bool param_2 = obj->deQueue();
	  std::cout << param_2 << std::endl;
	  int param_3 = obj->Front();
	  std::cout << param_3 << std::endl;
	  int param_4 = obj->Rear();
	  std::cout << param_4 << std::endl;
	  bool param_5 = obj->isEmpty();
	  std::cout << param_5 << std::endl;
	  bool param_6 = obj->isFull();
	  std::cout << param_6 << std::endl;
}

//For testing only
int main(void) {
//	testCircularQueue();
	BfsWallsAndGates wag;
	wag.TestDriver();
	return 0;
}
