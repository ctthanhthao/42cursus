/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:13:57 by thchau            #+#    #+#             */
/*   Updated: 2025/11/20 15:43:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "[Ice] " << this->type 
			  << " created." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "[Ice] " << this->type 
			  << " copied." << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[Ice] " << this->type
			  << " assigned." << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << "[Ice] " << this->type
			  << " destroyed." << std::endl;
}

AMateria *Ice::clone() const
{
	std::cout << "[Ice] " << this->type << " cloned." << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "[Ice] * shoots an ice bolt at " 
			  << target.getName() << " *" << std::endl;
}
