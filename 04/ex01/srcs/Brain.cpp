#include "Brain.hpp"
#include <cstdlib>

Brain::Brain() {
	std::cout << "Brain : Default Constructor Called" << std::endl;
	std::string	randomIdeas[] = {
		"That's a great idea!",
		"Sounds like a good idea",
		"Definitely a bad idea",
	};

	for (int i = 0; i < 100; i++)
		this->ideas[i] = randomIdeas[std::rand() % 3];
}

Brain::~Brain() {
	std::cout << "Brain : Destructor Called" << std::endl;
}

Brain::Brain(Brain const &obj) {
	std::cout << "Brain : Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Brain	&Brain::operator= (const Brain &obj) {
	std::cout << "Brain : Copy Assignment Operator Called" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return *this;
}

void	Brain::displaySomeIdeas() {
	for (int i = 0; i < 5; i++)
		std::cout << this->ideas[i] << std::endl;
}
