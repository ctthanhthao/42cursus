/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:24:40 by thchau            #+#    #+#             */
/*   Updated: 2025/11/20 15:43:42 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "[Cure] " << this->type 
			  << " created." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "[Cure] " << this->type 
			  << " copied." << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[Cure] " << this->type
			  << " assigned." << std::endl;
	return *this;
}

Cure::~Cure()
{
	std::cout << "[Cure] " << this->type
			  << " destroyed." << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << "[Cure] " << this->type << " cloned." << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "[Cure] * heals " << target.getName() 
			  << "'s wounds *" << std::endl;
}
