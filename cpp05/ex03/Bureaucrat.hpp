/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:14 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 18:13:02 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP
#include <string>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &other);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &form);
		void		executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
