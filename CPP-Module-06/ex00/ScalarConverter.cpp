/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:40:59 by thchau            #+#    #+#             */
/*   Updated: 2026/06/17 13:29:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utility.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	(void)source;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << std::fixed << std::setprecision(1);
	if(isPseudo(literal))
	{
		printPseudo(literal);
		return;
	}
	double val = 0;
	if (isChar(literal))
	{
		val = static_cast<double>(literal[1]);
		printChar(val);
		printInt(val);
		printFloat(val);
		printDouble(val);
		return;
	}
	char *end = NULL;
	val = strtod(literal.c_str(), &end);
	if (!isDecimalNumber(literal.c_str()) ||
		(end && *end && !(*end =='f' && *(end + 1) == '\0')))
	{
		std::cout << "Invalid input." << std::endl;
		return;
	}
	printChar(val);
	printInt(val);
	printFloat(val);
	printDouble(val);
}