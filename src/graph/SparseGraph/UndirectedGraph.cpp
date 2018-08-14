/*
 * UndirectedGraph.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: jshah
 */

#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph() {
	// TODO Auto-generated constructor stub

}

UndirectedGraph::~UndirectedGraph() {
	// TODO Auto-generated destructor stub
}

void
UndirectedGraph::addEdge(uint32_t v, uint32_t w, int32_t weight)
{
	base_type::addEdge(v, w, weight);
	base_type::addEdge(w, v, weight);
}

void
UndirectedGraph::addEdge(uint32_t v, uint32_t w)
{
	base_type::addEdge(v, w);
	base_type::addEdge(w, v);
}
