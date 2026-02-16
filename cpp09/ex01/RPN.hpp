/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:08:24 by ncrivell          #+#    #+#             */
/*   Updated: 2026/01/21 13:20:57 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP
#include <string>
#include <list>

class RPN
{
	private:
		std::list<int>	_stack;
		std::string		_input;

	public:
		RPN(void);
		RPN(std::string input);
		RPN(const RPN &other);
		~RPN(void);
		RPN &operator=(const RPN &other);

		void	calculator();
};

#endif
