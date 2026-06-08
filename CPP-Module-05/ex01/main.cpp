/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:30:51 by thchau            #+#    #+#             */
/*   Updated: 2026/06/08 09:32:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "===== BASIC SIGN TEST =====" << std::endl;

	Bureaucrat boss("Boss", 1);
	Form formA("Tax Form", 50, 30);
	std::cout << formA << std::endl;
	boss.signForm(formA);
	std::cout << formA << std::endl;
	
	std::cout << "\n===== TOO LOW GRADE TEST =====" << std::endl;
	
	Bureaucrat intern("Intern", 150);
	Form formB("Secret Form", 10, 5);
	std::cout << formB << std::endl;
	intern.signForm(formB);

	std::cout << "\n===== BORDERLINE TEST (EQUAL GRADE) =====" << std::endl;

	Bureaucrat mid("Mid", 42);
	Form formC("Border Form", 42, 100);
	std::cout << formC << std::endl;
	mid.signForm(formC); // should succeed (grade == required)

	std::cout << "\n===== MULTIPLE SIGN ATTEMPT =====" << std::endl;

	Bureaucrat chief("Chief", 1);
	Form formD("Repeat Form", 20, 10);
	chief.signForm(formD);
	chief.signForm(formD); // signing again should still "succeed logically"

	return 0;
}
