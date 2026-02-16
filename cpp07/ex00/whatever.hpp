/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:04:06 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/12 11:11:35 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	const &min(T const  &a, T const &b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
T	const &max(T const &a, T const &b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif
