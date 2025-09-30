/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:34:31 by thchau            #+#    #+#             */
/*   Updated: 2025/09/30 11:05:02 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact(std::string fn, std::string ln, std::string nn,
	std::string pn, std::string ds)
{
	firstName = fn;
	lastName = ln;
	nickName = nn;
	phoneNumber = pn;
	darkestSecret = ds;
}

std::string Contact::getFirstName() const 
{
	return firstName;
}

std::string Contact::getLastName() const 
{
	return lastName;
}

std::string Contact::getNickName() const 
{
	return nickName;
}

std::string Contact::getPhoneNumer() const 
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const 
{
	return darkestSecret;
}