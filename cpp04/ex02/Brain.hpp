/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:33:59 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/27 12:59:44 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP
#include <string>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(const Brain &other);
		~Brain(void);
		Brain &operator=(const Brain &other);

		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;
};

#endif
