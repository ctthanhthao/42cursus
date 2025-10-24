/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:16:52 by thchau            #+#    #+#             */
/*   Updated: 2025/10/24 13:12:02 by thchau           ###   ########.fr       */
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
	ClapTrap FooChild = Foo;
	FooChild.attack("BarChild");
	return 0;
}