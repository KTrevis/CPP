#ifndef _Animal_HPP_
#define _Animal_HPP_

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(Animal const &obj);
		virtual ~Animal();
		Animal &operator=(const Animal &obj);
		virtual void	makeSound() const;
		/* GETTERS */
		std::string	getType();

	protected:
		std::string type;
};

#endif
