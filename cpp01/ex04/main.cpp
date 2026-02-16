/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:43:09 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/14 10:47:55 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string	replace_myFile(std::string content, const std::string &s1, const std::string &s2)
{
	std::string	temp;
	std::string	res;

	size_t		pos = 0;
	size_t		found;

	if (s1.empty())
	{
		return content;
	}

	while (pos < content.length())
	{
		found = content.find(s1, pos);
		if (found != std::string::npos)
		{
			temp = content.substr(pos, found - pos);
			res.append(temp);
			res.append(s2);
			pos = found + s1.length();
		}
		else
			break;
	}
	res.append(content, pos, content.length() - pos);
	return res;
}


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Program is waiting for : " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::ifstream myFile(argv[1]);
	if (!myFile.is_open())
	{
		std::cerr << "Error with opening file : " << argv[1] << std::endl;
		return 1;
	}

	std::ostringstream ss;
	ss << myFile.rdbuf();
	std::string content = ss.str();

	if (myFile.fail() && !myFile.eof())
	{
		std::cerr << "Error with reading file: " << argv[1] << std::endl;
		myFile.close();
		return 1;
	}
	myFile.close();

	std::string	result = replace_myFile(content, argv[2], argv[3]);
	std::string	outfilename = std::string(argv[1]) + ".replace";
	std::ofstream outFile(outfilename.c_str());

	if (!outFile.is_open())
	{
		std::cerr << "Error with creating file : " << outfilename << std::endl;
		return 1;
	}

	outFile << result;
	if (outFile.fail())
	{
		std::cerr << "Error writing to file: " << outfilename << std::endl;
		outFile.close();
		return 1;
	}
	outFile.close();
	std::cout << "File created: " << outfilename << std::endl;
	return 0;
}
