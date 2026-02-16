/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:13:27 by ncrivell          #+#    #+#             */
/*   Updated: 2026/01/19 14:25:02 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_CLASS_HPP
# define PMERGE_CLASS_HPP
#include <vector>
#include <deque>
#include <string>

class Pmerge
{
	private:
		std::vector< std::pair<int, int> >	_pairsVector;
		std::vector<int>					_principalVector;
		std::vector<int>					_minimalVector;

		std::deque< std::pair<int, int> >	_pairsDeque;
		std::deque<int>						_principalDeque;
		std::deque<int>						_minimalDeque;

	public:
		Pmerge(void);
		Pmerge(const Pmerge &other);
		~Pmerge(void);
		Pmerge &operator=(const Pmerge &other);

		void	makeVectorPairs(const std::vector<int> &numbers);
		void	makeDequePairs(const std::deque<int> &deque);

		std::vector<int>	fordSortVector(std::vector<int> pVector);
		std::vector<size_t>	jacobsthalSuite(size_t minimal);
		std::deque<size_t>	jacobsthalSuiteDeque(size_t minimal);
		std::vector<size_t>	insertionOrder(size_t n);
		std::deque<size_t>	insertionOrderDeque(size_t n);
		std::deque<int>		fordSortDeque(std::deque<int> pDeque);

		const std::vector<int>	&getPrincipalVector() const;
		const std::deque<int>	&getPrincipalDeque() const;

		double	getTime();
};


#endif
