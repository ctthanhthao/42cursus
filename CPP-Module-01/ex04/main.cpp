/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchau <thchau@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:37:26 by thchau            #+#    #+#             */
/*   Updated: 2025/10/13 12:53:26 by thchau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string &content,
	const std::string &s1, const std::string &s2)
{
	if (s1.empty())
		return content;
	std::string result;
	std::size_t pos = 0;
	std::size_t found;
	while (1)
	{
		found = content.find(s1, pos);
		if (found == std::string::npos)
			break;
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, std::string::npos);
	return result;
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "USAGE: " << argv[0] 
				  << "<filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}
	std::ifstream inFile(filename.c_str());
	if (!inFile)
	{
		std::cerr << "Error: Cannot open file '" << filename
				  << "'for reading." << std::endl;
		return 1;
	}
	std::string content;
	std::string line;
	while(std::getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
			content += "\n";
	}
	inFile.close();
	std::string replaced = replaceAll(content, s1, s2);
	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "Error: Cannot create output file '"
				  << filename << ".replace'." << std::endl;
		return 1;
	}
	outFile << replaced;
	outFile.close();
	std::cout << "File '" << filename << ".replace' created sucessfully."
			  << std::endl;
	return 0;
}