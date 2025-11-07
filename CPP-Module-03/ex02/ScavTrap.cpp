/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:29:29 by thchau            #+#    #+#             */
/*   Updated: 2025/11/06 20:01:28 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attachDamage = 20;
	std::cout << "ScavTrap " << _name << " created." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attachDamage = 20;
    std::cout << "ScavTrap " << _name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Scavtrap " << _name << " copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << _name << " is assigned." << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name 
				  << " cannot attack, it has no hit points left."
				  << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name
				  << " has no energy to attack."
				  << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attachDamage << " points of damage."
			  << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name 
			  << " is now in Gate keeper mode."
			  << std::endl;
}
