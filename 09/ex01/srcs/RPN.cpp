#include "RPN.hpp"
#include <cstdlib>

RPN::RPN(): _tokens("+-*/") {}

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

void	RPN::applyOperator(char token) {
	int b = _stack.top(); _stack.pop();
	int a = _stack.top(); _stack.pop();
	switch (token) {
		case ('+'): _stack.push(a + b); break;
		case ('-'): _stack.push(a - b); break;
		case ('*'): _stack.push(a * b); break;
		case ('/'): _stack.push(a / b); break;
	}
}

void	RPN::calculate(const std::string &str) {
	for (size_t i = 0; i < str.size(); i++) {
		std::string nb;
		nb += str[i];
		if (_tokens.find(nb[0]) != std::string::npos) {
			if (_stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;
			}
			applyOperator(nb[0]);
		}
		else
			_stack.push(std::atoi(nb.c_str()));
		i++;
		if (i < str.size() && str[i] != ' ') {
			std::cerr << "Error";
			return;
		}
	}
	if (_stack.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}
