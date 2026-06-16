/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 10:40:59 by thchau            #+#    #+#             */
/*   Updated: 2026/06/16 13:07:45 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

static bool isPseudo(const std::string &s)
{
	return (s == "nan" || s == "nanf" ||
			s == "-inf" || s == "+inf" ||
			s == "-inff" || s == "+inff");
}

static void printChar(double v)
{
	if (std::isnan(v) || v < 0 || v > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(v)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(v) << "'" << std::endl;
}

static void printInt(double v)
{
	if (std::isnan(v) || 
		v > std::numeric_limits<int>::max() ||
		v < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(v) << std::endl;
}

static void printFloat(double v)
{
	float f = static_cast<float>(v);
	if(std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << ((f < 0) ? "-inff" : "+inff") << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

static void printDouble(double v)
{
	if(std::isnan(v))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(v))
		std::cout << "double: " << ((v < 0) ? "-inf" : "+inf") << std::endl;
	else
		std::cout << "double: " << v << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	std::cout << std::fixed << std::setprecision(1);
	if(isPseudo(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal[0] == '-')
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		else if (literal[0] == '+')
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		return;
	}
	double val = 0;
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
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
	if (end && *end && !(*end =='f' && *(end + 1) == '\0'))
	{
		std::cout << "Invalid input." << std::endl;
		return;
	}
	printChar(val);
	printInt(val);
	printFloat(val);
	printDouble(val);
}