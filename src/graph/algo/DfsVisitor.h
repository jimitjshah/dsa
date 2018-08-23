/*
 * DfsVisitor.h
 *
 *  Created on: Aug 17, 2018
 *      Author: jshah
 */

#ifndef SRC_GRAPH_ALGO_DFSVISITOR_H_
#define SRC_GRAPH_ALGO_DFSVISITOR_H_

#include <stack>
#include <map>
#include <iostream>

class GraphNode;
class SparseGraph;

class DfsVisitor {
public:
	DfsVisitor(const SparseGraph *graph);
	virtual ~DfsVisitor();

	virtual void Init(uint32_t vertex);

	void Visit();

	//From Boost - Visitor APIs
	//Initialize Vertex - called when initializing all vertices
	virtual void initVertex(uint32_t v) {
		std::cout << __FUNCTION__ << " : " << v << "\n";
	};

	//Start Vertex - called once for source vertex before traversal
	virtual void startVertex(uint32_t v) {
		std::cout << __FUNCTION__ << " : " << v << "\n";
	};

	//Discover Vertex - called for each newly discovered vertex
	virtual void visitVertex(uint32_t v) {
		std::cout << __FUNCTION__ << " : " << v << "\n";
	};

	//Finish Vertex - called for each vertex completed
	virtual void finishVertex(uint32_t v) {
		std::cout << __FUNCTION__ << " : " << v << "\n";
	};

	//Examine Edge - called for each new edge
	virtual void examineEdge(uint32_t fromV, uint32_t toV) {
		std::cout << __FUNCTION__ << ": " << fromV << "->" << toV << "\n";
};

	//Tree Edge - called for each edge that becomes a part of the search tree
	//Back Edge - reverse path of search tree
	//Forward Or Cross Edge - never called for undirected graph

	//Copy Constructor

private:
	void visit_(uint32_t v);

	const SparseGraph* graph_;
	std::stack<uint32_t> visitStack_;
	std::map<uint32_t, bool> visited_;

	const GraphNode* curNode_;
	uint32_t startVertex_;
};

#endif /* SRC_GRAPH_ALGO_DFSVISITOR_H_ */
