#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog : Default Constructor Called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog : Destructor Called" << std::endl;
}

Dog::Dog(Dog const &obj): Animal(obj) {
	std::cout << "Dog : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Dog	&Dog::operator=(const Dog &obj) {
	std::cout << "Dog : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	return (*this);
}

void	Dog::makeSound() const { 
	std::cout << "Bark !" << std::endl;
}
