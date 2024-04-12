#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat : Default Constructor Called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat() {
std::cout << "Cat : Destructor Called" << std::endl;
}

Cat::Cat(Cat const &obj) {
std::cout << "Cat : Copy Constructor Called" << std::endl;
if (this != &obj)
	*this = obj;
}

Cat	&Cat::operator= (const Cat &obj) {
	std::cout << "Cat : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	return (*this);
}

void	Cat::makeSound() {
	std::cout << "Miaou." << std::endl;
}
