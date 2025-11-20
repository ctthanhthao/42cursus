/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:00:53 by thchau            #+#    #+#             */
/*   Updated: 2025/11/20 15:43:24 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "[AMateria] " << this->type 
			  << " created." << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "[AMateria] " << this->type 
			  << " copied." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "[AMateria] " << this->type
			  << " assigned." << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] " << this->type
			  << " destroyed." << std::endl;
}

const std::string &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}