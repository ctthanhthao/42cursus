/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:54:19 by thchau            #+#    #+#             */
/*   Updated: 2025/11/11 09:57:52 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("uname_clap_name"), ScavTrap(), FragTrap(), _name("uname")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " created." << std::endl;
	std::cout << "[DEBUG] _hitPoints=" << _hitPoints << std::endl;
	std::cout << "[DEBUG] _energyPoints=" << _energyPoints << std::endl;
	std::cout << "[DEBUG] _attackDamage=" << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " created.!" << std::endl;
		std::cout << "[DEBUG] _hitPoints=" << _hitPoints << std::endl;
	std::cout << "[DEBUG] _energyPoints=" << _energyPoints << std::endl;
	std::cout << "[DEBUG] _attackDamage=" << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), 
	ScavTrap(other),
    FragTrap(other),
    _name(other._name)
{
    std::cout << "DiamondTrap " << _name 
              << " copied.!"
              << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        _hitPoints     = other._hitPoints;
        _energyPoints  = other._energyPoints;
        _attackDamage  = other._attackDamage;
    }
    std::cout << "DiamondTrap " << this->_name 
              << " assigned." << std::endl;
		std::cout << "[DEBUG] _hitPoints=" << _hitPoints << std::endl;
	std::cout << "[DEBUG] _energyPoints=" << _energyPoints << std::endl;
	std::cout << "[DEBUG] _attackDamage=" << _attackDamage << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name 
              << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->_name
              << " || ClapTrap name: " << ClapTrap::_name
              << std::endl;
}