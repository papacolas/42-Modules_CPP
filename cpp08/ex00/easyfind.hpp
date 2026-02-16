/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:00:11 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/18 11:08:21 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
typename T::const_iterator	easyfind(T const &lst, int tofind)
{
	typename T::const_iterator pos = std::find(lst.begin(), lst.end(), tofind);
	if (pos == lst.end())
	{
		throw std::exception();
	}
	std::cout << "Occurence : " << *pos << " found at position : " << std::distance(lst.begin(), pos) << std::endl;
	return (pos);
}
#endif
