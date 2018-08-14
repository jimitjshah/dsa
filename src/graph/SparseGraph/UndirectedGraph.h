/*
 * UndirectedGraph.h
 *
 *  Created on: Aug 14, 2018
 *      Author: jshah
 */

#ifndef SRC_GRAPH_SPARSEGRAPH_UNDIRECTEDGRAPH_H_
#define SRC_GRAPH_SPARSEGRAPH_UNDIRECTEDGRAPH_H_

#include "SparseGraph.h"

class UndirectedGraph: public SparseGraph {
public:
	UndirectedGraph();
	virtual ~UndirectedGraph();

	void addEdge(uint32_t v, uint32_t w, int32_t weight);
	void addEdge(uint32_t v, uint32_t w);
};

#endif /* SRC_GRAPH_SPARSEGRAPH_UNDIRECTEDGRAPH_H_ */
