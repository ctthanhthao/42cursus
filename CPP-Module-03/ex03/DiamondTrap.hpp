/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:59:40 by thchau            #+#    #+#             */
/*   Updated: 2025/11/11 09:39:53 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	DiamondTrap();
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();
	
	using ScavTrap::attack;
	void whoAmI();
};

#endif