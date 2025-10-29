/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:16:52 by thchau            #+#    #+#             */
/*   Updated: 2025/10/29 12:45:39 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Foo("Foo");
	Foo.attack("Bar");
	Foo.attack("Cho");

	// copy Foo
	ScavTrap FooChild = Foo;
	FooChild.attack("BarChild");
	FooChild.guardGate();
	return 0;
}