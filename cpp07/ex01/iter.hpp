/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:27:22 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/12 11:14:10 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename U, typename F>
void	iter(T const *array, U const len, F foo)
{
	U i = 0;
	while (i < len)
	{
		foo(array[i]);
		i++;
	}
}

template<typename T, typename U, typename F>
void	iter(T *array, U const len, F foo)
{
	U i = 0;
	while (i < len)
	{
		foo(array[i]);
		i++;
	}
}
#endif
