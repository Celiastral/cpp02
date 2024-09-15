/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:09 by eandre            #+#    #+#             */
/*   Updated: 2024/09/15 18:44:15 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <iostream>

int	main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 10.0f);
	Point	c(10.0f, 0.0f);
	Point	Point_1(1.5f, 1.1f);
	Point	Point_2(10.0f, 10.0f);

	if (bsp(a, b, c, Point_1) == true)
		std::cout << "\033[0;32mThe point is inside the triangle ! :>\033[0m" << std::endl;
	else
		std::cout << "\033[0;31mThe point is outside the triangle ! :<\033[0m" << std::endl;
	if (bsp(a, b, c, Point_2) == true)
		std::cout << "\033[0;32mThe point is inside the triangle ! :>\033[0m" << std::endl;
	else
		std::cout << "\033[0;31mThe point is outside the triangle ! :<\033[0m" << std::endl;
}