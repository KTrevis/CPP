#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat : Default Constructor Called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::~Cat() {
	std::cout << "Cat : Destructor Called" << std::endl;
	delete this->brain;
}

Cat::Cat(Cat const &obj): Animal(obj) {
std::cout << "Cat : Copy Constructor Called" << std::endl;
if (this != &obj)
	*this = obj;
}

Cat	&Cat::operator= (const Cat &obj) {
	std::cout << "Cat : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

void	Cat::makeSound() {
	std::cout << "Miaou." << std::endl;
}

void	Cat::displaySomeIdeas() {
	this->brain->displaySomeIdeas();
}
