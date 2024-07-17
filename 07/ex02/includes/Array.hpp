#ifndef _Array_HPP_
#define _Array_HPP_

#include <exception>
#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
	public:
		Array<T>() {
			this->elements = NULL;
			this->len = 0;
		}

		Array<T>(const unsigned int &size) {
			this->elements = new T[size];
			this->len = size;
		}

		Array<T>(Array<T> const &obj) {
			this->elements = NULL;
			this->len = 0;
			*this = obj;
		}

		~Array<T>() {
			delete []elements;
		}

		Array<T> &operator=(const Array<T> &obj) {
			if (this == &obj)
				return *this;
			delete []this->elements;
			len = obj.size();
			this->elements = new T[len];
			for (unsigned int i = 0; i < obj.size(); i++)
				this->elements[i] = obj[i];
			return *this;
		}

		unsigned int	size() const {
			return this->len;
		}

		const T	&operator[](unsigned int index) const {
			if (index >= this->len)
				throw std::out_of_range("Index out of range.");
			return this->elements[index];
		}

		T	&operator[](unsigned int index) {
			if (index >= this->len)
				throw std::out_of_range("Index out of range.");
			return this->elements[index];
		}

	private:
		T				*elements;
		unsigned int	len;
};

#endif
