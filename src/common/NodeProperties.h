/*
 * NodeProperties.h
 *
 *  Created on: Jul 5, 2018
 *      Author: jshah
 */

#ifndef SRC_COMMON_NODEPROPERTIES_H_
#define SRC_COMMON_NODEPROPERTIES_H_

#include <cstdint>

class NodeProperties {
public:
	NodeProperties(uint32_t value, int32_t weight) : value_(value),
																	weight_(weight)
	{}

	virtual ~NodeProperties();

	void setValue(uint32_t value);
	void setWeight(int32_t weight);

private:
	uint32_t value_;
	int32_t weight_;
};

#endif /* SRC_COMMON_NODEPROPERTIES_H_ */
