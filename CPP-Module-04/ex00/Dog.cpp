/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:42:11 by thchau            #+#    #+#             */
/*   Updated: 2025/11/12 14:52:53 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << this->_type << " created." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << this->_type << " copied." << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " assigned." << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << this->_type << " destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶 Woof! Woof!" << std::endl;
}
