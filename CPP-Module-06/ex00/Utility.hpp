/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 13:25:10 by thchau            #+#    #+#             */
/*   Updated: 2026/06/17 13:28:27 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cmath>
# include <iostream>
# include <limits>
# include <iomanip>

static bool isPseudo(const std::string &s)
{
	return (s == "nan" || s == "nanf" ||
			s == "-inf" || s == "+inf" ||
			s == "-inff" || s == "+inff");
}

bool isChar(const std::string &s)
{
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
	{
		return true;
	}
	return false;
}

bool isDecimalNumber(const std::string& s)
{
    bool hasDot = false;
    bool hasDigit = false;
    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (; i < s.length(); i++)
    {
        if (std::isdigit(s[i]))
            hasDigit = true;
        else if (s[i] == '.' && !hasDot)
            hasDot = true;
        else if (s[i] == 'f' && i == s.length() - 1)
            return hasDigit;
        else
            return false;
    }
    return hasDigit;
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

static void printPseudo(const std::string &s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (s[0] == '-')
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (s[0] == '+')
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}