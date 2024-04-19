#include "Dog.hpp"
#include "Cat.hpp"

static void	testCopy() {
	Animal	*dog1 = new Dog;
	Animal	*dog2 = new Dog;

	std::cout << std::endl << "IDEAS BEFORE COPY" << std::endl;
	std::cout << std::endl << "DOG 1 IDEAS" << std::endl;
	dog1->displaySomeIdeas();
	std::cout << std::endl << "DOG 2 IDEAS" << std::endl;
	dog2->displaySomeIdeas();
	*dog1 = *dog2;
	std::cout << std::endl << "IDEAS AFTER COPY" << std::endl;
	std::cout << std::endl << "DOG 1 IDEAS" << std::endl;
	dog1->displaySomeIdeas();
	delete dog1;
	std::cout << std::endl << "DOG 2 IDEAS" << std::endl;
	dog2->displaySomeIdeas();
	delete dog2;
}

int	main() {
	int quantity;

	std::cout << "Enter numbers of animals wished : ";
	std::cin >> quantity;
	if (quantity <= 0) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	Animal	*animals[quantity];
	for (int i = 0; i < quantity; i++) {
		if (i % 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}

	std::cout << std::endl;
	for (int i = 0; i < quantity; i++)
		animals[i]->makeSound();
	std::cout << std::endl;

	for (int i = 0; i < quantity; i++)
		delete animals[i];

	testCopy();
}
