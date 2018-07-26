/*
 * GraphNode.cpp
 *
 *  Created on: Jul 11, 2018
 *      Author: jshah
 */


#include "GraphNode.h"

GraphNode::GraphNode(uint32_t val, int32_t weight) : prop(val, weight)
{
}

GraphNode::~GraphNode() {
}

