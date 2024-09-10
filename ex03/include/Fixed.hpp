/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:02 by eandre            #+#    #+#             */
/*   Updated: 2024/09/10 23:03:35 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public :
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other_Fixed);
		~Fixed();
		Fixed				&operator=(const Fixed &other_Fixed);
	
		bool				operator>(const Fixed &other_Fixed) const;
		bool				operator<(const Fixed &other_Fixed) const;
		bool				operator<=(const Fixed &other_Fixed) const;
		bool				operator>=(const Fixed &other_Fixed) const;
		bool				operator==(const Fixed &other_Fixed) const;
		bool				operator!=(const Fixed &other_Fixed) const;
	
		Fixed				operator+(const Fixed &other_Fixed) const;
		Fixed				operator-(const Fixed &other_Fixed) const;
		Fixed				operator*(const Fixed &other_Fixed) const;
		Fixed				operator/(const Fixed &other_Fixed) const;
	
		Fixed				operator++(int);
		Fixed				operator--(int);
		Fixed				&operator++();
		Fixed				&operator--();
	
		static Fixed		max(Fixed &a, Fixed &b);
		static Fixed		min(Fixed &a, Fixed &b);
		static const Fixed	max(const Fixed &a, const Fixed &b);
		static const Fixed	min(const Fixed &a, const Fixed &b);
	
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;
	private :
		int	raw_bits;
		static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &Fixed);

#endif