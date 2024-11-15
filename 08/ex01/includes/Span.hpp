#ifndef _Span_HPP_
#define _Span_HPP_

#include <exception>
#include <iostream>
#include <vector>

class Span {
	public:
		Span(unsigned int size);
		Span(Span const &obj);
		~Span();
		Span &operator=(const Span &obj);
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end) {
			this->_arr.insert(this->_arr.end(), begin, end);
		}	

		class SpanFullException: public std::exception {
			virtual const char *what() const throw();
		};

		class NoSpanException: public std::exception {
			virtual const char *what() const throw();
		};
	private:
		Span();
		std::vector<int>	_arr;
		unsigned int		_maxSize;
};

#endif
