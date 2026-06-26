#include <iostream>
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

    return 0;
}