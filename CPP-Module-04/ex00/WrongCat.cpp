/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:12:10 by thchau            #+#    #+#             */
/*   Updated: 2025/11/13 15:14:07 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << this->_type << " created." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << this->_type << " copied." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << this->_type << " assigned." << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << this->_type << " destroyed." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "🙀 Wrong meow?" << std::endl;
}
