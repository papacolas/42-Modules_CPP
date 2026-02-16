/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:45 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 18:31:02 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm("ShrubberyCreationForm", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
AForm(other),
_target(other._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::createTree(std::ostream &file) const
{
file << "          .     .  .      +     .      .          ." << std::endl;
file << "     .       .      .    #       .           ." << std::endl;
file << "      .      .         ###            .      .      ." << std::endl;
file << "     .      .   #:. .:####:. .:#  .      ." << std::endl;
file << "         .      . ###########  ." << std::endl;
file << "     .     #:.    .:#0###0#:.    .:#  .        .       ." << std::endl;
file << " .             ########.#########        .        ." << std::endl;
file << "       .    #:.  #######.####  .:#   .       ." << std::endl;
file << "    .     .  #######00##0##00#######                  ." << std::endl;
file << "               .0##0#####0#####0##0           .      ." << std::endl;
file << "   .   #:. ...  .:##0###0###0##:.  ... .:#0     ." << std::endl;
file << "     .     #######0##0#####0##0#######0      .     ." << std::endl;
file << "   .    .     #####00#######00#####    .      ." << std::endl;
file << "           .       0    000      0    .     ." << std::endl;
file << "     .         .   .   000     .        .       ." << std::endl;
file << ".. ..................O000O........................ ...... ..." << std::endl;
}


void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() >= 137)
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::IsNotSignedException();

	const std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Error : creating file failed" << std::endl;
		return;
	}
	ShrubberyCreationForm::createTree(file);
}
