/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:42:11 by thchau            #+#    #+#             */
/*   Updated: 2025/11/17 20:21:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	brain = new Brain();
	std::cout << this->_type << " created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << this->_type << " copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*brain = *other.brain;
	}
	std::cout << this->_type << " assigned." << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << this->_type << " destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶 Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain;
}
