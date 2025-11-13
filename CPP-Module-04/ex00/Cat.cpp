/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:53:07 by thchau            #+#    #+#             */
/*   Updated: 2025/11/12 14:54:08 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << this->_type << " created." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << this->_type << " copied." << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " assigned." << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << this->_type << " destroyed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱 Meow~" << std::endl;
}
