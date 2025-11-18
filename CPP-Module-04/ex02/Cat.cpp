/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:53:07 by thchau            #+#    #+#             */
/*   Updated: 2025/11/17 20:21:11 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	brain = new Brain();
	std::cout << this->_type << " created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->brain = new Brain(*other.brain); // deep copy
	std::cout << this->_type << " copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*this->brain = *other.brain; // deep copy
	}
	std::cout << this->_type << " assigned." << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << this->_type << " destroyed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱 Meow~" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}
