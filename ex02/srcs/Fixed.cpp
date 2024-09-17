/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:05 by eandre            #+#    #+#             */
/*   Updated: 2024/09/17 14:08:58 by eandre           ###   ########.fr       */
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

bool	Fixed::operator>(const Fixed &other_Fixed) const
{
	return (this->getRawBits() > other_Fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &other_Fixed) const
{
	return (this->getRawBits() < other_Fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other_Fixed) const
{
	return (this->getRawBits() <= other_Fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other_Fixed) const
{
	return (this->getRawBits() >= other_Fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &other_Fixed) const
{
	return (this->getRawBits() == other_Fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other_Fixed) const
{
	return (this->getRawBits() != other_Fixed.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other_Fixed) const
{
	Fixed result(0);
	result.raw_bits = this->raw_bits + other_Fixed.raw_bits;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other_Fixed) const
{
	Fixed result(0);
	result.raw_bits = this->raw_bits - other_Fixed.raw_bits;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other_Fixed) const
{
	Fixed result(0);
	result.raw_bits = (this->raw_bits * other_Fixed.raw_bits) / (1 << bits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other_Fixed) const
{
	Fixed result(0);
	if (other_Fixed.toInt() == 0)
	{
		std::cout << "\033[0;31mNON\033[0m" << std::endl;
		return (result);
	}
	result.raw_bits = this->raw_bits * (1 << bits) / other_Fixed.raw_bits;
	return (result);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++*this;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--*this;
	return (temp);
}

Fixed	&Fixed::operator++()
{
	++this->raw_bits;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	--this->raw_bits;
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