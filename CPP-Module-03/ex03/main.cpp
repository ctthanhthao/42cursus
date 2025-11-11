/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:16:52 by thchau            #+#    #+#             */
/*   Updated: 2025/11/11 10:08:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    
	std::cout << "=== Default constructor ===" << std::endl;
    DiamondTrap dt1;                 // Default constructor
    dt1.whoAmI();

    std::cout << "\n=== Parameterized constructor ===" << std::endl;
    DiamondTrap dt2("DIAMOND-TP2");  // Parameterized constructor
    dt2.whoAmI();

    std::cout << "\n=== Copy constructor ===" << std::endl;
    DiamondTrap dt3(dt2);            // Copy constructor
    dt3.whoAmI();

    std::cout << "\n=== Assignment operator ===" << std::endl;
    DiamondTrap dt4;
    dt4 = dt2;                       // Copy assignment
    dt4.whoAmI();
	
	std::cout << "\n=== member functions ===" << std::endl;
	dt2.attack("DIAMOND-TP2 enemy");
	dt2.takeDamage(20);
	dt4.attack("DIAMOND-TP4 enemy");
	dt4.takeDamage(20);
	dt4.highFivesGuys();
	dt4.guardGate();

	std::cout << "\n=== check energy points ===" << std::endl;
	for (int i = 0; i < 49; i++)
	{
		dt4.beRepaired(10);
	}
	dt4.attack("DIAMOND-TP4 enemy again.");
	
    std::cout << "\n=== Destruction ===" << std::endl;
    // All objects go out of scope here, destructors called automatically
    return 0;
}
