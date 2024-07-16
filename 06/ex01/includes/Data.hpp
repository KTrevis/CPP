#ifndef _Data_HPP_
#define _Data_HPP_

#include <iostream>

class Data {
	public:
		Data();
		Data(Data const &obj);
		~Data();
		Data &operator=(const Data &obj);
		const std::string	&getName() const;
		void				setName(const std::string &name);
	private:
		std::string	name;
};

#endif
