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
	virtual ~SparseGraph();

	virtual void addEdge(uint32_t v, uint32_t w, int32_t weight);
	virtual void addEdge(uint32_t v, uint32_t w);

	NodeList* adj(uint32_t v) const {
	  auto adjListItr = adjVertices_.find(v);
	  return adjListItr->second;
	}

	void toString(std::ostream& os) const;

protected:
	using base_type = SparseGraph;

private:
	GraphNode* lookupNode(uint32_t v, uint32_t w);
    std::map<uint32_t,NodeList* > adjVertices_;
};

#endif /* SRC_GRAPH_SPARSEGRAPH_SPARSEGRAPH_H_ */
