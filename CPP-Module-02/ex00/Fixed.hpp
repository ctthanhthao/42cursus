/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:15:55 by thchau            #+#    #+#             */
/*   Updated: 2025/10/17 11:52:41 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();					// Default constructor
	Fixed(const Fixed &other);	// Copy constructor
	Fixed &operator=(const Fixed &other);	// Copy assignment operator
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif