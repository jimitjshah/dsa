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
	NodeProperties(uint32_t value, int32_t weight);
	virtual ~NodeProperties();
	uint32_t getValue() const;
	int32_t getWeight() const;

private:
	uint32_t value_;
	int32_t weight_;
};

#endif /* SRC_COMMON_NODEPROPERTIES_H_ */
