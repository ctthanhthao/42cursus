/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:03:12 by thchau            #+#    #+#             */
/*   Updated: 2025/09/30 10:40:59 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string tolowerString(const std::string &s)
{
	std::string re;
	
	for (size_t i = 0; i < s.size(); i++)
		re.push_back(std::tolower(s[i]));
	return re;
}

int main(void)
{
	PhoneBook pbook;
	std::string command;
	
	std::cout << "Welcome to crappy awesome phonebook!" << std::endl;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (tolowerString(command) == "add")
			pbook.addContact();
		else if (tolowerString(command) == "search")
			pbook.searchContacts();
		else if (tolowerString(command) == "exit")
			break;
		else
			std::cout << "Unknown command." << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}