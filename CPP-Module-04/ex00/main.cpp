/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:46 by thchau            #+#    #+#             */
/*   Updated: 2026/05/26 09:38:06 by thchau           ###   ########.fr       */
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
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound(); //will output the cat sound! 
	dog->makeSound();
    meta->makeSound();
	
	std::cout << "\n=== Assignment Operator ===\n" << std::endl;
	Cat catAo1;
	Cat catAo2;
	catAo1 = catAo2;
	std::cout << catAo2.getType() << " " << std::endl;
	catAo2.makeSound();

	std::cout << "\n=== Copy Constructor ===\n" << std::endl;
	const Cat *cat1 = new Cat();
	const Animal* copycat = new Cat(*cat1);
	std::cout << copycat->getType() << " " << std::endl;
	copycat->makeSound();

	std::cout << "\n=== Destructor ===\n" << std::endl;
	delete meta;
	delete cat;
	delete dog;
	delete cat1;
	delete copycat;

	std::cout << "\n=== Wrong Animal Tests ====\n" << std::endl;
	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *wac = new WrongCat();
	const WrongCat *wc = new WrongCat();
	std::cout << "~~~Wrong Animal Type: " << wa->getType() << std::endl;
	wa->makeSound();
	std::cout << "~~~Wrong Cat Type (point to base class): " << wac->getType() << std::endl;
	wac->makeSound();
	std::cout << "~~~Wrong Cat Type: " << wc->getType() << std::endl;
    wc->makeSound();

	delete wa;
	delete wac;
	delete wc;
	
	std::cout << "\n=== Destructor for static objects ====\n" << std::endl;
	return 0;
}