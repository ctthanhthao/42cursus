/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:35:54 by thchau            #+#    #+#             */
/*   Updated: 2026/06/24 19:52:03 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void)
{
	int r = std::rand() % 3;

	if (r == 0)
		return (new A);
	if (r == 1)
		return (new B);
	return (new C);
}

void identify(Base *p)
{
	std::cout << "The actual type of the object pointed to by p: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	std::cout << "The actual type of the object referenced by p: ";
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...) {}
	
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(...) {}

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(...) {}
}