/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:46 by thchau            #+#    #+#             */
/*   Updated: 2025/11/17 20:40:43 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n=== Animal Tests ===\n" << std::endl;
	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Delete Array ====\n" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	
	std::cout << "\n=== Animal with brain test ===\n" << std::endl;
	Dog *dog = new Dog();
	dog->getBrain()->setIdea(0, "Go to the zoo.");
	
	Dog *dog_copy = new Dog();
	*dog_copy = *dog;
	
	std::cout << "Dog's idea: " << dog->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Dog_copy's idea: " << dog_copy->getBrain()->getIdea(0)
			  << std::endl;
			  
	std::cout << "\n-- Changing Dog idea --\n" << std::endl;
	dog->getBrain()->setIdea(0, "No, go to the cinema.");
	std::cout << "Dog's idea: " << dog->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Dog_copy's idea: " << dog_copy->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "\n=== Destructor ====\n" << std::endl;

	delete dog;
	delete dog_copy;
	
	return 0;
}