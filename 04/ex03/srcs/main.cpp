#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	equipAndUseTest() {
	ICharacter	*player = new Character("player");
	ICharacter	*enemy = new Character("enemy");

	std::cout << std::endl << "EMPTY INVENTORY TEST" << std::endl;
	player->use(0, *enemy);

	std::cout << std::endl << "NON EMPTY INVENTORY TEST" << std::endl;
	player->equip(new Ice);
	player->equip(new Cure);
	player->use(0, *enemy);

	std::cout << std::endl << "FULL INVENTORY TEST" << std::endl;
	player->equip(new Ice);
	player->equip(new Cure);
	player->use(0, *enemy);
	player->use(1, *enemy);
	player->use(2, *enemy);
	player->use(3, *enemy);
	player->use(4, *enemy);

	AMateria	*ice = new Ice;
	player->equip(ice);
	player->use(1, *enemy);
	player->unequip(1);
	player->equip(ice);
	player->use(1, *enemy);

	delete ice;
	delete player;
	delete enemy;
}

void	copyTest() {
	std::cout << std::endl << "COPY TEST" << std::endl;
	ICharacter	*player = new Character("player");
	ICharacter	*enemy = new Character("enemy");

	std::cout << "ADDING RANDOM SPELLS IN PLAYER INVENTORY" << std::endl;
	for (int i = 0; i < CHARACTER_MAX_MATERIAS; i++) {
		if (i % 2)
			player->equip(new Ice);
		else
			player->equip(new Cure);
		player->use(i, *enemy);
	}

	std::cout << std::endl << "COPYING EVERYTHING INTO ENEMY INVENTORY" << std::endl;
	*enemy = *player;
	delete player;
	for (int i = 0; i < CHARACTER_MAX_MATERIAS; i++)
		enemy->use(i, *player);
	delete enemy;
}

void	materiaSourceTest() {}

int	main() {
	/* equipAndUseTest(); */
	copyTest();
	/* materiaSourceTest(); */
}
