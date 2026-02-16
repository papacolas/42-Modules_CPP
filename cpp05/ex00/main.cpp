/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:28:41 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/28 19:38:33 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	static const char* RESET  = "\033[0m";
	static const char* GREEN  = "\033[32m";

	std::cout << GREEN << "Creation normale" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "Constructeur de copie" << RESET << std::endl;
	try
	{
		Bureaucrat original("Alice", 42);
		std::cout << "Original: " << original << std::endl;

		Bureaucrat copie(original);  // Constructeur de copie
		std::cout << "Copie: " << copie << std::endl;

		// Modifier la copie
		copie.incrementGrade();
		std::cout << "Après increment de la copie:" << std::endl;
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copie: " << copie << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "Opérateur d'affectation" << RESET << std::endl;
	try
	{
		Bureaucrat a("Charlie", 100);
		Bureaucrat b("David", 50);

		std::cout << "Avant affectation:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		a = b;  // Opérateur d'affectation

		std::cout << "Après a = b:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;

		// Note: le nom de 'a' reste "Charlie" car il est const
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}



	std::cout << GREEN << "Grade trop haut" << RESET << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "Grade trop bas" << RESET << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "Exception increment" << RESET << std::endl;
	try
	{
		Bureaucrat david("David", 2);
		std::cout << david << std::endl;
		david.incrementGrade();
		std::cout << david << std::endl;
		david.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << GREEN << "Exception decrement" << RESET << std::endl;
	try
	{
		Bureaucrat eve("Eve", 149);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << eve << std::endl;
		eve.decrementGrade(); // Exception ici
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
