#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// References cannot be NULL, so Human A uses a reference because he always has a weapon
// Human uses a pointer because he doesn't always has one
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
