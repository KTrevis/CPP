#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &obj) {
	if (this != &obj)
		*this = obj;
}

RPN	&RPN::operator=(const RPN &obj) {
	if (this == &obj)
		return *this;
	return *this;
}
