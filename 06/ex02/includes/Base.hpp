#pragma once

#include <iostream>

class Base {
	public:
		virtual ~Base();
		Base	*generate();
		void	identify(Base *ptr);
		void	identify(Base &ptr);
};

class	A: public Base {};
class	B: public Base {};
class	C: public Base {};
