#ifndef _Data_HPP_
#define _Data_HPP_

#include <iostream>

enum e_type {
	UNDEFINED,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class Data {
	public:
		Data(const std::string &str);
		Data(Data const &obj);
		~Data();
		Data &operator=(const Data &obj);
		char	c;
		int		n;
		float	f;
		double	d;
		e_type	type;
	private:
		e_type	getType(const std::string &str);
		Data();
};

#endif
