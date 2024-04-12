#ifndef _Animal_HPP_
#define _Animal_HPP_

#include <iostream>

class Animal {
	public:
		Animal(Animal const &obj);
		virtual ~Animal();
		Animal &operator=(const Animal &obj);
		virtual void	makeSound();
		/* GETTERS */
		std::string	getType();

	protected:
		Animal();
		std::string type;
};

#endif
