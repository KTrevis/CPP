#ifndef _Animal_HPP_
#define _Animal_HPP_

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(Animal const &obj);
		virtual Animal &operator=(const Animal &obj);
		virtual ~Animal();
		virtual void	makeSound() = 0;
		virtual void	displaySomeIdeas() = 0;
		/* GETTERS */
		std::string	getType();

	protected:
		std::string type;
};

#endif
