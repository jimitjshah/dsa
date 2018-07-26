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
													 weight_(weight),
													 next_(nullptr),
													 prev_(nullptr)
	{}

	virtual ~NodeProperties() {};

	uint32_t getValue() const;
	int32_t getWeight() const;
	void setValue(uint32_t value);
	void setWeight(int32_t weight);

	void setNext(NodeProperties* next) { next_ = next; }
	void setPrev(NodeProperties* prev) { prev_ = prev; }

	NodeProperties* Next() { return next_; }
	NodeProperties* Prev() { return prev_; }

private:
	uint32_t value_;
	int32_t weight_;

	NodeProperties *next_;
	NodeProperties *prev_;
};

#endif /* SRC_COMMON_NODEPROPERTIES_H_ */
