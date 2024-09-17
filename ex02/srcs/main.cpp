/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:09 by eandre            #+#    #+#             */
/*   Updated: 2024/09/17 13:49:44 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(1);
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "c = " << c << std::endl;
	if (a < c)
		std::cout << "c is greater than a" << std::endl;
	else
		std::cout << "a is greater than c" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max between a and b = " << Fixed::max(a, b) << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b/2 = " << b/Fixed(2) << std::endl;
	std::cout << "b+c = " << b + c << std::endl;
}