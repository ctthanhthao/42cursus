/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:52:26 by thchau            #+#    #+#             */
/*   Updated: 2026/06/26 11:25:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main ()
{
	std::vector<int> vec;
	
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::cout << "======== FIND INTEGER IN VECTOR ========" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found: " << *it << std::endl;
		std::cout << "--- Should throw exception ---" << std::endl;
		easyfind(vec, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "======== FIND INTEGER IN LIST ========" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	
	try
	{
		std::list<int>::iterator itl = easyfind(lst, 30);
		std::cout << "Found: " << *itl << std::endl;
		std::cout << "--- Should throw exception ---" << std::endl;
		easyfind(lst, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}