#ifndef _ScalarConverter_HPP_
#define _ScalarConverter_HPP_

#include <iostream>

enum e_type {
	UNDEFINED,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter {
	public:
		ScalarConverter(ScalarConverter const &obj);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &obj);
		static void		convert(std::string str);

	private:

	protected:
		ScalarConverter();

};

#endif
