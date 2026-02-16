/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:27 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/04 16:21:43 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

static const char* GREEN  = "\033[32m";
static const char* YELLOW = "\033[33m";
static const char* RED    = "\033[31m";
static const char* RESET  = "\033[0m";

void printTest(const std::string& test)
{
	std::cout << GREEN << ">>> Test: " << test << RESET << std::endl;
}

int main()
{
	// ============================================================
	printTest("Test 1: Intern cree un RobotomyRequestForm");
	// ============================================================
	try {
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		if (rrf != NULL)
		{
			std::cout << "Formulaire cree: " << *rrf << std::endl;

			Bureaucrat bob("Bob", 1);
			bob.signForm(*rrf);
			bob.executeForm(*rrf);

			delete rrf;
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ============================================================
	printTest("Test 2: Intern cree un ShrubberyCreationForm");
	// ============================================================
	try {
		Intern someRandomIntern;
		AForm* scf;

		scf = someRandomIntern.makeForm("shrubbery creation", "garden");

		if (scf != NULL)
		{
			std::cout << "Formulaire cree: " << *scf << std::endl;

			Bureaucrat alice("Alice", 1);
			alice.signForm(*scf);
			alice.executeForm(*scf);

			delete scf;
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ============================================================
	printTest("Test 3: Intern cree un PresidentialPardonForm");
	// ============================================================
	try {
		Intern someRandomIntern;
		AForm* ppf;

		ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

		if (ppf != NULL)
		{
			std::cout << "Formulaire cree: " << *ppf << std::endl;

			Bureaucrat president("President", 1);
			president.signForm(*ppf);
			president.executeForm(*ppf);

			delete ppf;
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ============================================================
	printTest("Test 4: Formulaire inexistant");
	// ============================================================
	try {
		Intern someRandomIntern;
		AForm* unknown;

		unknown = someRandomIntern.makeForm("unknown form", "Target");

		if (unknown == NULL)
			std::cout << RED << "Le formulaire n'a pas ete cree (NULL retourne)" << RESET << std::endl;
		else
		{
			std::cout << "Formulaire cree: " << *unknown << std::endl;
			delete unknown;
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}


	// ============================================================
	printTest("Test 5: Noms de formulaires avec erreurs");
	// ============================================================
	try {
		Intern intern;

		std::cout << YELLOW << "Test avec differentes erreurs de noms:" << RESET << std::endl;

		AForm* f1 = intern.makeForm("robotomy", "Target");
		if (f1)
			delete f1;

		AForm* f2 = intern.makeForm("ROBOTOMY REQUEST", "Target");
		if (f2)
			delete f2;

		AForm* f3 = intern.makeForm("shrubbery", "Target");
		if (f3)
			delete f3;

		AForm* f4 = intern.makeForm("", "Target");
		if (f4)
			delete f4;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// ============================================================
	printTest("Test 6: Copie et assignation d'intern");
	// ============================================================
	try {
		Intern intern1;

		std::cout << YELLOW << "Creation d'un formulaire avec intern1" << RESET << std::endl;
		AForm* form1 = intern1.makeForm("robotomy request", "Test1");

		Intern intern2(intern1);  // Copie
		std::cout << YELLOW << "\nCreation d'un formulaire avec intern2 (copie)" << RESET << std::endl;
		AForm* form2 = intern2.makeForm("shrubbery creation", "Test2");

		Intern intern3;
		intern3 = intern1;  // Assignation
		std::cout << YELLOW << "\nCreation d'un formulaire avec intern3 (assignation)" << RESET << std::endl;
		AForm* form3 = intern3.makeForm("presidential pardon", "Test3");

		if (form1) delete form1;
		if (form2) delete form2;
		if (form3) delete form3;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}
