/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:08:20 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/22 17:34:46 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <list>
#include <iostream>

RPN::RPN(void)
{}

RPN::RPN(std::string input) : _input(input)
{}

RPN::RPN(const RPN &other)
{
	this->_input = other._input;
	this->_stack = other._stack;
}

RPN::~RPN()
{}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_input = other._input;
		this->_stack = other._stack;
	}
	return *this;
}

void	RPN::calculator()
{
	std::string			values = this->_input;
	std::istringstream	iss (values);
	std::string			token;

	while (iss >> token)
	{
		if (isdigit(token[0]) && token.length() == 1)
		{
			_stack.push_front(token[0] - '0');
		}
		else if ((token == "+" || token == "-" || token =="*" || token == "/") && token.length() == 1 && _stack.size() >= 2)
		{
			int	value_on_the_top = static_cast<int>(_stack.front());
			_stack.pop_front();
			int	value_in_second_position = static_cast<int>(_stack.front());
			_stack.pop_front();

			int	result;
			if (token == "+")
				result = value_in_second_position + value_on_the_top;
			if (token == "-")
				result = value_in_second_position - value_on_the_top;
			if (token == "*")
				result = value_in_second_position * value_on_the_top;
			if (token == "/")
			{
				if (value_on_the_top == 0)
				{
					std::cerr << "Error : cannot use the division by 0" << std::endl;
					return;
				}
				result = value_in_second_position / value_on_the_top;
			}

			_stack.push_front(result);
		}
		else
		{
			std::cerr << "Error : each token must be a number between 0 and 9 or only an operator" << std::endl;
			return;
		}
	}

	if (_stack.size() != 1)
	{
		std::cerr << "Error : invalid input" << std::endl;
		return;
	}
	std::cout << _stack.front() << std::endl;

}

