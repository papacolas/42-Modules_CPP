/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:37:16 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/15 16:24:58 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP
#include <vector>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _vect;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		void				addNumber(int num);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		template<typename T>
		void addMultipleNumbers(T first, T final)
		{
			if (this->_vect.size() + (std::distance(first, final)) <= this->_N)
				_vect.insert(_vect.end(), first, final);
			else
				throw std::exception();
		}
};

#endif
