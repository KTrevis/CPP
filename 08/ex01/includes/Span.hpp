#ifndef _Span_HPP_
#define _Span_HPP_

#include <iostream>

class Span {
	public:
		Span();
		Span(Span const &obj);
		~Span();
		Span &operator=(const Span &obj);
};

#endif
