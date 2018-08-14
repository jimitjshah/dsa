/*
 * SparseGraph.cpp
 *
 *  Created on: Jul 11, 2018
 *      Author: jshah
 */

#include <iostream>
#include "SparseGraph.h"

//#define DEBUG

class GraphNode;

std::ostream& operator<<(std::ostream& os, const NodeList& nodeList) {
	for (auto node : nodeList) {
		os << " -> " << node->prop.getValue();
	}

	return os;
}

SparseGraph::SparseGraph() : BaseGraph() {
}

SparseGraph::~SparseGraph() {
  if (!adjVertices_.empty()) {
	  std::map<uint32_t,NodeList* >::iterator adjItr = adjVertices_.begin();
	  for ( ; adjItr != adjVertices_.end() ; adjItr++) {
		NodeList* toDelete = adjItr->second;
		for (NodeList::iterator vItr = toDelete->begin(); vItr != toDelete->end(); ++vItr) {
			delete *vItr;
		}
		delete toDelete;
		adjVertices_.erase(adjItr);
	}
  }
}

GraphNode*
SparseGraph::lookupNode(uint32_t v, uint32_t w) {
	std::map<uint32_t, NodeList*>::iterator adjItr = adjVertices_.find(v);
	if (adjItr != adjVertices_.end()) {
		NodeList* list = adjItr->second;
		for (auto gNode : *list) {
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
		std::map<uint32_t, NodeList*>::iterator adjItr = adjVertices_.find(v);
		if (adjItr != adjVertices_.end()) {
			NodeList* list = adjItr->second;
			list->push_back(temp);
		} else {
			std::vector<GraphNode*>* newList = new NodeList();
			newList->push_back(temp);
			adjVertices_[v] = newList;
			numVertices_++;
		}
	}
	numEdges_++;
}

void
SparseGraph::addEdge(uint32_t v, uint32_t w) {
	auto nodeFound = lookupNode(v, w);
	if (nodeFound == nullptr) {
		auto temp = new GraphNode(w, GraphNode::GRAPH_CONST_WT);
		std::map<uint32_t, NodeList*>::iterator adjItr = adjVertices_.find(v);
		if (adjItr != adjVertices_.end()) {
			NodeList* list = adjItr->second;
			list->push_back(temp);
		} else {
			std::vector<GraphNode*>* newList = new NodeList();
			newList->push_back(temp);
			adjVertices_[v] = newList;
			numVertices_++;
		}
#ifdef DEBUG
		std::cout << "\naddEdge(" << v << ", " << w << "):\t";
		std::map<uint32_t, NodeList*>::iterator pItr = adjVertices_.find(v);
		NodeList* nodelist = pItr->second;
		std::cout << *nodelist;
#endif
		numEdges_++;
	}
}

void
SparseGraph::toString(std::ostream& os) const {
	os << "*********** Graph ***********\n";
	os << "V = " << V() << ", E = " << E() << std::endl;
	std::map<uint32_t, NodeList*>::const_iterator adjItr = adjVertices_.begin();
	for ( ; adjItr != adjVertices_.end(); ++adjItr) {
		os << adjItr->first;
		os << *adjItr->second;
		os << std::endl;
	}
	os << "*********** End ***********\n";
}
