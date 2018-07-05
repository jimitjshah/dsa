/*
 * NodeProperties.cpp
 *
 *  Created on: Jul 5, 2018
 *      Author: jshah
 */

#include "NodeProperties.h"

NodeProperties::NodeProperties(uint32_t val, int32_t wt) :value_(val),
														  weight_(wt)
{}

NodeProperties::~NodeProperties() {
}

uint32_t NodeProperties::getValue() const {
	return value_;
}

int32_t NodeProperties::getWeight() const {
	return weight_;
}
