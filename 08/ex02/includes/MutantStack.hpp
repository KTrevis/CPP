#ifndef _MutantStack_HPP_
#define _MutantStack_HPP_

#include <stack>
#include <stdexcept>

template <typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack<T>() {};
		MutantStack<T>(MutantStack const &obj) {
			static_cast<void>(obj);
		};
		~MutantStack<T>() {};
		MutantStack<T> &operator=(const MutantStack<T> &obj);
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end) {
			this->c.insert(this->c.end(), begin, end);
		}
};

#endif
