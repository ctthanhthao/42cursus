/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:31:08 by thchau            #+#    #+#             */
/*   Updated: 2025/10/12 16:20:48 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name);

void separator(std::string title) {
    std::cout << "\n==================== " << title << " ====================\n";
}

std::string to_string(int n) {
    std::ostringstream oss;
    oss << n;
    return oss.str();
}

int main()
{
	// 1️⃣ Basic test - heap allocation
	separator("Basic Horde Test (3 Zombies)");
	Zombie* horde = zombieHorde(3, "Zombies");
	if (horde)
	{
		for (int i = 0; i < 3; i++)
			horde[i].announce();
		delete [] horde;
	}
	// 2️⃣ Edge Case - Empty name
    separator("Edge Case - Empty Name");
    Zombie* emptyNameHorde = zombieHorde(2, "");
    if (emptyNameHorde) {
        for (int i = 0; i < 2; ++i)
            emptyNameHorde[i].announce();
        delete [] emptyNameHorde;
    }
	// 2️⃣ Edge Case - 0 Zombies
	separator("Edge Case - N = 0");
	Zombie* zeroHorde = zombieHorde(0, "Nobody");
	if (!zeroHorde)
        std::cout << "No zombies created (correct behavior)" << std::endl;

	// 3️⃣ Edge Case - Negative Number
	separator("Edge Case - N < 0");
	Zombie* negHorde = zombieHorde(-5, "Invalid");
	if (!negHorde)
		std::cout << "No zombies created (correct behavior)" << std::endl;

	separator("All Tests Completed");

	return (0);
}