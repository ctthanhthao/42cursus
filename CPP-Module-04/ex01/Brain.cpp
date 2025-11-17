/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:40:51 by thchau            #+#    #+#             */
/*   Updated: 2025/11/17 20:15:24 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain created." << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copied." << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assigned." << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destroyed." << std::endl;
}

void Brain::setIdea(unsigned int idx, const std::string &str)
{
	if (idx < 100)
		ideas[idx] = str;
}

std::string Brain::getIdea(unsigned int idx)
{
	if (idx < 100)
		return ideas[idx];
	return "";
}