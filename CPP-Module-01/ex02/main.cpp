/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:28:04 by thchau            #+#    #+#             */
/*   Updated: 2025/10/12 16:42:08 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str; //Pointer to the string
	std::string& stringREF = str; // Reference to the string
	std::string str1 = str;
	
	std::cout << "================== MEMORY ADDRESSES ==================" << std::endl;
	std::cout << "Address of str       : " << &str << std::endl;
	std::cout << "Address of str1       : " << &str1 << std::endl;
	std::cout << "Address held by PTR  : " << stringPTR << std::endl;
	std::cout << "Address held by REF  : " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "================== VALUES ==================" << std::endl;
	std::cout << "Value of str         : " << str << std::endl;
	std::cout << "Value of str1         : " << str1 << std::endl;
	std::cout << "Value pointed by PTR : " << *stringPTR << std::endl;
	std::cout << "Value by REF         : " << stringREF << std::endl;

	 std::cout << std::endl;
    std::cout << "================== LIVE CHANGE TEST ==================" << std::endl;
    std::cout << "Changing the string using 'stringREF'..." << std::endl;

    stringREF = "BRAIN HAS BEEN MODIFIED!";

    std::cout << "\nAfter modification:" << std::endl;
    std::cout << "Value of str         : " << str << std::endl;
	std::cout << "Value of str1         : " << str1 << std::endl;
    std::cout << "Value pointed by PTR : " << *stringPTR << std::endl;
    std::cout << "Value by REF         : " << stringREF << std::endl;

    std::cout << "\nChanging the string using '*stringPTR'..." << std::endl;

    *stringPTR = "THE BRAIN IS REPROGRAMMED!";

    std::cout << "\nAfter second modification:" << std::endl;
	std::cout << "Value of str         : " << str << std::endl;
    std::cout << "Value of str1         : " << str1 << std::endl;
    std::cout << "Value pointed by PTR : " << *stringPTR << std::endl;
    std::cout << "Value by REF         : " << stringREF << std::endl;

	return 0;
	
}