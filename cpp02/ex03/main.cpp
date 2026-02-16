/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrivell <ncrivell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:13:05 by ncrivell          #+#    #+#             */
/*   Updated: 2025/11/18 12:22:31 by ncrivell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void)
{
	// Triangle : A(0,0), B(10,0), C(5,10)
	Point a(3.0f, 4.0f);
	Point b(2.89f, 2.0f);
	Point c(5.0f, 1.8f);

	Point inside(3.54f, 4.0f);
	std::cout << "Point (5,5) inside: " << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;

	Point outside(15.0f, 5.0f);
	std::cout << "Point (15,5) inside: " << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;

	Point vertex(0.0f, 0.0f);
	std::cout << "Point (0,0) inside: " << (bsp(a, b, c, vertex) ? "YES" : "NO") << std::endl;

	Point edge(5.0f, 0.0f);
	std::cout << "Point (5,0) inside: " << (bsp(a, b, c, edge) ? "YES" : "NO") << std::endl;

	return 0;
}
