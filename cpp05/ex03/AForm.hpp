/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:21:07 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/29 18:23:17 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP
#include <string>

class Bureaucrat;

class AForm
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

		class IsNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		AForm(void);
		AForm(const AForm &other);
		AForm(std::string name, int signIt, int executeIt);
		virtual ~AForm(void);
		AForm &operator=(const AForm &other);

		std::string		getName() const;
		int				getGradeSignIt() const;
		int				getGradeExecuteIt() const;
		bool			getIsSigned() const;

		void			beSigned(const Bureaucrat &bcrat);

		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
