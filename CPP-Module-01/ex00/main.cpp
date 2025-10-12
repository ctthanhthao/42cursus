/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:31:08 by thchau            #+#    #+#             */
/*   Updated: 2025/10/12 15:50:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

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
    separator("Heap Allocation - Basic");
    Zombie* heapZombie = newZombie("Heapster");
    heapZombie->announce();
    delete heapZombie; // Destructor should print message

    // 2️⃣ Basic test - stack allocation
    separator("Stack Allocation - Basic");
    randomChump("Stacky");

    // 3️⃣ Edge case - empty name
    separator("Edge Case - Empty Name");
    Zombie* noName = newZombie("");
    noName->announce();  // Should handle gracefully
    delete noName;

    // 4️⃣ Edge case - name with spaces
    separator("Edge Case - Name With Spaces");
    Zombie* spacedName = newZombie("Zombie With Spaces");
    spacedName->announce();
    delete spacedName;

    // 5️⃣ Edge case - very long name
    separator("Edge Case - Very Long Name");
    std::string longName(100, 'Z');
    Zombie* longZombie = newZombie(longName);
    longZombie->announce();
    delete longZombie;

    // 6️⃣ Stress test - multiple zombies on the heap
    separator("Stress Test - Multiple Heap Zombies");
    Zombie* horde[5];
    for (int i = 0; i < 5; ++i) {
        horde[i] = newZombie("HeapZombie_" + to_string(i));
        horde[i]->announce();
    }
    for (int i = 0; i < 5; ++i) {
        delete horde[i];
    }

    // 7️⃣ Stress test - multiple zombies on the stack
    separator("Stress Test - Multiple Stack Zombies");
    for (int i = 0; i < 5; ++i) {
        randomChump("StackZombie_" + to_string(i));
    }

    // 8️⃣ Unicode / special characters in name
    separator("Edge Case - Unicode / Special Characters");
    Zombie* special = newZombie("💀_Zömbïe_#42");
    special->announce();
    delete special;

    // 9️⃣ Verify destructor is called automatically for stack objects
    separator("Destructor Verification (Stack)");
    {
        Zombie tempZombie("Temporary");
        tempZombie.announce();
    } // Destructor called here automatically

    // 🔟 End of tests
    separator("All Tests Completed");

	return (0);
}