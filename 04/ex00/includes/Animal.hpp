#ifndef _Animal_HPP_
#define _Animal_HPP_

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(Animal const &obj);
		~Animal();
		Animal &operator=(const Animal &obj);
		virtual void	makeSound();
		/* GETTERS */
		std::string	getType();

	protected:
		std::string type;
};

#endif
