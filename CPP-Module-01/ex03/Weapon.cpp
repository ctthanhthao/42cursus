/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 08:09:33 by thchau            #+#    #+#             */
/*   Updated: 2025/10/13 09:03:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){};
Weapon::Weapon(const std::string &type): type(type){};

void Weapon::setType(const std::string &type)
{
	this->type = type;
}

std::string Weapon::getType()
{
	return this->type;
}