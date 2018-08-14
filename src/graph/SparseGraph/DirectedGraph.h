/*
 * DirectedGraph.h
 *
 *  Created on: Aug 14, 2018
 *      Author: jshah
 */

#ifndef SRC_GRAPH_SPARSEGRAPH_DIRECTEDGRAPH_H_
#define SRC_GRAPH_SPARSEGRAPH_DIRECTEDGRAPH_H_

#include "SparseGraph.h"

class DirectedGraph final : public SparseGraph {
public:
	DirectedGraph();
	virtual ~DirectedGraph();
};

#endif /* SRC_GRAPH_SPARSEGRAPH_DIRECTEDGRAPH_H_ */
