/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:43:10 by thchau            #+#    #+#             */
/*   Updated: 2025/09/30 09:36:58 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

class PhoneBook
{
	private:
		Contact contacts[8];
		int count;
		int nextIndex;
		
		std::string formatField(std::string str) const;

	public:
		PhoneBook();
		void addContact();
		void searchContacts() const;
};

#endif