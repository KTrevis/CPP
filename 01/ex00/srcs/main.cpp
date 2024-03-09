#include "utils.hpp"

int	main() {
	Zombie	*zombie = newZombie("heap");
	zombie->announce();
	randomChump("stack");
	delete zombie;
}
