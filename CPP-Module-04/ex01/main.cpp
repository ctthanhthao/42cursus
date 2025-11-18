/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:46 by thchau            #+#    #+#             */
/*   Updated: 2025/11/18 09:50:04 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

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
	
	std::cout << "\n=== Dog with brain test ===\n" << std::endl;
	Dog *dog = new Dog();
	dog->getBrain()->setIdea(0, "Go to the zoo.");
	
	Dog *dog_assign = new Dog();
	*dog_assign = *dog;

	Dog *dog_copy = new Dog(*dog);
	
	std::cout << "Dog's idea: " << dog->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Dog_assign's idea: " << dog_assign->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Dog_copy's idea: " << dog_copy->getBrain()->getIdea(0)
			  << std::endl;
			  
	std::cout << "\n-- Changing Dog idea --\n" << std::endl;
	dog->getBrain()->setIdea(0, "No, go to the cinema.");
	std::cout << "Dog's idea: " << dog->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Dog_assign's idea: " << dog_assign->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Dog_copy's idea: " << dog_copy->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "\n=== Cat with brain test ===\n" << std::endl;
	Cat *cat = new Cat();
	cat->getBrain()->setIdea(0, "I want a fish.");
	
	Cat *cat_assign = new Cat();
	*cat_assign = *cat;

	Cat *cat_copy = new Cat(*cat);
	
	std::cout << "Cat's idea: " << cat->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Cat_assign's idea: " << cat_assign->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "Cat_copy's idea: " << cat_copy->getBrain()->getIdea(0)
			  << std::endl;
			  
	std::cout << "\n-- Changing cat idea --\n" << std::endl;
	cat->getBrain()->setIdea(0, "No, i will eat a banana.");
	std::cout << "Cat's idea: " << cat->getBrain()->getIdea(0)
			  << std::endl;
	cat_assign->getBrain()->setIdea(0, "No, i will eat a grape.");
	std::cout << "cat_assign's idea: " << cat_assign->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "cat_copy's idea: " << cat_copy->getBrain()->getIdea(0)
			  << std::endl;
	std::cout << "\n=== Destructor ====\n" << std::endl;

	delete dog;
	delete dog_copy;
	delete dog_assign;

	delete cat;
	delete cat_copy;
	delete cat_assign;
	
	return 0;
}