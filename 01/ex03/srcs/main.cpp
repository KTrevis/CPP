/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:54:58 by ketrevis          #+#    #+#             */
/*   Updated: 2024/03/15 14:17:38 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// References cannot be NULL, so Human A uses a reference because he always has a weapon
// Human B uses a pointer because he doesn't always has one
int main()
{
	Weapon weapon("sword");
	HumanA michel("michel", weapon);
	HumanB jean("jean");

	jean.attack();
	michel.attack();

	weapon.setType("dagger");
	jean.setWeapon(weapon);

	jean.attack();
	michel.attack();
	return 0;
}
