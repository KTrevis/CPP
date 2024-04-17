#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	wrongAnimalTest() {
	std::cout << "WRONG ANIMALS" << std::endl << std::endl;

	WrongAnimal	*wrongAnimal = new WrongAnimal;
	WrongAnimal	*wrongCat = new WrongCat;

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;
}

void	correctionAnimals() {
	std::cout << std::endl << "CORRECT ANIMALS" << std::endl << std::endl;

	Animal	*animal = new Animal;
	Animal	*cat = new Cat;
	Animal	*dog = new Dog;

	std::cout << "Animal type: " << animal->getType() << std::endl;
	animal->makeSound();
	std::cout << "Cat type: " << cat->getType() << std::endl;
	cat->makeSound();
	std::cout << "Dog type: " << dog->getType() << std::endl;
	dog->makeSound();

	delete animal;
	delete cat;
	delete dog;
}

int	main() {
	wrongAnimalTest();
	correctionAnimals();
}
