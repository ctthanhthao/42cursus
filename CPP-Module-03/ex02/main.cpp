/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:16:52 by thchau            #+#    #+#             */
/*   Updated: 2025/11/07 11:46:19 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== ClapTrap tests ===" << std::endl;
    ClapTrap clap("CL4P-TP");
    clap.attack("target dummy");
    clap.takeDamage(10);
    clap.beRepaired(5);

    std::cout << "\n=== ScavTrap tests ===" << std::endl;
    ScavTrap scav("SC4V-TP");
    scav.attack("training dummy");
    scav.takeDamage(40);
    scav.beRepaired(15);
    scav.guardGate();

    std::cout << "\n=== FragTrap tests ===" << std::endl;
    FragTrap frag("FR4G-TP1");
    frag.attack("sparring partner");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();

	FragTrap frag2("FR4G-TP2");
	FragTrap frag3("FR4G-TP3");
	frag2 = frag3 = frag;
	frag2.attack("Frag2 enemy");
	frag2.takeDamage(80);
	std::cout << "memory of frag " << &frag << std::endl;
	std::cout << "memory of frag2 " << &frag2 << std::endl;
	std::cout << "memory of frag3 " << &frag3 << std::endl;
    return 0;
}
