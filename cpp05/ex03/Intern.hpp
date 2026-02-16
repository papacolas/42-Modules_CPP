/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:50:26 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/04 16:02:47 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP
#include <string>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string nameForm, std::string targetForm);
		AForm *createRobotomyForm(std::string targetForm);
		AForm *createShrubberyForm(std::string targetForm);
		AForm *createPresidentialPardonForm(std::string targetForm);
};

#endif
