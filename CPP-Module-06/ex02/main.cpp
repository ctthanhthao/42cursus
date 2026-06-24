/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:31:21 by thchau            #+#    #+#             */
/*   Updated: 2026/06/24 19:53:38 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand(time(NULL));

	for (int i = 0; i < 3; i++)
	{
		std::cout << "===== RUN TIME : " << i + 1 << " =========\n";
		Base* p = generate();
		identify(p);
		identify(*p);
		std::cout << std::endl;
    	delete p;
	}
	std::cout << "~~~*** END TEST ***~~~" << std::endl;
	return (0);
}
