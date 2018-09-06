/*
 * BaseGraph.h
 *
 *  Created on: Jul 6, 2018
 *      Author: jshah
 */

#include <set>
#include <vector>
#include <ostream>

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

	const std::set<uint32_t>& vertices() const { return vertices_; }

	uint32_t V() const { return vertices_.size(); }
	uint32_t E() const { return numEdges_; }

	virtual NodeList* adj(uint32_t v) const = 0;	//Returns startnode of adj list
	virtual void toString(std::ostream& os) const = 0;

protected:

    uint32_t numEdges_;
    std::set<uint32_t> vertices_;
};

#endif /* SRC_GRAPH_BASEGRAPH_H_ */
