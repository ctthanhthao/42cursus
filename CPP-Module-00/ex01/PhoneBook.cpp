/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:47:43 by thchau            #+#    #+#             */
/*   Updated: 2025/09/30 10:58:27 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}

std::string PhoneBook::formatField(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

void trim(std::string &s)
{
	size_t start = 0;
	size_t end = s.size();
	
	while (start < end && std::isspace(s[start]))
		start++;
	while (end > start && std::isspace(s[end - 1]))
		end--;
	s = s.substr(start, end - start);
}

bool isValidPhoneNumber(const std::string &pn)
{
	if (pn.empty())
		return false;
	for (size_t i = 0; i < pn.size(); i++)
	{
		if (!isdigit(pn[i]) && !(i == 0 && (pn[i] == '+')))
			return false;
	}
	return true;
}

void PhoneBook::addContact()
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;
	
	std::cout << "First name: ";
	std::getline(std::cin, fn);
	std::cout << "Last name: ";
	std::getline(std::cin, ln);
	std::cout << "Nick name: ";
	std::getline(std::cin, nn);
	std::cout << "Phone number: ";
	std::getline(std::cin, pn);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, ds);
	trim(fn);
	trim(ln);
	trim(nn);
	trim(pn);
	trim(ds);
	if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty())
	{
		std::cout << "Error: Fields can not be empty." << std::endl;
		return;
	}
	if (!isValidPhoneNumber(pn))
	{
		std::cout << "Error: Phone number must contain only digits and start with '+'." 
			<< std::endl;
		return;
	}
	contacts[nextIndex].setContact(fn, ln, nn, pn, ds);
	nextIndex = (nextIndex + 1) % 8;
	if (count < 8)
		count++;
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContacts() const
{
	if (count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nick Name" << "|"
			  << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
				  << std::setw(10) << formatField(contacts[i].getNickName()) << "|"
				  << std::endl;
	}
	std::cout << "Enter index: ";
	std::string idx;
	std::getline(std::cin, idx);
	if (idx.size() != 1 || !isdigit(idx[0]))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	int num = idx[0] - '0';
	if (num >= count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::cout << "First Name: " << contacts[num].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[num].getLastName() << std::endl;
	std::cout << "Nick Name: " << contacts[num].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[num].getPhoneNumer() << std::endl;
	std::cout << "Darkest secret: " << contacts[num].getDarkestSecret() << std::endl;
}