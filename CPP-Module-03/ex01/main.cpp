/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:16:52 by thchau            #+#    #+#             */
/*   Updated: 2025/11/06 19:59:42 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Foo("Foo");
	Foo.attack("Bar");
	Foo.attack("Cho");
	Foo.takeDamage(80);

	// copy Foo
	ScavTrap FooChild("FooChild");
	FooChild.attack("BarChild");
	FooChild.guardGate();
	
	FooChild = Foo;
	FooChild.takeDamage(10);
	std::cout << "Finish assigned and start copying." << std::endl;
	ScavTrap assign(Foo);
	assign.attack("AssignTest");
	assign.takeDamage(50);
	return 0;
}