/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:05:35 by thchau            #+#    #+#             */
/*   Updated: 2025/10/12 16:04:12 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#pragma once
#include <iostream>
#include <string>
class Zombie
{
private:
	std::string _name;

public:
	Zombie( void );
	Zombie( std::string n );
	~Zombie( void );
	
	void announce( void );
	void setName(std::string name);
};

#endif