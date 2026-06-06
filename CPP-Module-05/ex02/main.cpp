/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:30:51 by thchau            #+#    #+#             */
/*   Updated: 2026/06/06 20:35:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(time(NULL));

	std::cout << "===== BASIC SIGN + EXECUTE TEST =====" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur");

		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n===== UNSIGNED EXECUTION TEST =====" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("fail_test");

		// NOT SIGNED ON PURPOSE
		boss.executeForm(shrub); // should fail
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n===== LOW GRADE SIGN TEST =====" << std::endl;

	try
	{
		Bureaucrat intern("Intern", 150);
		RobotomyRequestForm robot("Bender");

		intern.signForm(robot); // should fail
		intern.executeForm(robot); // should fail
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n===== EXECUTION WITHOUT ENOUGH GRADE =====" << std::endl;

	try
	{
		Bureaucrat mid("Mid", 50);
		PresidentialPardonForm pardon("Arthur");

		mid.signForm(pardon);     // may fail depending on grade
		mid.executeForm(pardon);  // likely fail
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n===== ROBOTOMY RANDOMNESS TEST =====" << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("RandomBot");

		boss.signForm(robot);

		for (int i = 0; i < 5; i++)
		{
			boss.executeForm(robot);
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n===== END TESTS =====" << std::endl;

	return 0;
}
