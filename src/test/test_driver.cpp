#include <iostream>
#include "SparseGraph.h"

//For testing only
int main(void) {
    printf("Starting dsa_test\n");
    SparseGraph g;

    g.addEdge(1,2);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,1);

    g.addEdge(8,9);
    g.addEdge(9,10);
    g.addEdge(9,11);
    g.addEdge(11,8);

    g.toString();
	return 0;
}
