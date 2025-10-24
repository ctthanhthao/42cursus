/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:16:52 by thchau            #+#    #+#             */
/*   Updated: 2025/10/24 13:25:35 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Foo("Foo");
	Foo.attack("Bar");
	Foo.attack("Cho");
	Foo.takeDamage(5);
	Foo.beRepaired(6);
	Foo.takeDamage(15);
	Foo.beRepaired(2);

	// copy Foo
	ClapTrap FooCopy(Foo);
	FooCopy.attack("BarChild");
	// assign Foo
	ClapTrap FooAssign("FooAssign");
	FooAssign = Foo;
	FooAssign.attack("BarChild");
	return 0;
}