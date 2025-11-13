/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:46 by thchau            #+#    #+#             */
/*   Updated: 2025/11/13 15:24:34 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n=== Normal Animal Tests ===\n" << std::endl;
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound! 
	j->makeSound();
    meta->makeSound();
	delete meta;
	delete i;
	delete j;

	std::cout << "\n=== Wrong Animal Tests ====\n" << std::endl;
	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();
	std::cout << "Wrong Animal Type: " << wa->getType() << std::endl;
	std::cout << "Wrong Cat Type: " << wc->getType() << std::endl;
    wa->makeSound();
	wc->makeSound();

	delete wa;
	delete wc;
	
	return 0;
}