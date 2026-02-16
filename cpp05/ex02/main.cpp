/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:27 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/08 10:26:58 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static const char* GREEN  = "\033[32m";
static const char* CYAN   = "\033[36m";
static const char* RESET  = "\033[0m";

void printHeader(const std::string& title)
{
	std::cout << "\n" << CYAN << "========================================" << RESET << std::endl;
	std::cout << CYAN << "  " << title << RESET << std::endl;
	std::cout << CYAN << "========================================" << RESET << "\n" << std::endl;
}

void printTest(const std::string& test)
{
	std::cout << GREEN << ">>> Test: " << test << RESET << std::endl;
}

int main()
{
	printHeader("TESTS SHRUBBERY CREATION FORM");

	printTest("Creation et informations de base");
	try {
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Execution sans signature");
	try {
		Bureaucrat bob("Bob", 100);
		ShrubberyCreationForm shrub("garden");

		std::cout << "Tentative d'execution sans signer..." << std::endl;
		bob.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature avec grade insuffisant");
	try {
		Bureaucrat intern("Intern", 146);
		ShrubberyCreationForm shrub("office");

		std::cout << "Grade requis pour signer: 145" << std::endl;
		std::cout << "Grade de l'intern: " << intern.getGrade() << std::endl;
		intern.signForm(shrub);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature reussie mais execution avec grade insuffisant");
	try {
		Bureaucrat signer("Signer", 140);
		Bureaucrat executor("Executor", 138);
		ShrubberyCreationForm shrub("park");

		std::cout << "Grade requis: sign 145, exec 137" << std::endl;
		signer.signForm(shrub);
		std::cout << "Grade de l'executor: " << executor.getGrade() << std::endl;
		executor.executeForm(shrub);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature et execution reussies");
	try {
		Bureaucrat boss("Boss", 130);
		ShrubberyCreationForm shrub("forest");

		boss.signForm(shrub);
		boss.executeForm(shrub);
		std::cout << "Verifiez le fichier 'forest_shrubbery' cree !" << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// ============================================================
	printHeader("TESTS ROBOTOMY REQUEST FORM");
	// ============================================================

	printTest("Creation et informations de base");
	try {
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Execution sans signature");
	try {
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Marvin");

		std::cout << "Tentative d'execution sans signer..." << std::endl;
		alice.executeForm(robot);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature avec grade insuffisant");
	try {
		Bureaucrat lowly("Lowly", 80);
		RobotomyRequestForm robot("C-3PO");

		std::cout << "Grade requis pour signer: 72" << std::endl;
		std::cout << "Grade de lowly: " << lowly.getGrade() << std::endl;
		lowly.signForm(robot);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature reussie mais execution avec grade insuffisant");
	try {
		Bureaucrat signer("Signer", 70);
		Bureaucrat executor("Executor", 50);
		RobotomyRequestForm robot("R2-D2");

		std::cout << "Grade requis: sign 72, exec 45" << std::endl;
		signer.signForm(robot);
		std::cout << "Grade de l'executor: " << executor.getGrade() << std::endl;
		executor.executeForm(robot);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature et execution reussies (50% de chance)");
	try {
		Bureaucrat chief("Chief", 40);
		RobotomyRequestForm robot1("Target1");
		RobotomyRequestForm robot2("Target2");
		RobotomyRequestForm robot3("Target3");

		chief.signForm(robot1);
		chief.executeForm(robot1);

		std::cout << std::endl;
		chief.signForm(robot2);
		chief.executeForm(robot2);

		std::cout << std::endl;
		chief.signForm(robot3);
		chief.executeForm(robot3);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// ============================================================
	printHeader("TESTS PRESIDENTIAL PARDON FORM");
	// ============================================================

	printTest("Creation et informations de base");
	try {
		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Execution sans signature");
	try {
		Bureaucrat vip("VIP", 1);
		PresidentialPardonForm pardon("Ford Prefect");

		std::cout << "Tentative d'execution sans signer..." << std::endl;
		vip.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature avec grade insuffisant");
	try {
		Bureaucrat employee("Employee", 30);
		PresidentialPardonForm pardon("Trillian");

		std::cout << "Grade requis pour signer: 25" << std::endl;
		std::cout << "Grade de l'employee: " << employee.getGrade() << std::endl;
		employee.signForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature reussie mais execution avec grade insuffisant");
	try {
		Bureaucrat signer("Signer", 20);
		Bureaucrat executor("Executor", 10);
		PresidentialPardonForm pardon("Zaphod");

		std::cout << "Grade requis: sign 25, exec 5" << std::endl;
		signer.signForm(pardon);
		std::cout << "Grade de l'executor: " << executor.getGrade() << std::endl;
		executor.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Signature et execution reussies");
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Marvin");

		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// ============================================================
	printHeader("TESTS MIXTES ET CAS LIMITES");
	// ============================================================

	printTest("Un bureaucrate signe et execute plusieurs formulaires");
	try {
		Bureaucrat superman("Superman", 1);

		ShrubberyCreationForm shrub("headquarters");
		RobotomyRequestForm robot("Employee42");
		PresidentialPardonForm pardon("Whistleblower");

		std::cout << "=== Shrubbery ===" << std::endl;
		superman.signForm(shrub);
		superman.executeForm(shrub);

		std::cout << "\n=== Robotomy ===" << std::endl;
		superman.signForm(robot);
		superman.executeForm(robot);

		std::cout << "\n=== Presidential Pardon ===" << std::endl;
		superman.signForm(pardon);
		superman.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Plusieurs bureaucrates avec grades limites");
	try {
		Bureaucrat topGrade("TopGrade", 1);
		Bureaucrat midGrade("MidGrade", 75);
		Bureaucrat lowGrade("LowGrade", 150);

		PresidentialPardonForm pardon("Criminal");
		RobotomyRequestForm robot("Patient");
		ShrubberyCreationForm shrub("wasteland");

		std::cout << "=== Test avec TopGrade (grade 1) ===" << std::endl;
		topGrade.signForm(pardon);
		topGrade.executeForm(pardon);

		std::cout << "\n=== Test avec MidGrade (grade 75) ===" << std::endl;
		midGrade.signForm(robot);
		midGrade.executeForm(robot);  // Devrait echouer (besoin grade 45)

		std::cout << "\n=== Test avec LowGrade (grade 150) ===" << std::endl;
		lowGrade.signForm(shrub);
		lowGrade.executeForm(shrub);  // Devrait echouer (besoin grade 137)
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	printTest("Tentative d'execution double");
	try {
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Lucky");

		boss.signForm(pardon);
		boss.executeForm(pardon);  // Premiere execution
		std::cout << "\nDeuxieme execution du meme formulaire:" << std::endl;
		boss.executeForm(pardon);  // Deuxieme execution (devrait reussir aussi)
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	return 0;
}
