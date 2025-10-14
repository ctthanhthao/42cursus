/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:56:16 by thchau            #+#    #+#             */
/*   Updated: 2025/10/14 10:05:05 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::levelNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(){};

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years, whereas you started working ";
	std::cout << "here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}

Harl::Level Harl::getLevel(const std::string &level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == levelNames[i])
			return static_cast<Level>(i);
	}
	return INVALID;
}

void Harl::complain(std::string level)
{
	Level lv = getLevel(level);
	// Array of pointers to member functions
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
	
	switch(lv)
	{
		case DEBUG:
		case INFO:
		case WARNING:
		case ERROR:
			for (int i = lv; i < 4; i++)
				(this->*functions[i])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
			  		  << std::endl;
	}
}