/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:15:58 by thchau            #+#    #+#             */
/*   Updated: 2025/10/17 16:57:50 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "===== Basic Constructors =====" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n===== Assignment =====" << std::endl;
    a = Fixed(1234.4321f);
    std::cout << "a = " << a << std::endl;

    std::cout << "\n===== Comparison Operators =====" << std::endl;
    Fixed x(5.05f);
    Fixed y(2);

	std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    std::cout << "\n===== Arithmetic Operators =====" << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    std::cout << "\n===== Increment / Decrement =====" << std::endl;
    Fixed n;
    std::cout << "n = " << n << std::endl;
    std::cout << "++n = " << ++n << std::endl;
    std::cout << "n++ = " << n++ << std::endl;
    std::cout << "n after n++ = " << n << std::endl;
    std::cout << "--n = " << --n << std::endl;
    std::cout << "n-- = " << n-- << std::endl;
    std::cout << "n after n-- = " << n << std::endl;

    std::cout << "\n===== min / max =====" << std::endl;
    Fixed a1(10.5f);
    Fixed a2(10.6f);

	std::cout << "a1 = " << a1 << std::endl;
    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "min(a1, a2): " << Fixed::min(a1, a2) << std::endl;
    std::cout << "max(a1, a2): " << Fixed::max(a1, a2) << std::endl;

    const Fixed ca1(7.7f);
    const Fixed ca2(7.8f);
	std::cout << "ca1 = " << ca1 << std::endl;
    std::cout << "ca2 = " << ca2 << std::endl;
    std::cout << "const min(ca1, ca2): " << Fixed::min(ca1, ca2) << std::endl;
    std::cout << "const max(ca1, ca2): " << Fixed::max(ca1, ca2) << std::endl;

    std::cout << "\n===== Edge Cases =====" << std::endl;

    // Division by zero
    Fixed zero(0);
    Fixed nonzero(5);
    std::cout << "nonzero / zero = " << (nonzero / zero) << std::endl;
    std::cout << "zero / nonzero = " << (zero / nonzero) << std::endl;

    // Very large numbers
    Fixed large1(838860); // near 2^23, maximum safe integer with 8 fractional bits
    Fixed large2(2);
	std::cout << "large1 = " << large1 << std::endl;
    std::cout << "large2 = " << large2 << std::endl;
    std::cout << "large1 + large2 = " << (large1 + large2) << std::endl;
    std::cout << "large1 * large2 = " << (large1 * large2) << std::endl;

    // Very small numbers
    Fixed small1(0.00390625f); // 1/256
    std::cout << "small1 = " << small1 << std::endl;
    std::cout << "small1 / 2 = " << (small1 / Fixed(2)) << std::endl;

    // Precision test
    Fixed f1(1.5f);
    Fixed f2(1.25f);
	std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;
    Fixed result = f1 * f2;
    std::cout << "1.5 * 1.25 = " << result << std::endl;

    std::cout << "\n===== Chain Operations =====" << std::endl;
    Fixed res = (Fixed(2.5f) + Fixed(1.25f)) * Fixed(3) / Fixed(2);
    std::cout << "(2.5 + 1.25) * 3 / 2 = " << res << std::endl;

    std::cout << "\n===== End of Tests =====" << std::endl;
	return 0;
}