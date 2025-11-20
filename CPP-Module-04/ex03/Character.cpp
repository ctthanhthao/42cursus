/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:20:41 by thchau            #+#    #+#             */
/*   Updated: 2025/11/20 15:38:32 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name): _name(name), _floorCount(0)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
	for (int i = 0; i < 100; i++)
		_floor[i] = 0;
	std::cout << "[Character] " << _name << " created." << std::endl;
}

Character::Character(const Character &other): _name(other._name),
	_floorCount(other._floorCount)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
	for (int i = 0; i < 100; i++)
		_floor[i] = 0;
	std::cout << "[Character] " << _name << " copied." << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++) // clear existing inventories
		{
			if (_inventory[i])
			{	
				delete _inventory[i];
				_inventory[i] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if(other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
		for (int i = 0; i < _floorCount; i++) // clear existing floor
		{
			delete _floor[i];
			_floor[i] = 0;	
		}
		_floorCount = 0;
		for (int i = 0; i < 100; i++)
			_floor[i] = 0;
	}
	std::cout << "[Character] " << _name << " assigned." << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
		
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i])
			delete _floor[i];
	}
	std::cout << "[Character] " << _name << " destroyed." << std::endl;
}
	
std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == 0)
		{	
			_inventory[i] = m;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx] == 0)
		return;
	if (_floorCount < 100)
		_floor[_floorCount++] = _inventory[idx];
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (_inventory[idx] == 0)
		return;
	_inventory[idx]->use(target);
}