/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:30:51 by thchau            #+#    #+#             */
/*   Updated: 2026/06/05 15:27:19 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===== VALID BUREAUCRAT =====" << std::endl;

	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== CONSTRUCTOR TOO HIGH =====" << std::endl;

	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== CONSTRUCTOR TOO LOW =====" << std::endl;

	try
	{
		Bureaucrat c("Charlie", 151);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== INCREMENT OVERFLOW =====" << std::endl;

	try
	{
		Bureaucrat d("David", 1);
		std::cout << d << std::endl;
		d.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== DECREMENT UNDERFLOW =====" << std::endl;

	try
	{
		Bureaucrat e("Eve", 150);
		std::cout << e << std::endl;
		e.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}