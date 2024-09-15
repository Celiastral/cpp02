/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:09 by eandre            #+#    #+#             */
/*   Updated: 2024/09/15 18:15:18 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(1);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << c << std::endl;
	if (a < c)
		std::cout << "c is greater than a" << std::endl;
	else
		std::cout << "a is greater than c" << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << b << std::endl;
	std::cout << b/Fixed(2) << std::endl;
	std::cout << b + c << std::endl;
}