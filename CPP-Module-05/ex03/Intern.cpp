/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:40:10 by thchau            #+#    #+#             */
/*   Updated: 2026/06/08 11:19:37 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &source)
{
	(void)source;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
    return *this;
}	

Intern::~Intern(){}

AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);	
}

AForm *createPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	static const std::string names[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(*creator[3])(const std::string &) =
	{
		createShrubbery,
		createRobotomy,
		createPardon
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			return creator[i](target);
		}
	}
	std::cout << "Intern couldn't create " << formName << std::endl;
	return (NULL);
}
