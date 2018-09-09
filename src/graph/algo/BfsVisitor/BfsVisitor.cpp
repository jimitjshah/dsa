/*
 * BfsVisitor.cpp
 *
 *  Created on: Sep 8, 2018
 *      Author: jshah
 */

#include <cassert>

#include "BfsVisitor.h"
#include "SparseGraph.h"

BfsVisitor::BfsVisitor(const SparseGraph* graph) : graph_(graph),
												   curNode_(nullptr)

{
	for (const auto& v : graph_->vertices()) {
		initVertex(v);
		visited_[v] = false;
	}
}

BfsVisitor::~BfsVisitor() {
	// TODO Auto-generated destructor stub
}

void
BfsVisitor::Init(uint32_t vertex)
{
	startVertex_ = vertex;
	startVertex(vertex);
}

void
BfsVisitor::visit_(uint32_t v)
{
	assert(!visited_[v]);
	visitVertex(v);
	visited_[v] = true;

	NodeList* adjList = graph_->adj(v);
	NodeList::iterator adjItr = adjList->begin();
	while (adjItr != adjList->end()) {
		GraphNode *adjNode = *adjItr;
		uint32_t nodeValue = adjNode->prop.getValue();
		if (!visited_[nodeValue]) {
			visitQueue_.push(nodeValue);
		}
		adjItr++;
	}

	while (!visitQueue_.empty()) {
		uint32_t visitNext = visitQueue_.front();
		visitQueue_.pop();
		if (!visited_[visitNext]) {
			visit_(visitNext);
		}
	}

	finishVertex(v);
}

void
BfsVisitor::Visit()
{
	uint32_t v = startVertex_;
	visit_(v);
}
