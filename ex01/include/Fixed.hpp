/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:07:02 by eandre            #+#    #+#             */
/*   Updated: 2024/09/10 20:39:19 by eandre           ###   ########.fr       */
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
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator=(const Fixed &other_Fixed);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
	private :
		int	raw_bits;
		static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &Fixed);

#endif