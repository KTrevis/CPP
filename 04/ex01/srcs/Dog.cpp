#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog : Default Constructor Called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::~Dog() {
	std::cout << "Dog : Destructor Called" << std::endl;
	delete this->brain;
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
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

void	Dog::makeSound() {
	std::cout << "Bark !" << std::endl;
}

void	Dog::displaySomeIdeas() {
	this->brain->displaySomeIdeas();
}
