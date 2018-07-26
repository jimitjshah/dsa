/*
 * GraphNode.h
 *
 *  Created on: Jul 11, 2018
 *      Author: jshah
 */

#ifndef SRC_GRAPH_GRAPHNODE_H_
#define SRC_GRAPH_GRAPHNODE_H_

#include <vector>

#include "common/NodeProperties.h"

class GraphNode {
public:
	GraphNode(uint32_t val, int32_t weight);
	virtual ~GraphNode();

    NodeProperties prop;
};

typedef std::vector<GraphNode*> NodeList;

#endif /* SRC_GRAPH_GRAPHNODE_H_ */
