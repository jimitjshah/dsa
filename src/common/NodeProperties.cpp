#include"NodeProperties.h"

uint32_t
NodeProperties::getValue() const {
	return value_;
}

int32_t
NodeProperties::getWeight() const {
	return weight_;
}

void
NodeProperties::setValue(uint32_t value) {
	value_ = value;
}

void
NodeProperties::setWeight(int32_t weight) {
	weight_ = weight;
}
