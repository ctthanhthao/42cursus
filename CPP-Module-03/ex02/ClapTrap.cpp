/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:16:44 by thchau            #+#    #+#             */
/*   Updated: 2025/11/10 19:24:38 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("unname"), _hitPoints(10),
		_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
};

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10),
		_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
};
					
ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name),
		_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
		_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << other._name << " copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " is assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name 
				  << " cannot attack, it has no hit points left."
				  << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
				  << " has no energy to attack."
				  << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage."
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitPoints)
	{
		std::cout << "ClapTrap " << _name << " takes only "
				  << _hitPoints << " points of damage. Remaining hit points: 0"
				  << std::endl;
		_hitPoints = 0;
		return;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes "
			  << amount << " points of damage. Remaining hit points: "
			  << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself because "
				  << "there is no hit points left." << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " cannot repair itself because "
				  << "there is no energy points left." << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " repaired itself, recovering "
			  << amount << " hit points! Current hit points: "
			  << _hitPoints << std::endl;
}

