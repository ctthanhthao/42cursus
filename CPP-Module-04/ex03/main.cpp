/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:48:09 by thchau            #+#    #+#             */
/*   Updated: 2025/11/20 15:34:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "\n=== TEST 1: MateriaSource Learn & Create ===\n";
	IMateriaSource* src = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	
	ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	
	std::cout << "\n=== TEST 2: Using Materias ===\n";
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
    me->use(1, *bob);

	std::cout << "\n=== TEST 3: Testing Unequip (no delete) ===\n";
    AMateria* dropped = src->createMateria("ice");
    me->equip(dropped);

    std::cout << "Unequipping index 2...\n";
    me->unequip(2);   // should NOT delete the materia
	
	std::cout << "\n=== TEST 4: Deep Copy Character ===\n";
	Character *original = new Character("original");
	AMateria *oriTmp;
	oriTmp = src->createMateria("cure");
	original->equip(oriTmp);
	oriTmp = src->createMateria("ice");
	original->equip(oriTmp);
	Character *copy = new Character(*original);
	std::cout << "Using original[0]: ";
    original->use(0, *bob);

    std::cout << "Using copy[0]: ";
    copy->use(0, *bob);
	std::cout << "\nModifying original inventory...\n";
    original->unequip(0);

    std::cout << "Using copy[0] after original changed: ";
    copy->use(0, *bob);
	delete original;
	delete copy;
	
	std::cout << "\n=== TEST 5: Full Inventory ===\n";
    Character full("full");
	full.equip(src->createMateria("ice"));
    full.equip(src->createMateria("ice"));
    full.equip(src->createMateria("ice"));
    full.equip(src->createMateria("ice"));

    std::cout << "Trying to equip 5th materia — should do nothing.\n";
    full.equip(src->createMateria("ice"));

    std::cout << "\n=== TEST 6: Delete All Objects ===\n";
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
	return 0;
}