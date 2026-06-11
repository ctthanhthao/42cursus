/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:30:51 by thchau            #+#    #+#             */
/*   Updated: 2026/06/10 11:40:14 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "===== INTERN CREATION TEST =====" << std::endl;

	Intern someRandomIntern;

	AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm *f2 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	AForm *f4 = someRandomIntern.makeForm("unknown form", "test");

	std::cout << "\n===== CHECK POINTERS =====" << std::endl;

	if (f1) std::cout << *f1 << std::endl;
	if (f2) std::cout << *f2 << std::endl;
	if (f3) std::cout << *f3 << std::endl;
	if (f4) std::cout << *f4 << std::endl;

	std::cout << "\n===== SIGN + EXECUTE TEST =====" << std::endl;

	Bureaucrat boss("Boss", 1);

	if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
	}

	if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);
	}

	if (f3)
	{
		boss.signForm(*f3);
		boss.executeForm(*f3);
	}

	std::cout << "\n===== LOW GRADE TEST =====" << std::endl;

	Bureaucrat intern("Intern", 146);

	if (f1)
	{
		intern.signForm(*f1);
		intern.executeForm(*f1);
	}

	std::cout << "\n===== CLEANUP =====" << std::endl;

	delete f1;
	delete f2;
	delete f3;
	delete f4;

	return 0;
}
