/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:05 by eandre            #+#    #+#             */
/*   Updated: 2024/09/11 17:32:49 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <math.h>

Fixed::Fixed(void) : raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : raw_bits(value << bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : raw_bits(roundf(value * (1 << bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other_Fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other_Fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other_Fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_bits = other_Fixed.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(const int raw)
{
	raw_bits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->getRawBits()) / (1 << bits));
}

std::ostream &operator<<(std::ostream &out, Fixed const &Fixed)
{
	out << Fixed.toFloat();
	return (out);
}

int	Fixed::toInt(void) const
{
	return ((int)(this->getRawBits()) >> bits);
}

int	Fixed::getRawBits(void) const
{
	return (raw_bits);
}