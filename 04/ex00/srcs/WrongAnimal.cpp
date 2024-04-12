#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal : Default Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal : Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj) {
	std::cout << "WrongAnimal : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongAnimal	&WrongAnimal::operator= (const WrongAnimal &obj) {
	std::cout << "WrongAnimal : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

void	WrongAnimal::makeSound() {
	std::cout << "I am a wrong animal" << std::endl;
}
