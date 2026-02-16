/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:53:01 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/08 10:05:28 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static const char* GREEN  = "\033[32m";
static const char* RESET  = "\033[0m";

void printTest(const std::string& test)
{
	std::cout << GREEN << ">>> Test: " << test << RESET << std::endl;
}

int main()
{

	printTest("Creation normale d'un Form");  //("Tester les differents cas")
	try {
		Form tax("Tax Form", 50, 25);
		std::cout << tax << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Constructeur de copie");
	try {
		Form original("Original", 100, 50);
		std::cout << "Original: " << original << std::endl;

		Form copy(original);
		std::cout << "Copie: " << copy << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Operateur d'affectation");
	try {
		Form form1("Form1", 100, 50);
		Form form2("Form2", 25, 10);

		std::cout << "Avant: " << form1 << std::endl;
		form1 = form2;
		std::cout << "Apres: " << form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Test Bureacrat grades");
	try {
		Bureaucrat alice("Alice", 30);
		Form permit("Building Permit", 50, 25);

		std::cout << "Avant signature: " << permit << std::endl;
		alice.signForm(permit);
		std::cout << "Apres signature: " << permit << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Grade trop faible pour signer");
	try {
		Bureaucrat bob("Bob", 60);
		Form permit("Permit", 50, 25);
		std::cout << "Avant: " << permit << std::endl;
		bob.signForm(permit);
		std::cout << "Apres: " << permit << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Form avec grades invalides");
	try {
		Form invalid("Invalid", 0, 25);  // Grade 0 -> trop haut
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
