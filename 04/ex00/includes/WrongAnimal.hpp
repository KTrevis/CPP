#ifndef _WrongAnimal_HPP_
#define _WrongAnimal_HPP_

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &obj);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &obj);
		void	makeSound();
};

#endif
