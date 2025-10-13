/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 08:09:22 by thchau            #+#    #+#             */
/*   Updated: 2025/10/13 09:11:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): name(name){};

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (this->weapon)
	{
		std::cout << this->name
			  << " attacks with their "
			  << this->weapon->getType()
			  << std::endl;
	}
	else
	{
		std::cout << this->name
			  << " attacks with no weapon"
			  << std::endl;
	}
}