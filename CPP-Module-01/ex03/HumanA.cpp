/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 08:09:09 by thchau            #+#    #+#             */
/*   Updated: 2025/10/13 09:01:05 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) 
	: name(name), weapon(weapon) {}

void HumanA::attack()
{
	std::cout << this->name
			  << " attacks with their "
			  << this->weapon.getType()
			  << std::endl;
}