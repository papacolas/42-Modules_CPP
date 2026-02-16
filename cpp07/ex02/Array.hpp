/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:38:10 by ncrivell          #+#    #+#             */
/*   Updated: 2025/12/12 15:00:15 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int	_sizeArray;
		T				*_array;
	public:
		Array(void) {_array = new T[0]; _sizeArray = 0;}
		Array(unsigned int n) {_array = new T[n]; _sizeArray = n;}
		Array(const Array &other) {
			this->_sizeArray = other._sizeArray;
			this->_array = new T[other._sizeArray];
			for (unsigned int i = 0; i < other._sizeArray; i++)
				this->_array[i] = other._array[i];
		};
		Array &operator=(const Array &other) {
			if (this != &other)
			{
				delete [] this->_array;
				this->_sizeArray = other._sizeArray;
				this->_array = new T[other._sizeArray];
				for (unsigned int i = 0; i < other._sizeArray; i++)
					this->_array[i] = other._array[i];
			}
			return (*this);
		};
		~Array(void) {delete[] _array;}
		T &operator[](unsigned int index) {
			if (index >= _sizeArray)
				throw std::exception();
			return _array[index];
		}
		const T &operator[](unsigned int index) const {
			if (index >= _sizeArray)
				throw std::exception();
			return _array[index];
		}

		unsigned int size() const {return _sizeArray;}
};
#endif
