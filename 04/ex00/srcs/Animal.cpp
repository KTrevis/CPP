#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal : Default Constructor Called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal : Destructor Called" << std::endl;
}

Animal::Animal(Animal const &obj) {
	std::cout << "Animal : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Animal	&Animal::operator=(const Animal &obj) {
	std::cout << "Animal : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}

void	Animal::makeSound() {
	std::cout << "I'm an animal" << std::endl;
}

std::string	Animal::getType() {
	return this->type;
}
