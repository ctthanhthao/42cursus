/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:52:26 by thchau            #+#    #+#             */
/*   Updated: 2026/06/25 10:03:44 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Template.hpp"

int main ()
{
	int a = 10;
	int b = 11;
	
	std::cout << "/====== TEST SWAP - INTEGER======/" << std::endl;
	std::cout << "BEFORE: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "AFTER: a = " << a << ", b = " << b << std::endl;
	
	std::cout << "/====== TEST MIN MAX - INTEGER======/" << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
    std::cout << "max(a, b) = " << max(a, b) << std::endl;

	std::cout << "/====== TEST SWAP - STRING======/" << std::endl;
	std::string c = "Hello";
    std::string d = "Ahoj";
	std::cout << "BEFORE: c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "AFTER: c = " << c << ", d = " << d << std::endl;
	std::cout << "/====== TEST MIN MAX - STRING======/" << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	return (0);
}