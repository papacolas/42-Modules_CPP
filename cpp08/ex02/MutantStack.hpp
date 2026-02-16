/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:36:07 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/18 12:01:14 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}
		~MutantStack(void) {}
		MutantStack &operator=(const MutantStack &other) {
			std::stack<T>::operator=(other);
			return (*this);
		};

		typedef typename std::stack<T>::container_type ct;
		typedef typename ct::iterator iterator;
		typedef	typename ct::reverse_iterator reverse_iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
};

#endif
