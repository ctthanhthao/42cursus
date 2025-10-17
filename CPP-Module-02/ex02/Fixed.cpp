/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:16:02 by thchau            #+#    #+#             */
/*   Updated: 2025/10/17 16:58:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
//	std::cout << "Int constructor called" << std::endl;
	_value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
//	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return *this;
}

// Destructor
Fixed::~Fixed()
{
//	std::cout << "Destructor called " << *this << std::endl;
}

int Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}
	
Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}
	
Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}
	
Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
	
Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.toFloat() == 0.0f)
	{
		std::cout << "Error: Division by zero!" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}
	
Fixed &Fixed::operator++()
{
	++_value;
	return *this;
}
	
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_value;
	return tmp;
}
	
Fixed &Fixed::operator--()
{
	--_value;
	return *this;
}
	
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--_value;
	return tmp;
}
	
Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return num2;
	return num1;
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return num2;
	return num1;
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
