#include <iostream>
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

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

//For testing only
int main(void) {
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

	return 0;
}
