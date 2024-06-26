#ifndef _Cat_HPP_
#define _Cat_HPP_

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat();
		Cat(Cat const &obj);
		~Cat();
		Cat &operator=(const Cat &obj);
		void	makeSound();
		void	displaySomeIdeas();

	private:
		Brain	*brain;
};

#endif
