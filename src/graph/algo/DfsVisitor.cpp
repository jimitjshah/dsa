/*
 * DfsVisitor.cpp
 *
 *  Created on: Aug 17, 2018
 *      Author: jshah
 */

#include <cassert>

#include "DfsVisitor.h"
#include "SparseGraph.h"

DfsVisitor::DfsVisitor(const SparseGraph *graph) : graph_(graph),
												   curNode_(nullptr)
{
  for (const auto& v : graph_->vertices()) {
    initVertex(v);
    visited_[v] = false;
  }
}

DfsVisitor::~DfsVisitor() {
	// TODO Auto-generated destructor stub
}

void
DfsVisitor::Init(uint32_t vertex)
{
	startVertex_ = vertex;
	startVertex(startVertex_);
}

void
DfsVisitor::visit_(uint32_t v)
{
	assert(!visited_[v]);
	visitStack_.push(v);
	visited_[v] = true;

	visitVertex(v);
	NodeList* adjList = graph_->adj(v);
	NodeList::iterator adjItr = adjList->begin();
	while (adjItr != adjList->end()) {
      GraphNode* adjNode = *adjItr;
      uint32_t nodeValue = adjNode->prop.getValue();
      if (!visited_[nodeValue]) {
    	  visitStack_.push(nodeValue);

    	  visit_(nodeValue);

    	  std::cout << "nodeValue = " << nodeValue << " stackTop = " << visitStack_.top() << std::endl;

    	  visitStack_.pop();
      }
      adjItr++;
	}

	finishVertex(v);
}

void
DfsVisitor::Visit()
{
	uint32_t v = startVertex_;
	visit_(v);
}

