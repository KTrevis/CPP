#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <iostream>
#include <stack>

class RPN {
	public:
		RPN();
		void	calculate(const std::string &str);
		RPN(RPN const &obj);
		~RPN();
		RPN &operator=(const RPN &obj);
	private:
		std::stack<int> _stack;
		void	applyOperator(char token);
		const std::string _tokens;
};

#endif
