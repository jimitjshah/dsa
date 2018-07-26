/*
 * SparseGraph.cpp
 *
 *  Created on: Jul 11, 2018
 *      Author: jshah
 */

#include "SparseGraph.h"

class GraphNode;

SparseGraph::SparseGraph() : BaseGraph() {
}

SparseGraph::~SparseGraph() {
  if (!adjVertices_.empty()) {
	  std::map<uint32_t,NodeList >::iterator adjItr = adjVertices_.begin();
	  for ( ; adjItr != adjVertices_.end() ; adjItr++) {
		NodeList toDelete = adjItr->second;
		for (NodeList::iterator vItr = toDelete.begin(); vItr != toDelete.end(); ++vItr) {
			delete *vItr;
		}
		adjVertices_.erase(adjItr);
	}
  }
}

GraphNode*
SparseGraph::lookupNode(uint32_t v, uint32_t w) {
	std::map<uint32_t, NodeList>::iterator adjItr = adjVertices_.find(v);
	if (adjItr != adjVertices_.end()) {
		NodeList list = adjItr->second;
		for (auto gNode : list) {
			if (gNode->prop.getValue() == w) {
				return gNode;
			}
		}
	}
	return nullptr;
}


void
SparseGraph::addEdge(uint32_t v, uint32_t w, int32_t weight) {
	auto nodeFound = lookupNode(v, w);
	if (nodeFound != nullptr) {
		nodeFound->prop.setWeight(w);
	} else {
		auto temp = new GraphNode(w, weight);
		std::map<uint32_t, NodeList>::iterator adjItr = adjVertices_.find(v);
		if (adjItr != adjVertices_.end()) {
			NodeList list = adjItr->second;
			list.push_back(temp);
		}
	}
}

void
SparseGraph::addEdge(uint32_t v, uint32_t w) {

}
