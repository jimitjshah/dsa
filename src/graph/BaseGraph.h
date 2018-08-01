/*
 * BaseGraph.h
 *
 *  Created on: Jul 6, 2018
 *      Author: jshah
 */

#include <vector>

#include "GraphNode.h"

#ifndef SRC_GRAPH_BASEGRAPH_H_
#define SRC_GRAPH_BASEGRAPH_H_


typedef std::vector<GraphNode*> NodeList;

class BaseGraph {
public:
	BaseGraph();
	virtual ~BaseGraph();

	virtual void addEdge(uint32_t v, uint32_t w, int32_t weight) = 0;
	virtual void addEdge(uint32_t v, uint32_t w) = 0;

	uint32_t V() const { return numVertices_; }
	uint32_t E() const { return numEdges_; }

	virtual NodeList::iterator adj(uint32_t v) = 0;	//Returns startnode of adj list
	virtual void toString() = 0;
private:

    uint32_t numVertices_;
    uint32_t numEdges_;
};

#endif /* SRC_GRAPH_BASEGRAPH_H_ */
