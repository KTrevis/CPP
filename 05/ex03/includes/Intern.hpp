#ifndef _Intern_HPP_
#define _Intern_HPP_

#include <iostream>

class Intern {
	public:
		Intern();
		Intern(Intern const &obj);
		~Intern();
		Intern &operator=(const Intern &obj);
};

#endif
