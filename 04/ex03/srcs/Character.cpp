#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

Character::Character(std::string name): ICharacter() {
	for (int i = 0; i < CHARACTER_MAX_MATERIAS; i++)
		this->materias[i] = NULL;
	this->name = name;
}

Character::Character(): ICharacter() {
	for (int i = 0; i < CHARACTER_MAX_MATERIAS; i++)
		this->materias[i] = NULL;
}

Character::~Character() {
	for (int i = 0; i < CHARACTER_MAX_MATERIAS; i++)
		delete this->materias[i];
}

Character::Character(Character const &obj): ICharacter(obj) {
	if (this != &obj)
		*this = obj;
}

Character	&Character::operator= (const Character &obj) {
	if (this == &obj)
		return *this;
	for (int i = 0; i < CHARACTER_MAX_MATERIAS; i++) {
		delete this->materias[i];
		if (obj.materias[i]) {
			this->materias[i] = obj.materias[i]->clone();
		}
		else
			this->materias[i] = NULL;
	}
	return *this;
}

void	Character::equip(AMateria *materia) {
	for (int i = 0; i < CHARACTER_MAX_MATERIAS; i++) {
		if (this->materias[i] == NULL) {
			this->materias[i] = materia;
			return ;
		}
	}
	std::cout << "Failed to equip materia " << materia->getType() << std::endl;
}

void	Character::unequip(int index) {
	if (index < 0 || index >= CHARACTER_MAX_MATERIAS)
		this->materias[index] = NULL;
}

void	Character::use(int index, ICharacter &target) {
	if (index < 0 || index >= CHARACTER_MAX_MATERIAS || this->materias[index] == NULL) {
		std::cerr << this->getName() << " has no Materia in slot " << index << std::endl;
		return ;
	}
	this->materias[index]->use(target);
}

std::string	const &Character::getName() const {
	return this->name;
}
