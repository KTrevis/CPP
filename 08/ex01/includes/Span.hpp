#ifndef _Span_HPP_
#define _Span_HPP_

#include <iostream>
#include <vector>

class Span {
	public:
		Span(int size);
		Span(Span const &obj);
		~Span();
		Span &operator=(const Span &obj);
		void	addNumber(int n);
	private:
		Span();
		std::vector<int>	_arr;
		unsigned int		_size;
};

#endif
