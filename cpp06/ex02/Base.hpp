/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:14:08 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/05 19:28:50 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

class Base
{
	private:

	public:
		virtual ~Base(void);
};

Base *generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
