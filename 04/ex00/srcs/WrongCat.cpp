#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat : Default Constructor Called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat : Destructor Called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &obj) {
	std::cout << "WrongCat : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongCat	&WrongCat::operator= (const WrongCat &obj) {
	std::cout << "WrongCat : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	return *this;
}


void	WrongCat::makeSound() {
	std::cout << "Wrong miaou" << std::endl;
}
