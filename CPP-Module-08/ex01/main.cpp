/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 20:08:35 by thchau            #+#    #+#             */
/*   Updated: 2026/06/26 20:09:03 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"

int main()
{
	std::cout << "====== HAPPY CASE =======" << std::endl;
    Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	std::cout << "====== NEGATIVE CASE =======" << std::endl;
	std::cout << "--- Expect exception: Span is full---" << std::endl;
	try
	{
		sp.addNumber(18);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	Span sp3(0);
	try
	{
		sp3.addNumber(42);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp1(1);
	try
	{
		sp1.addNumber(23);
		std::cout << "--- Expect exception: Not enough numbers---" << std::endl;
		sp1.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span sp2(1);
	try
	{
		sp2.addNumber(23);
		std::cout << "--- Expect exception: Not enough numbers---" << std::endl;
		sp2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span sp4(3);
	std::cout << "--- Expect exception: Too many numbers---" << std::endl;
	try
	{
		std::vector<int> v;
		v.push_back(4);
		v.push_back(7);
		v.push_back(11);
		v.push_back(34);
		sp3.addRange(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n===== SUBJECT STRESS TEST =====" << std::endl;
	std::vector<int> v;

	for (int i = 0; i < 10000; ++i)
		v.push_back(std::rand());

	Span sp6(10000);

	sp6.addRange(v.begin(), v.end());

	std::cout << "Size: 10000" << std::endl;
	std::cout << "Shortest span: "
			<< sp6.shortestSpan()
			<< std::endl;
	std::cout << "Longest span: "
			<< sp6.longestSpan()
			<< std::endl;

    return 0;
}