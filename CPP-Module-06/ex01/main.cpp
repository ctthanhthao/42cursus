/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:03:32 by thchau            #+#    #+#             */
/*   Updated: 2026/06/18 11:32:07 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.id = 1200;
	data.name = "test";
	Data *p1 = &data;
	
	std::cout << "Original pointer: " << p1 << std::endl;
	
	uintptr_t raw = Serializer::serialize(&data);
	
	std::cout << "Serialized value: " << raw << std::endl;
	
	Data *p2 = Serializer::deserialize(raw);
	
	std::cout << "Deserialized pointer: " << p2 << std::endl;
	
	if (p1 == p2)
		std::cout << "Pointers match." << std::endl;
	else
		std::cout << "Pointers don't match." << std::endl;
	
	std::cout << "Data check: " << p2->id << " " << p2->name << std::endl;
	
	return (0);
}