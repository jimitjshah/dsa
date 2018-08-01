/*
 * SparseGraph.h
 *
 *  Created on: Jul 11, 2018
 *      Author: jshah
 */

#include "BaseGraph.h"

#include <map>
#include <vector>

#ifndef SRC_GRAPH_SPARSEGRAPH_SPARSEGRAPH_H_
#define SRC_GRAPH_SPARSEGRAPH_SPARSEGRAPH_H_

class GraphNode;
class BaseGraph;

typedef std::vector<GraphNode*> NodeList;

class SparseGraph : public BaseGraph {
public:
	SparseGraph();
	~SparseGraph();

	void addEdge(uint32_t v, uint32_t w, int32_t weight);
	void addEdge(uint32_t v, uint32_t w);

	NodeList::iterator adj(uint32_t v) {
	  auto adjListItr = adjVertices_.find(v);
	  return adjListItr->second.begin();
	}

	void toString();

private:
	GraphNode* lookupNode(uint32_t v, uint32_t w);
    std::map<uint32_t,NodeList > adjVertices_;
};

#endif /* SRC_GRAPH_SPARSEGRAPH_SPARSEGRAPH_H_ */
