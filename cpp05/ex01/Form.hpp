/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:53:19 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 14:15:19 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP
#include <string>

class Bureaucrat;

class Form
{
	private:
		std::string	const	_name;
		bool				_isSigned;
		int	const			_grade_sign_it;
		int	const			_grade_exectute_it;

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

		Form(void);
		Form(const Form &other);
		Form(std::string name, int signIt, int executeIt);
		~Form(void);
		Form &operator=(const Form &other);

		std::string		getName() const;
		int				getGradeSignIt() const;
		int				getGradeExecuteIt() const;
		bool			getIsSigned() const;

		void			beSigned(const Bureaucrat &bcrat);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
