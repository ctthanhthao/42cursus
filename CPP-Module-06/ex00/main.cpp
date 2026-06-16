/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:52:26 by thchau            #+#    #+#             */
/*   Updated: 2026/06/16 12:56:19 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
		return (1);
		
	std::string s = argv[1];
	ScalarConverter::convert(s);
	return (0);
}